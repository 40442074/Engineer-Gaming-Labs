#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include "ship.h"

using namespace sf;
using namespace std;

Sprite invader;
Texture spritesheet;

vector<Ship*> ships;

void Load() {
    if (!spritesheet.loadFromFile("res/img/invaders_sheet.png")) {
        cerr << "Failed to load spritesheet!" << endl;
    }
    invader.setTexture(spritesheet);
    invader.setTextureRect(IntRect(0, 0, 32, 32));
}

void Update(RenderWindow& window) {

}

void Render(RenderWindow& window) {
    window.draw(invader);
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