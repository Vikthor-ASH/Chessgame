#include "stdafx.h"
#include <string>
#include <iostream>
#include "board.h"
#include "Piece.h"
#include <ctype.h>
// Create legal moves for black pieces ------------------------------------------------------------------------------------
// Call currentPosition() and legalMoves() so program knows where pieces are and how they can move ------------------------------
// Do kingCheck for black -------------------------------------------------------------------------------------------------

using namespace std;

int kingPosWhite = 0;
int kingPosBlack = 0;
int row;
int col;
int r;
int c;
JustABoard CurrentGame;


string JustABoard::board[8][8]
{
	// To convert from a position on the [64] item board to a [8][8] board
	//row = (byte)(index / 8); (horizontal)
	//col = (byte)(index % 8); (vertical)

	{ "r","n","b","q","k","b","n","r" },
	{ "p","p","p","p","p","p","p","p" },
	{ "-","-","-","-","-","-","-","-" },
	{ "-","-","-","-","-","-","-","-" },
	{ "-","-","-","-","-","-","-","-" },
	{ "-","-","-","-","-","-","-","-" },
	{ "P","P","P","P","P","P","P","P" },
	{ "R","N","B","Q","K","B","N","R" }
};


void Board::displayBoard(){
	getUserMove("");
	int counter = 0;
	int i = 0;
	for (int j = 0; j < 9; j++) {
		if (j == 8) {
			i++;
			j = 0;
			cout << endl;
		}

		cout << currentBoard.board[i][j] << " ";
		if (i == 7 && j == 7) {
			cout << endl; // setw
			break;
		}
	}


};

void Board::getUserMove(string move)
{
	//to                    from
	//move receives x1,y1,x2,y2(0,1,2,3)
	//r1,c1,r2,c2,piece captured
	CurrentGame.board[r][c] = CurrentGame.board[row][col];
	//from = "-"
	CurrentGame.board[row][col] = "-";
}

void Board::play()
{
	Piece k;
	Pawn p;
	int i = 0;

	cout << "If you wish to exit at any time, type 9 into both the row and column input.\n" << endl;

	do
	{
		cout << "\nEnter the Row of the piece you would like to move: " << endl;
		cin >> row;
		cout << "\nEnter the column of the piece you would like to move: " << endl;
		cin >> col;

		if (currentBoard.board[row][col] == "P")
		{
			cout << "\nEnter the Row of the position you would like to move to: " << endl;
			cin >> r;
			cout << "\nEnter the column of the position you would like to move to: " << endl;
			cin >> c;
			cout << endl;
			k.currentPosition();
			p.legalMoveP(i);


			displayBoard();
			//Check pawn legal moves
		}

		/*else if (currentBoard.board[row][col] == "R")
		{

		}
		else if (currentBoard.board[row][col] == "N")
		{

		}

		else if ((row == 9) && (col == 9))
		{
			break;
		}*/

	} while ((!k.kingSafe()) || ((row == 9) && (col == 9)));
}


