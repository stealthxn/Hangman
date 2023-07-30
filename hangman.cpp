#include<iostream>
#include <windows.h>
#include<string>
#include<cstring>
#include<random>
using namespace std;

int attempts = 5;
string words[5] = { "Ali","Hassan","Warda","Tatheer","Nabeeha" };

void gotoxy(int x, int y)
{

	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);

}
void hangman(int attempts) {
	switch (attempts) {
	case 1:
		cout << "--------" << endl;
		cout << "|      |" << endl;
		cout << "|      0" << endl;
		cout << "|      |" << endl;
		cout << "|     / \\" << endl;
		cout << "|      |" << endl;
		cout << "|     / \\" << endl;
		cout << "|" << endl;
		cout << "|_____" << endl;
		break;
	case 2:
		cout << "--------" << endl;
		cout << "|      |" << endl;
		cout << "|      0" << endl;
		cout << "|      |" << endl;
		cout << "|     / \\" << endl;
		cout << "|      |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|_____" << endl;
		break;
	case 3:
		cout << "--------" << endl;
		cout << "|      |" << endl;
		cout << "|      0" << endl;
		cout << "|      |" << endl;
		cout << "|     / \\" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|_____" << endl;
		break;
	case 4:
		cout << "--------" << endl;
		cout << "|      |" << endl;
		cout << "|      0" << endl;
		cout << "|      |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|_____" << endl;
		break;
	case 5:
		cout << "--------" << endl;
		cout << "|      |" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|" << endl;
		cout << "|_____" << endl;
		break;
	default:
		cout << "Error!!!!!" << endl;
		break;
	}
}
int lenofstr(string s) {

	int len = 0;
	while (s[len] != '\0') {
		len++;
	}
	return len;
}
void display(char* arr, int len) {
	int x = 0;
	int y = 20;
	for (int i = 0; i < len; i++) {
		gotoxy(x, y);
		cout << arr[i];
		x++;

	}
	cout << endl;
}
char* word(string s, int len) {
	srand(time(0));
	int r;
	char* charray = new char[len];
	if (len > 5) {
		int arr[2];

		for (int i = 0; i < 2; i++) {
			r = rand() % len;
			arr[i] = r;
		}
		while (arr[0] == arr[1]) {
			r = rand() % len;
			arr[1] = r;
		}

		for (int i = 0; i < len; i++) {

			if (i == arr[0] || i == arr[1]) {
				charray[i] = s[i];
			}
			else {
				charray[i] = '_';
			}
		}

	}
	else {
		r = rand() % 3;
		for (int i = 0; i < len; i++) {
			if (i == r) {
				charray[i] = s[i];
			}
			else {
				charray[i] = '_';
			}
		}

	}
	return charray;

}
bool areArraysEqual(char* arr, char* s, int len) {
	for (int i = 0; i < len; i++) {
		if (arr[i] != s[i]) {
			return false;
		}
	}
	return true;
}

char* stringss(string s, int len) {
	char* arr = new char[len];
	for (int i = 0; i < len; i++) {
		arr[i] = s[i];
	}

	return arr;
}

void guess(char* s, int len, char* arr) {
	bool flag;
	char ch;
	int i;
	while (attempts > 0) {
		flag = false;
		gotoxy(0, 30);
		cout << "Enter Alphabet To guess: ";
		cin >> ch;
		
		for (i = 0; i < len; i++) {
			if (s[i] == ch && ch != arr[i]) {
				flag = true;
				break;
			}
		}

		if (flag == true) {
			arr[i] = ch;
			system("cls");
			display(arr, len);
		}
		else {
			system("cls");
			cout << "Wrong Alphabet entered" << endl;
			hangman(attempts);

			attempts--;
			gotoxy(30, 30);
			cout << " Attempts Remaining = " << attempts << endl;
			display(arr, len);
		}

		if (areArraysEqual(arr, s, len)) {
			cout << "You have Successfully guessed!" << endl;
			break;
		}

	}

	if (attempts == 0) {
		cout << "You failed";
	}

}


int main() {
	srand(time(NULL));
	int a = rand() % 5;
	int len = lenofstr(words[a]);
	char* arr = word(words[a], len);
	char* original = stringss(words[a], len);


	display(arr, len);
	guess(original, len, arr);

	delete[] arr;
	delete[] original;


}
