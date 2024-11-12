#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Event evt;

Texture texturaPunto1;
Texture texturaPunto2;

Sprite spritePunto1;
Sprite spritePunto2;
 
std::vector<Sprite> puntos;

float escalaX = 0.4;
float escalaY = 0.4;

int main() {

    // Cargar texturas
    texturaPunto1.loadFromFile("rcircle.png");
    texturaPunto2.loadFromFile("rcircleb.png");

    spritePunto1.setTexture(texturaPunto1);
    spritePunto2.setTexture(texturaPunto2);

    spritePunto1.setScale(escalaX, escalaY);
    spritePunto2.setScale(escalaX, escalaY);

    RenderWindow App(VideoMode(800, 600, 32), "Círculos");

    while (App.isOpen()) {

        while (App.pollEvent(evt)) {
            // Procesar eventos
            switch (evt.type) {

            case sf::Event::Closed:
                App.close();
                break;

            case sf::Event::MouseButtonPressed:
                if (evt.mouseButton.button == sf::Mouse::Left) {
                    
                    spritePunto1.setPosition(evt.mouseButton.x , evt.mouseButton.y ); 
                    puntos.push_back(spritePunto1);
                }
                else if (evt.mouseButton.button == sf::Mouse::Right) {
                 
                    spritePunto2.setPosition(evt.mouseButton.x, evt.mouseButton.y); 
                    puntos.push_back(spritePunto2);  
                }
                break;
            }
        }

        App.clear();  

        for (int i = 0; i < puntos.size(); ++i) {
            App.draw(puntos[i]);
        }

        App.display();  
    }

    return 0;
}
