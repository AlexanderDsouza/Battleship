#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#define BOARD_SIZE 8
#define ShipSpaces 14

void CreateBoard(std::vector<std::vector<bool>>& P1, std::vector<std::vector<bool>>& P2) //p1 and p2 board
{
	std::vector<bool> temp;
	for (int i = 0; i < BOARD_SIZE; i++)
	{
		P1.push_back(temp);
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			P1[i].push_back(0);
		}
	}

	for (int i = 0; i < BOARD_SIZE; i++)
	{
		P2.push_back(temp);
		for (int j = 0; j < BOARD_SIZE; j++)
		{
			P2[i].push_back(0);
		}
	}
}
	


 void PlaceShips(std::vector<std::vector<bool>>& shipBoard)
{
	 int DestroyerPositionX = rand() % BOARD_SIZE;
	 int DestroyerPositionY = rand() % BOARD_SIZE;
	 shipBoard[DestroyerPositionY][DestroyerPositionX] = 1;
	 if (DestroyerPositionX != BOARD_SIZE)
		 shipBoard[DestroyerPositionY][DestroyerPositionX + 1] = 1;
	 else 
		 shipBoard[DestroyerPositionY][DestroyerPositionX - 1] = 1;
	 
	 int CruiserPositionX = rand() % (BOARD_SIZE - 3) + 1; //3x1
	 int CruiserPositionY = rand() % (BOARD_SIZE - 3) + 1;
	 while (1)//if not valid place reroll
	 {
		 
		 if (shipBoard[CruiserPositionX][CruiserPositionY] == 0
			 && shipBoard[CruiserPositionX][CruiserPositionY + 1] == 0
			 && shipBoard[CruiserPositionX][CruiserPositionY + 2] == 0)
			 break;
		 CruiserPositionX = rand() % (BOARD_SIZE - 1) + 1;
		 CruiserPositionY = rand() % (BOARD_SIZE - 3) + 1;
	 }
	shipBoard[CruiserPositionX][CruiserPositionY] = 1;
	shipBoard[CruiserPositionX][CruiserPositionY+1] = 1;
	shipBoard[CruiserPositionX][CruiserPositionY+2] = 1;


	int SubPostionX = rand() % (BOARD_SIZE - 1) + 1; //4x1
	int SubPostionY = rand() % (BOARD_SIZE - 4) + 1;
	while (1)//if not valid place reroll
	{

		if (shipBoard[SubPostionX][SubPostionY] == 0
			&& shipBoard[SubPostionX][SubPostionY + 1] == 0
			&& shipBoard[SubPostionX][SubPostionY + 2] == 0
			&& shipBoard[SubPostionX][SubPostionY + 3] == 0)
			break;
		SubPostionX = rand() % (BOARD_SIZE - 1) + 1;
		SubPostionY = rand() % (BOARD_SIZE - 4) + 1;
	}
	shipBoard[SubPostionX][SubPostionY] = 1;
	shipBoard[SubPostionX][SubPostionY + 1] = 1;
	shipBoard[SubPostionX][SubPostionY + 2] = 1;
	shipBoard[SubPostionX][SubPostionY + 3] = 1;


 	int AircraftPositionX = rand() % (BOARD_SIZE - 5) + 1; //4x1
	int AircraftPositionY = rand() % (BOARD_SIZE - 1) + 1;
	while (1)//if not valid place reroll
	{

		if (shipBoard[AircraftPositionX][AircraftPositionY] == 0
			&& shipBoard[AircraftPositionX+1][AircraftPositionY] == 0
			&& shipBoard[AircraftPositionX+2][AircraftPositionY] == 0
			&& shipBoard[AircraftPositionX+3][AircraftPositionY] == 0
			&& shipBoard[AircraftPositionX+4][AircraftPositionY] == 0)
			break;
		AircraftPositionX = rand() % (BOARD_SIZE - 5) + 1;
		AircraftPositionY = rand() % (BOARD_SIZE - 1) + 1;
	}
	shipBoard[AircraftPositionX][AircraftPositionY] = 1;
	shipBoard[AircraftPositionX+1][AircraftPositionY] = 1;
	shipBoard[AircraftPositionX+2][AircraftPositionY] = 1;
	shipBoard[AircraftPositionX+3][AircraftPositionY] = 1;
	shipBoard[AircraftPositionX+4][AircraftPositionY] = 1;


}

 void EmptyAttackMap(std::vector<std::vector<char>>& Map)
 {
	 std::vector<char> temp;
	 for (int i = 0; i < BOARD_SIZE; i++)
	 {
		 Map.push_back(temp);
		 for (int j = 0; j < BOARD_SIZE; j++)
		 {
			 Map[i].push_back('?');
		 }
	 }
 }


 void PrintAttackMap(std::vector<std::vector<char>>& Map)
 {
	 char temp = 'a';
	 std::cout << "\t\t\t\t\t";
	 for (int k = 0; k < BOARD_SIZE; k++)
	 {
		 std::cout << k+1 << "\t";
	 }
	 std::cout << std::endl << std::endl;
	 for (int i = 0; i < BOARD_SIZE; i++)
	 {
		 std::cout << "\t\t\t\t" << char(temp + i - 32) << "\t";
		 for (int j = 0; j < BOARD_SIZE; j++)
		 {
			 std::cout << Map[i][j] << "\t";
		 }
		 std::cout << std::endl << std::endl;
	 }


 }

 void ManualPlaceShips(std::vector<std::vector<bool>>& shipBoard)
 {
	 std::string input;
	 std::string shipInput;
	 int PositionX;
	 int PositionY;
	 bool CorrectInput  = 0;
	 bool ShipCompleted = 0;
	 int ShipSpacesLeft = 0;


	 while (1) //manual 2x1 ship placement with vertical horizontal options
	 {
		 std::cout << "Place your Destroyer(2x1): \n";
		 std::cin >> shipInput;
		 PositionX = shipInput[0] - 65;
		 PositionY = shipInput[1] - 49;
		 if (PositionX >= 0 && PositionY >= 0
			 && shipInput.size() == 2
			 && PositionX < BOARD_SIZE-1 
			 && PositionY < BOARD_SIZE-1 
			 && shipBoard[PositionY][PositionX] == 0
			 && shipBoard[PositionY+1][PositionX] == 0 
			 && shipBoard[PositionY][PositionX+1] == 0)
		 {
			 while (1)
			 {
				 std::cout << "Vertical or Horizontal: V or H: \n";
				 std::cin >> shipInput;
				 shipInput = toupper(shipInput[0]);
				 if (shipInput == "V" || shipInput == "H")
					 break;
				 else
					 std::cout << "Invalid positional input, try again \n";
			 }
			 
			 break;
		 }
		 else
		 {
			 std::cout << "Invalid coordinate input, try again: \n";
		 }
	 }
	 if (shipInput == "V")
	 {
		 shipBoard[PositionY][PositionX]= 1;
		 shipBoard[PositionY+1][PositionX] = 1;
	 }
	 else
	 {
		 shipBoard[PositionY][PositionX] = 1;
		 shipBoard[PositionY][PositionX+1] = 1;
	 }
	 
	 while (1) // manual 3x1ship placement with vertical or horizontal optiosn
	 {
		 std::cout << "Place your Cruiser(3x1): \n";
		 std::cin >> shipInput;
		 PositionX = shipInput[0] - 65;
		 PositionY = shipInput[1] - 49;
		 if (PositionX >= 0
			 && PositionY >= 0 
			 && shipInput.size() == 2 
			 && PositionX < BOARD_SIZE - 2 
			 && PositionY < BOARD_SIZE - 2 
			 && shipBoard[PositionY][PositionX] == 0
			 && shipBoard[PositionY+1][PositionX] == 0
			 && shipBoard[PositionY+2][PositionX] == 0
			 && shipBoard[PositionY][PositionX+1] == 0
			 && shipBoard[PositionY][PositionX+2] == 0)
		 {
			 while (1)
			 {
				 std::cout << "Vertical or Horizontal: V or H: \n";
				 std::cin >> shipInput;
				 shipInput = toupper(shipInput[0]);
				 if (shipInput == "V" || shipInput == "H")
					 break;
				 else
					 std::cout << "Invalid positional input, try again \n";
			 }

			 break;
		 }
		 else
		 {
			 std::cout << "Invalid coordinate input, try again: \n";
		 }
	 }
	 if (shipInput == "V")
	 {
		 shipBoard[PositionY][PositionX] = 1;
		 shipBoard[PositionY + 1][PositionX] = 1;
		 shipBoard[PositionY + 2][PositionX] = 1;
	 }
	 else
	 {
		 shipBoard[PositionY][PositionX] = 1;
		 shipBoard[PositionY][PositionX + 1] = 1;
		 shipBoard[PositionY][PositionX + 2] = 1;
	 }




	  
}

