#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

size_t parityWrite(
        int fd0, int fd1, int fd2,
        const void *buf0, const void *buf1,
        size_t count) {
        
        int i;
        for(i = 0; i < count; i++) {
                char byte0 = ((char*)buf0)[i];
                char byte1 = ((char*)buf1)[i];
                char parity = byte0 ^ byte1;
                write(fd0, &byte0, sizeof(char));
                write(fd1, &byte1, sizeof(char));
                write(fd2, &parity, sizeof(char));
        }
        return count;
}

size_t parityRead(int fd0, int fd1, int fd2, void *buf, size_t count) {
        char *buff0 = (char*)malloc(count);
        char *buff1 = (char*)malloc(count);
        char *buff = (char*)buf;
        read(fd0, buff0, count);
        read(fd1, buff1, count);
        int i;
        
        for(i = 0; i < count; i++) {
                buff[i] = buff0[i] ^ buff1[i];
        }
        
        write(fd2,buff,count);
        
        
        return count;
}
