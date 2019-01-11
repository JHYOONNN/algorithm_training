#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N, M, K;

int A[10][10];
int yang[10][10];

vector<int>age[10][10];
int dead_yang[10][10];

int main() {
	scanf("%d %d %d", &N, &M, &K);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &A[i][j]);
		}

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			yang[i][j] = 5;
		}

	for (int i = 0; i < M; i++) {
		int x, y, age_temp;
		scanf("%d %d %d", &x, &y, &age_temp);
		age[x - 1][y - 1].push_back(age_temp);
	}

	for (int i = 0; i < K; i++) {
		//봄
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				sort(age[j][k].begin(), age[j][k].end());
				int dead_point = -1;
				for (int l = 0; l < age[j][k].size(); l++) {
					if (yang[j][k] - age[j][k][l] < 0) {
						dead_point = l;
						//printf("%d %d have : %d need : %d\n", j, k, yang[j][k], age[j][k][l]);
						break;
					}
					
					else {
						yang[j][k] -= age[j][k][l];
						++age[j][k][l];
					}
				}

				if (dead_point != -1) {
					int vec_size = age[j][k].size();
					for (int l = 0; l < vec_size - dead_point; l++) {
						dead_yang[j][k] += age[j][k][age[j][k].size() - 1] / 2; //나중에 0으로 초기화
						age[j][k].pop_back();
					}
				}
				//여름
				yang[j][k] += dead_yang[j][k];
				dead_yang[j][k] = 0; // 0으로 초기화
			}
		}

		//가을
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				for (int l = 0; l < age[j][k].size(); l++) {
					if (age[j][k][l] % 5 == 0) {
						if (j > 0 && k > 0) {
							age[j - 1][k - 1].push_back(1);
						}
						if (j > 0) {
							age[j - 1][k].push_back(1);
						}
						if (j > 0 && k < N - 1) {
							age[j - 1][k + 1].push_back(1);
						}
						if (k < N - 1) {
							age[j][k + 1].push_back(1);
						}
						if (j < N - 1 && k < N - 1) {
							age[j + 1][k + 1].push_back(1);
						}
						if (j < N - 1) {
							age[j + 1][k].push_back(1);
						}
						if (j < N - 1 && k > 0) {
							age[j + 1][k - 1].push_back(1);
						}
						if (k > 0) {
							age[j][k - 1].push_back(1);
						}
					}
				}
			}
		}

		//겨울
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				yang[j][k] += A[j][k];
			}
		}
		/*
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				printf("%d ", age[j][k].size());
			}
			printf("\n");
		}

		printf("\n");
		*/
	}

	int dap = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j ++ ) {
			dap += age[i][j].size();
		}
	}

	printf("%d\n", dap);
}