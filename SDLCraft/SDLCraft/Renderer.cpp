#include "stdafx.h"
#include "Renderer.h"
#include <GL/glew.h>


Renderer::Renderer(SDL_Window& window)
	:	boundWindow(window)
{
	std::cout << "Renderer initialized!\n";
}

void Renderer::Render(Model model)
{
	glBindVertexArray(model.GetVaoID());			//Bind vertex array
	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glDrawElements(GL_TRIANGLES, model.GetVertexCount(), GL_UNSIGNED_INT, 0);
	glDisableVertexAttribArray(0);
	glBindVertexArray(0);							//Unbind Vertex array
}