string Piece::currentPosition()
{
	Pawn P, p;
	Rook R, r;
	Bishop B, b;
	Knight N, n;
	Queen Q, q;
	King K, k;

	string position;

	for (int i = 0; i < 64; i++)
	{
		if (CurrentGame.board[i / 8][i % 8] == "P")
		{
			position += P.legalMoveP(i);
		}
		else if (CurrentGame.board[i / 8][i % 8] == "R")
		{
			position += R.legalMoveR(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "N")
		{
			position += N.legalMoveN(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "B")
		{
			position += B.legalMoveB(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "Q")
		{
			position += Q.legalMoveQ(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "K")
		{
			position += K.legalMoveK(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "p")
		{
			position += p.legalMoveP(i);
		}
		else if (CurrentGame.board[i / 8][i % 8] == "r")
		{
			position += r.legalMoveR(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "n")
		{
			position += n.legalMoveN(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "b")
		{
			position += b.legalMoveB(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "q")
		{
			position += q.legalMoveQ(i);

		}
		else if (CurrentGame.board[i / 8][i % 8] == "k")
		{
			position += k.legalMoveK(i);

		}
	}
	return position;
}


bool Piece::kingSafe() //do for white
{
	int temp = 1;

	//Bishop/ Queen
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			try {
				while (CurrentGame.board[kingPosWhite / 8 + temp * i][kingPosWhite % 8 + temp * j] == "-")
				{
					temp++;
				}
				if ((CurrentGame.board[kingPosWhite / 8 + temp * i][kingPosWhite % 8 + temp * j] == "b") || (CurrentGame.board[kingPosWhite / 8 + temp * i][kingPosWhite % 8 + temp * j] == "q"))
				{
					return false;
				}

			}
			catch (exception e) {}
			temp = 1;
		}
	}

	//rook/queen
	for (int i = -1; i <= 1; i += 2) {
		try {
			while (CurrentGame.board[kingPosWhite / 8][kingPosWhite % 8 + temp * i] == "-")
			{
				temp++;
			}
			if ((CurrentGame.board[kingPosWhite / 8][kingPosWhite % 8 + temp * i] == "r") || (CurrentGame.board[kingPosWhite / 8][kingPosWhite % 8 + temp * i] == "q"))
			{
				return false;
			}
		}
		catch (exception e) {}
		temp = 1;

		try {
			while (CurrentGame.board[kingPosWhite / 8 + temp * i][kingPosWhite % 8] == "-")
			{
				temp++;
			}
			if ((CurrentGame.board[kingPosWhite / 8 + temp * i][kingPosWhite % 8] == "r") || (CurrentGame.board[kingPosWhite / 8 + temp * i][kingPosWhite % 8] == "q"))
			{
				return false;
			}

		}
		catch (exception e) {}
		temp = 1;

	}

	//Knight
	for (int i = -1; i <= 1; i += 2) {
		for (int j = -1; j <= 1; j += 2) {
			try {
				if (CurrentGame.board[kingPosWhite / 8 + i][kingPosWhite % 8 + j * 2] == "n")
				{
					return false;
				}

			}
			catch (exception e) {}
			try {
				if (CurrentGame.board[kingPosWhite / 8 + i * 2][kingPosWhite % 8 + j] == "n")
				{
					return false;
				}

			}
			catch (exception e) {}
		}
	}
	//Pawn
	if (kingPosWhite >= 16) {
		try {
			if (CurrentGame.board[kingPosWhite / 8 - 1][kingPosWhite % 8 - 1] == "p")
			{
				return false;
			}
		}
		catch (exception e) {}
		try {
			if (CurrentGame.board[kingPosWhite / 8 - 1][kingPosWhite % 8 + 1] == "p")
			{
				return false;
			}
		}
		catch (exception e) {}

		//king
		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i != 0 || j != 0) {
					try {
						if (CurrentGame.board[kingPosWhite / 8 + i][kingPosWhite % 8 + j] == "k")
						{
							return false;
						}
					}
					catch (exception e) {}
				}
			}
		}
	}
	return true;
}

bool Pawn::isWhite() // figure out better way of making all control paths return value
{
	int black = 0;
	int white = 0;
	for (int i = 0; i < 64; i++)
	{
		if (islower(CurrentGame.board[i / 8][i % 8].at(0)) && (CurrentGame.board[i / 8][i % 8] == "p"))
		{
			black = 1;
		}
		else (isupper(CurrentGame.board[i / 8][i % 8].at(0)) && (CurrentGame.board[i / 8][i % 8] == "P"));
		{
			white = 1;
		}
	}

	if (black == 1)
	{
		return false;
	}
	else
	{
		return true;
	}
}

string Pawn::legalMoveP(int i)
{
	string list;
	string oldPiece;
	int r = i / 8; //Horizontal --
	int c = i % 8; //Vertical ||

	for (int j = -1; j <= 1; j += 2) {
		try {// capture
			if (islower(CurrentGame.board[r - 1][c + j].at(0)))
			{
				oldPiece = CurrentGame.board[r - 1][c + j];
				CurrentGame.board[r][c] = "-";
				CurrentGame.board[r - 1][c + j] = "P";
				if (Piece::kingSafe())
				{
					list = list + to_string(r) + to_string(c) + to_string(r - 1) + to_string(c + j) + oldPiece;
				}
				CurrentGame.board[r][c] = "P";
				CurrentGame.board[r - 1][c + j] = oldPiece;
			}

		}
		catch (exception e) {}

		try {// move one up
			if (CurrentGame.board[r - 1][c] == "-")
			{
				oldPiece = CurrentGame.board[r - 1][c];
				CurrentGame.board[r][c] = "-";
				CurrentGame.board[r - 1][c] = "P";
				if (Piece::kingSafe())
				{
					list = list + to_string(r) + to_string(c) + to_string(r - 1) + to_string(c) + oldPiece;
				}
				CurrentGame.board[r][c] = "P";
				CurrentGame.board[r - 1][c] = oldPiece;
			}

		}
		catch (exception e) {}

		try {// move 2 up
			if ((CurrentGame.board[r - 1][c] == "-") && (CurrentGame.board[r - 2][c] == "-"))
			{
				oldPiece = CurrentGame.board[r - 2][c];
				CurrentGame.board[r][c] = "-";
				CurrentGame.board[r - 2][c] = "P";
				if (Piece::kingSafe())
				{
					list = list + to_string(r) + to_string(c) + to_string(r - 2) + to_string(c) + oldPiece;
				}
				CurrentGame.board[r][c] = "P";
				CurrentGame.board[r - 2][c] = oldPiece;
			}

		}
		catch (exception e) {}
	}
	return list;
}

string Rook::legalMoveR(int i)
{
	string oldPiece;
	string list;
	int r = i / 8; //Horizontal --
	int c = i % 8; //Vertical ||
	int temp = 1;
	for (int j = -1; j <= 1; j += 2) {
		try {
			while (CurrentGame.board[r][c + temp * j] == "-")
			{
				oldPiece = CurrentGame.board[r][c + temp * j];
				CurrentGame.board[r][c] == "-";
				CurrentGame.board[r][c + temp * j] = "R";
				if (Piece::kingSafe()) {
					list = list + to_string(r) + to_string(c) + to_string(r) + to_string(c + temp * j) + oldPiece;
				}
				CurrentGame.board[r][c] = "R";
				CurrentGame.board[r][c + temp * j] = oldPiece;
				temp++;
			}
			if (islower(CurrentGame.board[r][c + temp * j].at(0)))
			{
				oldPiece = CurrentGame.board[r][c + temp * j];
				CurrentGame.board[r][c] = "-";
				CurrentGame.board[r][c + temp * j] = "R";
				if (Piece::kingSafe())
				{
					list = list + to_string(r) + to_string(c) + to_string(r) + to_string(c + temp * j) + oldPiece;
				}
				CurrentGame.board[r][c] = "R";
				CurrentGame.board[r][c + temp * j] = oldPiece;
			}
		}
		catch (exception e) {}
		temp = 1;
		try {
			while (CurrentGame.board[r + temp * j][c] == "-")
			{
				oldPiece = CurrentGame.board[r + temp * j][c];
				CurrentGame.board[r][c] == "-";
				CurrentGame.board[r + temp * j][c] = "R";
				if (Piece::kingSafe()) {
					list = list + to_string(r) + to_string(c) + to_string(r + temp * j) + to_string(c) + oldPiece;
				}
				CurrentGame.board[r][c] = "R";
				CurrentGame.board[r + temp * j][c] = oldPiece;
				temp++;
			}
			if (islower(CurrentGame.board[r + temp * j][c].at(0)))
			{
				oldPiece = CurrentGame.board[r + temp * j][c];
				CurrentGame.board[r][c] = "-";
				CurrentGame.board[r + temp * j][c] = "R";
				if (Piece::kingSafe())
				{
					list = list + to_string(r) + to_string(c) + to_string(r + temp * j) + to_string(c) + oldPiece;
				}
				CurrentGame.board[r][c] = "R";
				CurrentGame.board[r + temp * j][c] = oldPiece;
			}
		}
		catch (exception e) {}
	}
	return list;
}

string Bishop::legalMoveB(int i)
{
	string oldPiece;
	string list;
	int r = i / 8; //Horizontal --
	int c = i % 8; //Vertical ||
	int temp = 1;

	for (int j = -1; j <= 1; j += 2)
	{
		for (int k = -1; k <= 1; k += 2)
		{
			try {
				while (CurrentGame.board[r + temp * j][c + temp * k] == "-")
				{
					oldPiece = CurrentGame.board[r + temp * j][c + temp * k];
					CurrentGame.board[r][c] == "-";
					CurrentGame.board[r + temp * j][c + temp * k] = "B";
					if (Piece::kingSafe()) {
						list = list + to_string(r) + to_string(c) + to_string(r + temp * j) + to_string(c + temp * k) + oldPiece;
					}
					CurrentGame.board[r][c] = "B";
					CurrentGame.board[r + temp * j][c + temp * k] = oldPiece;
					temp++;
				}
				if (islower(CurrentGame.board[r + temp * j][c + temp * k].at(0)))
				{
					oldPiece = CurrentGame.board[r + temp * j][c + temp * k];
					CurrentGame.board[r][c] = "-";
					CurrentGame.board[r + temp * j][c + temp * k] = "B";
					if (Piece::kingSafe())
					{
						list = list + to_string(r) + to_string(c) + to_string(r + temp * j) + to_string(c + temp * k) + oldPiece;
					}
					CurrentGame.board[r][c] = "B";
					CurrentGame.board[r + temp * j][c + temp * k] = oldPiece;
				}
			}
			catch (exception e) {}
			temp = 1;
		}
	}
	return list;
}

string Knight::legalMoveN(int i)
{
	string oldPiece;
	string list;
	int r = i / 8; //Horizontal --
	int c = i % 8; //Vertical ||

	for (int j = -1; j <= 1; j += 2)
	{
		for (int k = -1; k <= 1; k += 2)
		{
			try {
				if (islower(CurrentGame.board[r + j][c + k * 2].at(0)) || ((CurrentGame.board[r + j][c + k * 2] == "-")))
				{
					oldPiece = CurrentGame.board[r + j][c + k * 2];
					CurrentGame.board[r][c] = "-";
					if (Piece::kingSafe())
					{
						list = list + to_string(r) + to_string(c) + to_string(r + j) + to_string(c + k * 2) + oldPiece;
					}
					CurrentGame.board[r][c] = "N";
					CurrentGame.board[r + j][c + k * 2] = oldPiece;
				}

			}
			catch (exception e) {}
			try {
				if (islower(CurrentGame.board[r + j * 2][c + k].at(0)) || ((CurrentGame.board[r + j * 2][c + k] == "-")))
				{
					oldPiece = CurrentGame.board[r + j * 2][c + k];
					CurrentGame.board[r][c] = "-";
					if (Piece::kingSafe())
					{
						list = list + to_string(r) + to_string(c) + to_string(r + j * 2) + to_string(c + k) + oldPiece;
					}
					CurrentGame.board[r][c] = "N";
					CurrentGame.board[r + j * 2][c + k] = oldPiece;
				}

			}
			catch (exception e) {}
		}

	}
	return list;
}

string Queen::legalMoveQ(int i)
{
	string oldPiece;
	string list;
	int r = i / 8; //Horizontal --
	int c = i % 8; //Vertical ||
	int temp = 1;

	for (int j = -1; j <= 1; j++) {
		for (int k = -1; k <= 1; k++) {
			if (j != 0 || k != 0) {
				try {
					while (CurrentGame.board[r + temp * j][c + temp * k] == "-")
					{
						oldPiece = CurrentGame.board[r + temp * j][c + temp * k];
						CurrentGame.board[r][c] == " ";
						CurrentGame.board[r + temp * j][c + temp * k] = "Q";
						if (Piece::kingSafe()) {
							list = list + to_string(r) + to_string(c) + to_string(r + temp * j) + to_string(c + temp * k) + oldPiece;
						}
						CurrentGame.board[r][c] = "Q";
						CurrentGame.board[r + temp * j][c + temp * k] = oldPiece;
						temp++;
					}
					if (islower(CurrentGame.board[r + temp * j][c + temp * k].at(0)))
					{
						oldPiece = CurrentGame.board[r + temp * j][c + temp * k];
						CurrentGame.board[r][c] = "-";
						CurrentGame.board[r + temp * j][c + temp * k] = "Q";
						if (Piece::kingSafe())
						{
							list = list + to_string(r) + to_string(c) + to_string(r + temp * j) + to_string(c + temp * k) + oldPiece;
						}
						CurrentGame.board[r][c] = "Q";
						CurrentGame.board[r + temp * j][c + temp * k] = oldPiece;
					}
				}
				catch (exception e) {}
				temp = 1;
			}
		}
	}
	return list;
}

string King::legalMoveK(int i)
{
	string oldPiece;
	string list;
	int r = i / 8; //Horizontal --
	int c = i % 8; //Vertical ||
	for (int j = 0; j < 9; j++) {
		if (j != 4) {
			try {
				if (islower(CurrentGame.board[r - 1 + j / 3][c - 1 + j % 3].at(0)) || (CurrentGame.board[r - 1 + j / 3][c - 1 + j % 3] == "-"))
				{
					oldPiece = CurrentGame.board[r - 1 + j / 3][c - 1 + j % 3];
					CurrentGame.board[r][c] = "-";
					CurrentGame.board[r - 1 + j / 3][c - 1 + j % 3] = "K";
					int kingTemp = kingPosWhite;
					kingPosWhite = i + (j / 3) * 8 + j % 3 - 9;
					if (Piece::kingSafe())
					{
						list = list + to_string(r) + to_string(c) + to_string(r - 1 + j / 3) + to_string(c - 1 + j % 3) + oldPiece;
					}
					CurrentGame.board[r][c] = "K";
					CurrentGame.board[r - 1 + j / 3][c - 1 + j % 3] = oldPiece;
					kingPosWhite = kingTemp;
				}
			}
			catch (exception e) {}
		}
	}
	return list;
}
