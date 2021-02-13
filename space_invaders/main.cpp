#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "ship.h"
#include "bullet.h"

using namespace sf;
using namespace std;

Texture spritesheet;

vector<Ship*> ships;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << endl;
    }

    for (int r = 0; r < invaders_rows; r++) {
        auto rect = IntRect(r * 32, 0, 32, 32);
        for (int c = 0; c < invaders_columns; c++) {
            Vector2f position = { 16.0f + 50.0f*c, 16.0f + 50.0f*r};
            auto inv = new Invader(rect, position);
            ships.push_back(inv);
        }
    }

    auto player = new Player();
    ships.push_back(player);
}

void Update(RenderWindow& window) {
    static Clock clock;
    float dt = clock.restart().asSeconds();

    for (auto& s : ships) {
        s->Update(dt);
    }

    Bullet::Update(dt);
}

void Render(RenderWindow& window) {
    for (const auto s : ships) {
        window.draw(*s);
    }

    Bullet::Render(window);
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "SPACE-INVADERS");

    Load();

    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
        }
        if (Keyboard::isKeyPressed(Keyboard::Escape)) {
            window.close();
        }
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}