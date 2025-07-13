#pragma once
#ifndef H_SMOKEPARTICLE
#define H_SMOKEPARTICLE
#include"InertObject.h"

class SmokeParticle : public InertObject
{
private:
	rColor color; //color will fade out in lifetime
	const float radius = 1.5f;
	const float fadingStrength; //how much per frame black should become more white
	float currentfade = 255.0f;

public:
	unsigned int lifetime; //lifetime in frames
	SmokeParticle(rVector2 position, rVector2 velocity, unsigned int lifetime);

	void Update(rVector2 acceleration);
	void Draw();
};

#endif /* H_SMOKEPARTICLE */

