#include <bits/stdc++.h>
using namespace std;

int solution() {
  int n;
  std::map<string, vector<string>> clothes;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    string cloth, category;
    cin >> cloth >> category;
    clothes[category].push_back(cloth);
  }
  int count = 1;
  for (auto ele : clothes) {
    count *= ele.second.size() + 1;
  }
  return count - 1;
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int v = solution();
    cout << v << '\n';
  }
  return 0;
}
