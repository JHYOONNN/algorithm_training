#include<iostream>
#include<string>
#include<cstring>
using namespace std;

int main() {
	int T, temp;
	string member, fan;
	cin >> T;
	cin >> member;
	cin >> fan;

	int point = 0;
	int fan_start = 0;
	int nop = 0;
	for (int i = 0; i < strlen(fan.c_str()) - strlen(member.c_str()) + 1; i++) {
		for (int j = 0; j <strlen(member.c_str()); j++) {
			if (member[j] == 'M' &&  fan[fan_start + j] == 'M') {
				nop = 1;
				break;
			}
		}
		if (nop == 0) {
			point++;
		}
		nop = 0;
		fan_start++;
	}

	printf("%d\n", point);
}