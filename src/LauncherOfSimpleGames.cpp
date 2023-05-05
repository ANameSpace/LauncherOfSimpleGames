// LauncherOfSimpleGames.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>
//#include "./core/Window.h"

int main() {
    const int BUTTON_WIDTH = 200;
    const int BUTTON_HEIGHT = 300;
    // Создание окна и задание его настроек
    sf::RenderWindow window(sf::VideoMode(800, 600), "Launcher Of Simple Games", sf::Style::Default);
    window.setFramerateLimit(60);

    // Создание текстуры для заднего фона
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("./src/resources/image/background.jpg")) { /*return -1;*/ }
    sf::Sprite background(backgroundTexture);


    /*
    INFO Русские символы из конфигурации
    string map_name = test_map.getMapName();
    text.setString(String::fromUtf8(map_name.begin(), map_name.end()));
    Решение - sf::String::fromUtf8(youstring.begin(), youstring.end())
    */

    // Создание текста для заголовка
    sf::Font font;
    if (!font.loadFromFile("./src/resources/fonts/font.ttf")) {return -1;}
    sf::Text title(L"Выберите игру", font, 48);
    title.setFillColor(sf::Color::White);
    title.setPosition(150, 70);

    // Создание кнопки для игры 1
    sf::RectangleShape game1Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    game1Button.setFillColor(sf::Color::Green);
    game1Button.setOutlineColor(sf::Color::White);
    game1Button.setOutlineThickness(2);
    game1Button.setPosition(100, 250);
    sf::Text game1Text("TicTacToe", font, 24);
    game1Text.setFillColor(sf::Color::White);
    game1Text.setPosition(120, 500);

    // Создание кнопки для игры 2
    sf::RectangleShape game2Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    game2Button.setFillColor(sf::Color::Red);
    game2Button.setOutlineColor(sf::Color::White);
    game2Button.setOutlineThickness(2);
    game2Button.setPosition(325, 250);
    sf::Text game2Text(L"Скоро...", font, 24);
    game2Text.setFillColor(sf::Color::White);
    game2Text.setPosition(350, 500);

    // Создание кнопки для игры 2
    sf::RectangleShape game3Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    game3Button.setFillColor(sf::Color::Red);
    game3Button.setOutlineColor(sf::Color::White);
    game3Button.setOutlineThickness(2);
    game3Button.setPosition(550, 250);
    sf::Text game3Text(L"Скоро...", font, 24);
    game3Text.setFillColor(sf::Color::White);
    game3Text.setPosition(600, 500);

    // Главный цикл приложения
    while (window.isOpen())
    {
        // Обработка событий в окне
        sf::Event event;
        while (window.pollEvent(event)){
            switch (event.type){
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left){
                        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                        if (game1Button.getGlobalBounds().contains(mousePosition)) {
                            window.close();
                            break;

                            // Запуск игры 1
                        }else if (game2Button.getGlobalBounds().contains(mousePosition)) {
                        // Запуск игры 2
                        }else if (game3Button.getGlobalBounds().contains(mousePosition)) {
                            // Запуск игры 2
                        }
                    }
                    break;
                default:
                    break;
            }
        }        
        // Отрисовка элементов на экране
        window.clear();
        window.draw(background);
        window.draw(title);
        // 1
        window.draw(game1Button);
        window.draw(game1Text);
        // 2
        window.draw(game2Button);
        window.draw(game2Text);
        // 3
        window.draw(game3Button);
        window.draw(game3Text);
        window.display();
    }

    return 0;
}
