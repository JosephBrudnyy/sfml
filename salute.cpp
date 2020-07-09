#include <iostream>
#include <SFML/Graphics.hpp>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
#include <SFML/Audio.hpp>


using namespace std; 
using namespace sf; 


int getRandomNumber(int min, int max)
{
    static const double fraction = 1.0 / (static_cast<double>(RAND_MAX) + 1.0); 
    // Равномерно распределяем рандомное число в нашем диапазоне
    return static_cast<int>(rand() * fraction * (max - min + 1) + min);
}




class figure
{
public:
	double x;
	double y;
	double dx;
	double dy;
	double velocity;
	double nullspeedpoint;
	double Yspeed;
	double Ya;
	double Xa;
	double Xspeed;
	double fuel;
	
	double r;
	double g = 0.07;
	
	
	Color color = Color::Red;
	
	void gravity()
	{
		this->Yspeed -= g;
		this->y -= this->Yspeed;
	}
	
	
	
	
	
	
	
	void draw(RenderWindow& window,Color color = {255, 255, 255})
	{
		CircleShape circle(r);
		circle.setFillColor(this->color);
		circle.setPosition(x, y);
		window.draw(circle);
		
	}
	

};





 
int main()
{
	Clock clock;

	srand(time(NULL));
	double pi = 3.14;
	Color BackgroundColor = Color(0, 0, 0);
	
/////////SETTINGS////////////
	
	int windowH = 1080;
    int windowW = 720;
	double g = 0.007;
	int ExplosionHeight = 250;	
	
//////////BALL//////////////
	
	figure ball;
	ball.x = 540;
    ball.y = 720;
    ball.Ya = 0.25;
    ball.Xa = 0.01;
    ball.fuel = 50;
    ball.Yspeed = 0;
    ball.Xspeed = 0;
    int sqrh = 1;
	int sqrw = 10;


	
	
	bool isExploded = false;
	int RandomDest;
	int RandomVelocity;
	
	const int NumberOfPart = 700;
	figure PartArr[NumberOfPart];
	
	////////////SOUND////////////
	Music ExSound;
	ExSound.openFromFile("resources/firework.ogg");
	
	Music Whistle;
	Whistle.openFromFile("resources/whistle.wav");
	
	
	///////////COLOR/////////////

	
	Color ColorArr[2] {Color::Red, Color::Magenta};
	
	
	////////////DRAW////////////
	
	//BALL
	RectangleShape sqr(Vector2f(sqrh, sqrw)); 
	sqr.setFillColor(Color::White);

	

	
	for(int i = 0; i < NumberOfPart; i++)
	{
	
		PartArr[i].x = ball.x;
		PartArr[i].y = ExplosionHeight; 
		PartArr[i].r = 1;
	
		
	
	}
	
	int i = 0;
	int n = 1;
	
	RenderWindow window(VideoMode(windowH,windowW), "Fireworks!");
	while(window.isOpen())
	{
		Event event;
		while(window.pollEvent(event))
		{
			if(event.type == Event::Closed || 
			(event.type == Event::KeyPressed && event.key.code == Keyboard::Escape))
			window.close();
		}
		
		window.clear(BackgroundColor);
	
		sqr.setPosition(ball.x,ball.y);

		////////FUEL///////////
		if (ball.fuel != 0 )
		{
			ball.Yspeed += ball.Ya;
			ball.fuel -= 2;
			
			
		}
		
	
		/////////BALL///////////
		
	
		ball.Yspeed -= g;
		ball.y = ball.y - ball.Yspeed;
		
			
		if (ball.y < ExplosionHeight)
		{
			sqr.setFillColor(Color::Black);
			isExploded = true;
			if (n > NumberOfPart)
			{
				isExploded = false;
			}
			
		}
		
		//firework draw
		
		if(isExploded)
			{
				for(int s; s < 3; s++)
				{
					ExSound.play();
					
				}
			
				
				for (int n; n < NumberOfPart; n++ )
				{
				
				
					int RandomAngle = getRandomNumber(1, 360);
					int RandomColor = getRandomNumber(0,2);
					
					
					
					PartArr[n].dx =  cos(RandomAngle * pi/180) ;
					PartArr[n].dy =  -sin(RandomAngle * pi/180) ;
					
					PartArr[n].color = ColorArr[RandomColor];
					
					PartArr[n].velocity = getRandomNumber(2 , 20);
					n++;
				
					
					//cout << n << endl;
					
				}
				
				
				
				
				
				
				
				
				for(int j = 0; j < NumberOfPart ; j++)
				{
					
					PartArr[j].y -= 1;
					
					PartArr[j].draw(window);
					PartArr[j].gravity();
					
					//PartArr[j].velocity *= 0.9;
					
					PartArr[j].x += PartArr[j].dx * PartArr[j].velocity ;
					PartArr[j].y += PartArr[j].dy * PartArr[j].velocity;
					
					if(PartArr[j].velocity < 1)
					{
						//PartArr[j].color = BackgroundColor;
					}
					
					
				}
			
				
				
				i++;			
				if(i > NumberOfPart - 1)
				{
					i = 0;
				}				
				
				
			}
			
			else if(!isExploded)
			{
				for(int w; w < 1; w++)
				{
					Whistle.play();
				}
			}
			
	    ///////////////////////////////	
		
		
		
		
		
		window.setFramerateLimit(60);
		window.draw(sqr);
		window.display();
	}
	return 0;
}
