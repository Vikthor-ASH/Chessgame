//kingCheck(), and legelMove() calculations based on AlphaBetaChess.java by Logic Crazy Chess
//https://onedrive.live.com/?authkey=%21AIKDmEOnXEbMfHk&cid=D4629BC8D856F7D5&id=D4629BC8D856F7D5%21179&parId=D4629BC8D856F7D5%21176&o=OneUp

#ifndef PIECE_H
#define PIECE_H
#include <string>

//abstract/base class
class Piece {
public:
	bool static kingSafe(); //Check if king is safe
	static std::string currentPosition(); //Current Horizontal and Vertical position of piece
};

class Pawn : public Piece // derive class Pawn from class Piece
{
public:
	bool isWhite(); //Determine which direction pawn can move in based on if it is White or Black
	static std::string legalMoveP(int); //Retrieve legal moves for pawn

};

class Rook : public Piece
{
public:
	static std::string legalMoveR(int);
};

class Bishop : public Piece
{
public:
	static std::string legalMoveB(int);
};

class Knight : public Piece
{
public:
	static std::string legalMoveN(int);
};

class Queen : public Piece
{
public:
	static std::string legalMoveQ(int);
};

class King : public Piece
{
public:
	static std::string legalMoveK(int);
};

#endif
