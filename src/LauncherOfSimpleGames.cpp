// LauncherOfSimpleGames.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <SFML/Graphics.hpp>

#include "./core/Window.h"



/*class Window {
    sf::Window window;

}*/

int main(){
    test();
    // Создание окна и задание его настроек
    sf::RenderWindow window(sf::VideoMode(800, 600), "Launcher Of Simple Games", sf::Style::Default);
    window.setFramerateLimit(60);

    // Создание текстуры для заднего фона
    /*sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("background.jpg"))
        return -1;
    sf::Sprite background(backgroundTexture);*/

    // Создание текста для заголовка
    /*
    string map_name = test_map.getMapName();
    text.setString(String::fromUtf8(map_name.begin(), map_name.end()));
    Решение - sf::String::fromUtf8(youstring.begin(), youstring.end())
    */
    sf::Font font;
    if (!font.loadFromFile("font.ttf"))
        return -1;
    sf::Text title(L"Выберите игру", font, 48);
    title.setFillColor(sf::Color::White);
    title.setPosition(100, 50);

    // Создание кнопки для игры 1
    sf::RectangleShape game1Button(sf::Vector2f(200, 100));
    game1Button.setFillColor(sf::Color::Green);
    game1Button.setOutlineColor(sf::Color::White);
    game1Button.setOutlineThickness(2);
    game1Button.setPosition(100, 200);
    sf::Text game1Text("Игра 1", font, 24);
    game1Text.setFillColor(sf::Color::White);
    game1Text.setPosition(140, 240);

    // Создание кнопки для игры 2
    sf::RectangleShape game2Button(sf::Vector2f(200, 100));
    game2Button.setFillColor(sf::Color::Green);
    game2Button.setOutlineColor(sf::Color::White);
    game2Button.setOutlineThickness(2);
    game2Button.setPosition(400, 200);
    sf::Text game2Text("Игра 2", font, 24);
    game2Text.setFillColor(sf::Color::White);
    game2Text.setPosition(440, 240);

    // Главный цикл приложения
    while (window.isOpen())
    {
        // Обработка событий в окне
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

            // Обработка кликов по кнопкам
            if (event.type == sf::Event::MouseButtonPressed)
            {
                if (event.mouseButton.button == sf::Mouse::Left)
                {
                    sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));

                    if (game1Button.getGlobalBounds().contains(mousePosition))
                    {
                        // Запуск игры 1
                    }
                    else if (game2Button.getGlobalBounds().contains(mousePosition))
                    {
                        // Запуск игры 2
                    }
                }
            }
        }
        
        // Отрисовка элементов на экране
        window.clear();
        //window.draw(background);
        window.draw(title);
        window.draw(game1Button);
        window.draw(game1Text);
        window.draw(game2Button);
        window.draw(game2Text);
        window.display();
    }

    return 0;
}

/*#include <iostream>

int main()
{
    std::cout << "Hello World!\n";
}*/

// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
