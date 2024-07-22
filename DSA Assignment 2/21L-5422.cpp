#include"Header.h"
class Coordinates
{
private:
	int x;
	int y;
	int RoomNo;
public:
	// Coordinate Class is for Storing Coordinates of Different Cells in the Room
	// It has 2 Coordinates x and y
	Coordinates(int _x = 0, int _y = 0, int _RoomNo = 0)
	{
		x = _x;
		y = _y;
		RoomNo = _RoomNo;
	}
	int Get_X()
	{
		return x;
	}
	int Get_Y()
	{
		return y;
	}
	void Set_X(int temp)
	{
		x = temp;
	}
	void Set_Y(int temp)
	{
		y = temp;
	}
	void Print()
	{
		cout << "\t{" << this->x << " , " << this->y << "}";
		cout << endl;
	}
	friend ostream& operator<<(ostream& out, Coordinates& obj)  // Overloaded Stream Function to print coordinates
	{
		cout << "RoomNo:" << obj.RoomNo << " ->\t{" << obj.x << " , " << obj.y << "}";
		cout << endl;
		return out;
	}
	Coordinates& operator=(Coordinates& obj) // Assignment Operator
	{
		x = obj.x;
		y = obj.y;
		RoomNo = obj.RoomNo;
		return *this;
	}
	void SetRoomNo(int No)
	{
		RoomNo = No;
	}
};
template<class T>
class Stack
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node()
		{
			next = nullptr;
		}
	};
	Node* head;
	int stkptr;
