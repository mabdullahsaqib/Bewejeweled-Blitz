#include<iostream>
#include<conio.h>
#include<time.h>
#include"Help.h"
using namespace std;
void DestroyerGemExplosion(int board[][8], int row, int col);
//This function prints the current time and score on screen, we call it repeatedly so the score always stays updates on screen.
void printTime(int& starttime, int& score)
{
	if (time(0) - starttime <= 60)
		cout << time(0) - starttime << "  " << score << "\r";
}
//This function prints a gem at the specified coordinates based on the value given, shape of gems can be easily customized
void Gem(int x, int y, int boardvalue)
{
	if (boardvalue == 0 || boardvalue == 1 || boardvalue == 2)//Orange gemstone for 0, special gemstone for 1, destroyer gemstone for 2
	{
		if (boardvalue == 1)
			myRectangle(x - 1, y - 1, x + 31, y + 31, 255, 255, 255);
		else if (boardvalue == 2)
			myRectangle(x - 5, y - 5, x + 35, y + 35, 255, 0, 0);
		for (int i = 0; i <= 5; i++)
			myLine(x + 5 - i, y + i, x + 15, y + i, 255, 220, 130, 1);
		for (int i = 0; i <= 5; i++)
			myLine(x + 15, y + i, x + 25 + i, y + i, 255, 184, 0, 1);
		for (int i = 5, j = 0; i >= 0; j++, i--)
			myLine(x + 5 - i, y + 25 + j, x + 25 + i, y + 25 + j, 255, 184, 0, 1);
		myRectangle(x + 1, y + 6, x + 30, y + 25, 255, 255, 181);
		myRectangle(x + 1, y + 6, x + 5, y + 25, 255, 220, 130);
		myRectangle(x + 26, y + 6, x + 30, y + 25, 199, 153, 0);
		myRectangle(x + 6, y + 1, x + 25, y + 5, 255, 220, 130);
		myRectangle(x + 6, y + 26, x + 25, y + 31, 195, 120, 0);
	}
	else if (boardvalue == 3 || boardvalue == 4 || boardvalue == 5)//Pink square gemstone
	{
		if (boardvalue == 4)
			myRectangle(x - 3, y - 3, x + 33, y + 33, 255, 0, 255);
		else if (boardvalue == 5)
			myRectangle(x - 5, y - 5, x + 35, y + 35, 255, 0, 0);
		myRectangle(x + 15, y, x + 30, y + 30, 255, 100, 255);
		myRectangle(x, y, x + 15, y + 30, 255, 170, 255);
		myRectangle(x + 4, y + 3, x + 26, y + 26, 255, 230, 255);
		for (int i = 0, j = 0; i < 5; i++, j++)
			myLine(x + i - 1, y + j - 1, x + 30 - i, y + j - 1, 255, 200, 255, 1);
		for (int i = 0, j = 27; i < 5; i++, j++)
			myLine(x + 3 - i, y + j - 1, x + 26 + i, y + j - 1, 255, 0, 255, 1);
	}
	else if (boardvalue == 6 || boardvalue == 7 || boardvalue == 8)//Red Circular Gemstone
	{
		if (boardvalue == 7)
			myRectangle(x - 1, y - 1, x + 31, y + 31, 255, 255, 255);
		else if (boardvalue == 8)
			myRectangle(x - 5, y - 5, x + 35, y + 35, 255, 0, 0);
		myEllipse(x, y, x + 30, y + 30, 255, 0, 0);
		myEllipse(x + 4, y + 4, x + 28, y + 28, 150, 0, 0);
		myEllipse(x + 3, y + 3, x + 25, y + 25, 255, 0, 0);
		myEllipse(x + 5, y + 5, x + 15, y + 16, 255, 142, 142);
	}
	else if (boardvalue == 9 || boardvalue == 10 || boardvalue == 11)//Green Circular Gemstone
	{
		if (boardvalue == 10)
			myRectangle(x - 1, y - 1, x + 31, y + 31, 255, 255, 255);
		else if (boardvalue == 11)
			myRectangle(x - 5, y - 5, x + 35, y + 35, 255, 0, 0);
		myEllipse(x, y, x + 30, y + 30, 0, 255, 0);
		myEllipse(x + 4, y + 4, x + 28, y + 28, 0, 150, 0);
		myEllipse(x + 3, y + 3, x + 25, y + 25, 0, 255, 0);
		myEllipse(x + 5, y + 5, x + 15, y + 16, 142, 255, 142);
	}
	else if (boardvalue == 12 || boardvalue == 13 || boardvalue == 14)//Cyan Triangular Gemstone
	{
		if (boardvalue == 13)
			myRectangle(x - 1, y - 1, x + 31, y + 31, 255, 255, 255);
		else if (boardvalue == 14)
			myRectangle(x - 5, y - 5, x + 35, y + 35, 255, 0, 0);
		for (int i = 0, j = 30; i <= 15; i++, j -= 2)
			myLine(x + i, y + j, x + 15, y + j, 220, 255, 255, 2);
		for (int i = 0, j = 30; i <= 15; i++, j -= 2)
			myLine(x + 15, y + j, x + 30 - i, y + j, 0, 255, 255, 2);
		for (int i = 0, j = 30; i <= 3; i++, j--)
			myLine(x + (i * 2), y + j, x + 30 - (i * 2), y + j, 0, 150, 150, 1);
		for (int i = 0, j = 20; i <= 7; i++, j -= 2)
			myLine(x + i + 7, y + j + 6, x + 23 - i, y + j + 6, 150, 255, 255, 2);
	}
	else if (boardvalue >= 16)//Empty space
	{
		myRectangle(x, y, x + 30, y + 30, 0, 0, 255);
	}
}
void SpecialGemExplosion(int board[][8], int row, int col) //This is used for the special gem to explode, we use if conditions to avoid bound errors and recursion to trigger explosions of Gems within the explosion radius of the 1st gem
{
	board[row][col] = 18;
	if (row != 7)
	{
		if (board[row + 1][col] % 3 == 1)
			SpecialGemExplosion(board, row + 1, col);
		else if (board[row + 1][col] % 3 == 2)
			DestroyerGemExplosion(board, row + 1, col);
		board[row + 1][col] = 18;
	}
	if (row != 0)
	{
		if (board[row - 1][col] % 3 == 1)
			SpecialGemExplosion(board, row - 1, col);
		else if (board[row - 1][col] % 3 == 2)
			DestroyerGemExplosion(board, row - 1, col);
		board[row - 1][col] = 18;
	}
	if (col != 7)
	{
		if (board[row][col + 1] % 3 == 1)
			SpecialGemExplosion(board, row, col + 1);
		else if (board[row][col + 1] % 3 == 2)
			DestroyerGemExplosion(board, row, col + 1);
		board[row][col + 1] = 18;
	}
	if (col != 0)
	{
		if (board[row][col - 1] % 3 == 1)
			SpecialGemExplosion(board, row, col - 1);
		if (board[row][col - 1] % 3 == 2)
			DestroyerGemExplosion(board, row, col - 1);
		board[row][col - 1] = 18;
	}
	if (row != 7 && col != 7)
	{
		if (board[row + 1][col + 1] % 3 == 1)
			SpecialGemExplosion(board, row + 1, col + 1);
		if (board[row + 1][col + 1] % 3 == 2)
			DestroyerGemExplosion(board, row + 1, col + 1);
		board[row + 1][col + 1] = 18;
	}
	if (row != 0 && col != 0)
	{
		if (board[row - 1][col - 1] % 3 == 1)
			SpecialGemExplosion(board, row - 1, col - 1);
		if (board[row - 1][col - 1] % 3 == 2)
			DestroyerGemExplosion(board, row - 1, col - 1);
		board[row - 1][col - 1] = 18;
	}
	if (row != 7 && col != 0)
	{
		if (board[row + 1][col - 1] % 3 == 1)
			SpecialGemExplosion(board, row + 1, col - 1);
		if (board[row + 1][col - 1] % 3 == 2)
			DestroyerGemExplosion(board, row + 1, col - 1);
		board[row + 1][col - 1] = 18;
	}
	if (row != 0 && col != 7)
	{
		if (board[row - 1][col + 1] % 3 == 1)
			SpecialGemExplosion(board, row - 1, col + 1);
		if (board[row - 1][col + 1] % 3 == 2)
			DestroyerGemExplosion(board, row - 1, col + 1);
		board[row - 1][col + 1] = 18;
	}
}
void DestroyerGemExplosion(int board[][8], int row, int col)//The destroyer gem does not need as many conditions as the special gem as it only needs to destroy gems within its rows and columns
{
	board[row][col] = 18;
	for (int i = 0; i < 8; i++)
	{
		if (board[row][i] % 3 == 1 && board[i][col] < 16)
			SpecialGemExplosion(board, row, i);
		else if (board[row][i] % 3 == 2 && board[row][i] < 16)
			DestroyerGemExplosion(board, row, i);
		else
			board[row][i] = 18;
	}
	for (int i = 0; i < 8; i++)
	{
		if (board[i][col] % 3 == 1 && board[i][col] < 16)
			SpecialGemExplosion(board, i, col);
		else if (board[i][col] % 3 == 2 && board[i][col] < 16)
			DestroyerGemExplosion(board, i, col);
		else
			board[i][col] = 18;
	}
}
void SetSpecialGem(int board[][8], int row, int col, int gemtype)
{
	board[row][col] = gemtype + 1;
}
void SetDestroyerGem(int board[][8], int row, int col, int gemtype)
{
	board[row][col] = gemtype + 2;
}
void CheckerPattern()
{
	//This function prints a checker pattern so we dont have to reprint the full board everytime. This reduces flickering of the gems
	for (int i = 550; i <= 965; i += 50)
		myRectangle(i + 1, 61, i + 9, 469, 255, 255, 255);
	for (int i = 60; i <= 965; i += 50)
		myRectangle(551, i + 1, 959, i + 9, 255, 255, 255);
}
int CheckforElbow(int board[][8])
{
	int elbowcheck = 0;
	int i = 0, j = 0;
	//This function first checks if there is an "elbow" occuring anywhere in the board i.e. 3,4,5, in a row and column with a common element at the corner. If
	//There is an elbow we set the elbow to a destroyer gem ,replace the rest with empty squares return 1 or 0 based on wether an elbow was present
	//Elbowcheck variable is given value 1,2,3,4 to specify which type of elbow shaped formation we are dealing with
	for (i = 0; i < 8 && elbowcheck == 0; i++)
		for (j = 0; j < 8 && elbowcheck == 0; j++)
		{
			if (i < 6 && j < 6)
			{
				if (((board[i][j] / 3) == (board[i][j + 1] / 3) && (board[i][j + 1] / 3) == (board[i][j + 2]) / 3) && ((board[i][j] / 3) == (board[i + 1][j] / 3) && (board[i + 1][j] / 3) == (board[i + 2][j] / 3)) && board[i][j] < 16)
					elbowcheck = 1;
			}
			if (i > 1 && j > 1)
			{
				if (((board[i][j] / 3) == (board[i][j - 1] / 3) && (board[i][j - 1] / 3) == (board[i][j - 2] / 3)) && ((board[i][j] / 3) == (board[i - 1][j] / 3) && (board[i - 1][j] / 3) == (board[i - 2][j] / 3)) && board[i][j] < 16)
					elbowcheck = 2;
			}
			if (i < 6 && j >1)
			{
				if (((board[i][j] / 3) == (board[i][j - 1] / 3) && (board[i][j - 1] / 3) == (board[i][j - 2] / 3)) && ((board[i][j] / 3) == (board[i + 1][j] / 3) && (board[i + 1][j] / 3) == (board[i + 2][j] / 3)) && board[i][j] < 16)
					elbowcheck = 3;
			}
			if (i > 1 && j < 6)
			{
				if (((board[i][j] / 3) == (board[i][j + 1] / 3) && (board[i][j + 1] / 3) == (board[i][j + 2]) / 3) && ((board[i][j] / 3) == (board[i - 1][j] / 3) && (board[i - 1][j] / 3) == (board[i - 2][j] / 3)) && board[i][j] < 16)
					elbowcheck = 4;
			}
		}
	i--;
	j--;
	if (elbowcheck == 1)
	{
		if (board[i][j] % 3 == 0)
			SetDestroyerGem(board, i, j, board[i][j]);
		else if (board[i][j] % 3 == 1)
			SpecialGemExplosion(board, i, j);
		board[i][j + 1] = 17;
		board[i][j + 2] = 18;
		board[i + 1][j] = 19;
		board[i + 2][j] = 20;
		return 1;
	}
	else if (elbowcheck == 2)
	{
		if (board[i][j] % 3 == 0)
			SetDestroyerGem(board, i, j, board[i][j]);
		else if (board[i][j] % 3 == 1)
			SpecialGemExplosion(board, i, j);
		board[i][j - 1] = 17;
		board[i][j - 2] = 18;
		board[i - 1][j] = 19;
		board[i - 2][j] = 20;
		return 1;
	}
	else if (elbowcheck == 3)
	{
		if (board[i][j] % 3 == 0)
			SetDestroyerGem(board, i, j, board[i][j]);
		else if (board[i][j] % 3 == 1)
			SpecialGemExplosion(board, i, j);
		board[i][j - 1] = 17;
		board[i][j - 2] = 18;
		board[i + 1][j] = 19;
		board[i + 2][j] = 20;
		return 1;
	}
	else if (elbowcheck == 4)
	{
		if (board[i][j] % 3 == 0)
			SetDestroyerGem(board, i, j, board[i][j]);
		else if (board[i][j] % 3 == 1)
			SpecialGemExplosion(board, i, j);
		board[i][j + 1] = 17;
		board[i][j + 2] = 18;
		board[i - 1][j] = 19;
		board[i - 2][j] = 20;
		return 1;
	}
	return 0;
}
int CheckforMatch(int board[][8], int& rowtilecheck, int& columntilecheck)
{
	//This function checks for 3,4,5, in a row and sets them to empty while returning 1 if there were matches and 0 if there were not.
	//we also need to check them seperately if they are near the border or not otherwise we run into logical bound errors.
	bool Matchfound = 0;
	CheckforElbow(board);
	//First we check for 5's then 4's then 3's
	for (int i = 0; i < 8 && rowtilecheck == 0 && columntilecheck == 0; i++)
		for (int j = 0; j < 8 && rowtilecheck == 0 && columntilecheck == 0; j++)
		{
			if (i > 3)
			{
				if ((board[i][j] / 3) == (board[i - 1][j] / 3) && (board[i - 1][j] / 3) == (board[i - 2][j] / 3) && (board[i - 2][j] / 3) == (board[i - 3][j] / 3) && (board[i - 3][j] / 3) == (board[i - 4][j] / 3) && board[i][j] < 16)
				{
					for (int k = 0; k < 5; k++)
					{
						if (board[i - k][j] % 3 == 1)
							SpecialGemExplosion(board, i - k, j);
						else if (board[i - k][j] % 3 == 2)
							DestroyerGemExplosion(board, i - k, j);
					}
					columntilecheck = 1;
					board[i][j] = 16;
					board[i - 1][j] = 17;
					board[i - 2][j] = 18;
					board[i - 3][j] = 19;
					board[i - 4][j] = 20;
					Matchfound = 1;
				}
			}
			if (j > 3)
			{
				if ((board[i][j] / 3) == (board[i][j - 1] / 3) && (board[i][j - 1] / 3) == (board[i][j - 2] / 3) && (board[i][j - 2] / 3) == (board[i][j - 3] / 3) && (board[i][j - 3] / 3) == (board[i][j - 4] / 3) && board[i][j] < 16)
				{
					for (int k = 0; k < 5; k++)
					{
						if (board[i][j - k] % 3 == 1)
							SpecialGemExplosion(board, i, j - k);
						else if (board[i][j - k] % 3 == 2)
							DestroyerGemExplosion(board, i, j - k);
					}
					rowtilecheck = 1;
					board[i][j] = 16;
					board[i][j - 1] = 17;
					board[i][j - 2] = 18;
					board[i][j - 3] = 19;
					board[i][j - 4] = 20;
					Matchfound = 1;
				}
			}
		}
	//Now we check for 4's
	for (int i = 0; i < 8 && rowtilecheck == 0 && columntilecheck == 0; i++)
		for (int j = 0; j < 8 && rowtilecheck == 0 && columntilecheck == 0; j++)
		{
			if (i > 2)
			{
				if ((board[i][j] / 3) == (board[i - 1][j] / 3) && (board[i - 1][j] / 3) == (board[i - 2][j] / 3) && (board[i - 2][j] / 3) == (board[i - 3][j] / 3) && board[i][j] < 16)
				{
					for (int k = 0; k < 4; k++)
					{
						if (board[i - k][j] % 3 == 1)
							SpecialGemExplosion(board, i - k, j);
						else if (board[i - k][j] % 3 == 2)
							DestroyerGemExplosion(board, i - k, j);
					}
					columntilecheck = 1;
					if (board[i][j] % 3 == 0)
						SetSpecialGem(board, i, j, board[i][j]);
					board[i - 1][j] = 17;
					board[i - 2][j] = 18;
					board[i - 3][j] = 19;
					Matchfound = 1;
				}
			}
			if (j > 2)
			{
				if ((board[i][j] / 3) == (board[i][j - 1] / 3) && (board[i][j - 1] / 3) == (board[i][j - 2] / 3) && (board[i][j - 2] / 3) == (board[i][j - 3] / 3) && board[i][j] < 16)
				{
					for (int k = 0; k < 4; k++)
					{
						if (board[i][j - k] % 3 == 1)
							SpecialGemExplosion(board, i, j - k);
						else if (board[i][j - k] % 3 == 2)
							DestroyerGemExplosion(board, i, j - k);
					}
					rowtilecheck = 1;
					if (board[i][j] == 0 || board[i][j] == 3 || board[i][j] == 6 || board[i][j] == 9 || board[i][j] == 12)
						SetSpecialGem(board, i, j, board[i][j]);
					board[i][j - 1] = 17;
					board[i][j - 2] = 18;
					board[i][j - 3] = 19;
					Matchfound = 1;
				}
			}
		}
	//Now 3's
	for (int i = 0; i < 8 && rowtilecheck == 0 && columntilecheck == 0; i++)
		for (int j = 0; j < 8 && rowtilecheck == 0 && columntilecheck == 0; j++)
		{
			if (i > 1)
			{
				if ((board[i][j] / 3) == (board[i - 1][j] / 3) && (board[i - 1][j] / 3) == (board[i - 2][j] / 3) && board[i][j] < 16)
				{
					for (int k = 0; k < 3; k++)
					{
						if (board[i - k][j] % 3 == 1)
							SpecialGemExplosion(board, i - k, j);
						else if (board[i - k][j] % 3 == 2)
							DestroyerGemExplosion(board, i - k, j);
					}
					columntilecheck = 1;
					board[i][j] = 16;
					board[i - 1][j] = 17;
					board[i - 2][j] = 18;
					Matchfound = 1;
				}
			}
			if (j > 1)
			{
				if ((board[i][j] / 3) == (board[i][j - 1] / 3) && (board[i][j - 1] / 3) == (board[i][j - 2] / 3) && board[i][j] < 16)
				{
					for (int k = 0; k < 3; k++)
					{
						if (board[i][j - k] % 3 == 1)
							SpecialGemExplosion(board, i, j - k);
						else if (board[i][j - k] % 3 == 2)
							DestroyerGemExplosion(board, i, j - k);
					}
					rowtilecheck = 1;
					board[i][j] = 16;
					board[i][j - 1] = 17;
					board[i][j - 2] = 18;
					Matchfound = 1;
				}
			}
		}
	return Matchfound;
}

