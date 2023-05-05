#include "TicTacToe.h"
#include <SFML/Graphics.hpp>
#include <iostream>

/*class TicTacToe {
    private:
        // ������� ���� � �����
        const int BOARD_SIZE = 3;
        const int CELL_SIZE = 100;

        // ������� ����
        const int WINDOW_WIDTH = CELL_SIZE * BOARD_SIZE;
        const int WINDOW_HEIGHT = CELL_SIZE * BOARD_SIZE;

        // ������
        enum class PlayerType { NONE, PLAYER, BOT };
        struct Player {
            sf::Color color;
            PlayerType type;
        };

        void game() {
            PlayerType currentPlayer = PlayerType::NONE;

            // ������� �������
            std::vector<Player> players;
            players.push_back({ sf::Color::Red, PlayerType::PLAYER });
            players.push_back({ sf::Color::Blue, PlayerType::BOT });

            // ������� ����
            std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::NONE));

            sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TicTacToe", sf::Style::Default);
            window.setFramerateLimit(60);
        }

        // ������� ��� ��������� ���� � ���������/�������
        void drawBoard(Game& game) {
            // ��������� ����
            for (int i = 0; i < BOARD_SIZE; i++) {
                for (int j = 0; j < BOARD_SIZE; j++) {
                    sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
                    cell.setOutlineThickness(2);
                    cell.setOutlineColor(sf::Color::Black);
                    cell.setPosition(j CELL_SIZE, i * CELL_SIZE);
                    game.window.draw(cell);

                    // ��������� ���������/�������
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
            // ������� ������ ������ ������ � ������ ���� �����
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

            // ������� �������
            std::vector<Player> players;
            players.push_back({ sf::Color::Red, PlayerType::PLAYER });
            players.push_back({ sf::Color::Blue, PlayerType::BOT });

            // ������� ����
            std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::NONE));

            sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "TicTacToe", sf::Style::Default);
            window.setFramerateLimit(60);
        }

};*/



// ��������� ��������� ����
/*struct Game {
    sf::RenderWindow window;
    
    std::vector<Player> players;
    std::vector<std::vector<PlayerType>> board;

    // ���������� ����������� �� ���������
    Game() = default;

    // ���������� ����������� �����������
    Game(const Game& other)
        : window(other.window)
        , players(other.players)
        , board(other.board)
        , currentPlayer(other.currentPlayer) { }

    // ���������� �������� ������������
    Game& operator=(const Game& other) {
        window = other.window;
        players = other.players;
        board = other.board;
        currentPlayer = other.currentPlayer;
        return this;
    }
};*/

// ������� ��� �������� ����� ����
/*Game newGame() {
    // ������� ����
    sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), "��������-������");
    window.setFramerateLimit(60);

    // ������� �������
    std::vector<Player> players;
    players.push_back({ sf::Color::Red, PlayerType::Human });
    players.push_back({ sf::Color::Blue, PlayerType::Bot });

    // ������� ����
    std::vector<std::vector<PlayerType>> board(BOARD_SIZE, std::vector<PlayerType>(BOARD_SIZE, PlayerType::None));

    // ���������� ����� ����
    return { window, players, board, PlayerType::None };
}*/



// ������� ��� ��������, �������� �� ���� �����������
/*bool isGameOver(Game& game) {
    // �������� ����� � ��������
    for (int i = 0; i < BOARD_SIZE; i++) {
        if (game.board[i][0] != PlayerType::None && game.board[i][0] == game.board[i][1] && game.board[i][1] == game.board[i][2]) {
            return true;
        }
        if (game.board[0][i] != PlayerType::None && game.board[0][i] == game.board[1][i] && game.board[1][i] == game.board[2][i]) {
            return true;
        }
    }

    // �������� ����������
    if (game.board[0][0] != PlayerType::None && game.board[0][0] == game.board[1][1] && game.board[1][1] == game.board[2][2]) {
        return true;
    }
    if (game.board[0][2] != PlayerType::None && game.board[0][2] == game.board[1][1] && game.board[1][1] == game.board[2][0]) {
        return true;
    }

    // �������� ������� ������ �����
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (game.board[i][j] == PlayerType::None) {
                return false;
            }
        }
    }

    // ���� ��� ������ ����� � ��� ���������� - ���� ��������� ������
    return true;
}*/


// �������, ������� ���������, ����� �� ����� ��������� ���� ���� � ������ ������
/*bool canMakeMove(Game& game, int row, int col) {
    if (game.board[row][col] == PlayerType::None && game.currentPlayer == PlayerType::Human) {
        return true;
    }

    return false;
}*/

// ������� ��� ��������� ����� ����
/*void handleMouseClick(Game& game, int mouseX, int mouseY) {
    if (game.currentPlayer == PlayerType::Human) {
        // ���������� ����� ������, � ������� ��������
        int row = mouseY / CELL_SIZE;
        int col = mouseX / CELL_SIZE;

        // ���� ������ ������, �� ������ ���� �������
        if (canMakeMove(game, row, col)) {
            game.board[row][col] = PlayerType::Human;
            game.currentPlayer = PlayerType::Bot;
        }
    }
}*/

// ������� ��� ��������� �������
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

// ������� ��� ���������� ����
/*void update(Game & game) {
    // ���� ���� �����������, �� ��������� ��������� � ������� ����� ����
    if (isGameOver(game)) {
        std::cout << "���� ��������!" << std::endl;
        game = newGame();
        return;
    }

    // ��� ����
    if (game.currentPlayer == PlayerType::Bot) {
        botMove(game);
        game.currentPlayer = PlayerType::Human;
    }
}*/

// ������� ��� ������� ����
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