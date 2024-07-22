#include<iostream>
using namespace std;
int IsMember(int arr[],int size,int key)
{
	if (size <= 0)
		return 0;
	else
	{
		if (arr[size - 1] == key)
		{
			return 1;
		}
		else
		{
			return IsMember(arr, size - 1, key);
		}
	}
}

long Factorial(int n,long m)
{
	if (n == 0)
	{
		return 1;
	}
	m = Factorial(n - 1,m) * n;
	cout << m << " ";
	return m;

}
void Swap(float &num1, float &num2)
{
	float temp = num1;
	num1 = num2;
	num2 = temp;
}

void FlipArr(float arr[],int start,int end)
{
	if (start < end)
	{
		Swap(arr[start], arr[end]);
		FlipArr(arr, start + 1, end - 1);
	}
}

int SumDigit(int n)
{
	if (n < 9)
	{
		return n;
	}
	else
	{
		return ((n % 10) + SumDigit(n / 10));
	}
}

int CompareString(char const* str1,char const* str2)
{
	if (strlen(str1) != strlen(str2))
	{
		return -1;
	}
	else if (strlen(str1) == 1)
	{
		if (str1[0] == str2[0])
		{
			return 0;
		}
		else if (str1[0] > str2[0])
		{
			return 1;
		}
		else
			return -1;
	}
	else
	{
		if (str1[0] == str2[0])
		{
			CompareString(str1 + 1, str2 + 1);
		}
		else if (str1[0] >str2[0])
		{
			return 1;
		}
		else
			return -1;
	}
}

int main()
{
	//Task 1
	int arr1[10] = { 1,2,3,4,5,6,7,8,9,10 };
	cout << IsMember(arr1, 10, 12);
	cout << endl;
	//Task 2
	long m = 0;
	Factorial(5,m);
	cout << endl;
	//Task 3
	cout << SumDigit(725);
	cout << endl;
	//Task 4
	float arr2[10] = { 1.1,2.2,3.3,4.4,5.5,6.6,7.7,8.8,9.9,10.1 };
	FlipArr(arr2, 0, 9);
	for (int i = 0; i < 10; i++)
	{
		cout << arr2[i] << " ";
	}
	cout << endl;
	// Task 5
	cout << CompareString("abce", "abcf");

}