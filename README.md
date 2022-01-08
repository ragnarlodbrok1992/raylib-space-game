# This is a WIP game engine for Space Game build in RayLib.

## Build instructions
### Requirements
1. Header file in include/ dir -> raylib.h.
2. Lib file in lib/ dir -> libraylib.a.

### Build command (example) for Windows system using MinGW64
1. C:\msys64\mingw64\bin\g++.exe main.cpp -o main.exe -O1 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm
