#include <stdio.h>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include "utils.hpp"

#define SCREEN_SIZE_MULTIPLIER 3

// No parameters for main
int main(void)
{
    buildColorPalette();
    sf::RenderWindow window(sf::VideoMode(SCREEN_WIDTH * SCREEN_SIZE_MULTIPLIER, SCREEN_HEIGHT * SCREEN_SIZE_MULTIPLIER), "PLASMA!!");

    sf::Image canvasI;
    sf::Texture canvasT;
    sf::Sprite canvasS;

    canvasI.create(320, 240, {255, 0, 0});
    canvasT.loadFromImage(canvasI);
    canvasS.setTexture(canvasT);
    canvasS.scale(SCREEN_SIZE_MULTIPLIER, SCREEN_SIZE_MULTIPLIER);

    float shiftX = 0;
    float shiftY = 0;
    float shiftRadial = 0;
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

        shiftX += 0.1;
        shiftY += 0.1;
        shiftRadial += 0.1;

        drawPlasmaColor(canvasI, shiftX, shiftY, shiftRadial);
        drawColorPalette(canvasI);

        canvasT.loadFromImage(canvasI);

        window.draw(canvasS);
        window.display();
    }

    return 0;
}