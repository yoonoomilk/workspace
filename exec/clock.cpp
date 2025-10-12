#include <time.h>
#include <stdlib.h>
#include <stdio.h>

int main() {
  double s = clock();
  int val = system("exec\\main < stdin.txt");
  double e = clock();
  printf("\n%.3fs\n", (e - s) / CLOCKS_PER_SEC);
  if(val != 0) printf("returned 0x%X\n", val);
}
//g++ clock.cpp -o clock -O2