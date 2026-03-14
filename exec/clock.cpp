#include <bits/stdc++.h>
using namespace std;

const map<int, string> error{
  {0xC0000005, "access violation"},
  {0xC00000FD, "stack overflow"},
  {0xC0000094, "divide by zero"},
  {0xC0000095, "integer overflow"},
  {0xC0000096, "privileged instruction"},
  {0xC000001D, "illegal instruction"},
  {0xC0000409, "stack buffer overflow"},
  {0x40000015, "assert failed"},
};

int main() {
  double s = clock();
  int val = system("exec\\main < stdin.txt");
  double e = clock();
  printf("\n%.3fs\n", (e - s) / CLOCKS_PER_SEC);
  if(val) {
    printf("returned 0x%X ", val);
    if(error.contains(val)) printf("(%s)", error.at(val).c_str());
  }
}