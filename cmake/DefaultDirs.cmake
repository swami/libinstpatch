# Several directory names used by libInstPatch to install files
# the variable names are similar to the KDE4 build system

# BUNDLE_INSTALL_DIR - Mac only: the directory for application bundles
set (BUNDLE_INSTALL_DIR "/Applications" CACHE STRING
     "The install dir for application bundles")
mark_as_advanced (BUNDLE_INSTALL_DIR)

# FRAMEWORK_INSTALL_DIR - Mac only: the directory for framework bundles
set (FRAMEWORK_INSTALL_DIR "/Library/Frameworks" CACHE STRING
     "The install dir for framework bundles")
mark_as_advanced (FRAMEWORK_INSTALL_DIR)
