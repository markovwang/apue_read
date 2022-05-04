#include "apue.h"

int main(void) {
  int c;
  while((c = getc(stdin))!=EOF) {
    printf(" ascii %d char printed\n",c);
    if(putc(c,stdout) == NULL)
      err_sys("output error");
  }
  if(ferror(stdin))
    err_sys("input error");
}
