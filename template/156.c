char *rbuf, *rp;

char rc() {
  if(rp == rbuf + (1 << 16)) read(0, rp = rbuf, 1 << 16);
  return *rp++;
}

int readInt() {
  int tmp = 0;
  for(char c = rc();c & 16;c = rc()) tmp = tmp * 10 + (c & 15);
  return tmp; 
}

__libc_start_main() {
  char buf[1 << 16], w = 0;
  rbuf = buf, rp = buf + (1 << 16);

  int ans;

  do buf[9 - ++w] = ans % 10 + 48;
  while(ans /= 10);
  write(1, buf + 9 - w, w);

  _Exit(0);
} main;