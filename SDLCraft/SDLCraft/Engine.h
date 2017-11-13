#pragma once

#include "System.h"
#include "Message.h"
#include "Display.h"

class Engine
{
public:
	Engine();

	void SendMessage(Message msg);
private:
	bool running = true;
	void MainLoop() const;
	void Update() const;


	std::vector<std::unique_ptr<System>> m_systems;
};