void Tiles(int board[][8])
{
	//This function reprints the tiles based on value of board array every time a change is made
	CheckerPattern();
	for (int i = 70, k = 0; i <= 420 && k < 8; i += 50, k++)
		for (int j = 560, l = 0; j <= 910 && l < 8; j += 50, l++)
		{
			myRectangle(j, i, j + 40, i + 40, 0, 0, 255);
			Gem(j + 5, i + 5, board[k][l]);
		}
}
void SelectionRectangle(int x1, int y1, int x2, int y2, int R, int G, int B)
{
	//This function prints the selection rectangle at the specified coordinates
	int width = 5;
	myLine(x1, y1, x2, y1, R, G, B, width);
	myLine(x1, y1, x1, y2, R, G, B, width);
	myLine(x1, y2, x2, y2, R, G, B, width);
	myLine(x2, y1, x2, y2, R, G, B, width);
}
int Dropcolumns(int board[][8], int& score, int& timestart)
{
	//This function drops columns by first looking for an empty cell. It stores index values of the cell
	//and then swaps the cell with the cell above it in a loop so the empty cell comes to the top
	//The empty cell at the top is then assigned a random value that can be either 0,3,6,9 or 12.
	//The function keeps running until there are no empty boxes left in the board
	bool emptycheck = 0;//Used to check if a specific cell is empty
	bool emptyboard = 1;//Used to check if there is any empty cell at all in the board;
	bool didDrop = 0;//Used to check if any empty spaces were swapped. We can reduce the amount of times we need to reprint by using this variable
	int rowindex = 0, columnindex = 0;//Stores rowindex and columnindex of empty cell for later swapping
	while (emptyboard != 0)
	{
		emptycheck = 0;
		emptyboard = 0;
		rowindex = 0;
		columnindex = 0;
		for (int i = 0; i < 8 && emptycheck == 0; i++)
			for (int j = 0; j < 8 && emptycheck == 0; j++)
			{
				if (board[i][j] >= 16)
				{
					emptycheck = 1;
					rowindex = i;
					columnindex = j;
				}
			}
		int x = rowindex;
		if (emptycheck == 1)
		{
			for (int i = 0; i < x; i++, rowindex--)
			{
				swap(board[rowindex][columnindex], board[rowindex - 1][columnindex]);
				didDrop = 1;
			}
			score += 60;
			board[0][columnindex] = (rand() % 5) * 3;
		}
		for (int i = 0; i < 8; i++)
			for (int j = 0; j < 8; j++)
				if (board[i][j] >= 16)
					emptyboard=1;
	}
	return didDrop;
	printTime(timestart, score);
}
void reversemove(int board[][8], int userinput, int r, int c)
{
	//This function reverses a move if it did not match 3 in a row or column
	if (userinput == 1)
		swap(board[r][c], board[r][c - 1]);
	else if (userinput == 2)
		swap(board[r][c], board[r - 1][c]);
	else if (userinput == 3)
		swap(board[r][c], board[r][c + 1]);
	else if (userinput == 4)
		swap(board[r][c], board[r + 1][c]);
}

