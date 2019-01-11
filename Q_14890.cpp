#include<iostream>
#include<vector>

using namespace std;

int map[100][100];
int N, L;
int dap;
int main() {
	scanf("%d %d", &N, &L);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%d", &map[i][j]);

	for (int i = 0; i < N; i++) {
		bool can_go = true;
		vector<int> has_load(N,0);
		for (int j = 0; j < N - 1; j++) {
			if (abs(map[i][j] - map[i][j + 1]) > 1) {
				can_go = false;
				break;
			}
			else if (map[i][j] == map[i][j + 1]) continue;
			else if (map[i][j] + 1 == map[i][j + 1]) {
				
				bool can_make_load = true;
				if (j < L - 1) {
					can_make_load = false;
				}
				else {
					if (has_load[j] == 1) {
						can_make_load = false;
					}
					for (int k = 1; k < L; k++) {
						
						if (map[i][j - k] != map[i][j]) {
							can_make_load = false;
							
						}
						if (has_load[j - k] == 1) {
							can_make_load = false;
							
						}
					}
				}
				if (can_make_load == true) {
					for (int k = 0; k < L; k++) {
						has_load[j - k] = 1;
					}
				}
				else {
					
					can_go = false;
					break;
				}
			}
			else if (map[i][j] - 1 == map[i][j + 1]) {
				bool can_make_load = true;
				if (N - 1 - j < L) can_make_load = false;
				else {
					for (int k = 2; k <= L; k++) {
						if (map[i][j + k] != map[i][j + 1]) can_make_load = false;
						if (has_load[j + k] == 1) can_make_load = false;
					}
				}
				if (can_make_load == true) {
					for (int k = 1; k <= L; k++) {
						has_load[j + k] = 1;
					}
				}
				else {
					can_go = false;
					break;
				}
				
			}
		}
		if (can_go == true) {
			dap++;
		}
	}

	for (int i = 0; i < N; i++) {
		bool can_go = true;
		vector<int> has_load(N, 0);
		for (int j = 0; j < N - 1; j++) {
			if (abs(map[j][i] - map[j+1][i]) > 1) {
				can_go = false;
				break;
			}
			else if (map[j][i] == map[j+1][i]) continue;
			else if (map[j][i] + 1 == map[j+1][i]) {

				bool can_make_load = true;
				if (j < L - 1) {
					can_make_load = false;
				}
				else {
					if (has_load[j] == 1) {
						can_make_load = false;
					}
					for (int k = 1; k < L; k++) {

						if (map[j-k][i] != map[j][i]) {
							can_make_load = false;

						}
						if (has_load[j - k] == 1) {
							can_make_load = false;

						}
					}
				}
				if (can_make_load == true) {
					for (int k = 0; k < L; k++) {
						has_load[j - k] = 1;
					}
				}
				else {
					can_go = false;
					break;
				}
			}

			else if (map[j][i] - 1 == map[j+1][i]) {
				
				bool can_make_load = true;
				if (N - 1 - j < L) can_make_load = false;
				else {
					
					for (int k = 2; k <= L; k++) {
						if (map[j + k][i] != map[j + 1][i]) {
							can_make_load = false;
						}
						if (has_load[j + k] == 1) can_make_load = false;
					}
				}
				if (can_make_load == true) {
					
					for (int k = 1; k <= L; k++) {
						has_load[j + k] = 1;
					}
				}
				else {
					can_go = false;
					break;
				}

			}
		}
		if (can_go == true) {
			dap++;
		}
	}

	printf("%d\n", dap);
}