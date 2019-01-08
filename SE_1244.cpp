#include<iostream>
#include<vector>
#include<string>
#include<queue>

using namespace std;

int N;
int num, c,length_;
int best = 0;
int checker[1000000][15];

string gap;

bool check(int num, int c_time) {
	if (checker[num][c_time] == 1) return true;
	else return false;
}

void swapping(int a, int b) {
	char temp;
	temp = gap[a];
	gap[a] = gap[b];
	gap[b] = temp;
}


void cal(int count) {
	if (check(stoi(gap), count) == true)return;
	checker[stoi(gap)][count] = 1;
	for (int i = 0; i < length_; i++)
		for (int j = i+1; j < length_; j++) {
			//printf("%d %d %d\n", i, j, length_);
			swapping(i, j);
			if (count == c) {
				if (stoi(gap) > best) best = stoi(gap);
			}
			else {
				cal(count + 1);
			}
			swapping(i, j);
		}
}

int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d %d", &num, &c);
		best = num;
		gap = to_string(num);
		length_ = gap.size();
		
		cal(1);

		printf("#%d %d\n", i + 1, best);
	}
}