int main()
{
	srand((unsigned)time(NULL));
	bool P2turn = 0;
	int NumberOfTurns = 0;
	int PositionX = 0;
	int PositionY = 0;
	bool CorrectInput = 0;
	std::string InputString; 
	int P1Hits = 0;
	int P2Hits = 0;
	std::vector < std::vector<bool>> P1;
	std::vector < std::vector<bool>> P2;
	CreateBoard(P1, P2);
	std::vector < std::vector<bool>> P2ShipCoordinates = P1;
	std::vector < std::vector<bool>> P1ShipCoordinates = P1;
	std::vector < std::vector<bool>> P1Attacks = P1;
	std::vector < std::vector<bool>> P2Attacks = P1;
	std::vector < std::vector<char>> AttackMap;
	EmptyAttackMap(AttackMap);

	CreateBoard(P1, P2);
	PlaceShips(P2ShipCoordinates);
	ManualPlaceShips(P1ShipCoordinates);


	while (P1Hits != ShipSpaces && P2Hits != ShipSpaces)
	{
		NumberOfTurns++;
			std::cout << "Enter coordinates for an attack:  \n";
		
		while (1)
		{
			std::cin >> InputString;
			InputString[0] = toupper(InputString[0]);
			PositionX = InputString[0] - 65;
			PositionY = InputString[1] - 49;

			if ((PositionX >= 0
				&& PositionY >= 0 
				&& PositionX < BOARD_SIZE
				&& PositionY < BOARD_SIZE
				&& InputString.size() == 2) 
				&& ((P1Attacks[PositionX][PositionY] == 0 && (!P2turn))
				|| (P2Attacks[PositionX][PositionY] == 0 && P2turn)))
			{
				break;
			}
			else
				std::cout << "Invalid attack, try again! \n";
		}
		if (P2turn == 0) //p1 turn
		{
			for (int SpaceBuffer = 0; SpaceBuffer < 9; SpaceBuffer++)
			{
				std::cout << std::endl;
			}
			P1Attacks[PositionX][PositionY] = 1;
			if (P2ShipCoordinates[PositionX][PositionY] == 1)
			{	
				AttackMap[PositionX][PositionY] = 'X';
				std::cout << "Player 1 Hit!\n";
					P1Hits++;
			}
			else
			{
				AttackMap[PositionX][PositionY] = 'O';
				std::cout << "Player 1 Miss!\n";
			}
		}
		else //p2 turn
		{
			P2Attacks[PositionX][PositionY] = 1;
			if (P1ShipCoordinates[PositionX][PositionY] == 1)
			{
				std::cout << "Player 2 Hit!\n";
				P2Hits++;
			}
			else
			{
				std::cout << "Player 2 Miss!\n";
			}
		}
		//P2turn = !P2turn; //two player mode

		PrintAttackMap(AttackMap);
		std::cout << "P1 hits: " << P1Hits << std::endl;
	}
	if (P1Hits > P2Hits)
		std::cout << "Player 1 Wins! It took " << NumberOfTurns << " turns";
	else
		std::cout << "Player 2 Wins! It took " << NumberOfTurns << " turns";

}




/*
*TODO 
* ==============================================================================================================================*
be able to put all ships on board randomly
ai attacks( if hit try another adjacent)
add sunken ship text.
* ==============================================================================================================================*



*/