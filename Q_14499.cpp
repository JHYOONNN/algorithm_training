#include<iostream>
#include<vector>

using namespace std;

int main() {
	int x_size, y_size, order_size;
	int dice_pos[2] = {0,};
	int map_gap[21][21] = { -1, };
	int dice_gap[6] = { 0, };
	int temp = 0;
	scanf("%d %d %d %d %d", &x_size, &y_size, &dice_pos[0], &dice_pos[1], &order_size);

	vector<int> order(order_size);

	for (int i = 0; i < x_size; i++)
		for (int j = 0; j < y_size; j++)
			scanf("%d", &map_gap[i][j]);

	for (int i = 0; i < order_size; i++)
		scanf("%d", &order[i]);

	for (int i = 0; i < order_size; i++) {
		if (order[i] == 1 && dice_pos[1] < y_size-1) {
			temp = dice_gap[0];
			dice_gap[0] = dice_gap[4];
			dice_gap[4] = dice_gap[2];
			dice_gap[2] = dice_gap[5];
			dice_gap[5] = temp;
			dice_pos[1]++;
			if (map_gap[dice_pos[0]][dice_pos[1]] == 0)
				map_gap[dice_pos[0]][dice_pos[1]] = dice_gap[2];
			else {
				dice_gap[2] = map_gap[dice_pos[0]][dice_pos[1]];
				map_gap[dice_pos[0]][dice_pos[1]] = 0;
			}

			printf("%d\n", dice_gap[0]);
		}
		else if (order[i] == 2 && dice_pos[1] > 0) {
			temp = dice_gap[0];
			dice_gap[0] = dice_gap[5];
			dice_gap[5] = dice_gap[2];
			dice_gap[2] = dice_gap[4];
			dice_gap[4] = temp;
			dice_pos[1]--;
			if (map_gap[dice_pos[0]][dice_pos[1]] == 0)
				map_gap[dice_pos[0]][dice_pos[1]] = dice_gap[2];
			else {
				dice_gap[2] = map_gap[dice_pos[0]][dice_pos[1]];
				map_gap[dice_pos[0]][dice_pos[1]] = 0;
			}

			printf("%d\n", dice_gap[0]);
		}
		else if (order[i] == 3 && dice_pos[0] > 0) {
			temp = dice_gap[0];
			dice_gap[0] = dice_gap[1];
			dice_gap[1] = dice_gap[2];
			dice_gap[2] = dice_gap[3];
			dice_gap[3] = temp;
			dice_pos[0]--;
			if (map_gap[dice_pos[0]][dice_pos[1]] == 0)
				map_gap[dice_pos[0]][dice_pos[1]] = dice_gap[2];
			else {
				dice_gap[2] = map_gap[dice_pos[0]][dice_pos[1]];
				map_gap[dice_pos[0]][dice_pos[1]] = 0;
			}

			printf("%d\n", dice_gap[0]);
		}

		else if (order[i] == 4 && dice_pos[0] < x_size-1) {
			temp = dice_gap[0];
			dice_gap[0] = dice_gap[3];
			dice_gap[3] = dice_gap[2];
			dice_gap[2] = dice_gap[1];
			dice_gap[1] = temp;
			dice_pos[0]++;
			if (map_gap[dice_pos[0]][dice_pos[1]] == 0)
				map_gap[dice_pos[0]][dice_pos[1]] = dice_gap[2];
			else {
				dice_gap[2] = map_gap[dice_pos[0]][dice_pos[1]];
				map_gap[dice_pos[0]][dice_pos[1]] = 0;
			}

			printf("%d\n", dice_gap[0]);
		}
	}
}