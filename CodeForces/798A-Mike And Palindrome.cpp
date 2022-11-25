#include<iostream>
#include<string>
using namespace std;

int main() {
	string n;
	cin >> n;
	int sum = 0;
	int j = n.length() - 1;
	for (int i = 0; i < (n.length() / 2); i++) {
		if (n[i] != n[j]) {
			sum++;
		}
		j--;
	}

	if (sum == 1 || (sum == 0 && n.length() % 2 == 1)) {
		cout << "YES" << endl;
	}
	else
	{
		cout << "NO" << endl;

	}

}