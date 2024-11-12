//////Bibliotecas//////
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

using namespace sf;

Event evt;

int main() {

    RenderWindow App(VideoMode(800, 600, 32), "Que ventana horrible");

    while (App.isOpen()) {
       
        while (App.pollEvent(evt)) {
            
            switch (evt.type) {
           
            case sf::Event::Closed:
                App.close();
                break;

            case sf::Event::Resized:
                
                if (evt.size.width < 100) evt.size.width = 100;
                if (evt.size.width > 1000) evt.size.width = 1000;
                if (evt.size.height < 100) evt.size.height = 100;
                if (evt.size.height > 1000) evt.size.height = 1000;

                App.setSize(Vector2u(evt.size.width, evt.size.height));
                break;
            }
        }

        // Limpiamos la ventana
        App.clear();
        // Mostramos la ventana
        App.display();
    }

    return 0;
}
