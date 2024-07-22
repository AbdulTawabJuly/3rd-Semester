#include<iostream>
#include<fstream>
#include<string>
using namespace std;

int ArrayLength(char* arr)
{
	int counter = 0, i = 0;
	while (arr[i] != '\0')
	{
		i++;
		counter++;
	}
	return counter;
}

int ArrayLength2(char* arr)
{
	int counter = 0, i = 0;
	while (arr[i] != '\0'||arr[i]==' ')
	{
		i++;
		counter++;
	}
	return counter;
}

void PrintToken(char** Ptstr, int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << Ptstr[i] << endl;;
	}
	cout << endl;

}

char* CopyToken(char arr1[])
{
	int i = 0, counter = 0;
	while (arr1[i] != '\0')
	{
		counter++;
		i++;
	}
	char* Copied = new char[counter + 1]; // Counter +1 -> for storing NULL at the end
	i = 0;
	while (arr1[i] != '\0')
	{
		Copied[i] = arr1[i];
		i++;
	}

	Copied[i] = '\0';
	return Copied;
}

int WordCount(char* string)
{
	int i = 0; int wordcount = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')  // Counting the number of spaces
		{
			wordcount++;
		}
		i++;
	}
	return wordcount;
}

int Compare(char* cstring1, char* cstring2)
{
	int check = 0;
	int counter1 = ArrayLength(cstring1);
	for (int i = 0; i < counter1; i++)
	{
		if (cstring1[i] != cstring2[i])
		{
			return 0;
		}
		else
		{
			check++;
		}
	}
	if (check == counter1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}

char** StringToken(char* strTok, int& rows)
{
	int Length = ArrayLength(strTok);
	int space = WordCount(strTok);
	char** Token = new char* [space + 1];// (space+1)-> because words are 1 greator than space count
	int j = 0;
	while (rows < space + 1) // rows means i (while i < last dynmically allocated row)
	{
		int t = 0;
		char temp[50] = ""; // temporary array for storing words
		while ((strTok[j] != ' ') && (rows < space)) // j should be less than the last row
		{
			temp[t] = strTok[j];
			j++;
			t++;
		}
		if (rows == space) // because in last row loop will iterate till NULL not space
		{
			while (strTok[j] != '\0')
			{
				temp[t] = strTok[j];
				j++;
				t++;
			}
		}
		temp[t] = '\0';
		Token[rows] = CopyToken(temp);
		rows++;
		j++;
	}
	delete[]strTok;
	return Token;
}

char* Replace(char*& Replace_into, char* Replace_from)
{
	int Rows = 0;
	char** Tokenize = StringToken(Replace_from, Rows);
	

	int length = ArrayLength2(Replace_from);
	Replace_into = new char[length + 1];
	int i;
	for (i = 0; i < length; i++)
	{
		Replace_into[i] = Replace_from[i];
	}
	Replace_into[i] = '\0';

	return Replace_into;
}

int main()
{
	ifstream Read("Synonyms.txt");
	int NoofWords = 0;
	string ch;
	char line[100] = { '\0' };
	while (!Read.eof())
	{
		Read >> ch;
		Read.getline(line,100);
		NoofWords++;
	}
	Read.close();
	Read.open("Synonyms.txt");
	char** Words = new char* [NoofWords];
	char** Synonyms = new char* [NoofWords];
	int i = 0;
	int m = 0;
	while (i < NoofWords)
	{
		char tempwords[100] = { '\0' };
		char tempsynonyms[100] = { '\0' };

		Read.getline(tempwords,100,' ');
		Read.getline(tempsynonyms, 100);
		int length = 0;
		int lengthS = 0;
		while (tempwords[length] != '\0')
		{
			length++;
		}
		while (tempsynonyms[lengthS] != '\0')
		{
			lengthS++;
		}

		Words[i] = new char[length+1];

		int j = 0;
		while (tempwords[j] != '\0')
		{
			Words[i][j]=tempwords[j];
			j++;
		}
		Words[i][j] = '\0';
		j = 0;

		Synonyms[i] = new char[lengthS+1];
		int k = 0;
		while (tempsynonyms[j] != '\0')
		{
			Synonyms[i][j] = tempsynonyms[j];
			j++;
		}
		Synonyms[i][j] = '\0';
		i++;
	}

	cout << "Enter the Sentence which you want to Paraphrase" << endl;
	//string  Paraphrase;
	char *Paraphrase =new char[100];
	cin.getline(Paraphrase, 100);
	char** Tokenize;
	int Rows = 0;

	Tokenize=StringToken(Paraphrase,Rows);
	//PrintToken(Tokenize, Rows);

	int check = 0;

	for (int i = 0; i < Rows; i++)
	{
		for (int j = 0; j < NoofWords; j++)
		{
			check = Compare(Tokenize[i], Words[j]);
			if (check == 1)
			{
				Replace(Tokenize[i], Synonyms[j]);
				
			}
		}
	}


	for (int i = 0; i < NoofWords; i++)
	{
		cout << Words[i]<<" ";
	}
}



