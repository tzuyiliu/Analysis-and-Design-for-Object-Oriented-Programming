<<<<<<< HEAD
#include <iostream>
#include <string>

using namespace std;

class School
{
	string school_name;
public:
	School(){ school_name = ""; }
	School(string name){ school_name = name; }
	School(const School& other) { school_name = other.school_name; cout << "call School copy constructor" << endl; }
	School& operator=(const School& other)
	{ 
		cout << "call School operator=" << endl;
		school_name = other.school_name;
		return *this;
	}
	~School() { cout << "School::~School()" << endl; }
	virtual void print() { cout << "print() from School" << endl << "校名: " << school_name << endl; }
};

class Student : public School
{
	string dept;
	string ID;
public:
	Student() { dept = ""; ID = ""; }
	Student(string dept, string ID) { this->dept = dept; this->ID = ID;}
	Student(string school_name, string dept, string ID) : School(school_name) { this->dept = dept; this->ID = ID; }
	Student(const Student& other) : School(other) { this->dept = other.dept; this->ID = other.ID; cout << "call Student copy constructor" << endl; }
	Student& operator=(const Student& other)
	{
		cout << "call Student operator=" << endl;
		School::operator=(other);
		this->dept = other.dept;
		this->ID = other.ID;
		return *this;
	}
	~Student() { cout << "Student::~Student()" << endl; }
	void print()
	{ 
		cout << "print() from Student" << endl;
		School::print();
		cout << "系所: " << dept << " 學號: " << ID << endl;
	}
};

class CollegeStudent : public Student
{
	int grade;
public:
	CollegeStudent() { grade = 0; }
	CollegeStudent(int grade) { this->grade = grade; }
	CollegeStudent(string school_name, string dept, string ID, int grade) : Student(school_name, dept, ID) { this->grade = grade; }
	CollegeStudent(const CollegeStudent& other) : Student(other) { this->grade = other.grade; cout << "call CollegeStudent copy constructor" << endl; }
	CollegeStudent& operator=(const CollegeStudent& other)
	{
		cout << "call CollegeStudent operator=" << endl;
		Student::operator=(other);
		this->grade = other.grade;
		return *this;
	}
	~CollegeStudent() { cout << "CollegeStudent::~CollegeStudent()" << endl; }
	void print()
	{
		cout << "print() from CollegeStudent" << endl;
		Student::print();
		cout << "年級: " << grade << endl;
	}
};

class MasterStudent : public Student
{
	string professor;
public:
	MasterStudent() { professor = ""; }
	MasterStudent(string professor) { this->professor = professor; }
	MasterStudent(string school_name, string dept, string ID, string professor) : Student(school_name, dept, ID) { this->professor = professor; }
	MasterStudent(const MasterStudent& other) : Student(other) { this->professor = other.professor; cout << "call MasterStudent copy constructor" << endl; }
	MasterStudent& operator=(const MasterStudent& other)
	{
		cout << "call MasterStudent operator=" << endl;
		Student::operator=(other);
		this->professor = other.professor;
		return *this;
	}
	~MasterStudent() { cout << "MasterStudent::~MasterStudent()" << endl; }
	void print()
	{
		cout << "print() from MasterStudent" << endl;
		Student::print();
		cout << "指導教授: " << professor << endl;
	}
};

class Faculty : public School
{
	int salary;
public:
	Faculty() { salary = 0; }
	Faculty(int salary) { this->salary = salary; }
	Faculty(string school_name, int salary) : School(school_name) { this->salary = salary; }
	Faculty(const Faculty& other) : School(other) { this->salary = other.salary; cout << "call Faculty copy constructor" << endl; }
	Faculty& operator=(const Faculty& other)
	{
		cout << "call Faculty operator=" << endl;
		School::operator=(other);
		this->salary = other.salary;
		return *this;
	}
	~Faculty() { cout << "Faculty::~Faculty()" << endl; }
	void print()
	{
		cout << "print() from Faculty" << endl;
		School::print();
		cout << "薪水: " << salary << endl;
	}
};

class Staff : public Faculty
{
	string unit;
public:
	Staff() { unit = ""; }
	Staff(string unit) { this->unit = unit; }
	Staff(string school_name, int salary, string unit) : Faculty(school_name, salary) { this->unit = unit; }
	Staff(const Staff& other) : Faculty(other) { this->unit = other.unit; cout << "call Staff copy constructor" << endl; }
	Staff& operator=(const Staff& other)
	{
		cout << "call Staff operator=" << endl;
		Faculty::operator=(other);
		this->unit = other.unit;
		return *this;
	}
	~Staff() { cout << "Staff::~Staff()" << endl; }
	void print()
	{
		cout << "print() from Staff" << endl;
		Faculty::print();
		cout << "單位: " << unit << endl;
	}
};

