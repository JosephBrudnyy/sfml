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
		
		window.clear(Color(250, 220, 100, 0));
 
	
		CircleShape circle(50.f);
		circle.setFillColor(Color(230, 0, 230));
 		circle.setOutlineThickness(15.f);
 		circle.setOutlineColor(Color(80,220,50));
		circle.move(15,15);
		window.draw(circle);

		
		CircleShape triangle(65.f, 3);
		triangle.setPosition(125, 0);
		triangle.setFillColor(Color::Blue);
		window.draw(triangle);
		
		RectangleShape rectangle(Vector2f(100.f, 100.f));
		rectangle.setPosition(165,150);
		rectangle.setFillColor(Color(175,180,240));
		window.draw(rectangle);
		
		
		RectangleShape line(Vector2f(130.f, 1.f));
		line.rotate(45.f);
		line.setFillColor(Color(15,180,140));
		line.setPosition(350,150);
		window.draw(line);
		
		window.display();
		
		
	}
 
	return 0;
}
