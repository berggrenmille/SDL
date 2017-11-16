#include "stdafx.h"
#include "Engine.h"
#include "Time.h"
#include "Input.h"
#include "Renderer.h"
#include "Display.h"
#include "ModelLoader.h"
#include "Shader.h"
#include "TestShader.h"
#include <SDL.h>
#include <thread>
#include "PrimitiveShapes.h"

using namespace MolecularEngine;


Engine::Engine()
{
	Display disSystem = Display(*this);
	Input inputSystem = Input(*this);
	Time timeSystem = Time(*this);

	CreateSystem(&disSystem, F_INITIALIZABLE | F_UPDATABLE | F_UPDATABLE);
	CreateSystem(&inputSystem, F_MESSAGE_OBSERVER | F_UPDATABLE);
	CreateSystem(&timeSystem, F_UPDATABLE);
	m_display = reinterpret_cast<Display*>(GetListElementAtIndex(m_systems,0));
	Loop();
} 

bool Engine::CreateSystem(System* _system, int flag)
{
	if (_system == nullptr)
		return false;
	if ((flag & F_INITIALIZABLE) > 0)
	{
		if (!_system->Init()) {}
			//Something went wrong
			
	}
		
	m_systems.push_back(_system);
	if (flag & 1 << 0)
	{
		//subsystem = observer of messagebus
	}
	if (flag & 1 << 1)
	{
		//subsystem = updatable
	}
	return true;
}

void Engine::SendMessage(Message msg)
{
	switch (msg.dataID)
	{
		default:
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

void Engine::Update() 
{	
	for (unsigned int i = 0; i < m_systems.size(); i++)
	{
		GetListElementAtIndex(m_systems, i)->Update();
	}
}



void Engine::Loop()
{


	ModelLoader mLoader = ModelLoader();
	
	Model tri = PrimitiveShapes::Rect(mLoader,2,2);
	TestShader shader = TestShader();
	Vector3 vel = Vector3(0, 0, 0);
	Renderer m_renderer(m_display->GetWindow());
	float speed = 1.0f;
	Update();
	while (m_display->IsOpen())
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
		m_renderer.Render(tri);					      //Render the model
		shader.StopProgram();

		//Update time
		//Time::Tick();
		Update();
		

	}
}

