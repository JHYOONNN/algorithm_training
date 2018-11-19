#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;

int main() {
	int topni_state[4][8];
	string topni;
	int order_time;
	int point = 0;
	for (int i = 0; i < 4; i++) {
		cin >> topni;
		for (int j = 0; j < 8; j++)
			topni_state[i][j] = topni[j];
	}

	
	scanf("%d", &order_time);
	vector<pair<int, int>> order(order_time);
	for (int i = 0; i < order_time; i++)
		scanf("%d %d", &order[i].first, &order[i].second);

	for (int i = 0; i < order_time; i++) {
		int move_topni[4] = { 0, };

		move_topni[order[i].first - 1] = order[i].second;
		for (int j = order[i].first - 2; j >= 0; j--) {
			if (topni_state[j][2] != topni_state[j + 1][6]) {
				move_topni[j] = -move_topni[j+1];
			}
		}
		for (int j = order[i].first; j < 4; j++) {
			if (topni_state[j][6] != topni_state[j - 1][2]) {
				move_topni[j] = -move_topni[j - 1];
			}
		}
		for (int j = 0; j < 4; j++) {
			int temp;
			if (move_topni[j] == 1) {
				temp = topni_state[j][7];
				for (int k = 7; k > 0; k--) {
					topni_state[j][k] = topni_state[j][k-1];
				}
				topni_state[j][0] = temp;
			}
			else if (move_topni[j] == -1) {
				temp = topni_state[j][0];
				for (int k = 0; k < 7; k++) {
					topni_state[j][k] = topni_state[j][k + 1];
				}
				topni_state[j][7] = temp;
			}
		}
	}
	for (int i = 0; i < 4; i++) {
		if (topni_state[i][0] == '1')
			point += pow(2, i);
	}
	printf("%d\n", point);
}