#include<iostream>

using namespace std;

int work[15][2];
int N;
int best_money = 0;
int day_best[15];

int dp(int day) {
	if (day == N - 1) {
		if (work[day][0] == 1) {
			return work[day][1];
		}
		
		return 0;
	}

	else if (day == N) {
		return 0;
	}

	else {
		if (day_best[day] != 0) {
			return day_best[day];
		}
		else {
			int ps_1day = dp(day + 1);
			if (day + work[day][0] > N) {
				day_best[day] = ps_1day;
				return ps_1day;
			}

			else {
				
				int wk_day = work[day][1] + dp(day + work[day][0]);
				if (ps_1day < wk_day) {
					day_best[day] = wk_day;
					return wk_day;
				}
				else {
					day_best[day] = ps_1day;
					return ps_1day;
				}
			}
		}
	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &work[i][0], &work[i][1]);
	}

	int gap = dp(0);
	printf("%d\n", gap);
}