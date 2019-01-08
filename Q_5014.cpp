#include<iostream>
#include<vector>
#include<queue>

using namespace std;

queue<pair<int,int>> my_q;

int check[1000001] = { 0 };

int main() {
	int F, S, G, U, D;
	bool get_ans = false;
	scanf("%d", &F);
	scanf("%d", &S);
	scanf("%d", &G);
	scanf("%d", &U);
	scanf("%d", &D);

	int stair = S;
	D = -D;

	my_q.push(make_pair(S, 0));
	check[S] = 1;

	if (S + U <= F) {
		my_q.push(make_pair(S + U, 1));
		check[S + U] = 1;
	}

	if (S + D >= 0) {
		my_q.push(make_pair(S + D, 1));
		check[S + D] = 1;
	}

	while (my_q.size() > 0) {
		if (my_q.front().first == G) {
			printf("%d\n", my_q.front().second);
			get_ans = true;
			break;
		}

		else {
			int cur_stair = my_q.front().first;
			int cur_mov = my_q.front().second;
			int move_stair1 = cur_stair + U;
			int move_stair2 = cur_stair + D;
			bool in_queue1 = false;
			bool in_queue2 = false;
			
			if (move_stair1 <= F && check[move_stair1] == 0) {
				if (in_queue1 == false) {
					my_q.push(make_pair(move_stair1, cur_mov + 1));
					check[move_stair1] = 1;
				}
			}

			if (move_stair2 >= 0 && check[move_stair2] == 0) {
				if (in_queue2 == false) {
					my_q.push(make_pair(move_stair2, cur_mov + 1));
					check[move_stair2] = 1;
				}
			}
		}

		my_q.pop();
	}

	if (get_ans == false)
		printf("use the stairs\n");
	return 0;
}