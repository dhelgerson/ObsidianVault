#include <cstdlib>
#include <iomanip>
#include <cmath>
#include <vector>
#include <iostream>

using namespace std;

class Board
{
private:
    bool** spaces;
    int size;

public:
    Board(int size)
    {
        this->size = size;
        spaces = new bool*[size];
        for (int i = 0; i < size; ++i)
        {
            spaces[i] = new bool[size];
        }
    }

    bool isSafe(int row, int column, vector<int>& state)
    {
        //check row conflict
        //no need to check for column conflicts
        //because the board is beimg filled column
        //by column
        for(int i = 0; i < column; ++i)
        {
            if(state[i] == row)
            {
                return false;
            }
        }
 
        //check for diagonal conflicts
        int columnDiff = 0;
        int rowDiff = 0;
        for(int i = 0; i < column; ++i)
        {
            columnDiff = abs(column - i);
            rowDiff = abs(row - state[i]);
            if(columnDiff == rowDiff)
            return false;
        }

        return true;

    }

    int getSize()
    {
        return size;
    }

    bool getSpace(int x, int y)
    {
        return spaces[y][x];
    }

    void setSpace(int x, int y, bool value)
    {
        spaces[y][x] = value;
    }

Board(Board& other)
    {
        this->size = other.getSize();
        spaces = new bool*[size];
        for (int i = 0; i < size; ++i)
        {
            spaces[i] = new bool[size];
            for (int j = 0; j < size; ++j)
            {
                spaces[i][j] = other.getSpace(j, i);
            }
        }
    }

    bool backtrack(vector<int>& state, int& column, int board_size)
    {
    int row = 0;
    bool backtrack = column == board_size;
    while(column < board_size || backtrack)
    {
        if(backtrack)
        {
            if (column == 0)
                return false;
            column--;
            row = state[column] + 1;
            if(row == board_size)
            {
                backtrack = true;
                continue;
            }
            backtrack = false;
        }
        if(isSafe(row, column, state))
        {
            state[column] = row;
            row = 0;
            column++; //advance
            backtrack = false;
            continue;
        }
        else
        {
            if(row == (board_size - 1))
            {
                backtrack = true;
            }
            else
            {
                row++;
            }
        }
    }
    return true;
  }
};

void print_solutions(Board *board, vector<int>& state, int board_size)
{
   for(int i=0; i < board_size; ++i)
   {
      for(int j=0; j < board_size; ++j)
      {
         if(state[i] == j)
            cout << 'Q' << " ";
         else
            cout << '_' << " ";
      }

      cout << endl;
   }
    cout << endl;
}   

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cout << "Usage: nqueens [Board Size] [Number of Solutions]" << endl;
    return 1;
    }

    int board_size = atoi(argv[1]);
    int solution_count = atoi(argv[2]);
    vector<int> state;
    state.resize(board_size);

    Board *my_board = new Board(board_size);
    int column = 0;
    while (solution_count-- > 0 && my_board->backtrack(state, column, board_size))
        print_solutions(my_board, state, board_size);

    return 0;
}
