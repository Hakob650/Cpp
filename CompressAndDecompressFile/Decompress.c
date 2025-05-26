#include <stdio.h>
#include <stdlib.h>
#include "rle.h"
void Decompress(const char *input,const char *output){
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
    int ch,count;
    while((ch=fgetc(in))!=EOF){
        count=fgetc(in);
        if(count==EOF){
            fprintf(stderr,"Corrupt file: count byte missing for character '%c'\n",ch);
            break;
        }
        for(int i=0;i<count;++i){
                fputc(ch,out);
        }
        fclose(in);
        fclose(out);
        printf("Decompressed successfully");
        }
}
