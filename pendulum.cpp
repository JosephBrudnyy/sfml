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
		
		
		///PENDULUM PHYSICS//
		double g = 0.8;
		
		a += aVel;
		aVel += aAcc;
	
		aAcc = - (g / lenght) * sin(a);
		aVel *= 0.99;
			
		
		
	}
	
	
	
	
	
	void track()
	{
		
		
		
	}
	
	
};

int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}




int main()
{
	RenderWindow window(VideoMode(1080, 720), "Pendulum");
	srand(time(NULL));
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	
	
	const double pi = 3.141592653589793238462643;
		
	Pendulum p;
	p.x1 = 1080/2;
	p.y1 = 0; //720/2;
	p.x2 = p.x1;
	p.lenght = 300;
	p.y2 = p.y1 + p.lenght;
	p.width = 3;
	p.ballR = 15;
	
	p.a = pi/2;
	p.aVel = 0;
	p.aAcc = 0;
	p.speed = 0.01;
	
	
	Pendulum p2;
	p2.x1 = p.x2 ;
	p2.y1 = p.y2 ;
	p2.lenght = 200;
	p2.x2 = p.x2 + p2.lenght;
	p2.y2 = p.y2 + p2.lenght;
	p2.width = 3;
	p2.ballR = 15;
	
	p2.a = -pi/1.1;
	p2.speed = 0.01;
	
	
	
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
	
	

	
	
	//p2.physics();
	//p2.draw(window);
			
	p.physics();
	p.draw(window);
	
	window.setFramerateLimit(60);
	window.display();
	}

	
}
