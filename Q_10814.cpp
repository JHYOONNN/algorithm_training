#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;
struct Person {
	int age;
	string name;
};
bool cmp(const Person &u, const Person &v) {
	return u.age < v.age;
}

int main() {
	int N;
	cin >> N;

	vector<Person> arr(N);
	
	for (int i = 0; i < N; i++) {
		cin >> arr[i].age >> arr[i].name;
	}

	stable_sort(arr.begin(), arr.end(), cmp);

	for (int i = 0; i < N; i++) {
		cout << arr[i].age <<' '<< arr[i].name << '\n';
	}

	return 0;
}