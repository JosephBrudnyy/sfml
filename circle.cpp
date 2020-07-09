#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace sf; 
 
int main()
{	
	ContextSettings settings;
	settings.antialiasingLevel = 0;
	RenderWindow window(VideoMode(800, 600), "SFML Works!");
 	
 	double velocity = 1;
 	double r = 292;
 	double a = 1;
 	double planetX = 100;
 	double planetY = 292;
 
 

	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		////////////////
		CircleShape sun(16);
		sun.setFillColor(Color::Yellow);
		sun.setPosition(392, 292);
		window.draw(sun);
		///////////////
		
		////////////////////////
		CircleShape planet(5);
		planet.setFillColor(Color::Blue);

		velocity += a;
		planetY += velocity;
		
		
		planet.setPosition(planetX, planetY);
		window.draw(planet);
		///////////////
		window.setFramerateLimit(60);
		window.display();
	}
 
	return 0;
}
