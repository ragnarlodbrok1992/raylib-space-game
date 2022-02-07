#pragma once
#include <list>
#include "raylib.h"
#include "Ship.h"
#include "SmokeParticle.h"
#include "InertObject.h"

// Header with functions that allow objects on SceneGame to generate another objects.
// Generated ojects should be placed into pipe using "Add<object>ToPipe" ex. "AddSmokeParticleToPipe"
// SceneGame should update its lists of objects using functions "Get<Object>FromPipe" ex. "GetSmokeParticleFromPipe"

void GetSmokeParticleFromPipe(std::list<SmokeParticle*>& smoke);
void GetInertObjectFromPipe(std::list<InertObject*>& inert);

void AddSmokeParticleToPipe(SmokeParticle* smoke);
void AddInertObjectToPipe(InertObject* inert);
