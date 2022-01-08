#include "include/raylib.h"

int main(int charc, char** argv) {

  const int screenWidth = 1024;
  const int screenHeight = 768;

  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawText("This is RayLib Space Game engine!", 190, 200, 20, LIGHTGRAY);

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
