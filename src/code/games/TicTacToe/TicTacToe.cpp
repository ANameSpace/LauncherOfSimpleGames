#include "TicTacToe.h"
#include <SFML/Graphics.hpp>
#include <iostream>

/*class TicTacToe {
    private:
        // Размеры поля и ячеек
        const int BOARD_SIZE = 3;
        const int CELL_SIZE = 100;

        // Размеры окна
        const int WINDOW_WIDTH = CELL_SIZE * BOARD_SIZE;
        const int WINDOW_HEIGHT = CELL_SIZE * BOARD_SIZE;

        // Игроки
        enum class PlayerType { NONE, PLAYER, BOT };
        struct Player {
            sf::Color color;
            PlayerType type;
        };

        void game() {
            PlayerType currentPlayer = PlayerType::NONE;

            // Создаем игроков
            std::vector<Player> players;
            players.push_back({ sf::Color::Red, PlayerType::PLAYER });
            players.push_back({ sf::Color::Blue, PlayerType::BOT });

            // Создаем поле
            std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::NONE));

            sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TicTacToe", sf::Style::Default);
            window.setFramerateLimit(60);
        }

        // Функция для отрисовки поля и крестиков/ноликов
        void drawBoard(Game& game) {
            // Отрисовка поля
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                    cell.setOutlineThickness(2);
                    cell.setOutlineColor(sf::Color::Black);
                    cell.setPosition(j CELL_SIZE, i * CELL_SIZE);
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


        void botMove() {
            // Находим первую пустую ячейку и ставим туда нолик
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    if (board[i][j] == PlayerType::None) {
                        board[i][j] = PlayerType::Bot;
                        return;
                    }
                }
            }
        }

        

    public:
        void play() {
            PlayerType currentPlayer = PlayerType::NONE;

            // Создаем игроков
            std::vector<Player> players;
            players.push_back({ sf::Color::Red, PlayerType::PLAYER });
            players.push_back({ sf::Color::Blue, PlayerType::BOT });

            // Создаем поле
            std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::NONE));

            sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TicTacToe", sf::Style::Default);
            window.setFramerateLimit(60);
        }

};*/



// Описываем структуру игры
/*struct Game {
    sf::RenderWindow window;
    
    std::vector<Player> players;
    std::vector<std::vector<PlayerType>> board;

    // Определяем конструктор по умолчанию
    Game() = default;

    // Определяем конструктор копирования
    Game(const Game& other)
        : window(other.window)
        , players(other.players)
        , board(other.board)
        , currentPlayer(other.currentPlayer) { }

    // Определяем оператор присваивания
    Game& operator=(const Game& other) {
        window = other.window;
        players = other.players;
        board = other.board;
        currentPlayer = other.currentPlayer;
        return this;
    }
};*/

// Функция для создания новой игры
/*Game newGame() {
    // Создаем окно
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "Крестики-нолики");
    window.setFramerateLimit(60);

    // Создаем игроков
    std::vector<Player> players;
    players.push_back({ sf::Color::Red, PlayerType::Human });
    players.push_back({ sf::Color::Blue, PlayerType::Bot });

    // Создаем поле
    std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::None));

    // Возвращаем новую игру
    return { window, players, board, PlayerType::None };
}*/



// Функция для проверки, является ли игра законченной
/*bool isGameOver(Game& game) {
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
}*/


// Функция, которая проверяет, может ли игрок поставить свой знак в данной ячейке
/*bool canMakeMove(Game& game, int row, int col) {
    if (game.board[row][col] == PlayerType::None && game.currentPlayer == PlayerType::Human) {
        return true;
    }

    return false;
}*/

// Функция для обработки клика мыши
/*void handleMouseClick(Game& game, int mouseX, int mouseY) {
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
}*/

// Функция для обработки событий
/*void processEvents(Game& game) {
    sf::Event event;
    while (game.window.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            game.window.close();
        }
        else if (event.type == sf::Event::MouseButtonPressed) {
            if (event.mouseButton.button == sf::Mouse::Left) {
                handleMouseClick(game, event.mouseButton.x, event.mouseButton.y);
            }
        }
    }
}*/

// Функция для обновления игры
/*void update(Game & game) {
    // Если игра закончилась, то обновляем сообщение и создаем новую игру
    if (isGameOver(game)) {
        std::cout << "Игра окончена!" << std::endl;
        game = newGame();
        return;
    }

    // Ход бота
    if (game.currentPlayer == PlayerType::Bot) {
        botMove(game);
        game.currentPlayer = PlayerType::Human;
    }
}*/

// Функция для запуска игры
/*void play() {
    Game game = newGame();

    while (game.window.isOpen()) {
        processEvents(game);
        update(game);
        game.window.clear(sf::Color::White);
        drawBoard(game);
        game.window.display();
    }
}*/

/*int main() {
    play();
    return 0;
}*/