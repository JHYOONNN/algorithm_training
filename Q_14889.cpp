#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int arr[20][20];

vector<int> member1;
vector<int> member2;
int dif = 100000;

void choose_member(int member_count, int n, int last) {
	if (member_count != n/2) {
		for (int i = last + 1; i <= n/2 + member_count; i++) {
			member1.push_back(i);
			choose_member(member_count + 1, n, i);
			member1.pop_back();
		}
	}

	if (member_count == n / 2) {
		for (int i = 0; i < n; i++) {
			for (vector<int>::size_type j = 0; j < member1.size(); j++) {
				if (i == member1[j]) break;
				if (j == member1.size() - 1 && i != member1[j]) {
					member2.push_back(i);
				}
			}
		}

		int team1_point = 0;
		int team2_point = 0;
		
		for (vector<int>::size_type i = 0; i < member1.size() - 1; i++)
			for (vector<int>::size_type j = i + 1; j < member1.size(); j++) {
				team1_point += arr[member1[i]][member1[j]];
				team1_point += arr[member1[j]][member1[i]];
			}

		for(vector<int>::size_type i =0; i < member2.size() - 1; i++)
			for (vector<int>::size_type j = i + 1; j < member2.size(); j++) {
				team2_point += arr[member2[i]][member2[j]];
				team2_point += arr[member2[j]][member2[i]];
			}

		int dif_temp = abs(team1_point - team2_point);
		if (dif_temp < dif) dif = dif_temp;
		member2.clear();
	}
}
int main() {
	int N;

	scanf("%d", &N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &arr[i][j]);
	
	choose_member(0, N, -1);

	printf("%d\n", dif);
}