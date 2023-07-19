#include <stdint.h>
#include <stdio.h> 
#include <stdlib.h>

uint32_t ntohl(uint32_t n){
    uint32_t n1 = (n & 0xff000000) >> 24;
    uint32_t n2 = (n & 0x00ff0000) >> 8;
    uint32_t n3 = (n & 0x0000ff00) << 8;
    uint32_t n4 = (n & 0x000000ff) << 24;
    return n1 | n2 | n3 | n4;
}

int main(int argc, char *argv[]) {
    if(argc!=3){
        exit(0);
    }
    FILE *fp1 = fopen(argv[1],"rb");
    FILE *fp2 = fopen(argv[2],"rb");
    uint32_t number1=0, number2=0, sum=0;
    fread(&number1,sizeof(uint32_t),1,fp1);
    fread(&number2,sizeof(uint32_t),1,fp2);
    number1 = ntohl(number1);
    number2 = ntohl(number2);
    sum=number1+number2;

    printf("%d(0x%02x) + %d(0x%02x) = %d(0x%02x)\n", number1, number1, number2, number2, sum, sum);

    fclose(fp1);
    fclose(fp2);
}
