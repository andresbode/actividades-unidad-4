//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <cstdlib> 
#include <ctime>
#include <iostream>

using namespace sf;

class Enemigo {
private:
	Sprite spriteEnemigo;
public:
	Enemigo(Texture& textureEnmigo) {
		spriteEnemigo.setTexture(textureEnmigo);

		spriteEnemigo.setScale(0.07, 0.07);

		int posX = rand() % 700 + 1; 
		int posY = rand() % 500 + 1; 
		spriteEnemigo.setPosition(posX, posY);
	}

	void draw(RenderWindow& window) {
		window.draw(spriteEnemigo);
	}

	// Verifica si el enemigo fue clickeado
	bool checkClick(int mouseX, int mouseY) {
		return spriteEnemigo.getGlobalBounds().contains(mouseX, mouseY);
	}
};


Event evt;

Texture texture;
Sprite sprite;

Texture textureEnemigo;
int enemigosDerrotados = 0;


int main() {
	srand(time(0));
	
	textureEnemigo.loadFromFile("et.png");

	texture.loadFromFile("crosshair.png");
	sprite.setTexture(texture);

	sprite.setPosition(336, 236);

	sprite.setScale(0.5, 0.5);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Que ventana horrible");

	App.setMouseCursorVisible(false);
	Enemigo enemigo(textureEnemigo);

	// Loop principal
	while (App.isOpen())
	{


		while (App.pollEvent(evt)) {
			
			switch (evt.type) {
				
			case sf::Event::Closed:
				App.close();
				break;
			
			case sf::Event::MouseMoved:
	
				sprite.setPosition(evt.mouseMove.x, evt.mouseMove.y);
				break;

			case sf::Event::MouseButtonPressed:
			    
				if (evt.mouseButton.button == Mouse::Left) {
					if (enemigo.checkClick(evt.mouseButton.x, evt.mouseButton.y)) {
						enemigosDerrotados++;
						if (enemigosDerrotados >= 5) {
							std::cout << "¡Has derrotado a 5 enemigos! El juego ha terminado." << std::endl;
							App.close();  
						}
						else {
							enemigo = Enemigo(textureEnemigo);  // Genera un nuevo enemigo.
						}
					}
				}
				break;




			}
		}

		App.clear();
		
		enemigo.draw(App);
		App.draw(sprite);
		
		App.display();
	}
	return 0;
}
