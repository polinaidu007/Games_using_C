# Games_using_C
## 15_Puzzle

![1200px-15-puzzle_magical svg](https://user-images.githubusercontent.com/28729727/92978328-1e1da400-f4ad-11ea-9758-fa1c64a627a8.png)

### Objective of the Game .

Given a Random Board of 15 Pieces .You need to move the pieces in such a way that all pieces will be in asceding order or correct order .
You can refer the below link for the Game details .The Correct order is the one shown in the picture .
Link : https://en.wikipedia.org/wiki/15_puzzle

How we are going to Design the Game .?

We are using a Board structure to store the Table information , which also stores rows,cols,Empty Tile Row and Empty Tile Column .
All The Board Related functions are in BoardUtils.h
We are representing the emptyTile using 0 in the 2d Array .
We are using a User struct to store Who is playing the game and the number of moves he made .We are going to revisit this game again ,So make sure you are
implementing every feature .
User related functions are present in UserUtils.h

How Game is played :
It is played by moving some other Tile into the empty Space .
Ex if the first row has 1,0,2,4 [0 specifying empty Tile ] ,By pressing D and Enter , The First row will be modified as 0,1,2,4 .

W is used to move any Tile to the Up , S is used to move any Tile down , A for left and D for right .

Ex Move 'A' or 'a' :

1 2 3      1 2 3
4   5  ==> 4 5
6 7 8      6 7 8

Ex Move 'D' or 'd' :

1 2 3      1 2 3
4   5  ==>   4 5
6 7 8      6 7 8

Ex Move 'W' or 'w' :

1 2 3      1 2 3
4   5  ==> 4 7 5
6 7 8      6   8

Ex Move 'S' or 's' :

1 2 3      1   3
4   5  ==> 4 2 5
6 7 8      6 7 8

If by making moves you reach the final Correct position ,The game is completed .

Moves Related Functions are There in MovesUtils.h

## Reversi Game
![download](https://user-images.githubusercontent.com/28729727/92978499-908e8400-f4ad-11ea-92b9-4fc5dce55fcc.jpg)

### Objective of the Game .

Given a NxN Square Board of containing Whites and Blacks , the game is played between two players.
where each player owns one color (onePlayer chooses white and anotherPlayer chooses black).

Players take alternate turns and place their color on the one square such that it captures the other colors
as described in the figures given below.

The game ends when either the board is completely filled or both the players can't make a move.
Link : https://en.wikipedia.org/wiki/Reversi

We are using a ReversiGame structure to store all the Game related information , which also stores rows,cols,board,whiteCoinCount,blackCoinCount,MoveCount,Turn.
All The Board Related functions are in ReversiBoardUtils.h
We are representing the emptySquare using ' ' (space) in the 2d Array white coins with 'w' and blacks with 'b'.
We are using a ReversiMove struct to store Move(x,y) We are going to revisit this game again ,So make sure you are
implementing every feature .
Move(x,y) is 1 indexed. ie top left square is called as (1,1) instead of(0,0)

All MoveRelated Functions are present in ReverseMovesUtil.h

How Game is played :
Ex Lets take a 4x4 board ('w' representing whites, 'b' representing blacks, '.' representing empty )

  1 2 3 4												    1 2 3 4
1 . . . .												  1 . . . .
2 . w b .   ==> White places coin at (4,2) Turn ==>       2 . w b .   (see that it captures all the blacks between two
3 . b w .												  3 . w w .   white coins when a move is placed)
4 . . . .												  4 . w . .


  1 2 3 4				                                 1 2 3 4
1 . . . .											   1 . . . .
2 . w b .   ==> Black places coin at (4,3) Turn ==>    2 . w b .   (see that it captures all the white between two
3 . w w .											   3 . w b .   black coins when a move is placed)
4 . w . .										       4 . w b .

Note : only moves that captures the opponent coins are valid , example white cannot place the coin at (1,1) or (1,2) etc..

The rules of the game can be found at :
Link : http://www.ultraboardgames.com/othello/game-rules.php
