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

std::vector<float> vertices =
{
	-0.5f,0.5f,0,
	-0.5f,-0.5f,0,
	0.5f,-0.5f,0,
	0.5f,0.5f,0
};
std::vector<int> indices =
{
	0,1,3,
	3,1,2
};

void Application::MainLoop() const
{
	ModelLoader mLoader;
	Model rect = mLoader.LoadToVAO(vertices, indices);
	TestShader* shader = new TestShader();
	while (m_display.IsOpen())
	{
		rect = mLoader.LoadToVAO(vertices, indices);
		m_display.ManageEvents();
		shader->UseProgram();
		m_renderer.Render(rect);
		shader->StopProgram();

		//Swap and Clear back buffer
		m_display.Clear();
		//Update time
		Time::Tick();
	}
	delete shader;
}

