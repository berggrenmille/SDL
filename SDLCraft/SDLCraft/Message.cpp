#include "stdafx.h"
#include "Message.h"

Message::Message()
{
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
Message::Message(int ID, int dataID, void* params)
{
	this->toID = ID;
	this->dataID = dataID;
	this->data = params;
}
