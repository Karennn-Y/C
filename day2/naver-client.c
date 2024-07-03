#include <sys/stat.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>

#define MAXBUF      1024

extern int getIpv4(char *domain, char *ip);

int main(int argc, char **argv)
{
    struct sockaddr_in serveraddr;
    int server_sockfd;
    int client_len;
    char buf[MAXBUF];
    char rbuf[MAXBUF];
    char ipBuf[32];
    int rtn;
    char sendBuf[MAXBUF];
    char rcvBuf;

    if (argc != 3) {
        printf("Using : %s <domain> <port>\n", argv[0]);
        exit(0);
    }

    if ((server_sockfd = socket(AF_INET, SOCK_STREAM, 0)) < 0)
    {
        printf("Error : %s\n", strerror(errno));
        exit(0);
    }
    printf("%d\n", server_sockfd);

    memset(ipBuf, 0x00, 32); // chogihwa
    rtn = getIpv4(argv[1], ipBuf);
    if (rtn == 0) {
        printf("cannot found\n");
        exit(0);
    }
    printf("%s\n", ipBuf);

    serveraddr.sin_family = AF_INET;
    serveraddr.sin_addr.s_addr = inet_addr(ipBuf);
    serveraddr.sin_port = htons(atoi(argv[2]));

    client_len = sizeof(serveraddr);

    if (connect(server_sockfd, (struct sockaddr *)&serveraddr, client_len) < 0)
    {
        perror("connect error :");
        exit(0);
    }

    memset(sendBuf, 0x00, MAXBUF);

    sprintf(sendBuf, "GET / HTTP/1.0\r\n"
        "Host: %s\r\n"
        "Accept: /\r\n"
        "Connection: close\r\n\r\n",
        argv[1]);

    rtn = write(server_sockfd, sendBuf, strlen(sendBuf));

    if (rtn <= 0) {
        printf("cannot found\n");
        exit(0);
    }

    printf("SEND : %s\n", sendBuf);

    while(1) {
        rtn = read(server_sockfd, &rcvBuf, 1);
        if(rtn <= 0)
            break;
        printf("%c", rcvBuf);
    }

    close(server_sockfd);
    return 0;
}
