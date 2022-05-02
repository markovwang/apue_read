#include "apue.h"
#include <dirent.h>
int main(int argc, char** argv) {
  DIR* dp;
  struct dirent* dirp;
  
  if(argc!=2) {
    err_quit("usage: ls directory_name");
  }
  if((dp = opendir(argv[1])) == NULL) {
    err_sys("can' t open dir: %s",argv[1]);
  }
  while((dirp = readdir(dp))!=NULL) {
    printf("%s\t",dirp->d_name);
    printf("%d\n",dirp->d_type);
  }
  closedir(dp);
  exit(0);
}