#include<iostream>
#include<cstdlib>
#include<ctime>
#include<cstring>
#include<fstream>
using namespace std;

int strLen(char* arr)
{
	int i = 0;
	while (arr[i] != '\0')
		i++;
	return i;
}

void replaceStr(char* a, char*& b)
{
	int aLen = strLen(a);
	int bLen = strLen(b);
	char* temp = new char[aLen];
	int i = 0;
	for (; i < aLen; i++)
	{
		temp[i] = a[i];
	}
	temp[i] = '\0';
	b = temp;
}



bool compareString(char* a, char* b)
{
	bool check = true;
	int length1 = strLen(a);
	int length2 = strLen(b);
	if (length1 == length2)
	{
		for (int i = 0; i < length1; i++)
		{
			if (a[i] == b[i])
			{
				check = true;
			}
			else
			{
				check = false;
				break;
			}
		}
		if (check == true)
			return true;
		else
			return false;
	}
	return false;
}

char* arrayResize(char* sentence) //to remove spaces in synonyms array
{
	int length = 0;
	while (sentence[length] != '\0')
	{
		length++;
	}
	int i = 0;
	for (; i < length; i++)
	{
		sentence[i] = sentence[i + 1];
	}
	sentence[i] = '\0';
	return sentence;
}

char** tokens(char* sentence)
{
	int i = 0, words = 0, length = 0, j = 0, count = 0;
	char** tokenized;
	while (sentence[i] != '\0')
		i++;
	length = i;
	for (int i = 0; i < length; i++)
	{
		if (sentence[i] == ' ')
			words++;
	}
	words++;
	tokenized = new char* [words];
	for (int i = 0; i < words; i++)
	{
		char temp[100];
		int k = 0;
		count = 0;
		for (; j < length; j++)
		{

			if (sentence[j] != ' ' && sentence[j] != '\0')
			{
				temp[k] = sentence[j];
				count++;
				k++;
			}
			else
				break;
		}
		j++;
		tokenized[i] = new char[count + 1];
		int l = 0;
		for (; l < count; l++)
		{
			tokenized[i][l] = temp[l];
		}
		tokenized[i][l] = '\0';
	}
	return tokenized;
}

char** Paraphrase(char* sentence)
{
	srand(time(0));
	char temp2[5][100];
	char* words = new char[100];
	char* synonyms = new char[100];
	ifstream fin;
	fin.open("Synonyms.txt");
	int noOfWords = 0;
	int j = 0;
	while (!fin.eof())
	{
		fin >> words;
		fin.getline(synonyms, 100);
		strcpy_s(temp2[j], synonyms);
		j++;
		noOfWords++;
	}
	fin.close();
	fin.open("Synonyms.txt");
	char** word = new char* [noOfWords];
	char*** syno = new char** [noOfWords];
	char* syn = new char[100];
	int* tempNoOfWords = new int[noOfWords];
	for (int i = 0; i < noOfWords; i++)
	{
		j = 0;
		int m = 0;
		char temp[20];
		fin >> temp;
		fin.getline(syn, 100);
		syn = arrayResize(syn);
		while (temp[j] != '\0')
			j++;
		word[i] = new char[j];
		int k = 0;
		for (; k < j; k++)
		{
			word[i][k] = temp[k];
		}
		word[i][k++] = '\0';
		int spaces = 0;
		while (syn[m] != '\0')
		{
			if (syn[m] == ' ')
				spaces++;
			m++;
		}
		syno[i] = new char* [spaces + 1];
		tempNoOfWords[i] = spaces + 1;
		int a = 0;
		for (int n = 0; n < spaces + 1; n++)
		{
			char tempArr[100];
			int count = 0;
			int b = 0;
			for (; syn[a] != ' ' && syn[a] != '\0'; a++)
			{

				tempArr[b] = syn[a];
				count++;
				b++;
			}
			tempArr[b] = '\0';
			syno[i][n] = new char[count + 2];
			int o = 0;
			for (; o < count; o++)
			{
				syno[i][n][o] = tempArr[o];
			}
			syno[i][n][o] = '\0';
			a++;

		}
	}
	int senLength = strLen(sentence);
	int senWords = 0;
	char** senTok = tokens(sentence);
	for (int i = 0; i < senLength; i++)
	{
		if (sentence[i] == ' ')
		{
			senWords++;
		}
	}
	senWords++;
	for (int i = 0; i < senWords; i++)
	{
		bool found = false;
		for (int j = 0; j < noOfWords; j++)
		{
			found = compareString(senTok[i], word[j]);
			if (found == true)
			{
				int tempRand = (rand() % tempNoOfWords[j]) + 0;
				replaceStr(syno[j][tempRand], senTok[i]);
			}
		}
	}
	delete[]tempNoOfWords;
	return senTok;
}


int main()
{
	int senLength = 0, senWords = 0;
	char* array = new char[100];
	char** token;
	cout << "enter a sentence" << endl;
	cin.getline(array, 100);
	senLength = strLen(array);
	for (int i = 0; i < senLength; i++)
	{
		if (array[i] == ' ')
			senWords++;
	}
	senWords++;
	token = Paraphrase(array);
	for (int i = 0; i < senWords; i++)
	{
		cout << token[i] << " ";
	}
}