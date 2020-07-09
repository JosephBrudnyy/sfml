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



int main()
{
	
	
	
	
	RenderWindow window(VideoMode(800,600), "Fractal");
	
	srand(time(NULL));
	//400
	//325

	int CurrentX = 400;
	int CurrentY = 325;
	
	int Vertex1X = 400;
	int Vertex1Y = 200;
	
	int Vertex2X = 300;
	int Vertex2Y = 400;
	
	int Vertex3X = 500;
	int Vertex3Y = 400;
	
	
	CircleShape Vertex1(2);
	Vertex1.setFillColor(Color::White);
	Vertex1.setPosition(400, 200);
	
	CircleShape Vertex2(2);
	Vertex2.setFillColor(Color::White);
	Vertex2.setPosition(300, 400);
	
	CircleShape Vertex3(2);
	Vertex3.setFillColor(Color::White);
	Vertex3.setPosition(500, 400);
	
	
	CircleShape point(2);
	point.setFillColor(Color::White);
	point.setPosition(CurrentX, CurrentY);
	
	
	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}

	
	
	
	
	
	
	point.setPosition(CurrentX, CurrentY);
	
	int RandomDest = getRandomNumber(1, 3);
	if (RandomDest == 1)
	{
		CurrentX = (CurrentX + Vertex1X) / 2;
		CurrentY = (CurrentY + Vertex1Y) / 2;
		
		point.setPosition(CurrentX, CurrentY);
	}
	if (RandomDest == 2)
	{
		CurrentX = (CurrentX + Vertex2X) / 2;
		CurrentY = (CurrentY + Vertex2Y) / 2;
		
		point.setPosition(CurrentX, CurrentY);
	}
	if (RandomDest == 3)
	{
		CurrentX = (CurrentX + Vertex3X) / 2;
		CurrentY = (CurrentY + Vertex3Y) / 2;
		
		point.setPosition(CurrentX, CurrentY);
	}
	
	
	
	
	window.draw(Vertex1);
	window.draw(Vertex2);
	window.draw(Vertex3);
	window.draw(point);
	//window.setFramerateLimit(60);
	window.display();
	}
}
