#include <iostream>
#include <SFML/Graphics.hpp>
//#include "./code/games/TicTacToe/TicTacToe.h"

class TicTacToe {
public:

    const static int WINDOW_ICON_SIZE = 64;

    // Размеры поля и ячеек
    static const int BOARD_SIZE = 3;
    static const int CELL_SIZE = 100;

    // Размеры окна
    static const int WINDOW_WIDTH = CELL_SIZE * BOARD_SIZE;
    static const int WINDOW_HEIGHT = CELL_SIZE * BOARD_SIZE;

    // Описываем структуру игрока и бота
    enum class PlayerType { None, Human, Bot };
    struct Player {
        sf::Color color;
        PlayerType type;
    };

    // Описываем структуру игры
    struct Game {
        sf::RenderWindow window;
        std::vector<Player> players;
        std::vector<std::vector<PlayerType>> board;
        PlayerType currentPlayer = PlayerType::None;
    };

    // Функция для отрисовки поля и крестиков/ноликов
    void drawBoard(Game& game) {
        // Отрисовка поля
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                cell.setOutlineThickness(2);
                cell.setOutlineColor(sf::Color::Black);
                cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                game.window.draw(cell);

                // Отрисовка крестиков/ноликов
                if (game.board[i][j] != PlayerType::None) {
                    Player player = game.players[static_cast<int>(game.board[i][j]) - 1];

                    if (game.board[i][j] == PlayerType::Human) {
                        sf::RectangleShape cross(sf::Vector2f(CELL_SIZE - 20, 10));
                        cross.setFillColor(player.color);
                        cross.rotate(45);
                        cross.setPosition(j * CELL_SIZE + 10, i * CELL_SIZE + 45);
                        game.window.draw(cross);
                        cross.rotate(-90);
                        cross.setPosition(j * CELL_SIZE + 60, i * CELL_SIZE + 45);
                        game.window.draw(cross);
                    }
                    else {
                        sf::CircleShape circle(CELL_SIZE / 2 - 20);
                        circle.setFillColor(player.color);
                        circle.setPosition(j * CELL_SIZE + 20, i * CELL_SIZE + 20);
                        game.window.draw(circle);
                    }
                }
            }
        }
    }

    // Функция для проверки, является ли игра законченной
    bool isGameOver(Game& game) {
        // Проверка строк и столбцов
        for (int i = 0; i < BOARD_SIZE; i++) {
            if (game.board[i][0] != PlayerType::None && game.board[i][0] == game.board[i][1] && game.board[i][1] == game.board[i][2]) {
                return true;
            }
            if (game.board[0][i] != PlayerType::None && game.board[0][i] == game.board[1][i] && game.board[1][i] == game.board[2][i]) {
                return true;
            }
        }

        // Проверка диагоналей
        if (game.board[0][0] != PlayerType::None && game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2]) {
            return true;
        }
        if (game.board[0][2] != PlayerType::None && game.board[0][2] == game.board[1][1] && game.board[1][1] == game.board[2][0]) {
            return true;
        }

        // Проверка наличия пустых ячеек
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (game.board[i][j] == PlayerType::None) {
                    return false;
                }
            }
        }

        // Если нет пустых ячеек и нет победителя - игра закончена вничью
        return true;
    }

    // Функция для хода бота
    void botMove(Game& game) {
        // Находим первую пустую ячейку и ставим туда нолик
        for (int i = 0; i < BOARD_SIZE; i++) {
            for (int j = 0; j < BOARD_SIZE; j++) {
                if (game.board[i][j] == PlayerType::None) {
                    game.board[i][j] = PlayerType::Bot;
                    return;
                }
            }
        }
    }

    // Функция, которая проверяет, может ли игрок поставить свой знак в данной ячейке
    bool canMakeMove(Game& game, int row, int col) {
        if (game.board[row][col] == PlayerType::None && game.currentPlayer == PlayerType::Human) {
            return true;
        }

        return false;
    }

    // Функция для обработки клика мыши
    void handleMouseClick(Game& game, int mouseX, int mouseY) {
        if (game.currentPlayer == PlayerType::Human) {
            // Определяем номер ячейки, в которую кликнули
            int row = mouseY / CELL_SIZE;
            int col = mouseX / CELL_SIZE;

            // Если ячейка пустая, то ставим туда крестик
            if (canMakeMove(game, row, col)) {
                game.board[row][col] = PlayerType::Human;
                game.currentPlayer = PlayerType::Bot;
            }
        }
    }

    // Функция для обработки событий
    void processEvents(Game& game) {

    }

    // Функция для обновления игры
    void update(Game& game) {
        // Если игра закончилась, то обновляем сообщение и создаем новую игру
        if (isGameOver(game)) {
            std::cout << "Игра окончена!" << std::endl;
            return;
        }

        // Ход бота
        if (game.currentPlayer == PlayerType::Bot) {
            botMove(game);
            game.currentPlayer = PlayerType::Human;
        }
    }

    // Функция для запуска игры
    static void play_old() {
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Крестики-нолики");
        window.setFramerateLimit(60);

        // Создаем игроков
        std::vector<Player> players;
        players.push_back({ sf::Color::Red, PlayerType::Human });
        players.push_back({ sf::Color::Blue, PlayerType::Bot });

        // Создаем поле
        std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::None));

        while (window.isOpen()) {
            window.clear(sf::Color::White);
            // Отрисовка поля
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                    cell.setOutlineThickness(2);
                    cell.setOutlineColor(sf::Color::Black);
                    cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
                    window.draw(cell);

                    // Отрисовка крестиков/ноликов
                    if (board[i][j] != PlayerType::None) {
                        Player player = players[static_cast<int>(board[i][j]) - 1];

                        if (board[i][j] == PlayerType::Human) {
                            sf::RectangleShape cross(sf::Vector2f(CELL_SIZE - 20, 10));
                            cross.setFillColor(player.color);
                            cross.rotate(45);
                            cross.setPosition(j * CELL_SIZE + 10, i * CELL_SIZE + 45);
                            window.draw(cross);
                            cross.rotate(-90);
                            cross.setPosition(j * CELL_SIZE + 60, i * CELL_SIZE + 45);
                            window.draw(cross);
                        }
                        else {
                            sf::CircleShape circle(CELL_SIZE / 2 - 20);
                            circle.setFillColor(player.color);
                            circle.setPosition(j * CELL_SIZE + 20, i * CELL_SIZE + 20);
                            window.draw(circle);
                        }

                    }
                }
            }
            window.display();
        }
    }
    static void play() {
        // WINDOW
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TicTacToe", sf::Style::Default);
        window.setFramerateLimit(60);

        // ICON
        sf::Image icon;
        if (!icon.loadFromFile("./src/resources/image/icon.jpg")) { return; }
        window.setIcon(WINDOW_ICON_SIZE, WINDOW_ICON_SIZE, icon.getPixelsPtr());

        // FONT
        sf::Font font;
        if (!font.loadFromFile("./src/resources/fonts/font.ttf")) { return; }

        // BACKGOUND
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("./src/resources/image/background.jpg")) { return; }
        sf::Sprite background(backgroundTexture);

        // CORE
        while (window.isOpen()) {
            // DISPLAY
            window.clear();
            window.draw(background);
            //window.draw(title);

            // DISPLAY FINAL
            window.display();


            // EVENTS
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                default:
                    break;
                }
            }
        }
    }
};


