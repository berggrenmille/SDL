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
	Vector3 vel = Vector3(0, 0, 0);
	while (m_display.IsOpen())
	{
		//m_display.ManageEvents();
		shader.UseProgram();	
		
		//test input
		SDL_Event e;
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) //Exit program
				m_display.Close();
			if (e.window.event == SDL_WINDOWEVENT_RESIZED)
			{
				SDL_Log("Window %d resized to %dx%d",
					e.window.windowID, e.window.data1,
					e.window.data2);
				m_display.WIDTH = e.window.data1; m_display.HEIGHT = e.window.data2;
				m_display.Resize(e.window.data1, e.window.data2);
			}
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

