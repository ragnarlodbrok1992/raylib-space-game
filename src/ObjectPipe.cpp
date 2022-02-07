#include"ObjectPipe.h"

static std::list<SmokeParticle*> smokeParticlesList;
static std::list<InertObject*> inertObjectsList;

void GetSmokeParticleFromPipe(std::list<SmokeParticle*>&smoke)
{
	if (0 == smokeParticlesList.size())
	{
		return;
	}
	for (SmokeParticle* newsmoke : smokeParticlesList)
	{
		smoke.push_back(newsmoke);
	}
	smokeParticlesList.clear();
}

void GetInertObjectFromPipe(std::list<InertObject*>&inert)
{
	if (0 == inertObjectsList.size())
	{
		return;
	}
	for (InertObject* newInert : inertObjectsList)
	{
		inert.push_back(newInert);
	}
	inertObjectsList.clear();
}

void AddSmokeParticleToPipe(SmokeParticle* smoke)
{
	smokeParticlesList.push_back(smoke);
}

void AddInertObjectToPipe(InertObject* inert)
{
	inertObjectsList.push_back(inert);
}
