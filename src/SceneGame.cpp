#include "SceneGame.h"

// TEMP INCLUDE
#include <iostream>

SceneGame :: SceneGame(SceneEnum se) : Scene(se) {

  // Randomness init
  std::mt19937_64 randGen(rand());
  std::uniform_int_distribution<> distr(-100, 100);  

  // Init objects here
  this->ship = new Ship(shipPlacement, 20.0f);

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
   this->ship->Rotate(Ship::COUNTERCLOCKWISE);
 }
 if (IsKeyDown (KEY_D)) 
 {
   this->ship->Rotate(Ship::CLOCKWISE);
 }

 
 if (IsKeyDown (KEY_W)) 
 {
     this->ship->velocity.x += this->ship->shipMoveVector.x * this->ship->thrustAcceleration;
     this->ship->velocity.y += this->ship->shipMoveVector.y * this->ship->thrustAcceleration;
     Vector2 revVec;

     //TODO (moliwa): This stuff here for randomness requiress some mangling
     revVec.x = this->ship->shipMoveVector.x * -15 + distr(randGen) / 30.0f;
     revVec.y = this->ship->shipMoveVector.y * -15 + distr(randGen) / 30.0f;
     SmokeParticle* smoke = new SmokeParticle(this->ship->position, revVec, 150+distr(randGen));
     //ship.Accelerate(smoke);
     smokeParticles.push_back(smoke);
 }

 
 if (IsKeyPressed(KEY_SPACE))
 {
     if (this->ship->reload >= this->ship->reloaded)
     {
         this->ship->chargingMissile = true;
         this->ship->missileSpeed = 3.0f;
         this->ship->reload = 0;
     }
 }
 if (IsKeyDown(KEY_SPACE))
 {
     if (true == this->ship->chargingMissile)
     {
         this->ship->missileSpeed += 0.5;
     }
 }
 if (IsKeyReleased(KEY_SPACE))
 {
     if (this->ship->chargingMissile == true)
     {
         gravityConsumers.push_back(ship->FireMissile());
         this->ship->missileSpeed = 0.0f;
         this->ship->chargingMissile = false;
     }
 }


 if (!this->ship->chargingMissile)
 {
     if(this->ship->reload < this->ship->reloaded) this->ship->reload++;
 }

 // End of gathering input
 //calculating forces
 // TODO(moliwa): Fix stuff here
 
 iterator = gravityConsumers.begin();
 while (iterator != gravityConsumers.end())
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

 // Calculate smoke
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
 

 // Ship status
 WriteMessage("Velocity: ", VectorLength(ship->velocity), 20, screenHeight - 60);
 WriteMessage("Reload: ", ship->reload, 20, screenHeight - 40);
 WriteMessage("Missile speed: ", ship->missileSpeed, 20, screenHeight - 20);

};
