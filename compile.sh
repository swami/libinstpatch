
### for cleaning the project run:
###
# cmake --build build --target clean


cmake -S.  -B build  -DCMAKE_BUILD_TYPE=RelWithDebInfo
# add if required:
# -DCMAKE_INSTALL_PREFIX=/usr/local/
# -S for project base directory
# -B for build directory

cmake --build build  -j7

sudo cmake --install build

