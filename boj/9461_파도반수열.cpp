#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9
long long dp[101];

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  dp[1] = 1;
  dp[2] = 1;
  dp[3] = 1;
  dp[4] = 2;
  dp[5] = 2;
  for (int i = 5; i <= 100; i++) dp[i] = dp[i - 5] + dp[i - 1];

  int T;
  cin >> T;
  while (T--) {
    int N;
    cin >> N;
    cout << dp[N] << "\n";
  }
}