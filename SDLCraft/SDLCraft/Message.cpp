#include "stdafx.h"
#include "Message.h"

Message::Message(int _msgID, int _dataID, void* _data)
{
	this->msgID = _msgID;
	this->dataID = _dataID;
	this->data = _data;
}

Message::~Message()
{
	switch (dataID)
	{
	case 0:
		break;
	case 1:
		break;
	}
}

bool* Message::GetBool()
{
	return reinterpret_cast<bool*>(data);
}
int* Message::GetInt()
{
	return reinterpret_cast<int*>(data);
}
double* Message::GetDouble()
{
	return reinterpret_cast<double*>(data);
}
char* Message::GetChar()
{
	return reinterpret_cast<char*>(data);
}