//============================================================================
// Name        : Vectors.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int main() {

	vector<string> strings;

	strings.push_back("one");
	strings.push_back("two");
	strings.push_back("three");

	cout << "For loop: " << endl;
	for(int i=0; i<strings.size(); i++) {
		cout << strings[i] << endl;
	}
	cout << endl;

	cout << "Iterator loop: " << endl;

	// auto 实际上是 iterator， iterator其实是指针，所以要用 * 取得对应地址的值
	for(auto it = strings.begin(); it != strings.end(); ++it) {
		cout << *it << endl;	// 注意要用 *it 取值！
	}
	cout << endl;

	cout << "Single item." << endl;
	vector<string>::iterator it = strings.begin();
	it += 2;

	cout << *it << endl;

	return 0;
}
