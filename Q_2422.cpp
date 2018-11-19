#include<iostream>
#include<vector>
#include<cmath>

using namespace std;

int N, M;
int how_many = 0;

int main() {
	int a, b;
	scanf("%d %d", &N, &M);

	vector<vector<int>> cannot(N, vector<int>(N,0));

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		cannot[a - 1][b - 1] = 1;
		cannot[b - 1][a - 1] = 1;
	}

	for (int first_choose = 0; first_choose < N - 2; first_choose++) {

		for (int second_choose = first_choose + 1; second_choose < N - 1; second_choose++) {

			for (int third_choose = second_choose + 1; third_choose < N; third_choose++) {
				bool breaker2 = false;
				if (cannot[first_choose][second_choose] == 1) breaker2 = true;
				else if (cannot[second_choose][third_choose] == 1) breaker2 = true;
				else if (cannot[first_choose][third_choose] == 1) breaker2 = true;
				

				if (breaker2 == false) { how_many++; }
			}

		}
	}
	printf("%d \n", how_many);
}