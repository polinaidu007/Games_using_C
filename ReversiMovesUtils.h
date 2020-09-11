/*
This struct denotes the move played by user, X means the x cordinate and Y means y cordinate.
*/
typedef struct ReversiMove {
	int x, y;
}ReversiMove;

/*
Create a ReversiMove struct (malloc/calloc etc) and return it.
Assign parameters x and y to its fields.
*/


ReversiMove *createMove(int x, int y) {
	if (x < 1 || y < 1)
		return NULL;
	ReversiMove *temp = (ReversiMove *)malloc(sizeof(ReversiMove));
	temp->x = x;
	temp->y = y;
	return temp;
}
/*
To check the validity of coordinate on the board
*/

int isvalidCoordinate(ReversiGame *game, int x, int y) {
	if (x >= 1 && x <= game->rows && y >= 1 && y <= game->cols)
		return 1;
	return 0;
}
/*
	Take Only Valid Input x, y two integers . If Invalid input is entered ,Take input again . Keep Taking input until its valid
	Hint : Use While Loop and isValidInput function
	Cordinates are 1 indexed. Ie first row/column is denoted by 1 while giving input.
*/

ReversiMove *inputMove(ReversiGame *game) {
	int x, y;
	do{
		scanf("%d%d", &x, &y);
	} while (!isvalidCoordinate(game, x, y));
	ReversiMove *temp=createMove(x, y);
	return temp;
}




/*
Check if the move can be placed, if its going to make a valid capture to the opponent coins
*/
void fillRight(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (j < yPos){
		if (game->board[i][j] == edge){
			j++;
			continue;
		}
		game->board[i][j++] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (j-move->y>1)
				game->blackCount--;
			//printf("%d %d", game->whiteCount, game->blackCount);
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (j - move->y>1)
				game->whiteCount--;
		}
	}
	//printf("here %d %d", game->whiteCount, game->blackCount);
	//printf("\n");

}
void fillLeft(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (j > yPos){
		if (game->board[i][j] == edge){
			j--;
			continue;
		}
		game->board[i][j--] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (move->y - j > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (move->y - j > 1)
			game->whiteCount--;
		}
	}
}
void fillDown(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (i < xPos){
		if (game->board[i][j] == edge)
		{
			i++;
			continue;
		}
		game->board[i++][j] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (i - move->x > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (i- move->x > 1)
			game->whiteCount--;
		}
	}
}
void fillTop(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (i > xPos){
		if (game->board[i][j] == edge)
		{
			i--;
			continue;
		}
		game->board[i--][j] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (move->x - i > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (move->x - i > 1)
			game->whiteCount--;
		}
	}
}

void fillTopRight(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (i > xPos ){
		if (game->board[i][j] == edge)
		{
			i--;
			j++;
			continue;
		}
		game->board[i--][j++] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (j-move->y > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (j - move->y > 1)
			game->whiteCount--;
		}
	}
}

void fillTopLeft(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (i > xPos){
		if (game->board[i][j] == edge){
			i--;
			j--;
			continue;
		}
		game->board[i--][j--] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (move->y - j > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (move->y - j > 1)
			game->whiteCount--;
		}
	}
}

void fillBottomRight(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (i < xPos){
		if (game->board[i][j] == edge){
			i++;
			j++;
			continue;
		}
		game->board[i++][j++] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (i - move->x > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (i - move->x > 1)
			game->whiteCount--;
		}
	}
}

void fillBottomLeft(ReversiMove *move, ReversiGame *game, int xPos, int yPos)
{
	int mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	int i = move->x;
	int j = move->y;
	while (i < xPos){
		if (game->board[i][j] == edge){
			i++;
			j--;
			continue;
		}
		game->board[i++][j--] = edge;
		if (edge == 'w')
		{
			game->whiteCount++;
			if (i - move->x > 1)
			game->blackCount--;
		}
		else if (edge == 'b')
		{
			game->blackCount++;
			if (i - move->x > 1)
			game->whiteCount--;
		}
	}
}


