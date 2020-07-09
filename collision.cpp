#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace sf;
using namespace std;




int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}







class Molecule
{
public:
	double x;
	double y;
	double dx;
	double dy;
	double speed;
	int r;
	bool isUp = false;
	bool isRight = false;
	bool isDown = false;
	bool isLeft = false;
	double angle1 ;
	double angle2 ;
	int energy = 10;

	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape p(this->r);
		p.setFillColor(Color::White);
		p.setPosition(this->x, this->y);
		window.draw(p); 
	}
	
	
	void collision()
	{
		
		//moving
		
		this->dx = (cos(this->angle1));
		this->dy = (sin(-this->angle2));
		
		if (this->isUp)
		{
			this->dy = -this->dy; 
		}
		if (isRight)
		{
			this->dx = -this->dx ;
		}
		
		
		//Rebound	
	
		//walls
		if (this->y <= 0)
		{
			this->isUp  = true;
	
		}
		
		
		if (this->x >= 400 - 3 )
		{
			this->isRight = true;
		}
		if (this->y >= 400 - 3)
		{
		
			this->isUp = false;
		}
		if (this->x <= 0)
		{
			this->isRight = false;
		}
		
		
	}
	
	
	void EnergySaving()
	{
		if (y <= 0)
		{
			speed -= 0.3;
	
		}
		
		
		if (x >= 400 - 3 )
		{
			speed -= 0.3;
		}
		if (y >= 400 - 3)
		{
		
			speed -= 0.3;
		}
		if (x <= 0)
		{
			speed -= 0.3;
		}
	}
		
	
	
	


};





void Gravity(Molecule ball)	
	{
		double g = 1000000;
		ball.y / g;
	}


int main()
{


	
	
	srand(time(NULL));
	Molecule m;
	int windowH = 400;
	int windowW = 400;
	double pi = 3.14;
	bool isTouch = false;

	m.x = 400;
	m.y = 200;
	
	Molecule ball;
	ball.angle1 = pi/3;
	ball.angle2 = pi/2;
	ball.isUp = false;
	ball.isRight = false;
	ball.x = 1;
	ball.y = 397;
	ball.r = 5;
	ball.speed = 5;
	
	Molecule ball2;
	ball2.angle1 = pi/3;
	ball2.angle2 = pi/2;
	ball2.isUp = false;
	ball2.isRight = false;
	ball2.x = 400;
	ball2.y = 1;
	ball2.r = 5;
	ball2.speed = 15;	

	
	Molecule Box;
	Box.x = 202;
	Box.y = 200;
	Box.r = 10;

	
	
	
	RenderWindow window(VideoMode(windowH,windowW), "Test");
	
	
	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
	
	
		
		if (ball.y == ball2.y )
		{
	
			
		
		}
		
		
		ball.x += ball.dx * ball.speed;
		ball.y += ball.dy * ball.speed; 
		
		ball2.x += ball2.dx * ball.speed;
		ball2.y += ball2.dy * ball.speed; 
		
		ball.collision();
		ball2.collision();
		//ball.EnergySaving();
		//ball2.EnergySaving();
		Gravity(ball);
		ball.draw(window);
		ball2.draw(window);
		window.setFramerateLimit(60);
		window.display();
			
	}	
	
}
