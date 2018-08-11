
#include "pathname.h"
#include "directory.h"
#include "inode.h"
#include "diskimg.h"
#include <stdio.h>
#include <string.h>
#include <assert.h>

int pathname_lookup(struct unixfilesystem *fs, const char *pathname) {
  // remove the placeholder implementation and replace with your own
  //fprintf(stderr, "pathname_lookup(path=%s) unimplemented.  Returing -1.\n", pathname);
  struct direntv6 new;
  //directory_findname();
  printf("pathname is : %s",pathname);
  //depending on the pathname, we can have different dirinumber...?
  int dirinumber = -1;
  if(strcmp("/",pathname) == 0){
        dirinumber = 1;
        //printf("they are the same");
  }
  int check_directory = directory_findname(fs,pathname,dirinumber,&new);

  if(check_directory == 0 && strcmp(new.d_name,pathname)){
        return 0;
  }

  return -1;
}
