
#include <iostream>
#include <queue>

constexpr auto MAX = 10;

char map[MAX][MAX];
bool visit[MAX][MAX][MAX][MAX];
int n, m;
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, 1, -1 };
int red_x, red_y, blue_x, blue_y;

struct ball {
	int rx, ry, bx, by;
};

void readMap();
int solve();

int main()
{
	readMap();
	std::cout << solve();
}

void readMap() {
	std::cin >> n >> m;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			std::cin >> map[i][j];
			if (map[i][j] == 'R') {
				red_x = i;
				red_y = j;
			}
			else if (map[i][j] == 'B') {
				blue_x = i;
				blue_y = j;
			}
		}
	}
}

int solve() {
	std::queue<ball> que;

	visit[red_x][red_y][blue_x][blue_y] = true;
	que.push({ red_x,red_y,blue_x,blue_y });

	int count = 0;

	while (!que.empty()) {
		int size = que.size();
		while (size--) {
			int orx = que.front().rx;
			int ory = que.front().ry;
			int obx = que.front().bx;
			int oby = que.front().by;
			que.pop();

			if (map[orx][ory] == 'O' && map[obx][oby] != 'O') {
				return count;
			}

			for (int i = 0; i < 4; ++i) {
				int crx = orx;
				int cry = ory;
				int cbx = obx;
				int cby = oby;

				int nrx, nry, nbx, nby;

				while (1) {
					nrx = crx + dx[i];
					nry = cry + dy[i];
					if (map[nrx][nry] == '#' || map[crx][cry] == 'O')
						break;
					crx = nrx;
					cry = nry;
				}

				while (1) {
					nbx = cbx + dx[i];
					nby = cby + dy[i];
					if (map[nbx][nby] == '#' || map[cbx][cby] == 'O')
						break;
					cbx = nbx;
					cby = nby;
				}

				// red 와 blue 가 같은 위치에 있을 경우
				if (crx == cbx && cry == cby) {
					if (map[cbx][cby] == 'O') {
						// 동시에 구멍에 들어간 경우는 fail처리
						continue;
					}
					if (abs(orx - crx) + abs(ory - cry) > abs(obx - cbx) + abs(oby - cby)) {
						// red 가 움직임이 더 클 경우
						crx -= dx[i];
						cry -= dy[i];
					}
					else {
						cbx -= dx[i];
						cby -= dy[i];
					}
				}

				if (visit[crx][cry][cbx][cby] == false) {
					visit[crx][cry][cbx][cby] = true;
					que.push({ crx, cry, cbx, cby });
				}
			}
		}
		if (count == 10) {
			return -1;
		}
		count += 1;
	}
	return -1;
}