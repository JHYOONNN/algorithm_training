#include<stdio.h>
#include<math.h>

#define MAX_NUM 3;

int cal(int N, int arr[][10]) {
	int peopleNum = 0, starr[3][4], wh_people[11][4], temp = 0, time_count = 1000;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (arr[i][j] == 1) {
				wh_people[peopleNum][0] = i;
				wh_people[peopleNum][1] = j;
				peopleNum++;
			}
			if (arr[i][j] > 1) {
				starr[temp][0] = i;
				starr[temp][1] = j;
				starr[temp][2] = arr[i][j];
				temp++;
			}
		}
	}
	int pow_gap = pow(2, peopleNum);
	for (int i = 0; i<pow_gap; i++) {
		int temp2 = pow(2, peopleNum);
		for (int j = 0; temp2 >= 2; j++) {
			temp2 /= 2;
			if ((i & temp2) != 0) wh_people[j][3] = 0;
			else wh_people[j][3] = 1;
		}

		int wasting_time[10] = { 0, };
		for (int j = 0; j < peopleNum; j++) {
			wasting_time[j] = abs(wh_people[j][0] - starr[wh_people[j][3]][0]) + abs(wh_people[j][1] - starr[wh_people[j][3]][1]);
			printf(" (%d ,%d) to (%d, %d):%d  ", wh_people[j][0],wh_people[j][1], starr[wh_people[j][3]][0], starr[wh_people[j][3]][1], wasting_time[j]);
		}
		printf("\n");
		int remain_people = peopleNum;
		int time_count_temp = 0;
		int done[10] = { 0, };
		int waiting_people[2] = { 0, };
		int already_wait[10] = { 0, };
		while (remain_people > 0) {
			time_count_temp++;
			for (int j = 0; j < peopleNum; j++) {
				if (wasting_time[j] > 0) wasting_time[j] -= 1;
			}

			for (int j = 0; j < peopleNum; j++) {
				if (wasting_time[j] == 0) {
					if (done[j] == 1) {
						remain_people--;
						waiting_people[wh_people[j][3]]--;
						done[j] = 2;
					}
				}
			}
			for (int j = 0; j < peopleNum; j++) {
				if (wasting_time[j] == 0) {
					if (done[j] == 0) {
						if (waiting_people[wh_people[j][3]] < 3) {
							waiting_people[wh_people[j][3]] ++;
							printf("¿þÀÌÆÃ : %d    ", waiting_people[wh_people[j][3]]);
							if(already_wait[j] == 0) wasting_time[j] += (starr[wh_people[j][3]][2] + 1);
							else wasting_time[j] += (starr[wh_people[j][3]][2]);
							done[j] = 1;
						}
						else already_wait[j] = 1;
					}
				}
				printf("%d    ", wasting_time[j]);
			}
			printf("\n");
			printf("remain people : %d\n", remain_people);
		}
		printf("%d\n\n", time_count_temp);
		if (time_count > time_count_temp) time_count = time_count_temp;
	}
	return time_count;
}
int main() {
	int T, N, arr[10][10] = {-1,};
	scanf("%d", &T);
	for (int i = 0; i < T; i++) {
		scanf("%d", &N);
		for (int j = 0; j < N; j++) {
			for (int k = 0; k < N; k++) {
				scanf("%d", &arr[j][k]);
			}
		}

		printf("%d", cal(N, arr));
	}
	scanf("%d", &T);
}