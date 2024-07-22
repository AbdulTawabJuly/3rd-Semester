//#include<iostream>
// 
////Question Find x^n
//// Stack Height n 
//
//using namespace std;
//int CalcPower(int x, int n)
//{
//	if (n == 0)
//	{
//		return 1;
//	}
//	if (x == 0)
//	{
//		return 0;
//	}
//	int xPowmn1 = CalcPower(x, n - 1);
//	int xPown = x * xPowmn1;
//	return xPown;
//}
//
//int main()
//{
//	int x = 2, n = 5;
//	int ans=CalcPower(x, n);
//	cout << ans << endl;
//	return 0;
//
//}