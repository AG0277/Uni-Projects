#include "Game.h"
#include <sstream>

void test2(sf::RenderWindow* window)
{
   
}
void test()
{

    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
    sf::Font font;
    if (!font.loadFromFile("font/arial.ttf"))
        std::cout << "ERROR::FAILED TO LOAD TEXTURE BALL\n";
    sf::Text text;
    text.setFont(font);
    int test = 50;
    std::string stext = std::to_string(test);
    text.setString( stext);

   // text.setPosition(400, 300);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(text);
        window.display();
    }

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