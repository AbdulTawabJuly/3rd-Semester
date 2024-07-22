//#include<iostream>
//using namespace std;
//bool Bears(int n)
//{
//	if (n == 42)
//	{
//		cout << "You have Reached the Goal"<<endl;
//		return true;
//	}
//	else if (n < 42)
//	{
//		cout << "Goal Not Achieved" << endl;
//		return false;
//	}
//	else
//	{
//		if (n % 2 == 0)
//		{
//			Bears(n / 2);
//		}
//		else if (n % 3 == 0 || n % 4 == 0)
//		{
//			int First = n % 10;
//			int Second = (n % 100)/10;
//			Bears(First * Second);
//		}
//		else if (n % 5 == 0)
//		{
//			Bears(42);
//		}
//		else
//		{
//			cout << "Goal Not Achieved" << endl;
//		}
//
//	}
//}
//int main()
//{
//	Bears(250);
//	Bears(42);
//	Bears(84);
//	Bears(53);
//	Bears(41);
//}