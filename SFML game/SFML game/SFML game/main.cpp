#include "Game.h"

void test2(sf::RenderWindow* window)
{
   
}
void test()
{

    sf::RenderWindow* window =  new sf::RenderWindow(sf::VideoMode(1280, 720), "ImGui + SFML = <3");
   // ImGui::SFML::SetCurrentWindow(*window);
    ImGui::SFML::Init(*window);
    ImGuiContext* ctx1 = ImGui::GetCurrentContext();

    sf::RenderWindow* window2 = new sf::RenderWindow(sf::VideoMode(580, 320), "ImGui + SFML = <3");
    //ImGui::SFML::SetCurrentWindow(*window2);
    ImGui::SFML::Init(*window2);
    ImGuiContext* ctx2 = ImGui::CreateContext();
    ImGui::SetCurrentContext(ctx2);

    sf::Clock deltaClock;
    while (window->isOpen()) {
      //  ImGui::SFML::SetCurrentWindow(*window);
        //ImGui::SetCurrentContext(ctx1);
        // Main window event processing
        sf::Event event;
        while (window->pollEvent(event)) {
            ImGui::SFML::ProcessEvent(*window, event);
            if (event.type == sf::Event::Closed) {

                window->close();
                ImGui::SFML::Shutdown(); // will shutdown all windows
                return;// return here so that we don't call Update/Render
            }
        }


        // Update
        const sf::Time dt = deltaClock.restart();
        ImGui::SFML::Update(*window, dt);


        // Add ImGui widgets in the first window

        ImGui::Begin("Hello, world!");
        ImGui::Button("Look at this pretty button");
        ImGui::End();

       // ImGui::ShowDemoWindow();


        // Main window drawing
        sf::CircleShape shape(100.f);
        shape.setFillColor(sf::Color::Green);

        window->clear();
        window->draw(shape);
        ImGui::SFML::Render(*window);
        window->display();
    }
   // delete window;
    //delete window2;
}

int main()
{

   // test();
    Game game;
    
    while (game.running())
    {
        game.updateDeltaTime();
        if (game.update())
            game.render();
    
    }
   
    return 0;
}