#ifndef PARITY_H_INCLUDED
#define PARITY_H_INCLUDED

size_t parityWrite(
        int fd0, int fd1, int fd2,
        const void *buf0, const void *buf1,
        size_t count);
        

size_t parityRead(int fd0, int fd1, int fd2, void *buf, size_t count);


#endif // PARITY_H_INCLUDED