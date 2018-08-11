#include <stdio.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

#include "inode.h"
#include "diskimg.h"

int inode_iget(struct unixfilesystem *fs, int inumber, struct inode *inp) {

    println("this is fd from fs : %d",fs->dfd);
    /*
    struct inode array[DISKIMG_SECTOR_SIZE/sizeof(struct inode)];
    int count = 0;
    while(inumber > (int)(DISKIMG_SECTOR_SIZE/sizeof(struct inode))){
        inumber -= (int)DISKIMG_SECTOR_SIZE/sizeof(struct inode);
        count++;
    }
    int num_count = diskimg_readsector(fs->dfd, count+2, array);
    *inp = array[inumber-1];
    if(num_count < 0) return -1;
    */
    return 0;

}

// remove the placeholder implementation and replace with your own
int inode_indexlookup(struct unixfilesystem *fs, struct inode *inp, int blockNum) {
    
    if((inp->i_mode & ILARG) == 0){
        if(blockNum < 8){
            int actual_number = inp->i_addr[blockNum];
            return actual_number;
        }
        return -1;
    }
    return -1;
}

int inode_getsize(struct inode *inp) {
  return ((inp->i_size0 << 16) | inp->i_size1); 
}
