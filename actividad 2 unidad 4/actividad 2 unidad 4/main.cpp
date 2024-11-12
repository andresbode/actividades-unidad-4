#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Event evt;

Texture texturaPunto1;
Texture texturaPunto2;
Texture texturaPunto3;
Texture texturaPunto4;
Sprite spritePunto1;
Sprite spritePunto2;
Sprite spritePunto3;
Sprite spritePunto4;
float escalaX = 0.2;
float escalaY = 0.2;

int main() {

	texturaPunto1.loadFromFile("rcircle.png");
	texturaPunto2.loadFromFile("rcircle.png");
	texturaPunto3.loadFromFile("rcircle.png");
	texturaPunto4.loadFromFile("rcircle.png");

	spritePunto1.setTexture(texturaPunto1);
	spritePunto2.setTexture(texturaPunto2);
	spritePunto3.setTexture(texturaPunto3);
	spritePunto4.setTexture(texturaPunto4);

	spritePunto1.setScale(escalaX, escalaY);
	spritePunto2.setScale(escalaX, escalaY);
	spritePunto3.setScale(escalaX, escalaY);
	spritePunto4.setScale(escalaX, escalaY);

	spritePunto1.setPosition(0, 0);
	spritePunto2.setPosition(775, 0);
	spritePunto3.setPosition(0, 575);
	spritePunto4.setPosition(775, 575);

	RenderWindow App(VideoMode(800, 600, 32), "Que ventana horrible");

	bool arrastrandoP1 = false;
	bool arrastrandoP2 = false;
	bool arrastrandoP3 = false;
	bool arrastrandoP4 = false;

	// Loop principal
	while (App.isOpen())
	{

		while (App.pollEvent(evt)) {

			switch (evt.type) {

				
			case sf::Event::Closed:
				App.close();
				break;

			case sf::Event::MouseButtonPressed:

				if (evt.mouseButton.button == sf::Mouse::Left) {
					
					int tolerancia = 25; 

					float posX1 = spritePunto1.getPosition().x;
					float posY1 = spritePunto1.getPosition().y;
					float posX2 = spritePunto2.getPosition().x;
					float posY2 = spritePunto2.getPosition().y;
					float posX3 = spritePunto3.getPosition().x;
					float posY3 = spritePunto3.getPosition().y;
					float posX4 = spritePunto4.getPosition().x;
					float posY4 = spritePunto4.getPosition().y;

					if (evt.mouseButton.x >= posX1 - tolerancia && evt.mouseButton.x <= posX1 + tolerancia &&
						evt.mouseButton.y >= posY1 - tolerancia && evt.mouseButton.y <= posY1 + tolerancia) {
						arrastrandoP1 = true;
					}

					if (evt.mouseButton.x >= posX2 - tolerancia && evt.mouseButton.x <= posX2 + tolerancia &&
						evt.mouseButton.y >= posY2 - tolerancia && evt.mouseButton.y <= posY2 + tolerancia) {
						arrastrandoP2 = true;
					}

					if (evt.mouseButton.x >= posX3 - tolerancia && evt.mouseButton.x <= posX3 + tolerancia &&
						evt.mouseButton.y >= posY3 - tolerancia && evt.mouseButton.y <= posY3 + tolerancia) {
						arrastrandoP3 = true;
					}

					if (evt.mouseButton.x >= posX4 - tolerancia && evt.mouseButton.x <= posX4 + tolerancia &&
						evt.mouseButton.y >= posY4 - tolerancia && evt.mouseButton.y <= posY4 + tolerancia) {
						arrastrandoP4 = true;
					}
				}
				break;

			case sf::Event::MouseButtonReleased:
				if (evt.mouseButton.button == sf::Mouse::Left) {
					arrastrandoP1 = false;
					arrastrandoP2 = false;
					arrastrandoP3= false;
					arrastrandoP4 = false;
				}
				break;
			}

			if (arrastrandoP1) {
				Vector2i posicionMouse = Mouse::getPosition(App);
				spritePunto1.setPosition(posicionMouse.x, posicionMouse.y);
			}
			if (arrastrandoP2) {
				Vector2i posicionMouse = Mouse::getPosition(App);
				spritePunto2.setPosition(posicionMouse.x, posicionMouse.y);
			}
			if (arrastrandoP3) {
				Vector2i posicionMouse = Mouse::getPosition(App);
				spritePunto3.setPosition(posicionMouse.x, posicionMouse.y);
			}
			if (arrastrandoP4) {
				Vector2i posicionMouse = Mouse::getPosition(App);
				spritePunto4.setPosition(posicionMouse.x, posicionMouse.y);
			}
		}
		
		App.clear();

		App.draw(spritePunto1);
		App.draw(spritePunto2);
		App.draw(spritePunto3);
		App.draw(spritePunto4);
		
		App.display();
	}
	return 0;
}
