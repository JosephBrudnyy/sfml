#include <SFML/Graphics.hpp>
#include <iostream>
#include <windows.h>
#include <ctime>
#include <string>
#include <cmath>
using namespace sf;
using namespace std;


class Object 
{
public:
	double x;
	double y


	
	
};






int main()
{
	
	
	RenderWindow window(VideoMode(1080, 720), "Test");
	
	
	while(window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		window.clear();
		
		
		
		
		
		window.display();
	
	}	
}
