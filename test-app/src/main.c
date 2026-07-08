#include <stdlib.h>
#include <stdio.h>
#include <glib.h>
#include <glib-object.h>
#include <libinstpatch/libinstpatch.h>

int main(int argc, char *argv[])
{
    const char *filename = "/usr/share/soundfonts/FluidR3_GM.sf2";
    GError *err = NULL;

    /* Allow overriding the filename via command line arguments */
    if (argc > 1) {
        filename = argv[1];
    }

    printf("Starting LSAN test...\n");
    printf("Initializing libinstpatch...\n");

    /* Initialize the libinstpatch library and GObject types */
    ipatch_init();

    printf("Loading '%s'...\n", filename);

    /* Create a specific SF2 file item for reading */
    IpatchFile *file = IPATCH_FILE(ipatch_sf2_file_new());
    if (!file) {
        fprintf(stderr, "Failed to create IpatchSF2File for %s\n", filename);
        return 1;
    }

    /* Set the file name using the correct function */
    ipatch_file_set_name(file, filename);

    /* Open the file to get a file handle for reading (requires 4 arguments) */
    IpatchFileHandle *handle = ipatch_file_open(file, filename, "r", &err);
    if (!handle) {
        fprintf(stderr, "Failed to open file '%s': %s\n", filename, err ? err->message : "Unknown error");
        if (err) g_error_free(err);
        g_object_unref(file);
        return 1;
    }

    /* Create an SF2 reader and pass the handle to it. Ownership of 'handle'
     * is taken over by the reader (its IpatchRiff parent) from this point on;
     * it gets closed automatically when the reader is unreffed/finalized, so
     * it must NOT be closed manually anymore (doing so caused a double-close
     * / use-after-free, which is what ASan was catching in ipatch_file_close). */
    IpatchSF2Reader *reader = ipatch_sf2_reader_new(handle);
    if (!reader) {
        fprintf(stderr, "Failed to create IpatchSF2Reader for '%s'\n", filename);
        ipatch_file_close(handle);
        g_object_unref(file);
        return 1;
    }

    /* Load the SoundFont file via the reader.
     * NOTE: there is no way to load into a pre-existing IpatchSF2 - an
     * "item"/"sf" property never existed on IpatchSF2Reader for that (the
     * earlier g_object_set(reader, "item", ...) call only raised a
     * GLib-GObject-CRITICAL and did nothing). ipatch_sf2_reader_load()
     * always creates its own IpatchSF2 internally and returns it
     * (transfer full: refcount 1, owned by us from here on). The previous
     * version of this program never captured that return value - it just
     * compared it to NULL and discarded it - which leaked the entire
     * loaded preset/instrument/sample object graph (the large LSAN leak
     * report rooted at ipatch_sf2_reader_load). */
    IpatchSF2 *sfont = ipatch_sf2_reader_load(reader, &err);  /* ++ ref */
    if (!sfont) {
        fprintf(stderr, "Error loading SoundFont: %s\n", err ? err->message : "Unknown error");
        if (err) g_error_free(err);
        g_object_unref(reader);
        g_object_unref(file);
        return 1;
    }

    printf("Successfully loaded '%s'!\n", filename);

    /* Clean up the reader and file object. Do NOT call ipatch_file_close()
     * here: the reader owns 'handle' and closes/frees it on unref above. */
    g_object_unref(reader);
    g_object_unref(file);

    /* Unref the loaded SoundFont object (the ref returned by
     * ipatch_sf2_reader_load() above). If there are memory leaks in
     * libinstpatch's SF2 reader or item destruction, LSAN will detect them
     * here. */
    printf("Freeing SoundFont object...\n");
    g_object_unref(sfont);  /* -- unref */

    /* Shutdown libinstpatch to clear internal caches/types */
    printf("Shutting down libinstpatch...\n");
    ipatch_close();

    printf("Cleanup complete. Any leaks will be reported by LSAN below.\n");
    return 0;
}
