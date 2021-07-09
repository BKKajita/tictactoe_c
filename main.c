// Program 5.8 Tic-Tac-Toe
#include <stdio.h>
#define SIZE 3

int main(void)
{
    unsigned int winner = 0;                     // The winner player number
    int choice = 0;                     // Chosen square
    unsigned int row;               // row square index
    unsigned int column;            // column square index
    char board[SIZE][SIZE] = {
            {'1','2','3'},
            {'4','5','6'},
            {'7','8','9'}
    };

    // The main game loop. The game continues for up to 9 turns
    // As long as there no winner
    for (unsigned int i = 0; i < 9 && winner == 0; ++i) {
        // Display the board
        printf("\n");
        printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]);
        printf("---+---+---\n");
        printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]);

        unsigned int player = i % 2 + 1;         // Select player

        // get valid player square selection

        do
        {
            printf("Player %d, please enter a valid square number "
                   "for where you want to place your %c: ",
                   player, (player == 1) ? 'X' : 'O');
            scanf("%d", &choice);

            row = --choice / SIZE;     // Get row index of square
            column = choice % SIZE;    // Get column index of square
        }
         while(choice < 0 || choice > 8 || board[row][column] > '9');

         //insert player symbol
         board[row][column] = (player == 1) ? 'X' : 'O';

         // Check for a winning line - diagonals first
         if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) ||
            (board[0][2] == board[1][1] && board[0][2] == board[2][0]))
         {
             winner = player;
         }
         else
         {
             // check rows and columns for a winning line
             for (unsigned int line = 0; line <=2; ++line) {
                 if((board[line][0] == board[line][1] && board[line][0] == board[line][2]) ||
                    (board[0][line] == board[1][line] && board[0][line] == board[2][line]))
                     winner = player;
             }
         }
    }
    // Game is over so display the final board
    printf("\n");
    printf(" %c | %c | %c \n", board[0][0], board[0][1], board[0][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[1][0], board[1][1], board[1][2]);
    printf("---+---+---\n");
    printf(" %c | %c | %c \n", board[2][0], board[2][1], board[2][2]);
    printf("---+---+---\n");

    // Display result message
    if (winner)
    {
        printf("\nCongratulations, player %d, YOU ARE THE WINNER!\n", winner);
    }
    else {
        printf("\nHow boring, it is a draw\n");
    }

    return 0;
}
