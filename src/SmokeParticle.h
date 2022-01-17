#pragma once
#include"InertObject.h"

class SmokeParticle : public InertObject
{
private:
	Color color; //color will fade out in lifetime
	const float radius = 1.5f;
	const float fadingStrength; //how much per frame black should become more white
	float currentfade = 255.0f;

public:
	unsigned int lifetime; //lifetime in frames
	SmokeParticle(Vector2 position, Vector2 velocity, unsigned int lifetime);

	void Update(Vector2 acceleration);
	void Draw();
};