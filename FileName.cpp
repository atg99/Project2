#include <iostream> //cpp standard
#include "conio.h" //c standard
#include "./L0922.h"

using namespace std;

#define UP 'w'
#define LEFT 'a'
#define RIGHT 'd'
#define DOWN 's'
#define QUIT 'q'

const int Y = 10;
const int X = 10;
int World[Y][X] =
{
	{1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1}
};


int DrawMap(int PlayerX, int PlayerY);

class Character
{

public:

	int LocX = 0;
	int LocY = 0;

	Character(int LocX, int LocY) : LocX(LocX), LocY(LocY)
	{

	}

};

class Player : public Character
{

public:

	pair<int, int> PlayerDirection = { 0,0 };

	Player(int LocX, int LocY) : Character(LocX, LocY)
	{

	};

	void GetInput()
	{
		int MoveDirectionX = 0;
		int MoveDirectionY = 0;

		if (int KeyCode = _getch()) //assembler
		{
			switch (KeyCode)
			{
			case UP: MoveDirectionY--; break;
			case DOWN: MoveDirectionY++; break;
			case LEFT: MoveDirectionX--; break;
			case RIGHT: MoveDirectionX++; break;
			case QUIT: break;
			}
		}

		this->PlayerDirection = { MoveDirectionX, MoveDirectionY };

		return;
	}

	void ProcessLocation()
	{
		if (!World[LocX + PlayerDirection.first][LocY + PlayerDirection.second])
		{
			LocX += PlayerDirection.first;
			LocY += PlayerDirection.second;
		}
		return;
	}
};

int main()
{
	Player UserCharacter(5, 5);

	TestString();

	//frame, deltaseconds
	while (true)
	{
		UserCharacter.GetInput();
		UserCharacter.ProcessLocation();
		DrawMap(UserCharacter.LocX, UserCharacter.LocY);
	}

	return 0;
}

int DrawMap(int PlayerX, int PlayerY)
{

	system("cls");

	char PlayerShape = 'p';
	char Sprites[10] = { ' ','*', };

	//Render();
	for (int i = 0; i < Y; ++i)
	{
		for (int j = 0; j < X; ++j)
		{
			if (PlayerX == j and PlayerY == i)
			{
				cout << 'p';
			}
			else
			{
				cout << Sprites[World[i][j]];
			}
		}
		cout << '\n';
	}

	return 0;
}