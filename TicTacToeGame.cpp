#include <iostream>
#include <vector>

using namespace std;

// Function to print the Tic-Tac-Toe board
void printBoard(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j];
            if (j < 2) cout << " | ";
        }
        cout << endl;
        if (i < 2) cout << "---------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true;
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true;
    }
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true;
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true;
    return false;
}

// Function to check if the game is a draw
bool checkDraw(const vector<vector<char>>& board) {
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (board[i][j] == ' ') return false;
        }
    }
    return true;
}

int main() {
	char opt;
	
	do{
	    vector<vector<char>> board(3, vector<char>(3, ' '));
	    char currentPlayer = 'X';
	    bool gameWon = false;
	    bool gameDraw = false;
	
		system("CLS");
		
	    cout << "     *******  *  ******     *******  ******  ******     *******  ******  ******" << endl;
		cout << "        *     *  *             *     *    *  *             *     *    *  *" <<endl;
		cout << "        *     *  *             *     ******  *             *     *    *  ******" <<endl;
		cout << "        *     *  *             *     *    *  *             *     *    *  *" <<endl;
		cout << "        *     *  ******        *     *    *  ******        *     ******  ******" <<endl;
		
	    while (!gameWon && !gameDraw) {
	        cout << "\n[+] CURRENT BOARD\n" << endl;
	        printBoard(board);
	        cout << "\n[+] PLAYER " << currentPlayer <<endl;
			cout << "   ENTER YOUR MOVE (ROW & COLUMN)";
	        int row, col;
	        cin >> row >> col;
	
	        if (row < 1 || row > 3 || col < 1 || col > 3 || board[row-1][col-1] != ' ') {
	            cout << "INVALID MOVE :(" << endl;
	            continue;
	        }
	
	        board[row-1][col-1] = currentPlayer;
	
	        if (checkWin(board, currentPlayer)) {
	            cout << "\n\n~~~~~~~~~ PLAYER " << currentPlayer << " WINS! ~~~~~~~~~" << endl;
	            gameWon = true;
	        } else if (checkDraw(board)) {
	            cout << "IT'S A DRAW :|" << endl;
	            gameDraw = true;
	        }
	
	        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
	    }
	
	    cout << "THANKS FOR PLAYING!" << endl;
	    
	    cout << "\n[+] ANOTHER MATCH ??? (Y/N)" <<endl;
	    cin >> opt;
	    
	}while(opt == 'Y' || opt == 'y');
	
    return 0;
}

