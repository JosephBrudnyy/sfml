#include <SFML/Graphics.hpp>
 
using namespace sf; 
 
int main()
{	
	ContextSettings settings;
	settings.antialiasingLevel = 0;
	
	
	RenderWindow window(VideoMode(500, 300), "SFML Works!");
 

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
	
	
	
	window.clear(Color::White);
	
	Texture texture;
	
	texture.loadFromFile("F:\\dev\\idle1.png");
	
	Sprite sprite(texture);
	sprite.setPosition(100, 0);

	
	window.draw(sprite);
	window.display();
	
	}
}
