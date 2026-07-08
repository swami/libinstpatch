

cmake -S.  -B build  -DCMAKE_BUILD_TYPE=RelWithDebInfo
# add if required:
# -DCMAKE_INSTALL_PREFIX=/usr/local/
# -S for project base directory
# -B for build directory

cmake --build build

sudo cmake --install build

