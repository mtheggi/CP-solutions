#include <iostream>
#include <vector>
using namespace std;
int main()
{
	int n;
	cin >> n;
	int z2;
	vector<int> v1;
	vector<int> v2;
	vector<int> v3;
	int count1 = 0; int count2 = 0; int count3 = 0;
	for (int i = 0; i < n; i++)
	{
		int a;
		cin >> a;
		if (a == 1)
		{
			v1.push_back(i);
			count1++;
		}
		else if (a == 2)
		{
			v2.push_back(i);
			count2++;
		}

		else if (a == 3)
		{
			v3.push_back(i);
			count3++;
		}
	}
	if (count3 == 0 || count1 == 0 || count2 == 0)
		cout << 0;
	else
	{
		z2 = min(count1, min(count2, count3));
		cout << z2 << endl; 

		for (int j = 0; j < z2; j++)
		{
			cout << v1[j] + 1 << " " << v2[j] + 1 << " " << v3[j] + 1 << endl;
		}
	}

}
