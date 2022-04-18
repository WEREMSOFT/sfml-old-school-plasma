#pragma once
#include <SFML/Graphics.hpp>
#include <glm/glm.hpp>
#include <glm/gtc/constants.hpp>
#define SCREEN_WIDTH 320
#define SCREEN_HEIGHT 240

static glm::vec2 screenCenter(SCREEN_WIDTH / 2, SCREEN_HEIGHT / 2);

static sf::Color colorPalette[255];
static const float colorToPIRelation = glm::pi<float>() / 255.0;

void buildColorPalette()
{
    for (int i = 0; i < 255; i++)
    {
        colorPalette[i].r = glm::sin(i * colorToPIRelation * 2) * 128 + 128;
        colorPalette[i].g = glm::sin(i * colorToPIRelation * 3) * 128 + 128;
        colorPalette[i].b = glm::sin(i * colorToPIRelation * 4) * 128 + 128;
    }
}

void drawColorPalette(sf::Image &image)
{
    for (int i = 0; i < 255; i++)
    {
        image.setPixel(i, 0, colorPalette[i]);
    }
}

void drawPlasmaColor(sf::Image &image, float xShift, float yShift, float radialShift)
{
    float components[3] = {0};
    // Column mayor is cache friendly (or the other way around?)
    for (int y = 0; y < 240; y++)
        for (int x = 0; x < 320; x++)
        {
            sf::Color color = {0, 0, 0};

            components[0] = glm::sin((x + xShift) * 0.1);
            components[1] = glm::sin((x + y + yShift) * 0.01);
            components[2] = glm::sin((glm::distance(screenCenter, glm::vec2(x, y)) + radialShift) * 0.3);

            auto result = (components[0] + components[1] + components[2]) / 3;

            auto colorIndex = (unsigned char)(result * 128.0 + 128.0);

            image.setPixel(x, y, colorPalette[colorIndex]);
        }
}