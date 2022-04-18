#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>

#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240
#define SCREEN_SIZE_MULTIPLIER 3

// No parameters for main
int main(void)
{
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH * SCREEN_SIZE_MULTIPLIER, SCREEN_HEIGHT * SCREEN_SIZE_MULTIPLIER), "PLASMA!!");

    sf::Image canvasI;
    sf::Texture canvasT;
    sf::Sprite canvasS;

    canvasI.create(320, 240, {255, 0, 0});
    canvasT.loadFromImage(canvasI);
    canvasS.setTexture(canvasT);
    canvasS.scale(SCREEN_SIZE_MULTIPLIER, SCREEN_SIZE_MULTIPLIER);

    while (window.isOpen())
    {
        sf::Event evt;
        while (window.pollEvent(evt))
        {
            if (evt.type == sf::Event::EventType::Closed)
                window.close();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
            window.close();

        canvasI.setPixel(0, 0, {0xFF, 0xFF, 0xFF});
        canvasI.setPixel(319, 0, {0xFF, 0xFF, 0xFF});
        canvasI.setPixel(0, 239, {0xFF, 0xFF, 0xFF});
        canvasI.setPixel(319, 239, {0xFF, 0xFF, 0xFF});

        canvasT.loadFromImage(canvasI);

        window.draw(canvasS);
        window.display();
    }

    return 0;
}