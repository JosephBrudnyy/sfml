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
	
	Boundery(){	}
	
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



class Ray
{
public:
	double x;
	double y;
	double dirX;
	double dirY;
	double pointX ;
	double pointY ;
	
	
	Ray(){}
	
	Ray(double x, double y, double dirX, double dirY)
	{
		this->x = x;
		this->y =  y;
		this->dirX = dirX;
		this->dirY = dirY ;
			
		}	
	
	
	void cast(Boundery wall)
	{
		double x1 = wall.x1;
		double y1 = wall.y1;
		double x2 = wall.x2;
		double y2 = wall.y2;
		
		double x3 = this->x;
		double y3 = this->y;
		double x4 = this->dirX;
		double y4 = this->dirY;
	
		double den = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
		
		double t =  ((x1 - x3) * (y3 - y4) - (y1 - y3) * (x3 - x4)) / den;
		double u = -((x1 - x2) * (y1 - y3) - (y1 - y2) * (x1 - x3)) / den;
		
		if(t > 0 && t < 1 && u > 0 && u < 1 )
		{
			pointX = x1 + t * (x2 - x1);
			pointY = y1 + t * (y2 - y1);
			
			this->dirX = pointX;
			this->dirY = pointY;
		}
		else
		{
			pointX = -10;
		}
		
	}
	
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		VertexArray line(Lines, 2);
		line[0].position = Vector2f(x, y);
		line[1].position = Vector2f(dirX , dirY );
			
		line[0].color = Color::White;
		line[1].color = Color::White;
		
		CircleShape p(5);
		p.setFillColor(Color::White);
		p.setPosition(pointX - 3, pointY - 3);
		
		window.draw(line);
		window.draw(p);
	}
	

	
};


class WallConstructor : public Boundery
{
public:
	
	int counter = 0;
	
	void Create(RenderWindow& window,Color color = {255, 255, 255})
	{
		
		if(counter == 1)
		{
			x1 = Mouse::getPosition(window).x;
			y1 = Mouse::getPosition(window).y;
			x2 = Mouse::getPosition(window).x;
			y2 = Mouse::getPosition(window).y;
		}
		if(counter == 2)
		{
			x2 = Mouse::getPosition(window).x;
			y2 = Mouse::getPosition(window).y;
		}
		
		VertexArray w(Lines, 2);
		w[0].position = Vector2f(x1, y1 );
		w[1].position = Vector2f(x2, y2);
				
		w[0].color = Color::White;
		w[1].color = Color::White;
		
			
		window.draw(w);	
			
					
	}
	
	
	
	
		
};




int main()
{
	RenderWindow window(VideoMode(1080, 720), "RayCast");
	ContextSettings settings;
	settings.antialiasingLevel = 5;
	
	
	
	double pi = 3.14;
	Ray ray(540, 360, 2000, 360);

	int ViewAngle = 360;
	Ray RayArr[ViewAngle];
	double angle = 1 * pi/180;
	double RayLenght = ray.dirX - ray.x;
	
	WallConstructor wc;
	
	int NumberOfWalls = 15;
	WallConstructor WallArr[NumberOfWalls];
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
				
			if (event.type == sf::Event::MouseButtonPressed)
	       	{
	            if (event.mouseButton.button == sf::Mouse::Left && Keyboard::isKeyPressed(Keyboard::Space))
	            {
	            	WallArr[0].counter += 1;
	            	for(int i = 1; i < NumberOfWalls; i++)
	            	{
	            		if(WallArr[i-1].counter > 2)
	            		{
	            			WallArr[i].counter += 1;
						}
						
					}
	        	}
	    	}	
			
		}
		window.clear();
		
		//CAMERA SETTINGS//
		for(int i = 0; i < ViewAngle ; i += 1)
		{
			RayArr[i].x = ray.x;
			RayArr[i].y = ray.y;
			RayArr[i].dirX = ray.x + RayLenght  * sin(i * pi/180) ;
			RayArr[i].dirY = ray.y + RayLenght  * cos(i * pi/180) ;
			
			//Wall Array casting
			for(int j = 0; j < NumberOfWalls; j++)
			{
				RayArr[i].cast(WallArr[j]);
			}
				
			if(!Keyboard::isKeyPressed(Keyboard::Space))
			{
				RayArr[i].draw(window);
			}
				
		}
		
		//CAMERA MOVING//
		ray.x = Mouse::getPosition(window).x;
		ray.y = Mouse::getPosition(window).y;
		
		
		
		//DRAWING//
		for(int i = 0; i < NumberOfWalls; i++){	WallArr[i].Create(window);}	
		window.display();
	}
}
