@echo off
SET compiler_dir="C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.31.31103\bin\Hostx64\x64\cl.exe"

REM Set your own raylib version if this is not correct
SET RAYLIB_VERSION=raylib-4.5.0_win64_msvc16

REM Set your own rayblib path if this is not correct
SET raylib_include_dir="D:\libraries\%RAYLIB_VERSION%\include"
SET raylib_link_dir="D:\libraries\%RAYLIB_VERSION%\lib"

echo %raylib_include_dir%
echo %raylib_link_dir%

REM %compiler_dir% /EHsc main.cpp src/InertObject.cpp src/SmokeParticle.cpp src/Collisions.cpp src/Particle.cpp src/Planet.cpp src/Ship.cpp src/Object.cpp src/Utils.cpp src/Scene.cpp src/SceneMainMenu.cpp src/SceneGame.cpp src/SceneEditor.cpp src/Console.cpp src/ObjectPipe.cpp src/PlayerShip.cpp src/Parser.cpp /I \src user32.lib gdi32.lib winmm.lib D:\engines\raylib-space-game\lib\raylib.lib /DEBUG:FULL /INCREMENTAL:NO

%compiler_dir% /EHsc /Zi^
 /DEBUG:FULL^
 /INCREMENTAL:NO^
 /Fe:"space-game"^
 main.cpp^
 src/objects/InertObject.cpp^
 src/objects/SmokeParticle.cpp^
 src/objects/Particle.cpp^
 src/objects/Planet.cpp^
 src/objects/Ship.cpp^
 src/objects/Object.cpp^
 src/scenes/Scene.cpp^
 src/scenes/SceneMainMenu.cpp^
 src/scenes/SceneGame.cpp^
 src/scenes/SceneEditor.cpp^
 src/Utils.cpp^
 src/Collisions.cpp^
 src/CameraOperation.cpp^
 src/Console.cpp^
 src/ObjectPipe.cpp^
 src/objects/PlayerShip.cpp^
 src/Parser.cpp^
 /I%raylib_include_dir%^
 /link /LIBPATH:%raylib_link_dir% /NODEFAULTLIB:libcmt^
 raylib.lib gdi32.lib User32.lib Shell32.lib winmm.lib kernel32.lib

REM rm *.obj

