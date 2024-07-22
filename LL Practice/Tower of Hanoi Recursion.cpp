#include<iostream>
#include<string>
using namespace std;

void TowerofHanoi(int n, string src, string helper, string dest)
{
	if (n == 1)
	{
		cout << "Tranfer Disk " << n << " from " << src << " to " << dest << endl;
		return;
	}

	TowerofHanoi(n - 1, src, dest, helper);
	cout << "Tranfer Disk " << n << " from " << src << " to " << dest << endl;
	TowerofHanoi(n - 1, helper, src, dest);
}

int main()
{
	int n = 3;
	TowerofHanoi(n, "S", "H","D");

	return 0;
}