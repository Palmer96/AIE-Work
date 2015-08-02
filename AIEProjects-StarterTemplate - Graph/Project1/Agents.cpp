#include "Agents.h"


Agents::Agents()
{
}


Agents::~Agents()
{
}

void Agents::Update(float deltaTime)
{
	// Sense
		// check the environment

	// Think
		// choose Behaviour

	//Act
		// use behaviour

	for (auto iter = m_behaviours.begin(); iter != m_behaviours.end(); iter++)
		(*iter)->Update(this);

	

	// Physics
		// force		AddForce();
		// acceleration
		// velocity
}
void Agents::Draw()
{

}
void Agents::AddForce()
{
	m_position += m_force;
}
