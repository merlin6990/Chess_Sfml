#include <SFML/Window.hpp>
#include<SFML/Graphics.hpp>
#include<iostream>
#include<vector>
#include <SFML/System.hpp>
#include<SFML/Audio.hpp>
bool alive[33] = { true,true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true, true ,true};
int Board[8][8] = { {-9,-10,-11,-13,-12,-14,-15,-16} ,{-1,-2,-3,-4,-5,-6,-7,-8},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{1,2,3,4,5,6,7,8},{9,10,11,13,12,14,15,16} };
bool whitetomove = true;
bool pawns_transformed[17] = {false ,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false,false };
bool LongCastleOpWhite = true, LongCastleOpBlack=true,ShortCastleOpWhite = true, ShortCastleOpBlack = true;
bool shortblack = false, shortwhite = false, longblack = false, longwhite = false;
bool blacktomove = false;
bool transform = false;
bool whitekingmoved = false, blackkingmoved = false;
int whiteKingxpos=7, whiteKingypos=4, blackKingxpos=0, blackKingypos=4;
int wsubkx = whiteKingxpos, wsubky = whiteKingypos, bsubkx = blackKingxpos, bsubky = blackKingypos;
int Transformation(int x);
bool KingInDanger() {
	if (whitetomove) {
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				if (Board[i][j] < 0) {
					//std::cout << j;
					if (abs(Board[i][j]) <= 8) {
						if (i + 1 == whiteKingxpos && (j - 1 == whiteKingypos || j + 1 == whiteKingypos)) {
							return true;
						}
					}
					//horizontal or vertical attacks which can be delivered by Queen or Rook
					else if (abs(Board[i][j]) == 9 || abs(Board[i][j]) == 13 || abs(Board[i][j]) == 16 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 9)) {
						bool kingunderattack = true;
						if (j == whiteKingypos) {
							for (int k = std::min(i, whiteKingxpos)+1; k < std::max(i, whiteKingxpos); k++) {
								if (Board[k][j] != 0 /*&& Board[k][j]!=12*/) {
									kingunderattack = false;
									
									break;
								}	
							}
							if (kingunderattack) {
								std::cout << "white x:" << whiteKingxpos << "white y:" << whiteKingypos;
								return true;
							}
						}
						else if (i == whiteKingxpos) {
							for (int k = std::min(j, whiteKingypos) + 1; k < std::max(j, whiteKingypos); k++) {
								if (Board[i][k] != 0 /*&& Board[i][k]!=12*/) {
									kingunderattack = false;
									break;
								}
							}
							if (kingunderattack) {
								return true;
							}

						}
					}
					//diagonal attacks delivered by Queen or a bishop
					if (abs(Board[i][j]) == 11 || abs(Board[i][j]) == 13 || abs(Board[i][j]) == 14 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 11)) {
						std::cout << abs(i - j)<< abs(whiteKingxpos - whiteKingypos)<<"  ";
						if (abs(i - whiteKingxpos) == abs(j - whiteKingypos)) {
							// Check if there are any pieces blocking the way
							bool under = true;
							int rowDiff = whiteKingxpos - i;
							int colDiff = whiteKingypos - j;
							int rowStep = rowDiff > 0 ? 1 : -1;
							int colStep = colDiff > 0 ? 1 : -1;
							int row = i + rowStep;
							int col = j + colStep;
							while (row != whiteKingxpos || col != whiteKingypos)
							{
								if (Board[row][col] != 0)
								{
									under = false;
									break;
								}

								row += rowStep;
								col += colStep;
							}
							if (under) {
								return true;
							}
						}
					}
					//we have the knight
					else if (abs(Board[i][j]) == 10 || abs(Board[i][j]) == 15 || (abs(Board[i][j]) % 100 == 10)) {
						if ((i - 2 == whiteKingxpos && (j + 1 == whiteKingypos || j - 1 == whiteKingypos)) || (i + 2 == whiteKingxpos && (j + 1 == whiteKingypos || j - 1 == whiteKingypos)) || (j - 2 == whiteKingypos && (i + 1 == whiteKingxpos || i - 1 == whiteKingxpos)) || (j + 2 == whiteKingypos && (i + 1 == whiteKingxpos || i - 1 == whiteKingxpos))) {
							return true;
						}
					}
					// and at last we have the King itself
					else if (abs(Board[i][j]) == 12) {
						for (int z = i - 1; z <= i + 1; z++) {
							for (int zprim = j - 1; zprim <= j + 1; zprim++) {
								if (whiteKingxpos == z && whiteKingypos == zprim) {
									return true;
								}
							}
						}

					}
				}
			}
		}
		//std::cout << "king is under attack do sth!!!!";
		return false;


	}
	else {
		for (int i = 0; i <= 7; i++) {
			for (int j = 0; j <= 7; j++) {
				if (Board[i][j] > 0) {
					bool kingunderattack = true;
					if (abs(Board[i][j]) <= 8) {
						if (i - 1== blackKingxpos && (j - 1 == blackKingypos || j + 1 == blackKingypos)) {
							return true;
						}
					}
					//horizontal or vertical attacks which can be delivered by Queen or Rook
					else if (abs(Board[i][j]) == 9 || abs(Board[i][j]) == 13 || abs(Board[i][j]) == 16 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 9)) {
						bool kingunderattack = true;
						if (j == blackKingypos) {
							for (int k = std::min(i, blackKingxpos) + 1; k < std::max(i, blackKingxpos); k++) {
								if (Board[k][j] != 0 /*&& Board[k][j]!=12*/) {
									kingunderattack = false;

									break;
								}
							}
							if (kingunderattack) {
								return true;
							}
						}
						else if (i == blackKingxpos) {
							for (int k = std::min(j, blackKingypos) + 1; k < std::max(j, blackKingypos); k++) {
								if (Board[i][k] != 0 /*&& Board[i][k]!=12*/) {
									kingunderattack = false;
									break;
								}
							}
							if (kingunderattack) {
								return true;
							}

						}
					}
					//diagonal attacks delivered by Queen or a bishop
					if (abs(Board[i][j]) == 11 || abs(Board[i][j]) == 13 || abs(Board[i][j]) == 14 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 11)) {
						if (abs(i - blackKingxpos) == abs(j - blackKingypos)) {
							// Check if there are any pieces blocking the way
							bool under = true;
							int rowDiff = blackKingxpos - i;
							int colDiff = blackKingypos - j;
							int rowStep = rowDiff > 0 ? 1 : -1;
							int colStep = colDiff > 0 ? 1 : -1;
							int row = i + rowStep;
							int col = j + colStep;
							while (row != blackKingxpos || col != blackKingypos)
							{
								if (Board[row][col] != 0)
								{
									under = false;
									break;
								}

								row += rowStep;
								col += colStep;
							}
							if (under) {
								return true;
							}
						}
					}
					//we have the knight
					else if (abs(Board[i][j]) == 10 || abs(Board[i][j]) == 15 || (abs(Board[i][j]) % 100 == 10)) {
						if ((i - 2 == blackKingxpos && (j + 1 == blackKingypos || j - 1 == blackKingypos)) || (i + 2 == blackKingxpos && (j + 1 == blackKingypos || j - 1 == blackKingypos)) || (j - 2 == blackKingypos && (i + 1 == blackKingxpos || i - 1 == blackKingxpos)) || (j + 2 == blackKingypos && (i + 1 == blackKingxpos || i - 1 == blackKingxpos))) {
							return true;
						}
					}
					// and at last we have the King itself
					else if (abs(Board[i][j]) == 12) {
						for (int z = i - 1; z <= i + 1; z++) {
							for (int zprim = j - 1; zprim <= j + 1; zprim++) {
								if (blackKingxpos == z && blackKingypos == zprim) {
									return true;
								}
							}
						}

					}

				}
			}
		}
		return false;

	}
}



