
//-----------------------------STAR GROUPING PROJECT--------------------------------	


//			*************************************************
//			*			COPYRIGHTS @						*
//			*												*
//			*		MUHAMMAD SHEHARYAR MOHSIN	(18L-1137)	*
//			*		ZUHAIB SOHAIL				(18L-0997)	*
//			*		ALI HAMZA					(18L-1038)  *
//			*												*
//			*												*
//			*************************************************


#include <iostream>
#include <assert.h>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <list>

using namespace std;

struct HeapItem
{
	float distance;				//Store Distances
	int group1;
	int group2;

	HeapItem()					//Default Constructor
	{
	}

	HeapItem(float dist, int g1, int g2)		//Overloaded Constructor for HeapItems
	{
		this->distance = dist;
		this->group1 = g1;
		this->group2 = g2;
	}

	void operator = (HeapItem* obj)			//Overloaded Assignment Operator
	{
		this->distance = obj->distance;
		this->group1 = obj->group1;
		this->group2 = obj->group2;
	}
	friend void groupingPoints(string nm);				//Friend Function to Access Variables
};

class minHeap
{
	vector<HeapItem> arr;					//Vector of HeapItem
	int capacity;
	int totalItems;

public:

	minHeap()						//Default Constructor
	{
		this->capacity = 0;
		this->totalItems = 0;
	}

	minHeap(int _capacity)
	{
		this->capacity = _capacity;
		this->totalItems = 0;
	}

	void reHeapUp(int root, int cNode)				//Heapify Function for Reheap Up
	{
		int parent = 0;
		if (root < cNode)
		{
			parent = (cNode - 1) / 2;
		}
		if (arr[parent].distance > arr[cNode].distance)
		{
			swap(arr[parent], arr[cNode]);
			reHeapUp(root, parent);
		}
	}

	void reHeapDown(int cNode, int last)			//Heapify Function for Reheap Down
	{
		int minChild = 0, LeftChild = (2 * cNode) + 1, rChild = (2 * cNode + 2);

		if (cNode <= last)
		{
			if (cNode == last)
				minChild = LeftChild;
			else
			{
				if (arr[LeftChild].distance > arr[rChild].distance)
					minChild = rChild;
				else
					minChild = LeftChild;
			}

			if (arr[cNode].distance > arr[minChild].distance)
			{
				swap(arr[cNode], arr[minChild]);
				reHeapDown(minChild, last);
			}
		}
	}

	void insertVector(HeapItem vctr)				//Insert Function for Vectors
	{
		arr.push_back(vctr);
		reHeapUp(0, arr.size() - 1);
	}

	void deleteMin()							//Delete minimum value from heap
	{
		swap(arr[0], arr[arr.size() - 1]);
		arr.pop_back();
		reHeapDown(0, (arr.size() / 2) - 1);

	}

	void MinH(HeapItem& val)					//It gives us minimum value of heap
	{
		val.distance = arr[0].distance;
		val.group1 = arr[0].group1;
		val.group2 = arr[0].group2;

	}

	void Myswap(vector<HeapItem>& tmp, int i, int j)		//Swap Function for Vectors
	{
		swap(tmp[i], tmp[j]);
	}

	bool isEmpty()							//Check whether Heap is Empty or Not
	{
		if (totalItems == 0)
			return true;
		else
			return false;
	}

	~minHeap()							//DESTRUCTOR
	{
		//As we are using vectors so we don't need to delete array of vectors
	}

	friend void groupingPoints(string filename);			//Friend Function to Access Private Variables
};



struct Points
{
	float x = 0;
	float y = 0;

	Points()
	{
		x = 0;
		y = 0;
	}

	Points(float _x, float _y)
	{
		x = _x;
		y = _y;
	}

	friend ostream& operator <<(ostream& out, Points& pt);			//Overloaded Insertion Operator

	Points& operator = (Points& pt)				//overloaded Assignment Operator
	{
		x = pt.x;
		y = pt.y;
		return *this;
	}

	~Points()				//Destructor
	{
	}
};

ostream& operator <<(ostream& out, Points& pt)				//Overload Insertion operator
{
	out << "(" << pt.x << " , " << pt.y << ") ";
	return out;
}

float calculateDistance(Points* P1, Points* P2)
{
	return (sqrt(pow((P1->x - P2->x), 2) + pow((P1->y - P2->y), 2)));		//Calculates Euclidean Distance according to given formula
}

