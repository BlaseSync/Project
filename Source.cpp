#include "Header.h"

// Implementation of the Slider class methods

Slider::Slider(float x, float y, float width, float height, sf::Color color, float min, float max, float value)
    : position(x, y), size(width, height), color(color), min(min), max(max), value(value) {
    background.setSize(size);
    background.setPosition(position);
    background.setFillColor(sf::Color(200, 200, 200));

    handle.setSize(sf::Vector2f(20, size.y));
    handle.setFillColor(color);
    updateHandlePosition();
}

void Slider::draw(sf::RenderWindow& window) {
    window.draw(background);
    window.draw(handle);
}

void Slider::handleEvent(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (handle.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            dragging = true;
        }
    }
    else if (event.type == sf::Event::MouseButtonReleased) {
        dragging = false;
    }
    else if (event.type == sf::Event::MouseMoved) {
        if (dragging) {
            float mouseX = static_cast<float>(event.mouseMove.x);
            value = min + (mouseX - position.x) / size.x * (max - min);
            value = std::max(min, std::min(max, value));
            updateHandlePosition();
        }
    }
}

float Slider::getValue() const {
    return value;
}

void Slider::updateHandlePosition() {
    float handleX = position.x + (value - min) / (max - min) * size.x - handle.getSize().x / 2;
    handle.setPosition(handleX, position.y);
}

// Implementation of the Button class methods

Button::Button(float x, float y, float size, const std::string& textureFile) {
    shape.setSize(sf::Vector2f(size, size));
    shape.setPosition(x, y);
    shape.setFillColor(sf::Color(200, 200, 200));

    if (!texture.loadFromFile(textureFile)) {
        std::cerr << "Error loading texture: " << textureFile << "\n";
    }
    else {
        sprite.setTexture(texture);
        float scaleX = size / texture.getSize().x;
        float scaleY = size / texture.getSize().y;
        sprite.setScale(scaleX, scaleY);
        sprite.setPosition(x, y);
    }
}

void Button::draw(sf::RenderWindow& window) {
    window.draw(shape);
    window.draw(sprite);
}

bool Button::isClicked(const sf::Event& event) {
    if (event.type == sf::Event::MouseButtonPressed) {
        if (shape.getGlobalBounds().contains(event.mouseButton.x, event.mouseButton.y)) {
            return true;
        }
    }
    return false;
}

// Implementation of the PaintModule class methods

PaintModule::PaintModule() :
    window(sf::VideoMode(1920, 1080), "Simple Paint", sf::Style::Fullscreen),
    redSlider(50, 50, 300, 20, sf::Color::Red, 0, 255, brushColor.r),
    greenSlider(50, 100, 300, 20, sf::Color::Green, 0, 255, brushColor.g),
    blueSlider(50, 150, 300, 20, sf::Color::Blue, 0, 255, brushColor.b),
    sizeSlider(50, 200, 300, 20, sf::Color::Black, 1, 50, brushSize),
    buttonSize(100.0f),
    drawButton(750, 50, buttonSize, "brush.png"),
    eraseButton(850, 50, buttonSize, "eraser.png"),
    fillButton(750, 150, buttonSize, "fill.png"),
    saveButton(850, 150, buttonSize, "save.png"),
    prevMousePos(sf::Mouse::getPosition(window)),
    drawing(false),
    fillClicked(false),
    brushColor(sf::Color::Black),
    brushSize(5.0f),
    currentTool(DRAW),
    showMenu(true) {

    canvasTexture.create(1920, 1080);
    canvasSprite.setTexture(canvasTexture.getTexture());
    canvasTexture.clear(sf::Color::White);
    canvasTexture.display();
    topPanel.setSize(sf::Vector2f(1920, 300));
    topPanel.setFillColor(sf::Color(150, 150, 150));
    brushPreview.setRadius(brushSize / 2);
    brushPreview.setFillColor(brushColor);
    brushPreview.setPosition(400, 150 - brushPreview.getRadius());
}

void PaintModule::run() {
    while (window.isOpen()) {
        handleEvents();
        update();
        draw();
    }
}

void PaintModule::handleEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            window.close();
        }
        if (event.type == sf::Event::KeyPressed) {
            if (event.key.code == sf::Keyboard::M) {
                showMenu = !showMenu;
            }
            else if (event.key.code == sf::Keyboard::Z && event.key.control) {
                if (!undoStack.empty()) {
                    sf::Image prevImage = undoStack.top();
                    undoStack.pop();
                    canvasTexture.clear(sf::Color::White);
                    sf::Texture texture;
                    texture.loadFromImage(prevImage);
                    sf::Sprite sprite(texture);
                    canvasTexture.draw(sprite);
                    canvasTexture.display();
                }
            }
        }

        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            if (event.mouseButton.y > 300 || !showMenu) {
                drawing = true;
                prevMousePos = sf::Mouse::getPosition(window);
                undoStack.push(canvasTexture.getTexture().copyToImage());
                if (currentTool == FILL) {
                    fillClicked = true;
                }
            }
            else {
                if (drawButton.isClicked(event)) {
                    currentTool = DRAW;
                }
                else if (eraseButton.isClicked(event)) {
                    currentTool = ERASE;
                }
                else if (fillButton.isClicked(event)) {
                    currentTool = FILL;
                }
                else if (saveButton.isClicked(event)) {
                    std::string fileName;
                    std::cout << "Enter file name (without extension): ";
                    std::cin >> fileName;
                    if (fileName.empty()) {
                        fileName = "drawing_" + getCurrentTime();
                    }
                    fileName += ".png";
                    saveImage(canvasTexture, fileName);
                }
            }
        }
        if (event.type == sf::Event::MouseButtonReleased && event.mouseButton.button == sf::Mouse::Left) {
            drawing = false;
            if (fillClicked) {
                sf::Vector2i mousePos = sf::Mouse::getPosition(window);
                if (mousePos.x >= 0 && mousePos.x < 1920 && mousePos.y >= 300 && mousePos.y < 1080) {
                    fill(canvasTexture, mousePos, brushColor);
                }
                fillClicked = false;
            }
        }

        if (showMenu) {
            redSlider.handleEvent(event);
            greenSlider.handleEvent(event);
            blueSlider.handleEvent(event);
            sizeSlider.handleEvent(event);
        }
    }
}

