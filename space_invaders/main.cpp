#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "ship.h"

using namespace sf;
using namespace std;

Texture spritesheet;

vector<Ship*> ships;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << endl;
    }

    Invader* inv = new Invader(IntRect(0, 0, 32, 32), { 100,100 });
    ships.push_back(inv);
    Invader* inv2 = new Invader(IntRect(64, 0, 32, 32), { 200,200 });
    ships.push_back(inv2);
    Invader* inv3 = new Invader(IntRect(0, 0, 32, 32), { 300,300 });
    ships.push_back(inv3);
}

void Update(RenderWindow& window) {
    static Clock clock;
    float dt = clock.restart().asSeconds();

    for (auto& s : ships) {
        s->Update(dt);
    }
}

void Render(RenderWindow& window) {
    for (const auto s : ships) {
        window.draw(*s);
    }
}

int main() {
    RenderWindow window(VideoMode(gameWidth, gameHeight), "PONG");

    Load();

    while (window.isOpen()) {
        window.clear();
        Update(window);
        Render(window);
        window.display();
    }
    return 0;
}