#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class Game {
private:
    int player1Position;
    int player2Position;
    const int boardSize = 100;
    int snakes[11][2] = { {16, 6}, {47, 26}, {49, 11}, {56, 53}, {62, 19}, {64, 60}, {87, 24}, {93, 73}, {95, 75}, {98, 78} };
    int ladders[8][2] = { {1, 38}, {4, 14}, {9, 31}, {21, 42}, {28, 84}, {36, 44}, {51, 67}, {71, 91} };

public:
    Game() : player1Position(0), player2Position(0) {
        srand(static_cast<unsigned int>(time(0))); }

    void play() {
        while (player1Position < boardSize && player2Position < boardSize) {
            playerTurn(1);
            if (player1Position >= boardSize) {
                cout << "Player 1 wins!" << endl;
                break;
            }
            playerTurn(2);
            if (player2Position >= boardSize) {
                cout << "Player 2 wins!" << endl;
                break;
            }
        }
    }

private:
    void playerTurn(int player) {
        int diceRoll = rollDice();
        cout << "Player " << player << " rolled a " << diceRoll << endl;

        if (player == 1) {
            player1Position += diceRoll;
            if (player1Position > boardSize) {
                player1Position -= diceRoll; 
            } else {
                checkForSnakesAndLadders(player1Position);
            }
            cout << "Player 1 is now on square " << player1Position << endl;
        } else {
            player2Position += diceRoll;
            if (player2Position > boardSize) {
                player2Position -= diceRoll; 
            } else {
                checkForSnakesAndLadders(player2Position);
            }
            cout << "Player 2 is now on square " << player2Position << endl;
        }
    }

    int rollDice() {
        return rand() % 6 + 1; 
    }

    void checkForSnakesAndLadders(int& position) {
        
        for (int i = 0; i < 11; i++) {
            if (position == snakes[i][0]) {
                position = snakes[i][1];
                cout << "Oh no! Player " << (position == player1Position ? 1 : 2) << " hit a snake! Moved down to " << position << endl;
                return;
            }
        }
        
        for (int i = 0; i < 8; i++) {
            if (position == ladders[i][0]) {
                position = ladders[i][1];
                cout << "Yay! Player " << (position == player1Position ? 1 : 2) << " climbed a ladder! Moved up to " << position << endl;
                return;
            }
        }
    }
};

int main() {
    Game game;
    game.play();
    return 0;
}