void PaintModule::update() {
    brushColor.r = static_cast<sf::Uint8>(redSlider.getValue());
    brushColor.g = static_cast<sf::Uint8>(greenSlider.getValue());
    brushColor.b = static_cast<sf::Uint8>(blueSlider.getValue());
    brushSize = sizeSlider.getValue();

    brushPreview.setFillColor(brushColor);
    brushPreview.setRadius(brushSize / 2);
    brushPreview.setPosition(400, 150 - brushPreview.getRadius());

    if (drawing && currentTool != FILL) {
        sf::Vector2i mousePos = sf::Mouse::getPosition(window);
        if (mousePos.x >= 0 && mousePos.x < 1920 && mousePos.y >= 0 && mousePos.y < 1080) {
            sf::Color currentColor = (currentTool == ERASE) ? sf::Color::White : brushColor;

            sf::Vertex line[] = {
                sf::Vertex(sf::Vector2f(prevMousePos.x, prevMousePos.y), currentColor),
                sf::Vertex(sf::Vector2f(mousePos.x, mousePos.y), currentColor)
            };

            if (brushSize <= 1.0f) {
                canvasTexture.draw(line, 2, sf::Lines);
            }
            else {
                sf::CircleShape brush(brushSize / 2);
                brush.setFillColor(currentColor);
                sf::Vector2f direction = sf::Vector2f(mousePos.x - prevMousePos.x, mousePos.y - prevMousePos.y);
                float length = std::sqrt(direction.x * direction.x + direction.y * direction.y);
                for (float i = 0; i < length; i += brushSize / 2) {
                    brush.setPosition(prevMousePos.x + direction.x * (i / length) - brush.getRadius(), prevMousePos.y + direction.y * (i / length) - brush.getRadius());
                    canvasTexture.draw(brush);
                }
            }
            canvasTexture.display();

            prevMousePos = mousePos;
        }
    }
}

void PaintModule::draw() {
    window.clear();
    window.draw(canvasSprite);
    if (showMenu) {
        window.draw(topPanel);
        redSlider.draw(window);
        greenSlider.draw(window);
        blueSlider.draw(window);
        sizeSlider.draw(window);
        window.draw(brushPreview);
        drawButton.draw(window);
        eraseButton.draw(window);
        fillButton.draw(window);
        saveButton.draw(window);
    }
    window.display();
}

void PaintModule::fill(sf::RenderTexture& canvas, sf::Vector2i position, sf::Color fillColor) {
    sf::Image canvasImage = canvas.getTexture().copyToImage();
    sf::Color targetColor = canvasImage.getPixel(position.x, position.y);

    if (targetColor == fillColor) return;

    std::vector<sf::Vector2i> stack;
    stack.push_back(position);

    while (!stack.empty()) {
        sf::Vector2i point = stack.back();
        stack.pop_back();

        if (point.x < 0 || point.x >= 1920 || point.y < 0 || point.y >= 1080) continue;
        if (canvasImage.getPixel(point.x, point.y) != targetColor) continue;

        canvasImage.setPixel(point.x, point.y, fillColor);

        stack.push_back(sf::Vector2i(point.x + 1, point.y));
        stack.push_back(sf::Vector2i(point.x - 1, point.y));
        stack.push_back(sf::Vector2i(point.x, point.y + 1));
        stack.push_back(sf::Vector2i(point.x, point.y - 1));
    }

    canvas.clear(sf::Color::White);
    sf::Texture texture;
    texture.loadFromImage(canvasImage);
    sf::Sprite sprite(texture);
    canvas.draw(sprite);
    canvas.display();
}

std::string PaintModule::getCurrentTime() {
    auto now = std::time(nullptr);
    std::tm tm;
    localtime_s(&tm, &now);
    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d_%H-%M-%S");
    return oss.str();
}

void PaintModule::saveImage(const sf::RenderTexture& canvas, const std::string& fileName) {
    int resultDir;
#ifdef _WIN32
    resultDir = _mkdir("paintings");
#else
    resultDir = mkdir("paintings", 0777);
#endif
    if (resultDir != 0 && errno != EEXIST) {
        std::cerr << "Failed to create directory." << std::endl;
        return;
    }

    std::string filePath = "paintings/" + fileName;
    if (canvas.getTexture().copyToImage().saveToFile(filePath)) {
        std::cout << "Saved to " << filePath << std::endl;
    }
    else {
        std::cerr << "Failed to save image." << std::endl;
    }
}