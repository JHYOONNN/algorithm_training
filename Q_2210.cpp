#include<iostream>
#include<vector>
#include<cmath>

using namespace std;
int can_move[4][2] = { {-1,0},{1,0},{0,1},{0,-1} };
vector<pair<int, int>> choosed_pos;
vector<vector<int>> arr(5, vector<int>(5));
vector<vector<int>> point_arr;
int final_point = 0;


void cal_choosed_pos(int pos_x, int pos_y, int time) {
	time++;
	choosed_pos.push_back(make_pair(pos_x, pos_y));
	int dx, dy;
	vector<int> pos_point(6);
	int point_temp;
	bool point_overlap = false;
	if (time < 6) {
		for (int i = 0; i < 4; i++) {
			dx = pos_x + can_move[i][0];
			dy = pos_y + can_move[i][1];
			if (dx >= 0 && dx < 5 && dy >= 0 && dy < 5) {
				cal_choosed_pos(dx, dy, time);
			}
		}
	}
	else if (time == 6) {
		for (vector<int>::size_type i = 0; i < choosed_pos.size(); i++) {
			pos_point[i] = arr[choosed_pos[i].first][choosed_pos[i].second];
			//printf("%d, %d  ", choosed_pos[i].first, choosed_pos[i].second);
		}
		//printf("\n");

		for (vector<int>::size_type i = 0; i < point_arr.size(); i++) {
			bool point_overlap_temp = true;
			for (int j = 0; j < 6; j++) {
				if (pos_point[j] != point_arr[i][j]) point_overlap_temp = false;
			}
			if (point_overlap_temp == true) { point_overlap = true; break; }
		}
		if (point_overlap == false) { 
			final_point++; 
			point_arr.push_back(pos_point);
		}
	}

	choosed_pos.pop_back();
}
int main() {
	int pos[2];
	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++)
			scanf("%d", &arr[i][j]);

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {
			pos[0] = i; pos[1] = j;
			cal_choosed_pos(pos[0], pos[1], 0);
		}
	
		

	printf("%d\n", final_point);
}