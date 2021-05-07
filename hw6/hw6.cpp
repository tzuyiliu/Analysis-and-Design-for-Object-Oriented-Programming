<<<<<<< HEAD
//hw6.cpp

#include <iostream>
#include <assert.h>

using namespace std;

class vector;  //!!This is required for the dataultiV function to know vector class!!

// Please provide the matrix class 
class matrix
{
private:
	//add data members
	int** data;
	int ss;
	static int count;

public:
	//add functiom members

	matrix() {
		count++;
		ss = 0;
		data = new int*[ss];
		for (int i = 0; i < ss; i++)
			data[i] = new int[ss];
	}

	matrix(int size) {
		count++;
		ss = size;
		data = new int*[ss];
		for (int i = 0; i < ss; i++)
			data[i] = new int[ss];
	}

	matrix(const matrix& other) {
		count++;
		ss = other.ss;
		data = new int*[ss];
		for (int i = 0; i < ss; i++)
			data[i] = new int[ss];

		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				data[i][j] = other.data[i][j];
			}
		}
	}

	matrix& operator=(const matrix& other)
	{
		if(this != &other)
		{
			ss = other.ss;
			data = new int*[ss];
			for (int i = 0; i < ss; i++)
				data[i] = new int[ss];
	
			for (int i = 0; i < ss; i++) {
				for (int j = 0; j < ss; j++) {
					data[i][j] = other.data[i][j];
				}
			}
			return *this;
		}
		
	}

	~matrix() {
		count--;
		for (int i = 0; i < ss; i++)
			delete[] data[i];

		delete[] data;
	}

	void setElement(int i, int j, int input) {
		data[i][j] = input;
	}

	int getElement(int i, int j) {
		return data[i][j];
	}

	void printSelf() {
		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}

	static int getCount() {
		return count;
	}

	friend vector& MmultV(matrix& m, vector& v);
	friend vector& VmultM(vector& v, matrix& m);
};

class vector
{
private:
	int ss;
	int* data;
	static int count;
public:
	vector() {
		count++;
		ss = 0;
		data = new int[ss];
	}

	vector(int size) {
		count++;
		ss = size;
		data = new int[ss];
	}

	vector(const vector& other) {
		count++;
		ss = other.ss;
		data = new int[ss];

		for (int i = 0; i < ss; i++) {
			data[i] = other.data[i];
		}
	}

	vector& operator=(const vector& other)
	{
		if(this != &other)
		{
			ss = other.ss;
			data = new int[ss];
	
			for (int i = 0; i < ss; i++) {
				data[i] = other.data[i];
			}
			return *this;
		}
	}

	~vector() {
		count--;
		delete data;
	}

	void setElement(int i, int input) {
		data[i] = input;
	}

	int getElement(int i) {
		return data[i];
	}

	void printSelf() {
		for (int i = 0; i < ss; i++)
			cout << data[i] << " ";
		cout << endl;
	}

	static int getCount() {
		return count;
	}

	friend vector& MmultV(matrix& m, vector& v);
	friend vector& VmultM(vector& v, matrix& m);
};

vector& MmultV(matrix& m, vector& v)
{
	vector* vv = new vector(v.ss);
	int tmp = 0;
	for (int i = 0; i < v.ss; i++) {
		for (int j = 0; j < v.ss; j++) {
			tmp += m.data[i][j] * v.data[j];
		}
		vv->data[i] = tmp;
		tmp = 0;
	}

	return *vv;
}

vector& VmultM(vector& v, matrix& m)
{
	vector* vv = new vector(v.ss);
	int tmp = 0;
	for (int i = 0; i < v.ss; i++) {
		for (int j = 0; j < v.ss; j++) {
			tmp += v.data[j] * m.data[i][j];
		}
		vv->data[i] = tmp;
		tmp = 0;
	}

	return *vv;
}

//initialize static member
int matrix::count = 0;
int vector::count = 0;



