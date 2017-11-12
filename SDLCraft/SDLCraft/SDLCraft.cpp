// SDL.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "SDL.h"
#include "Display.h"
#include "Renderer.h"
#include "Engine.h"
#include "MolecularEngine.h"
using namespace MolecularEngine;

int main(int argc, char* args[])
{
	
	Engine engine = Engine();


	return 0;

}
//NOTE: This is a way to "cheat with sdl built-in api for threads" 
/*SDL_THREAD t1 = SDL_CreateThread(StaticTestFunc, "InouThread", this)
 *
int Foo::StaticTestfunc(void* data)
{
	Engine* self = static_cast<Engine*>(data);
	return self->Update();
}

int Foo::TestFunc(void)
{
*/




