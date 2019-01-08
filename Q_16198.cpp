#include<iostream>
#include<vector>

using namespace std;

int point_temp = 0;
int final_point = 0;
int cal_time = 0;

void cal_point(vector<int> arr,int arr_size) {
	if (cal_time < arr_size - 2) {
		cal_time++;
		
		for (int i = 1; i < arr.size() - 1; i++) {
			int add_point = arr[i - 1] * arr[i + 1];
			point_temp += add_point;
			
			int pop_temp = arr[i];
			for (int j = i; j < arr.size()-1; j++)
				arr[j] = arr[j + 1];
			arr.pop_back();
			cal_point(arr, arr_size);
			point_temp -= add_point;
			arr.push_back(arr[arr.size() - 1]);
			for (int j = arr.size() - 2; j > i; j--)
				arr[j] = arr[j - 1];
			arr[i] = pop_temp;
			
		}
		cal_time--;
	}

	else {
		if (point_temp > final_point)
			final_point = point_temp;
	}
}
int main() {
	int n;
	scanf("%d", &n);
	vector<int> w_arr(n);
	for (int i = 0; i < n; i++)
		scanf("%d", &w_arr[i]);
	
	cal_point(w_arr,w_arr.size());
	printf("%d\n",final_point);
}