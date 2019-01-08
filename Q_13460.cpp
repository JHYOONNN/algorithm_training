#include<iostream>
#include<vector>

using namespace std;

int N;

int map[20][20];
int best = 0;


void cal(int time) {
	if (time == 5) {
		int best_gap = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (map[i][j] > best_gap) best_gap = map[i][j];
			}
		}

		if (best_gap > best) best = best_gap;
	}

	else {
		int map_bef[20][20];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				map_bef[i][j] = map[i][j];
			}
		}

		for (int i = 0; i < 4; i++) {
			
			
			if (i == 0) {
				for (int j = 0; j < N; j++) {
					vector<int>gap;
					for (int k = 0; k < N; k++) {
						if (map[k][j] != 0) {
							gap.push_back(map[k][j]);
						}
					}

					int pos = 0;
					for (int k = 0; k < gap.size(); k++) {
						if (k < gap.size() - 1) {
							if (gap[k] == gap[k + 1]) {
								map[pos][j] = 2 * gap[k];
								pos++;
								k++;
							}
							else {
								map[pos][j] = gap[k];
								pos++;
							}
						}
						else {
							map[pos][j] = gap[k];
							pos++;
						}
					}
					for (int k = pos; k < N; k++) {
						map[k][j] = 0;
					}
				}
			}

			if (i == 1) {
				for (int j = 0; j < N; j++) {
					vector<int>gap;
					for (int k = N - 1; k >= 0; k--) {
						if (map[k][j] != 0) {
							gap.push_back(map[k][j]);
						}
					}
					int pos = 0;
					for (int k = 0; k < gap.size(); k++) {
						if (k < gap.size() - 1) {
							if (gap[k] == gap[k + 1]) {
								map[N - 1 - pos][j] = 2 * gap[k];
								pos++; 
								k++;
							}
							else {
								map[N - 1 - pos][j] = gap[k];
								pos++;
							}
						}
						else {
							map[N - 1 - pos][j] = gap[k];
							pos++;
						}
					}

					for (int k = N - 1 - pos; k >= 0; k--) {
						map[k][j] = 0;
					}
				}
			}

			if (i == 2) {
				for (int j = 0; j < N; j++) {
					vector<int>gap;
					for (int k = 0; k < N; k++) {
						if (map[j][k] != 0) {
							gap.push_back(map[j][k]);
						}
					}

					int pos = 0;
					for (int k = 0; k < gap.size(); k++) {
						if (k < gap.size() - 1) {
							if (gap[k] == gap[k + 1]) {
								map[j][pos] = 2 * gap[k];
								pos++;
								k++;
							}
							else {
								map[j][pos] = gap[k];
								pos++;
							}
						}
						else {
							map[j][pos] = gap[k];
							pos++;
						}
					}
					for (int k = pos; k < N; k++) {
						map[j][k] = 0;
					}
				}
			}

			if (i == 3) {
				for (int j = 0; j < N; j++) {
					vector<int>gap;
					for (int k = N - 1; k >= 0; k--) {
						if (map[j][k] != 0) {
							gap.push_back(map[j][k]);
						}
					}
					int pos = 0;
					for (int k = 0; k < gap.size(); k++) {
						if (k < gap.size() - 1) {
							if (gap[k] == gap[k + 1]) {
								map[j][N - 1 - pos] = 2 * gap[k];
								pos++; k++;
							}
							else {
								map[j][N - 1 - pos] = gap[k];
								pos++;
							}
						}
						else {
							map[j][N - 1 - pos] = gap[k];
							pos++;
						}
					}

					for (int k = N - 1 - pos; k >= 0; k--) {
						map[j][k] = 0;
					}
				}
			}
			
			
			

			cal(time + 1);

			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					map[i][j] = map_bef[i][j];
				}
			}
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j ++ ) {
			scanf("%d", &map[i][j]);
		}
	}

	cal(0);
	printf("%d\n", best);
}