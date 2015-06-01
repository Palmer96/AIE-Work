#ifndef _RIDDLEROOMS_H
#define _RIDDLEROOMS_H

#include "Rooms.h"



class EndRoom : public Rooms
{
public:
	EndRoom();
	~EndRoom();
	void RoomStart();
	void NextRoom();
	//void Map(int Location);

};



#endif //_RIDDLEROOMS_H