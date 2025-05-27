#include <stdio.h>
#include <stdlib.h>
#include "rle.h"
void Compress(const char *input,const char *output){
    FILE *in=fopen(input,"r");
    if(!in){
        printf("Failed to open the file");
        return;
    }
    FILE *out=fopen(output,"w");
    if(!out){
        printf("Failed to open the file");
        fclose(in);
        return;
    }
    int curr=fgetc(in);
    while(curr!=EOF){
        int count=1;
        int nextchar;
        while((nextchar=fgetc(in))==curr && count<256){
                count++;
        }
        fprintf (out,"%c%d",curr,count);
        curr=nextchar;
    }
    fclose(in);
    fclose(out);

    printf("Compressed successfully");
}
