#include <iostream>
using namespace std;

bool handleInputs(string x, string y)
{
    int numX, numY;
    for(int i = 0; i < x.length(); i++)
        if (!isdigit(x[i])) return false;
    
    for(int i = 0; i < y.length(); i++)
        if (!isdigit(y[i])) return false;
    
    numX = stoi(x);
    numY = stoi(y);

    if (numX < 1 || numY < 1) return false;
    if (numX > 3 || numY > 3) return false;

    return true;
}

void printBoard(int** board)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            if (board[i][j] == 0) cout << " - ";
            if (board[i][j] == 1) cout << " X ";
            if (board[i][j] == 2) cout << " O ";
        }
        cout << endl;
    } 
}

bool winCon(int** board)
{
    for(int i = 0; i < 3; i++)
    {
        if (board[i][0] == 1 && board[i][1] == 1 && board[i][2] == 1)
        {
            cout << "Player 1 wins!" << endl;
            return true;
        }
        if (board[0][i] == 1 && board[1][i] == 1 && board[2][i] == 1)
        {
            cout << "Player 1 wins!" << endl;
            return true;
        }
        if (board[i][0] == 2 && board[i][1] == 2 && board[i][2] == 2)
        {
            cout << "Player 2 wins!" << endl;
            return true;
        }
        if (board[0][i] == 2 && board[1][i] == 2 && board[2][i] == 2)
        {
            cout << "Player 2 wins!" << endl;
            return true;
        }
    }
    if (board[0][0] == 1 && board[1][1] == 1 && board[2][2] == 1)
    {
        cout << "Player 1 wins!" << endl;
        return true;
    }

    if (board[0][2] == 1 && board[1][1] == 1 && board[2][0] == 1)
    {
        cout << "Player 1 wins!" << endl;
        return true;
    }

    if (board[0][0] == 2 && board[1][1] == 2 && board[2][2] == 2)
    {
        cout << "Player 2 wins!" << endl;
        return true;
    }

    if (board[0][2] == 2 && board[1][1] == 2 && board[2][0] == 2)
    {
        cout << "Player 2 wins!" << endl;
        return true;
    }

    return false;
}

void menu()
{
    string str1, str2;
    int player = 1;
    int turns = 0;
    system("clear");
    
    cout << "Player 1 goes first!" << endl;
    cout << "Please provide two numbers, the first being the X value" << endl;
    cout << "The second being the Y value." << endl;
    cout << "Example: '2 3' means second spot to the right, third row down." << endl;

    int** board = new int*[3];
    for(int i = 0; i < 3; i++)
        board[i] = new int[3];
    
    while(true)
    {
        cout << "Player " << player << " >> ";
        cin >> str1 >> str2;
        if (!handleInputs(str1, str2))
        {
            cout << "Apologies, '" << str1 << "'" << " '" << str2 << "' " << "are not valid inputs." << endl;
            continue;
        }
        int x = stoi(str2);
        int y = stoi(str1);
        if (board[x - 1][y - 1] > 0)
        {
            cout << "Spot has already been taken!" << endl;
            continue;
        }
        board[x - 1][y - 1] = player;
        printBoard(board);
        turns++; 
        if (turns > 4)
            if(winCon(board)) break;
        
        if (player == 1) player = 2;
        else player = 1;
    }
    
}

int main(int argc, char* argv[])
{
    menu();
    return 0;
}