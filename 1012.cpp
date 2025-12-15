#include <bits/stdc++.h>

using namespace std;

int mx[] = {0, -1, 0, 1};
int my[] = {1, 0, -1, 0};
int N, M, K;

int bfs(vector<vector<int>> &arr, pair<int, int> p,
        vector<vector<bool>> &visited) {
  int y = p.first, x = p.second;
  if (visited[y][x]) {
    return 0;
  }
  queue<pair<int, int>> q;
  q.push({y, x});
  visited[y][x] = true;
  while (!q.empty()) {
    pair<int, int> now = q.front();
    q.pop();
    int ny = now.first, nx = now.second;
    for (int i = 0; i < 4; ++i) {
      int newX = nx + mx[i];
      int newY = ny + my[i];
      if (newX < 0 || newX >= N) {
        continue;
      }
      if (newY < 0 || newY >= M) {
        continue;
      }
      if (visited[newY][newX]) {
        continue;
      }
      if (!arr[newY][newX]) {
        continue;
      }
      q.push({newY, newX});
      visited[newY][newX] = true;
    }
  }
  return 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int T = 0;
  cin >> T;
  for (int i = 0; i < T; ++i) {
    vector<vector<int>> arr;
    vector<pair<int, int>> vegetable;
    vector<vector<bool>> visited;
    cin >> N >> M >> K;
    vegetable.resize(K);
    arr.assign(M, vector<int>(N, 0));
    visited.assign(M, vector<bool>(N, false));
    for (int i = 0; i < K; ++i) {
      int x, y;
      cin >> x >> y;
      arr[y][x] = 1;
      vegetable[i] = {y, x};
    }
    int count = 0;
    for (int j = 0; j < K; ++j) {
      count += bfs(arr, vegetable[j], visited);
    }
    cout << count << '\n';
  }
  return 0;
}
