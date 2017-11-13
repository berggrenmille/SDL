#pragma once
#include "Display.h"
#include "Renderer.h"
#include "System.h"
#include "Input.h"
#include "Message.h"

class Engine
{
public:
	Engine();

	void SendMessage(Message msg);
private:
	bool running = true;
	void MainLoop() const;
	void Update() const;

	Display& m_display;
	Renderer& m_renderer;

	std::vector<std::unique_ptr<System>> m_systems;
};