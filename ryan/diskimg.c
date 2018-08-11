#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#include <stdio.h>

#include "diskimg.h"

int diskimg_open(char *pathname, int readOnly) {
  return open(pathname, readOnly ? O_RDONLY : O_RDWR);
}

int diskimg_getsize(int fd) {
  return lseek(fd, 0, SEEK_END);
}

int diskimg_readsector(int fd, int sectorNum,  void *buf) {
  if (lseek(fd, sectorNum * DISKIMG_SECTOR_SIZE, SEEK_SET) == (off_t) -1){
      //printf("diskimg_sector_size: %d",DISKIMG_SECTOR_SIZE);
      return -1;  
  }
  //printf("diskimg_sector_size: %d\n",DISKIMG_SECTOR_SIZE);

  return read(fd, buf, DISKIMG_SECTOR_SIZE);
}

int diskimg_writesector(int fd, int sectorNum,  void *buf) {
  if (lseek(fd, sectorNum * DISKIMG_SECTOR_SIZE, SEEK_SET) == (off_t) -1) {
    return -1;
  }

  return write(fd, buf, DISKIMG_SECTOR_SIZE);
}

int diskimg_close(int fd) {
  return close(fd);
}
