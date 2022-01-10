#include<list>
#include "src/raylib.h"
#include "src/Planet.h"
#include "src/Particle.h"
#include "src/Ship.h"
#include "src/Utils.h"
#include "src/Collisions.h"


int main(int charc, char** argv) {

  const int screenWidth = 1024;
  const int screenHeight = 768;

  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  // Init control values here
  double angle = 0.04f;
  Vector2 shipMoveVector = {0.0f, -1.0f};

  // Init control structures here
  std::list <Planet*> gravitySources;
  std::list <Particle*> gravityConsumers;
  std::list <Particle*>::iterator iterator;


  // Init objects here
  Ship ship(Vector2{150.0f, 250.0f}, 50.0f);

  Particle* particle;
  for (int ii = 0; ii < 400; ii++)
  {
      particle = new Particle(Vector2{ 100.0f+ii,400.0f+ii/2 }, Vector2{ 3.0f+ii/10.0f,0.0f }, BLACK);
      particle->objectType = objType::PARTICLE;
      gravityConsumers.push_back(particle);
  }
  Planet planet (Vector2{ 400.0f,400.0f }, 50, 50000, BLUE);
  Planet planet2(Vector2{ 650.0f,250.0f }, 60, 70000, DARKBLUE);
  Planet planet3(Vector2{ 100.0f,120.0f }, 30, 30000, BROWN);
  planet.objectType  = objType::PLANET;
  planet2.objectType = objType::PLANET;
  planet3.objectType = objType::PLANET;
  gravitySources.push_back(&planet);
  gravitySources.push_back(&planet2);
  gravitySources.push_back(&planet3);
  //end init objects

  while (!WindowShouldClose()) {

    // Get input
    if (IsKeyDown (KEY_A)) {
      ship.Rotate(-angle);
      RotateUnitVector(shipMoveVector, -angle);
    }
    if (IsKeyDown (KEY_D)) {
      ship.Rotate(angle);
      RotateUnitVector(shipMoveVector, angle);
    }
    if (IsKeyDown (KEY_W)) {
      ship.MoveByVector(shipMoveVector);
    }
    if (IsKeyDown (KEY_S)) {
      Vector2 revVec;
      revVec.x = shipMoveVector.x * -1;
      revVec.y = shipMoveVector.y * -1;
      ship.MoveByVector(revVec);
    }
 
    // Frame begins here
    BeginDrawing();

    ClearBackground(RAYWHITE);
    //calculating forces
    iterator = gravityConsumers.begin();
    while(iterator!=gravityConsumers.end())
    {
        Vector2 acceleration{ 0.0f,0.0f };
        bool particleCollided = false;
        for (Planet* currentPlanet : gravitySources)
        {
            Vector2 partialAcceleration = currentPlanet->GetAcceleration((*iterator)->position);
            acceleration.x += partialAcceleration.x;
            acceleration.y += partialAcceleration.y;
            if (!particleCollided)
            { 
                particleCollided = CheckCollision(*iterator, currentPlanet);
            }

        }
        if (!particleCollided)
        {
            (*iterator)->Update(acceleration);
            iterator++;
        }
        else
        {
            gravityConsumers.remove(*iterator++);
        }
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

    // Drawing ship
    ship.Draw();

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
