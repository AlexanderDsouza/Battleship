#include <vector>
#include <string>
#include <cstdlib>
#include <iostream>
#define BOARD_SIZE 8
#define ShipSpaces 14

class PlayerBoard
{
public:
	std::vector < std::vector<bool>> board;
	std::vector<std::pair<int, int>> DestroyerCoordinates;
	std::vector<std::pair<int, int>> CruiserCoordinates;
	std::vector<std::pair<int, int>> SubmarineCoordinates;
	std::vector<std::pair<int, int>> AircraftCoordinates;


	PlayerBoard()
	{}

	PlayerBoard(std::vector<std::vector<bool>> board)
	{
		this->board;
	}
};

void CreateBoard(std::vector<std::vector<bool>>& P1) //p1 and p2 board
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

}
	

bool ComputerTurn(std::vector<std::vector<bool>>& Player1Board , std::vector<std::vector<bool>>& ComputerAttacks,std::vector<std::vector<char>>& PrintedMap)
{
	int AttackCoordinateX = rand() % BOARD_SIZE;
	int AttackCoordinateY = rand() % BOARD_SIZE ;
	while (1)
	{
		if (ComputerAttacks[AttackCoordinateX][AttackCoordinateY] == 0)
			break;
		AttackCoordinateX = rand() % BOARD_SIZE;
		AttackCoordinateY = rand() % BOARD_SIZE;
	}
	PrintedMap[AttackCoordinateX][AttackCoordinateY] = 'X';
	if (Player1Board[AttackCoordinateX][AttackCoordinateY] == 1)
	{
		std::cout << "Computer attack hit!\n";
		return 1;
	}
	else
	{
		std::cout << "Computer attack miss!\n";
		return 0;
	}
	
	
}


 void PlaceShips(PlayerBoard& shipBoard)
{

	 int AircraftPositionX = rand() % (BOARD_SIZE - 5) + 1; //5x1
	 int AircraftPositionY = rand() % (BOARD_SIZE - 1) + 1;
	 while (1)//if not valid place reroll
	 {

		 if (shipBoard.board[AircraftPositionX][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 1][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 2][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 3][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 4][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX - 1][AircraftPositionY] == 0)
			 break;
		 AircraftPositionX = rand() % (BOARD_SIZE - 5) + 1;
		 AircraftPositionY = rand() % (BOARD_SIZE - 1) + 1;
	 }
	 shipBoard.board[AircraftPositionX][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 1][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 2][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 3][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 4][AircraftPositionY] = 1;

	 int DestroyerPositionX = rand() % BOARD_SIZE;
	 int DestroyerPositionY = rand() % BOARD_SIZE;
	 shipBoard.board[DestroyerPositionX][DestroyerPositionY] = 1;
	// shipBoard.DestroyerCoordinates.push_back(std::make_pair(DestroyerPositionX, DestroyerPositionX));
	 if (DestroyerPositionX != BOARD_SIZE - 1)
	 {
		 shipBoard.board[DestroyerPositionX + 1][DestroyerPositionY] = 1;
	//	 shipBoard.DestroyerCoordinates.push_back(std::make_pair(DestroyerPositionX+1, DestroyerPositionY));

	 }
	 else
	 {
		 shipBoard.board[DestroyerPositionX - 1][DestroyerPositionY] = 1;
		// shipBoard.DestroyerCoordinates.push_back(std::make_pair(DestroyerPositionX - 1, DestroyerPositionY));

	 }

	 
	 int CruiserPositionX = rand() % (BOARD_SIZE - 3) + 1; //3x1
	 int CruiserPositionY = rand() % (BOARD_SIZE - 3) + 1;
	 while (1)//if not valid place reroll
	 {
		 
		 if (shipBoard.board[CruiserPositionX][CruiserPositionY] == 0
			 && shipBoard.board[CruiserPositionX][CruiserPositionY + 1] == 0
			 && shipBoard.board[CruiserPositionX][CruiserPositionY + 2] == 0)
			 break;
		 CruiserPositionX = rand() % (BOARD_SIZE - 1) + 1;
		 CruiserPositionY = rand() % (BOARD_SIZE - 3) + 1;
	 }
	shipBoard.board[CruiserPositionX][CruiserPositionY] = 1;
	shipBoard.board[CruiserPositionX][CruiserPositionY+1] = 1;
	shipBoard.board[CruiserPositionX][CruiserPositionY+2] = 1;


	int SubPostionX = rand() % (BOARD_SIZE - 1) + 1; //4x1
	int SubPostionY = rand() % (BOARD_SIZE - 4) + 1;
	while (1)//if not valid place reroll
	{

		if (shipBoard.board[SubPostionX][SubPostionY] == 0
			&& shipBoard.board[SubPostionX][SubPostionY + 1] == 0
			&& shipBoard.board[SubPostionX][SubPostionY + 2] == 0
			&& shipBoard.board[SubPostionX][SubPostionY + 3] == 0
			&& shipBoard.board[SubPostionX][SubPostionY - 1] == 0)
			break;
		SubPostionX = rand() % (BOARD_SIZE - 1) + 1;
		SubPostionY = rand() % (BOARD_SIZE - 4) + 1;
	}
	shipBoard.board[SubPostionX][SubPostionY] = 1;
	shipBoard.board[SubPostionX][SubPostionY + 1] = 1;
	shipBoard.board[SubPostionX][SubPostionY + 2] = 1;
	shipBoard.board[SubPostionX][SubPostionY + 3] = 1;


 	
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

 void ComputerAttackMap(PlayerBoard& map,std::vector<std::vector<char>>&PrintedMap)
 {
	 std::vector<char> temp;
	 for (int i = 0; i < BOARD_SIZE; i++)
	 {
		 PrintedMap.push_back(temp);
		 for (int j = 0; j < BOARD_SIZE; j++)
		 {
			 if (map.board[i][j] == 0)
				 PrintedMap[i].push_back('O');
			 else
				 PrintedMap[i].push_back('S');
		 }
	 }
 }


 void PrintAttackMap(std::vector<std::vector<char>>& Map)
 {
	 char temp = 'a';
	 std::cout << "\t\t\t\t\t";
	 for (int k = 0; k < BOARD_SIZE; k++)
	 {
		 std::cout << char(temp + k - 32) << "\t";
	 }
	 std::cout << std::endl << std::endl;
	 for (int i = 0; i < BOARD_SIZE; i++)
	 {
		 std::cout << "\t\t\t\t" << i + 1 << "\t";
		 for (int j = 0; j < BOARD_SIZE; j++)
		 {
			 std::cout << Map[i][j] << "\t";
		 }
		 std::cout << std::endl << std::endl << std::endl;
	 }


 }

 void ManualPlaceShips(PlayerBoard& shipBoard)
 {
	 std::string input;
	 std::string shipInput;
	 int PositionX;
	 int PositionY;
	 bool CorrectInput  = 0;
	 bool ShipCompleted = 0;
	 int ShipSpacesLeft = 0;

	 while (1) // manual 4x1ship placement with vertical or horizontal optiosn
	 {
		 std::cout << "Place your Aircraft Carrier(5x1): \n";
		 std::cin >> shipInput;
		 PositionX = shipInput[0] - 65;
		 PositionY = shipInput[1] - 49;
		 if (PositionX >= 0
			 && PositionY >= 0
			 && shipInput.size() == 2
			 && PositionX < BOARD_SIZE - 4
			 && PositionY < BOARD_SIZE - 4
			 && shipBoard.board[PositionY][PositionX] == 0
			 && shipBoard.board[PositionY + 1][PositionX] == 0
			 && shipBoard.board[PositionY + 2][PositionX] == 0
			 && shipBoard.board[PositionY + 3][PositionX] == 0
			 && shipBoard.board[PositionY + 4][PositionX] == 0
			 && shipBoard.board[PositionY][PositionX + 1] == 0
			 && shipBoard.board[PositionY][PositionX + 2] == 0
			 && shipBoard.board[PositionY][PositionX + 3] == 0
			 && shipBoard.board[PositionY][PositionX + 4] == 0)
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
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY + 1][PositionX] = 1;
		 shipBoard.board[PositionY + 2][PositionX] = 1;
		 shipBoard.board[PositionY + 3][PositionX] = 1;
		 shipBoard.board[PositionY + 4][PositionX] = 1;
	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX + 1] = 1;
		 shipBoard.board[PositionY][PositionX + 2] = 1;
		 shipBoard.board[PositionY][PositionX + 3] = 1;
		 shipBoard.board[PositionY][PositionX + 4] = 1;
	 }

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
			 && shipBoard.board[PositionY][PositionX] == 0
			 && shipBoard.board[PositionY+1][PositionX] == 0
			 && shipBoard.board[PositionY][PositionX+1] == 0)
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
		 shipBoard.board[PositionY][PositionX]= 1;
		 shipBoard.board[PositionY+1][PositionX] = 1;
	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX+1] = 1;
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
			 && shipBoard.board[PositionY][PositionX] == 0
			 && shipBoard.board[PositionY+1][PositionX] == 0
			 && shipBoard.board[PositionY+2][PositionX] == 0
			 && shipBoard.board[PositionY][PositionX+1] == 0
			 && shipBoard.board[PositionY][PositionX+2] == 0)
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
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY + 1][PositionX] = 1;
		 shipBoard.board[PositionY + 2][PositionX] = 1;
	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX + 1] = 1;
		 shipBoard.board[PositionY][PositionX + 2] = 1;
	 }

	 while (1) // manual 4x1ship placement with vertical or horizontal optiosn
	 {
		 std::cout << "Place your Submarine(4x1): \n";
		 std::cin >> shipInput;
		 PositionX = shipInput[0] - 65;
		 PositionY = shipInput[1] - 49;
		 if (PositionX >= 0
			 && PositionY >= 0
			 && shipInput.size() == 2
			 && PositionX < BOARD_SIZE - 3
			 && PositionY < BOARD_SIZE - 3
			 && shipBoard.board[PositionY][PositionX] == 0
			 && shipBoard.board[PositionY + 1][PositionX] == 0
			 && shipBoard.board[PositionY + 2][PositionX] == 0
			 && shipBoard.board[PositionY + 3][PositionX] == 0
			 && shipBoard.board[PositionY][PositionX + 1] == 0
			 && shipBoard.board[PositionY][PositionX + 2] == 0
			 && shipBoard.board[PositionY][PositionX + 3] == 0)
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
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY + 1][PositionX] = 1;
		 shipBoard.board[PositionY + 2][PositionX] = 1;
		 shipBoard.board[PositionY + 3][PositionX] = 1;
	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX + 1] = 1;
		 shipBoard.board[PositionY][PositionX + 2] = 1;
		 shipBoard.board[PositionY][PositionX + 3] = 1;
	 }


	
}



