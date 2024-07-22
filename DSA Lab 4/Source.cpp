#include <iostream>
using namespace std;

template <class T>

class List {
private:
	class Node 
	{
	public:
		T data;
		Node* next;
	};

	Node* head;
	Node* tail;

public:
	class iterator {
	private:
		friend class List;
		Node* curr;

	public:
		iterator() {
			curr = nullptr;
		}

		int operator *() {
			return curr->data.returnSIZE();
		}

		int operator &() {
			return curr->data.returnID();
		}

		void Alter(int NEW) {
			curr->data.AlterStartID(NEW);
		}


	};

	iterator begin() {
		iterator it;
		it.curr = head;

		return it;
	}

	iterator end() {
		iterator it;
		it.curr = tail;

		return it;
	}

	List() {
		head = tail = nullptr;
	}

	void insertStart(T d) {
		Node* temp = new Node;
		temp->data = d;
		temp->next = head;
		if (head == nullptr)
			head = tail = temp;
		else
			head = temp;
	}

	void insertEnd(T d) {
		if (head == nullptr)
			insertStart(d);
		else {
			Node* temp = new Node;
			temp->data = d;
			temp->next = nullptr;
			tail->next = temp;
			tail = temp;

		}
	}

	void Print() {
		Node* curr = head;
		while (curr != nullptr) {
			cout << curr->data;
			curr = curr->next;
		}

		cout << endl;
	}

	bool Search(T d) {
		Node* curr = head;
		while (curr != nullptr) {
			if (d == curr->data)
				return true;
			curr = curr->next;
		}
		return false;
	}

	bool isEmpty() {
		if (head == nullptr)
			return true;
		else return false;
	}


	void deleteStart() {
		if (head != nullptr) {
			Node* temp = head;
			head = head->next;
			delete temp;
		}
		else tail = nullptr;
	}

	void deleteEnd() {
		if (head != nullptr) {
			if (head == tail) {
				delete head;
				head = tail = nullptr;
			}
			else {
				Node* temp = head;
				while (temp->next != tail) {
					temp = temp->next;
				}
				delete tail;
				tail = temp;
				tail->next = nullptr;
			}
		}
	}


	/*~List() {
		while (head)
			deleteStart();
	}*/


};


class Block {
private:
	int startID;
	int total;

public:
	Block() {
		startID = total = 0;
	}

	Block(int id, int t) {
		startID = id;
		total = t;
	}

	void AlterStartID(int nSIZE) {
		startID += nSIZE;
		total -= nSIZE;
		cout << total << " " << nSIZE << endl;
	}

	int returnSIZE() {
		return total;
	}

	int returnID() {
		return startID;
	}

};


class Program {
private:
	int ID;
	int size;
	List <Block> Blocks;

public:
	Program() {
		ID = size = 0;
	}

	Program(int id, int start, int total) {
		ID = id;
		size = total;

		Block temp(start, total);
		Blocks.insertEnd(temp);


	}

	int returnSIZE() {
		return size;
	}

	int returnID() {
		return ID;
	}

};



class MemManagement {
private:

	List <Block> Pool;
	List <Program> Programs;

	bool strategy;
	int sizeMem;

public:
	MemManagement(int s) {
		sizeMem = s;
		strategy = true;

		Block p(0, sizeMem);
		Pool.insertEnd(p);

		List < Block > ::iterator irt;
		irt = Pool.begin();
		cout << *irt << endl;
		cout << &irt << endl;
	}

	void check(int s) {
		if (s <= sizeMem) strategy = true;
		else strategy = false;
	}

	void getMem(int id, int s) {
		check(s);

		if (strategy == false) cout << "Memory not available. " << endl;

		else {
			List < Block > ::iterator irt;
			irt = Pool.begin();

			Program temp(id, &irt, s);
			Programs.insertEnd(temp);
			irt.Alter(s);

		}

	}

};



int main() {
	MemManagement RAM(1000);
	RAM.getMem(1, 100);

	system("pause");
	return 0;
}