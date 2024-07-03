///
/// @brief  :
/// @file   : strtest2.c
/// @date   : 2024년 6월 11일 화요일 15시 37분 18초 KST
/// @author : Cento
///
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

////////////////////////////////////////////////////////////////////////////////
///
/// @fn     : void DumpMem(char *msg, char *str, int len){
/// @param  :
/// @return :
////////////////////////////////////////////////////////////////////////////////
void DumpMem(char *msg, char *str, int len){
unsigned char *p;
    printf("%s\n", msg);
    p = (unsigned char *)str;
    for(int i = 0; i < len; i++, p++)
          printf("0x%02x[%c] ", *p, *p);
    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////
///
/// @fn     : int main(int argc, char **argv) {
/// @param  :
/// @return :
////////////////////////////////////////////////////////////////////////////////
int main(int argc, char **argv) {
    char dest[32];
    char src[50];
    char *strp;
    char *p;

    memset(dest, 0x00, 32);
    memset(src, 0x00, 50);

    strcpy(src, "TEST Copy1234567");
    printf("src : %s\n", src);

    strcpy(dest, src);
    DumpMem("strcpy() Test -----", dest, 20);
    printf("TEXT : %s\n", dest);
    printf("SIZE : %ld\n", strlen(dest));

    memset(dest, 0x00, 32);

    strp = src;
    *(strp + 4) = 0x00;

    strncpy(dest, src, 8);
    DumpMem("strncpy(8) 후", dest, 10);

    memset(dest, 0x00, 32);
    memcpy(dest, src, 8);

    DumpMem("memcpy(8) 후", dest, 10);
}
