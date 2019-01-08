#include<iostream>
#include<queue>

using namespace std;

#define MAX 1100000000;

int N;

int calculator[4];
int num[12];

int best_up_num = -MAX;
int best_down_num = MAX;

void cal(int cal_time, int gap, int plus, int minus, int gop, int nanu) {
	if (cal_time == N) {
		if (gap > best_up_num) best_up_num = gap;
		if (gap < best_down_num) best_down_num = gap;
	}

	else {
		if (plus < calculator[0])
			cal(cal_time + 1, gap + num[cal_time],plus + 1, minus, gop, nanu);
		if (minus < calculator[1])
			cal(cal_time + 1, gap - num[cal_time], plus, minus + 1, gop, nanu);
		if (gop < calculator[2])
			cal(cal_time + 1, gap * num[cal_time], plus, minus, gop + 1, nanu);
		if (nanu < calculator[3])
			cal(cal_time + 1, gap / num[cal_time], plus, minus, gop, nanu + 1);

	}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &num[i]);
	}

	for (int i = 0; i < 4; i++) {
		scanf("%d", &calculator[i]);
	}

	cal(1, num[0], 0, 0, 0, 0);
	printf("%d\n%d\n", best_up_num, best_down_num);
}