#include <iostream>
#include <random>
#include <string>

using namespace std;

bool isGridFull(string*, int);
void PrintGrid(string*);
string CPUmove(string*, string, string, int);
bool CheckWin(string*, string);
bool moveCheck(string*, string, int);

int main()
{
    string playerXO, CPUXO, printNumbers; int startplayer, playermove, cpumove, i;
    string grid[] = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
    PrintGrid(grid);
    for (i=0; i<=8; i++) grid[i] = " "; // for cleaning the array
    cout << "Welcome to the tris game, the initial player will be random\n\n" << "Choose beetween X or O: ";
    while (true) 
    {
        cin >> playerXO;
        if (playerXO == "X" || playerXO == "x" || playerXO == "O" || playerXO == "o") break;
        else cout << "wrong value, please reinsert: ";
    }
    if (playerXO == "x") playerXO = "X";
    else playerXO = "O"; 
    if (playerXO == "X") CPUXO = "O";
    else CPUXO = "X";
    srand (time(NULL)); startplayer = rand() % 2 + 0; // selecting random number (0 or 1) for starting player
    while (true)
    {
        if (startplayer == 0) 
        {
            if (isGridFull(grid, i=0)) 
            {
                cout << "this a draw!\n";
                break;
            }
            cout << "it's your turn, choose a box\n";
            while (true) 
            {
                cin >> playermove;
                playermove--;
                if (grid[playermove] != " ") cout << "this box is already filled, please insert a valid value: ";
                else 
                {
                    grid[playermove] = playerXO; 
                    break;
                }
            }
            PrintGrid(grid);
            if (CheckWin(grid, playerXO)) 
            {
                cout << "Congrats, you have won!\n";
                break;
            } 
            startplayer = 1;
        }
        if (startplayer == 1)
        {
            if (isGridFull(grid, i=0)) 
            {
                cout << "this a draw!\n";
                break;
            }
            cout << "CPU turn\n";
            CPUmove(grid, CPUXO, playerXO, i=0);
            PrintGrid(grid);
            if (CheckWin(grid, CPUXO))
            {
                cout << "the CPU wins!\n";
                break;
            }
            startplayer = 0;
        }
    }
    return 0;
}

void PrintGrid(string grid[8])
{
    cout << "\n"
         << grid[0] << "|" << grid[1] << "|" << grid[2] << endl
         << "-----" << endl
         << grid[3]<< "|" << grid[4] << "|" << grid[5] << endl
         << "-----" << endl 
         << grid[6] << "|" << grid[7] << "|" << grid[8] << endl
         << "\n" ;
}

bool isGridFull(string grid[8], int i)
{
    for (i=0; i<=8; i++)
    {
        if (grid[i] == " ") 
        {
            return false;
            break;
        }
        if (i==8) return true;
    } 
}

bool moveCheck(string grid[8], string XorO, int a, int b, int c)
{
    if (grid[a] == XorO && grid[b] == XorO) 
    {
        if (grid[c] != " ") return false;
        else return true;
    }
    else return false;
}

bool CheckWin(string grid[8], string XorO)
{
    if (grid[0] == XorO && grid[1] == XorO && grid[2] == XorO) return true; // first row
    else if (grid[3] == XorO && grid[4] == XorO && grid[5] == XorO) return true; // second row
    else if (grid[6] == XorO && grid[7] == XorO && grid[8] == XorO) return true; // third row
    else if (grid[0] == XorO && grid[3] == XorO && grid[6] == XorO) return true; // first column
    else if (grid[1] == XorO && grid[4] == XorO && grid[7] == XorO) return true; // second column
    else if (grid[2] == XorO && grid[5] == XorO && grid[8] == XorO) return true; // third column
    else if (grid[0] == XorO && grid[4] == XorO && grid[8] == XorO) return true; // first oblique
    else if (grid[2] == XorO && grid[4] == XorO && grid[6] == XorO) return true; // second oblique
    else return false;
}

string CPUmove(string grid[8], string XorO, string enemyXO, int i)
{
        // TRY TO WIN IF POSSIBLE 
    
    // ROWS
    if (moveCheck(grid, XorO, 0, 1 ,2)) { grid[2] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 1, 2 ,0)) { grid[0] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 0, 2 ,1)) { grid[1] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 3, 4 ,5)) { grid[5] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 4, 5 ,3)) { grid[3] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 3, 5 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 6, 7 ,8)) { grid[8] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 7, 8 ,6)) { grid[6] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 6, 8 ,7)) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (moveCheck(grid, XorO, 0, 3 ,6)) { grid[6] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 1, 4 ,7)) { grid[7] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 2, 5 ,8)) { grid[8] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 0, 6 ,3)) { grid[3] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 1, 7 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 2, 8 ,5)) { grid[5] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 3, 6 ,0)) { grid[0] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 4, 7 ,1)) { grid[1] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 5, 8 ,2)) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (moveCheck(grid, XorO, 0, 4 ,4)) { grid[8] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 2, 4 ,6)) { grid[6] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 0, 8 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 2, 6 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 4, 6 ,2)) { grid[2] = XorO; return XorO; }
    if (moveCheck(grid, XorO, 4, 8 ,0)) { grid[0] = XorO; return XorO; }
    
        // TRY TO NOT LOSE IF POSSIBLE
    // ROWS
    if (moveCheck(grid, enemyXO, 0, 1 ,2)) { grid[2] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 1, 2 ,0)) { grid[0] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 0, 2 ,1)) { grid[1] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 3, 4 ,5)) { grid[5] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 4, 5 ,3)) { grid[3] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 3, 5 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 6, 7 ,8)) { grid[8] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 7, 8 ,6)) { grid[6] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 6, 8 ,7)) { grid[7] = XorO; return XorO; }
    // COLUMNS
    if (moveCheck(grid, enemyXO, 0, 3 ,6)) { grid[6] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 1, 4 ,7)) { grid[7] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 2, 5 ,8)) { grid[8] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 0, 6 ,3)) { grid[3] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 1, 7 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 2, 8 ,5)) { grid[5] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 3, 6 ,0)) { grid[0] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 4, 7 ,1)) { grid[1] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 5, 8 ,2)) { grid[2] = XorO; return XorO; }
    //OBLIQUE
    if (moveCheck(grid, enemyXO, 0, 4 ,4)) { grid[8] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 2, 4 ,6)) { grid[6] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 0, 8 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 2, 6 ,4)) { grid[4] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 4, 6 ,2)) { grid[2] = XorO; return XorO; }
    if (moveCheck(grid, enemyXO, 4, 8 ,0)) { grid[0] = XorO; return XorO; }
    
        // OTHER MOVES
    
    for (i=0; i<=8; i+=2)
    {
        if (grid[i] == " ") 
        {
            grid[i] = XorO;
            return XorO;
        }
        if (i == 8) i=1;
    } 
}