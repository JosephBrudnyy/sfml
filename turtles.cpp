#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace sf;
using namespace std;




class Star
{
public:
	int x;
	int y;
	int r;
	double gr;
	double g;
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape s(this->r);
		s.setFillColor(Color(212, 203, 30));
		s.setPosition(this->x, this->y);
		window.draw(s); 
	}
	
};




class Planet
{
public:
	double x;
	double y;
	double dx;
	double dy;
	int r;
	int speed;
	double angle;
	
	
	
	void move()
	{
		dx = cos(angle);
		dy = sin(-(angle));
		
		x += dx * speed;
		y += dy * speed;
		
		
	}
	
	
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape d(this->r);
		d.setFillColor(Color(30, 170, 212));
		d.setPosition(this->x, this->y);
		window.draw(d); 
	}
	
	
	
	
};



int main()
{
	
	
	int windowW = 1080;
	int windowH = 720;
	double pi = 3.14;
	double F;
	double n;
	
	Planet p;
	p.x = 200;
	p.y = 10;
	p.r = 5;
	p.angle = 100;

	p.speed = 2;
	 
	
	
	Star sun;
	sun.x = windowW/2;
	sun.y = windowH/2;
	sun.r = 15;
	sun.gr = 200;
	sun.g = pi/1080;
	
	RenderWindow window(VideoMode(windowW,windowH), "Sun");

	
	

	
	
	
	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		
		n = sun.x / p.x  ;
		F = pi/n ;
		//p.angle1 -= a;
		//p.angle2 -= a;
		
		p.move();
		
		
	//Gravity
	
	if (p.x >= sun.x - sun.gr && p.x <= sun.x + sun.gr &&
	    p.y >= sun.y - sun.gr && p.y <= sun.y + sun.gr )
	{
		p.angle -= sun.g * F;
	}
	if(	p.x >= sun.x - sun.gr && p.x <= sun.x + sun.gr &&
	    p.y >= sun.y - sun.gr && p.y <= sun.y + sun.gr && 
		p.angle < 0)
		{
			p.angle += sun.g * F;
		}
	
	/*if (p.x <= sun.x + sun.gr &&
	    p.y <= sun.y + sun.gr )
	{
		p.angle += sun.g * F;
	}*/
		
		
		
	//Draw	
		sun.draw(window);
		p.draw(window);

		
		window.setFramerateLimit(60);
		window.display();
	}
	
}
