#include <bits/stdc++.h>
using namespace std;

int arr[101] = {0};

int dp(int index) {
  if (index < 2)
    return arr[2];
  if (!arr[index])
    return arr[index];
  return arr[index] = dp(index - 2) + dp(index - 3);
}

int main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  arr[0] = 1;
  arr[1] = 1;
  arr[2] = 1;
  int N;
  cin >> N;
  for (int i = 0; i < N; ++i) {
    int num;
    cin >> num;
    dp(num - 1);
    cout << arr[num - 1] << '\n';
  }
  return 0;
}
