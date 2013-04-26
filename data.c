#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <linux/fs.h>
#include "data.h"
#include "parity.h"

ParityData Data1;
ParityData Data2;
FILE *stream;
char *buff1;
char *buff2;
unsigned long imgSize;
int file1;
int file2;
int file3;

void start(char ** argv);

char* readFile(FILE *stream);
void initStruct(ParityData *temp, char *path);
void setOffSet(ParityData *temp1, ParityData *temp2);
unsigned long calcSize(char * argv);
void openStream(char *argv1,char*argv2,char*argv3);

void openStream(char *argv1,char*argv2,char*argv3){
	
        file1 = open(argv1, O_CREAT|O_TRUNC|O_RDWR, 0666);
        file2 = open(argv2, O_CREAT|O_TRUNC|O_RDWR, 0666);
        file3 = open(argv3, O_CREAT|O_TRUNC|O_RDWR, 0666);

}

void closeStream(int f0,int f1, int f2){

	close(f0);
	close(f1);
	close(f2);	
}

void readIMG(char *argv1, char*argv2)
{ 

     buff1 = (char*)malloc(imgSize);
     buff2 = (char*)malloc(imgSize);
     
     int fd0 = open(argv1, O_RDWR, 0666);
     int fd1 = open(argv2, O_RDWR, 0666);

     read(fd0,buff1,imgSize);
     read(fd1,buff2,imgSize);
     
     close(fd0);
     close(fd1);
     
     
}

unsigned long calcSize(char * argv){
	
	int fd;
	unsigned long numblocks=0;

        fd = open(argv, O_RDONLY);
        ioctl(fd, BLKGETSIZE, &numblocks);
        close(fd);
        
        return (numblocks*512);

		
}

void start(char ** argv){
	
        // argv[0] contains ./Main

        char temp1[8] = "write";
        char temp2[8] = "read";
        
        int result1 = strncmp(temp1,argv[4],10);
        printf("result1: %d\n",result1);
 
        int result2 = strncmp(temp2,argv[4],10);
         printf("result2: %d\n",result2); 
 

        printf("arg0: %s, arg1: %s, arg2: %s,\n arg3: %s, arg4: %s\n",
                argv[0],argv[1],argv[2],argv[3],argv[4]); 

	if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && result1 == 0 )
	{
                printf("entered\n");
		imgSize = calcSize(argv[1]);
		printf("size: %d, File: %s\n",imgSize,argv[1]);
                readIMG(argv[1],argv[2]);
		openStream(argv[1],argv[2],argv[3]);
		parityWrite(file1,file2,file3,buff1,buff2,imgSize);
		closeStream(file1,file2,file3);
		free(buff1);
		free(buff2);
	}
	else if(argv[1] != NULL && argv[2] != NULL && argv[3] != NULL && result2 == 0)
	{        
	        imgSize = calcSize(argv[1]);
	        char *buff = (char*)malloc(imgSize);
	        openStream(argv[1],argv[2],argv[3]);
	        parityRead(file1,file2,file3,buff,imgSize);
	        closeStream(file1,file2,file3);
	        free(buff);
	
	}
	
}

char * readFile(FILE *stream){
    char * line = malloc(100), * linep = line;
    size_t lenmax = 100, len = lenmax;
    int c;
    int curSize = 0;

    if(line == NULL)
        return NULL;

    for(;;) {
        c = fgetc(stream);
        curSize++;

        if(c == EOF)
            break;

        if(--len == 0) {
            len = lenmax;
            char * linen = realloc(linep, lenmax *= 2);

            if(linen == NULL) {
                free(linep);
                return NULL;
            }
            line = linen + (line - linep);
            linep = linen;
        }

    }
    *line = '\0';
    return linep;
}

void initStruct(ParityData *temp, char *path){
	
  stream = popen(path, "r");	
  temp->MSG = readFile(stream);
  temp->SIZE = strlen(temp->MSG);
  pclose(stream);
 
}

void setOffSet(ParityData *temp1, ParityData *temp2) {
	
  if(temp1->SIZE > temp2->SIZE){
	
	temp1->OFFSET = 0;
	temp2->OFFSET = (temp1->SIZE-temp2->SIZE); 
	
  }
  else if(temp1->SIZE < temp2->SIZE) {
  
	temp2->OFFSET = 0;
	temp1->OFFSET = (temp2->SIZE-temp1->SIZE); 
	   
  }
  else{
	  
        temp1->OFFSET = 0;
	temp2->OFFSET = 0; 
  }	  
}

void adjustMSG(ParityData *temp1, ParityData *temp2){
	int Len;
	
	if(temp1->OFFSET > 0){
	 
	 Len = temp1->SIZE + temp1->OFFSET;
        
	}	
	else if(temp2->OFFSET > 0){
	   
	   Len = temp2->SIZE + temp2->OFFSET;
	
	}

}

void addPadding(ParityData *temp, int size) {

     int tempSize;
     char* newMSG=(char*)malloc((size)*sizeof(char));
     
     strcpy(newMSG,temp->MSG);
 
     for(tempSize = 0;tempSize<temp->OFFSET;tempSize++){
	     
         strcat(newMSG,'#');
     
     }

     temp->MSG = newMSG;  
}
