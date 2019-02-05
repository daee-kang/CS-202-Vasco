#include "battleship.h"
#include <cstdlib>
#include <cmath>
using namespace std;

/*---------------------------------------
Constructor
PARAMETER(S):ifstream from main
POSTCONDITION(S):Constructs the playerGrid to emptyspaces
sets the solutionGrid to what the input file states
sets maxmoves and movesmade to 20 and 0 respectively.
essentially sets the game up.
---------------------------------------*/
battleship::battleship(ifstream& in)
{
	char temp;
	for(int i = 0; i < ROWS; i++)
   		for(int j = 0; j < COLUMNS; j++){
    		in >> temp;
    		if(temp == '1')
    			solutionGrid[i][j] = 1;
      		if(temp == '0')
        		solutionGrid[i][j] = 0;
    }
	for(int i = 0; i < ROWS; i++)
		for(int j = 0; j < COLUMNS; j++)
			playerGrid[i][j] = ' ';
	maxMoves = 20;
	movesMade = 0;
}
/*---------------------------------------
FUNCTION NAME:fire
PARAMETER(S):char and int
RETURN TYPE:char
POSTCONDITION(S):Takes in two values, a char an an int.
It recieves the char value and converts it into an int 
and uses the other int variable (-1) and uses that as the 
position for solutionGrid array to see if there is a match.
If there is a match, it increases moves made and returns
H. If it misses, it returns a miss and still increments moves
made. If it is out of bounds, it returns E and does not 
increment movesmade. 
---------------------------------------*/
char battleship::fire(char x, int y)
{
	int a = x - 65;
	y -= 1;
	bool alreadyHit = false;
	
	if(playerGrid[a][y] != ' ')
		alreadyHit = true;

	if(a > 9 or a < 0 or y > 9 or y < 0 or alreadyHit)
		return 'E';
	if(solutionGrid[a][y]){
		playerGrid[a][y] = 'X';
		movesMade++;
		return 'H';
	}else{
		movesMade++;
		playerGrid[a][y] = '-';
		return 'M';
	}
}
/*---------------------------------------
FUNCTION NAME:isOver
PARAMETER(S):none
RETURN TYPE:Char
POSTCONDITION(S):Function in general checks which state
the game is in. It does this by constantly checking the 
solutionGrid with the playerGrid. If all X's match, 
the boolean gameOver is set to true and the game is read
as won. However if the movesmade = maxmoves and the
player hasn't hit all X's, it returns L for loss.
Otherwise the function returns C to say game is still going on.
---------------------------------------*/
char battleship::isOver() const
{
	bool gameOver = true;

	for(int c = 0; c < ROWS; c++)
		for(int j = 0; j < COLUMNS; j++)
			if(solutionGrid[c][j] == true)
				if(playerGrid[c][j] != 'X')
					gameOver = false;
	
	if((movesMade == maxMoves) and !gameOver)
		return 'L';
	if(remaining()>0 and gameOver)
		return 'W';
	else
		return 'C';
}
/*---------------------------------------
FUNCTION NAME:GetGrid
PARAMETER(S):None
RETURN TYPE:string
POSTCONDITION(S):Outputs a string that forms a grid that contains
the playerGrid with labels
---------------------------------------*/
string battleship::getGrid() const
{
	string board = "  1 2 3 4 5 6 7 8 9 10 \n";
	
	char alph = 65;
	for(int i = 0; i < ROWS; i++){
		board += alph;
		for(int j = 0; j < COLUMNS; j++){
			board += '|';
			board += playerGrid[i][j];
		}
		board += '|';
		alph++;
		board += '\n';	
	}
	return board;
}
/*---------------------------------------
FUNCTION NAME:remaining
PARAMETER(S):none
RETURN TYPE:int
POSTCONDITION(S):returns the amount of moves the
player has left. Max moves - movesmade; simple function
---------------------------------------*/
int battleship::remaining() const
{
	return maxMoves - movesMade;
}