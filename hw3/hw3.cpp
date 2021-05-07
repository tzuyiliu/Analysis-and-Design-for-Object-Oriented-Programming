<<<<<<< HEAD
//hw3.cpp

#include <iostream>

using namespace std;

// add the matrix simple class/structure here
class matrix
{
public:
	//add data members
	int** mm;
	int ss;

	//add functiom members
	void init(int size) {
		ss = size;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];
	}

	void transpose() {
		for (int i = 0; i < ss; i++) {
			for (int j = i; j < ss; j++)
			{
				int tmp;
				tmp = mm[i][j];
				mm[i][j] = mm[j][i];
				mm[j][i] = tmp;
			}
		}
	}

	void destroy() {
		for (int i = 0; i < ss; i++)
			delete[] mm[i];

		delete[] mm;
	}
};



int main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix m;

	// using init to setup the matrix object
	m.init(size);

	// assign the values to the created matrix
	int count = 1;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			m.mm[i][j] = count;	//<== this will not work. correct it
			count++;
		}
	}

	// show the matrix on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m.mm[i][j]<<" ";	//<== this will not work. correct it

		cout<<endl;
	}

	// call transpose() to calculate its transpose
	m.transpose();

	// show the matrix after transpose on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m.mm[i][j]<<" ";	//<== this will not work. correct it

		cout<<endl;
	}

	// call destroy to free the object
	m.destroy();

	system("pause");
	return 0;
}

=======
//hw3.cpp

#include <iostream>

using namespace std;

// add the matrix simple class/structure here
class matrix
{
public:
	//add data members
	int** mm;
	int ss;

	//add functiom members
	void init(int size) {
		ss = size;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];
	}

	void transpose() {
		for (int i = 0; i < ss; i++) {
			for (int j = i; j < ss; j++)
			{
				int tmp;
				tmp = mm[i][j];
				mm[i][j] = mm[j][i];
				mm[j][i] = tmp;
			}
		}
	}

	void destroy() {
		for (int i = 0; i < ss; i++)
			delete[] mm[i];

		delete[] mm;
	}
};



int main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix m;

	// using init to setup the matrix object
	m.init(size);

	// assign the values to the created matrix
	int count = 1;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
		{
			m.mm[i][j] = count;	//<== this will not work. correct it
			count++;
		}
	}

	// show the matrix on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m.mm[i][j]<<" ";	//<== this will not work. correct it

		cout<<endl;
	}

	// call transpose() to calculate its transpose
	m.transpose();

	// show the matrix after transpose on the screen
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m.mm[i][j]<<" ";	//<== this will not work. correct it

		cout<<endl;
	}

	// call destroy to free the object
	m.destroy();

	system("pause");
	return 0;
}

>>>>>>> 3af4f55 (commit2021/05/07)
