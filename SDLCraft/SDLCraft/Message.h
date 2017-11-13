#pragma once

struct Message
{
	Message();
	Message(int toID, int dataID, void* params = NULL);
	~Message();
	int toID;
	int dataID;
	void* data;

	bool* GetBool();
	int* GetInt();
	double* GetDouble();
	char* GetChar;

};