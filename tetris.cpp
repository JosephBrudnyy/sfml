#include <SFML/Graphics.hpp>
 
using namespace sf; 
 
const int M = 20;
const int N = 10;

int field[M][N] = { 0 };

int figures[7][4]=
{
	1,3,5,7, // I
	2,4,5,7, // S
	3,5,4,6, // Z
	3,5,4,7, // T
	2,3,5,7, // L
	3,5,7,6, // J
	2,3,4,5, // O
};
 

int main()
{	
	
	
	RenderWindow window(VideoMode(380, 480), "The Game!");
 	Texture texture;
 	texture.loadFromFile("F:\\dev\\tiles.png");
 	
 	Sprite sprite(texture);
	
	sprite.setTextureRect(IntRect(0,0,18,18));
	
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
	
	
	
	window.clear(Color::White);
	
	
	
	window.draw(sprite);
	
	window.display();
	}

}
