#include <fcntl.h>
#include <errno.h>
#include <err.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdio.h>
int fsize(int fd) {
  struct stat stat;
  int res = fstat(fd,&stat);
  return stat.st_size;
}
int printll(char* s) {
  while (*s != '\n' && *s != ',' && *s != '\t') {
    putchar(*s++);
  }
  return 0;
}
unsigned long hash(unsigned char *str) // FIXME: need to take length!
{
  unsigned long hash = 5381;
  int c;
  while ((c = *str++))
  hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
  return hash;
}
void Snippet(char*);
int main(int argc, char *argv[])
{
  if (argc != 2) {
    printf("usage: query <filename>\n");
    return 0;
  }
  Snippet(argv[1]);
  return 0;
}
/*****************************************
Emitting C Generated Code
*******************************************/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
void Snippet(char*  x0) {
  printf("%s\n","Name");
  int32_t x5 = 0;
  int32_t x2 = open("src/data/t.csv",0);
  int32_t x3 = fsize(x2);
  char* x4 = mmap(0, x3, PROT_READ, MAP_FILE | MAP_SHARED, x2, 0);
  for (;;) {
    int32_t x6 = x5;
    char x7 = x4[x6];
    bool x8 = x7 != ',';
    if (!x8) break;
    x5 += 1;
  }
  int32_t x13 = x5;
  x5 += 1;
  int32_t x16 = x5;
  int32_t x17 = 0;
  for (;;) {
    int32_t x18 = x5;
    char x19 = x4[x18];
    bool x20 = x19 != ',';
    if (!x20) break;
    int32_t x22 = x17;
    int32_t x24 = x5;
    int32_t x23 = x22 * 10;
    char x25 = x4[x24];
    char x26 = x25 - '0';
    int32_t x27 = x23 + x26;
    x17 = x27;
    x5 += 1;
  }
  x5 += 1;
  int32_t x33 = x17;
  int32_t x34 = x5;
  for (;;) {
    int32_t x35 = x5;
    char x36 = x4[x35];
    bool x37 = x36 != '\n';
    if (!x37) break;
    x5 += 1;
  }
  int32_t x42 = x5;
  x5 += 1;
  for (;;) {
    int32_t x46 = x5;
    bool x47 = x46 < x3;
    if (!x47) break;
    int32_t x49 = x5;
    for (;;) {
      int32_t x50 = x5;
      char x51 = x4[x50];
      bool x52 = x51 != ',';
      if (!x52) break;
      x5 += 1;
    }
    int32_t x57 = x5;
    x5 += 1;
    int32_t x61 = x5;
    int32_t x62 = 0;
    for (;;) {
      int32_t x63 = x5;
      char x64 = x4[x63];
      bool x65 = x64 != ',';
      if (!x65) break;
      int32_t x67 = x62;
      int32_t x69 = x5;
      int32_t x68 = x67 * 10;
      char x70 = x4[x69];
      char x71 = x70 - '0';
      int32_t x72 = x68 + x71;
      x62 = x72;
      x5 += 1;
    }
    x5 += 1;
    int32_t x78 = x62;
    int32_t x79 = x5;
    for (;;) {
      int32_t x80 = x5;
      char x81 = x4[x80];
      bool x82 = x81 != '\n';
      if (!x82) break;
      x5 += 1;
    }
    int32_t x87 = x5;
    x5 += 1;
    int32_t x88 = x87 - x79;
    bool x92 = x88 == 3;
    bool x107;
    if (x92) {
      int32_t x93 = 0;
      char* x90 = x4+x79;
      for (;;) {
        int32_t x94 = x93;
        bool x95 = x94 < x88;
        char x96 = x90[x94];
        char x97 = "yes"[x94];
        bool x98 = x96 == x97;
        bool x99 = x95 && x98;
        if (!x99) break;
        x93 += 1;
      }
      int32_t x104 = x93;
      bool x105 = x104 == x88;
      x107 = x105;
    } else {
      x107 = false;
    }
    if (x107) {
      char* x60 = x4+x49;
      int32_t x108 = printll(x60);
      printf("%s\n","");
    } else {
    }
  }
}
/*****************************************
End of C Generated Code
*******************************************/