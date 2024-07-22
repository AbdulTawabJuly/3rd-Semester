//#include<iostream>
//using namespace std;
//
//bool IsSorted(int arr[], int idex)
//{
//	
//	if (idex == (sizeof(arr)/sizeof(arr[0]))-1)
//	{
//		return true;
//	}
//	if (arr[idex] < arr [idex + 1])
//	{
//		return IsSorted(arr, idex + 1);
//	}
//	else
//	{
//		return false;
//	}
//}
//
//int main()
//{
//	int arr[] = { 1,3,5,4 };
//
//	int idex = (sizeof(arr) / sizeof(arr[0])) ;
//
//	cout<<IsSorted(arr, 0);
//
//}