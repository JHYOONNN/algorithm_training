#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int N,temp=0,longest = 0;
	scanf("%d", &N);
	vector<pair<long long,long long>> a(N);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &a[i].first);
		a[i].second = i;
	}

	sort(a.begin(), a.end());
	for (int i = 0; i < N; i++) {
		if (longest <a[i].second - i) longest = a[i].second - i;
	}
	printf("%d\n", longest +1);
}