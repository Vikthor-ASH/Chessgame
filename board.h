#ifndef BOARD_H
#define BOARD_H
#include <string>
#include "Piece.h"

using namespace std;

class JustABoard
{
public:
	string static board[8][8];
};

class Board {
private:
	JustABoard currentBoard;
public:
	void static getUserMove(string); //Coordinates of source, coordinates of destination
	void displayBoard(); // the current state of the game
	void play();
};




#endif 
