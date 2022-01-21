#include "SceneGame.h"

// TEMP INCLUDE
#include <iostream>

SceneGame :: SceneGame(SceneEnum se) : Scene(se) {

  // Randomness init
  std::mt19937_64 randGen(rand());
  std::uniform_int_distribution<> distr(-100, 100);  

  // Init objects here
  Ship* ship = new Ship(shipPlacement, 20.0f);

  this->gravityConsumers.push_back(ship);

  Planet* planet  = new Planet(planetPlacement,  50, 50000,  BLUE);
  Planet* planet2 = new Planet(planet2Placement, 60, 170000, DARKBLUE);
  Planet* planet3 = new Planet(planet3Placement, 30, 30000,  BROWN);

  planet->objectType  = objType::PLANET;
  planet2->objectType = objType::PLANET;
  planet3->objectType = objType::PLANET;
  this->gravitySources.push_back(planet);
  this->gravitySources.push_back(planet2);
  this->gravitySources.push_back(planet3);

};

SceneGame::~SceneGame() {

  // This might not be correct
  // delete[] this->gravitySources;
  // delete[] this->gravityConsumers;

  //delete* this->planet;
  //delete* this->planet2;
  //delete* this->planet3;
};

void SceneGame::render() {
  WriteMessage("SceneGame is here!", 20, 20);

  //drawing
  //
  
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
  // TODO(moliwa): maybe seperate that after some time?

  for (InertObject* currentParticle : gravityConsumers)
  {
      currentParticle->Draw();
  }
    
};
void SceneGame::simulate() {


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

 // End of gathering input


};
