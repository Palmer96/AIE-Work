#include "Behaviours.h"
#include "Agents.h"
#include "GameObject.h"
#include <random>
#include <time.h>

Vector2 Seek::Update(Agents* agent)
{
	return (Normalize(*target - *agent->position) * agent->speed) - agent->velocity;
}
void Seek::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}


Vector2 Flee::Update(Agents* agent)
{
	return ((Normalize(*agent->position - *target) * agent->speed) - agent->velocity);
}
void Flee::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}


Vector2 Wander::Update(Agents* agent)
{
	circle = agent->velocity;

	if (!(circle == Vector2(0.0f, 0.0f)))
		circle.Normalize();

	circle *= distance;

	srand(time(NULL));
	int angle = rand();

	displacement.x = cos(angle) * radius;
	displacement.y = sin(angle) * radius;

	return (Normalize(circle + displacement) * agent->speed) - agent->velocity;

}

Vector2 Pursue::Update(Agents* agent)
{
	return (Normalize(target->position + target->AI->velocity - *agent->position) * agent->speed) - agent->velocity;
}
void Pursue::SetTarget(GameObject* a_target)
{
	this->target = a_target;
}


Vector2 Evade::Update(Agents* agent)
{
	return (Normalize(*agent->position - target->position + target->AI->velocity) * agent->speed) - agent->velocity;
}
void Evade::SetTarget(GameObject* a_target)
{
	this->target = a_target;
}


Vector2 Arrival::Update(Agents* agent)
{
	Vector2 dir = Normalize(*target - *agent->position);
	float dist = Magnitude(*target - *agent->position);

	Vector2 seekForce = dir * agent->speed;

	float scalar = Clamp(dist / 100.0f, std::numeric_limits<float>::min(), 1);

	if (scalar < 1)
	{
		seekForce *= scalar;
		seekForce += (Normalize(agent->velocity) * -1) * Magnitude(agent->velocity) * Dot(dir, Normalize(agent->velocity)) * 2;
	}

	return seekForce - agent->velocity;


};
void Arrival::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}



Vector2 Avoid::Update(Agents* agent)
{
	//Vector2 dir = Normalize(*target - *agent->position);
	//float dist = Magnitude(*target - *agent->position);
	//
	//Vector2 seekForce = dir * agent->speed;
	//
	//float scalar = Clamp(dist / 100.0f, std::numeric_limits<float>::min(), 1);
	//
	//if (scalar < 1)
	//{
	//	seekForce *= scalar;
	//	seekForce += (Normalize(agent->velocity) * -1) * Magnitude(agent->velocity) * Dot(dir, Normalize(agent->velocity)) * 2;
	//}
	//
	//return seekForce - agent->velocity;
	return Vector2();

};
void Avoid::SetTarget(Vector2* a_target)
{
	this->target = a_target;
}