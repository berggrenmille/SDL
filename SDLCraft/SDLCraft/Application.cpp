#include "stdafx.h"
#include "Application.h"
#include "Time.h"
#include "ModelLoader.h"
#include "Shader.h"
#include "TestShader.h"
#include <SDL.h>
#include "Input.h"
using namespace MolecularEngine;


Application::Application(Display& display, Renderer& renderer)
	:	m_display(display), m_renderer(renderer)
{
	MainLoop();
	
}

void Application::ManageEvents() const
{
	SDL_Event e;
	while (SDL_PollEvent(&e) != 0)
	{
		m_display.ManageEvents(e);
	}
	Input::UpdateState();
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
	while (m_display.IsOpen())
	{
		ManageEvents();

		if(Input::GetKeyDown(SDLK_w))
			vel.y += 1.f * Time::delta;
		if(Input::GetKeyDown(SDLK_s))
			vel.y -= 1.f * Time::delta;
		if (Input::GetKeyDown(SDLK_d))
			vel.x += 1.f * Time::delta;
		if (Input::GetKeyDown(SDLK_a))
			vel.x -= 1.f * Time::delta;

		std::cout << Time::time << "\n";
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

