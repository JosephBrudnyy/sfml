#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>
#pragma comment(lib, "glu32.lib")
using namespace sf;


int main()
{
	
	RenderWindow window(VideoMode(800,600), "Test");
	
	Texture t;
	t.loadFromFile("resources/background.jpg");
	Sprite background(t);
	
	GLuint texture = 0;
	{
		Image image;
		image.loadFromFile("resources/texture.jpg");
		
		glGenTextures(1, &texture);
		
	}
	
	
}
