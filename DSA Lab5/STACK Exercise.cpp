#include<iostream>
using namespace std;

template<class T>
class Stack
{
private:
	T* arr;
	int max_size;
	int stkptr;
public:
	Stack(int s=10)
	{
		arr = new T[s];
		max_size = s;
		stkptr = 0;
	}

	bool IsFull()
	{
		return (stkptr == max_size);
	}

	bool Push(T d)
	{
		if (! IsFull())
		{
			arr[stkptr] = d;
			stkptr++;
			return true;
		}
		return false;
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

	bool Top(T d)
	{
		if (!IsEmpyt())
		{
			d = arr[stkptr-1];
			return true;
		}
		return false;
	}

	void Pop()
	{
		if (!IsEmpyt())
		{
			--stkptr;
			cout << "POPED" << endl;
			return;
		}
		else
		{
			cout << "STACK EMPYT" << endl;
			return;
		}
	}


	bool IsBalanced(char* str)
	{
		char ch;
		Stack<char>obj(strlen(str));
		for (int i = 0; str[i] != '\0'; i++)
		{
			if (str[i] == '[' || str[i] == '{' || str[i] == '(')
			{
				obj.Push(str[i]);
			}
			else if (str[i] == ']' || str[i] == '}' || str[i] == ')')
			{
				if (str[i] == ']')
				{
					if (obj.Top('['))
					{
						obj.Pop();
					}
					else
					{
						cout << "Not Balanced" << endl;
						return false;
					}

				}
				else if (str[i] == '}')
				{
					if (obj.Top('{'))
					{
						obj.Pop();
					}
					else
					{
						cout << "Not Balanced" << endl;
						return false;
					}
				}
				else if (str[i] == ')')
				{
					if (obj.Top('('))
					{
						obj.Pop();
					}
					else
					{
						cout << "Not Balanced" << endl;
						return false;
					}
				}
			}
		}
		cout << "Balanced" << endl;
		return true;
	}

	void Print()
	{
		int i = 0;
		while (i!=stkptr)
		{
			cout << arr[i] << " ";
			i++;
		}
	}
};

int main()
{
	Stack <char>obj(7);
	obj.Push('{');          
	obj.Push('[');
	obj.Push('{');
	obj.Push('}');
	obj.Push('{');
	obj.Push('{');
	obj.Push(']');

	obj.Print();
	cout << endl;
	char arr[] = {'{','[','{','}','{','}' ,']','}','[','(',')',']','{','{','}','{','}' ,'}'};
	obj.IsBalanced(arr);





}