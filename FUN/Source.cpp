#include<iostream>
using namespace std;

template< class T>
class List
{
private:
	class Node
	{
	public:
		T data;
		Node* next;
		Node()
		{
			next = nullptr;
		}
	};
		Node* head;
		Node* tail;
public:
		class Iterator
		{
			friend class List<T>;
		private:
			Node* curr;

			Iterator(Node* c)
			{
				curr = c;
			}

		public:

			bool Not_Null()
			{
				if (curr == nullptr)
				{
					return true;
				}

				else
				{
					return false;
				}
			}

			bool Not_Next_Null()
			{
				if (curr->next == nullptr)
				{
					return true;
				}

				else
				{
					return false;
				}
			}

			Iterator& First()
			{
				Iterator it(head->next);
				return it;
			}

			Iterator& Next()
			{
				return curr->next;
			}

		};
	
};
