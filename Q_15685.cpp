#include<iostream>
#include<vector>
using namespace std;

int N;
int map[101][101];
int dxdy[4][2] = { {0,1},{-1,0},{0,-1},{1,0} };

int count_ = 0;

pair<int,int> move_dot(int start_x, int start_y, int pos_x, int pos_y) {
	int dx = pos_x - start_x;
	int dy = pos_y - start_y;

	return make_pair(start_x + dy, start_y - dx);
}

int main() {
	scanf("%d", &N);

	for (int i = 0; i < N; i++) {
		int dragon[4];
		scanf("%d %d %d %d",&dragon[1], &dragon[0], &dragon[2], &dragon[3]);
		vector<pair<int, int>>dra;
		map[dragon[0]][dragon[1]] = 1;
		dra.push_back(make_pair(dragon[0], dragon[1]));
		dra.push_back(make_pair(dragon[0] + dxdy[dragon[2]][0], dragon[1] + dxdy[dragon[2]][1]));
		if (dragon[3] != 0) {
			pair<int, int>final_p = move_dot(dra[1].first, dra[1].second, dra[0].first, dra[0].second);
			dra.push_back(final_p);
			for (int j = 0; j < dragon[3] -1 ; j++) {
				int dra_size = dra.size();
				for (int k = 0; k < dra_size; k++) {
					dra.push_back(move_dot(final_p.first, final_p.second, dra[k].first, dra[k].second));
					}
				final_p = move_dot(final_p.first, final_p.second, dra[0].first, dra[0].second);
			}
		}
		for (int j = 0; j < dra.size(); j++) {
			map[dra[j].first][dra[j].second] = 1;
		}
	}

	for (int i = 0; i < 100; i++) {
		for (int j = 0; j < 100; j++) {
			if (map[i][j] == 1 && map[i + 1][j] == 1 && map[i][j + 1] == 1 && map[i + 1][j + 1] == 1)
				count_++;
		}
		
	}
	printf("%d\n",count_);
}