#include <iostream>

int graph[101][101] = {0};
int visit[101] = {0};
int c, res = 0;

void dfs(int x) {
  res++;
  visit[x] = 1;
  for (int i = 1; i <= c; i++)
    if (graph[x][i] && !visit[i]) dfs(i);
}

int main(void) {
  int n, x, y;

  std::cin >> c >> n;
  for (int i = 0; i < n; i++) {
    std::cin >> x >> y;
    graph[x][y] = graph[y][x] = 1;
  }
  dfs(1);
  std::cout << res - 1 << std::endl;
}