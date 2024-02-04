#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
#define INF 1e9
int dp[500][500];

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;
  vector<pair<int, int>> matrices(n);

  for (int i = 0; i < n; i++) {
    int row, col;
    cin >> row >> col;
    matrices[i] = make_pair(row, col);
  }

  for (int i = 0; i < n - 1; i++) {
    for (int j = 0; i + j <= n - 1; j++) {
      dp[j][j + i] = INF;
      for (int k = j; k <= i + j; k++) {
        dp[j][j + i] =
            min(dp[j][j + i], dp[j][k] + dp[k + 1][i + j] +
                                  matrices[j].first * matrices[k].second *
                                      matrices[j + i].second);
      }
    }
  }

  cout << dp[0][n - 1] << endl;
}