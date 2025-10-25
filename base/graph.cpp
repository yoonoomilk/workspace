#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<int> raw[100005];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> m;
  while(m--) {
    int a, b; cin >> a >> b;
    raw[a].push_back(b);
    raw[b].push_back(a);
  }


}