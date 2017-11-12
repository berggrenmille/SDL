// SDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Display.h"
#include "Renderer.h"
#include "Application.h"
#include "MolecularEngine.h"
using namespace MolecularEngine;

int main(int argc, char* args[])
{
	
	Application app = Application();

	return 0;

}
//NOTE: This is a way to "cheat with sdl build in api for threads" 
/*SDL_THREAD t1 = SDL_CreateThread(StaticTestFunc, "InouThread", this)
 *
int Foo::StaticTestfunc(void* data)
{
	Application* self = static_cast<Application*>(data);
	return self->ManageEvents();
}

int Foo::TestFunc(void)
{
*/




