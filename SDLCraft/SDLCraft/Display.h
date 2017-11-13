#pragma once
#include <SDL.h>

class Display
{
public:
	Display(const char* _title = "SDL", int w = 1280, int h = 720);

	void Resize(int w, int h) const;
	
	void Clear() const;
	void UpdateEvents(SDL_Event e);
	bool Initialize();
	void Close();

	SDL_Window& GetWindow() const;
	bool IsOpen() const;

	int WIDTH;
	int HEIGHT;
	const char* title;
private:
	SDL_Window* window;
	SDL_Surface* screen;
	// Our opengl context handle
	SDL_GLContext windowContext;

	
	void SetOpenGLAttributes();
};

