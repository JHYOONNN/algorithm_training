#include<iostream>
#include<vector>

using namespace std;

vector<vector<int>> line(30, vector<int>(8, -1));
int N, M, H;
vector<pair<int, int>> choose_node;
vector<pair<int, int>> choose_node2;
vector<pair<int, int>> choose_node3;
void make_node(vector<pair<int,int>> &choosed_node) {
	
	for (int i = 0; i<H; i++)
		for (int j = 0; j < N - 1; j++) {
			if (N - 1 == 1) { if (line[i][j] == 0) choosed_node.push_back(make_pair(i, j)); }
			else {
				if (j == 0) {
					if (line[i][j + 1] == 0 && line[i][j] == 0) { choosed_node.push_back(make_pair(i, j)); }
				}
				else if (j == N - 2) {
					if (line[i][j - 1] == 0 && line[i][j] == 0) choosed_node.push_back(make_pair(i, j));
				}
				else {
					if (line[i][j + 1] == 0 && line[i][j - 1] == 0 && line[i][j] == 0) choosed_node.push_back(make_pair(i, j));
				}
			}
		}
}

bool move_ok() {
	/*for (int i = 0; i < H; i++) {
		for (int j = 0; j < N - 1; j++) printf("%d ", line[i][j]);
		printf("\n");
	}*/
	bool mid = true;
	for (int sero = 0; sero < N; sero++) {
		int start_sero = sero;
		for (int garo = 0; garo < H; garo++) {
			if (sero == 0) {
				if (line[garo][sero] == 1) sero++;
			}
			else if (sero == N - 1) {
				if (line[garo][sero - 1] == 1) sero--;
			}
			else {
				if (line[garo][sero] == 1) sero++;
				else if (line[garo][sero - 1] == 1)sero--;
			}
		}

		if (sero != start_sero) mid = false;
	}
	return mid;
}
int main() {
	int a, b;
	int minimum = 100;

	scanf("%d %d %d", &N, &M, &H);
	
	for (int j = 0; j < H; j++)
		for (int k = 0; k < N - 1; k++)
			line[j][k] = 0;

	for (int i = 0; i < M; i++) {
		scanf("%d %d", &a, &b);
		line[a-1][b-1] = 1;
	}

	bool can_go = move_ok();
	if (can_go == true) minimum = 0;

	if (minimum > 0) {
		make_node(choose_node);
		for (vector<int>::size_type i = 0; i < choose_node.size(); i++) {
			line[choose_node[i].first][choose_node[i].second] = 1;
			bool can_go = move_ok();
			if (can_go == true) minimum = 1;
			line[choose_node[i].first][choose_node[i].second] = 0;
		}
	}
	choose_node.erase(choose_node.begin(), choose_node.end());
	if (minimum > 1) {
		make_node(choose_node);
		for (vector<int>::size_type i = 0; i < choose_node.size(); i++) {
			line[choose_node[i].first][choose_node[i].second] = 1;
			
			for (vector<int>::size_type j = i; j < choose_node.size(); j++) {
				if (choose_node[i].first != choose_node[j].first || abs(choose_node[i].second - choose_node[j].second) > 1) {
					//printf("%d,%d   %d,%d\n", choose_node[i].first, choose_node[i].second, choose_node[j].first, choose_node[j].second);

					line[choose_node[j].first][choose_node[j].second] = 1;
					bool can_go = move_ok();
					line[choose_node[j].first][choose_node[j].second] = 0;
					if (can_go == true) minimum = 2;
				}
			}
			line[choose_node[i].first][choose_node[i].second] = 0;
		}
	}

	choose_node.erase(choose_node.begin(), choose_node.end());
	
	bool breaker = false;
	if (minimum > 2) {
		make_node(choose_node);
		for (vector<int>::size_type i = 0; i < choose_node.size(); i++) {
			line[choose_node[i].first][choose_node[i].second] = 1;
			for (vector<int>::size_type j = i; j < choose_node.size(); j++) {
				if (choose_node[i].first != choose_node[j].first || abs(choose_node[i].second - choose_node[j].second) > 1) {
					line[choose_node[j].first][choose_node[j].second] = 1;
					for (vector<int>::size_type k = j; k < choose_node.size(); k++) {
						if (choose_node[k].first != choose_node[i].first || abs(choose_node[k].second - choose_node[i].second) > 1)
							if (choose_node[k].first != choose_node[j].first || abs(choose_node[k].second - choose_node[j].second) > 1) {
								line[choose_node[k].first][choose_node[k].second] = 1;
								//printf("%d,%d   %d,%d   %d,%d\n", choose_node[i].first, choose_node[i].second, choose_node[j].first, choose_node[j].second, choose_node[k].first, choose_node[k].second);
								bool can_go = move_ok();
								line[choose_node[k].first][choose_node[k].second] = 0;
								if (can_go == true) { minimum = 3; breaker = true; break; }
							}
					}
					if (breaker == true) break;
					line[choose_node[j].first][choose_node[j].second] = 0;
				}
				if (breaker == true) break;
			}
			line[choose_node[i].first][choose_node[i].second] = 0;
		}
		
	}

	if (minimum > 3) minimum = -1;

	printf("%d\n", minimum);
}