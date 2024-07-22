//#include<iostream>
//#include<fstream>
//using namespace std;
//
//int ReadNoofRowsintheFile(ifstream &Read)
//{
//	Read.open("Synonyms.txt");
//	string ch;
//	char line[100];
//	int i = 0;
//	while (!Read.eof())
//	{
//		Read >> ch;
//		Read.getline(line, 100);
//		i++;
//	}
//	Read.close();
//	return i;
//}
//
//char** Paraphrase(char* Sentence)
//{
//	ifstream Read;
//	int NoofRows = ReadNoofRowsintheFile(Read);
//	Read.open("Synonyms.txt");
//	char** Words = new char* [NoofRows];
//	char*** Synonyms = new char** [NoofRows];
//	int i = 0;
//	while (i < NoofRows)
//	{
//
//		i++;
//	}
//}
//
//int main()
//{
//	
//	cout << "Enter the Sentence you want to Paraphrase" << endl<<"-> ";
//	char* Sentence = new char[100];
//	cin.getline(Sentence, 100);
//
//
//}