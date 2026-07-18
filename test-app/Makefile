
# Define compiler
CC = gcc

# Program name (variable)
TARGET = test_instpa_a

# Compiler flags
CFLAGS = -I./include/   $(shell pkg-config --cflags glib-2.0 gobject-2.0)
CFLAGS += -ggdb -Wall -Wextra -fsanitize=address

# Linker flags
LDFLAGS = -Wl,-rpath,'$$ORIGIN/lib' -fsanitize=address

# Libraries to link
LIBS = ./lib/libinstpatch-1.0.so  $(shell pkg-config --libs glib-2.0 gobject-2.0)

# Default target
all: pre_all $(TARGET)

pre_all:
	@echo "### Running pre‑all command..."
	rm -f $(TARGET) $(TARGET).o   # clean files (optional)
	###  creating symlinks  (overwrite if existent)
	ln -s -r -f -v  ../build/libinstpatch/libinstpatch-1.0.so        ./lib/
	ln -s -r -f -v  ../build/libinstpatch/libinstpatch-1.0.so.2      ./lib/
	ln -s -r -f -v  ../build/libinstpatch/libinstpatch-1.0.so.2.2.1  ./lib/
	###  update headers - directory
	cp  ../libinstpatch/*.h ./include/libinstpatch/
	cp  ../build/libinstpatch/*.h ./include/libinstpatch/

# Compile step
$(TARGET).o: src/main.c
	$(CC) -c src/main.c -o $(TARGET).o $(CFLAGS)

# Link step
$(TARGET): $(TARGET).o
	$(CC) -o $(TARGET) $(TARGET).o $(LIBS) $(LDFLAGS)

# Cleanup
clean:
	rm -f $(TARGET) $(TARGET).o

