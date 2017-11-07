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



void Application::MainLoop() const
{
	std::vector<float> vertices =
	{
		0,0.5f,0,
		-0.5f,-0.5f,0,
		0.5f,-0.5f,0
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
		//m_display.ManageEvents();
		shader.UseProgram();	
		
		//test input
		SDL_Event e;		
		while (SDL_PollEvent(&e) != 0)
		{
			m_display.ManageEvents(e);
			switch(e.type)
			{
				case SDL_KEYDOWN:
					switch (e.key.keysym.sym)
					{
						case SDLK_UP:
							vel.y += .01f;
							break;
						case SDLK_DOWN:
							vel.y -= .01f;
							break;
						case SDLK_LEFT:
							vel.x -= .01f;
							break;
						case SDLK_RIGHT:
							vel.x += .01f;
							break;
						default:
							break;
					}
					break;
				default:
					break;
			}
		}

		shader.LoadFloat(shader.m_locTime, Time::time); //load uniform float
		shader.LoadVector3(shader.m_locVel, vel); //Load uniform vector
		m_renderer.Render(rect);					//Draw the shape
		shader.StopProgram();

		//Swap and Clear back buffer
		m_display.Clear();
		//Update time
		Time::Tick();
	}
}

