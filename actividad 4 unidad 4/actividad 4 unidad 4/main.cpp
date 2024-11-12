//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Event evt; 

Texture texturaPunto1;
Texture texturaCirculo;

Sprite spritePunto1;


float escalaX = 0.2;
float escalaY = 0.2;
float escalaCirculoX = 102.0 / 128.0;
float escalaCirculoY = 102.0 / 128.0;


int main() {

	//Cargamos la textura del archivo
	texturaPunto1.loadFromFile("cuad_yellow.png");
	texturaCirculo.loadFromFile("rcircleg.png");

	//Cargamos el material del sprite
	spritePunto1.setTexture(texturaPunto1);

	//Escalamos tamaño
	spritePunto1.setScale(escalaX, escalaY);

	//Posicionamos
	spritePunto1.setPosition(0, 0);

	//Creamos la ventana
	RenderWindow App(VideoMode(800, 600, 32), "Que ventana horrible");

	// Loop principal
	while (App.isOpen())
	{

		while (App.pollEvent(evt)) {
			
			switch (evt.type)
			{

			case sf::Event::Closed:
				App.close();
				break;

			case sf::Event::KeyPressed:
				if (evt.key.code == Keyboard::Space)
				{
					spritePunto1.setTexture(texturaCirculo);
					spritePunto1.setScale(escalaCirculoX, escalaCirculoY); 
				}
				break;
			}

			// Movimiento con las teclas de dirección
			if (Keyboard::isKeyPressed(Keyboard::Left))
			{
				if (spritePunto1.getPosition().x > 0) // Limite para que no salga de la ventana
					spritePunto1.move(-5.0, 0.0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Right))
			{
				if (spritePunto1.getPosition().x + 102 < 800)
					spritePunto1.move(5.0, 0.0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Up))
			{
				if (spritePunto1.getPosition().y > 0)
					spritePunto1.move(0.0, -5.0);
			}
			if (Keyboard::isKeyPressed(Keyboard::Down))
			{
				if (spritePunto1.getPosition().y + 102 < 600)
					spritePunto1.move(0.0, 5.0);
			}

		}

		// Limpiamos la ventana
		App.clear();
		// Dibujamos la escena
		App.draw(spritePunto1);
		
		// Mostramos la ventana
		App.display();
	}
	return 0;
}