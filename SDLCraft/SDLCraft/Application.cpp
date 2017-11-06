#include "stdafx.h"
#include "Application.h"
#include "Time.h"
#include "ModelLoader.h"
#include "Shader.h"
#include "TestShader.h"

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
	ModelLoader mLoader;
	Model rect = mLoader.LoadToVAO(vertices, indices);
	TestShader shader = TestShader();
	while (m_display.IsOpen())
	{
		m_display.ManageEvents();
		shader.UseProgram();
		shader.LoadFloat(shader.m_locSinTime, sin(Time::time));
		m_renderer.Render(rect);
		shader.StopProgram();

		//Swap and Clear back buffer
		m_display.Clear();
		//Update time
		Time::Tick();
	}
}

