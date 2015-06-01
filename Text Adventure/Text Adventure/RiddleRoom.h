#ifndef _RIDDLEROOMS_H
#define _RIDDLEROOMS_H

#include "Rooms.h"



class RiddleRoom : public Rooms
{
public:
	RiddleRoom();
	~RiddleRoom();
	void RoomStart();
	void NextRoom();
	//void Map(int Location);

};



#endif //_RIDDLEROOMS_H