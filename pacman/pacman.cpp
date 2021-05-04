#include "pacman.h"
#include "Windows.h"
using namespace sf;
using namespace std;

shared_ptr<Scene> gameScene;
shared_ptr<Scene> menuScene;
shared_ptr<Scene> activeScene;

void MenuScene::update(double dt) {
	Scene::update(dt);
	text.setString("Almost Pacman");
}

void MenuScene::render() {
	Renderer::queue(&text);
	Scene::render();
}

void MenuScene::load() {
	char c[MAX_PATH];
	GetModuleFileName(NULL, c, MAX_PATH);
	string s = string(c);
	s = s.substr(0, s.find_last_of("\\/"));

	Font f = Font();
	f.loadFromFile(s + "\\res\\font.txt");
	text = Text("Almost Pacman", f);
}