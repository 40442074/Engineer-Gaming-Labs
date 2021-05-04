#include <SFML/Graphics.hpp>
#include <iostream>
#include "Windows.h"
#include "player.h"
#include "ghost.h"
#include "LevelSystem.h"
#include "system_renderer.h"

using namespace sf;
using namespace std;

EntityManager em;

shared_ptr<Player> p(new Player());
shared_ptr<Ghost> g(new Ghost());

void Load(RenderWindow& window) {
    Renderer::initialise(window);

    char c[MAX_PATH];
    GetModuleFileName(NULL, c, MAX_PATH);
    string s = string(c);
    s = s.substr(0, s.find_last_of("\\/"));
    ls::loadLevelFile(s + "\\res\\maze.txt");

    for (size_t y = 0; y < ls::getHeight(); ++y) {
        for (size_t x = 0; x < ls::getWidth(); ++x) {
            cout << ls::getTile({ x, y });
        }
        cout << endl;
    }

    em.list.push_back(p);

    g->setPosition(Vector2f(400, 225));
    em.list.push_back(g);
}

void Update() {
    static Clock clock;
    float dt = clock.restart().asSeconds();

    em.update(dt);
}

void Render(RenderWindow& window) {
    ls::Render(window);
    
    em.render();
}

int main() {
    RenderWindow window(sf::VideoMode(800, 450), "Tile Engine");

    Load(window);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
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