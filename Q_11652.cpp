#include <iostream>
#include <vector>
#include <algorithm>
#include<math.h>
using namespace std;

int main() {
	int N;
	scanf("%d", &N);
	vector<long long> arr(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &arr[i]);
	}
	sort(arr.begin(), arr.end());

	int freq = 1;
	long long freq_dap = arr[0];
	int freq_temp = 1;

	for (int i = 1; i < N; i++) {
		if (arr[i] == arr[i - 1]) freq_temp++;
		else {
			freq_temp = 1;
		}

		if (freq_temp > freq) {
			freq = freq_temp;
			freq_dap = arr[i];
		}
	}
	printf("%lld\n", freq_dap);
}