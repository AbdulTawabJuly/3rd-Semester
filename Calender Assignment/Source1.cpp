#include<iostream>
#include<fstream>
using namespace std;
struct Activity
{

	char* UserID;
	char* Title;
	int Duration;
	float Priority;
};


int DaysinMonths[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
int NoofActivity[12][31][24]={0};


void MemoryAllocation(Activity*****& Calender)
{
	Calender = new Activity * ***[12];
	for (int month = 0; month < 12; month++)
	{
		Calender[month] = new Activity * **[DaysinMonths[month]];
		for (int days = 0; days < DaysinMonths[month]; days++)
		{
			Calender[month][days] = new Activity * *[24];
			for (int hour = 0; hour < 24; hour++)
			{
				Calender[month][days][hour] = new Activity * [1];
				Calender[month][days][hour][0] = nullptr;
			}
		}
	}
}

void Input(Activity*****& Calender)
{
	fstream Read;
	Activity temp;
	int day, month, start, end;
	char userid[20], actid[20], title[100];
	float priority;
	Read.open("Calender.txt");
	while (!Read.eof())
	{
		Read >> day;
		Read.ignore();
		Read >> month;
		Read.ignore();
		Read >> start;
		Read.ignore();
		Read >> end;
		Read.ignore();
		Read.getline(userid, 20, ',');
		Read.getline(actid, 20, ',');
		Read.getline(title, 100, ',');
		Read >> priority;
		


	}

}

int main()
{
	Activity***** Calender;
	MemoryAllocation(Calender);


}