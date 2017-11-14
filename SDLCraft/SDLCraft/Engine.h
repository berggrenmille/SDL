#pragma once

#include "System.h"
#include "Message.h"
#include "Display.h"
class Display;

class Engine
{
public:
	Engine();

	void SendMessage(Message msg);
private:
	bool running = true;
	void MainLoop() const;
	void Update() const;

	Display* m_display = nullptr;

#define MESSAGE_OBSERVER (1<<0)
	//00000001
#define UPDATABLE (1<<1)
	//00000010
#define Initializable (1<<2)
	//00000100

	bool CreateSystem(System* _system, int _flag);
	std::vector<System*> m_systems;
};
