#include "SceneGame.h"


SceneGame :: SceneGame(SceneEnum se) : Scene(se) {

  // Init objects here
  this->ship = new Ship(shipPlacement, 20.0f);

  this->gravityConsumers.push_back(ship);

  Planet* planet  = new Planet(planetPlacement,  50, 50000,  BLUE);
  Planet* planet2 = new Planet(planet2Placement, 60, 170000, DARKBLUE);
  Planet* planet3 = new Planet(planet3Placement, 30, 30000,  BROWN);

  this->gravitySources.push_back(planet);
  this->gravitySources.push_back(planet2);
  this->gravitySources.push_back(planet3);

};

SceneGame::~SceneGame() {
};

void SceneGame::render() {
  // Drawing planets
  for (Planet* currentPlanet : gravitySources)
  {
      currentPlanet->Draw();
  }

  // Drawing smoke
  for (SmokeParticle* smoke : smokeParticles)
  {
      smoke->Draw();
  }

  // Drawing particles
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
     revVec.x = this->ship->shipMoveVector.x * -15 + distr(randGen) / 30.0f;
     revVec.y = this->ship->shipMoveVector.y * -15 + distr(randGen) / 30.0f;
     smokeParticles.push_back(ship->Accelerate());
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

 //calculate acceleration from planets and collisions with planets.
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
             particleCollided = CheckCollision((Object*)*iterator, (Object*)currentPlanet);
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

 //check collisions between other objects - WARNING - BRUTFORCE. TBD - do it better
 if (gravityConsumers.size() > 1)
 {
     iterator = gravityConsumers.begin();
     iterator2 = gravityConsumers.begin();
     std::list <InertObject*> objectToDelete;
     while (iterator != gravityConsumers.end())
     {
         while (iterator2 != gravityConsumers.end())
         {
             if (iterator != iterator2)
             {
                 //if collision occured
                 if (CheckCollision((Object*)*iterator, (Object*)*iterator2))
                 {
                     //delete both objects
                     objectToDelete.push_back(*iterator);
                     objectToDelete.push_back(*iterator2);
                 }
             }
             iterator2++;
         } 
         iterator++;
         iterator2 = gravityConsumers.begin();
     } 
     objectToDelete.sort();
     objectToDelete.unique();
     if (objectToDelete.size() > 0)
     {
         iterator = objectToDelete.begin();
         while (iterator != objectToDelete.end())
         {
             delete (*iterator);
             gravityConsumers.remove(*iterator++);
         }
     }
 }

 // Calculate smoke
 smokeIterator = smokeParticles.begin();
 int howMany = 0;
 while (smokeIterator != smokeParticles.end())
 {
  howMany++;
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

