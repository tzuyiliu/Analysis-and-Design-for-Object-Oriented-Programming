<<<<<<< HEAD
//hw4.cpp

#include <iostream>

using namespace std;

// Please provide the matrix class 
class matrix
{
private:
	//add data members
	int** mm;
	int ss;

public:
	//add functiom members

	matrix() {
		ss = 0;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];
	}

	matrix(int size) {
		ss = size;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];
	}

	matrix(const matrix& other) {
		ss = other.ss;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];

		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				mm[i][j] = other.mm[i][j];
			}
		}
	}

	matrix& operator=(const matrix& other)
	{
		if(this != &other){
			
			this->~matrix();
			ss = other.ss;
			mm = new int*[ss];
			for (int i = 0; i < ss; i++)
				mm[i] = new int[ss];
	
			for (int i = 0; i < ss; i++) {
				for (int j = 0; j < ss; j++) {
					mm[i][j] = other.mm[i][j];
				}
			}
			return *this;
		}
		
	}

	~matrix() {
		for (int i = 0; i < ss; i++)
			delete[] mm[i];

		delete[] mm;
	}

	void setElement(int i, int j, int input) {
		mm[i][j] = input;
	}

	int getElement(int i, int j) {
		return mm[i][j];
	}

	void printSelf() {
		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				cout << mm[i][j] << " ";
			}
			cout << endl;
		}
	}

};



int main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	// show the matrix on the screen
	cout<<"m = "<<endl;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}


	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor (10 times)
	matrix mArr2[5];							//calling default constructor (5 times)
	matrix m1;									//calling default constructor
	matrix* m2 = new matrix(*m);		//calling copy constructor
	matrix m3 = matrix(*m);				//calling copy constructor

	m1 = *m;										//calling copy assignment operator
	
	
	//show the testing matrix objects
	cout<<"m1 = "<<endl;
	m1.printSelf();
	cout<<"*m2 = "<<endl;
	m2->printSelf();
	cout<<"m3 = "<<endl;
	m3.printSelf();


	// delete the dynamic allocated objects
	delete m;
	delete [] mArr1;
	delete m2;

	system("pause");
	return 0;
}

=======
//hw4.cpp

#include <iostream>

using namespace std;

// Please provide the matrix class 
class matrix
{
private:
	//add data members
	int** mm;
	int ss;

public:
	//add functiom members

	matrix() {
		ss = 0;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];
	}

	matrix(int size) {
		ss = size;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];
	}

	matrix(const matrix& other) {
		ss = other.ss;
		mm = new int*[ss];
		for (int i = 0; i < ss; i++)
			mm[i] = new int[ss];

		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				mm[i][j] = other.mm[i][j];
			}
		}
	}

	matrix& operator=(const matrix& other)
	{
		if(this != &other){
			
			this->~matrix();
			ss = other.ss;
			mm = new int*[ss];
			for (int i = 0; i < ss; i++)
				mm[i] = new int[ss];
	
			for (int i = 0; i < ss; i++) {
				for (int j = 0; j < ss; j++) {
					mm[i][j] = other.mm[i][j];
				}
			}
			return *this;
		}
		
	}

	~matrix() {
		for (int i = 0; i < ss; i++)
			delete[] mm[i];

		delete[] mm;
	}

	void setElement(int i, int j, int input) {
		mm[i][j] = input;
	}

	int getElement(int i, int j) {
		return mm[i][j];
	}

	void printSelf() {
		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				cout << mm[i][j] << " ";
			}
			cout << endl;
		}
	}

};



int main()
{
	// obtain the matrix size from user
	int size;
	cout<<"Please input the size of the square matrix."<<endl;
	cin>>size;

	// create the matrix object
	matrix* m = new matrix(size);

	// assign the values to the created matrix
	for(int i=0; i<size; i++)
		for(int j=0; j<size; j++)
		{
			if(i==j)
				m->setElement(i,j,10);	
			else
				m->setElement(i,j,1);	
		}

	// show the matrix on the screen
	cout<<"m = "<<endl;
	for(int i=0; i<size; i++)
	{
		for(int j=0; j<size; j++)
			cout<<m->getElement(i,j)<<" ";

		cout<<endl;
	}


	//testing standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor (10 times)
	matrix mArr2[5];							//calling default constructor (5 times)
	matrix m1;									//calling default constructor
	matrix* m2 = new matrix(*m);		//calling copy constructor
	matrix m3 = matrix(*m);				//calling copy constructor

	m1 = *m;										//calling copy assignment operator
	
	
	//show the testing matrix objects
	cout<<"m1 = "<<endl;
	m1.printSelf();
	cout<<"*m2 = "<<endl;
	m2->printSelf();
	cout<<"m3 = "<<endl;
	m3.printSelf();


	// delete the dynamic allocated objects
	delete m;
	delete [] mArr1;
	delete m2;

	system("pause");
	return 0;
}

>>>>>>> 3af4f55 (commit2021/05/07)
