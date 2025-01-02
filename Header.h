#ifndef HEADER_H
#define HEADER_H

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stack>
#include <iomanip>
#include <ctime>
#include <sstream>

#ifdef _WIN32
#include <direct.h> // For Windows
#else
#include <sys/stat.h> // For POSIX systems
#endif

class Slider {
public:
    Slider(float x, float y, float width, float height, sf::Color color, float min, float max, float value);
    void draw(sf::RenderWindow& window);
    void handleEvent(const sf::Event& event);
    float getValue() const;

private:
    void updateHandlePosition();
    sf::RectangleShape background;
    sf::RectangleShape handle;
    sf::Vector2f position;
    sf::Vector2f size;
    sf::Color color;
    float min;
    float max;
    float value;
    bool dragging = false;
};

class Button {
public:
    Button(float x, float y, float size, const std::string& textureFile);
    void draw(sf::RenderWindow& window);
    bool isClicked(const sf::Event& event);

private:
    sf::RectangleShape shape;
    sf::Sprite sprite;
    sf::Texture texture;
};

class PaintModule {
public:
    PaintModule();
    void run();

private:
    void handleEvents();
    void update();
    void draw();
    void fill(sf::RenderTexture& canvas, sf::Vector2i position, sf::Color fillColor);
    std::string getCurrentTime();
    void saveImage(const sf::RenderTexture& canvas, const std::string& fileName);

    sf::RenderWindow window;
    sf::RenderTexture canvasTexture;
    sf::Sprite canvasSprite;
    sf::Vector2i prevMousePos;
    bool drawing;
    bool fillClicked;
    sf::Color brushColor;
    float brushSize;
    Slider redSlider;
    Slider greenSlider;
    Slider blueSlider;
    Slider sizeSlider;
    sf::RectangleShape topPanel;
    sf::CircleShape brushPreview;
    float buttonSize;
    Button drawButton;
    Button eraseButton;
    Button fillButton;
    Button saveButton;
    std::stack<sf::Image> undoStack;
    enum Tool { DRAW, ERASE, FILL };
    Tool currentTool;
    bool showMenu;
};

#endif // HEADER_H