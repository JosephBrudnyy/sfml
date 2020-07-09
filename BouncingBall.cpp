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
	double angle ;
	int energy = 10;

	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape p(this->r);
		p.setFillColor(Color::Blue);
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
			this->y *= 1.5;
			
		}
		if(this->isDown)
		{
			this->y /= 1.5;
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
		
		
		if (this->x >= 800 - r )
		{
			this->isRight = true;
		}
		if (this->y > 600 - r)
		{
		
			this->isUp = false;
		}
		if (this->x <= 0)
		{
			this->isRight = false;
		}
		
		
	}
	
	
	void EnergyLosing()
	{
		if (y <= 0)
		{
			speed -= 0.3;
	
		}
		
		
		if (x >= 800 - r )
		{
			speed -= 0.3;
		}
		if (y >= 600 - r)
		{
		
			speed -= 0.3;
		}
		if (x <= 0)
		{
			speed -= 0.3;
		}
	}
		
	
	
	


};








int main()
{


	
	
	srand(time(NULL));
	Molecule m;
	int windowH = 800;
	int windowW = 600;
	double pi = 3.14;
	bool isTouch = false;
	double g = 9.8;

	m.x = 400;
	m.y = 200;
	
	Molecule ball;
	ball.angle1;
	ball.angle2 = 30;
	ball.isUp = false;
	ball.isRight = false;
	ball.x = 300;
	ball.y = 1;
	ball.r = 10;
	ball.speed = 5;
	
	Molecule ball2;
	ball2.angle1 = pi/3;
	ball2.angle2 = pi/2;
	ball2.isUp = true;
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
		
		
		ball.y += ball.dy * ball.speed;

		
		ball.collision();
		ball2.collision();
		//ball.EnergyLosing();

		ball.draw(window);
		//ball2.draw(window);
		window.setFramerateLimit(60);
		window.display();
			
	}	
	
}
