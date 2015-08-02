#pragma once
#include "IBehaviour.h"



class Seek : public IBehaviour
{
public:
	Seek();
	~Seek();

	virtual void Update(Agents *pAgent);
};

