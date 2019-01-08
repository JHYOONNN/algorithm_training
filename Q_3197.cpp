#include <cstdio>

#include <queue>

using namespace std;

int N, M;

char map[1501][1501];

int L[2][2], lcnt = 0;

int dy[4] = { -1, 0, 0, 1 }, dx[4] = { 0, 1, -1, 0 };

int visit[1501][1501] = { 0 };

int water[1501][1501];

void clear(int arr[1501][1501]) {

	for (int n = 0; n < N; n++)

		for (int m = 0; m < M; m++)

			arr[n][m] = 0;

}

int waterbfs() {

	int cnt = 1;

	int ret = 0;

	queue<pair<int, int>> q;


	for (int n = 0; n < N; n++)

		for (int m = 0; m < M; m++)

			if (map[n][m] == '.' || map[n][m] == 'L') {

				visit[n][m] = 1;

				q.push({ n, m });

			}

	while (!q.empty()) {

		int sz = q.size();

		for (int s = 0; s < sz; s++) {

			int y = q.front().first, x = q.front().second;

			q.pop();


			for (int i = 0; i < 4; i++) {

				int ny = y + dy[i], nx = x + dx[i];

				if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx]) continue;

				if (map[ny][nx] != 'L') {

					water[ny][nx] = cnt;

					visit[ny][nx] = 1;

					q.push({ ny, nx });

				}

			}

		}

		cnt++;

	}

	return cnt - 2;

}

bool bfs(int limit) {

	queue<pair<int, int>> q;


	q.push({ L[0][0], L[0][1] });

	visit[L[0][0]][L[0][1]] = 1;


	while (!q.empty()) {

		int y = q.front().first, x = q.front().second;

		q.pop();

		if (y == L[1][0] && x == L[1][1]) return true;

		for (int i = 0; i < 4; i++) {

			int ny = y + dy[i], nx = x + dx[i];

			if (ny < 0 || ny >= N || nx < 0 || nx >= M || visit[ny][nx]) continue;

			if (water[ny][nx] <= limit) {

				q.push({ ny, nx });

				visit[ny][nx] = 1;

			}

		}

	}

	return false;

}

int main() {

	scanf("%d%d", &N, &M);

	for (int n = 0; n < N; n++) {

		for (int m = 0; m < M; m++) {

			scanf(" %1c", &map[n][m]);

			if (map[n][m] == 'L') {

				L[lcnt][0] = n;

				L[lcnt++][1] = m;

			}

		}

	}

	int st = 0, en;

	en = waterbfs();


	while (st <= en) {

		clear(visit);

		int mid = (st + en) / 2;

		if (bfs(mid)) en = mid - 1;

		else st = mid + 1;

	}

	printf("%d\n", st);

	return 0;

}
