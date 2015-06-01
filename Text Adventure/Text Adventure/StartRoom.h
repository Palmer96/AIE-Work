#ifndef _STARTROOMS_H
#define _STARTROOMS_H

#include "Rooms.h"



class StartRoom : public Rooms
{
public:
	StartRoom();
	~StartRoom();
	void RoomStart();
	void NextRoom();
	//void Map(int Location);

};


#endif //_STARTROOMS_H