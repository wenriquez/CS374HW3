
#ifndef DATA_H_INCLUDED
#define DATA_H_INCLUDED

typedef struct

        {
                int OFFSET;

                int SIZE;

                char* MSG;

        } ParityData;


extern ParityData Data1;
extern ParityData Data2;
extern  char *buff1;
extern  char *buff2;
extern unsigned long imgSize;

void start(char ** argv);

char* readFile(FILE *stream);
void initStruct(ParityData *temp, char *path);
void setOffSet(ParityData *temp1, ParityData *temp2);

#endif // DATA_H_INCLUDED
