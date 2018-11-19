#include<iostream>
#include<vector>
#include<deque>

using namespace std;

int where_heading[4][2] = {
	{-1,0},{0,1},{1,0},{0,-1}
};

int visited[101][101] = { 0, };

int main() {
	int N, k, L, time = 0;
	int a, b;
	int X[100]; char C[100];
	int snake_size = 1, snake_heading = 1;
	pair<int, int> tmp;
	bool crash = false;
	deque<pair<int,int>> snake;
	snake.push_back(make_pair(0, 0));
	visited[0][0] = 1;
	scanf("%d", &N);

	vector<vector<int>> arr(N, vector<int>(N, 0));

	scanf("%d", &k);
	for (int i = 0; i < k; i++) {
		scanf("%d %d", &a, &b);
		arr[a - 1][b - 1] = 1;
	}

	scanf("%d", &L);

	for (int i = 0; i < L; i++)
		scanf("%d %c", &X[i], &C[i]);

	while (1) {
		time++;

		int x = snake[0].first + where_heading[snake_heading][0];
		int y = snake[0].second + where_heading[snake_heading][1];
		tmp.first = x; tmp.second = y;

		if (x<0 || x>N - 1 || y<0 || y>N - 1 || visited[x][y] == 1) break;

		snake.push_front(tmp);

		visited[tmp.first][tmp.second] = 1;

		if (arr[tmp.first][tmp.second] == 0) {
			tmp = snake.back();
			snake.pop_back();
			visited[tmp.first][tmp.second] = 0;
		}
		else
			arr[tmp.first][tmp.second] = 0;

		for(int i =0; i< L; i++)
			if (time == X[i]) {
				if (C[i] == 'L') {
					if (snake_heading > 0) snake_heading--;
					else snake_heading = 3;
				}
				
				else if (C[i] == 'D')
					snake_heading = (snake_heading + 1) % 4;
			}
	}

	printf("%d\n", time);
}