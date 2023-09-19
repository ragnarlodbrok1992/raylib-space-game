#include "include/SceneGame.h"
#include "../raylib.h"
#include "../toRaylibConversion.h"


//true when collided with any planet
static inline bool UpdateGivenObjectAndCheckPlanetCollision(std::list<Planet*> planets, InertObject* object)
{
    rVector2 acceleration{ 0.0f,0.0f };
    bool particleCollided = false;
    for (Planet* currentPlanet : planets)
    {
        rVector2 partialAcceleration = currentPlanet->GetAcceleration((object)->position);
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

static bool is_local_player_ship(Ship* ship)
{
    // if ship is not "player ship" player will be null pointer
    if (PlayerShip* player = dynamic_cast<PlayerShip*>(ship))
    {
        if (PlayerType::LOCAL == player->playerType)
        {
            return true;
        }
    }
    return false;
}

SceneGame :: SceneGame(SceneEnum se) : Scene(se) {
    this->shipMoveVector = { 0.0f, -1.0f };
  // Init objects here
    playerKeyMap_t player1Keys;
    player1Keys.accelerate = KEY_W;
    player1Keys.fire = KEY_SPACE;
    player1Keys.rotateClockwise = KEY_D;
    player1Keys.rotateCounterclockwise = KEY_A;
  PlayerShip* ship = new PlayerShip(shipPlacement, 20.0f, player1Keys);

  this->shipsList.push_back(ship);

  Planet* planet  = new Planet(this->planetPlacement,  50, 50000,  convert(BLUE));
  Planet* planet2 = new Planet(this->planet2Placement, 60, 170000, convert(DARKBLUE));
  Planet* planet3 = new Planet(this->planet3Placement, 30, 30000,  convert(BROWN));

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

void SceneGame::process_input() {
  // Handling input events
  for (Ship* ship : shipsList)
  {
      if (is_local_player_ship(ship))
      {
          dynamic_cast<PlayerShip*>(ship)->HandlePressedKeys();
      }       
  }
}

void SceneGame::simulate() {

  GetSmokeParticleFromPipe(smokeParticles);
  GetInertObjectFromPipe(gravityConsumers);

  //calculate acceleration from planets and collisions with planets.
  CalculatePlanetsEffects(gravitySources,gravityConsumers);
  CalculatePlanetsEffects(gravitySources, shipsList);

  //check collisions: ships with particles
  HandleShipToParticlesCollisions(shipsList, gravityConsumers);

  // Calculate smoke
  HandleSmoke(smokeParticles);

  // Ship status
  for (Ship* ship : shipsList)
  {
      if (ship->health > 0)
      {
          WriteMessage("Ship health: ", ship->health, 20, screenHeight - 80);
          WriteMessage("Velocity: ", VectorLength(ship->velocity), 20, screenHeight - 60);
          WriteMessage("Reload: ", ship->reload, 20, screenHeight - 40);
          WriteMessage("Missile speed: ", ship->missileSpeed, 20, screenHeight - 20);
      }
  }
  if(0==shipsList.size())
  {
      WriteMessage("Ship ded", 20, screenHeight - 80);
  }

};

rVector2 SceneGame::get_player_position()
{
    for (Ship* ship : shipsList)
    {
        if (is_local_player_ship(ship))
        {
            return ship->position;
        }
    }
}

rVector2 SceneGame::get_player_velocity()
{
    for (Ship* ship : shipsList)
    {
        if (is_local_player_ship(ship))
        {
            return ship->velocity;
        }
    }
}

