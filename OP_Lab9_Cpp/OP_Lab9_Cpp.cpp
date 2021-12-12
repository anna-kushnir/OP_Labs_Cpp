#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

string s;									// the input string
const int n = 20;
typedef string Array[n][n];
Array words;								// array of words
bool check(string);							// whether the condition is met (all characters are numbers or spaces)
int find_words(string, Array);				// defining the list and number of words
void output_words(Array, int);				// output of each word in a new line
void search(Array, int, int*, int*);		// search for the largest and smallest words
string replace(Array, int, int, int);

int main()
{
	int numOfWords;
	int nMax = 0;
	int nMin = 0;
	bool Is;
	cout << "Enter a string of numbers and spaces: " << endl;
	getline(cin,s);
	Is = check(s);
	if (Is) {
		numOfWords = find_words(s, words);
		cout << "The number of words: " << numOfWords << endl;
		cout << "The list of words:" << endl;
		output_words(words, numOfWords);
		search(words, numOfWords, &nMax, &nMin);
		s = replace(words, numOfWords, nMax, nMin);
		cout << "New string:" << endl << s << endl;
	}
	else
		cout << "You entered a wrong line! Try again!" << endl;
	system("pause");
	return 0;
}

bool check(string str)
{
	char c;
	bool R = 0;
	for (unsigned int i = 0; i < str.length(); i++) {
		c = str[i];
		if (isdigit(c) || isspace(c))
			R = 1;
		else {
			R = 0;
			break;
		}
	}
	return R;
}

int find_words(const string str, Array st)
{
	int k;
	int num = 0;
	int pos = 0;
	int Sum = 0;
	int i = 0;
	string space = " ";
	int size = str.length();
	while (pos != size) {
		if (str[pos] != ' ') {
			k = str.find(space, pos);
			if (k >= 0) {
				st[i][1] = str.substr(pos, k - pos);
				pos = k;
				num++;
			}
			else {
				st[i][1] = str.substr(pos, size - pos);
				num++;
				break;
			}
			i++;
		}
		else pos++;
	}
	return num;
}

void output_words(Array word, int m)
{
	for (int j = 0; j < m; j++)
		cout << "  " << word[j][1] << endl;
	cout << endl;
}

void search(Array st, int num, int* numOfMax, int* numOfMin)
{
	long str1;
	long max = stoul(st[0][1]);
	long min = stoul(st[0][1]);
	for (int i = 1; i < num; i++) {
		str1 = stoul(st[i][1]);
		if (str1 > max) {
			max = str1;
			*numOfMax = i;
		}
		if (str1 < min) {
			min = str1;
			*numOfMin = i;
		}
	}
	cout << "The biggest word is number " << *numOfMax << ": " << max << endl;
	cout << "The smallest word is number " << *numOfMin << ": " << min << endl;
}

string replace(Array st, int num, int numMax, int numMin)
{
	
	string str = "";
	string st2;
	st2 = st[numMax][1];
	st[numMax][1] = st[numMin][1];
	st[numMin][1] = st2;
	for (int i = 0; i < num; i++)
	{
		str = str + st[i][1] + " ";
	}
	return str;
}