#include <bits/stdc++.h>

using namespace std;

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N, M;
  std::string input;
  cin >> N;
  cin >> M;
  cin >> input;
  int count = 0;
  for (int i = 0; i < input.size(); ++i) {
    int len = 0;
    if (input[i] == 'O') {
      continue;
    }
    while (input[i + 1] == 'O' && input[i + 2] == 'I') {
      len++;
      if (len == N) {
        count++;
        len--;
      }
      i += 2;
    }
    len = 0;
  }
  cout << count << '\n';
  return 0;
}
