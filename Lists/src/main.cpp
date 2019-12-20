//============================================================================
// Name        :
// Author      : John Purcell
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <list>

using namespace std;

int main() {

	// C++ 里的list是双向链表！
	list<int> numbers;

	numbers.push_back(1);
	numbers.push_back(2);
	numbers.push_back(3);
	numbers.push_front(0);	// 可以从头加哦

	list<int>::iterator it = numbers.begin();
	it++;
	numbers.insert(it, 100);	// 插入node
	cout << "Element: " << *it << endl;

	list<int>::iterator eraseIt = numbers.begin();
	eraseIt++;
	eraseIt = numbers.erase(eraseIt);	// 删掉刚刚插入的node
	cout << "Element: " << *eraseIt << endl;

	for(list<int>::iterator it=numbers.begin(); it != numbers.end(); it++) {
		cout << *it << endl;
	}
	// 依然打印出 0 1 2 3

	it = numbers.begin();
	// 想删掉1， 插入1234
	while(it != numbers.end()) {
		if(*it == 2) {
			// 在当前node前一个节点接插人
			numbers.insert(it, 1234);
		}
		if(*it == 1) {
			// 因为 1 删掉后 it 自动指向下一个node，所以不用 it++
			it = numbers.erase(it);
		} else {
			it++;
		}
	}
	// 最后的list变成： 0 1234 2 3

	return 0;
}
