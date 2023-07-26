# This is a WIP game engine for Space Game build in RayLib.

## Build instructions
### Requirements
1. Header file in include/ dir -> `raylib.h`.
2. Lib file in lib/ dir -> `libraylib.a`.

### Build command (example) for Windows system using MinGW64
1. C:\msys64\mingw64\bin\g++.exe main.cpp -o main.exe -O1 -Wall -Wno-missing-braces -I include/ -L lib/ -lraylib -lopengl32 -lgdi32 -lwinmm

# License

Since this software uses [RayLib](https://www.raylib.com/index.html), here is licence for it:

Copyright (c) 2013-2022 Ramon Santamaria (@raysan5)

This software is provided "as-is", without any express or implied warranty. In no event will the authors be held liable for any damages arising from the use of this software.

Permission is granted to anyone to use this software for any purpose, including commercial applications, and to alter it and redistribute it freely, subject to the following restrictions:

1. The origin of this software must not be misrepresented; you must not claim that you wrote the original software. If you use this software in a product, an acknowledgment in the product documentation would be appreciated but is not required.

2. Altered source versions must be plainly marked as such, and must not be misrepresented as being the original software.

3. This notice may not be removed or altered from any source distribution.
