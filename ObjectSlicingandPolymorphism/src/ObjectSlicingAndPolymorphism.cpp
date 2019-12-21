//============================================================================
// Name        : Object.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

class Parent {
private:
	int one;

public:
	
	// subclass 被copy 时，要调用parent的constructor
	Parent(): one(0) {

	}

	// copy constructor
	Parent(const Parent &other): one(0) {

		one = other.one;
		cout << "copy parent" << endl;
	}

	//  虚函数是指一个类中你希望重载的成员函数，当你用一个基类指针或引用指向一个继承类对象的时候，
	//	你调用一个虚函数，实际调用的是继承类的版本。
	virtual void print() {
		cout << "parent" << endl;
	}

	virtual ~Parent() {	// virtual constructor

	}
};

class Child: public Parent {
private:
	int two;

public:
	Child(): two(0) {

	}

	void print() {
		cout << "child" << endl;
	}
};

int main() {

	Child c1;
	Parent &p1 = c1;
	p1.print();	// 实际上会调用child的print函数，因为parent的print是virtual

	// copy initialization
	Parent p2 = Child();	// 实际上是copy一个parent object，但是被cast成child
	p2.print();

	return 0;
}

// parent 被 cast成child叫做 object slicing

// "Slicing" is where you assign an object of a derived class 
// to an instance of a base class, 
// thereby losing part of the information - some of it is "sliced" away.