bool islegal(int x1, int y1, int x2, int y2) {
	x1 /= 100; y1 /= 100; x2 /= 100; y2 /= 100;
	//check if the cursor is out of the window
	if (x1>7 || x2 > 7 || x1 < 0 || x2 < 0 || y1>7 || y2 > 7 || y1 < 0 || y2 < 0 )
	{
		return false;
	}
	//check if the start pos is empty
	if (Board[x1][y1] == 0) {
		return false;
	}
	// Check if the end position is occupied by a piece of the same color
	if ((Board[x1][y1]>0 && Board[x2][y2] > 0)|| (Board[x1][y1] < 0 && Board[x2][y2] < 0)) {
		return false;
	}
	//check whose turn is it??
	if (Board[x1][y1] > 0 && blacktomove) {
		return false;
	}
	if (Board[x1][y1] < 0 && whitetomove) {
		return false;
	}
	if (x1 == x2 && y1 == y2) {
		return false;
	}
	//////////////////////////////////////////////////////////////////////////
	//castling
	if (abs(Board[x1][y1]) == 12 && x1 == x2) {
		if (Board[x1][y1] == 12) {
			//long castle
			if (y2 == 2 && Board[x1][2] == 0 && Board[x1][1] == 0 && Board[x1][3] == 0 && LongCastleOpWhite) {
				bool letithappen = true;
				int sub = whiteKingypos;
				for (int z = sub; z >= 0; z--) {
					whiteKingypos = z;
					if (KingInDanger()) {
						letithappen = false;
						break;
					}
				}
				whiteKingypos = sub;
				if (letithappen) {
					ShortCastleOpWhite = false;
					Board[x1][y1] = 0;
					Board[7][2] = 12;
					Board[7][0] = 0;
					Board[7][3] = 9;
					whiteKingypos = 2;
					longwhite = true;
					return true;
			    }
			}
			//short castle
			if (y2 == 6 && Board[x1][5] == 0 && Board[x1][6] == 0 && ShortCastleOpWhite) {
				bool letithappen = true;
				int sub = whiteKingypos;
				for (int z = sub; z <= 7; z++) {
					whiteKingypos = z;
					if (KingInDanger()) {
						letithappen = false;
						break;
					}
				}
				whiteKingypos = sub;
				if (letithappen) {
					LongCastleOpWhite = false;
					Board[7][6] = 12;
					Board[7][7] = 0;
					Board[7][5] = 16;
					Board[x1][y1] = 0;
					whiteKingypos = 6;
					shortwhite = true;
					return true;
				}
			}
		}
		else {
			if (y2 == 2 && Board[x1][2] == 0 && Board[x1][1] == 0 && Board[x1][3] == 0 && LongCastleOpBlack) {
				bool letithappen = true;
				int sub = blackKingypos;
				for (int z = sub; z >= 0; z--) {
					blackKingypos = z;
					if (KingInDanger()) {
						letithappen = false;
						break;
					}
				}
				blackKingypos = sub;
				if (letithappen) {
					ShortCastleOpBlack = false;
					Board[x1][y1] = 0;
					Board[0][2] = -12;
					Board[0][0] = 0;
					Board[0][3] = -9;
					blackKingypos = 2;
					longblack = true;
					return true;
				}
			}
			//short castle
			if (y2 == 6 && Board[x1][5] == 0 && Board[x1][6] == 0 && ShortCastleOpBlack) {
				bool letithappen = true;
				int sub = blackKingypos;
				for (int z = sub; z <= 7; z++) {
					blackKingypos = z;
					if (KingInDanger()) {
						letithappen = false;
						break;
					}
				}
				blackKingypos = sub;
				if (letithappen) {
					LongCastleOpBlack = false;
					Board[0][6] = -12;
					Board[0][7] = 0;
					Board[0][5] = -16;
					Board[x1][y1] = 0;
					blackKingypos = 6;
					shortblack = true;
					return true;
				}
			}

		}
	}

	////////////////////////////////////////////////////////////








	// Check if the move is legal for the specific piece type
	//first the pawns
	if (Board[x1][y1] / 9 == 0) {
		//white pawns can't go downwards and black pawns can't go upwards
		if (Board[x1][y1] > 0) {
			if (x2 - x1 > 0) {
				return false;
			}
		}
		else {
			if (x1 - x2 > 0) {
				return false;
			}
		}
		int rowDiff = abs(x2 - x1);
		if (rowDiff > 2)
		{
			return false;
		}
		if (rowDiff == 2 && whitetomove && x1 != 6) {
			return false;
		}
		if (rowDiff == 2 && whitetomove && Board[x1 - 1][y2] < 0) {
			return false;
		}
		if (rowDiff == 2 && blacktomove && x1!=1) {
			return false;
		}

		if (rowDiff == 2 && blacktomove && x1 != 1 && Board[x1 + 1][y2] > 0) {
			return false;
		}
		if (rowDiff == 2 && blacktomove && Board[x1 + 1][y2] > 0) {
			return false;
		}
		if (x1 == x2) {
			return false;
		}
		// Pawns can only capture diagonally
		int colDiff = abs(y2 - y1);
		if (colDiff >1)
		{
			return false;
		}
		if (colDiff == 1 && Board[x2][y2] == 0) {
			return 0;
		}
		if ((colDiff == 0 && rowDiff == 1 && Board[x2][y2] != 0) || (colDiff == 0 && rowDiff == 2 && Board[x2][y2] != 0)) {

			return false;
		}
		//Transformation
		if (Board[x1][y1]>0 && x2==0) {
			int subx = x1, suby = y1, piece = Board[x1][y1], oppiece;
			if (Board[x2][y2] < 0) {
				oppiece = Board[x2][y2];
				Board[x2][y2] = piece;
				Board[x1][y1] = 0;
				if (KingInDanger()) {
					Board[x1][y1] = piece;
					Board[x2][y2] = oppiece;
					return false;
				}
				Board[x1][y1] = piece;
				Board[x2][y2] = oppiece;
			}
			Board[x2][y2] = piece;
			Board[x1][y1] = 0;
			if (KingInDanger()) {
				Board[x1][y1] = piece;
				Board[x2][y2] = 0;
				return false;
			}
			Board[x1][y1] = piece;
			Board[x2][y2] = oppiece;


			/*transform = true;*/
			if (Board[x2][y2] < 0) {
				alive[(-1 * Board[x2][y2]) + 16] = false;
			}
			else if (Board[x2][y2] > 0) {
				alive[Board[x2][y2]] = false;
			}
			Board[x2][y2]=100* Board[x1][y1] +Transformation(0);
			/*alive[Board[x1][y1]] = false;*/
			/*pawns_transformed[Board[x1][y1]] = true;*/
			Board[x1][y1] = 0;
			return true;
		}
		else if (Board[x1][y1] < 0 && x2==7) {
			int subx = x1, suby = y1, piece = Board[x1][y1], oppiece;
			if (Board[x2][y2] > 0) {
				oppiece = Board[x2][y2];
				Board[x2][y2] = piece;
				Board[x1][y1] = 0;
				if (KingInDanger()) {
					Board[x1][y1] = piece;
					Board[x2][y2] = oppiece;
					return false;
				}
				Board[x1][y1] = piece;
				Board[x2][y2] = oppiece;
			}
			Board[x2][y2] = piece;
			Board[x1][y1] = 0;
			if (KingInDanger()) {
				Board[x1][y1] = piece;
				Board[x2][y2] = 0;
				return false;
			}
			Board[x1][y1] = piece;
			Board[x2][y2] = oppiece;
			/*transform = true;*/
			if (Board[x2][y2] < 0) {
				alive[(-1 * Board[x2][y2]) + 16] = false;
			}
			else if (Board[x2][y2] > 0) {
				alive[Board[x2][y2]] = false;
			}
			Board[x2][y2] =100* Board[x1][y1] +Transformation(1);
			/*alive[(-1 * Board[x1][y1]) + 16] = false;*/
			/*pawns_transformed[-1*Board[x1][y1]+8] = true;*/
			Board[x1][y1] = 0;
			return true;
		}
	}
	//now we have got the Rooks
	else if (abs(Board[x1][y1]) == 9 || abs(Board[x1][y1]) == 16 || (abs(Board[x1][y1])%100==9)) {
		// Rooks can only move horizontally or vertically
		if (x1 != x2 && y1 != y2) {
			return false;
		}
		// Check if there are any pieces blocking the way
		if (x1 == x2) {
			int minCol = std::min(y1,y2);
			int maxCol = std::max(y1,y2);
			for (int col = minCol + 1; col < maxCol; col++)
			{
				if (Board[x1][col] != 0)
				{
					return false;
				}
			}
		}
		else {
			// Check along the same column
			int minRow = std::min(x1,x2);
			int maxRow = std::max(x1,x2);
			for (int row = minRow + 1; row < maxRow; row++)
			{
				if (Board[row][y1] != 0)
				{
					return false;
				}
			}
		}
		if (abs(Board[x1][y1]) == 9) {
			if (Board[x1][y1] > 0) {
				LongCastleOpWhite = false;
			}
			else {
				LongCastleOpBlack = false;
			}
		}
		else {
			if (Board[x1][y1] > 0) {
				ShortCastleOpWhite = false;
			}
			else {
				ShortCastleOpBlack = false;
			}

		}

	}
	//now we have got the knight
	else if (abs(Board[x1][y1]) == 10 || abs(Board[x1][y1]) == 15 || (abs(Board[x1][y1]) % 100 == 10)) {
		// Knights can only move in an "L" shape (two squares horizontally and one square vertically, or vice versa)
		int rowDiff = abs(x1 - x2);
		int colDiff = abs(y1 - y2);
		if ((rowDiff != 2 || colDiff != 1) && (rowDiff != 1 || colDiff != 2))
		{
			return false;
		}
	}
	//now it's time for the bishops
	else if (abs(Board[x1][y1]) == 11 || abs(Board[x1][y1]) == 14 || (abs(Board[x1][y1]) % 100 == 11)) {
		// Bishops can only move diagonally
		if (abs(x1 - x2) != abs(y1 - y2))
		{
			return false;
		}
		// Check if there are any pieces blocking the way
		int rowDiff = x2 - x1;
		int colDiff = y2 - y1;
		int rowStep = rowDiff > 0 ? 1 : -1;
		int colStep = colDiff > 0 ? 1 : -1;
		int row = x1 + rowStep;
		int col = y1 + colStep;
		while (row != x2 || col != y2)
		{
			if (Board[row][col] != 0)
			{
				return false;
			}

			row += rowStep;
			col += colStep;
		}
	}
	//now we check the legal moves for Queen
	else if (abs(Board[x1][y1]) == 13 || (abs(Board[x1][y1]) % 100 == 13)) {
	if (x1 == x2 || y1 == y2)
	{
		// Check if there are any pieces blocking the way (like a rook)
		if (x1 == x2)
		{
			// Check along the same row
			int minCol = std::min(y1, y2);
			int maxCol = std::max(y1, y2);
			for (int col = minCol + 1; col < maxCol; col++)
			{
				if (Board[x1][col]!= 0)
				{
					return false;
				}
			}
		}
		else
		{
			// Check along the same column
			int minRow = std::min(x1, x2);
			int maxRow = std::max(x1, x2);
			for (int row = minRow + 1; row < maxRow; row++)
			{
				if (Board[row][y1] != 0)
				{
					return false;
				}
			}
		}
	}
	else if (abs(x1 - x2) == abs(y1 - y2))
	{
		// Check if there are any pieces blocking the way (like a bishop)
		int rowDiff = x2 - x1;
		int colDiff = y2 - y1;
		int rowStep = rowDiff > 0 ? 1 : -1;
		int colStep = colDiff > 0 ? 1 : -1;
		int row = x1 + rowStep;
		int col = y1 + colStep;
		while (row != x2 || col != y2)
		{
			if (Board[row][col] != 0)
			{
				return false;
			}

			row += rowStep;
			col += colStep;
		}
	}
	else
	{
		return false;
	}
	     
	}
	//and at last the King
	else if (abs(Board[x1][y1]) == 12) {
	// Kings can only move one square in any direction
	int rowDiff = abs(x1 - x2);
	int colDiff = abs(y1 - y2);
	if (rowDiff > 1 || colDiff > 1)
	{
		return false;
	}
	if (Board[x1][y1] == 12) {
		LongCastleOpWhite = false;
		ShortCastleOpWhite = false;
		whiteKingxpos = x2;
		whiteKingypos = y2;
	}
	else {
		LongCastleOpBlack = false;
		ShortCastleOpBlack = false;
		blackKingxpos = x2;
		blackKingypos = y2;
	}
}
	
















	int sub2 = Board[x2][y2], sub1 = Board[x1][y1];
	Board[x2][y2] = Board[x1][y1];
	Board[x1][y1] = 0;
	if (KingInDanger()) {
		Board[x2][y2] = sub2;
		Board[x1][y1] = sub1;
		whiteKingxpos = wsubkx;
		whiteKingypos = wsubky;
		blackKingxpos = bsubkx;
		blackKingypos = bsubky;
		std::cout << "white x:" << whiteKingxpos << "white y:" << whiteKingypos;
		return false;
	}
	else {
		wsubkx = whiteKingxpos;
		wsubky = whiteKingypos;
		bsubkx = blackKingxpos;
		bsubky = blackKingypos;
	}
	if (sub2 < 0) {
		if (sub2 / 100 != 0) {
			alive[(-1 * sub2/100) + 16] = false;
		}
		else {
			alive[(-1 * sub2) + 16] = false;
		}
	}
	else if (sub2 > 0) {
		if (sub2 / 100 != 0) {
			alive[(sub2/100)] = false;
		}
		else {
			alive[(sub2)] = false;
		}
	}

	


	return true;

}
bool CheckMate() {
	if (blacktomove) {
		blacktomove = false;
		whitetomove = true;
		if (KingInDanger()) {
			int subs = whiteKingxpos, subf = whiteKingypos;
			for (int z = whiteKingxpos - 1; z <= whiteKingxpos+ 1; z++) {
				for (int zprim = whiteKingypos - 1; zprim <= whiteKingypos + 1; zprim++) {
					if ((z >= 0 && z <= 7) && (zprim >= 0 && zprim <= 7) && Board[z][zprim] <= 0) {
							whiteKingxpos = z;
							whiteKingypos = zprim;
							if (!KingInDanger()) {
								whiteKingxpos = subs;
								whiteKingypos = subf;
								return false;
							}
							whiteKingxpos = subs;
							whiteKingypos = subf;
						
					}
				}
			}
			for (int i = 0; i <= 7; i++) {
				for (int j = 0; j <= 7; j++) {
					if (Board[i][j] > 0) {
						int subx=i, suby=j,piece=Board[i][j],oppiece;
						//check whether a pawn can save the king
						if (abs(Board[i][j]) <= 8 && i-1>=0) {

								if (Board[i - 1][j] == 0) {
									Board[i][j] = 0;
									Board[i - 1][j] = piece;
									if (!KingInDanger()) {

										Board[i][j] = piece;
										Board[i - 1][j] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[i - 1][j] = 0;
								}
								if (i == 6) {
									if (Board[i - 2][j] == 0) {
										Board[i][j] = 0;
										Board[i - 2][j] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j] = 0;
									}
								}
								if (Board[i - 1][j + 1] < 0 || Board[i - 1][j - 1] < 0) {
									if (Board[i - 1][j + 1] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 1][j + 1];
										Board[i - 1][j+1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j + 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j + 1] = oppiece;
									}
									else {
										Board[i][j] = 0;
										oppiece = Board[i - 1][j - 1];
										Board[i - 1][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j - 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j - 1] = oppiece;

									}
								}
						}
						else if (abs(Board[i][j]) == 13 || abs(Board[i][j]) == 9 || abs(Board[i][j]) == 16 || abs(Board[i][j])==11 || abs(Board[i][j])==14 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 9) || (abs(Board[i][j]) % 100 == 11)) {
							//queen can defend vertically like a rook and also horizontally ///Going down
							if(abs(Board[i][j])==13 || abs(Board[i][j])==9 || abs(Board[i][j])==16 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 9)){
							for (int z = i + 1; z <= 7; z++) {
								if (Board[z][j] > 0) {
									break;
								}
								else if (Board[z][j] == 0) {
									Board[i][j] = 0;
									Board[z][j] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][j] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][j] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][j];
									Board[z][j] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][j] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][j] = oppiece;
									break;
								}
							}
							//going up
							for (int z = i - 1; z >= 0; z--) {
								if (Board[z][j] > 0) {
									break;
								}
								else if (Board[z][j] == 0) {
									Board[i][j] = 0;
									Board[z][j] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][j] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][j] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][j];
									Board[z][j] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][j] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][j] = oppiece;
									break;
								}
							}
							//going right or left
							for (int z = j + 1; z <= 7; z++) {
								if (Board[i][z] > 0) {
									break;
								}
								else if (Board[i][z] == 0) {
									Board[i][j] = 0;
									Board[i][z] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i][z] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[i][z] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[i][z];
									Board[i][z] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i][z] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[i][z] = oppiece;
									break;
								}
							}
							//going left
							for (int z = j - 1; z >= 0; z--) {
								if (Board[i][z] > 0) {
									break;
								}
								else if (Board[i][z] == 0) {
									Board[i][j] = 0;
									Board[i][z] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i][z] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[i][z] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[i][z];
									Board[i][z] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i][z] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[i][z] = oppiece;
									break;
								}
							}
						}

						}
						//now bishops and queens can move diagonally
						if (abs(Board[i][j]) == 13 || abs(Board[i][j]) == 11 || abs(Board[i][j]) == 14 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 11)) {
							//north-east
							for (int z = i - 1, zprim = j + 1; z >= 0 && zprim <= 7; z--, zprim++) {
								if (Board[z][zprim] > 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}
							}
							//north-west
							for (int z = i - 1, zprim = j - 1; z >= 0 && zprim >= 0; z--, zprim--) {
								if (Board[z][zprim] > 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}
							}
							//south-west
							for (int z = i + 1, zprim = j - 1; z <= 7 && zprim >= 0; z++, zprim--) {
								if (Board[z][zprim] > 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}

							}
							//south-east
							for (int z = i + 1, zprim = j + 1; z <= 7 && zprim <= 7; z++, zprim++) {
								if (Board[z][zprim] > 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}
							}
						}
						else if (abs(Board[i][j]) == 10 || abs(Board[i][j]) == 15 || (abs(Board[i][j]) % 100 == 10)) {
							//knights can attack at most 8 squares 
							//upward
							if (i - 2 >= 0) {
								if (j - 1 >= 0) {
									if (Board[i - 2][j - 1] == 0) {
										Board[i][j] = 0;
										Board[i - 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j - 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j - 1] = 0;
									}
									else if (Board[i - 2][j - 1] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 2][j - 1];
										Board[i - 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j - 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j - 1] = oppiece;
									}
								}
								if (j + 1 <= 7) {
									if (Board[i - 2][j + 1] == 0) {
										Board[i][j] = 0;
										Board[i - 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j + 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j + 1] = 0;
									}
									else if (Board[i - 2][j + 1] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 2][j + 1];
										Board[i - 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j + 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j + 1] = oppiece;
									}

								}
							}
							//down
							if (i + 2 <= 7) {
								if (j - 1 >= 0) {
									if (Board[i + 2][j - 1] == 0) {
										Board[i][j] = 0;
										Board[i + 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j - 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j - 1] = 0;
									}
									else if (Board[i + 2][j - 1] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 2][j - 1];
										Board[i + 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j - 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j - 1] = oppiece;
									}
								}
								if (j + 1 <= 7) {
									if (Board[i + 2][j + 1] == 0) {
										Board[i][j] = 0;
										Board[i + 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j + 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j + 1] = 0;
									}
									else if (Board[i + 2][j + 1] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 2][j + 1];
										Board[i + 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j + 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j + 1] = oppiece;
									}

								}
							}
							//right
							if (j + 2 <= 7) {
								if (i - 1 >= 0) {
									if (Board[i - 1][j + 2] == 0) {
										Board[i][j] = 0;
										Board[i - 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j + 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j + 2] = 0;
									}
									else if (Board[i - 1][j + 2] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 1][j + 2];
										Board[i - 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j + 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j + 2] = oppiece;
									}
								}
								if (i + 1 <= 7) {
									if (Board[i + 1][j + 2] == 0) {
										Board[i][j] = 0;
										Board[i + 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j + 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j + 2] = 0;
									}
									else if (Board[i + 1][j + 2] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 1][j + 2];
										Board[i + 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j + 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j + 2] = oppiece;
									}

								}
							}
							//left
							if (j - 2 >= 0) {
								if (i - 1 >= 0) {
									if (Board[i - 1][j - 2] == 0) {
										Board[i][j] = 0;
										Board[i - 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j - 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j - 2] = 0;
									}
									else if (Board[i - 1][j - 2] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 1][j - 2];
										Board[i - 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j - 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j - 2] = oppiece;
									}
								}
								if (i + 1 <= 7) {
									if (Board[i + 1][j - 2] == 0) {
										Board[i][j] = 0;
										Board[i + 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j - 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j - 2] = 0;
									}
									else if (Board[i + 1][j - 2] < 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 1][j - 2];
										Board[i + 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j - 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j - 2] = oppiece;
									}

								}
							}
                        }

					}
				}
			}


			return true;
		}
		else {
			return false;
		}
	}
	else {
		blacktomove = true;
		whitetomove = false;
		if (KingInDanger()) {
			int subs = blackKingxpos, subf = blackKingypos;
			for (int z = blackKingxpos - 1; z <= blackKingxpos + 1; z++) {
				for (int zprim = blackKingypos - 1; zprim <= blackKingypos + 1; zprim++) {
					if ((z > 0 && z <= 7) && (zprim > 0 && zprim <= 7) && Board[z][zprim] >= 0) {
						blackKingxpos = z;
						blackKingypos = zprim;
						if (!KingInDanger()) {
							blackKingxpos = subs;
							blackKingypos = subf;
							return false;
						}
						blackKingxpos = subs;
						blackKingypos = subf;
					}
				}
			}
			for (int i = 0; i <= 7; i++) {
				for (int j = 0; j <= 7; j++) {
					if (Board[i][j] < 0) {
						int subx = i, suby = j, piece = Board[i][j], oppiece;
						//check whether a pawn can save the king
						if (abs(Board[i][j]) <= 8 && i+1<=7) {

							if (Board[i + 1][j] == 0) {
								Board[i][j] = 0;
								Board[i + 1][j] = piece;
								if (!KingInDanger()) {

									Board[i][j] = piece;
									Board[i + 1][j] = 0;
									return false;
								}
								Board[i][j] = piece;
								Board[i + 1][j] = 0;
							}
							if (i == 1) {
								if (Board[i + 2][j] == 0) {
									Board[i][j] = 0;
									Board[i + 2][j] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i + 2][j] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[i + 2][j] = 0;
								}
							}
							if (Board[i + 1][j + 1] < 0 || Board[i + 1][j - 1] < 0) {
								if (Board[i + 1][j + 1] < 0) {
									Board[i][j] = 0;
									oppiece = Board[i + 1][j + 1];
									Board[i + 1][j + 1] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i + 1][j + 1] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[i + 1][j + 1] = oppiece;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[i + 1][j - 1];
									Board[i + 1][j - 1] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[i + 1][j - 1] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[i + 1][j - 1] = oppiece;

								}
							}
						}
						else if (abs(Board[i][j]) == 13 || abs(Board[i][j]) == 9 || abs(Board[i][j]) == 16 || abs(Board[i][j]) == 11 || abs(Board[i][j]) == 14 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 9) || (abs(Board[i][j]) % 100 == 11)) {
							//queen can defend vertically like a rook and also horizontally ///Going down
							if (abs(Board[i][j]) == 13 || abs(Board[i][j]) == 9 || abs(Board[i][j]) == 16 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 9)) {
								for (int z = i + 1; z <= 7; z++) {
									if (Board[z][j] < 0) {
										break;
									}
									else if (Board[z][j] == 0) {
										Board[i][j] = 0;
										Board[z][j] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[z][j] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[z][j] = 0;
									}
									else {
										Board[i][j] = 0;
										oppiece = Board[z][j];
										Board[z][j] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[z][j] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[z][j] = oppiece;
										break;
									}
								}
								//going up
								for (int z = i - 1; z >= 0; z--) {
									if (Board[z][j] < 0) {
										break;
									}
									else if (Board[z][j] == 0) {
										Board[i][j] = 0;
										Board[z][j] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[z][j] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[z][j] = 0;
									}
									else {
										Board[i][j] = 0;
										oppiece = Board[z][j];
										Board[z][j] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[z][j] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[z][j] = oppiece;
										break;
									}
								}
								//going right or left
								for (int z = j + 1; z <= 7; z++) {
									if (Board[i][z] < 0) {
										break;
									}
									else if (Board[i][z] == 0) {
										Board[i][j] = 0;
										Board[i][z] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i][z] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i][z] = 0;
									}
									else {
										Board[i][j] = 0;
										oppiece = Board[i][z];
										Board[i][z] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i][z] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i][z] = oppiece;
										break;
									}
								}
								//going left
								for (int z = j - 1; z >= 0; z--) {
									if (Board[i][z] < 0) {
										break;
									}
									else if (Board[i][z] == 0) {
										Board[i][j] = 0;
										Board[i][z] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i][z] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i][z] = 0;
									}
									else {
										Board[i][j] = 0;
										oppiece = Board[i][z];
										Board[i][z] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i][z] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i][z] = oppiece;
										break;
									}
								}
							}

						}
						//now bishops and queens can move diagonally
						if (abs(Board[i][j]) == 13 || abs(Board[i][j]) == 11 || abs(Board[i][j]) == 14 || (abs(Board[i][j]) % 100 == 13) || (abs(Board[i][j]) % 100 == 11)) {
							//north-east
							for (int z = i - 1, zprim = j + 1; z >= 0 && zprim <= 7; z--, zprim++) {
								if (Board[z][zprim] < 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}
							}
							//north-west
							for (int z = i - 1, zprim = j - 1; z >= 0 && zprim >= 0; z--, zprim--) {
								if (Board[z][zprim] < 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}
							}
							//south-west
							for (int z = i + 1, zprim = j - 1; z <= 7 && zprim >= 0; z++, zprim--) {
								if (Board[z][zprim] < 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}

							}
							//south-east
							for (int z = i + 1, zprim = j + 1; z <= 7 && zprim <= 7; z++, zprim++) {
								if (Board[z][zprim] < 0) {
									break;
								}
								else if (Board[z][zprim] == 0) {
									Board[i][j] = 0;
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = 0;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = 0;
								}
								else {
									Board[i][j] = 0;
									oppiece = Board[z][zprim];
									Board[z][zprim] = piece;
									if (!KingInDanger()) {
										Board[i][j] = piece;
										Board[z][zprim] = oppiece;
										return false;
									}
									Board[i][j] = piece;
									Board[z][zprim] = oppiece;
									break;
								}
							}
						}
						else if (abs(Board[i][j]) == 10 || abs(Board[i][j]) == 15 || (abs(Board[i][j]) % 100 == 10)) {
							//knights can attack at most 8 squares 
							//upward
							if (i - 2 >= 0) {
								if (j - 1 >= 0) {
									if (Board[i - 2][j - 1] == 0) {
										Board[i][j] = 0;
										Board[i - 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j - 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j - 1] = 0;
									}
									else if (Board[i - 2][j - 1] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 2][j - 1];
										Board[i - 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j - 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j - 1] = oppiece;
									}
								}
								if (j + 1 <= 7) {
									if (Board[i - 2][j + 1] == 0) {
										Board[i][j] = 0;
										Board[i - 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j + 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j + 1] = 0;
									}
									else if (Board[i - 2][j + 1] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 2][j + 1];
										Board[i - 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 2][j + 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 2][j + 1] = oppiece;
									}

								}
							}
							//down
							if (i + 2 <= 7) {
								if (j - 1 >= 0) {
									if (Board[i + 2][j - 1] == 0) {
										Board[i][j] = 0;
										Board[i + 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j - 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j - 1] = 0;
									}
									else if (Board[i + 2][j - 1] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 2][j - 1];
										Board[i + 2][j - 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j - 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j - 1] = oppiece;
									}
								}
								if (j + 1 <= 7) {
									if (Board[i + 2][j + 1] == 0) {
										Board[i][j] = 0;
										Board[i + 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j + 1] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j + 1] = 0;
									}
									else if (Board[i + 2][j + 1] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 2][j + 1];
										Board[i + 2][j + 1] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 2][j + 1] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 2][j + 1] = oppiece;
									}

								}
							}
							//right
							if (j + 2 <= 7) {
								if (i - 1 >= 0) {
									if (Board[i - 1][j + 2] == 0) {
										Board[i][j] = 0;
										Board[i - 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j + 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j + 2] = 0;
									}
									else if (Board[i - 1][j + 2] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 1][j + 2];
										Board[i - 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j + 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j + 2] = oppiece;
									}
								}
								if (i + 1 <= 7) {
									if (Board[i + 1][j + 2] == 0) {
										Board[i][j] = 0;
										Board[i + 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j + 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j + 2] = 0;
									}
									else if (Board[i + 1][j + 2] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 1][j + 2];
										Board[i + 1][j + 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j + 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j + 2] = oppiece;
									}

								}
							}
							//left
							if (j - 2 >= 0) {
								if (i - 1 >= 0) {
									if (Board[i - 1][j - 2] == 0) {
										Board[i][j] = 0;
										Board[i - 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j - 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j - 2] = 0;
									}
									else if (Board[i - 1][j - 2] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i - 1][j - 2];
										Board[i - 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i - 1][j - 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i - 1][j - 2] = oppiece;
									}
								}
								if (i + 1 <= 7) {
									if (Board[i + 1][j - 2] == 0) {
										Board[i][j] = 0;
										Board[i + 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j - 2] = 0;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j - 2] = 0;
									}
									else if (Board[i + 1][j - 2] > 0) {
										Board[i][j] = 0;
										oppiece = Board[i + 1][j - 2];
										Board[i + 1][j - 2] = piece;
										if (!KingInDanger()) {
											Board[i][j] = piece;
											Board[i + 1][j - 2] = oppiece;
											return false;
										}
										Board[i][j] = piece;
										Board[i + 1][j - 2] = oppiece;
									}

								}
							}
						}

					}
				}
			}


			return true;
		}
		else {
			return false;
		}

	}
}
int Transformation(int x) {
	int chosenpiece;
	sf::Vector2u v1(120,410);
	sf::RenderWindow window(sf::VideoMode(v1), "Transformation");
	sf::Sprite back;
	sf::Texture background;
	background.loadFromFile("Images\\Chess\\1x\\Asset 10.png");
	back.setTexture(background);
	window.draw(back);
	sf::Sprite op1;
	sf::Sprite op2;
	sf::Sprite op3;
	sf::Sprite op4;
	sf::Texture queen;
	sf::Texture bishop;
	sf::Texture rook;
	sf::Texture knight;
	if (x == 0) {
		chosenpiece = 13;
		queen.loadFromFile("Images\\w_queen.png");
		bishop.loadFromFile("Images\\w_bishop.png");
		rook.loadFromFile("Images\\w_rook.png");
		knight.loadFromFile("Images\\w_knight.png");
	}
	else if(x==1) {
		chosenpiece = -13;
		queen.loadFromFile("Images\\b_queen.png");
		bishop.loadFromFile("Images\\b_bishop.png");
		rook.loadFromFile("Images\\b_rook.png");
		knight.loadFromFile("Images\\b_knight.png");
	}
	op1.setTexture(queen);
	op2.setTexture(rook);
	op3.setTexture(bishop);
	op4.setTexture(knight);
	op1.setScale(piece_scale);
	op2.setScale(piece_scale);
	op3.setScale(piece_scale);
	op4.setScale(piece_scale);
	sf::Vector2f option1(8, 5);
	sf::Vector2f option2(15, 105);
	sf::Vector2f option3(15, 205);
	sf::Vector2f option4(15, 305);
	op1.setPosition(option1);
	op2.setPosition(option2);
	op3.setPosition(option3);
	op4.setPosition(option4);
	window.draw(op1);
	window.draw(op2);
	window.draw(op3);
	window.draw(op4);
	window.display();
	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			if (event.type == sf::Event::Closed) {
				window.close();
			}
			else if (event.type == sf::Event::MouseButtonPressed) {
				if (event.mouseButton.button == sf::Mouse::Left) {
					sf::Vector2i mousePos = sf::Mouse::getPosition(window);
					sf::Vector2f sit(mousePos.x, mousePos.y);
					if (op1.getGlobalBounds().contains(sit)) {
						window.close();
					}
					else if (op2.getGlobalBounds().contains(sit)) {
						if (x == 0) {
							chosenpiece = 9;
							window.close();
						}
						else {
							chosenpiece = -9;
							window.close();
						}
					}
					else if (op3.getGlobalBounds().contains(sit)) {
						if (x == 0) {
							chosenpiece = 11;
							window.close();
						}
						else {
							chosenpiece = -11;
							window.close();
						}
					}
					else if (op4.getGlobalBounds().contains(sit)) {
						if (x == 0) {
							chosenpiece = 10;
							window.close();
						}
						else {
							chosenpiece = -10;
							window.close();
						}
					}

				}
			}
		}
	}
	
	

	return chosenpiece;
}
