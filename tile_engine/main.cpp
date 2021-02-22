#include <SFML/Graphics.hpp>
#include <iostream>
#include "player.h"
#include "LevelSystem.h"

using namespace sf;
using namespace std;

unique_ptr<Player> player(new Player());

void Load() {
    ls::loadLevelFile("res/maze.txt");

    for (size_t y = 0; y < ls::getHeight(); ++y) {
        for (size_t x = 0; x < ls::getWidth(); ++x) {
            cout << ls::getTile({ x, y });
        }
        cout << endl;
    }
}

void Update() {
    static Clock clock;
    float dt = clock.restart().asSeconds();

    player->Update(dt);
}

void Render(RenderWindow& window) {
    ls::Render(window);
    player->Render(window);
}

int main(){
    RenderWindow window(sf::VideoMode(800, 450), "Tile Engine");

    Load();

    while (window.isOpen()){
        Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed){
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }

        window.clear();
        Update();
        Render(window);
        window.display();
    }
    return 0;
}