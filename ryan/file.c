#include <stdio.h>
#include <assert.h>

#include "file.h"
#include "inode.h"
#include "diskimg.h"

// remove the placeholder implementation and replace with your own
int file_getblock(struct unixfilesystem *fs, int inumber, int blockNum, void *buf) {

    struct inode temp;
    if(inumber >= fs->superblock.s_isize) return -1;
    int inode_test = inode_iget(fs, inumber, &temp);

    if(inode_test == 0){
        
        int disk_block_num = inode_indexlookup(fs, &temp, blockNum);
        //printf("This is disk_block_num : %d", disk_block_num);
        if(disk_block_num != -1){

            int random = diskimg_readsector(fs->dfd, disk_block_num, buf);
            struct inode array[DISKIMG_SECTOR_SIZE/sizeof(struct inode)];
            //(char*)array = (char*)buf;
            char *buffer = buf;
            //printf("buffer : %s\n\n", buffer);
            return random;
        }
    }
    return -1;
}