void groupingPoints(string filename)
{
	vector<vector<int>> matrix;				//2D Matrix for Storing Variables
	vector<list<int>> list1;
	minHeap ptHeap;
	HeapItem tmp1;
	ifstream fin;
	fin.open(filename);
	if (fin.is_open())
	{
		int totalPts = 0, rqdGrps = 0;
		float x = 0, y = 0, dist = 0;

		fin >> totalPts;
		fin.ignore();
		fin >> rqdGrps;
		fin.ignore();
		Points** arr = new Points * [totalPts];		//2D Array of Points
		for (int i = 0; i < totalPts; i++)
		{
			fin >> x;
			fin.ignore();
			fin >> y;
			fin.ignore();
			arr[i] = new Points(x, y);
		}

		matrix.resize(totalPts);					//Assign Size to Matrix
		for (int i = 0; i < totalPts; i++)
		{
			matrix[i].resize(totalPts);
		}
		list1.resize(totalPts);
		for (int i = 0; i < totalPts; i++)
		{
			list1[i].push_back(i);
		}

		//Building Heap from the points

		for (int i = 0; i < totalPts; i++)
		{
			for (int j = i + 1; j < totalPts; j++)
			{
				tmp1.distance = calculateDistance(arr[i], arr[j]);
				//dist = calculateDistance(arr[i], arr[j]);
				tmp1.group1 = i;
				tmp1.group2 = j;
				ptHeap.insertVector(tmp1);
				//ptHeap.insert(dist, *arr[i]);
			}
		}

		//Storing Index in Matrix according to Calculated Distances

		for (int i = 0; i < (totalPts * (totalPts - 1)) / 2; i++)
		{
			int row = ptHeap.arr[i].group1;
			int col = ptHeap.arr[i].group2;
			matrix[row][col] = i;
		}

		for (int count = totalPts; count != rqdGrps;)
		{
			ptHeap.MinH(tmp1);
			ptHeap.deleteMin();
			int m = 0;
			while (m < ptHeap.arr.size())					//Updating Matrix According to Updated Distances
			{
				int row = ptHeap.arr[m].group1;
				int col = ptHeap.arr[m].group2;
				if (row != tmp1.group2 || col != tmp1.group2)
				{
					matrix[row][col] = m;
				}
				//cout << matrix[row][col] << " ";			//Function Used to Print Matrix Entries
				m++;
			}
			if (list1[tmp1.group1].size() != 0 && list1[tmp1.group2].size() != 0)
			{
				list1[tmp1.group1].merge(list1[tmp1.group2]);			//Using Built-in Merge Function to Merge Matrices
				float MinDist;
				int j = tmp1.group2 + 1;
				while (j < totalPts)
				{
					int dist2 = ptHeap.arr[matrix[tmp1.group1][j]].group2;
					MinDist = calculateDistance(arr[dist2], arr[tmp1.group1]);
					list<int>::iterator itr = list1[tmp1.group1].begin();
					for (itr = list1[tmp1.group1].begin(); itr != list1[tmp1.group1].end(); itr++)
					{
						MinDist = min(MinDist, calculateDistance(arr[*itr], arr[dist2]));		//Calculates Minimum Distance between Grouped Points
					}
					ptHeap.arr[matrix[tmp1.group1][j]].distance = MinDist;		//Updates Distance--- Selects Minimum Distance Among Grouped Points
					j++;
				}
				count--;
			}
		}

		//Printing of Grouped Points

		int grpNmbr = 0;
		for (int i = 0; i < list1.size(); i++)
		{
			list<int>::iterator itr = list1[i].begin();

			if (list1[i].size() != 0)
			{
				cout << "Group " << grpNmbr + 1 << ": ";
				grpNmbr = grpNmbr + 1;
				while (itr != list1[i].end())
				{
					cout << *arr[*itr];					//Prints Points In Group
					itr++;
				}
				cout << endl;
			}
		}

		/*for (int i = 0; i < 3; i++)					//TEST FUNCTION TO CHECK PROGRAM MATRIX
		{
		for (int j = 0; j < 3; j++)
		{
		cout << matrix[i][j] << "\t";
		}
		cout << endl;
		}*/
		cout << endl;
		fin.close();
	}
	else
		cout << "Unable to Find Input File\n";
}

void main()
{
	cout << "INPUT THE STAR DISTANCE FILE PLEASE\n";
	cout << "(File Name is \'Points.txt\' By Default)\n\n";

	string filename;
	cin >> filename;
	groupingPoints(filename);
	system("PAUSE");
}

//**********************************************************************//
//18L-1137	Muhammad Sheharyar Mohsin
//18L-1038	Ali Hamza
//18L-0997	Zuhaib Sohail
//CS-A
//**********************************************************************//