#include<iostream>
#include<algorithm>
#include<vector>

using namespace std;

int main() {
	int N, K;
	scanf("%d %d", &N, &K);
	vector<long long> arr(N);

	for (int i = 0; i < N; i++)
		scanf("%lld", &arr[i]);

	nth_element(arr.begin(), arr.begin()+K-1, arr.end());

	printf("%lld\n", arr[K - 1]);
}