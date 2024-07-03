#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

void DumpMem(char *msg, char *str, int len){
unsigned char *p;
    printf("%s\n", msg);
    p = (unsigned char *)str;
    for(int i = 0; i < len; i++, p++)
          printf("0x%02x[%c] ", *p, *p);
    printf("\n");
}

int main(int argc, char **argv) {
    char dest[1024];
    char dest1[32];
    char dest2[32];
    char src[50];
    char *strp;
    char *p;

    memset(dest, 0x00, 1024);
    memset(dest1, 0x00, 32);
    memset(dest2, 0x00, 32);
    memset(src, 0x00, 50);

    strcpy(src, "TEST Copy1234567");
    printf("src : %s\n", src);

    strcpy(dest, src);
    printf("strcpy() Test -----\n");
    printf("TEXT : %s\n", dest);
    printf("SIZE : %ld\n", strlen(dest));

    printf("strncpy(8) Test ----\n");
    strncpy(dest1, src, 8);
    printf("TEXT1 : %s\n", dest1);
    printf("SIZE : %ld\n", strlen(dest1));

    printf("memcpy(5)----\n");
    memcpy(dest2, src, 5); // 주로 structure copy시 사용
    printf("TEST2 : %s\n", dest2);
    printf("SIZE : %ld\n", strlen(dest2));

    strp = src;
    *(strp + 4) = 0x00;

    memset(dest2, 0x00, 32);
    strncpy(dest2, src, 8);

    DumpMem("src 출력", src, 10);

    DumpMem("strncpy(8) 후", dest2, 10);

    memset(dest2, 0x00, 32);
    memcpy(dest2, src, 8);
    printf("dest2: %s\n", dest2); // %s -> null 값 전까지만 출력

    DumpMem("memcpy(8) 후", dest2, 10);
}
