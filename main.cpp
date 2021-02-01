#include <vector>
#include <iostream>
#include <string>
using namespace std;

template <typename a>
void printv(string message, a c)
{
    cout << message << ": " << endl;
    for (auto b : c)
    {
        for (auto i : b)
        {
            cout << i << " ";
        }
        cout << endl;
    }
    cout << endl;
}

vector<vector<int>> GameOfLife(vector<vector<int>> board)
{
    vector<vector<int>> result(board);
    int lBoard = board.size();
    for (int iBoard = 0; iBoard < lBoard; iBoard++)
    {
        int lRow = result[iBoard].size();
        for (int iRow = 0; iRow < lRow; iRow++)
        {
            int cAlive = 0;
            // check same row
            if (lRow >= 1)
            {
                if (iRow >= 0 && iRow != (lRow - 1))
                    cAlive += (board[iBoard][iRow + 1] == 1) ? 1 : 0;
                if (iRow != 0 && iRow <= (lRow - 1))
                    cAlive += (board[iBoard][iRow - 1] == 1) ? 1 : 0;
            }

            // check middle row
            {
                if (iBoard >= 0 && iBoard < (lBoard - 1))
                {
                    int lenSD = board[iBoard + 1].size();
                    if (iRow != 0 && lenSD > 1)
                        cAlive += (board[iBoard + 1][iRow - 1] == 1) ? 1 : 0;
                    lenSD = ((iRow + 1) == lenSD) ? 1 : 2;
                    for (int i = 0; i < lenSD; i++)
                    {
                        cAlive += (board[iBoard + 1][iRow + i] == 1) ? 1 : 0;
                    }
                }
            }
            // check end row
            {
                if (iBoard != 0 && iBoard <= lBoard)
                {
                    int lenSU = board[iBoard - 1].size();
                    if (iRow != 0 && lenSU > 1)
                    {
                        cAlive += (board[iBoard - 1][iRow - 1] == 1) ? 1 : 0;
                    }
                    lenSU = ((iRow + 1) == lenSU) ? 1 : 2;
                    for (int x = 0; x < lenSU; x++)
                    {
                        cAlive += (board[iBoard - 1][iRow + x] == 1) ? 1 : 0;
                    }
                }
            }
            if ((result[iBoard][iRow] == 1) && (cAlive < 2 || cAlive > 3))
                result[iBoard][iRow] = 0;
            else if ((result[iBoard][iRow] == 0) && cAlive == 3)
                result[iBoard][iRow] = 1;
        }
    }
    return result;
}

int main()
{
    vector<vector<int>> board{
        {1, 0, 1, 1},
        {1, 0, 1, 1}};
    printv("input",board);
    printv("output",GameOfLife(board));
    return 0;
}