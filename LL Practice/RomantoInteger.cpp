//#include<iostream>
//#include<stdio.h>
//using namespace std;
//
//char ReturnCharacter(char c)
//{
//	switch (c)
//	{
//	case 'I':return 1;
//	case 'V':return 5;
//	case 'X':return 10;
//	case 'L':return 50;
//	case 'C':return 100;
//	case 'D':return 500;
//	case 'M':return 1000;
//	default: return -1;
//	}
//
//}
//int RomantoInteger(char arr[])
//{
//	int size1 = sizeof(arr);
//	cout << size1;
//	int current = 0, next = 0, result = 0;
//	for (int i = 0; i < size1; i++)
//	{
//		current = ReturnCharacter(arr[i]);
//		next = ReturnCharacter(arr[i + 1]);
//		if (i == size1 )
//		{
//			result += ReturnCharacter(arr[i]);
//			return result;
//		}
//		if (current > next)
//		{
//			result += current;
//			i++;
//		}
//		else if (next > current)
//		{
//			result += next - current;
//			i += 2;
//		}
//
//	}
//	return result;
//}
//int main()
//{
//	char arr[] = { 'I','I','I'};
//	cout<< RomantoInteger(arr);
//}