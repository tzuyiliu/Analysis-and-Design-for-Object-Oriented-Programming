<<<<<<< HEAD
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int size;
	int curr = 0;
	char input[20];
	cout << "Please input the max number of words to be stored." << endl;
	cin >> size;
	string* array = new string[size];
	//string array[size];
	cout << "Please input the word, or command(print/exit) : ";
	cin >> input;
	while (strcmp(input, "exit") != 0) {
		if (strcmp(input, "print") == 0) {
			for (int i = 0; i < curr - 1; i++) {
				for (int j = 0; j < curr - i - 1; j++) {
					if ( array[j].compare(array[j+1]) > 0) {
						string tmp = array[j];
						array[j] = array[j+1];
						array[j+1] = tmp;
					}
				}
			}
			//sort(array, array + curr);
			for (int i = 0; i < curr; i++) {
				cout << array[i] << " ";
			}
			cout << endl;
		}
		else {
			if (curr < size) {
				array[curr] = input;
				curr++;
			}
			else {
				cout << "The array is full!" << endl;
			}
		}
		cout << "Please input the word, or command(print/exit) : ";
		cin >> input;
	}
	return 0;
}
=======
#include <iostream>
#include <string.h>
#include <algorithm>

using namespace std;

int main()
{
	int size;
	int curr = 0;
	char input[20];
	cout << "Please input the max number of words to be stored." << endl;
	cin >> size;
	string* array = new string[size];
	//string array[size];
	cout << "Please input the word, or command(print/exit) : ";
	cin >> input;
	while (strcmp(input, "exit") != 0) {
		if (strcmp(input, "print") == 0) {
			for (int i = 0; i < curr - 1; i++) {
				for (int j = 0; j < curr - i - 1; j++) {
					if ( array[j].compare(array[j+1]) > 0) {
						string tmp = array[j];
						array[j] = array[j+1];
						array[j+1] = tmp;
					}
				}
			}
			//sort(array, array + curr);
			for (int i = 0; i < curr; i++) {
				cout << array[i] << " ";
			}
			cout << endl;
		}
		else {
			if (curr < size) {
				array[curr] = input;
				curr++;
			}
			else {
				cout << "The array is full!" << endl;
			}
		}
		cout << "Please input the word, or command(print/exit) : ";
		cin >> input;
	}
	return 0;
}
>>>>>>> 3af4f55 (commit2021/05/07)
