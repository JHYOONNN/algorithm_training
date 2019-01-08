#include<iostream>
#include<queue>
#include<string>

using namespace std;

int map[1000][1000];

queue<pair<int,int>> my_q;
queue<int> k_q;

int is_new[1000][1000];
int remain_k[1000][1000][11];
int moved_time[1000][1000];

int move_dir[4][2] = { {1, 0}, {-1,0}, {0,1}, {0, -1} };

int main() {
	int N, M, K;
	string map_s;

	scanf("%d %d %d", &N, &M, &K);
	
	for (int i = 0; i < N; i++) {
		cin >> map_s;
		for (int j = 0; j < M; j++)
			map[i][j] = (int)map_s[j] - 48;
	}

	pair<int, int> my_pos;
	my_pos = make_pair(0, 0);
	is_new[0][0] = 1;
	remain_k[0][0][K] = 1;
	moved_time[0][0] = 0;

	my_q.push(make_pair(0, 0));
	k_q.push(K);

	bool finded = false;
	while (my_q.size() > 0) {
		my_pos = my_q.front();
		if (my_pos.first == N - 1 && my_pos.second == M - 1) {
			printf("%d\n", moved_time[my_pos.first][my_pos.second] + 1);
			finded = true;
			break;
		}
		
		for (int i = 0; i < 4; i++) {
			int my_k = k_q.front();
			int new_pos_x = my_pos.first + move_dir[i][0];
			int new_pos_y = my_pos.second + move_dir[i][1];
			if (new_pos_x >= 0 && new_pos_x < N &&new_pos_y >= 0 && new_pos_y < M) {
				if (map[new_pos_x][new_pos_y] == 0 && is_new[new_pos_x][new_pos_y] == 0) {
					my_q.push(make_pair(new_pos_x, new_pos_y));
					k_q.push(my_k);
					is_new[new_pos_x][new_pos_y] = 1;
					remain_k[new_pos_x][new_pos_y][my_k] = 1;
					moved_time[new_pos_x][new_pos_y] = moved_time[my_pos.first][my_pos.second] + 1;
					
				}

				if (map[new_pos_x][new_pos_y] == 0 && is_new[new_pos_x][new_pos_y] == 1 && remain_k[new_pos_x][new_pos_y][my_k] != 1) {
					my_q.push(make_pair(new_pos_x, new_pos_y));
					k_q.push(my_k);
					is_new[new_pos_x][new_pos_y] = 1;
					remain_k[new_pos_x][new_pos_y][my_k] = 1;
					moved_time[new_pos_x][new_pos_y] = moved_time[my_pos.first][my_pos.second] + 1;
				}

				if (map[new_pos_x][new_pos_y] == 1 && my_k > 0 && remain_k[new_pos_x][new_pos_y][my_k - 1] != 1) {
					my_q.push(make_pair(new_pos_x, new_pos_y));
					k_q.push(my_k - 1);
					is_new[new_pos_x][new_pos_y] = 1;
					remain_k[new_pos_x][new_pos_y][my_k - 1] = 1;
					moved_time[new_pos_x][new_pos_y] = moved_time[my_pos.first][my_pos.second] + 1;
				}
			}
		}
		my_q.pop();
		k_q.pop();
	}
	
	if (finded == false)
		printf("-1\n");
	return 0;
}