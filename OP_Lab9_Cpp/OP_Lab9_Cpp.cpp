#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

bool check(string);                            // whether the condition is met (all characters are numbers or spaces)
int find_words(string, string**);              // defining the list and number of words
void output_words(string**, int);              // output of each word in a new line
void search(string**, int, long*, long*);      // search for the largest and smallest words
string replace(string**, int, long, long);     // swap the smallest and largest words
void deleting(string**, int);                  // deleting an array of words

int main()
{
	string s;                                  // the input string
	int n = 40, m = 15;
	string** words;
	words = new string * [n];                  // array of words
	for (int i = 0; i < n; i++) {
		words[i] = new string [m];
	}
	int numOfWords;
	long nMax = 0;
	long nMin = 0;
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
	deleting(words,m);
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

int find_words(const string str, string** st)
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

void output_words(string** word, int k)
{
	for (int j = 0; j < k; j++)
		cout << "  " << word[j][1] << endl;
	cout << endl;
}

void search(string** st, int num, long* numOfMax, long* numOfMin)
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

string replace(string** st, int num, long numMax, long numMin)
{
	
	string str = "";
	string st2;
	st2 = st[numMax][1];
	st[numMax][1] = st[numMin][1];
	st[numMin][1] = st2;
	for (int i = 0; i < num; i++) {
		str = str + st[i][1] + " ";
	}
	return str;
}

void deleting(string** st, int k)
{
	for (int i = 0; i < k; i++) {
		delete[] st[i];
	}
	delete[] st;
}