void Movecandy(int board[][8], int userinput, int x, int y, int& time, int& score)
{
	//This function moves a candy by swapping it up,down,left,or right based on user input.
	int r = 10, c = 10;
	int check = 0;
	for (int i = 65, k = 0; i <= 415 && k < 8; i += 50, k++)
		for (int j = 555, l = 0; j <= 905 && l < 8; j += 50, l++)
		{
			if (i == y && j == x)
			{
				if (userinput == 1)
					swap(board[k][l], board[k][l - 1]);
				else if (userinput == 2)
					swap(board[k][l], board[k - 1][l]);
				else if (userinput == 3)
					swap(board[k][l], board[k][l + 1]);
				else if (userinput == 4)
					swap(board[k][l], board[k + 1][l]);
				r = k;
				c = l;
			}
		}
	//We then reprint board, check for 3 in a row again and undo the move if there are none
	Tiles(board);
	SelectionRectangle(x, y, x + 50, y + 50, 0, 0, 0);
	printTime(time, score);
	Sleep(100);
	if (CheckforMatch(board, check, check) == 0)
	{
		reversemove(board, userinput, r, c);
		printTime(time, score);
		Sleep(100);
	}
}

int main()
{
	srand(time(0));
	bool isenterpressed = 0, waitforkey = 0, iselbowpresent = 0, preventerpressed = 1;
	int board[8][8], columntilecheck = 0, rowtilecheck = 0, emptycheck = 0, rowindex = 5, columnindex = 5, userinput = 0, timestart = 0, timeend = 0, score = 0;
	int selectionrectx = 555, selectionrecty = 65;
	for (int i = 0; i < 8; i++)                                     //We use the rand function to populate the board with random integers 0,3,6,9,12 during the beginning of the game
		for (int j = 0; j < 8; j++)
			board[i][j] = (rand() % 5) * 3;
	//Background
	myRectangle(0, 0, 1920, 1080, 0, 255, 255);
	myRectangle(540, 0, 1000, 600, 102, 51, 0);
	myRectangle(560, 10, 945, 50, 51, 20, 0);
	myRectangle(0, 400, 540, 600, 255, 255, 0);
	//This code is used to print the character
	{
		//cape
		myEllipse(420, 120, 440, 320, 255, 0, 0);
		myEllipse(330, 120, 350, 320, 255, 0, 0);
		myEllipse(335, 180, 433, 340, 0, 0, 255);
		//lower belly
		myEllipse(345, 180, 425, 290, 20, 56, 160);
		//Waist
		myRectangle(340, 120, 430, 220, 240, 0, 0);
		//Belt
		myEllipse(345, 210, 425, 290, 20, 56, 160);
		//cape
		myEllipse(300, 270, 480, 420, 0, 255, 255);
		myLine(345, 120, 338, 240, 0, 0, 255, 3);
		myLine(418, 120, 425, 240, 0, 0, 255, 5);
		myEllipse(418, 120, 435, 150, 0, 0, 255);
		//corlar
		myLine(405, 127, 380, 150, 240, 240, 240, 20);
		myLine(355, 130, 380, 150, 240, 240, 240, 20);
		myLine(353, 125, 408, 125, 240, 240, 240, 15);
		//head
		myEllipse(360, 90, 400, 120, 255, 206, 180);
		myEllipse(365, 20, 410, 120, 255, 206, 180);
		myEllipse(360, 20, 420, 40, 240, 160, 0);
		myEllipse(355, 30, 380, 40, 240, 160, 0);
		myEllipse(390, 110, 380, 100, 255, 164, 0);
		myEllipse(385, 107, 370, 103, 255, 164, 0);
		myLine(375, 103, 370, 107, 255, 164, 0, 6);
		myLine(369, 102, 360, 105, 255, 164, 0, 8);
		myEllipse(390, 50, 395, 60, 60, 60, 60);
		myEllipse(375, 50, 380, 60, 60, 60, 60);
		myLine(390, 45, 400, 45, 240, 160, 0, 4);
		myLine(372, 45, 380, 45, 240, 160, 0, 4);
		//Smile
		myLine(373, 82, 377, 85, 0, 0, 0, 2);
		myLine(377, 85, 382, 87, 0, 0, 0, 2);
		myLine(382, 87, 390, 80, 0, 0, 0, 2);
		//tie
		myLine(382, 123, 380, 158, 20, 56, 120, 12);
		myLine(375, 121, 380, 130, 20, 56, 120, 10);
		myLine(390, 121, 380, 130, 20, 56, 120, 10);
		myLine(375, 121, 390, 121, 20, 56, 120, 10);
		//pattern
		myLine(346, 135, 342, 219, 255, 214, 20, 3);
		myLine(360, 147, 361, 215, 255, 214, 20, 3);
		myLine(395, 150, 394, 210, 255, 214, 20, 3);
		myLine(414, 133, 417, 220, 255, 214, 20, 3);
		myEllipse(372, 205, 392, 225, 255, 215, 0);
		//arm left
		myLine(335, 130, 300, 205, 255, 0, 0, 20);
		myLine(300, 205, 260, 150, 255, 0, 0, 20);
		myLine(250, 147, 270, 148, 0, 0, 255, 20);
		myLine(240, 130, 270, 131, 220, 220, 220, 20);
		myLine(223, 127, 272, 200, 0, 255, 255, 18);
		myLine(270, 125, 290, 160, 0, 255, 255, 18);
		myEllipse(327, 124, 343, 140, 255, 215, 0);
		myEllipse(290, 188, 310, 210, 255, 215, 0);
		myLine(335, 143, 315, 188, 255, 214, 20, 2);
		myLine(323, 143, 305, 182, 255, 214, 20, 2);
		myLine(265, 163, 284, 192, 255, 214, 20, 2);
		//hand left
		myEllipse(223, 80, 270, 125, 236, 188, 180);
		myLine(225, 79, 270, 79, 0, 255, 255, 25);
		myEllipse(245, 80, 280, 110, 0, 255, 255);
		myEllipse(250, 95, 270, 120, 230, 190, 180);
		myLine(230, 93, 228, 105, 0, 255, 255, 2);
		myLine(235, 93, 237, 107, 0, 255, 255, 2);
		//arm right
		myLine(435, 132, 470, 190, 255, 0, 0, 20);
		myLine(470, 190, 460, 290, 255, 0, 0, 20);
		myLine(455, 293, 467, 298, 0, 0, 255, 20);
		myLine(450, 308, 470, 315, 220, 220, 220, 20);
		myLine(444, 288, 440, 315, 0, 255, 255, 13);
		myLine(478, 288, 474, 320, 0, 255, 255, 15);
		myEllipse(428, 125, 445, 143, 255, 215, 0);
		myEllipse(460, 180, 480, 200, 255, 215, 0);
		myLine(437, 145, 459, 179, 255, 214, 20, 2);
		myLine(448, 145, 465, 170, 255, 214, 20, 2);
		myLine(468, 205, 459, 280, 255, 214, 20, 2);
		//hand right
		myEllipse(440, 320, 480, 370, 236, 188, 180);
		myLine(450, 327, 445, 360, 0, 255, 255, 15);
		myEllipse(435, 320, 465, 350, 230, 190, 180);
		myLine(463, 370, 465, 355, 0, 255, 255, 2);
		//legs
		myRectangle(355, 270, 385, 420, 20, 56, 160);
		myRectangle(390, 270, 420, 420, 20, 56, 160);
		myEllipse(350, 275, 365, 400, 0, 255, 255);
		myEllipse(408, 275, 430, 400, 0, 255, 255);
		myEllipse(365, 325, 385, 345, 255, 215, 0);
		myEllipse(389, 325, 409, 345, 255, 215, 0);
		//feet
		myEllipse(325, 400, 385, 430, 30, 30, 30);
		myEllipse(387, 400, 447, 430, 30, 30, 30);

	}
	//Board
	Tiles(board);
	timestart = time(0);        //We use the timestart and timeend variables to make the loop run for exactly 1 minute giving us 1 minute to play the game
	while (time(0) - timestart <= 60)                               //Loop runs for 1 minute and is used to exit the game
	{
		printTime(timestart, score);
		rowtilecheck = 0;
		columntilecheck = 0;
		emptycheck = 0;
		waitforkey = 0;                                               //We check for any elbows first, if no elbows then check for any 3 in a row or column and store that index in rowindex and columnindex variables		             
		if (CheckforElbow(board) == 0)                                //Redraw board after rows and columns have been checked and marked as empty, We only redraw if the user pressed 
			CheckforMatch(board, rowtilecheck, columntilecheck);      //enter last turn since that is the only case where the Gems are going to move
		if (preventerpressed)
			Tiles(board);
		if (Dropcolumns(board, score, timestart))                                  //We use the dropcolumns command to drop new gems into any of the empty spaces 
			Sleep(100);                                          //If the user pressed enter last turn we redraw board when tiles are dropped and random value is added and print	
		if (preventerpressed)                                //selection rectangle again, Otherwise we simply print the checker pattern and selection rectangle
			Tiles(board);
		else
			CheckerPattern();
		if (CheckforElbow(board) == 0)
			CheckforMatch(board, rowtilecheck, columntilecheck);
		SelectionRectangle(selectionrectx, selectionrecty, selectionrectx + 50, selectionrecty + 50, 0, 0, 0);
		//If there are no empty tiles and no tiles in a row then we take user input otherwise the loop simply runs again
		for (int i = 0; i < 8 && emptycheck == 0; i++)
			for (int j = 0; j < 8 && emptycheck == 0; j++)
				if (board[i][j] >= 16 && board[i][j] <= 20)
					emptycheck = 1;
		userinput = 0;                                 //For user input we use a while loop to temporarily pause while waiting for user input, when user inputs we then check if                   
		waitforkey = 0;                                //the user pressed enter or not, if user did not press enter we simply move selection rectangle otherwise we try to move the 
		isenterpressed = 0;                            //actual Gem
		printTime(timestart, score);
		if (emptycheck == 0 && rowtilecheck == 0 && columntilecheck == 0)
		{
			preventerpressed = 0;
			while (waitforkey == 0 && time(0) - timestart <= 60)
			{
				printTime(timestart, score);
				waitforkey = isCursorKeyPressed(userinput);
			}
		}
		if (userinput == 5)
			isenterpressed = 1;
		if (emptycheck == 0 && isenterpressed == 0 && rowtilecheck == 0 && columntilecheck == 0)
		{
			if (userinput == 1 && selectionrectx > 555)           //The selectionrectx coordinate has a minimum value of 555 and max of 900. If the user attempts to move beyond that then program will not detect it.
				selectionrectx -= 50;
			else if (userinput == 2 && selectionrecty > 65)       //Similarly, The selectionrecty has a minimum value of 65 and max of 415.
				selectionrecty -= 50;
			else if (userinput == 3 && selectionrectx < 900)
				selectionrectx += 50;
			else if (userinput == 4 && selectionrecty < 415)
				selectionrecty += 50;
		}
		//If the user pressed enter then we wait for another input from user and move the selection rectangle and the gem.
		else if (isenterpressed == 1 && rowtilecheck == 0 && columntilecheck == 0)
		{
			SelectionRectangle(selectionrectx, selectionrecty, selectionrectx + 50, selectionrecty + 50, 255, 0, 255);
			waitforkey = 0;
			while (waitforkey == 0 && time(0) - timestart <= 60)
			{
				printTime(timestart, score);
				waitforkey = isCursorKeyPressed(userinput);
			}
			if (userinput == 1 && selectionrectx > 555)
			{
				Movecandy(board, 1, selectionrectx, selectionrecty, timestart, score);
				selectionrectx -= 50;
			}
			if (userinput == 2 && selectionrecty > 65)
			{
				Movecandy(board, 2, selectionrectx, selectionrecty, timestart, score);
				selectionrecty -= 50;
			}
			if (userinput == 3 && selectionrectx < 900)
			{
				Movecandy(board, 3, selectionrectx, selectionrecty, timestart, score);
				selectionrectx += 50;
			}
			if (userinput == 4 && selectionrecty < 415)
			{
				Movecandy(board, 4, selectionrectx, selectionrecty, timestart, score);
				selectionrecty += 50;
			}
			preventerpressed = 1;
		}
	}
	cout << "GAME OVER\nUser achieved Score of " << score << " in 60 seconds";//At the end of the program we print the score and wait 10 seconds so user does not end up closing console
	Sleep(10000);
	return 0;
}