public:
	Stack()
	{
		head = nullptr;
		stkptr = 0;   // This Shows the Size of Stack
	}
	void Push(T d)
	{
		Node* temp = new Node;
		temp->data = d;
		temp->next = head;
		head = temp;
		stkptr++;
	}
	bool IsEmpyt()
	{
		if (stkptr == 0)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	T& Top()
	{
		if (!IsEmpyt())
		{
			return head->data;
		}
	}
	void Pop()
	{
		if (!IsEmpyt())
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			--stkptr;
			return;
		}
		else
		{
			return;
		}
	}
	void Print(Node* temp) // This is a Recursive function for Printing Stack from the end 
	{
		if (temp->next != nullptr)
			Print(temp->next);
		cout << temp->data;
	}
	void PrintStack() // A Wrapper Function to Call the Above Print Function 
	{
		Node* temp;
		temp = head;
		if (temp == nullptr)
			return;
		Print(temp);
	}
	int GetStkPtr()
	{
		return stkptr;
	}
};
class Rooms
{
private:
	Coordinates Dimensions;
	Coordinates Starting_Coordinates;
	Coordinates TreasureIndex;
	Coordinates CurrentCoordinate;
	int RoomNo;
	int Treasure;
	char** Maze;
public:
	Rooms()
	{
		Maze = nullptr;
		RoomNo = 0;
		Treasure = 0;
	}
	void GetDataFromFile(ifstream& RoomFile, int No)
	{ // This Function Takes Data From Room File Which Includes 2 Dimensions and a 2D Array of Room Cells
		RoomNo = No;
		int tempR, tempC;
		RoomFile >> tempR >> tempC;
		Dimensions.Set_X(tempR + 2);
		Dimensions.Set_Y(tempC + 2);
		RoomFile >> tempR >> tempC;
		Starting_Coordinates.Set_X(tempR + 1);
		Starting_Coordinates.Set_Y(tempC + 1);
		CurrentCoordinate.Set_X(tempR + 1);
		CurrentCoordinate.Set_Y(tempC + 1);
		Maze = new char* [Dimensions.Get_X()];
		for (int i = 0; i < Dimensions.Get_X(); i++)
		{
			Maze[i] = new char[Dimensions.Get_Y()];
		}
		for (int i = 0; i < Dimensions.Get_X(); i++)
		{
			for (int j = 0; j < Dimensions.Get_Y(); j++)
			{
				if (i == 0 || j == 0)
				{
					Maze[i][j] = 'X';
				}
				else if (i == Dimensions.Get_X() - 1 || j == Dimensions.Get_Y() - 1)
				{
					Maze[i][j] = 'X';
				}
				else
				{
					RoomFile >> Maze[i][j];
					if (Maze[i][j] == 'T')
					{
						TreasureIndex.Set_X(i);
						TreasureIndex.Set_Y(j);
						Treasure = 1;
					}
				}
			}
		}
	}
	void Print() // Function For Printing The 2D Array( Rooms Data )
	{
		int sml = 1;
		char ch = sml;
		cout << "\n\n\n";
		for (int i = 0; i < Dimensions.Get_X(); i++)
		{
			cout << "\t\t";
			for (int j = 0; j < Dimensions.Get_Y(); j++)
			{
				if (CurrentCoordinate.Get_X() == i && CurrentCoordinate.Get_Y() == j)
				{
					cout << " " << ch << " ";
				}
				else if (Maze[i][j] == 'X')
				{
					cout << " # ";
				}
				else
				{
					cout << "   ";
				}
			}
			cout << endl;
		}
		cout << endl << endl;
	}
	int CheckUp() // This Function Checks in the Upward Direction if the player can Move or Not. If he Can Move then it will Return The Cells Data
	{
		if (CurrentCoordinate.Get_X() == 0)
		{
			return 0;
		}
		else
		{
			return Maze[CurrentCoordinate.Get_X() - 1][CurrentCoordinate.Get_Y()];
		}
	}
	int CheckDown() // This Function Checks in the Downward Direction if the player can Move or Not. If he Can Move then it will Return The Cells Data
	{
		if (CurrentCoordinate.Get_X() == Dimensions.Get_X() - 1)
		{
			return 0;
		}
		else
		{
			return Maze[CurrentCoordinate.Get_X() + 1][CurrentCoordinate.Get_Y()];
		}
	}
	int CheckLeft() // This Function Checks in the Left Direction if the player can Move or Not. If he Can Move then it will Return The Cells Data
	{
		if (CurrentCoordinate.Get_Y() == 0)
		{
			return 0;
		}
		else
		{
			return Maze[CurrentCoordinate.Get_X()][CurrentCoordinate.Get_Y() - 1];
		}
	}
	int CheckRight() // This Function Checks in the Right Direction if the player can Move or Not. If he Can Move then it will Return The Cells Data
	{
		if (CurrentCoordinate.Get_Y() == Dimensions.Get_Y() - 1)
		{
			return 0;
		}
		else
		{
			return Maze[CurrentCoordinate.Get_X()][CurrentCoordinate.Get_Y() + 1];
		}
	}
	void PrintTreasureCoordinates() // This Prints the Coordinates of the cell where the treasure is
	{
		TreasureIndex.Print();
	}
	void MoveUp()  // This Function Changes the current coordinates of the Player in the Upward Direction
	{
		CurrentCoordinate.Set_X(CurrentCoordinate.Get_X() - 1);
	}
	void MoveDown()  // This Function Changes the current coordinates of the Player in the Downward Direction
	{
		CurrentCoordinate.Set_X(CurrentCoordinate.Get_X() + 1);
	}
	void MoveRight()  // This Function Changes the current coordinates of the Player in the Right Direction
	{
		CurrentCoordinate.Set_Y(CurrentCoordinate.Get_Y() + 1);
	}
	void MoveLeft()  // This Function Changes the current coordinates of the Player in the Left Direction
	{
		CurrentCoordinate.Set_Y(CurrentCoordinate.Get_Y() - 1);
	}
	bool IsTreasure()  // A check to Verify the existence of treasure
	{
		if (Treasure == 1)
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	int GetRoomNo()
	{
		return RoomNo;
	}
	Coordinates GetCuurentCoordinates()
	{
		return CurrentCoordinate;
	}
};
class Game
{
private:
	int NoofRooms;
	Rooms* Roomptr;
	Stack<Rooms>RoomsPath;
	Stack<Coordinates>PlayersPath;
	int TreasureRoom;
public:
	Game()
	{
		NoofRooms = 0;
		TreasureRoom = 0;
		Roomptr = NULL;
	}
	void ReadData()
	{ // This Function Reads the Main File which includes No of Rooms and Room Names
		ifstream MainFile("HauntedHouse.txt");
		MainFile >> NoofRooms;
		string* FileNames = new string[NoofRooms];
		for (int i = 0; i < NoofRooms; i++)
		{
			MainFile >> FileNames[i];
		}
		Roomptr = new Rooms[NoofRooms];
		for (int i = 0; i < NoofRooms; i++)
		{
			ifstream RoomFile(FileNames[i]);
			Roomptr[i].GetDataFromFile(RoomFile, i);
		}
		for (int i = 0; i < NoofRooms; i++)
		{
			if (Roomptr[i].IsTreasure())
			{
				TreasureRoom = i;
			}
		}
	}
	void PortalCheck(char move, int& RandomChoice, Rooms& Current, bool& Game) // This Function is for recursive implementation, its checks if theres a portal or not in the next position
	{
		system("CLS");
		int NewChoice;
		Coordinates temp = Current.GetCuurentCoordinates();
		temp.SetRoomNo(Current.GetRoomNo());
		PlayersPath.Push(temp);
		if (move == KEY_UP)
		{
			Current.MoveUp();
		}
		else if (move == KEY_RIGHT)
		{
			Current.MoveRight();
		}
		else if (move == KEY_DOWN)
		{
			Current.MoveDown();
		}
		else if (move == KEY_LEFT)
		{
			Current.MoveLeft();
		}
		srand(time(0));
		int Coin = (rand() % NoofRooms) + 0;
		cout << "You Have Reached The Portal \n Tossing Coin to Decide your FAITH....\n\n";
		if (Coin == 1)// 1->Head
		{
			cout << "\n Coin Results in Head \n You are Transferred to the Next Room By Portal!!\n";
			if (RandomChoice == 0)
				RandomChoice = 1;
			else
				RandomChoice = 0;
			RoomsPath.Push(Roomptr[RandomChoice]);
			Current = Roomptr[RandomChoice];
		}
		else
		{
			cout << "\n Coin Results in Tail !!! \n" << endl;
			RoomsPath.Pop();
			if (RoomsPath.GetStkPtr() == 0)
			{
				cout << "\n You are Out of the GAME !!! \n" << endl;
				Game = false;
			}
			else if (RoomsPath.GetStkPtr() != 0)
			{
				cout << "You are Transferred to the Previous Room By Portal!!\n";
				Rooms RoomData = RoomsPath.Top();
				int RoomNo = RoomData.GetRoomNo();
				Current = Roomptr[RoomNo];
			}
		}
	}
	void MovementCheck(char choice, Rooms& Curr) // This is also for Recursive implementation to move the player in the next cell
	{
		if (choice == KEY_UP)
		{
			system("CLS");
			Coordinates temp = Curr.GetCuurentCoordinates();
			temp.SetRoomNo(Curr.GetRoomNo());
			PlayersPath.Push(temp);
			Curr.MoveUp();
		}
		else if (choice == KEY_RIGHT)
		{
			system("CLS");
			Coordinates temp = Curr.GetCuurentCoordinates();
			temp.SetRoomNo(Curr.GetRoomNo());
			PlayersPath.Push(temp);
			Curr.MoveRight();
		}
		else if (choice == KEY_DOWN)
		{
			system("CLS");
			Coordinates temp = Curr.GetCuurentCoordinates();
			temp.SetRoomNo(Curr.GetRoomNo());
			PlayersPath.Push(temp);
			Curr.MoveDown();
		}
		else if (choice == KEY_LEFT)
		{
			system("CLS");
			Coordinates temp = Curr.GetCuurentCoordinates();
			temp.SetRoomNo(Curr.GetRoomNo());
			PlayersPath.Push(temp);
			Curr.MoveLeft();
		}
	}
	void GasperCheck(Rooms& Current, char move, int& Random) // This is also for recursive implementation to check if theres a gasper in the next cell or not
	{
		system("CLS");
		Coordinates temp = Current.GetCuurentCoordinates();
		temp.SetRoomNo(Current.GetRoomNo());
		PlayersPath.Push(temp);
		if (move == KEY_UP)
		{
			Current.MoveUp();
		}
		else if (move == KEY_RIGHT)
		{
			Current.MoveRight();
		}
		else if (move == KEY_DOWN)
		{
			Current.MoveDown();
		}
		else if (move == KEY_LEFT)
		{
			Current.MoveLeft();
		}
		Random = 1;
		cout << "\nYou are Transferred to the Room With the Treasure By Gasper!!\n";
		Current = Roomptr[TreasureRoom];
	}
	void StartGame() // This Function Starts the Game with Iterative Implementation
	{
		srand(time(0));
		int RandomChoice = (rand() % NoofRooms) + 0;
		int NewChoice = 0;
		bool Game = true;
		RoomsPath.Push(Roomptr[RandomChoice]);  // Pushes the room in Room Stack
		Rooms CurrRoom = Roomptr[RandomChoice];
		while (Game == true)
		{
			LoadTitle();
			CurrRoom.Print(); // Print the Current Room
			int choice = _getch();
			choice = _getch();
			if (choice == KEY_UP)
			{
				if (CurrRoom.CheckUp() == 'X')
				{
					system("CLS");
					cout << "\n Cannot Move Upward \n ";
				}
				else if (CurrRoom.CheckUp() == '0')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveUp();
				}
				else if (CurrRoom.CheckUp() == 'D')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveUp();
					Game = false;
					cout << "\nYou are Eaten By the Devil!!!\n";
				}
				else if (CurrRoom.CheckUp() == 'G') // This is for Gasper Check-- > READ the RULES CAREFULLY to find the Role of Gasper
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveUp();
					RandomChoice = 1;
					RoomsPath.Push(Roomptr[0]);
					cout << "\nYou are Transferred to the Room With the Treasure By Gasper!!\n";
					CurrRoom = Roomptr[TreasureRoom];
				}
				else if (CurrRoom.CheckUp() == 'P')  // This is for Portal Check --> READ the RULES CAREFULLY to find the Role of Portal 
				{
					system("CLS");
					int NewChoice;
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveUp();
					srand(time(0));
					int Coin = (rand() % NoofRooms) + 0;
					cout << "You Have Reached The Portal \n Tossing Coin to Decide your FAITH....\n\n";
					if (Coin == 1)// 1->Head
					{
						cout << "\n Coin Results in Head \n You are Transferred to the Next Room By Portal!!\n";
						if (RandomChoice == 0)
							RandomChoice = 1;
						else
							RandomChoice = 0;
						RoomsPath.Push(Roomptr[RandomChoice]);
						CurrRoom = Roomptr[RandomChoice];
					}
					else
					{
						cout << "\n Coin Results in Tail !!! \n" << endl;
						RoomsPath.Pop();
						if (RoomsPath.GetStkPtr() == 0)
						{
							cout << "\n You are Out of the GAME !!! \n" << endl;
							Game = false;
						}
						else if (RoomsPath.GetStkPtr() != 0)
						{
							cout << "You are Transferred to the Previous Room By Portal!!\n";
							Rooms RoomData = RoomsPath.Top();
							int RoomNo = RoomData.GetRoomNo();
							CurrRoom = Roomptr[RoomNo];
						}
					}
				}
				else if (CurrRoom.CheckUp() == 'T')  // If treasur is found the Game Stops there
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveUp();
					Coordinates temp1 = CurrRoom.GetCuurentCoordinates();
					temp1.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp1);
					cout << "Treasure Found!!!!";
					Game = false;
				}
				else
				{
					system("CLS");
					cout << "\nYou have Reached the Boundary ...\n Move in another Direction\n";
					cout << endl;
				}
			}
			else if (choice == KEY_LEFT)  // Same Functions are Implemented for every Direction
			{
				if (CurrRoom.CheckLeft() == 'X')
				{
					system("CLS");
					cout << "\n Cannot Move Left \n ";
				}
				else if (CurrRoom.CheckLeft() == '0')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveLeft();
				}
				else if (CurrRoom.CheckLeft() == 'D')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveLeft();
					Game = false;
					cout << "\nYou are Eaten By the Devil!!!\n";
				}
				else if (CurrRoom.CheckLeft() == 'G')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveLeft();
					RandomChoice = 1;
					RoomsPath.Push(Roomptr[0]);
					cout << "\nYou are Transferred to the Room With the Treasure By Gasper!!\n";
					CurrRoom = Roomptr[TreasureRoom];
				}
				else if (CurrRoom.CheckLeft() == 'P')
				{
					system("CLS");
					int NewChoice;
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveLeft();
					srand(time(0));
					int Coin = (rand() % NoofRooms) + 0;
					cout << "You Have Reached The Portal \n Tossing Coin to Decide your FAITH....\n\n";
					if (Coin == 1)// 1->Head
					{
						cout << "\n Coin Results in Head \n You are Transferred to the Next Room By Portal!!\n";
						if (RandomChoice == 0)
							RandomChoice = 1;
						else
							RandomChoice = 0;
						RoomsPath.Push(Roomptr[RandomChoice]);
						CurrRoom = Roomptr[RandomChoice];
					}
					else
					{
						cout << "\n Coin Results in Tail !!! \n" << endl;
						RoomsPath.Pop();
						if (RoomsPath.GetStkPtr() == 0)
						{
							cout << "\n You are out of the Game !!!" << endl;
							Game = false;
						}
						else if (RoomsPath.GetStkPtr() != 0)
						{
							cout << "You are Transferred to the Previous Room By Portal!!\n";
							Rooms RoomData = RoomsPath.Top();
							int RoomNo = RoomData.GetRoomNo();
							CurrRoom = Roomptr[RoomNo];
						}
					}
				}
				else if (CurrRoom.CheckLeft() == 'T')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveLeft();
					cout << "Treasure Found!!!!";
					Coordinates temp1 = CurrRoom.GetCuurentCoordinates();
					temp1.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp1);
					Game = false;
				}
				else
				{
					system("CLS");
					cout << "\nYou have Reached the Boundary ...\n Move in another Direction\n";
					cout << endl;
				}
			}
			else if (choice == KEY_DOWN)
			{
				if (CurrRoom.CheckDown() == 'X')
				{
					system("CLS");
					cout << "\n Cannot Move Downward \n ";
				}
				else if (CurrRoom.CheckDown() == '0')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveDown();
				}
				else if (CurrRoom.CheckDown() == 'D')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveDown();
					Game = false;
					cout << "\nYou are Eaten By the Devil!!!\n";
				}
				else if (CurrRoom.CheckDown() == 'G')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveDown();
					RandomChoice = 1;
					RoomsPath.Push(Roomptr[0]);
					cout << "\nYou are Transferred to the Room With the Treasure By Gasper!!\n";
					CurrRoom = Roomptr[TreasureRoom];
				}
				else if (CurrRoom.CheckDown() == 'P')
				{
					system("CLS");
					int NewChoice;
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveDown();
					srand(time(0));
					int Coin = (rand() % NoofRooms) + 0;
					cout << "You Have Reached The Portal \n Tossing Coin to Decide your FAITH....\n\n";
					if (Coin == 1)// 1->Head
					{
						cout << "\n Coin Results in Head \n You are Transferred to the Next Room By Portal!!\n";
						if (RandomChoice == 0)
							RandomChoice = 1;
						else
							RandomChoice = 0;
						RoomsPath.Push(Roomptr[RandomChoice]);
						CurrRoom = Roomptr[RandomChoice];
					}
					else
					{
						cout << "\n Coin Results in Tail !!! \n" << endl;
						RoomsPath.Pop();
						if (RoomsPath.GetStkPtr() == 0)
						{
							cout << "\n You are out of the Game !!!" << endl;
							Game = false;
						}
						else if (RoomsPath.GetStkPtr() != 0)
						{
							cout << "You are Transferred to the Previous Room By Portal!!\n";
							Rooms RoomData = RoomsPath.Top();
							int RoomNo = RoomData.GetRoomNo();
							CurrRoom = Roomptr[RoomNo];
						}
					}
				}
				else if (CurrRoom.CheckDown() == 'T')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveDown();
					cout << "Treasure Found!!!!";
					Coordinates temp1 = CurrRoom.GetCuurentCoordinates();
					temp1.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp1);
					Game = false;
				}
				else
				{
					system("CLS");
					cout << "\nYou have Reached the Boundary ...\n Move in another Direction\n";
					cout << endl;
				}
			}
			else if (choice == KEY_RIGHT)
			{
				if (CurrRoom.CheckRight() == 'X')
				{
					system("CLS");
					cout << "\n Cannot Move Right \n ";
				}
				else if (CurrRoom.CheckRight() == '0')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveRight();
				}
				else if (CurrRoom.CheckRight() == 'D')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveRight();
					Game = false;
					cout << "\nYou are Eaten By the Devil!!!\n";
				}
				else if (CurrRoom.CheckRight() == 'G')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveRight();
					RandomChoice = 1;
					RoomsPath.Push(Roomptr[0]);
					cout << "\nYou are Transferred to the Room With the Treasure By Gasper!!\n";
					CurrRoom = Roomptr[TreasureRoom];
				}
				else if (CurrRoom.CheckRight() == 'P')
				{
					system("CLS");
					int NewChoice;
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveRight();
					srand(time(0));
					int Coin = (rand() % NoofRooms) + 0;
					cout << "You Have Reached The Portal \n Tossing Coin to Decide your FAITH....\n\n";
					if (Coin == 1)// 1->Head
					{
						cout << "\n Coin Results in Head \n You are Transferred to the Next Room By Portal!!\n";
						if (RandomChoice == 0)
							RandomChoice = 1;
						else
							RandomChoice = 0;
						RoomsPath.Push(Roomptr[RandomChoice]);
						CurrRoom = Roomptr[RandomChoice];
					}
					else
					{
						cout << "\n Coin Results in Tail !!!\n " << endl;
						RoomsPath.Pop();
						if (RoomsPath.GetStkPtr() == 0)
						{
							cout << "\n You are out of the Game !!!" << endl;
							Game = false;
						}
						else if (RoomsPath.GetStkPtr() != 0)
						{
							cout << "You are Transferred to the Previous Room By Portal!!\n";
							Rooms RoomData = RoomsPath.Top();
							int RoomNo = RoomData.GetRoomNo();
							CurrRoom = Roomptr[RoomNo];
						}
					}
				}
				else if (CurrRoom.CheckRight() == 'T')
				{
					system("CLS");
					Coordinates temp = CurrRoom.GetCuurentCoordinates();
					temp.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp);
					CurrRoom.MoveRight();
					cout << "Treasure Found!!!!";
					Coordinates temp1 = CurrRoom.GetCuurentCoordinates();
					temp1.SetRoomNo(CurrRoom.GetRoomNo());
					PlayersPath.Push(temp1);
					Game = false;
				}
				else
				{
					system("CLS");
					cout << "\nYou have Reached the Boundary ...\n Move in another Direction\n";
					cout << endl;
				}
			}
			else if (choice == 'Q' || choice == 'q')
			{
				system("CLS");
				cout << "Game Ended " << endl << endl;;
				Game = false;
			}
			else
			{
				cout << "Invalid Input \n Enter Again " << endl;
				system("pause");
				system("CLS");
			}
		}
		cout << endl;
		system("pause");
		cout << endl;
		system("CLS");
		int i = 0;
		for (i = 0; i < NoofRooms; i++)
		{
			if (Roomptr[i].IsTreasure())  // Findinf the Treasure Room to Print the Coordinates of treasure
			{
				TreasureRoom = i;
				break;
			}
		}
		cout << "Treasur was in Room No " << i << " at Coordinates :";
		Roomptr[i].PrintTreasureCoordinates();
		cout << "Path of the Player is : " << endl;
		PlayersPath.PrintStack();
		system("pause");
		cout << endl;
	}
	void StartGameRecursively(Rooms Current, int Random)  // This is for Recursive Implementation of the Game
	{
		int move = _getch();
		move = _getch();
		if (move == KEY_UP)
		{
			if (!Current.CheckUp())  // Same Checks are applied in this function also but with RECURSIVE IMPLEMENTATION
			{
				system("CLS");
				Current.Print();
				cout << "\n Boundary Reached \nMove in another Direction\n ";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckUp() == 'X')
			{
				system("CLS");
				Current.Print();
				cout << "\nCannot Move Upward...\n Move in another Direction\n";
				cout << endl;
				StartGameRecursively(Current, Random);

			}
			else if (Current.CheckUp() == 'T')
			{
				system("CLS");
				cout << "Treasure Found!!!!";
				Coordinates temp = Current.GetCuurentCoordinates();
				temp.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp);
				Current.MoveUp();
				Coordinates temp1 = Current.GetCuurentCoordinates();
				temp1.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp1);
				cout << endl << endl;
				return;
			}
			else if (Current.CheckUp() == 'D')
			{
				system("CLS");
				cout << "You have been EATEN by the Devil...!!!!\n\tGAME OVER ";
				cout << endl << endl;
				return;
			}
			else if (Current.CheckUp() == 'P')
			{
				bool GameCheck;
				PortalCheck(move, Random, Current, GameCheck);
				if (GameCheck == false)
					return;
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckUp() == 'G')
			{
				GasperCheck(Current, move, Random);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else
			{
				MovementCheck(move, Current);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
		}
		else if (move == KEY_LEFT)
		{
			if (!Current.CheckLeft())
			{
				system("CLS");
				Current.Print();
				cout << "\n Boundary Reached \nMove in another Direction\n ";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckLeft() == 'X')
			{
				system("CLS");
				Current.Print();
				cout << "\nCannot Move Left...\n Move in another Direction\n";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckLeft() == 'T')
			{
				system("CLS");
				cout << "Treasure Found!!!!";
				Coordinates temp = Current.GetCuurentCoordinates();
				temp.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp);
				Current.MoveLeft();
				Coordinates temp1 = Current.GetCuurentCoordinates();
				temp1.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp1);
				cout << endl << endl;
				return;
			}
			else if (Current.CheckLeft() == 'D')
			{
				system("CLS");
				cout << "You have been EATEN by the Devil...!!!!\n\tGAME OVER ";
				cout << endl << endl;
				return;
			}
			else if (Current.CheckLeft() == 'P')
			{
				bool GameCheck;
				PortalCheck(move, Random, Current, GameCheck);
				if (GameCheck == false)
					return;
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckLeft() == 'G')
			{
				GasperCheck(Current, move, Random);
				Current.Print();
				StartGameRecursively(Current, Random);  // For Suhaib -->Implement this function . it is not implemented
			}
			else
			{
				MovementCheck(move, Current);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
		}
		else if (move == KEY_DOWN)
		{
			if (!Current.CheckDown())
			{
				system("CLS");
				Current.Print();
				cout << "\n Boundary Reached \nMove in another Direction\n ";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckDown() == 'X')
			{
				system("CLS");
				Current.Print();
				cout << "\nCannot Move Downward...\n Move in another Direction\n";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckDown() == 'T')
			{
				system("CLS");
				cout << "Treasure Found!!!!";
				Coordinates temp = Current.GetCuurentCoordinates();
				temp.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp);
				Current.MoveDown();
				Coordinates temp1 = Current.GetCuurentCoordinates();
				temp1.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp1);
				cout << endl << endl;
				return;
			}
			else if (Current.CheckDown() == 'D')
			{
				system("CLS");
				cout << "You have been EATEN by the Devil...!!!!\n\tGAME OVER ";
				cout << endl << endl;
				return;
			}
			else if (Current.CheckDown() == 'P')
			{
				bool GameCheck;
				PortalCheck(move, Random, Current, GameCheck);
				if (GameCheck == false)
					return;
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckDown() == 'G')
			{
				GasperCheck(Current, move, Random);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else
			{
				MovementCheck(move, Current);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
		}
		else if (move == KEY_RIGHT)
		{
			if (!Current.CheckRight())
			{
				system("CLS");
				Current.Print();
				cout << "\n Boundary Reached \nMove in another Direction\n ";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckRight() == 'X')
			{
				system("CLS");
				Current.Print();
				cout << "\nCannot Move Right...\n Move in another Direction\n";
				cout << endl;
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckRight() == 'T')
			{
				system("CLS");
				cout << "Treasure Found!!!!";
				Coordinates temp = Current.GetCuurentCoordinates();
				temp.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp);
				Current.MoveRight();
				Coordinates temp1 = Current.GetCuurentCoordinates();
				temp1.SetRoomNo(Current.GetRoomNo());
				PlayersPath.Push(temp1);
				cout << endl << endl;
				return;
			}
			else if (Current.CheckRight() == 'D')
			{
				system("CLS");
				cout << "You have been EATEN by the Devil...!!!!\n\tGAME OVER ";
				cout << endl << endl;
				return;
			}
			else if (Current.CheckRight() == 'P')
			{
				bool GameCheck;
				PortalCheck(move, Random, Current, GameCheck);
				if (GameCheck == false)
					return;
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else if (Current.CheckRight() == 'G')
			{
				GasperCheck(Current, move, Random);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
			else
			{
				MovementCheck(move, Current);
				Current.Print();
				StartGameRecursively(Current, Random);
			}
		}
		else if (move == 'Q' || move == 'q')
		{
			system("cls");
			cout << "Game Ended" << endl << endl;
			return;
		}
		else
		{
			cout << "Invalid Input \n Enter Again\n";
			StartGameRecursively(Current, Random);
		}
	}
	void WrapperRecurr()  // This is a Wrapper Function to Call the above Recursive Function 
	{
		srand(time(0));
		int Random = (rand() % NoofRooms) + 0;
		Rooms Curr = Roomptr[Random];
		Curr.Print();
		StartGameRecursively(Curr, Random);
		cout << endl;
		system("pause");
		cout << endl;
		system("CLS");
		int i = 0;
		for (i = 0; i < NoofRooms; i++)
		{
			if (Roomptr[i].IsTreasure())
			{
				TreasureRoom = i;
				break;
			}
		}
		cout << "Treasur was in Room No " << i << " at Coordinates :";
		Roomptr[i].PrintTreasureCoordinates();
		PlayersPath.PrintStack();
	}
};
void Menu()
{
	cout << "							Welcome to Treasure Hunt Game " << endl;
	cout << "							By: Abdul Tawab (L21-5422) " << endl;
	cout << endl << endl;
	LoadRules();
	system("pause");
	system("CLS");
	int choice = 0;
	cout << "Which Implementation would you like to Use\n 1->ITERATIVE \n 2->RECURSIVE\n\n";
	cin >> choice;
	system("CLS");
	if (choice == 1)
	{
		Game TH;
		TH.ReadData();
		TH.StartGame();
	}
	else
	{
		Game TH;
		TH.ReadData();
		TH.WrapperRecurr();
	}
}
int main()
{
	system("color 74");
	Menu();
}