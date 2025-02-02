#include <cassert>
#include <iostream>
#include <set>

bool validSolution(unsigned int board[9][9])
{
    std::set<unsigned int> total1, total2, total3;
    for (int i = 0; i < 9; i++)
    {
        total1.insert(board[i][i]);
        for (int j = 0; j < 9; j++)
        {
            total1.insert(board[i][j]);
            total2.insert(board[j][i]);
            if (board[i][j] == 0)
            {
                return false;
            }
        }

        if ((total1.size() != 9) || (total1.size() != 9))
        {
            return false;
        }
        total1.clear();
        total2.clear();
    }

    for (int i = 0; i < 9; i = i + 3)
    {
        for (int j = 0; j < 9; j = j + 3)
        {
            for (int k = 0; k < 3; k++)
            {
                for (int l = 0; l < 3; l++)
                {
                    total1.insert(board[i + k][j + l]);
                }
            }
            if (total1.size() != 9)
            {
                return false;
            }
            total1.clear();
        }
    }

    return true;
}

int main()
{

    unsigned int example1[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                   {6, 7, 2, 1, 9, 5, 3, 4, 8},
                                   {1, 9, 8, 3, 4, 2, 5, 6, 7},
                                   {8, 5, 9, 7, 6, 1, 4, 2, 3},
                                   {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                   {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                   {9, 6, 1, 5, 3, 7, 2, 8, 4},
                                   {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                   {3, 4, 5, 2, 8, 6, 1, 7, 9}};

    unsigned int example2[9][9] = {{5, 3, 4, 6, 7, 8, 9, 1, 2},
                                   {6, 7, 2, 1, 9, 0, 3, 4, 8},
                                   {1, 0, 0, 3, 4, 2, 5, 6, 0},
                                   {8, 5, 9, 7, 6, 1, 0, 2, 0},
                                   {4, 2, 6, 8, 5, 3, 7, 9, 1},
                                   {7, 1, 3, 9, 2, 4, 8, 5, 6},
                                   {9, 0, 1, 5, 3, 7, 2, 1, 4},
                                   {2, 8, 7, 4, 1, 9, 6, 3, 5},
                                   {3, 0, 0, 4, 8, 1, 1, 7, 9}};

    assert(validSolution(example1) == true);
    assert(validSolution(example2) == false);
    std::cout << "Test passed" << std::endl;
}