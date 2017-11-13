#include "stdafx.h"
#include "Engine.h"
#include "Time.h"
#include "ModelLoader.h"
#include "Shader.h"
#include "TestShader.h"
#include <SDL.h>
#include "Input.h"
#include "Display.h"
#include "Renderer.h"
#include <thread>

using namespace MolecularEngine;
std::unique_ptr<Display&> m_display;
Engine::Engine()
{
	std::unique_ptr<System> inputSystem(new Input(*this));
	std::unique_ptr<System> displaySystem(new Display(*this));
	m_systems.push_back(std::move(displaySystem));
	m_systems.push_back(std::move(inputSystem));
	m_display = std::make_unique<Display&>(*(Display*)m_systems[1].get()); //FIX
	for (unsigned int i = 0; i < m_systems.size(); i++)
	{
		m_systems[i]->Initialize();
	}
	MainLoop();
} 

void Engine::SendMessage(Message msg)
{
	switch (msg.dataID)
	{
		case 0:
			bool* info = (bool*)msg.data;
			if (*info == true)
			{
				m_display->Close();
				delete info;
			}
			break;
	}
}

void Engine::Update() const
{	
	
	for (unsigned int i = 0; i < m_systems.size(); i++)
	{
		m_systems[i]->Update();
	}
}



void Engine::MainLoop() const
{

	std::vector<float> vertices =
	{
		0,0.1f,0,
		-0.1f,-0.1f,0,
		0.1f,-0.1f,0
	};
	std::vector<int> indices =
	{
		0,1,2
	};
	std::vector<float> color =
	{
		1.0f,1.0f,0,
		0,1.0f,1.0f,
		0.5f,0,1.0f
	};

	ModelLoader mLoader;
	Model rect = mLoader.LoadToVAO(vertices, indices, color);
	TestShader shader = TestShader();
	Vector3 vel = Vector3(0, 0, 0);
	Renderer m_renderer(m_display->GetWindow());
	float speed = 1.0f;
	Update();
	while ((*(Display*)m_systems[0].get()).IsOpen())
	{
		
		if (Input::GetKeyDown(SDLK_UP))
			speed += 0.1f;
		if (Input::GetKeyDown(SDLK_DOWN))
			speed -= 0.1f;
		if(Input::GetKeyHold(SDLK_w))
			vel.y += speed * Time::delta;
		if(Input::GetKeyHold(SDLK_s))
			vel.y -= speed * Time::delta;
		if (Input::GetKeyHold(SDLK_d))
			vel.x += speed * Time::delta;
		if (Input::GetKeyHold(SDLK_a))
			vel.x -= speed * Time::delta;
		
		shader.UseProgram();
		shader.LoadFloat(shader.m_locTime, Time::time); //load uniform float into shader
		shader.LoadVector3(shader.m_locVel, vel);		  //load uniform vector into shader
		m_renderer.Render(rect);					      //Render the model
		shader.StopProgram();

		//Update time
		Time::Tick();
		Update();
		

	}
}

