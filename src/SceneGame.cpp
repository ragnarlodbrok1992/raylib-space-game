#include "SceneGame.h"

//true when collided with any planet
static inline bool UpdateGivenObjectAndCheckPlanetCollision(std::list<Planet*> planets, InertObject* object)
{
    Vector2 acceleration{ 0.0f,0.0f };
    bool particleCollided = false;
    for (Planet* currentPlanet : planets)
    {
        Vector2 partialAcceleration = currentPlanet->GetAcceleration((object)->position);
        acceleration.x += partialAcceleration.x;
        acceleration.y += partialAcceleration.y;
        if (!particleCollided)
        {
            //after first collision no need to search for other collisions
            particleCollided = CheckCollision((Object*)object, (Object*)currentPlanet);
        }
    }
    object->Update(acceleration);
    return particleCollided;
}

// Calculates acceleration and colliosions for given lists of InertObjects.
// Current collision efect: delete object that collided with planet
//TBD: two functions with the same name can be merged into one somehow?
static void CalculatePlanetsEffects(std::list<Planet*> &planets, std::list<InertObject*> &object)
{
    if (object.size() == 0)
    {
        return;
    }
    std::list<InertObject*>::iterator collisionIterator;
    collisionIterator = object.begin();
    while (collisionIterator != object.end())
    {
        bool particleCollided = UpdateGivenObjectAndCheckPlanetCollision(planets, (InertObject*)*collisionIterator);
        if (!particleCollided)
        {
            collisionIterator++;
        }
        else
        {
            delete (*collisionIterator);
            object.remove(*collisionIterator++);
        }
    }
}

// Calculates acceleration and colliosions for given lists of InertObjects.
// Current collision efect: delete object that collided with planet
static void CalculatePlanetsEffects(std::list<Planet*> &planets, std::list<Ship*> &object)
{
    if (object.size() == 0)
    {
        return;
    }
    std::list<Ship*>::iterator collisionIterator;
    collisionIterator = object.begin();
    while (collisionIterator != object.end())
    {
        bool particleCollided = UpdateGivenObjectAndCheckPlanetCollision(planets, (InertObject*)*collisionIterator);
        if (!particleCollided)
        {
            collisionIterator++;
        }
        else
        {
            delete (*collisionIterator);
            object.remove(*collisionIterator++);
        }
    }
}

static void HandleShipToParticlesCollisions(std::list<Ship*> &ships, std::list<InertObject*> &particles)
{
    if ((0 == ships.size()) || (0 == particles.size()))
    {
        return;
    }
    std::list<Ship*>::iterator shipIterator = ships.begin();
    std::list<InertObject*>::iterator particleIterator = particles.begin();
    while (shipIterator != ships.end())
    {
        bool destroyCurrentShip = false;
        while (particleIterator != particles.end())
        {
             //if collision occured
            if (CheckCollision((Object*)*shipIterator, (Object*)*particleIterator))
            {
                //handle collision here:
                (*shipIterator)->health = (*shipIterator)->health - 30.0f;
                delete (*particleIterator);
                particles.remove(*particleIterator++);
                if (((*shipIterator)->health) <= 0)
                {
                    destroyCurrentShip = true;
                }
            }
            else
            {
                particleIterator++;
            }
        }
        if (destroyCurrentShip)
        {
            delete (*shipIterator);
            ships.remove(*shipIterator++);
        }
        else
        {
            shipIterator++;
        }
        particleIterator = particles.begin();
    }
}

static void HandleSmoke(std::list<SmokeParticle*> &smokeParticles)
{
    std::list <SmokeParticle*>::iterator smokeIterator = smokeParticles.begin();
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
}

SceneGame :: SceneGame(SceneEnum se) : Scene(se) {

  // Init objects here
  this->ship = new Ship(shipPlacement, 20.0f);

  this->shipsList.push_back(ship);

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

  for (Ship* ship : shipsList)
  {
      ship->Draw();
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
  CalculatePlanetsEffects(gravitySources,gravityConsumers);
  CalculatePlanetsEffects(gravitySources, shipsList);

  //check collisions: ships with particles
  HandleShipToParticlesCollisions(shipsList, gravityConsumers);

  // Calculate smoke
  HandleSmoke(smokeParticles);

  // Ship status
  if (ship->health > 0) 
  {
      WriteMessage("Ship health: ", ship->health, 20, screenHeight - 80);
      WriteMessage("Velocity: ", VectorLength(ship->velocity), 20, screenHeight - 60);
      WriteMessage("Reload: ", ship->reload, 20, screenHeight - 40);
      WriteMessage("Missile speed: ", ship->missileSpeed, 20, screenHeight - 20);
  }
  //TBD: This is working don't know why. After destruction ship is deallocated so there is garbage inside class fields.
  else
  {
      WriteMessage("Ship ded", 20, screenHeight - 80);
  }
};

