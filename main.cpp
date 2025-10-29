#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

int n, q;
string arr[2];

bool hmm(int x, int y) {
  return x >= 0 && x < 2 && y >= 0 && y < n && arr[x][y] == '.';
}

bool yap(int x, int y) {
  if(!hmm(x, y - 1) && !hmm(x, y + 1) && !hmm(x ^ 1, y)) return false;
  for(auto [xx, yy] : vector<pii>{{x, y - 1}, {x, y + 1}, {x ^ 1, y}}) if(hmm(xx, yy)) {
    bool flag = true;
    for(auto [xxx, yyy] : vector<pii>{{xx, yy - 1}, {xx, yy + 1}, {xx ^ 1, yy}}) {
      if(xxx == x && yyy == y) continue;
      flag &= !hmm(xxx, yyy);
    }
    if(flag) return true;
  }
  for(int i : {-1, 1}) {
    if(hmm(x, y + i) && hmm(x, y + i + i)) return true;
    if(hmm(x, y + i) && hmm(x ^ 1, y + i) && (hmm(x ^ 1, y + i - 1) || hmm(x ^ 1, y + i + 1))) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  cin >> n >> q >> arr[0] >> arr[1];
  while(q--) {
    int a, b, c; cin >> a >> b >> c;
    if(a == 1) arr[b - 1][c - 1] ^= '.' ^ '#';
    else cout << (yap(b - 1, c - 1) ? "Kaorin\n" : "Turtle\n");
  }
}