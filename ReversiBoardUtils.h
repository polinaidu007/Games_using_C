#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct ReversiGame {
	char **board;	// char 'w' for whites, 'b' for blacks ' ' for empty 
	// do allocate memory for '\0' as it is character array.
	char *player1name;
	char *player2name;
	int whiteCount = 0;
	int blackCount = 0;
	int NumberofMoves = 0;
	int rows, cols;
	int turn = 1;   //1 for white, -1 for black
	int state = 0;  //0 for unfinished, 1 for game over
	int winner = 0; //1 for white, -1 for black
}ReversiGame;


void endGame(ReversiGame *game);
int hasMove(ReversiGame *game);
void modifyTurn(ReversiGame *game);

/*

Create a new ReversiGame By allocating memory from Heap , Let it be game;
Create a 2D Array from Heap(Dynamically) with specified number of rows and cols
and copy its reference to game->board;

Note : Return NULL for Invalid Inputs
Note : Copy Rows into newlyCreatedBoard->rows , and vice versa for cols ,
Also copy player1name,player2name.
*/

ReversiGame * createNewGame(int rows, int cols, char *player1, char *player2) {
	if (rows < 1 || cols < 1 || !player1 || !player2 || rows!=cols)
		return NULL;
	ReversiGame *game =(ReversiGame *)malloc(sizeof(ReversiGame));
	char **array = (char **)malloc((rows+1)*sizeof(char *));
	int i;
	for (i = 0; i <= rows; i++)
		array[i]=(char *)malloc((cols + 1)*sizeof(char));
	game->board = array;
	game->player1name = player1;
	game->player2name = player2;
	game->rows = rows;
	game->cols = cols;
	game->blackCount = 0;
	game->whiteCount = 0;
	game->NumberofMoves = 0;
	game->turn = 1;
	game->winner = 0;
	game->state = 0;
	return game;
}


/*
Copy the tobeCopied Array into game->board .
Learn how to Copy a 2D array when address of first row is given.
Note this function is called in the following way

Also Initialize the turn variable, whiteCount with no of white coins and same for black.

Do Nothing for Invalid Inputs
*/

void initializeReversiGame(ReversiGame *game, char *tobeCopiedBoard, int rows, int cols, int turn) {
	game->blackCount = 0;
	game->whiteCount = 0;
	int i, j;
	int k = 0;
	for (i = 1; i <= game->rows; i++){
		for (j = 1; j <= game->cols; j++)
		{
			if (tobeCopiedBoard[k] != '\0'){
				game->board[i][j] = tobeCopiedBoard[k++];
				if (game->board[i][j] == 'w')
					game->whiteCount++;
				else if (game->board[i][j] == 'b')
					game->blackCount++;
			}
			else
			{
				k++;
				j--;
			}
		}
	}
	game->turn = turn;
	if (game->whiteCount > 1 && !game->blackCount || (game->blackCount > 1 && !game->whiteCount) || game->blackCount + game->whiteCount==(game->rows * game->cols))
		endGame(game);
	
	if (!hasMove(game))
		modifyTurn(game);

	return;
}

/*
Check if the Current board is in End Position . Return 0 if the game is Ended, 1 if not .
Win Condition : Either all the squares are filled or a stalemate position (No one can Move)

*/

int checkReversiGameOver(ReversiGame *game){
	int i, j;
	if (hasMove(game))
		return 1;
	modifyTurn(game);
	if (hasMove(game))
		return 1;
	endGame(game);
	return 0;
}

void printMoves(ReversiGame *game){
	printf("Whites Count : %d\nBlack Count : %d\nMove Count : %d\n", game->whiteCount, game->blackCount, game->NumberofMoves);
	/*
	Sample output :
	Whites Count : 5
	Black Count : 4
	Move Count : 9
	*/
	return;
}

/*
Print the Board in a Good Way.Make sure Each Number is properly formatted and Seperated, and Row lines too .
Print Empty Space when you encounter 0.Also make sure your board looks good for 5x5 or 7x7 boards too .
Use your Thinking / UI Skills .
See the link we shared for sample screenshots for inspiration.
*/

void drawBoardOnScreen(ReversiGame *game) {
	int i, j;
	for (i = 1; i <= game->rows; i++){
		for (j = 1; j <= game->cols; j++)
			printf("%c", game->board[i][j]);
		printf("\n");
	}
	return;
}

/*
Clear The Screen , So that we can redraw the Board (which has modified values )
*/

void clearScreen(ReversiGame *game){
	system("cls");
}

/*
Clear the Screen and ReDraw the Board ,Call above two functions
*/

void clearAndRedrawScreen(ReversiGame *game){
	clearScreen(game);
	drawBoardOnScreen(game);
}



