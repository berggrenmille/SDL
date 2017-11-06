#include "stdafx.h"
#include "Application.h"
#include "Time.h"
#include "ModelLoader.h"
#include "Shader.h"
#include "TestShader.h"
#include <SDL.h>


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
	
	while (m_display.IsOpen())
	{
		m_display.ManageEvents();
		shader.UseProgram();	
		Vector3 vel = Vector3(0,0,0);
		//test input
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_KEYDOWN)
			{
				if (e.key.keysym.sym == SDLK_UP)
				{
					vel.y += .1f;
				}
				else if (e.key.keysym.sym == SDLK_DOWN)
				{
					vel.x -= .1f;
				}
				else if (e.key.keysym.sym == SDLK_RIGHT)
				{
					vel.x += .1f;
				}
				else if (e.key.keysym.sym == SDLK_LEFT)
				{
					vel.x -= .1f;
				}
			}
		}

		shader.LoadFloat(shader.m_locTime, Time::time);
		shader.LoadVector3(shader.m_locVel, vel);
		m_renderer.Render(rect);
		shader.StopProgram();

		//Swap and Clear back buffer
		m_display.Clear();
		//Update time
		Time::Tick();
	}
}

