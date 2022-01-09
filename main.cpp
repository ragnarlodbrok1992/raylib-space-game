#include<list>
#include "include/raylib.h"
#include "src/Planet.h"
#include "src/Particle.h"

int main(int charc, char** argv) {

  const int screenWidth = 1024;
  const int screenHeight = 768;

  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  std::list <Planet*> gravitySources;
  std::list <Particle*> gravityConsumers;
  //init objects here
  Particle* particle;
  for (int ii = 0; ii < 400; ii++)
  {
      particle = new Particle(Vector2{ 100.0f+ii,400.0f+ii/2 }, Vector2{ 3.0f+ii/10.0f,0.0f }, BLACK);
      gravityConsumers.push_back(particle);
  }
  Planet planet(Vector2{ 400.0f,400.0f }, 50, 50000, BLUE);
  Planet planet2(Vector2{ 650.0f,250.0f }, 60, 70000, DARKBLUE);
  Planet planet3(Vector2{ 100.0f,120.0f }, 30, 30000, BROWN);
  gravitySources.push_back(&planet);
  gravitySources.push_back(&planet2);
  gravitySources.push_back(&planet3);
  //end init objects

  while (!WindowShouldClose()) {

    BeginDrawing();

    ClearBackground(RAYWHITE);
    //calculating forces
    for (Particle* currentParticle : gravityConsumers)
    {
        Vector2 acceleration{ 0.0f,0.0f };
        for (Planet* currentPlanet : gravitySources)
        {
            Vector2 partialAcceleration = currentPlanet->GetAcceleration(currentParticle->position);
            acceleration.x += partialAcceleration.x;
            acceleration.y += partialAcceleration.y;
        }
        currentParticle->Update(acceleration);
    }

    //drawing
    for (Planet* currentPlanet : gravitySources)
    {
        currentPlanet->Draw();
    }
    for (Particle* currentParticle : gravityConsumers)
    {
        currentParticle->Draw();
    }

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
