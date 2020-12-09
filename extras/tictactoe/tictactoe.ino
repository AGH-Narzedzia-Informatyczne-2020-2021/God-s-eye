/**
 * @file tictactoe.ino
 * @author Piotr Sokołowski (psokolowski@student.agh.edu.pl)
 * @brief Classic tic-tac-toe game
 * @version 0.1
 * @date 2020-11-27
 * 
 * @copyright Copyright (c) 2020
 * 
 */

int board[3][3] = {
    {0, 0, 0},
    {0, 0, 0},
    {0, 0, 0}};

void setup()
{
    Serial.begin(115200);
}

int readDataFromUser()
{
    while (true)
    {
        if (Serial.available() > 0)
        {
            char input = Serial.read();
            if (input >= '1' && input <= '9')
                return input - '0';
        }
    }
}

void printBoard(int board[3][3])
{
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            char symbol;
            if (board[i][j] == -1)
                symbol = 'x';
            else if (board[i][j] == 0)
                symbol = ' ';
            else if (board[i][j] == 1)
                symbol = 'o';
            Serial.print(" ");
            Serial.print(symbol);
            Serial.print(" ");
            if (j != 2)
                Serial.print("|");
        }
        Serial.println();
        if (i != 2)
            Serial.println("---+---+---");
    }
}

void loop()
{
    Serial.println(readDataFromUser());
    printBoard(board);
    /*
    int x, y;
    printBoard(board);
    int field = readDataFromUser();
    if (isFieldEmpty(board, field))
        makeMove(board, field, -1);
    printBoard(board);
    if (estimateBoard(board) == AI_LOSE)
    {
        Serial.println("Wygrales! Aby zagrac jeszcze raz, wcisnij przycisk RESET");
        ESP.deepSleep(0);
    }
    generateMoveTree(board, &x, &y);
    board[x][y] = 1;
    printBoard(board);
    if (estimateBoard(board) == AI_WIN)
    {
        Serial.println("Przegrales! Aby zagrac jeszcze raz, wcisnij przycisk RESET");
        ESP.deepSleep(0);
    }
    */
}