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
	
	
}; 
 
 

class Player
{
public:
	int x;
	int y;
	int height;
	int width;
	int speed;
	int r;
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape p(r);
		p.setFillColor(Color::White);
		p.setPosition(this->x, this->y);
		window.draw(p); 
	}
	
};

 
 
class Camera
{
public:
	int x;
	int y;
	
	int X;
	int Y;
	
	int dx;
	int dy;
	int lenght;	
	
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		Vertex Line[] = 
		{
			
			Vertex(Vector2f(X + lenght,Y + lenght)),
			Vertex(Vector2f(x , y ))
			
			
		};
		Line->color = Color::White;
		window.draw(Line, 2, Lines); 
	}
	
	
};

 
 
 
 
int main()
{
	RenderWindow window(VideoMode(1080, 720), "FPS");
	
	////main
	Color MainColor = Color(74, 62, 53);
	double const pi = 3.14;
	
	
	
	////Player
	
	
	
	Player player;
	player.x = 400;
	player.y = 200;
	player.r = 5;
	player.speed = 1;
	
	////Camera 
	Camera cam;
	
	cam.x = player.x - 20;
	cam.y = player.y - 20;
	
	cam.dx = cos(pi/1);
	cam.dy = -sin(pi/1);
		
	
	
	
	
	cam.lenght = 100;
	
	
	////Objets
	
	RectangleShape Wall1(Vector2f(500,50));
	Wall1.setPosition(50, 50);
	Wall1.setFillColor(Color(219, 155, 105));
	
	RectangleShape Wall2(Vector2f(50,500));
	Wall2.setPosition(550, 50);
	Wall2.setFillColor(Color(219, 155, 105));
	
	RectangleShape Block(Vector2f(50,50));
	Block.setPosition(200, 500);
	Block.setFillColor(Color(219, 155, 105));
	
	
	
	while (window.isOpen())
	{
		
		Event event;
		while (window.pollEvent(event))
		{
		
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear(MainColor);
		
		
		if(Keyboard::isKeyPressed(Keyboard::W))
		{
			player.y -= player.speed;
		}
		if(Keyboard::isKeyPressed(Keyboard::S))
		{
			player.y += player.speed;
		}
		if(Keyboard::isKeyPressed(Keyboard::A))
		{
			player.x -= player.speed;
		}
		if(Keyboard::isKeyPressed(Keyboard::D))
		{
			player.x += player.speed;
		}
		
		cam.lenght += sin(pi/180);
		
		///CameraMoving
		
		if(Keyboard::isKeyPressed(Keyboard::A))
		{
			player.x -= player.speed;
		}
		if(Keyboard::isKeyPressed(Keyboard::D))
		{
			player.x += player.speed;
		}
		
	
		
		cam.x = player.x + 2;
		cam.y = player.y + 2;
		 
		 
		if(Keyboard::isKeyPressed(Keyboard::Left))
		{
		
			cam.X += 1;
			cam.Y += -1;
			
		}
		
		player.draw(window);
		cam.draw(window);
		window.draw(Wall1);
		window.draw(Wall2);
		window.draw(Block);
		window.display();
	}



}
