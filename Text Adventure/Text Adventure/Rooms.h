#ifndef _ROOMS_H
#define _ROOMS_H




class Rooms
{
public:

	Rooms();
	~Rooms();
	virtual void RoomStart();
	virtual void NextRoom();
	virtual void Map(int Location);

protected:
	char* RoomName = nullptr;
	int roomNum;

};




#endif //_ROOMS_H