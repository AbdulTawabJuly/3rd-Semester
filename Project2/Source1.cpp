#include<iostream>
#include<string>
#include<string.h>

using namespace std;
long Fact(int n)
{
	if (n == 0 || n == 1) { return 1; }
	else { return Fact(n - 1) * n; }
}

void swap(char& arr1, char& arr2)
{
	char temp = arr1;
	arr1 = arr2;
	arr2 = temp;
}
void ReverseString(char arr[], int s, int e)
{
	if (s < e)
	{
		swap(arr[s], arr[e]);
		ReverseString(arr, s + 1, e - 1);
	}
}
int main()
{
	int m = Fact(5);
	cout << m;
	cout << endl;
	char arr[] = { 'A','B','C','D','E','\0'};
	ReverseString(arr, 0, 4);
	int i = 0;
	while (arr[i] != '\0')
	{
		cout << arr[i];
		i++;
	}
	
}