#include <memory.h>

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
vector<pair<int, int>> nodes[1001];
bool visited[1001];
int endPoint;
int endSum;

void dfs(int idx, int sum) {
  if (sum >= endSum) {
    endSum = sum;
    endPoint = idx;
  }

  for (auto nodePair : nodes[idx]) {
    int next = nodePair.first;
    int weight = nodePair.second;
    if (!visited[next]) {
      visited[next] = true;
      dfs(next, sum + weight);
      visited[next] = false;
    }
  }
}

int main(int argc, char** argv) {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n - 1; i++) {
    int a, b, c;
    cin >> a >> b >> c;
    nodes[a].push_back({b, c});
    nodes[b].push_back({a, c});
  }

  // find end point
  visited[1] = true;
  dfs(1, 0);
  visited[1] = false;

  visited[endPoint] = true;
  endSum = 0;
  dfs(endPoint, 0);

  cout << endSum << endl;
}