void main()
{
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the matrix and vector." << endl;
	cin >> size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				m->setElement(i, j, 10);
			else
				m->setElement(i, j, 1);
		}

	for (int i = 0; i < size; i++)
		v->setElement(i, i + 1);


	//show the matrix and vector on the screen
	cout << "m = " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << m->getElement(i, j) << " ";

		cout << endl;
	}

	cout << "v = " << endl;
	for (int i = 0; i < size; i++)
		cout << v->getElement(i) << " ";

	cout << endl;

	//test the standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor (10 times)
	matrix mArr2[5];							//calling default constructor (5 times)
	matrix m1;									//calling default constructor
	matrix* m2 = new matrix(*m);		//calling copy constructor
	matrix m3 = matrix(*m);				//calling copy constructor
	m1 = *m;										//calling copy assignment operator
	vector* vArr1 = new vector[10];	//calling default constructor (10 times)
	vector vArr2[5];								//calling default constructor (5 times)
	vector v1;										//calling default constructor
	vector* v2 = new vector(*v);			//calling copy constructor
	vector v3 = vector(*v);					//calling copy constructor
	v1 = *v;											//calling copy assignment operator


	//test MmultV and VmultM
	vector& ans1 = MmultV(*m, *v);
	cout << "ans1=" << endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v, *m);
	cout << "ans2=" << endl;
	ans2.printSelf();


	//test counting objects
	cout << "You have create " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;


	// delete the dynamic allocated objects
	delete m;
	delete[] mArr1;
	delete m2;
	delete v;
	delete[] vArr1;
	delete v2;

	//test counting objects
	cout << "After deleting, there are " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;

	system("pause");
}

=======
//hw6.cpp

#include <iostream>
#include <assert.h>

using namespace std;

class vector;  //!!This is required for the dataultiV function to know vector class!!

// Please provide the matrix class 
class matrix
{
private:
	//add data members
	int** data;
	int ss;
	static int count;

public:
	//add functiom members

	matrix() {
		count++;
		ss = 0;
		data = new int*[ss];
		for (int i = 0; i < ss; i++)
			data[i] = new int[ss];
	}

	matrix(int size) {
		count++;
		ss = size;
		data = new int*[ss];
		for (int i = 0; i < ss; i++)
			data[i] = new int[ss];
	}

	matrix(const matrix& other) {
		count++;
		ss = other.ss;
		data = new int*[ss];
		for (int i = 0; i < ss; i++)
			data[i] = new int[ss];

		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				data[i][j] = other.data[i][j];
			}
		}
	}

	matrix& operator=(const matrix& other)
	{
		if(this != &other)
		{
			ss = other.ss;
			data = new int*[ss];
			for (int i = 0; i < ss; i++)
				data[i] = new int[ss];
	
			for (int i = 0; i < ss; i++) {
				for (int j = 0; j < ss; j++) {
					data[i][j] = other.data[i][j];
				}
			}
			return *this;
		}
		
	}

	~matrix() {
		count--;
		for (int i = 0; i < ss; i++)
			delete[] data[i];

		delete[] data;
	}

	void setElement(int i, int j, int input) {
		data[i][j] = input;
	}

	int getElement(int i, int j) {
		return data[i][j];
	}

	void printSelf() {
		for (int i = 0; i < ss; i++) {
			for (int j = 0; j < ss; j++) {
				cout << data[i][j] << " ";
			}
			cout << endl;
		}
	}

	static int getCount() {
		return count;
	}

	friend vector& MmultV(matrix& m, vector& v);
	friend vector& VmultM(vector& v, matrix& m);
};

class vector
{
private:
	int ss;
	int* data;
	static int count;
public:
	vector() {
		count++;
		ss = 0;
		data = new int[ss];
	}

	vector(int size) {
		count++;
		ss = size;
		data = new int[ss];
	}

	vector(const vector& other) {
		count++;
		ss = other.ss;
		data = new int[ss];

		for (int i = 0; i < ss; i++) {
			data[i] = other.data[i];
		}
	}

