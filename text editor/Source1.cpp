#include <fstream>
#include <iostream>
#include <stdlib.h>
# include "Header1.h"
# include "Header.h"

using namespace std;

//-------------------------------POINT CLASS------------------------------//
//initialize MaxPoint
point point::MaxPoint(MAX_X, MAX_Y);
bool point::incrementX()
{
	bool returnValue = true;
	if (x < MaxPoint.x)
		x++;
	else if (y < MaxPoint.y)
	{
		x = 0;
		y = y + 1;
	}
	else
		returnValue = false;

	return returnValue;
}

bool point::incrementY()
{
	bool returnValue = true;
	if (y < MaxPoint.y)
		y++;
	else
		returnValue = false;

	return returnValue;

}
bool point::decrementX()
{
	bool returnValue = true;
	if (x > 0)
		x--;
	else
		returnValue = false;

	return returnValue;
}
bool point::decrementY()
{
	bool returnValue = true;
	if (y > 0)
		y--;
	else
		returnValue = false;

	return returnValue;

}

//-------------------------------END OF POINT CLASS------------------------------------------------//


//--------------------------The function Where you will write code--------------------------------//
int mainEditor()
{
	int key = 0;
	bool stop = false;
	point currentPosition(0, 0);
	currentPosition.setMaxPoint(MAX_X, MAX_Y);
	bool specialKey = false;
	linklist list;
	linklist::iterator i;
	i = list.end();
	stack undokey;
	while (!stop)
	{
		key = CheckWhichKeyPressed(specialKey);
		//escape key
		if (key == ESCKEY)
		{
			stop = true;
			//printable character...only adds to the end of text
			//this will not do insertions in between text
		}//add code here to insert characters within text
		else if (!specialKey && key >= 32 && key <= 126)
		{
			if (currentPosition.getX() < MAX_X)
			{
				cout << (char)key;
				//You can change color of text by calling this function
				list.insert(i, key, currentPosition);
				undokey.push(i, true, nullptr, key);
				SetColorAtPoint(currentPosition.getX(), currentPosition.getY(), F_BLACK | B_White);   //ForeGround|BackGround
				currentPosition.incrementX();
			}
			else if (currentPosition.getY() < MAX_Y)
			{
				cout << '\n';
				currentPosition.incrementY();
				currentPosition.setX(0);
				cout << (char)key;
				list.insert(i, key, currentPosition);
				undokey.push(i, true, nullptr, key);
				currentPosition.incrementX();
			}

		}
		else if (specialKey && key == LEFTKEY)
		{

			if (currentPosition.getY() > 0 && currentPosition.getX() == 0)
			{
				--i;
				currentPosition.set(i.getcurrent()->pos.getX(), i.getcurrent()->pos.getY());
			}
			else
			{
				if (i.getcurrent()->priv != list.bigen().getcurrent()->priv)
				{
					--i;
				}
				currentPosition.set(i.getcurrent()->pos.getX(), i.getcurrent()->pos.getY());
			}

		}
		else if (specialKey && key == RIGHTKEY)
		{

			if (i.getcurrent()->data != '\0' && currentPosition.getX() == (i.getcurrent()->pos.getX()))
			{
				++i;
				currentPosition.set(i.getcurrent()->pos.getX(), i.getcurrent()->pos.getY());
			}
			else
			{
				if (currentPosition.getX() < list.end().getcurrent()->pos.getX())
					if (i.getcurrent()->next != nullptr)
					{
						++i;
					}
				currentPosition.set(i.getcurrent()->pos.getX(), i.getcurrent()->pos.getY());
			}

		}
		else if (specialKey && key == UPKEY)
		{
			list.searchhorizontal(true, i);
			currentPosition.set(i.getcurrent()->pos.getX(), i.getcurrent()->pos.getY());
		}
		else if (specialKey && key == DOWNKEY)
		{	//Update it so that cursur not move downword if it is at last line of text.
			list.searchhorizontal(false, i);
			currentPosition.set(i.getcurrent()->pos.getX(), i.getcurrent()->pos.getY());
		}
		else if (key == ENTERKEY) {

			cout << ('\n');
			list.insert(i, '\n', currentPosition);
			undokey.push(i, true, nullptr, '\n');
			currentPosition.setX(0);
			currentPosition.incrementY();
		}
		else if (key == DELKEY)
		{
			linklist::iterator as;
			as = i;
			if (i.getcurrent()->next != nullptr)
			{
				linklist::iterator as;
				as = i;
				++i;
				++i;
			}
			else
				i++;
			if (i.getcurrent() != nullptr)
			{
				char* j = new char[2];
				j[0] = i.getcurrent()->priv->data;
				j[1] = '\0';
				undokey.push(i, false, nullptr, i.getcurrent()->priv->data);
				list.erase(i);
			}
			i = as;
		}
		else if (key == BACKSPACE)
		{

			//handle backspace here
			if (!currentPosition.decrementX() && currentPosition.getY() > 0) {
				cout << '\0';
				currentPosition.set(i.getcurrent()->priv->pos.getX(), i.getcurrent()->priv->pos.getY());
			}
			else
				currentPosition.set(i.getcurrent()->priv->pos.getX(), i.getcurrent()->priv->pos.getY());
			undokey.push(i, false, nullptr, i.getcurrent()->priv->data);
			list.erase(i);
		}
		else if (key == F1KEY || key == F2KEY || key == F3KEY)
		{
			//handle search here
			//you can take the cursor at the bottom of the screen and get some input
			//for searching
			point last = currentPosition;
			PlaceCursor(0, MAX_Y);
			for (int i = 0; i < MAX_X; i++)
			{
				cout << '\0';
				currentPosition.incrementX();
			}
			PlaceCursor(0, MAX_Y);
			cout << "Enter Search Query: " << endl;
			currentPosition.setX(0 + strlen("Enter Search Text : "));
			currentPosition.setY(MAX_Y);
			char buffer[100];
			cin.getline(buffer, 100);
			int i = strlen(buffer);
			char* str = new char[i + 1];
			for (int j = 0; j < i; j++)
			{
				str[j] = buffer[j];
			}
			str[i] = '\0';
			linklist::iterator as = list.bigen();
			if (key == F1KEY)
			{
				point* k = list.searchword(str, as);
				if (k != nullptr)
					for (int i = 0; i < strlen(str); i++)
					{
						SetColorAtPoint(k->getX(), k->getY(), 21);
						k->incrementX();
						if (k->getX() > k->getMaxPointX())
						{
							k->incrementY();
							k->setX(0);
						}
					}
				currentPosition = last;
			}
			else if (key == F2KEY)
			{
				for (; as.getcurrent() != nullptr && as.getcurrent() != list.end().getcurrent(); as++)
				{
					point* k = list.searchword(str, as);
					if (k != nullptr)
						for (int i = 0; i < strlen(str); i++)
						{
							SetColorAtPoint(k->getX(), k->getY(), 21);
							k->incrementX();
							if (k->getX() > k->getMaxPointX())
							{
								k->incrementY();
								k->setX(0);
							}
						}
				}
				currentPosition = last;
			}
			else
			{
				cout << "enter insersion string\n";
				cin.getline(buffer, 100);
				int i = strlen(buffer);
				char* str2 = new char[i + 1];
				for (int j = 0; j < i; j++)
				{
					str2[j] = buffer[j];
				}
				str2[i] = '\0';
				for (; as.getcurrent() != nullptr && as.getcurrent()->data != '\0'; as++)
				{
					if (list.searchword(str, as) != nullptr)
					{
						list.multipledel(as, str);
						undokey.push(as, false, str);
						list.multipleinsertion(str2, as);
						undokey.push(as, true, str2);
					}
				}
				currentPosition = list.end().getcurrent()->pos;
			}
		}
		else if (key == F4KEY)
		{
			list.save_in_file();
			stop = true;
			//save to file
		}
		else if (key == CTRL_Z)
		{
			linklist::iterator as;
			char* a;
			bool q;
			char p = '\0';
			bool c;
			a = undokey.pop(as, c, q, p);
			if (c)
			{
				if (q)
				{
					if (a != nullptr)
					{
						for (int i = 0; i < strlen(a); i++)
							list.erase(as);
					}
					else
						list.erase(as);
				}
				else
				{
					if (a != nullptr)
						list.multipleinsertion(a, as);
					else
						list.insert(as, p, as.getcurrent()->pos);
					if (as == list.end())
					{
						cout << p;
					}
				}
				currentPosition.set(as.getcurrent()->pos.getX(), as.getcurrent()->pos.getY());
			}
		}
		PlaceCursor(currentPosition.getX(), currentPosition.getY());
	}
	system("cls");
	return 0;
}

//-------------------------------------------End Main Editor--------------------------//
void main()
{
	system("color F0");
	mainEditor();
}