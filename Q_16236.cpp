#include<iostream>
#include<vector>
#include<queue>

using namespace std;
int N;
int map[20][20];
int shark_size = 2;
int eat = 0;
int dxdy[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int go_time;

vector<pair<int, int>>can_eat;
pair<int, int>shark_pos;

bool is_good_pos(int x, int y) {
	if (x >= 0 && x < N && y >= 0 && y < N)
		return true;
	else return false;
}

pair<int,int> cal_route(vector<pair<int, int>>fish, pair<int, int>shark) {
	vector<vector<int>>checker(N, vector<int>(N,0));
	queue<pair<int, int>> my_q;
	queue<int> time;
	my_q.push(shark);
	time.push(0);
	checker[shark.first][shark.second] = 1;
	vector<pair<int, int>>can_fish;
	int best_time = 1000000;

	while (!my_q.empty()) {
		bool find_fish = false;
		int pos_x = my_q.front().first;
		int pos_y = my_q.front().second;
		int time_ = time.front();
		my_q.pop();
		time.pop();
		if (time_ > best_time) break;

		else  {
			for (int i = 0; i < fish.size(); i++) {
				if (pos_x == fish[i].first && pos_y == fish[i].second) {
					can_fish.push_back(make_pair(pos_x, pos_y));
					find_fish = true;
					best_time = time_;
				}
			}
			if (find_fish == false) {
				for (int i = 0; i < 4; i++) {
					int x_ = pos_x + dxdy[i][0];
					int y_ = pos_y + dxdy[i][1];
					if (is_good_pos(x_, y_) == true) {
						if (checker[x_][y_] == 0 && map[x_][y_] <= shark_size) {
							my_q.push(make_pair(x_, y_));
							time.push(time_ + 1);
							checker[x_][y_] = 1;
						}
					}
				}
			}
		}
	}

	int bx = 100000, by = 100000;

	if (can_fish.size() > 1) {
		go_time = best_time;
		for (int i = 0; i < can_fish.size(); i++) {
			if (bx > can_fish[i].first) {
				bx = can_fish[i].first;
				by = can_fish[i].second;
			}
			else if (bx == can_fish[i].first) {
				if (by > can_fish[i].second) {
					bx = can_fish[i].first;
					by = can_fish[i].second;
				}
			}
		}
		return make_pair(bx, by);
	}
	else if (can_fish.size() == 1) {
		go_time = best_time;
		return make_pair(can_fish[0].first, can_fish[0].second);
	}
	else return make_pair(-1, -1);
}

int main() {
	int final_time = 0;
	scanf("%d", &N);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 9) {
				shark_pos.first = i;
				shark_pos.second = j;
				map[i][j] = 0;
			}
		}

	while (1) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (map[i][j] > 0 && map[i][j] < shark_size) {
					can_eat.push_back(make_pair(i, j));
				}
		if (can_eat.size() == 0) break;

		else {
			pair<int, int>best = cal_route(can_eat, shark_pos);
			if (best.first == -1 && best.second == -1) break;
			else {
				shark_pos.first = best.first;
				shark_pos.second = best.second;
				map[best.first][best.second] = 0;
				final_time += go_time;
				eat += 1;
				if (eat == shark_size) {
					shark_size += 1;
					eat = 0;
				}
			}
		}
		can_eat.clear();
	}

	printf("%d\n", final_time);
}