	vector& operator=(const vector& other)
	{
		if(this != &other)
		{
			ss = other.ss;
			data = new int[ss];
	
			for (int i = 0; i < ss; i++) {
				data[i] = other.data[i];
			}
			return *this;
		}
	}

	~vector() {
		count--;
		delete data;
	}

	void setElement(int i, int input) {
		data[i] = input;
	}

	int getElement(int i) {
		return data[i];
	}

	void printSelf() {
		for (int i = 0; i < ss; i++)
			cout << data[i] << " ";
		cout << endl;
	}

	static int getCount() {
		return count;
	}

	friend vector& MmultV(matrix& m, vector& v);
	friend vector& VmultM(vector& v, matrix& m);
};

vector& MmultV(matrix& m, vector& v)
{
	vector* vv = new vector(v.ss);
	int tmp = 0;
	for (int i = 0; i < v.ss; i++) {
		for (int j = 0; j < v.ss; j++) {
			tmp += m.data[i][j] * v.data[j];
		}
		vv->data[i] = tmp;
		tmp = 0;
	}

	return *vv;
}

vector& VmultM(vector& v, matrix& m)
{
	vector* vv = new vector(v.ss);
	int tmp = 0;
	for (int i = 0; i < v.ss; i++) {
		for (int j = 0; j < v.ss; j++) {
			tmp += v.data[j] * m.data[i][j];
		}
		vv->data[i] = tmp;
		tmp = 0;
	}

	return *vv;
}

//initialize static member
int matrix::count = 0;
int vector::count = 0;



void main()
{
	// obtain the matrix size from user
	int size;
	cout << "Please input the size of the matrix and vector." << endl;
	cin >> size;

	// create the matrix and vector object
	matrix* m = new matrix(size);
	vector* v = new vector(size);

	// assign the values to the created matrix and vector
	for (int i = 0; i < size; i++)
		for (int j = 0; j < size; j++)
		{
			if (i == j)
				m->setElement(i, j, 10);
			else
				m->setElement(i, j, 1);
		}

	for (int i = 0; i < size; i++)
		v->setElement(i, i + 1);


	//show the matrix and vector on the screen
	cout << "m = " << endl;
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
			cout << m->getElement(i, j) << " ";

		cout << endl;
	}

	cout << "v = " << endl;
	for (int i = 0; i < size; i++)
		cout << v->getElement(i) << " ";

	cout << endl;

	//test the standard constructors
	matrix* mArr1 = new matrix[10];	//calling default constructor (10 times)
	matrix mArr2[5];							//calling default constructor (5 times)
	matrix m1;									//calling default constructor
	matrix* m2 = new matrix(*m);		//calling copy constructor
	matrix m3 = matrix(*m);				//calling copy constructor
	m1 = *m;										//calling copy assignment operator
	vector* vArr1 = new vector[10];	//calling default constructor (10 times)
	vector vArr2[5];								//calling default constructor (5 times)
	vector v1;										//calling default constructor
	vector* v2 = new vector(*v);			//calling copy constructor
	vector v3 = vector(*v);					//calling copy constructor
	v1 = *v;											//calling copy assignment operator


	//test MmultV and VmultM
	vector& ans1 = MmultV(*m, *v);
	cout << "ans1=" << endl;
	ans1.printSelf();

	vector ans2 = VmultM(*v, *m);
	cout << "ans2=" << endl;
	ans2.printSelf();


	//test counting objects
	cout << "You have create " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;


	// delete the dynamic allocated objects
	delete m;
	delete[] mArr1;
	delete m2;
	delete v;
	delete[] vArr1;
	delete v2;

	//test counting objects
	cout << "After deleting, there are " << matrix::getCount() << " matrices and "
		<< vector::getCount() << " vectors in this program." << endl;

	system("pause");
}

>>>>>>> 3af4f55 (commit2021/05/07)
