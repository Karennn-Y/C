#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

extern int getIpv4(char *domain, char *ip);

int main (int argc, char **argv)
{
    char ipv4[32];
    int rtn;

    if (argc != 2) {
        printf("please enter your domain name\n");
        exit(0);
    }

    rtn = getIpv4(argv[1], ipv4);

    if (rtn == 1) {
        printf("%s = %s \n", argv[1], ipv4);
    }
    else {
        printf("ip cannot found\n");
    }

    return 0;
}
