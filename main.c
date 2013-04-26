
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fs.h>
#include "data.h"
#include "parity.h"



int main(int argc, char ** argv)
{
  
    /*
   
   //char *temp = "dev/loop0";

  int fd;
  unsigned long numblocks=0;

  fd = open(argv[0], O_RDONLY);
  ioctl(fd, BLKGETSIZE, &numblocks);
  close(fd);
  printf("Number of blocks: %lu, this makes %.3f GB\n",
	 numblocks, 
	 (double)numblocks * 512.0 / (1024 * 1024 * 1024));
    
   
   if(argv[1] == NULL)
   {
	printf("null\n");   
   }   
   else
   {
        printf("not null%s\n",argv[1]);
    
   }  
   */
   
   start(argv);
   
   return 0;

}

