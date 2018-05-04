/*
 CPP sample05.cpp
 */

#include <iostream>

using namespace std;

int main(int argc, char *argv[]) {
	int a;

	while (1) {
		cout << "input a number:";
		cin >> a;

		if (a == 0)
			break;

		if (a % 2) {
			cout << a << " is odd number" << endl;
		} else {
			cout << a << " is even number" << endl;
		}
	}
	cout << "bye" << endl;

	return 0;
}
