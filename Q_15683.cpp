#include<iostream>
#include<vector>

using namespace std;

int N, M;
int map[8][8];
int dxdy[4][2] = { {1,0}, {-1,0}, {0,1},{0,-1} };
int cctv1[4][4] = { {1,0,0,0},{0,1,0,0} ,{0,0,1,0},{0,0,0,1} };
int cctv2[2][4] = { {1,1,0,0},{0,0,1,1} };
int cctv3[4][4] = { {1,0,1,0},{0,1,1,0},{1,0,0,1},{0,1,0,1} };
int cctv4[4][4] = { {0,1,1,1}, {1,0,1,1},{1,1,0,1},{1,1,1,0} };
int cctv5[1][4] = { {1,1,1,1} };

char cctv_map[8][8];

vector<int>cctv_num;
vector<pair<int, int>>cctv_pos;

int best_sagak = 100000000;
void cal(int cctv_nums, char ccmap[8][8]) {
	if (cctv_nums == cctv_num.size()) {
		int sagak = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				//printf("%c ", ccmap[i][j]);
				if (ccmap[i][j] == '0')
					sagak++;
			}
			//printf("\n");
		}
		//printf("\n");
		if (sagak < best_sagak)best_sagak = sagak;
	}

	else {
		char ccmap_temp[8][8];
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < M; j++) {
				ccmap_temp[i][j] = ccmap[i][j];
			}
		}
		if (cctv_num[cctv_nums] == 1) {
			int cam_pos_x = cctv_pos[cctv_nums].first;
			int cam_pos_y = cctv_pos[cctv_nums].second;
			ccmap[cam_pos_x][cam_pos_y] = 'c1';

			for (int i = 0; i < 4; i++) {
				int dx = 0; int dy = 0;

				for (int j = 0; j < 4; j++) {
					if (cctv1[i][j] == 1) {
						while (cam_pos_x + dx >= 0 && cam_pos_x + dx < N &&
							cam_pos_y + dy >= 0 && cam_pos_y + dy < M) {
							if (map[cam_pos_x + dx][cam_pos_y + dy] == 6)
								break;
							ccmap[cam_pos_x + dx][cam_pos_y + dy] = '#';
							dx += dxdy[j][0];
							dy += dxdy[j][1];
						}
					}
				}

				cal(cctv_nums + 1, ccmap);

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						ccmap[i][j] = ccmap_temp[i][j];
					}
				}
			}
		}

		if (cctv_num[cctv_nums] == 2) {
			int cam_pos_x = cctv_pos[cctv_nums].first;
			int cam_pos_y = cctv_pos[cctv_nums].second;
			ccmap[cam_pos_x][cam_pos_y] = 'c1';

			for (int i = 0; i < 2; i++) {
				for (int j = 0; j < 4; j++) {
					if (cctv2[i][j] == 1) {
						int dx = 0; int dy = 0;
						while (cam_pos_x + dx >= 0 && cam_pos_x + dx < N &&
							cam_pos_y + dy >= 0 && cam_pos_y + dy < M) {
							if (map[cam_pos_x + dx][cam_pos_y + dy] == 6)
								break;
							ccmap[cam_pos_x + dx][cam_pos_y + dy] = '#';
							dx += dxdy[j][0];
							dy += dxdy[j][1];
						}
					}
				}

				cal(cctv_nums + 1, ccmap);

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						ccmap[i][j] = ccmap_temp[i][j];
					}
				}
			}
		}

		if (cctv_num[cctv_nums] == 3) {
			int cam_pos_x = cctv_pos[cctv_nums].first;
			int cam_pos_y = cctv_pos[cctv_nums].second;
			ccmap[cam_pos_x][cam_pos_y] = 'c1';

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (cctv3[i][j] == 1) {
						int dx = 0; int dy = 0;
						while (cam_pos_x + dx >= 0 && cam_pos_x + dx < N &&
							cam_pos_y + dy >= 0 && cam_pos_y + dy < M) {
							if (map[cam_pos_x + dx][cam_pos_y + dy] == 6)
								break;
							ccmap[cam_pos_x + dx][cam_pos_y + dy] = '#';
							dx += dxdy[j][0];
							dy += dxdy[j][1];
						}
					}
				}

				cal(cctv_nums + 1, ccmap);

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						ccmap[i][j] = ccmap_temp[i][j];
					}
				}
			}
		}

		if (cctv_num[cctv_nums] == 4) {
			int cam_pos_x = cctv_pos[cctv_nums].first;
			int cam_pos_y = cctv_pos[cctv_nums].second;
			ccmap[cam_pos_x][cam_pos_y] = 'c1';

			for (int i = 0; i < 4; i++) {
				for (int j = 0; j < 4; j++) {
					if (cctv4[i][j] == 1) {
						int dx = 0; int dy = 0;
						while (cam_pos_x + dx >= 0 && cam_pos_x + dx < N &&
							cam_pos_y + dy >= 0 && cam_pos_y + dy < M) {
							if (map[cam_pos_x + dx][cam_pos_y + dy] == 6)
								break;
							ccmap[cam_pos_x + dx][cam_pos_y + dy] = '#';
							dx += dxdy[j][0];
							dy += dxdy[j][1];
						}
					}
				}

				cal(cctv_nums + 1, ccmap);

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						ccmap[i][j] = ccmap_temp[i][j];
					}
				}
			}
		}

		if (cctv_num[cctv_nums] == 5) {
			int cam_pos_x = cctv_pos[cctv_nums].first;
			int cam_pos_y = cctv_pos[cctv_nums].second;
			ccmap[cam_pos_x][cam_pos_y] = 'c1';

			for (int i = 0; i < 1; i++) {
				for (int j = 0; j < 4; j++) {
					if (cctv5[i][j] == 1) {
						int dx = 0; int dy = 0;
						while (cam_pos_x + dx >= 0 && cam_pos_x + dx < N &&
							cam_pos_y + dy >= 0 && cam_pos_y + dy < M) {
							if (map[cam_pos_x + dx][cam_pos_y + dy] == 6)
								break;
							ccmap[cam_pos_x + dx][cam_pos_y + dy] = '#';
							dx += dxdy[j][0];
							dy += dxdy[j][1];
						}
					}
				}

				cal(cctv_nums + 1, ccmap);

				for (int i = 0; i < N; i++) {
					for (int j = 0; j < M; j++) {
						ccmap[i][j] = ccmap_temp[i][j];
					}
				}
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++) {
			scanf("%d", &map[i][j]);
			cctv_map[i][j] = '0';
			if (map[i][j] >= 1 && map[i][j] < 6) {
				cctv_num.push_back(map[i][j]);
				cctv_pos.push_back(make_pair(i, j));
				cctv_map[i][j] = 'C';
			}
			if (map[i][j] == 6)
				cctv_map[i][j] = 'W';
		}

	cal(0, cctv_map);

	printf("%d\n", best_sagak);
}