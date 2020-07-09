#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace sf;
using namespace std;









class Racket1
{
public:
	int x;
	int y;
	int height;
	int width;
	int speed;
	bool isUp;
	bool isDown;
	int center;
	int counter;
	
	
	void Check()
	{
		if (y <= 0)
		{
			isUp = true;
		}
		else
		{
			isUp = false;
		}
		
		if (y >= 720 - height)
		{
			isDown = true;
		}
		else
		{
			isDown = false;
		}
	}
	
	
	void move()
	{
		if (Keyboard::isKeyPressed(Keyboard::Up) and !isUp)
		{
			y -= speed;
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Down) and !isDown)
		{
			y += speed;
			}	
	
	}
	
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		RectangleShape p(Vector2f(width, height));
		p.setFillColor(Color(50,168,135));
		p.setPosition(this->x, this->y);
		window.draw(p); 
	}
};


class Racket2 : public Racket1
{
public:	
	int x;
	int y;
	int height;
	int width;
	int speed;
	int isUp;
	int isDown;
	int center;
	int counter;
	
	void move() 
	{
		if (Keyboard::isKeyPressed(Keyboard::W) and !isUp)
		{
			y -= speed;
		}
		
		
		if (Keyboard::isKeyPressed(Keyboard::S) and !isDown)
		{
			y += speed;
			}	
	
	}
	
	void draw2(RenderWindow& window,Color color = {255, 255, 255})
	{
		RectangleShape p2(Vector2f(this->width, this->height));
		p2.setFillColor(Color(50,168,135));
		p2.setPosition(this->x, this->y);
		window.draw(p2); 
	}
	
	
	void Check()
	{
		if (y <= 0)
		{
			isUp = true;
		}
		else
		{
			isUp = false;
		}
		
		if (y >= 720 - height)
		{
			isDown = true;
		}
		else
		{
			isDown = false;
		}
	}
	
};



class Ball
{
public:
	double x;
	double y;
	double dx;
	double dy;
	double angle;
	int r;
	int speed;
	bool isRebound;
	bool isUp;
	bool isDown;

	
	void move()
	{
		dx = cos(angle);
		dy = sin(angle);
		
		
		if(isRebound)
		{
			dx = -dx;
	
		}
		
		if(isUp)
		{
			dy = -dy;
		}
		if (isDown)
		{
			dy = -dy;
		}
		
	}
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape b(r);
		b.setFillColor(Color(209, 159, 65));
		b.setPosition(this->x, this->y);
		window.draw(b); 
	}
	
	

	
	
	
};