class Professor : public Faculty
{
	string dept;
public:
	Professor() { dept = ""; }
	Professor(string dept) { this->dept = dept; }
	Professor(string school_name, int salary, string dept) : Faculty(school_name, salary) { this->dept = dept; }
	Professor(const Professor& other) : Faculty(other) { this->dept = other.dept; cout << "call Professor copy constructor" << endl; }
	Professor& operator=(const Professor& other)
	{
		cout << "call Professor operator=" << endl;
		Faculty::operator=(other);
		this->dept = other.dept;
		return *this;
	}
	~Professor() { cout << "Professor::~Professor()" << endl; }
	void print()
	{
		cout << "print() from Professor" << endl;
		Faculty::print();
		cout << "系所: " << dept << endl;
	}
};

int main()
{
	School s1("NTUST");
	Student s2("NTUST", "資工系", "M10815071");
	CollegeStudent s3("NTUST", "資工系", "M10815071", 3);
	MasterStudent s4("NTUST", "資工系", "M10815071", "Hung-Ming Chen");
	Faculty s5("NTU", 30000);
	Staff s6("NTU", 40000, "教務處");
	Professor s7("NTU", 50000, "資工系");

	School* sArr[7] = { &s1, &s2, &s3, &s4, &s5, &s6, &s7 };
	cout << "------------------print test------------------" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i << endl;
		sArr[i]->print();
		cout << endl;
	}
	cout << endl;
	
	cout << "------------------copy constructor test------------------" << endl;
	CollegeStudent ss3(s3);
	ss3.print();
	
	cout << endl;
	
	Professor ss7(s7);
	ss7.print();
	cout << endl << endl;
	
	cout << "------------------operator= test------------------" << endl;
	MasterStudent ss4;
	ss4 = s4;
	ss4.print();
	
	cout << endl;
	
	Staff ss6;
	ss6 = s6;
	ss6.print();
	cout << endl << endl;
	

	//system("pause");
	return 0;
}
=======
#include <iostream>
#include <string>

using namespace std;

class School
{
	string school_name;
public:
	School(){ school_name = ""; }
	School(string name){ school_name = name; }
	School(const School& other) { school_name = other.school_name; cout << "call School copy constructor" << endl; }
	School& operator=(const School& other)
	{ 
		cout << "call School operator=" << endl;
		school_name = other.school_name;
		return *this;
	}
	~School() { cout << "School::~School()" << endl; }
	virtual void print() { cout << "print() from School" << endl << "校名: " << school_name << endl; }
};

class Student : public School
{
	string dept;
	string ID;
public:
	Student() { dept = ""; ID = ""; }
	Student(string dept, string ID) { this->dept = dept; this->ID = ID;}
	Student(string school_name, string dept, string ID) : School(school_name) { this->dept = dept; this->ID = ID; }
	Student(const Student& other) : School(other) { this->dept = other.dept; this->ID = other.ID; cout << "call Student copy constructor" << endl; }
	Student& operator=(const Student& other)
	{
		cout << "call Student operator=" << endl;
		School::operator=(other);
		this->dept = other.dept;
		this->ID = other.ID;
		return *this;
	}
	~Student() { cout << "Student::~Student()" << endl; }
	void print()
	{ 
		cout << "print() from Student" << endl;
		School::print();
		cout << "系所: " << dept << " 學號: " << ID << endl;
	}
};

class CollegeStudent : public Student
{
	int grade;
public:
	CollegeStudent() { grade = 0; }
	CollegeStudent(int grade) { this->grade = grade; }
	CollegeStudent(string school_name, string dept, string ID, int grade) : Student(school_name, dept, ID) { this->grade = grade; }
	CollegeStudent(const CollegeStudent& other) : Student(other) { this->grade = other.grade; cout << "call CollegeStudent copy constructor" << endl; }
	CollegeStudent& operator=(const CollegeStudent& other)
	{
		cout << "call CollegeStudent operator=" << endl;
		Student::operator=(other);
		this->grade = other.grade;
		return *this;
	}
	~CollegeStudent() { cout << "CollegeStudent::~CollegeStudent()" << endl; }
	void print()
	{
		cout << "print() from CollegeStudent" << endl;
		Student::print();
		cout << "年級: " << grade << endl;
	}
};