int fillUp(ReversiGame *game, ReversiMove *move) {
	int i, j;
	char mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}
	i = move->x;
	j = move->y + 1;
	while (j <= game->cols && game->board[i][j] == mid)
		j++;
	if (j<=game->cols && j>move->y+1 && game->board[i][j] == edge)
		fillRight(move, game, i, j);


	i = move->x;
	j = move->y - 1;
	while (j >= 1 && game->board[i][j] == mid )
		j--;
	if (j>=1 && j<move->y-1 && game->board[i][j] == edge )
		fillLeft(move, game, i, j);



	i = move->x + 1;
	j = move->y;
	while ( i <= game->rows && game->board[i][j] == mid)
		i++;
	if (i <= game->rows && i>move->x+1 && game->board[i][j] == edge)
		fillDown(move, game, i, j);

	i = move->x - 1;
	j = move->y;
	while ( i >= 1 && game->board[i][j] == mid)
		i--;
	if (i >= 1 && i<move->x-1 && game->board[i][j] == edge)
		fillTop(move, game, i, j);


	i = move->x - 1;
	j = move->y + 1;
	while (i >= 1 && j <= game->cols && game->board[i][j] == mid)
		i--, j++;
	if (i >= 1 && j <= game->cols && j>move->y+1 && game->board[i][j] == edge)
		fillTopRight(move, game, i, j);



	i = move->x - 1;
	j = move->y - 1;
	while (i >= 1 && j >= 1 && game->board[i][j] == mid)
		i--, j--;
	if (i >= 1 && j >= 1 && i<move->x-1 && game->board[i][j] == edge)
		fillTopLeft(move, game, i, j);

	i = move->x + 1;
	j = move->y + 1;
	while (i <= game->rows && j <= game->cols && game->board[i][j] == mid )
		i++, j++;
	if (i <= game->rows && j <= game->cols && i>move->x+1 && game->board[i][j] == edge)
		fillBottomRight(move, game, i, j);

	i = move->x + 1;
	j = move->y - 1;
	while ( i <= game->rows && j >= 1 && game->board[i][j] == mid)
		i++, j--;
	if (i <= game->rows && j >= 1 && i>move->x+1 && game->board[i][j] == edge)
		fillBottomLeft(move, game, i, j);
	
	return 0;
	
}
int isValidMove(ReversiGame *game, ReversiMove *move) {
	if (!move)
		return 0;
	int i, j;
	char mid, edge;
	if (game->turn == 1)
	{
		mid = 'b';
		edge = 'w';
	}
	else if (game->turn == -1)
	{
		mid = 'w';
		edge = 'b';
	}

	i = move->x;
	j = move->y +1;
	while (j <= game->cols && game->board[i][j] == mid)
		j++;
	if (j <= game->cols && j>move->y + 1 && game->board[i][j] == edge)
	{
		return 1;
	}


	i = move->x;
	j = move->y - 1;
	while ( j >= 1 && game->board[i][j] == mid)
		j--;
	if (j >= 1 && j < move->y - 1 && game->board[i][j] == edge){
		//printf("here\n");
		return 1;
	}

	i = move->x +1;
	j = move->y;
	while (i <= game->rows && game->board[i][j] == mid )
		i++;
	if (i<=game->rows && game->board[i][j] == edge && i>move->x+1)
		return 1;

	i = move->x-1;
	j = move->y;
	while (i >= 1 && game->board[i][j] == mid)
		i--;
	if (i >= 1 && game->board[i][j] == edge && i<move->x-1 && i<move->x-1)
		return 1;


	i = move->x - 1;
	j = move->y + 1;
	while (i >= 1 && j <= game->cols && game->board[i][j] == mid)
		i--, j++;
	if (i >= 1 && j <= game->cols && i<move->x-1 && j>move->y+1 && game->board[i][j] == edge)
		return 1;

	i = move->x - 1;
	j = move->y - 1;
	while (i >= 1 && j >= 1 && game->board[i][j] == mid )
		i--, j--;
	if (i >= 1 && j >= 1 && i<move->x - 1 && j<move->y - 1 && game->board[i][j] == edge)
		return 1;

	i = move->x + 1;
	j = move->y + 1;
	while (i <= game->rows && j <= game->cols && game->board[i][j] == mid )
		i++, j++;
	if (i <= game->rows && j <= game->cols &&  i>move->x + 1 && j>move->y + 1 && game->board[i][j] == edge)
		return 1;

	i = move->x + 1;
	j = move->y - 1;
	while (i <= game->rows && j >= 1 && game->board[i][j] == mid)
		i++, j--;
	if (i <= game->rows && j >= 1 && i>move->x + 1 && j<move->y - 1 && game->board[i][j] == edge)
		return 1;

	return 0;
}

/*
Check if the player can move , if the player is not able to move, he looses the turn
and the opponent gets the chance to play.
If both players are not able to make a move, then the game ends.
*/

int hasMove(ReversiGame *game){
	int i, j;
	ReversiMove *m = createMove(1,1);
	for (i = 1; i <= game->rows; i++){
		for (j = 1; j <= game->cols; j++){
			if (game->board[i][j] != 'w' && game->board[i][j] != 'b')
			{
				m->x = i;
				m->y = j;
				if (isValidMove(game, m))
					return 1;
			}
		}
	}
/*	modifyTurn(game);
	for (i = 1; i <= game->rows; i++){
		for (j = 1; j <= game->cols; j++){
			if (game->board[i][j] != 'w' && game->board[i][j] != 'b')
			{
				m->x = i;
				m->y = j;
				if (isValidMove(game, m))
					return 1;
			}
		}
	}*/
	return 0;
}

/*
Increment the number of moves in ReversiGame struct.
*/
void incrementMoves(ReversiGame *game) {
	game->NumberofMoves++;
	return;
}

/*
Toggle the turn in Reversi Game.
This function is to be called when you want to change the turn.
*/
void modifyTurn(ReversiGame *game) {
	game->turn = game->turn == 1 ? -1 : 1;
	return;
}

/*
End Reversi Game.
Populate game->winner field accordingly with who won. 1 for white, -1 for black.
This function is to be called when the game is ended.
*/
void endGame(ReversiGame *game) {
	if (game->blackCount > game->whiteCount)
		game->winner = -1;
	else if (game->whiteCount > game->blackCount)
		game->winner = 1;
	else
		game->winner = 0;
	game->state = 1;
	return;
}

/*
	Wrapper function you will call only modify to increment moves and modify the turn.
*/

void modify(ReversiGame *game) {
	incrementMoves(game);
	modifyTurn(game);
}


/*
	This function performs move action on the board
	Note : call validity check performs using above functions before making a move
	returns :
	true on move sucess
	false if move is invalid
*/

bool playMove(ReversiGame *game, ReversiMove *move) {
	if (hasMove(game)){
		 if(isValidMove(game, move))
		{
			fillUp(game, move);
			modify(game);
			if (!hasMove(game))
				modifyTurn(game);
			if (!hasMove(game))
				endGame(game);
			return true;
			
		}
	}
	return false;
}


void printWinner(ReversiGame *game) {
	if (game->winner == 1)
		printf("%s has won.\n", game->player1name);
	else if (game->winner == -1)
		printf("%s has won.\n", game->player2name);
	else
		printf("Game is Drawn.");
	/*
	Sample output :
	Result Praveen has won. / Game is Drawn.
	*/
}