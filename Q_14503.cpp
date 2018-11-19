#include<iostream>
#include<vector>

using namespace std;
int where_heading[4][2] = {
	{-1,0},{0,1},{1,0},{0,-1}
};

int main() {
	int size[2], pos_dir[3], clear = 1;
	scanf("%d %d", &size[0], &size[1]);
	vector<vector<int>> clean_map(size[0], vector<int>(size[1]));
	scanf("%d %d %d", &pos_dir[0], &pos_dir[1], &pos_dir[2]);
	
	for (int i = 0; i < size[0]; i++)
		for (int j = 0; j < size[1]; j++)
			scanf("%d", &clean_map[i][j]);

	clean_map[pos_dir[0]][pos_dir[1]] = 2;
	bool has_go = true;
	while (1) {
		for (int i = 0; i < 4; i++) {
			if (pos_dir[2] != 0)pos_dir[2] -= 1;
			else pos_dir[2] = 3;

			if (clean_map[pos_dir[0] + where_heading[pos_dir[2]][0]][pos_dir[1] + where_heading[pos_dir[2]][1]] == 0) {
				pos_dir[0] += where_heading[pos_dir[2]][0];
				pos_dir[1] += where_heading[pos_dir[2]][1];
				clear++;
				clean_map[pos_dir[0]][pos_dir[1]] = 2;
				break;
			}

			if (i == 3) {
				if (clean_map[pos_dir[0] + where_heading[(pos_dir[2] + 2) % 4][0]][pos_dir[1] + where_heading[(pos_dir[2] + 2) % 4][1]] == 1)
					has_go = false;
				else {
					pos_dir[0] += where_heading[(pos_dir[2] + 2) % 4][0];
					pos_dir[1] += where_heading[(pos_dir[2] + 2) % 4][1];
				}
			}
		}

		if (has_go == false) break;
	}

	printf("%d\n", clear);
}