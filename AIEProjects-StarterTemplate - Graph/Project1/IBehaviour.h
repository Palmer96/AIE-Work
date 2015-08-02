#pragma once

class Agents;

class IBehaviour
{
public:
	IBehaviour();
	~IBehaviour();

	virtual void Update(Agents *pAgent);
};

