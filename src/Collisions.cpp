#include"Collisions.h"

//source: https://gamedev.stackexchange.com/questions/7735/how-do-i-test-if-a-circle-and-concave-polygon-intersect
static bool CollisionDoCircleCollidedWithPolygon(Vector2 polygonEdges[], unsigned int numberOfEgdes, Vector2 circleCenter, float circleRadius)
{
	// Polygon must have at least 3 edges
	if (numberOfEgdes < 3)
	{
		return false;
	}

	unsigned int current = 0;
	unsigned int next = 0;
	do
	{
		next = (current + 1) % numberOfEgdes;
		float distance = DistancePointToSegment(polygonEdges[current], polygonEdges[next], circleCenter);
		if (circleRadius > distance)
		{
			WriteMessage("collision", 50, 50);//TBD: delete... only for debug purpose for now
	        return true;
			
		}
		current++;
	} while (current % numberOfEgdes != 0);
	return false;
}

bool IsThisTypesCollide(objType first, objType second)
{
	if ((first == objType::PLANET) && (second == objType::PARTICLE))   return true;
	else if ((first == objType::PARTICLE) && (second == objType::PLANET))   return true;
	else if ((first == objType::PARTICLE) && (second == objType::SHIP)) return true;
	else if ((first == objType::SHIP) && (second == objType::PARTICLE)) return true;
	else if ((first == objType::PLANET) && (second == objType::SHIP)) return true;
	else if ((first == objType::SHIP) && (second == objType::PLANET)) return true;
	return false;
}

bool IsCollisionCircleCircle(Object* firstCircle, Object* secondCircle)
{
	float firstRadius = (static_cast<ShapeCircle*>(firstCircle->shapeClassObject))->radius;
	float secondRadius = (static_cast<ShapeCircle*>(secondCircle->shapeClassObject))->radius;
	Vector2 firstPosition = firstCircle->position;
	Vector2 secondPosition = secondCircle->position;
	float distance = GetDistance(firstPosition, secondPosition);
	if (distance <= firstRadius + secondRadius)
	{
		return true;
	}
	return false;
}

bool IsCollisionCircleCircle(Vector2 firstPosition, float firstRadius, Vector2 secondPosition, float secondRadius)
{
	float distance = GetDistance(firstPosition, secondPosition);
	if (distance <= firstRadius + secondRadius)
	{
		return true;
	}
	return false;
}

bool CheckCollision(Object* firstObj, Object* secondObj)
{
	//now only working for shperes/circles
	objType firstType = firstObj->objectType;
	objType secondType = secondObj->objectType;
	objShape firstShape = firstObj->objectShape;
	objShape secondShape = secondObj->objectShape;

	if ((firstType == objType::UNKNOWN) ||
		(secondType == objType::UNKNOWN) ||
		(firstShape == objShape::UNKNOWN) ||
		(secondShape == objShape::UNKNOWN))
	{
		return false;
	}
	if (!IsThisTypesCollide(firstType, secondType))
	{
		return false;
	}

	if ((firstShape == objShape::CIRCLE) && (secondShape == objShape::CIRCLE))
	{
		return IsCollisionCircleCircle(firstObj, secondObj);
	}

	else if (((firstShape == objShape::POLYGON) && (secondShape == objShape::CIRCLE))
		 || ((firstShape == objShape::CIRCLE) && (secondShape == objShape::POLYGON)))
	{

		if (secondShape == objShape::POLYGON)
		{
			SwapPointers((void**)&firstObj, (void**)&secondObj); // we always want to have ship as first object.
		}

		bool circumscribedCirclesColided = IsCollisionCircleCircle(firstObj->position,
																  (static_cast<ShapePolygon*>(firstObj->shapeClassObject))->circumscribedCircleRadius,
															      secondObj->position,
																  (static_cast<ShapeCircle*>(secondObj->shapeClassObject))->radius);
		if (!circumscribedCirclesColided)
		{
			//if this circles don't collide then no way for polygon and circle collide
			return false;
		}

		return CollisionDoCircleCollidedWithPolygon(
			(static_cast<ShapePolygon*>(firstObj->shapeClassObject))->shipCoords,
			(static_cast<ShapePolygon*>(firstObj->shapeClassObject))->vertexNumber,
			secondObj->position,
			(static_cast<ShapeCircle*>(secondObj->shapeClassObject))->radius
		);
	}
	
	return false;
}
