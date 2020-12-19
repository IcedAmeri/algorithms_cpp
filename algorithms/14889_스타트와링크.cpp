
#include <iostream>

void readData();
void solve(int count, int index);

int n;
int map[20][20];
bool visited[20] = { false };
int ans = 123456789;


int main()
{
	readData();
	solve(0, 0);
	std::cout << ans;
}

void readData() {
	std::cin >> n;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			std::cin >> map[i][j];
		}
	}
}

void solve(int count, int index) {
	if (count >= n / 2) {
		int teamA = 0;
		int teamB = 0;
		for (int i = 0; i < n; ++i) {
			for (int j = i+1; j < n; ++j) {
				if (visited[i] && visited[j]) {
					teamA += map[i][j];
					teamA += map[j][i];
				}
				else if (!visited[i] && !visited[j]) {
					teamB += map[i][j];
					teamB += map[j][i];
				}
			}
		}
		ans = std::min(ans, std::abs(teamA - teamB));
		return;
	}

	for (int i = index; i < n; i++) {
		if (visited[i] == false) {
			visited[i] = true;
			solve(count + 1, i);
			visited[i] = false;
		}
	}
}