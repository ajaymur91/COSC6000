/*
 CPP sample06.cpp
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main(int argc, char *argv[]) {
	int n;

	cout << "number of terms : ";
	cin >> n;
	cout << "n=" << n << endl;
	;

	double x = 0.0;
	for (int i = 0; i < n; i += 2) {
		x += 1.0 / (2 * i + 1);
		x -= 1.0 / (2 * i + 3);
	}

	cout << "Pi=" << setprecision(16) << 4.0 * x << endl;

	return 0;
}
