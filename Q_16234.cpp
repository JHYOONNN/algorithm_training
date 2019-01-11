#include<iostream>
#include<queue>

using namespace std;

int people[50][50];
int team[50][50];
int N, L, R;

queue<pair<int, int>>team_q[2501];
int team_hap[2501];
int main() {
	scanf("%d %d %d", &N, &L, &R);
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &people[i][j]);
		}
	}

	bool people_can_move = false;
	int time = 0;
	while (people_can_move == true || time == 0) {
		people_can_move = false;
		int team_num = 1;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				queue<pair<int, int>> same_team;
				bool make_new_team = false;
				if (team[i][j] == 0) {
					same_team.push(make_pair(i, j));
					make_new_team = true;
				}

				while (!same_team.empty()) {
					int pos_x = same_team.front().first;
					int pos_y = same_team.front().second;
					same_team.pop();
					if (team[pos_x][pos_y] == 0) {
						team[pos_x][pos_y] = team_num;
						team_q[team_num].push(make_pair(pos_x, pos_y));
						team_hap[team_num] += people[pos_x][pos_y];
						if (0 < pos_x) {
							if (team[pos_x - 1][pos_y] == 0 && abs(people[pos_x][pos_y] - people[pos_x - 1][pos_y]) >= L
								&& abs(people[pos_x][pos_y] - people[pos_x - 1][pos_y]) <= R) {
								same_team.push(make_pair(pos_x - 1, pos_y));
								people_can_move = true;
							}
						}

						if (N - 1 > pos_x) {
							if (team[pos_x + 1][pos_y] == 0 && abs(people[pos_x][pos_y] - people[pos_x + 1][pos_y]) >= L
								&& abs(people[pos_x][pos_y] - people[pos_x + 1][pos_y]) <= R) {
								same_team.push(make_pair(pos_x + 1, pos_y));
								people_can_move = true;
							}
						}

						if (0 < pos_y) {
							if (team[pos_x][pos_y - 1] == 0 && abs(people[pos_x][pos_y] - people[pos_x][pos_y - 1]) >= L
								&& abs(people[pos_x][pos_y] - people[pos_x][pos_y - 1]) <= R) {
								same_team.push(make_pair(pos_x, pos_y - 1));
								people_can_move = true;
							}
						}

						if (N - 1 > pos_y) {
							if (team[pos_x][pos_y + 1] == 0 && abs(people[pos_x][pos_y] - people[pos_x][pos_y + 1]) >= L
								&& abs(people[pos_x][pos_y] - people[pos_x][pos_y + 1]) <= R) {
								same_team.push(make_pair(pos_x, pos_y + 1));
								people_can_move = true;
							}
						}
					}
				}

				if (make_new_team == true) {
					team_num++;
				}
			}
		}
		time++;
		if (people_can_move == true) {
			for (int i = 1; i < team_num; i++) {
				int team_size = team_q[i].size();
				while (!team_q[i].empty()) {
					int x = team_q[i].front().first;
					int y = team_q[i].front().second;
					team_q[i].pop();
					people[x][y] = team_hap[i] / team_size;
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = 0; j < N; j++) {
					team[i][j] = 0;
				}
			}
			for (int i = 0; i < 2500; i++) {
				team_hap[i] = 0;
			}
		}
	}

	printf("%d\n", time - 1);
}