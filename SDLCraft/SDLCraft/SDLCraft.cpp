// SDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Display.h"
#include "Renderer.h"
#include "Application.h"
#include "Input.h"

int main(int argc, char* args[])
{


	Display display1 = Display();
	Renderer renderer1 = Renderer(display1.GetWindow());

	Application game = Application(display1, renderer1);

	return 0;
}
