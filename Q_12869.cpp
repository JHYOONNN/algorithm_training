#include<iostream>
#include<vector>

using namespace std;

int N;
int hp[3];
int best_time = 100000;
int checker[61][61][61];
int dmg[6][3] = { {9,3,1}, {9,1,3}, {3,9,1}, {3,1,9}, {1,9,3}, {1,3,9} };

void dp(int time) {
	//printf("hp : %d %d %d\n", hp[0], hp[1], hp[2]);
	bool all_dead = true;
	for (int i = 0; i < 3; i++) {
		if (hp[i] > 0) all_dead = false;
	}
	if (all_dead == true) {
		if (time < best_time)
			best_time = time;
	}
	
	else {
		for (int i = 0; i < 6; i++) {
			int hp_t[3];
			for (int j = 0; j < 3; j++)
				hp_t[j] = hp[j];
			hp[0] -= dmg[i][0];
			hp[1] -= dmg[i][1];
			hp[2] -= dmg[i][2];

			if (hp[0] < 0) hp[0] = 0; 
			if (hp[1] < 0) hp[1] = 0; 
			if (hp[2] < 0) hp[2] = 0;

			if (checker[hp[0]][hp[1]][hp[2]] == 0 || checker[hp[0]][hp[1]][hp[2]] > time) {
				checker[hp[0]][hp[1]][hp[2]] = time;
				dp(time + 1);
			}
			for (int j = 0; j < 3; j++)
				hp[j] = hp_t[j];
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &hp[i]);
	}
	dp(0);
	cout << best_time << endl;
}