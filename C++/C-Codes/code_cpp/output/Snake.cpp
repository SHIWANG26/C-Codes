#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono> // Include chrono for std::this_thread::sleep_for
#include <thread> // Include thread for std::this_thread::sleep_for

#ifdef _WIN32
#include <conio.h> // Include conio.h for _kbhit() and _getch() on Windows
#else
#include <unistd.h> // Include unistd.h for read() and STDIN_FILENO on Unix-like systems
#endif

using namespace std;

const int width = 80;
const int height = 20;

int x, y;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
enum snakesDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
snakesDirection sDir;
bool isGameOver;

void GameInit()
{
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

void GameRender(string playerName)
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (j == 0 || j == width)
                cout << "|";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#";
            else
            {
                bool printTail = false;
                for (int k = 0; k < snakeTailLen; k++)
                {
                    if (snakeTailX[k] == j && snakeTailY[k] == i)
                    {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    cout << playerName << "'s Score: " << playerScore << endl;
}

void UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    for (int i = 1; i < snakeTailLen; i++)
    {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;

    for (int i = 0; i < snakeTailLen; i++)
    {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    if (x == fruitCordX && y == fruitCordY)
    {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

int SetDifficulty()
{
    int difficulty, choice;
    cout << "Set Difficulty\n1: Easy\n2: Medium\n3: Hard\nChoose difficulty level: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        difficulty = 50;
        break;
    case 2:
        difficulty = 100;
        break;
    case 3:
        difficulty = 150;
        break;
    default:
        difficulty = 100;
        break;
    }

    return difficulty;
}

void UserInput()
{
#ifdef _WIN32
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            sDir = LEFT;
            break;
        case 'd':
            sDir = RIGHT;
            break;
        case 'w':
            sDir = UP;
            break;
        case 's':
            sDir = DOWN;
            break;
        case 'x':
            isGameOver = true;
            break;
        }
    }
#else
    // Implement input handling for non-Windows platforms here
#endif
}

int main()
{
    string playerName;
    cout << "Enter your name:\n->";
    cin >> playerName;

    int difficulty = SetDifficulty();
    GameInit();

    while (!isGameOver)
    {
        GameRender(playerName);
        UserInput();
        UpdateGame();
        // Sleep for specified difficulty time
        std::this_thread::sleep_for(std::chrono::milliseconds(difficulty));
    }

    return 0;
}
// #include <conio.h>
// #include <iostream>

// using namespace std;
// // height and width of the boundary
// const int width = 80;
// const int height = 20;
// // Snake head coordinates of snake(x and y axis)
// int x, y;
// // Food coordinates
// int fruitCordX, fruitCordY;
// // Variable to store the score of the player
// int playerScore;
// // Array to store coordinates of the tail
// int snakeTailX[100], snakeTailY[100];
// // Variable to store the length of snake
// int snakeTailLen;
// // for storing direction of snake
// enum snakesDirection
// {
//     STOP = 0,
//     LEFT,
//     RIGHT,
//     UP,
//     DOWN
// };
// // snakesDirection variable
// snakesDirection variable;
// // boolean variable for checking game is over or not
// bool isGameOver;

// void GameInit()
// {
//     isGameOver = false;
//     sDir = STOP;
//     x = width / 2;
//     y = height / 2;
//     fruitCordX = rand() % width;
//     fruitCordY = rand() % height;
//     playerScore = 0;
// }
// // Funct to create the game board and rendering
// void GameRender(string playerName)
// {
//     system("cls"); // clear the console
//     // Creating top walls with '-'
//     for (int i 0; i < width + 2; i++)
//         cout << "-";
//     cout << endl;
//     for (int i = 0; i < height + 2; i++)
//     {
//         for (int j = 0; j <= width; j++)
//         {
//             // Creating side walls with side as '|'
//             if (j == 0 || j == width)
//                 cout << "|";
//             // Creating snakes head with 'O'
//             if (i == y && j == x)
//                 cout << "O";
//             // Creating snakes food with '#'
//             else if (i == fruitCordY && j == fruitCordX)
//                 cout << "#";
//             else
//             { // Creating snake head with 'o'
//                 bool prTail = false;
//                 for (int k = 0; k < snakeTailLen; k++)
//                 {
//                     if (snakeTailX[k] == j && snakeTailY[k] == i)
//                     {
//                         cout << "o";
//                         prTail = true;
//                     }
//                 }
//                 if (!prTail)
//                 {
//                     cout << " ";
//                 }
//             }
//             cout << endl;
//             // Creating bottom walls with '|'
//             for (int i = 0; i < width + 2; i++)
//             {
//                 cout << "-";
//                 cout << endl;
//                 // Display player score
//                 cout << playerName << "s Score: " << playerScore << endl;
//             }
//         }
//     }
// }
// //Funct for updating the game stat
// void UpdateGame()
// {
//     int prevX = snakeTailX[0];
//     int prevY = snakeTailY[0];
//     int prev2X, prev2Y;
//     snakeTailX[0] = x;
//     snakeTailY[0] = y;
//     for (int i = 1; i < snakeTailLen; i++)
//     {
//         prev2X = snakeTailX[i];
//         prev2Y = snakeTailY[i];
//         snakeTailX[i] = prevX;
//         snakeTailY[i] = prevY;
//         prevX = prev2X;
//         prevY = prev2Y;
//     }
//     switch (sDir)
//     {
//     case LEFT:
//         x--;
//         break;
//     case RIGHT:
//         x++;
//         break;
//     case UP;
//         y--;
//         break;
//     case DOWN:
//         y++;
//         break;
//     }
//     //checks for collision with wall
//     wall(|)
//         if(x>=width || x< 0|| y >= height || y< 0)
//             isGameOver = true;
//         //checks for collion with tail
//         for (int i = 0; i < snakeTailLen; i++)
//         {
//             if(snakeTailX[i] == x && snakeTailY[i] == y)
//                 isGameOver = true;
//         }
//         //checks for collision with food(#)
//         if (x == fruitCordX && y == fruitCordY)
//         {
//             playerScore += 10;
//             fruitCordX = rand() % width;
//             fruitCordY = rand() % height;
//             snakeTailLen++;
//         }
// }
// //Funct to set difficulty of game
// int setDifficulty()
// {
//     int dfc, choice;
//     cout<<"\nSet Difficulty\n:1:Easy\n2:Medium\n3:Hard\nNote:If not chosen or pressed any other key, the difficilty will be atumatically set to medium\nChoose difficulty level: ";
//     cin>>choice;
//     switch (choice)
//     {
//     case '1':
//         dfc = 50;
//         break;
//     case '2':
//         dfc = 100;
//         break;
//     case '3':
//         dfc = 150;
//         break;
//     default:
//         dfc = 100;
//         break;
//     }
//     return dfc;
// }
// //FUNCT to handle userInput
// void UserInput()
// {
//     //checks if a key is pressed or not
//     if(_kbhit()){
//         //Getting the pressed key
//         switch (_getch()){
//             case 'a':
//                 sDir = LEFT;
//                 break;
//             case 'd':
//                 sDir = RIGHT;
//                 break;
//             case 'w':
//                 sDir = UP;
//                 break;
//             case 's':
//                 sDir = DOWN;
//                 break;
//             case 'x':
//                 isGameOver = true;
//                 break;
//         }
//     }
// }
// //Main Funct game looping function
// int main()
// {
//     string playerName;
//     cout<<"Enter your name:\n->";
//     cin>>playerName;
//     int dfc =setDifficulty();
//     GameInit();
//     while (!isGameOver)
//     {
//         GameRender(playerName);
//         UserInput();
//         //Creating a delay for ACCORDING TO the game difficulty
//         Sleep(dfc);
//     }
//     return 0;
// }
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono> // Include chrono for std::this_thread::sleep_for
#include <thread> // Include thread for std::this_thread::sleep_for

#ifdef _WIN32
#include <conio.h> // Include conio.h for _kbhit() and _getch()
#else
#include <unistd.h> // Include unistd.h for STDIN_FILENO
#include <sys/select.h> // Include sys/select.h for select()
#endif#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono> // Include chrono for std::this_thread::sleep_for
#include <thread> // Include thread for std::this_thread::sleep_for

#ifdef _WIN32
#include <conio.h> // Include conio.h for _kbhit()
#else
#include <unistd.h> // Include unistd.h for read() and STDIN_FILENO
#include <termios.h> // Include termios.h for termios struct and tcgetattr() / tcsetattr()
#endif#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <chrono> // Include chrono for std::this_thread::sleep_for
#include <thread>#include <windows.h> 

using namespace std;

const int width = 80;
const int height = 20;

int x, y;
int fruitCordX, fruitCordY;
int playerScore;
int snakeTailX[100], snakeTailY[100];
int snakeTailLen;
enum snakesDirection
{
    STOP = 0,
    LEFT,
    RIGHT,
    UP,
    DOWN
};
snakesDirection sDir;
bool isGameOver;

void GameInit()
{
    isGameOver = false;
    sDir = STOP;
    x = width / 2;
    y = height / 2;
    fruitCordX = rand() % width;
    fruitCordY = rand() % height;
    playerScore = 0;
}

void GameRender(string playerName)
{
    system("cls");
    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j <= width; j++)
        {
            if (j == 0 || j == width)
                cout << "|";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitCordY && j == fruitCordX)
                cout << "#";
            else
            {
                bool printTail = false;
                for (int k = 0; k < snakeTailLen; k++)
                {
                    if (snakeTailX[k] == j && snakeTailY[k] == i)
                    {
                        cout << "o";
                        printTail = true;
                    }
                }
                if (!printTail)
                    cout << " ";
            }
        }
        cout << endl;
    }

    for (int i = 0; i < width + 2; i++)
        cout << "-";
    cout << endl;

    cout << playerName << "'s Score: " << playerScore << endl;
}

