#include <iostream>
#include <vector>

char board[3][3] = {{'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'}};

void DrawBoard() {
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

bool CheckWin() {
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return true;
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return true;
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return true;
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return true;
    return false;
}

int main() {
    int player = 1;
    int position;
    bool win = false;

    while (!win) {
        DrawBoard();
        std::cout << "Player " << player << ", enter a number: ";
        std::cin >> position;

        if (position < 1 || position > 9) {
            std::cout << "Invalid position!\n";
            continue;
        }

        int row = (position - 1) / 3;
        int col = (position - 1) % 3;

        if (board[row][col] != 'X' && board[row][col] != 'O') {
            board[row][col] = (player == 1) ? 'X' : 'O';
            if (CheckWin()) {
                std::cout << "Player " << player << " wins!\n";
                win = true;
            }
            player = (player == 1) ? 2 : 1;
        } else {
            std::cout << "Position already taken!\n";
        }
    }

    return 0;
}
