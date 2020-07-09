#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace std; 
using namespace sf; 


class Pendulum
{
public:
	double x1;
	double x2;
	double y1;
	double y2;
	int lenght;
	int width;
	double m;
	
	
	double ballX;
	double ballY;
	double ballR;
	
	double a;
	double aVel ;
	double aAcc ;
	
	double speed;
	
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		
		//STRING//
			VertexArray line(Lines, 2);
			line[0].position = Vector2f(x1, y1);
			line[1].position = Vector2f(x2, y2);
			
			line[0].color = Color::Black;
			line[1].color = Color::Black;
		
		
		//BOB//	
		 	CircleShape b(ballR);	
			b.setFillColor(Color(255, 123, 0));
			b.setPosition(x2 - ballR, y2 - ballR);
	
	
		window.draw(line); 
		window.draw(b);
		
	}
	
	
	
	void physics()
	{
		//BOB PHYSICS//
		x2 = x1 + lenght * sin(a);
		y2 =  y1 + lenght * cos(a);
	
	}
	
	
	
	
	
	
	
};


int main()
{
	RenderWindow window(VideoMode(1080, 720), "Double Pendulum");
	srand(time(NULL));
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	
	
	const double pi = 3.141592653589793238462643;
	const double g = 0.9;
		
	Pendulum p;
	p.x1 = 1080/2;
	p.y1 = 720/2 - 150 ;
	p.x2 = p.x1;
	p.lenght = 250;
	p.width = 3;
	p.y2 = p.y1 + p.lenght;
	p.m = 10;
	p.ballR = 15;
	
	p.a = pi;
	p.aAcc ;

	
	
	Pendulum p2;
	p2.x1 = p.x2 ;
	p2.y1 = p.y2 ;
	p2.lenght = 250;
	p2.x2 = p.x2 + p2.lenght;
	p2.y2 = p.y2 + p2.lenght;
	p2.width = 3;
	p2.m = 10;
	p2.ballR = 15;
	
	
	
	p2.a = pi/2;
	p2.aAcc ;
	
	
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
	window.clear(Color::White);
	p2.x1 = p.x2 ;
	p2.y1 = p.y2 ;
	
	//DOUBLE PENDULUM PHYSICS//
	
	

	
	double num1 = -g * (2 * p.m + p2.m) * sin(p.a);
	double num2 = -p2.m * g * sin(p.a - 2 * p2.a);
	double num3 =  -2 * sin(p.a - p2.a) * p2.m;
	double num4 = p2.aVel * p2.aVel * p2.lenght + p.aVel * p.aVel * p.lenght * cos(p.a - p2.a);
	double den = p.lenght * (2 * p.m + p2.m - p2.m * cos(2 * p.a - 2 * p2.a));
	p.aAcc = (num1 + num2 + num3 * num4)/den;
		
		
	num1 = 2 * sin(p.a - p2.a);
	num2 = (p.aVel * p.aVel * p.lenght * (p.m + p2.m));
	num3 = g * (p.m + p2.m) * cos(p.a);
	num4 = p2.aVel * p2.aVel * p2.lenght * p2.m * cos(p.a - p2.a);
	den = p2.lenght * (2 * p.m + p2.m - p2.m * cos(2 * p.a - 2 * p2.a));
	p2.aAcc = (num1 * (num2 + num3 + num4)) / den;
	
		
		
	p.aVel += p.aAcc;
	p2.aVel += p2.aAcc;
		
	p.a += p.aVel;
	p2.a += p2.aVel;
	
	
	p.aVel *= 0.99;
	p2.aVel *= 0.99;
	
	
	//DRAW//
	p2.draw(window);
	p.draw(window);

	p2.physics();
	p.physics();
	window.setFramerateLimit(60);
	window.display();
	}

	
}
