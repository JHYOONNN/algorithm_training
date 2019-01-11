#include<iostream>
#include<string>
#include<queue>

using namespace std;

int checker[1500][1500];
int has_group[100][100];
int has_group2[100][100];
int move_pos[4][2] = { {1,0},{-1,0},{0,1},{0,-1} };
int N;
string str_arr[100];
string str_arr2[100][100];
queue<pair<int, int>>my_q;
vector<pair<int, int>>my_vec;

void search(pair<int,int>cur_pos, int g_num) {
	int c_x = cur_pos.first;
	int c_y = cur_pos.second;

	for (int i = 0; i < 4; i++) {
		int x_ = c_x + move_pos[i][0];
		int y_ = c_y + move_pos[i][1];
		if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < N && has_group[x_][y_] == 0) {
			if (str_arr[c_x][c_y] == str_arr[x_][y_]) {
				has_group[x_][y_] = has_group[c_x][c_y];
				search(make_pair(x_, y_), g_num);
			}
		}
	}
}

void search2(pair<int, int>cur_pos, int g_num) {
	int c_x = cur_pos.first;
	int c_y = cur_pos.second;

	for (int i = 0; i < 4; i++) {
		int x_ = c_x + move_pos[i][0];
		int y_ = c_y + move_pos[i][1];
		if (x_ >= 0 && x_ < N && y_ >= 0 && y_ < N && has_group2[x_][y_] == 0) {
			if (str_arr2[c_x][c_y] == str_arr2[x_][y_]) {
				has_group2[x_][y_] = has_group2[c_x][c_y];
				search2(make_pair(x_, y_), g_num);
			}
		}
	}
}

int main() {

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		cin >> str_arr[i];
		for (int j = 0; j < str_arr[i].size(); j++) {
			if (str_arr[i][j] == 'G')
				str_arr2[i][j] = 'R';
			else
				str_arr2[i][j] = str_arr[i][j];
		}
	}

	int count = 1;
	has_group[0][0] = 1;
	search(make_pair(0, 0), 1);

	for(int i = 0 ; i < N; i ++)
		for (int j = 0; j < N; j++) {
			if (has_group[i][j] == 0) {
				has_group[i][j] = ++count;
				search(make_pair(i, j), has_group[i][j]);
			}
		}

	printf("%d ", count);

	count = 1;
	has_group2[0][0] = 1;
	search2(make_pair(0, 0), 1);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (has_group2[i][j] == 0) {
				has_group2[i][j] = ++count;
				search2(make_pair(i, j), has_group[i][j]);
			}
		}

	printf("%d\n", count);
}