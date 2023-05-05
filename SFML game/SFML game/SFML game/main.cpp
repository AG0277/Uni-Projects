#include "Game.h"
#include <sstream>

void test2(sf::RenderWindow* window)
{
   
}
void test()
{

    sf::RenderWindow window(sf::VideoMode(300, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    shape.setOrigin(shape.getGlobalBounds().width / 2, shape.getGlobalBounds().height / 2);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    std::cout << window.getSize().x << " " << window.getPosition().x;
    //std::cout << shape.getPosition().x<< shape.getPosition().y;
}

int main()
{

    //test();
   Game game;
   
   while (game.running())
   {
       game.updateDeltaTime();
       if (game.update())
           game.render();
   
   }
   
    return 0;
}