void UpdateGame()
{
    int prevX = snakeTailX[0];
    int prevY = snakeTailY[0];
    int prev2X, prev2Y;
    snakeTailX[0] = x;
    snakeTailY[0] = y;
    for (int i = 1; i < snakeTailLen; i++)
    {
        prev2X = snakeTailX[i];
        prev2Y = snakeTailY[i];
        snakeTailX[i] = prevX;
        snakeTailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (sDir)
    {
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    }

    if (x >= width || x < 0 || y >= height || y < 0)
        isGameOver = true;

    for (int i = 0; i < snakeTailLen; i++)
    {
        if (snakeTailX[i] == x && snakeTailY[i] == y)
            isGameOver = true;
    }

    if (x == fruitCordX && y == fruitCordY)
    {
        playerScore += 10;
        fruitCordX = rand() % width;
        fruitCordY = rand() % height;
        snakeTailLen++;
    }
}

int SetDifficulty()
{
    int difficulty, choice;
    cout << "Set Difficulty\n1: Easy\n2: Medium\n3: Hard\nChoose difficulty level: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        difficulty = 50;
        break;
    case 2:
        difficulty = 100;
        break;
    case 3:
        difficulty = 150;
        break;
    default:
        difficulty = 100;
        break;
    }

    return difficulty;
}

void UserInput()
{
    if (_kbhit())
    {
        switch (_getch())
        {
        case 'a':
            sDir = LEFT;
            break;
        case 'd':
            sDir = RIGHT;
            break;
        case 'w':
            sDir = UP;
            break;
        case 's':
            sDir = DOWN;
            break;
        case 'x':
            isGameOver = true;
            break;
        }
    }
}

int main()
{
    string playerName;
    cout << "Enter your name:\n->";
    cin >> playerName;

    int difficulty = SetDifficulty();
    GameInit();

    while (!isGameOver)
    {
        GameRender(playerName);
        UserInput();
        UpdateGame();
        Sleep(difficulty);
    }

    return 0;
}
