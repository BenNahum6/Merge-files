#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxSize 1024

int main(int argc, char *argv[]) {
    FILE *fdA,*fdB,*fdC;

    fdA = fopen(argv[1], "r");
    if (!fdA)
    {
        perror("Unable to open the file.");
        exit(EXIT_FAILURE);
    }

    fdB = fopen(argv[2], "r");
    if (!fdB)
    {
        perror("Unable to open the file.");
        fclose(fdA);
        exit(EXIT_FAILURE);
    }

    fdC = fopen("fileC", "w");//need to check.
    if (!fdC)
    {
        perror("Unable to open the file.");
        fclose(fdA);
        fclose(fdB);
        exit(EXIT_FAILURE);
    }

    char bufA[maxSize], bufB[maxSize];
    int flagA = 0, flagB = 0;
    while (flagA == 0 || flagB == 0){//when flag equal 2 the both file is copy.
        if(fgets(bufA, maxSize, fdA) == NULL){
            flagA=1;
        }
        else{
            fwrite(bufA,1, strlen(bufA),fdC);
            memset(bufA,'\0',maxSize);
        }

        if(fgets(bufB, maxSize, fdB) == NULL){
            flagB = 1;
        }
        else{
            fwrite(bufB,1, strlen(bufB),fdC);
            memset(bufB,'\0',maxSize);
        }

    }
    fclose(fdA);
    fclose(fdB);
    fclose(fdC);
    return 0;
}


