#include <bits/stdc++.h>

using namespace std;

int arr[101][101] = {0};
int mx[] = {-1, 0, 1, 0};
int my[] = {0, -1, 0, 1};

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  cin >> N >> M;
  for (int i = 0; i < N; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < M; ++j) {
      arr[i][j] = (int)(str[j] - '0');
    }
  }
  queue<pair<int, int>> q;
  q.push({0, 0});
  bool flag = false;
  while (!q.empty()) {
    pair<int, int> Front = q.front();
    q.pop();
    int oldX = Front.second, oldY = Front.first;
    for (int i = 0; i < 4; ++i) {
      int x = oldX, y = oldY;
      x += mx[i];
      y += my[i];
      if (x < 0 || x > M - 1)
        continue;
      if (y < 0 || y > N - 1)
        continue;
      if (x == M - 1 && y == N - 1) {
        flag = true;
        arr[y][x] = arr[oldY][oldX] + 1;
        break;
      }
      if (arr[y][x] == 1) {
        arr[y][x] = arr[oldY][oldX] + 1;
        q.push({y, x});
      }
    }
    if (flag)
      break;
  }
  cout << arr[N - 1][M - 1] << '\n';

  return 0;
}
