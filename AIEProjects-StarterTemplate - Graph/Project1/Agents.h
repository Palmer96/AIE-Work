#pragma once

#include <vector>
#include "MathLib.h"
#include "IBehaviour.h"



class Agents
{
public:
	Agents();
	~Agents();

	virtual void Update(float deltaTime);
	virtual void Draw();
	void AddForce();



protected:

	std::vector < IBehaviour * > m_behaviours;

	Vector2 m_position;
	Vector2 m_velocity;
	Vector2 m_acceleration;
	Vector2 m_force;



};
