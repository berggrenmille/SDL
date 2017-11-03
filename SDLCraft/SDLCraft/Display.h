#pragma once
#include <SDL.h>

class Display
{
public:
	Display(const char* _title = "SDL", int w = 1280, int h = 720);

	void Resize(int w, int h);
	void Close();
	void Clear();
	void ManageEvents();

	SDL_Window& GetWindow() const;
	bool IsOpen() const;
private:
	SDL_Window* window;
	SDL_Surface* screen;
	// Our opengl context handle
	SDL_GLContext windowContext;

	int WIDTH;
	int HEIGHT;
	const char* title;

	bool Initialize();
	void SetOpenGLAttributes();
};