int main()
{
	
	RenderWindow window(VideoMode(1080,720), "Pong");
	

	
	
	
	Racket1 r;
	r.height = 200;
	r.width = 10;
	r.x = 1030;
	r.y = 275;
	r.speed = 4;
	r.isUp = false;
	r.isDown = false;
	r.counter = 0;
	
	Racket2 r2;
	r2.height = 200;
	r2.width = 10;
	r2.x = 50;
	r2.y = 275;
	r2.speed = 4;
	r2.isUp = false;
	r2.isDown = false;
	r2.counter = 0;
	
	Ball ball;
	double pi = 3.14;
	ball.x = 545;
	ball.y = 365;
	ball.angle = 10;
	ball.r = 10;
	ball.speed = 11;
	ball.isRebound = false;
	ball.isUp = false;
	
	bool isStart = false;
	
	
	
	
	
	Text text;
	Font font;
	font.loadFromFile("font.TTF");
	text.setFont(font);
	text.setString("P  o  n  g");
	text.setCharacterSize(24);
	text.setStyle(sf::Text::Bold | sf::Text::Underlined);
	text.setColor(Color(50,168,135));
	text.setPosition(470, 20);
	
	Text score1;
	Font scorefont1;
	scorefont1.loadFromFile("font.TTF");
	score1.setFont(scorefont1);
	score1.setCharacterSize(24);
	score1.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score1.setColor(Color(50,168,135));
	score1.setPosition(1040, 20);
	
	
	Text score2;
	Font scorefont2;
	scorefont2.loadFromFile("font.TTF");
	score2.setFont(scorefont1);
	score2.setCharacterSize(24);
	score2.setStyle(sf::Text::Bold | sf::Text::Underlined);
	score2.setColor(Color(50,168,135));
	score2.setPosition(20, 20);
	
	
	
	
	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed )
				window.close();
		}
		window.clear();
		window.clear(Color(46, 51, 44));
	
	
		//ball settings
		
		if (ball.x >= r.x - r.width
		and ball.y >= r.y and ball.y <= r.y + r.height)
			{
				ball.isRebound = true;
				ball.isUp = false;
				ball.isDown = false;
				
				
			}
		
		if (ball.x <= r2.x
		and ball.y >= r2.y and ball.y <= r2.y + r2.height)
			{
				ball.isRebound = false;
				ball.isUp = false;
				ball.isDown = false;
				
			}
	
		//rebounds r1
		
		if (!ball.isRebound and ball.y < r.center and ball.y > r.y and ball.x >= r.x - r.width - 10)
			{
				ball.angle = pi - ball.angle + (std::rand() % 20) * pi / 180;
				 
				}
					
		if (!ball.isRebound and ball.y > r.center and ball.y < r.y + r.height and ball.x >= r.x - r.width - 5)
			{
				ball.angle = pi  - ball.angle + (std::rand() % 20) * pi / 180;
				}	
		
		
		//rebounds r2
		
		if (ball.isRebound and ball.y < r2.center and ball.y > r2.y and ball.x <= r2.x + 9)
			{
				ball.angle = pi - ball.angle + (std::rand() % 20) * pi / 180;
				
				}
					
		if (ball.isRebound and ball.y > r2.center and ball.y < r2.y + r2.height and ball.x <= r2.x + 9)
			{
				ball.angle = pi - ball.angle + (std::rand() % 20) * pi / 180;
			
				}	
		
		
		//walls
		if (ball.y <= 0 and ball.x < r.x and ball.x > r2.x )
		{
			ball.isUp = true;
			
		}
		
		if (ball.y >= 650 and ball.x < r.x and ball.x > r2.x )
		{
			ball.isDown = true;
			
		}
		
		
		
		
		
		//goals
		if (ball.x > 1080)
		{
			
			r.counter += 1;
			ball.x = 1080/2;
			ball.y = 720/2;
			ball.angle = 1;
			
			
		
		}
		
		if (ball.x < 0)
		{
			r2.counter += 1;
			ball.x = 1080/2;
			ball.y = 720/2;
			ball.angle = 1;
			
		}
		
		
		if (r.counter >= 3 or r2.counter >= 3)
		{
			window.close();
			window.setVisible(false);
		}
	// score2	
		if (r.counter == 1)
		{
			score2.setString("1"); 
		}
		
		if (r.counter == 2)
		{
			score2.setString("2"); 
		}
		if (r.counter == 3)
		{
			score2.setString("3"); 
		}
		if (r.counter == 0)
		{
			score2.setString("0"); 
		}
		
	//score1	
		if (r2.counter == 1)
		{
			score1.setString("1"); 
		}
		
		if (r2.counter == 2)
		{
			score1.setString("2"); 
		}
		if (r2.counter == 3)
		{
			score1.setString("3"); 
		}
		if (r2.counter == 0)
		{
			score1.setString("0"); 
		}
		
		
		
		
		//menu
		if(isStart)
		{
			ball.move();	
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Space))
		{
			isStart = true;
			ball.speed = 11;
		}
		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			isStart = false;
			ball.speed = 0;
		}
		
		
		
		
		//texts
		
		window.draw(text);
		window.draw(score1);
		window.draw(score2);
	
		r.draw(window);
		r.move();
		r.Check();
		r.center = r.y + (r.height/2);
		
		r2.draw2(window);
		r2.move();
		r2.Check();
		r2.center = r2.y + (r2.height/2);
	
		ball.draw(window);
		
		ball.x += ball.dx * ball.speed;
		ball.y += ball.dy * ball.speed;
		
		window.setFramerateLimit(60);
		
		
		
		window.display();
	
		
	}
	
	
}
