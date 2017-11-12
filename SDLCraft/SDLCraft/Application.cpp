#include "stdafx.h"
#include "Application.h"
#include "Time.h"
#include "ModelLoader.h"
#include "Shader.h"
#include "TestShader.h"
#include <SDL.h>
#include "Input.h"
#include <thread>
using namespace MolecularEngine;


Application::Application()
	: m_display(Display()), m_renderer(Renderer(m_display.GetWindow()))
{
	MainLoop();
} 


void Application::ManageEvents() const
{	
	SDL_Event e;
	while (SDL_PollEvent(&e))
	{
		m_display.ManageEvents(e);
		Input::UpdateEventState(e);
	}
	Input::UpdateKeyState();
}



void Application::MainLoop() const
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
	float speed = 1.0f;
	while (m_display.IsOpen())
	{
		ManageEvents();
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

		//Swap buffers and Clear the back buffer
		m_display.Clear();
		//Update time
		Time::Tick();
	}
}

