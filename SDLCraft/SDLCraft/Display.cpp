#include "stdafx.h"
#include "Display.h"
#include <SDL.h>
#include "GL/glew.h"


Display::Display(const char* _title, int w, int h)
	:	WIDTH(w),HEIGHT(h),title(_title)
{
	if (!Initialize())
	{
		printf("SDL could not initialize!\n");
	}
	else
	{
		printf("SDL initialized!\n");
	}
}

// Initialize SDL's subsystems
bool Display::Initialize()
{
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0)
	{
		printf("SDL could not be initialized! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	// Create window
	window = SDL_CreateWindow
	(title, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE | SDL_WINDOW_OPENGL);

	if (window == nullptr)
	{
		printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
		return false;
	}

	//Create surface
	screen = SDL_GetWindowSurface(window);

	// Create our opengl context and attach it to our window
	windowContext = SDL_GL_CreateContext(window);
	SetOpenGLAttributes();

	// Init GLEW
	GLenum error = glewInit();
	if (error == GLEW_OK)
	{
		printf("GLEW Status : %s\n", glewGetErrorString(error));
		printf("GLEW Version : %s\n", glewGetString(GLEW_VERSION));
	}
	else
	{
		printf("GLEW Status : %s\n", glewGetErrorString(error));
		return false;
	}
	glViewport(0, 0, WIDTH,HEIGHT);
	return true;
}

void Display::SetOpenGLAttributes()
{
	// SDL_GL_CONTEXT_CORE disables deprecated funtions
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	// 3.2 is mostly modern OpenGL, the majority of video cards is able to run this
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 2);

	// Turn on double buffering with a 24bit Z buffer.
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);

	// Print GL version
	int value = 0;
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, &value);
	std::cout << "GL Version : " << value << '.';
	SDL_GL_GetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, &value);
	std::cout << value << std::endl;

}


void Display::ManageEvents(SDL_Event e)
{
	if (e.type == SDL_QUIT || (e.type == SDL_KEYDOWN && e.key.keysym.sym == SDLK_ESCAPE)) //Exit program
		Close();
	if (e.window.event == SDL_WINDOWEVENT_RESIZED)
	{
		SDL_Log("Window %d resized to %dx%d",
			e.window.windowID, e.window.data1,
			e.window.data2);
		WIDTH = e.window.data1; HEIGHT = e.window.data2;
		Resize(e.window.data1, e.window.data2);
	}
}

void Display::Clear()
{
	SDL_GL_SwapWindow(window);
	glClearColor(0.0f, 0.0f, 0.f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}


void Display::Resize(int w, int h)
{
	glViewport(0, 0, w, h);
	SDL_SetWindowSize(window, w, h);
}

void Display::Close()
{
	SDL_GL_DeleteContext(windowContext);
	SDL_DestroyWindow(window);
	window = nullptr;
	SDL_Quit();
}


SDL_Window& Display::GetWindow() const
{
	return *window;
}

bool Display::IsOpen() const
{
	return window != nullptr;
}


