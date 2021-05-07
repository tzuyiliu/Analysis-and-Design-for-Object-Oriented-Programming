<<<<<<< HEAD
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	
	int data[50];
	int buffer;
	int count = 0;

	ifstream fcin("input.txt");

	while (fcin >> buffer)
	{
		//cout << buffer << endl;
		data[count] = buffer;
		count++;
	}
	
	int min = data[0];
	int max = data[1];
	int ans = data[2];
	int input;
	
	cout << "Please guess an integer number between " << min << " and " << max << endl; 
	cin >> input;
	while(input != ans){
		if(input < min || input > max){
			cout << "The number you entered is not within the valid range." << endl;
			cout << "Please try again!" << endl;
		}
		else if(input < ans){
			min = input;
		}
		else if(input > ans){
			max = input;
		}
		cout << "Please guess an integer number between " << min << " and " << max << endl; 
		cin >> input;
	}
	cout << "Bingo! You hit the bomb." << endl; 

	system("pause");
	return 0;
}

=======
#include <iostream>
#include <fstream>

using namespace std;

int main() 
{
	
	int data[50];
	int buffer;
	int count = 0;

	ifstream fcin("input.txt");

	while (fcin >> buffer)
	{
		//cout << buffer << endl;
		data[count] = buffer;
		count++;
	}
	
	int min = data[0];
	int max = data[1];
	int ans = data[2];
	int input;
	
	cout << "Please guess an integer number between " << min << " and " << max << endl; 
	cin >> input;
	while(input != ans){
		if(input < min || input > max){
			cout << "The number you entered is not within the valid range." << endl;
			cout << "Please try again!" << endl;
		}
		else if(input < ans){
			min = input;
		}
		else if(input > ans){
			max = input;
		}
		cout << "Please guess an integer number between " << min << " and " << max << endl; 
		cin >> input;
	}
	cout << "Bingo! You hit the bomb." << endl; 

	system("pause");
	return 0;
}

>>>>>>> 3af4f55 (commit2021/05/07)
