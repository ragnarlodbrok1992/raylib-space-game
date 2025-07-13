@echo off

SET BUILD_DIR="build"
SET compiler_dir="C:\Program Files (x86)\Microsoft Visual Studio\2022\BuildTools\VC\Tools\MSVC\14.43.34808\bin\Hostx64\x64\cl.exe"

REM Set your own raylib version if this is not correct
SET RAYLIB_VERSION=raylib-5.5_win64_msvc16
echo %RAYLIB_VERSION%

REM Set your own rayblib path if this is not correct
SET raylib_include_dir="D:\libraries\%RAYLIB_VERSION%\include"
SET raylib_link_dir="D:\libraries\%RAYLIB_VERSION%\lib"

echo %raylib_include_dir%
echo %raylib_link_dir%

echo Checking for build directory...

IF NOT EXIST %BUILD_DIR% (
  echo Creating build directory...
  mkdir "%BUILD_DIR%"
)

pushd %BUILD_DIR%

%compiler_dir% /EHsc /Zi^
 /DEBUG:FULL^
 /INCREMENTAL:NO^
 /Fe:"space-game"^
 /std:c++20^
 ../main.cpp^
 ../src/objects/InertObject.cpp^
 ../src/objects/SmokeParticle.cpp^
 ../src/objects/Particle.cpp^
 ../src/objects/Planet.cpp^
 ../src/objects/Ship.cpp^
 ../src/objects/Object.cpp^
 ../src/scenes/Scene.cpp^
 ../src/scenes/SceneMainMenu.cpp^
 ../src/scenes/SceneGame.cpp^
 ../src/scenes/SceneEditor.cpp^
 ../src/Graphics.cpp^
 ../src/Utils.cpp^
 ../src/Collisions.cpp^
 ../src/Console.cpp^
 ../src/ObjectPipe.cpp^
 ../src/objects/PlayerShip.cpp^
 ../src/Parser.cpp^
 /I%raylib_include_dir%^
 /link /LIBPATH:%raylib_link_dir% /NODEFAULTLIB:libcmt^
 raylib.lib gdi32.lib User32.lib Shell32.lib winmm.lib kernel32.lib

popd
