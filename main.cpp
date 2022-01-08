#include "include/raylib.h"
#include "src/Planet.h"
#include "src/Particle.h"

int main(int charc, char** argv) {

  const int screenWidth = 1024;
  const int screenHeight = 768;

  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  //init objects here
  Planet planet(Vector2{ 400.0f,400.0f }, 50, 80000);
  Particle particle(Vector2{ 100.0f,600.0f }, Vector2{ 15.0f,0.0f });
  particle.RegisterPlanet(&planet);
  //end init objects

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(RAYWHITE);

    DrawCircleV(planet.GetPlanetPosition(),
        planet.GetPlanetRadius(),
        ORANGE);
    DrawCircleV(particle.GetPosition(), 2.0f, particle.GetColor());
    particle.Update();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
