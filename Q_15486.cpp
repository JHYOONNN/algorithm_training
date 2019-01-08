#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int N;

int b_p_arr[1500001];
int p[1500001];
int t[1500001];

int cal(int d) {
	if (d > N)
		return 0;

	if (b_p_arr[d] != -1)
		return b_p_arr[d];

	b_p_arr[d] = 0;

	if (d + 1 <= N + 1)
		b_p_arr[d] = cal(d + 1);

	if (d + t[d] <= N + 1) {
		b_p_arr[d] = max(b_p_arr[d], p[d] + cal(d + t[d]));
	}
		
	return b_p_arr[d];
}

int main() {
	scanf("%d", &N);

	for (int i = 1; i <= N; i++) {
		scanf("%d %d", &t[i], &p[i]);
	}

	for (int i = 1; i <= 1500001; i++)
		b_p_arr[i] = -1;

	cout << cal(1) << endl;
	return 0;
}