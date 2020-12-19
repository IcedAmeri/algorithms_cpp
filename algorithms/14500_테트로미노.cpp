
#include <iostream>
#include <algorithm>

int n, m;
int map[500][500];
bool visit[500][500] = { false };
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int ex[4][3] = { {0, 1, 0}, {1, 0, -1}, {-1, 0, 0}, {1, -1, 0} };
int ey[4][3] = { {-1, 0, 1}, {0, 1, 0}, {0, -1, 1}, {0, 0, -1} };
int result = 0;

void readMap();
void dfs(int x, int y, int sum, int length);
void check_extra(int x, int y);

int main()
{
	readMap();

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			visit[i][j] = true;
			dfs(i, j, map[i][j], 1);
			visit[i][j] = false;
			check_extra(i, j);
		}
	}

	std::cout << result;
}

void readMap() {
	std::cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> map[i][j];
		}
	}
}

void dfs(int x, int y, int sum, int length) {
	if (length >= 4) {
		result = std::max(result, sum);
		return;
	}

	for (int i = 0; i < 4; ++i) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

		if (visit[nx][ny] == false) {
			visit[nx][ny] = true;
			dfs(nx, ny, sum + map[nx][ny], length + 1);
			visit[nx][ny] = false;
		}
	}
}

void check_extra(int x, int y) {
	for (int i = 0; i < 4; ++i) {
		bool isout = false;
		int sum = map[x][y];
		for (int j = 0; j < 3; j++) {
			int nx = x + ex[i][j];
			int ny = y + ey[i][j];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				isout = true;
				break;
			}
			sum += map[nx][ny];
		}
		if (isout == false) {
			result = std::max(sum, result);
		}
	}
}