//
//  LAUNCHER
//
class Launcher {
private:
    //CONST
    const static int WINDOW_WIDTH = 800;
    const static int WINDOW_HEIGHT = 600;
    const static int WINDOW_ICON_SIZE = 64;
    const static int BUTTON_WIDTH = 200;
    const static int BUTTON_HEIGHT = 300;

    static void addButton(sf::RectangleShape& gameButton, bool eneble, sf::Font font, int x, int y, sf::Text& gameText, int name_x, int name_y, sf::Text& gameTextStatsG, sf::Text& gameTextStatsW) {
        sf::Color COLOR;
        if (eneble == true) {
            COLOR = sf::Color::Green;
        }
        else {
            COLOR = sf::Color::Red;
        }
        gameButton.setFillColor(COLOR);
        gameButton.setOutlineColor(sf::Color::White);
        gameButton.setOutlineThickness(2);
        gameButton.setPosition(x, y);

        gameText.setFillColor(sf::Color::White);
        gameTextStatsG.setFillColor(sf::Color::White);
        gameTextStatsW.setFillColor(sf::Color::White);

        gameTextStatsG.setPosition(name_x, name_y - 50);
        gameTextStatsW.setPosition(name_x, name_y - 30);
        gameText.setPosition(name_x, name_y);
    }

public:
    static void start() {
        // WINDOW
        sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Launcher Of Simple Games", sf::Style::Default);
        window.setFramerateLimit(60);

        // ICON
        sf::Image icon;
        if (!icon.loadFromFile("./src/resources/image/icon.jpg")) { return; }
        window.setIcon(WINDOW_ICON_SIZE, WINDOW_ICON_SIZE, icon.getPixelsPtr());

        // FONT
        sf::Font font;
        if (!font.loadFromFile("./src/resources/fonts/font.ttf")) { return; }

        // BACKGOUND
        sf::Texture backgroundTexture;
        if (!backgroundTexture.loadFromFile("./src/resources/image/background.jpg")) { return; }
        sf::Sprite background(backgroundTexture);

        // TITLE
        sf::Text title(L"Выберите игру:", font, 48);
        title.setFillColor(sf::Color::White);
        title.setPosition(170, 70);

        // BUTTONS
        sf::RectangleShape game1Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        sf::Text game1Text("TicTacToe", font, 24);
        sf::Text game1StatsG("Total: NO STATS", font, 16);
        sf::Text game1StatsW("Wins: NO STATS", font, 16);
        addButton(game1Button, true, font, 100, 250, game1Text, 120, 500, game1StatsG, game1StatsW);

        sf::RectangleShape game2Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        sf::Text game2Text(L"Скоро...", font, 24);
        sf::Text game2StatsG("Total: NO STATS", font, 16);
        sf::Text game2StatsW("Wins: NO STATS", font, 16);
        addButton(game2Button, false, font, 325, 250, game2Text, 350, 500, game2StatsG, game2StatsW);

        sf::RectangleShape game3Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
        sf::Text game3Text(L"Скоро...", font, 24);
        sf::Text game3StatsG("Total: NO STATS", font, 16);
        sf::Text game3StatsW("Wins: NO STATS", font, 16);
        addButton(game3Button, false, font, 550, 250, game3Text, 570, 500, game3StatsG, game3StatsW);

        // CORE
        while (window.isOpen()) {
            // DISPLAY
            window.clear();
            window.draw(background);
            window.draw(title);
            // 1
            window.draw(game1Button);
            window.draw(game1StatsG);
            window.draw(game1StatsW);
            window.draw(game1Text);
            // 2
            window.draw(game2Button);
            window.draw(game2StatsG);
            window.draw(game2StatsW);
            window.draw(game2Text);
            // 3
            window.draw(game3Button);
            window.draw(game3StatsG);
            window.draw(game3StatsW);
            window.draw(game3Text);
            // DISPLAY FINAL
            window.display();


            // EVENTS
            sf::Event event;
            while (window.pollEvent(event)) {
                switch (event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    if (event.mouseButton.button == sf::Mouse::Left) {
                        sf::Vector2f mousePosition = window.mapPixelToCoords(sf::Vector2i(event.mouseButton.x, event.mouseButton.y));
                        if (game1Button.getGlobalBounds().contains(mousePosition)) {
                            TicTacToe::play();
                            break;
                        }
                        else if (game2Button.getGlobalBounds().contains(mousePosition)) {
                            window.close();
                            //TicTacToe::play();
                            break;
                        }
                        else if (game3Button.getGlobalBounds().contains(mousePosition)) {
                            window.close();
                            //TicTacToe::play();
                            break;
                        }
                    }
                default:
                    break;
                }
            }
        }
    }
};

int main() {
    Launcher::start();
}






/*int main() {
    /*
    INFO Русские символы из конфигурации
    string map_name = test_map.getMapName();
    text.setString(String::fromUtf8(map_name.begin(), map_name.end()));
    Решение - sf::String::fromUtf8(youstring.begin(), youstring.end())
    *//*

    // Создание кнопки для игры 1
    sf::RectangleShape game1Button(sf::Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT));
    game1Button.setFillColor(sf::Color::Green);
    game1Button.setOutlineColor(sf::Color::White);
    game1Button.setOutlineThickness(2);
    game1Button.setPosition(100, 250);
    sf::Text game1Text("TicTacToe", font, 24);
    game1Text.setFillColor(sf::Color::White);
    game1Text.setPosition(120, 500);
}*/


