#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>


using namespace std; 
using namespace sf; 


int gravity(int object)
{
	
	
	
}




class figure
{
public:
	double x;
	double y;
	double nullspeedpoint;
	double Yspeed;
	double Ya;
	double Xa;
	double Xspeed;
	double fuel;

	
	bool isOnGround()
	{
		if (y < 485)
		{
			return false;
		}
		else
		{
			return true;
		}
	}
	
	
	
};





int timer(int sec)
{
	while(true)
	{
		Sleep(1000);
		sec++;
	}	
}




 
 
int main()
{
	Clock clock;

	srand(time(NULL));
	
/////////SETTINGS////////////
	
	int windowH = 500;
    int windowW = 500;
	double g = 0.01;	
	
//////////BALL//////////////
	
	figure ball;
	ball.x = 250;
    ball.y = 484;
    ball.Ya = 0.1;
    ball.Xa = 0.01;
    ball.fuel = 50;
    ball.Yspeed = 0;
    ball.Xspeed = 0;
    int sqrh = 10;
	int sqrw = 10;
	
///////PARTICLES////////////

	figure particle1;
	particle1.x = 250;
	particle1.y = 202;
	particle1.Xa = 0.15;
	particle1.Ya = 0;
	particle1.Xspeed = 0;
	particle1.Yspeed = 0;
	int part1h = 5;
	int part1w = 10;
	int impulse1 = 5;
	
	figure particle2;
	particle2.x = 255;
	particle2.y = 202;
	particle2.Xa = 0.15;
	particle2.Ya = 0;
	particle2.Xspeed = 0;
	particle2.Yspeed = 0;
	int part2h = 5;
	int part2w = 10;
	int impulse2 = 10;

	////////////DRAW////////////
	
	//BALL
	RectangleShape sqr(Vector2f(sqrh, sqrw)); 
	sqr.setFillColor(Color::White);
	//PARTICLE1
	RectangleShape part1(Vector2f(part1h, part1w)); 
	part1.setFillColor(Color::White);
	
	RectangleShape part2(Vector2f(part2h, part2w)); 
	part2.setFillColor(Color::White);
	
	RenderWindow window(VideoMode(windowH,windowW), "Test");
	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed || 
			(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
			window.close();
		}
		
		window.clear();
		
	
		if (Mouse::isButtonPressed(Mouse::Left))
		{
			
			
		}
	
		sqr.setPosition(ball.x,ball.y);


		////////FUEL///////////
		if (ball.fuel != 0 )
		{
			ball.Yspeed += ball.Ya;
			ball.fuel -= 2;
			
			
		}
		
		
		/////////BALL///////////
		
		if (ball.isOnGround())
		{
			ball.y = 485;
		}
		else if(!ball.isOnGround())
			{
			
				ball.Yspeed -= g;
				ball.y = ball.y - ball.Yspeed;
				
				
				
				
	
			}
		if (ball.Yspeed <= 10)
		{
			sqr.setFillColor(Color::Black);
			
		}
		
		///////////PARTICLES/////////
		
		if (ball.Yspeed >= 0)
		{
			part1.setPosition(ball.x,ball.y);
			part2.setPosition(ball.x + 5,ball.y);
		}
		else
		{
		
			
			
			particle1.x += particle1.Xspeed;
			particle2.x -= particle2.Xspeed;
			
			particle1.Yspeed -= g;
			particle2.Yspeed -= g;
			
			particle1.y -= particle1.Yspeed;
			particle2.y -= particle2.Yspeed;
			
		
			part1.setPosition(particle1.x,particle1.y);
			part2.setPosition(particle2.x,particle2.y);
			
			if (impulse1 != 0 && impulse2 != 0)
			{
				particle1.Xspeed += particle1.Xa;
				particle2.Xspeed += particle2.Xa;
				
				impulse1--;
				impulse2--;
				
			}
		}
		
			

		window.setFramerateLimit(60);
		window.draw(sqr);
		window.draw(part1);
		window.draw(part2);
		window.display();
	}
	return 0;
}
