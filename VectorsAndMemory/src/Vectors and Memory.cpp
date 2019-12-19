//============================================================================
// Name        : Vectors.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
using namespace std;

int main() {

	vector<double> numbers(0);

	cout << "Size: " << numbers.size() << endl;

	int capacity = numbers.capacity();
	cout << "Capacity: " << capacity << endl;

	for(int i=0; i<10000; i++) {

		if(numbers.capacity() != capacity) {
			capacity = numbers.capacity();
			cout << "Capacity: " << capacity << endl;
		}

		numbers.push_back(i);	// push_back 会使 size + 1
	}

	numbers.reserve(100000);	// capacity 变为 100000
	cout << numbers[2] << endl;
	cout << "Size: " << numbers.size() << endl;	// size 依然是 10000，可以用numbers.resize()来改变vector的size
	cout << "Capacity: " << numbers.capacity() << endl;


	return 0;
}
