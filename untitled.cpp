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
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape p(3);
		p.setFillColor(Color::White);
		p.setPosition(this->x, this->y);
		window.draw(p); 
	}



};


int main()
{
	RenderWindow window(VideoMode(800,400), "Test");
	
	
	srand(time(NULL));
	Molecule m;
	Molecule ball;
	double pi = 3.14;
	double g = pi/360;
	m.x = 400;
	m.y = 200;
	double angle1 = pi/6;
	double angle2 = pi/3;
	
	ball.x = 1;
	ball.y = 394;
	

	
	
	
	
	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		
		
		
		int n = getRandomNumber(1,360);
		
		m.dx = round(3*cos(n*pi/180));	
		m.dy = round(-3*sin(n*pi/180));
			
		m.x += m.dx;
		m.y += m.dy;
	
		//m.draw(window);
		
		angle2 += g;
		
		ball.dx = (cos(angle1));
		ball.dy = (sin(-angle2));
		
		
		
		ball.x += ball.dx;
		ball.y += ball.dy; 
		
		ball.draw(window);
		
		
		window.setFramerateLimit(60);
		window.display();
			
	}	
	
}