class MasterStudent : public Student
{
	string professor;
public:
	MasterStudent() { professor = ""; }
	MasterStudent(string professor) { this->professor = professor; }
	MasterStudent(string school_name, string dept, string ID, string professor) : Student(school_name, dept, ID) { this->professor = professor; }
	MasterStudent(const MasterStudent& other) : Student(other) { this->professor = other.professor; cout << "call MasterStudent copy constructor" << endl; }
	MasterStudent& operator=(const MasterStudent& other)
	{
		cout << "call MasterStudent operator=" << endl;
		Student::operator=(other);
		this->professor = other.professor;
		return *this;
	}
	~MasterStudent() { cout << "MasterStudent::~MasterStudent()" << endl; }
	void print()
	{
		cout << "print() from MasterStudent" << endl;
		Student::print();
		cout << "指導教授: " << professor << endl;
	}
};

class Faculty : public School
{
	int salary;
public:
	Faculty() { salary = 0; }
	Faculty(int salary) { this->salary = salary; }
	Faculty(string school_name, int salary) : School(school_name) { this->salary = salary; }
	Faculty(const Faculty& other) : School(other) { this->salary = other.salary; cout << "call Faculty copy constructor" << endl; }
	Faculty& operator=(const Faculty& other)
	{
		cout << "call Faculty operator=" << endl;
		School::operator=(other);
		this->salary = other.salary;
		return *this;
	}
	~Faculty() { cout << "Faculty::~Faculty()" << endl; }
	void print()
	{
		cout << "print() from Faculty" << endl;
		School::print();
		cout << "薪水: " << salary << endl;
	}
};

class Staff : public Faculty
{
	string unit;
public:
	Staff() { unit = ""; }
	Staff(string unit) { this->unit = unit; }
	Staff(string school_name, int salary, string unit) : Faculty(school_name, salary) { this->unit = unit; }
	Staff(const Staff& other) : Faculty(other) { this->unit = other.unit; cout << "call Staff copy constructor" << endl; }
	Staff& operator=(const Staff& other)
	{
		cout << "call Staff operator=" << endl;
		Faculty::operator=(other);
		this->unit = other.unit;
		return *this;
	}
	~Staff() { cout << "Staff::~Staff()" << endl; }
	void print()
	{
		cout << "print() from Staff" << endl;
		Faculty::print();
		cout << "單位: " << unit << endl;
	}
};

class Professor : public Faculty
{
	string dept;
public:
	Professor() { dept = ""; }
	Professor(string dept) { this->dept = dept; }
	Professor(string school_name, int salary, string dept) : Faculty(school_name, salary) { this->dept = dept; }
	Professor(const Professor& other) : Faculty(other) { this->dept = other.dept; cout << "call Professor copy constructor" << endl; }
	Professor& operator=(const Professor& other)
	{
		cout << "call Professor operator=" << endl;
		Faculty::operator=(other);
		this->dept = other.dept;
		return *this;
	}
	~Professor() { cout << "Professor::~Professor()" << endl; }
	void print()
	{
		cout << "print() from Professor" << endl;
		Faculty::print();
		cout << "系所: " << dept << endl;
	}
};

int main()
{
	School s1("NTUST");
	Student s2("NTUST", "資工系", "M10815071");
	CollegeStudent s3("NTUST", "資工系", "M10815071", 3);
	MasterStudent s4("NTUST", "資工系", "M10815071", "Hung-Ming Chen");
	Faculty s5("NTU", 30000);
	Staff s6("NTU", 40000, "教務處");
	Professor s7("NTU", 50000, "資工系");

	School* sArr[7] = { &s1, &s2, &s3, &s4, &s5, &s6, &s7 };
	cout << "------------------print test------------------" << endl;
	for (int i = 0; i < 7; i++)
	{
		cout << i << endl;
		sArr[i]->print();
		cout << endl;
	}
	cout << endl;
	
	cout << "------------------copy constructor test------------------" << endl;
	CollegeStudent ss3(s3);
	ss3.print();
	
	cout << endl;
	
	Professor ss7(s7);
	ss7.print();
	cout << endl << endl;
	
	cout << "------------------operator= test------------------" << endl;
	MasterStudent ss4;
	ss4 = s4;
	ss4.print();
	
	cout << endl;
	
	Staff ss6;
	ss6 = s6;
	ss6.print();
	cout << endl << endl;
	

	//system("pause");
	return 0;
}
>>>>>>> 3af4f55 (commit2021/05/07)
