#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using pii = pair<int, int>;

bool is_alpha_lower_or_slash(char c) {
  if('0' <= c && c <= '9') return true;
  if('a' <= c && c <= 'z') return true;
  return c == '/';
}

bool is_hex(char c) {
  if('0' <= c && c <= '9') return true;
  if('a' <= c && c <= 'f') return true;
  if('A' <= c && c <= 'F') return true;
  return false;
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  string s;
  while(getline(cin, s)) {
    bool ans = true;
    int i = 0;
    auto gc = [&]() {
      if(i < s.size()) return s[i++];
      ans = false;
      return '\0';
    };
    stack<string> context;
    while(i < s.size() && ans) {
      char a = gc();
      if(a == '&') {
        string tmp;
        for(char b = gc();b != 0 && b != ';';b = gc()) tmp += b;
        if(tmp == "lt" || tmp == "gt" || tmp == "amp") continue;
        if(tmp.size() > 1 && tmp[0] == 'x' && tmp.size() % 2 == 1) ans &= all_of(tmp.begin() + 1, tmp.end(), is_hex);
        else ans = false;
      } else if(a == '<') {
        string tmp;
        for(char b = gc();b != 0 && b != '>';b = gc()) tmp += b;
        int slash = count(tmp.begin(), tmp.end(), '/');
        if(slash == 0) {
          ans &= tmp.size() >= 1;
          ans &= all_of(tmp.begin(), tmp.end(), is_alpha_lower_or_slash);
          context.push(tmp);
        } else if(slash == 1) {
          ans &= tmp.size() >= 2;
          ans &= all_of(tmp.begin(), tmp.end(), is_alpha_lower_or_slash);
          if(!ans) break;
          int slash_idx = tmp.find('/');
          if(slash_idx == 0) {
            ans &= context.size() && context.top() == tmp.substr(1);
            if(ans) context.pop();
          } else if(slash_idx == tmp.size() - 1) {}
          else ans = false;
        } else ans = false;
      } else ans &= a != '>';
    }
    ans &= context.empty();
    cout << (ans ? "valid\n" : "invalid\n");
  }
}