#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {
    FILE* input = fopen(argv[1], "rb");
    int p = atoi(argv[2]);
    int q = atoi(argv[3]);
  
    unsigned char* preberiNajprej = calloc(1000000, sizeof(unsigned char));
    int stPrebranih = fread(preberiNajprej, sizeof(unsigned char), 1000000, input);    
    int* tabelaBitov = calloc(stPrebranih * 8, sizeof(int));

    int currBajt = 0;
    int currBit = 0;

    while (currBit < stPrebranih * 8) {
        unsigned char maska = 0x80;
        
        for(int i = 0; i < 8; i++) {
            tabelaBitov[currBit] = ((preberiNajprej[currBajt] & maska) != 0 ? 1 : 0);
            currBit++;
            maska >>= 1;
            
        }

        currBajt++;
    }

    for (int i = p; i < q; i++) {
        printf("%d", tabelaBitov[i]);
    }

    printf("\n");
    free(tabelaBitov);  
    free(preberiNajprej);
    fclose(input);
    return 0;
}