int main()
{
	srand((unsigned)time(NULL));
	bool P1turn = 1;
	int NumberOfTurns = 0;
	int PositionX = 0;
	int PositionY = 0;
	bool CorrectInput = 0;
	std::string InputString; 
	int P1Hits = 0;
	int ComputerHits = 0;
	std::vector < std::vector<bool>> P1;
	CreateBoard(P1);
	std::vector < std::vector<bool>> P2 = P1;
	std::vector < std::vector<bool>> ComputerShipCoordinates = P1;
	std::vector < std::vector<bool>> P1ShipCoordinates = P1;
	std::vector < std::vector<bool>> P1Attacks = P1;
	std::vector < std::vector<bool>> ComputerAttacks = P1;
	std::vector < std::vector<char>> P1AttackMap;
	std::vector < std::vector<char>> CompAttackMap;

	PlayerBoard ComputerBoard;
	ComputerBoard.board = P1;
	PlayerBoard P1Board;
	P1Board.board = P1;

	PlaceShips(ComputerBoard);
	ManualPlaceShips(P1Board);
	ComputerAttackMap(P1Board, CompAttackMap);
	EmptyAttackMap(P1AttackMap);



	while (P1Hits != ShipSpaces && ComputerHits != ShipSpaces)
	{
		NumberOfTurns++;
		PrintAttackMap(P1AttackMap);
		std::cout << "\t\t\t\t------------------------------------------------------------------\n\n";
		PrintAttackMap(CompAttackMap);
			std::cout << "Enter coordinates for an attack:  \n";
			while (1)
			{
				
				std::cin >> InputString;
				InputString[0] = toupper(InputString[0]);
				PositionY = InputString[0] - 65;
				PositionX = InputString[1] - 49;

				if ((PositionX >= 0
					&& PositionY >= 0
					&& PositionX < BOARD_SIZE
					&& PositionY < BOARD_SIZE
					&& InputString.size() == 2)
					&& (P1Attacks[PositionX][PositionY] == 0 && (P1turn)))
				{
					break;
				}
				else
					std::cout << "Invalid attack, try again! \n";
			}
			for (int SpaceBuffer = 0; SpaceBuffer < 9; SpaceBuffer++)
			{
				std::cout << std::endl;
			}
			P1Attacks[PositionX][PositionY] = 1;
			if (ComputerBoard.board[PositionX][PositionY] == 1)
			{	
				P1AttackMap[PositionX][PositionY] = 'X';
				P1Hits++;
				std::cout << "Player 1 hit!\n";
			}
			else
			{
				P1AttackMap[PositionX][PositionY] = 'O';
				std::cout << "Player 1 miss!\n";
			}
		
			if (ComputerTurn(P1Board.board, ComputerAttacks, CompAttackMap))
			{
				ComputerHits++;
			}
			std::cout << "Score:\nComputer: " << ComputerHits << "\nPlayer1: " << P1Hits << "\n\n\n";
		}
	

	
	if (P1Hits > ComputerHits)
		std::cout << "Player 1 Wins! It took " << NumberOfTurns << " turns";
	else
		std::cout << "Computer Wins! It took " << NumberOfTurns << " turns";

}




/*
*TODO 
* ==============================================================================================================================*
ai attacks( if hit try another adjacent)
add sunken ship text.
* ==============================================================================================================================*

*/
