#include<iostream>
#include<queue>
#include<string>

using namespace std;

queue<long long>my_q;
queue<string>my_sq;

vector<long long>checker;
string cal_ = "*+-/";

int main() {
	long long s,t;

	scanf("%lld %lld", &s, &t);
	if (s == t)
		printf("0\n");
	else {
		my_q.push(s);
		checker.push_back(s);
		my_sq.push("");
		bool find_ans = false;

		while (!my_q.empty()) {
			long long c = my_q.front();
			string c_s = my_sq.front();

			my_q.pop();
			my_sq.pop();
			if (c == t) {
				cout << c_s<<endl;
				find_ans = true;
				break;
			}

			else if(c != 0){
				long long temp = 0;
				bool check[4] = { false,false,false,false };
				long long d[4] = { 0,0,0,0 };
				d[0] = c * c;
				d[1] = c + c;
				d[2] = c - c;
				d[3] = c / c;

				for (int i = 0; i < checker.size(); i++) {
					if (checker[i] == d[0]) check[0] = true;
					if (checker[i] == d[1]) check[1] = true;
					if (checker[i] == d[2]) check[2] = true;
					if (checker[i] == d[3]) check[3] = true;
				}

				for (int i = 0; i < 4; i++) {
					if (check[i] == false) {
						string c_s_ = c_s + cal_[i];
						my_q.push(d[i]);
						checker.push_back(d[i]);
						my_sq.push(c_s_);
					}
				}
			}
		}

		if (find_ans == false)
			printf("-1\n");
	}
}