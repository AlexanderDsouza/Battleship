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
	int DestroyerCounter = 2;
	std::vector<std::pair<int, int>> CruiserCoordinates;
	int CruiserCounter = 3;
	std::vector<std::pair<int, int>> SubmarineCoordinates;
	int SubmarineCounter = 4;
	std::vector<std::pair<int, int>> AircraftCoordinates;
	int AircraftCounter = 5;


	PlayerBoard()
	{}

	PlayerBoard(std::vector<std::vector<bool>> board)
	{
		this->board;
	}
};

void CreateBoard(std::vector<std::vector<bool>>& P1) //p1
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
	

bool ComputerTurn(PlayerBoard& Player1Board, std::vector<std::vector<bool>>& ComputerAttacks,std::vector<std::vector<char>>& PrintedMap)
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
	if (Player1Board.board[AttackCoordinateX][AttackCoordinateY] == 1)
	{
		std::cout << "Computer attack hit!\n";
		for (int i = 0; i < Player1Board.AircraftCoordinates.size(); i++)
		{
			if (Player1Board.AircraftCoordinates[i] == std::make_pair(AttackCoordinateX, AttackCoordinateY))
			{
				Player1Board.AircraftCounter--;
				if (Player1Board.AircraftCounter == 0)
					std::cout << "Your Aircraft Carrier ship sunk!";
			}
		}
		for (int i = 0; i < Player1Board.DestroyerCoordinates.size(); i++)
		{
			if (Player1Board.DestroyerCoordinates[i] == std::make_pair(AttackCoordinateX, AttackCoordinateY))
			{
				Player1Board.DestroyerCounter--;
				if (Player1Board.DestroyerCounter == 0)
					std::cout << "Your Destroyer ship sunk!";
			}
		}
		for (int i = 0; i < Player1Board.CruiserCoordinates.size(); i++)
		{
			if (Player1Board.CruiserCoordinates[i] == std::make_pair(AttackCoordinateX, AttackCoordinateY))
			{
				Player1Board.CruiserCounter--;
				if (Player1Board.CruiserCounter == 0)
					std::cout << "Your Cruiser ship sunk!";
			}
		}
		for (int i = 0; i < Player1Board.SubmarineCoordinates.size(); i++)
		{
			if (Player1Board.SubmarineCoordinates[i] == std::make_pair(AttackCoordinateX, AttackCoordinateY))
			{
				Player1Board.SubmarineCounter--;
				if (Player1Board.SubmarineCounter == 0)
					std::cout << "Your Submarine ship sunk!";
			}
		}
		return 1;
	}
	else
	{
		std::cout << "Computer attack miss!\n";
		return 0;
	}
	
	
}


 void ComputerPlaceShips(PlayerBoard& shipBoard)
{

	 int AircraftPositionX = rand() % (BOARD_SIZE - 5); //5x1
	 int AircraftPositionY = rand() % (BOARD_SIZE);
	 while (1)//if not valid place reroll
	 {

		 if (shipBoard.board[AircraftPositionX][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 1][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 2][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 3][AircraftPositionY] == 0
			 && shipBoard.board[AircraftPositionX + 4][AircraftPositionY] == 0)
			 break;
		 AircraftPositionX = rand() % (BOARD_SIZE - 5);
		 AircraftPositionY = rand() % (BOARD_SIZE);
	 }
	 shipBoard.board[AircraftPositionX][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 1][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 2][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 3][AircraftPositionY] = 1;
	 shipBoard.board[AircraftPositionX + 4][AircraftPositionY] = 1;

	 shipBoard.AircraftCoordinates.push_back(std::make_pair(AircraftPositionX, AircraftPositionY));
	 shipBoard.AircraftCoordinates.push_back(std::make_pair(AircraftPositionX+1, AircraftPositionY));
	 shipBoard.AircraftCoordinates.push_back(std::make_pair(AircraftPositionX+2, AircraftPositionY));
	 shipBoard.AircraftCoordinates.push_back(std::make_pair(AircraftPositionX+3, AircraftPositionY));
	 shipBoard.AircraftCoordinates.push_back(std::make_pair(AircraftPositionX+4, AircraftPositionY));

	 int DestroyerPositionX = rand() % (BOARD_SIZE-1);
	 int DestroyerPositionY = rand() % (BOARD_SIZE-1);
	 while (1)
	 {
		
		 if (shipBoard.board[DestroyerPositionX][DestroyerPositionY] == 0
			 && shipBoard.board[DestroyerPositionX + 1][DestroyerPositionY] == 0
			 && shipBoard.board[DestroyerPositionX][DestroyerPositionY + 1] == 0)
			 break;
		 DestroyerPositionX = rand() % BOARD_SIZE;
		 DestroyerPositionY = rand() % BOARD_SIZE;
	}
	
	 shipBoard.board[DestroyerPositionX][DestroyerPositionY] = 1;
	 shipBoard.DestroyerCoordinates.push_back(std::make_pair(DestroyerPositionX, DestroyerPositionY));

	
	 if (DestroyerPositionX != BOARD_SIZE - 1)
	 {
		 shipBoard.board[DestroyerPositionX + 1][DestroyerPositionY] = 1;
		 shipBoard.DestroyerCoordinates.push_back(std::make_pair(DestroyerPositionX+1, DestroyerPositionY));
	 }
	 else
	 {
		 shipBoard.board[DestroyerPositionX - 1][DestroyerPositionY] = 1;
		 shipBoard.DestroyerCoordinates.push_back(std::make_pair(DestroyerPositionX - 1, DestroyerPositionY));
	 }

	 
	 int CruiserPositionX = rand() % (BOARD_SIZE - 3); //3x1 0-boardsize-3 bs = 8   0-6
	 int CruiserPositionY = rand() % (BOARD_SIZE - 3);
	 while (1)//if not valid place reroll
	 {
		 
		 if (shipBoard.board[CruiserPositionX][CruiserPositionY] == 0
			 && shipBoard.board[CruiserPositionX][CruiserPositionY + 1] == 0
			 && shipBoard.board[CruiserPositionX][CruiserPositionY + 2] == 0)
			 break;
		 CruiserPositionX = rand() % (BOARD_SIZE - 1);
		 CruiserPositionY = rand() % (BOARD_SIZE - 3);
	 }
	shipBoard.board[CruiserPositionX][CruiserPositionY] = 1;
	shipBoard.board[CruiserPositionX][CruiserPositionY+1] = 1;
	shipBoard.board[CruiserPositionX][CruiserPositionY+2] = 1;

	shipBoard.CruiserCoordinates.push_back(std::make_pair(CruiserPositionX, CruiserPositionY));
	shipBoard.CruiserCoordinates.push_back(std::make_pair(CruiserPositionX, CruiserPositionY+1));
	shipBoard.CruiserCoordinates.push_back(std::make_pair(CruiserPositionX, CruiserPositionY+2));


	int SubPostionX = rand() % (BOARD_SIZE - 1); //4x1
	int SubPostionY = rand() % (BOARD_SIZE - 4);
	while (1)//if not valid place reroll
	{

		if (shipBoard.board[SubPostionX][SubPostionY] == 0
			&& shipBoard.board[SubPostionX][SubPostionY + 1] == 0
			&& shipBoard.board[SubPostionX][SubPostionY + 2] == 0
			&& shipBoard.board[SubPostionX][SubPostionY + 3] == 0)
			break;
		SubPostionX = rand() % (BOARD_SIZE - 1) + 1;
		SubPostionY = rand() % (BOARD_SIZE - 4) + 1;
	}
	shipBoard.board[SubPostionX][SubPostionY] = 1;
	shipBoard.board[SubPostionX][SubPostionY + 1] = 1;
	shipBoard.board[SubPostionX][SubPostionY + 2] = 1;
	shipBoard.board[SubPostionX][SubPostionY + 3] = 1;

	shipBoard.SubmarineCoordinates.push_back(std::make_pair(SubPostionX, SubPostionY));
	shipBoard.SubmarineCoordinates.push_back(std::make_pair(SubPostionX, SubPostionY+1));
	shipBoard.SubmarineCoordinates.push_back(std::make_pair(SubPostionX, SubPostionY+2));
	shipBoard.SubmarineCoordinates.push_back(std::make_pair(SubPostionX, SubPostionY+3));


 	
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

		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY,   PositionX));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY+1, PositionX));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY+2, PositionX));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY+3, PositionX));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY+4, PositionX));


	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX + 1] = 1;
		 shipBoard.board[PositionY][PositionX + 2] = 1;
		 shipBoard.board[PositionY][PositionX + 3] = 1;
		 shipBoard.board[PositionY][PositionX + 4] = 1;

		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY, PositionX+1));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY, PositionX+2));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY, PositionX+3));
		 shipBoard.AircraftCoordinates.push_back(std::make_pair(PositionY, PositionX+4));
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
		 shipBoard.DestroyerCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.DestroyerCoordinates.push_back(std::make_pair(PositionY+1, PositionX));

	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX+1] = 1;
		 shipBoard.DestroyerCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.DestroyerCoordinates.push_back(std::make_pair(PositionY, PositionX+1));

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
		 shipBoard.CruiserCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.CruiserCoordinates.push_back(std::make_pair(PositionY+1, PositionX));
		 shipBoard.CruiserCoordinates.push_back(std::make_pair(PositionY+2, PositionX));
	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX + 1] = 1;
		 shipBoard.board[PositionY][PositionX + 2] = 1;
		 shipBoard.CruiserCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.CruiserCoordinates.push_back(std::make_pair(PositionY, PositionX + 1));
		 shipBoard.CruiserCoordinates.push_back(std::make_pair(PositionY, PositionX + 2));

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

		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY+1, PositionX));
		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY+2, PositionX));
		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY+3, PositionX));
	 }
	 else
	 {
		 shipBoard.board[PositionY][PositionX] = 1;
		 shipBoard.board[PositionY][PositionX + 1] = 1;
		 shipBoard.board[PositionY][PositionX + 2] = 1;
		 shipBoard.board[PositionY][PositionX + 3] = 1;

		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY, PositionX));
		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY, PositionX + 1));
		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY, PositionX + 2));
		 shipBoard.SubmarineCoordinates.push_back(std::make_pair(PositionY, PositionX + 3));
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

	ComputerPlaceShips(ComputerBoard);
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
				P1Hits++;
				std::cout << "Player 1 hit!\n";
				P1AttackMap[PositionX][PositionY] = 'X';
				for (int i = 0; i < ComputerBoard.AircraftCoordinates.size(); i++)
				{
					if (ComputerBoard.AircraftCoordinates[i] == std::make_pair(PositionX, PositionY))
					{
						ComputerBoard.AircraftCounter--;
						if (ComputerBoard.AircraftCounter == 0)
							std::cout << "The enemy Aircraft Carrier ship sunk!\n";
					}
				}
				for (int i = 0; i < ComputerBoard.DestroyerCoordinates.size(); i++)
				{
					if (ComputerBoard.DestroyerCoordinates[i] == std::make_pair(PositionX, PositionY))
					{
						ComputerBoard.DestroyerCounter--;
						if (ComputerBoard.DestroyerCounter == 0)
							std::cout << "The enemy Your Destroyer ship sunk!\n";
					}
				}
				for (int i = 0; i < ComputerBoard.CruiserCoordinates.size(); i++)
				{
					if (ComputerBoard.CruiserCoordinates[i] == std::make_pair(PositionX, PositionY))
					{
						ComputerBoard.CruiserCounter--;
						if (ComputerBoard.CruiserCounter == 0)
							std::cout << "The enemy Cruiser ship sunk!\n";
					}
				}
				for (int i = 0; i < ComputerBoard.SubmarineCoordinates.size(); i++)
				{
					if (ComputerBoard.SubmarineCoordinates[i] == std::make_pair(PositionX, PositionY))
					{
						ComputerBoard.SubmarineCounter--;
						if (ComputerBoard.SubmarineCounter == 0)
							std::cout << "The enemy Submarine ship sunk!\n";
					}
				}			
			}
			else
			{
				P1AttackMap[PositionX][PositionY] = 'O';
				std::cout << "Player 1 miss!\n";
			}
		
			if (ComputerTurn(P1Board, ComputerAttacks, CompAttackMap))
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
