#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace sf;
using namespace std;


class Boundery
{
public:
	double x1;
	double x2;
	double y1;
	double y2;
	
	
	Boundery(double x1,double y1,double x2,double y2)
	{
		this->x1 = x1;
		this->y1 = y1;
		this->x2 = x2;
		this->y2 = y2;
	
	}
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		VertexArray line(Lines, 2);
		line[0].position = Vector2f(x1, y1);
		line[1].position = Vector2f(x2, y2);
			
		line[0].color = Color::White;
		line[1].color = Color::White;
		
		window.draw(line);
	}
};



int main()
{
	RenderWindow window(VideoMode(1080, 720), "RayCast");
	
	
	Boundery wall1(100,100,100,500);
	
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
	
		
	
	
	
		wall1.draw(window);
		window.display();
	}
}
