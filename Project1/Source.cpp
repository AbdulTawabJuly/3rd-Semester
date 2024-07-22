#include<iostream>
using namespace std;

template<typename T1,typename T2>

T1 Sum(T1 a,T2 b)
{
	return a + b;
}

template <class identifier,class identifier2>
identifier2 Product(identifier a,identifier2 b)
{
	return a * b;
}

int main()
{
	cout << Sum(1.2345,-1)<<endl;
	cout << Product(2, 2.3456);
}