//
//  History.cpp
//  

#include "History.h"
#include "globals.h"
#include <iostream>
using namespace std;

History::History(int nRows, int nCols)
{
    m_nRows = nRows;
    m_nCols = nCols;
    for (int r = 0; r < MAXROWS; r++) {
        for (int c = 0; c < MAXCOLS; c++) {
            m_grid[r][c] = 0;
        }
    }
}

bool History::record(int r, int c) {
    if (r < 1 || r > m_nRows || c < 1 || c > m_nCols) {
        return false;
    }
    m_grid[r-1][c-1]++;
    return true;
}

void History::display() const {
    clearScreen();
    for (int r = 0; r < m_nRows; r++) {
        for (int c = 0; c < m_nCols; c++) {
            int location = m_grid[r][c];
            switch (location) {
                case 0:
                    cout << '.';
                    break;
                case 1:
                    cout << 'A';
                    break;
                case 2:
                    cout << 'B';
                    break;
                case 3:
                    cout << 'C';
                    break;
                case 4:
                    cout << 'D';
                    break;
                case 5:
                    cout << 'E';
                    break;
                case 6:
                    cout << 'F';
                    break;
                case 7:
                    cout << 'G';
                    break;
                case 8:
                    cout << 'H';
                    break;
                case 9:
                    cout << 'I';
                    break;
                case 10:
                    cout << 'J';
                    break;
                case 11:
                    cout << 'K';
                    break;
                case 12:
                    cout << 'L';
                    break;
                case 13:
                    cout << 'M';
                    break;
                case 14:
                    cout << 'N';
                    break;
                case 15:
                    cout << 'O';
                    break;
                case 16:
                    cout << 'P';
                    break;
                case 17:
                    cout << 'Q';
                    break;
                case 18:
                    cout << 'R';
                    break;
                case 19:
                    cout << 'S';
                    break;
                case 20:
                    cout << 'T';
                    break;
                case 21:
                    cout << 'U';
                    break;
                case 22:
                    cout << 'V';
                    break;
                case 23:
                    cout << 'W';
                    break;
                case 24:
                    cout << 'X';
                    break;
                case 25:
                    cout << 'Y';
                    break;
                default:
                    cout << 'Z';
                    break;
            }
        }
        cout << endl;
    }
    cout << endl;
}
