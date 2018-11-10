#include<iostream>
#include<vector>

using namespace std;

int main() {
	int N,temp;
	vector<int>arr(10001);
	fill(arr.begin(), arr.end(), 0);
	scanf("%d", &N);
	
	for (int i = 0; i < N; i++) {
		scanf("%d", &temp);
		arr[temp] += 1;
	}

	for(int i = 0; i<=10000; i++)
		if (arr[i] != 0) {
			while (arr[i] > 0) {
				printf("%d\n", i);
				arr[i]--;
			}
		}
}