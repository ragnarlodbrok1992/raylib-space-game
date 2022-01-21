#include <list>
#include <random>
#include "src/raylib.h"
#include "src/Planet.h"
#include "src/Particle.h"
#include "src/Ship.h"
#include "src/Utils.h"
#include "src/Collisions.h"
#include "src/SmokeParticle.h"
#include "src/Scene.h"
#include "src/SceneMainMenu.h"
#include "src/SceneGame.h"
#include "src/SceneEditor.h"

// TEMP INCLUDES
#include <iostream>


int main(int charc, char** argv) {

  /* TEMP COMMENT FOR TESTING CODE REFACTORING 
  //prepare random number generator
  // I think this will go into SceneGame
  std::random_device rand;
  std::mt19937_64 randGen(rand());
  std::uniform_int_distribution<> distr(-100, 100);

  // Init control values here
  double angle = 0.04f;
  Vector2 shipMoveVector = {0.0f, -1.0f};

  // Init control structures here
  std::list <Planet*> gravitySources;
  std::list <InertObject*> gravityConsumers;
  std::list <InertObject*>::iterator iterator;
  std::list <SmokeParticle*> smokeParticles;
  std::list <SmokeParticle*>::iterator smokeIterator;

  // Init objects here
  Ship ship(Vector2{250.0f, 200.0f}, 20.0f);
  gravityConsumers.push_back(&ship);

  Planet planet (Vector2{ 1000.0f,600.0f }, 50, 50000, BLUE);
  Planet planet2(Vector2{ 650.0f,350.0f }, 60, 170000, DARKBLUE);
  Planet planet3(Vector2{ 100.0f,120.0f }, 30, 30000, BROWN);
  planet.objectType  = objType::PLANET;
  planet2.objectType = objType::PLANET;
  planet3.objectType = objType::PLANET;
  gravitySources.push_back(&planet);
  gravitySources.push_back(&planet2);
  gravitySources.push_back(&planet3);
  //end init objects
  */
  
  InitWindow(screenWidth, screenHeight, "RayLib Space Game");

  SetTargetFPS(60);

  // Init scenes here
  // TODO: Should here we have all the scenes? Or construct them/ destruct at runtime?
  // Entry scene: main menu for now
  SceneMainMenu* sceneMainMenu = new SceneMainMenu(SceneEnum::MAINMENU);
  SceneGame*     sceneGame     = new SceneGame(SceneEnum::GAMESCENE);
  SceneEditor*   sceneEditor   = new SceneEditor(SceneEnum::EDITOR);
  Scene*         selectedScene;

  // Start scene is main menu
  selectedScene = sceneMainMenu;


  while (!WindowShouldClose()) {

    /* TEMP COMMENT FOR TESTING CODE REFACTORING 
    // Get input
    if (IsKeyDown (KEY_A)) 
    {
      ship.Rotate(Ship::COUNTERCLOCKWISE);
    }
    if (IsKeyDown (KEY_D)) 
    {
      ship.Rotate(Ship::CLOCKWISE);
    }
    if (IsKeyDown (KEY_W)) 
    {
        ship.velocity.x += ship.shipMoveVector.x* ship.thrustAcceleration;
        ship.velocity.y += ship.shipMoveVector.y * ship.thrustAcceleration;
        Vector2 revVec;
        revVec.x = ship.shipMoveVector.x * -15 + distr(randGen) / 30.0f;
        revVec.y = ship.shipMoveVector.y * -15 + distr(randGen) / 30.0f;
        SmokeParticle* smoke = new SmokeParticle(ship.position, revVec, 150+distr(randGen));
        //ship.Accelerate(smoke);
        smokeParticles.push_back(smoke);
    }
    if (IsKeyPressed(KEY_SPACE))
    {
        if (ship.reload >= ship.reloaded)
        {
            ship.chargingMissile = true;
            ship.missileSpeed = 3.0f;
            ship.reload = 0;
        }
    }
    if (IsKeyDown(KEY_SPACE))
    {
        if (true == ship.chargingMissile)
        {
            ship.missileSpeed += 0.5;
        }
    }
    if (IsKeyReleased(KEY_SPACE))
    {
        if (ship.chargingMissile == true)
        {
            gravityConsumers.push_back(ship.FireMissile());
            ship.missileSpeed = 0.0f;
            ship.chargingMissile = false;
        }
    }
    if (!ship.chargingMissile)
    {
        if(ship.reload<ship.reloaded) ship.reload++;
    }

    backward thrust to be deleted?
    if (IsKeyDown (KEY_S)) {
      Vector2 revVec;
      revVec.x = shipMoveVector.x * -1;
      revVec.y = shipMoveVector.y * -1;
      ship.MoveByVector(revVec);
    }
    
    */

    // Selecting scene - right now with 1,2,3 keys
    if      (IsKeyPressed(KEY_ONE)) {
      selectedScene = sceneMainMenu;
      std::cout << "Pressing 1!\n";
    }
    else if (IsKeyPressed(KEY_TWO)) {
      selectedScene = sceneGame;
      std::cout << "Pressing 2!\n";
    }
    else if (IsKeyPressed(KEY_THREE)) {
      selectedScene = sceneEditor;
      std::cout << "Pressing 3!\n";
    }
 
    // Frame begins here
    BeginDrawing();

    ClearBackground(RAYWHITE);

    // Select scene to render
    selectedScene->render();
    selectedScene->simulate();

    /* TEMP COMMENT FOR TESTING CODE REFACTORING 
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
            delete (*iterator);
            gravityConsumers.remove(*iterator++);
        }
    }

    //calculate smoke
    smokeIterator = smokeParticles.begin();
    while (smokeIterator != smokeParticles.end())
    {
        (*smokeIterator)->Update({ 0.0f,0.0f });
        if (0 == (*smokeIterator)->lifetime)
        {
            delete (*smokeIterator);
            smokeParticles.remove(*smokeIterator++);
        }
        else
        {
            smokeIterator++;
        }
    }

    //ship status
    WriteMessage("Velocity: ", VectorLength(ship.velocity), 20, screenHeight - 60);
    WriteMessage("Reload: ", ship.reload, 20, screenHeight - 40);
    WriteMessage("Missile speed: ", ship.missileSpeed, 20, screenHeight - 20);

    //drawing
    for (Planet* currentPlanet : gravitySources)
    {
        currentPlanet->Draw();
    }
    //draw smoke
    for (SmokeParticle* smoke : smokeParticles)
    {
        smoke->Draw();
    }
    //ship is an inert object so it will be drawn here
    for (InertObject* currentParticle : gravityConsumers)
    {
        currentParticle->Draw();
    }
    */

    EndDrawing();
  }

  CloseWindow();

  return 0;
}
