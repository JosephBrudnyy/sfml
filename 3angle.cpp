#include <SFML/Graphics.hpp>
#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

const int WINDOW_WIDTH = 800;    // ������ ����
const int WINDOW_HEIGHT = 600;   // ������ ����

void drawStuff(int &pointCounter, sf::RenderWindow &window, sf::Event event, sf::VertexArray &triangle);
void Randomize();
int RandomInteger(int low, int high);
void drawCircle(sf::RenderWindow& window, sf::Vector2f currentPoint, sf::CircleShape& circle);
void moveCurrentPoint(sf::Vector2f &currentPoint, sf::VertexArray triangle);

// ����� ����� � ���������
int main() {
   // ���������������� ��������� ��������� �����
   Randomize();
   // ��������� ����
   sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Chaos Game");
   int pointCounter = 0;  // ������� ������
   sf::VertexArray triangle(sf::LinesStrip, 4);    // ������ ������
   sf::CircleShape circle(WINDOW_WIDTH / 500);
   sf::Vector2f currentPoint;                      // ������� �����
   cout << "Click three points within window please" << endl;

   // �������� ���� �������� ���� ������� ����
   while(window.isOpen()) {
      sf::Event event;     // ������ �������
      // ��������� ������� ������ ����
      while(window.pollEvent(event)) {
         switch(event.type) {
            // ���� �������� ������� �������� ����, �� �������
            case sf::Event::Closed:
               window.close();
               break;
            case sf::Event::MouseButtonPressed:
               // ���� ������������ ����� �� ����� ������ ����
               if(event.mouseButton.button == sf::Mouse::Left) {
                  cout << "Mouse pressed! " << "Mouse X: " << event.mouseButton.x
                       << " Y: " << event.mouseButton.y << endl;
                  // ���� ��������� ������ 4 ������ ������ ������� �����������
                  if(pointCounter <= 2)
                     triangle[pointCounter].position = sf::Vector2f(event.mouseButton.x, event.mouseButton.y);
                  pointCounter++;
                  if(pointCounter == 3) {
                     triangle[pointCounter].position = triangle[0].position;
                     currentPoint = triangle[RandomInteger(0, 2)].position;
                  }
               }
               break;
         }
      }
		//window.clear();
      // ������ ����������� � ������� �����
      if(pointCounter == 3) {
         window.draw(triangle);
         drawCircle(window, currentPoint, circle);
         // ���������� ������� �����
         moveCurrentPoint(currentPoint, triangle);
      }
      else if(pointCounter > 3) window.close();
      window.display();
   }

   return 0;
}

// �������������� ��������� ��������� ����� ������� ��������
void Randomize() {
   srand(int(time(NULL)));
}

// ���������� ��������� ����� �� low �� high
int RandomInteger(int low, int high) {
   double normalVal = double(rand()) / (double(RAND_MAX) + 1);
   int scaledVal = int(normalVal * (high - low + 1));
   return low + scaledVal;
}


// ������ ���� � ������� � ������� �����
void drawCircle(sf::RenderWindow& window, sf::Vector2f currentPoint, sf::CircleShape& circle) {
   circle.setFillColor(sf::Color(sf::Color::Yellow));
   int xPos = currentPoint.x - circle.getRadius();
   int yPos = currentPoint.y - circle.getRadius();
   cout << "Random x: " << xPos + circle.getRadius() << " y: " << yPos + circle.getRadius() << endl;
   circle.setPosition(xPos, yPos);
   window.draw(circle);
}

// ���������� ������� ����� � ����������� �������� ��������� ������� �� �������� ���������� �� �������
void moveCurrentPoint(sf::Vector2f &currentPoint, sf::VertexArray triangle) {
   int vertexIndex = RandomInteger(0, 2);
   sf::Vector2f dirVertex = triangle[vertexIndex].position;
   currentPoint.x = (dirVertex.x + currentPoint.x) / 2;
   currentPoint.y = (dirVertex.y + currentPoint.y) / 2;
}
