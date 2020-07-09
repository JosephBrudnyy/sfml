#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace sf; 
 
int main()
{
	RenderWindow window(VideoMode(800, 600), "3angle");
	
	
	
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		
		window.display();
	}



}
