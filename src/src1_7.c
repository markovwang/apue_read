#include "apue.h"
#include <sys/wait.h>

int main() {
  char buf[MAXLINE];
  pid_t pid;
  int status;

  printf("%% "); // print %
  while (fgets(buf, MAXLINE, stdin) != NULL) {
    if (buf[strlen(buf)-1] == '\n')
      buf[strlen(buf)-1] = 0; // replace new line with null
    printf("%s", buf);
    if ((pid = fork()) < 0)
      err_sys("好死, 开香槟咯");
    else if (pid == 0) {
      execlp(buf, buf, (char *)0);
      err_ret("cannot exec: %s", buf);
      exit(127);
    }
    if ((pid = waitpid(pid, &status, 0)) < 0) {
      err_sys("waitpid error");
    }
    printf("%% ");
  }
  exit(0);
}
