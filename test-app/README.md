
## only for debugging 

an extreme simple app that loads
a sf2 file from **hardcoded** directory using 
libinstpatch DLL **from ../build/ folder** (not system).


**NOTE:** 
- Makefile expects a build of libinstpatch in ../build directory 
- install liblsan / libasan

NOTES:  (skip, **done** by Makefile already) 
before compiling update include files: 
  cp ../libinstpatch/*.h  ./include/libinstpatch/ 
  # and:
  cp ../build/libinstpatch/*.h  ./include/libinstpatch/

update DLL in ./lib/  
