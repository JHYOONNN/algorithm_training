#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main() {
	string input, value_type, value_name[200], value_back[200];
	getline(cin, input);

	int type_change = 0;
	int i = 0, j = 0, k = 0;
	while (i != input.length()) {
		if (input[i] == ' ') {
			i++;
			break;
		}
		value_type.push_back(input[i]);
		i++;
	}

	while (i < input.length()) {
		while (i<input.length()) {
			if (input[i] == '*' || input[i] == '[' || input[i] == ']' || input[i] == '&' || input[i] == ',' || input[i] == ';') {
				break;
			}
			value_name[j].push_back(input[i]);
			i++;
		}

		while (i<input.length()) {
			if (input[i] == ',' || input[i] == ';') {
				i += 2;
				j++;
				break;
			}

			value_back[j].push_back(input[i]);
			i++;
		}
	}

	for (int k = 0; k < j; k++) {
		cout << value_type;
		for (int l = value_back[k].length() - 1; l >= 0; l--) {
			if (value_back[k][l] == '[') cout << value_back[k][l + 1];
			else if (value_back[k][l] == ']') cout << value_back[k][l - 1];
			else cout << value_back[k][l];
		}
		cout << ' ' << value_name[k] << ';' << endl;
	}
}