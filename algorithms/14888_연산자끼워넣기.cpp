
#include <iostream>
#include <vector>

void readDatas();
int calculate(int val1, int val2, int index);
void dfs(int curr, int depth, int reamins[]);

int num;
int min, max;
int values[100];
int cal[4];
bool setted = false;

int main() {
	readDatas();
	dfs(values[0], 1, cal);
	std::cout << max << std::endl;
	std::cout << min << std::endl;
}

void readDatas() {
	std::cin >> num;
	
	for (int i = 0; i < num; ++i) {
		int temp;
		std::cin >> values[i];
	}

	for (int i = 0; i < 4; ++i) {
		int temp;
		std::cin >> temp;
		cal[i] = temp;
	}
}

int calculate(int val1, int val2, int index) {
	int res = 0;
	switch (index) {
	case 0: res = val1 + val2; break;
	case 1: res = val1 - val2; break;
	case 2: res = val1 * val2; break;
	case 3: 
		try {
			res = val1 / val2; break;
			break;
		}
		catch (const char* str) {
			std::cout << str << std::endl;
			res = 1;
			break;
		}
	}
	return res;
}
void dfs(int curr, int depth, int remains[]) {
	if (depth >= num) {
		if (setted == false) {
			min = curr;
			max = curr;
			setted = true;
		}
		if (curr < min) {
			min = curr;
		}
		if (curr > max) {
			max = curr;
		}
		return;
	}

	for (int i = 0; i < 4; ++i) {
		if (remains[i] > 0) {
			int temp[4];
			std::copy(remains, remains + 4, temp);
			temp[i] -= 1;
			dfs(calculate(curr, values[depth], i), depth + 1, temp);
		}
	}
}