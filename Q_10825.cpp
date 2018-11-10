#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

struct Person {
	string name;
	int gook;
	int young;
	int soo;
};

bool cmp(const Person &u, const Person &v) {
	if (u.gook > v.gook) return true;
	else if (u.gook == v.gook) {
		if (u.young < v.young) return true;
		else if (u.young == v.young) {
			if (u.soo > v.soo) return true;
			else if (u.soo == v.soo) {
				return u.name < v.name;
			}
		}
	}

	return false;
}
int main() {
	int N;
	scanf("%d", &N);
	vector<Person> arr(N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i].name >> arr[i].gook >> arr[i].young >> arr[i].soo;
	}

	sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].name<< "\n";
	}
}