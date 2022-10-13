#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {

    if (argc < 3){
        fprintf(stderr, "Too few arguments.\nUse %s <ip> <port> instead.\n", argv[0]);
        _exit(-1);
    }

    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // Cast pointer to other pointer type
    // (sockaddr_in*)&conn_info
    uint16_t hostPort = atoi(argv[2]);
    uint16_t networkPort = htons(hostPort);
    sockaddr_in con_info;
    con_info.sin_port = networkPort;
    con_info.sin_family = AF_INET; 
    con_info.sin_addr.s_addr = inet_addr(argv[1]);
    if ((connect(fd, (sockaddr*)&con_info, sizeof(sockaddr))) != 0){
        fprintf(stderr, "Error while connecting.\n");
        _exit(-1);
    }
    char buf[128];
    if ((read(fd, buf, 128)) == -1){
        fprintf(stderr, "Error while reading.\n");
        _exit(-1);
    }
    printf("%s", buf);
    close(fd);
    return 0;
}
