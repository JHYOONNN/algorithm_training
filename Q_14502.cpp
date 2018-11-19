#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int check_point[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };

int main() {
	int N, M;
	scanf("%d %d", &N, &M);
	int not_spread_best = 0;

	vector<vector<int>> arr(N, vector<int>(M));
	vector<vector<int>> temp_arr(N, vector<int>(M));
	vector<pair<int, int>> can_choose;
	vector<pair<int, int>> choose_node(3);
	pair<int, int> temp;

	queue<pair<int, int>> virus_point;
	vector<pair<int, int>> virus_point_temp;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &arr[i][j]);
			temp_arr[i][j] = arr[i][j];
			if (arr[i][j] == 0) {
				temp.first = i; temp.second = j;
				can_choose.push_back(temp);
			}
			if (arr[i][j] == 2) {
				temp.first = i; temp.second = j;
				virus_point_temp.push_back(temp);
			}
		}

	for (vector<int>::size_type i =0; i<can_choose.size();i++)
		for (vector<int>::size_type j = i+1; j<can_choose.size(); j++)
			for (vector<int>::size_type k = j+1; k<can_choose.size(); k++) {
				arr[can_choose[i].first][can_choose[i].second] = 1;
				arr[can_choose[j].first][can_choose[j].second] = 1;
				arr[can_choose[k].first][can_choose[k].second] = 1;

				for (vector<int>::size_type i = 0; i < virus_point_temp.size(); i++) {
					virus_point.push(virus_point_temp[i]);
				}

				while (!virus_point.empty()) {
					int x = virus_point.front().first;
					int y = virus_point.front().second;

					for (int l = 0; l < 4; l++) {
						int dx = x + check_point[l][0];
						int dy = y + check_point[l][1];

						if(dx>=0 && dx<N && dy>=0 && dy<M)
							if (arr[dx][dy] == 0) {
								virus_point.push(make_pair(dx, dy));
								arr[dx][dy] = 2;
							}
					}

					virus_point.pop();
				}

				int point_temp = 0;

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						if (arr[i][j] == 0) point_temp++;
					}
				}

				if (point_temp > not_spread_best) not_spread_best = point_temp;
				
				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++)
						arr[i][j] = temp_arr[i][j];
				}
			}
	printf("%d\n", not_spread_best);
}