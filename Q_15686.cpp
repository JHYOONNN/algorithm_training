#include<iostream>
#include<vector>

using namespace std;
int N, M;
vector<pair<int, int>>home;
vector<pair<int, int>>chicken;

int map[50][50];
int best = 1000000;
int choosed[13];
int cal__ = 0;
void cal(vector<pair<int,int>>choosed_chicken, int before_i) {
	if (choosed_chicken.size() == M) {
		cal__++;
		int chicken_len = 0;
		/*
		for (int i = 0; i < choosed_chicken.size(); i++) {
			printf("choose : %d %d \n", choosed_chicken[i].first, choosed_chicken[i].second);
		}
		printf("done\n");
		*/
		for (int i = 0; i < home.size(); i++) {
			int chi_len = 1000000;
			for (int j = 0; j < choosed_chicken.size(); j++) {
				int chi_len_temp = abs(home[i].first - choosed_chicken[j].first) + abs(home[i].second - choosed_chicken[j].second);
				if (chi_len_temp < chi_len) chi_len = chi_len_temp;
			}
			chicken_len += chi_len;
		}

		if (best > chicken_len) best = chicken_len;
	}

	else {
		for (int i = before_i + 1; i < chicken.size(); i++) {
			if (choosed[i] == 0) {
				choosed[i] = 1;
				choosed_chicken.push_back(chicken[i]);
				cal(choosed_chicken, i);
				choosed_chicken.pop_back();
				choosed[i] = 0;
			}
		}
	}
}

int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &map[i][j]);
			if (map[i][j] == 1) home.push_back(make_pair(i, j));
			else if (map[i][j] == 2) chicken.push_back(make_pair(i, j));
		}
	}
	vector<pair<int,int>> choose_temp;

	cal(choose_temp, -1);
	printf("%d\n", best);
}