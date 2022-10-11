#include <fcntl.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netinet/ip.h>
#include <arpa/inet.h>
#include <stdio.h>

int main(int argc, char **argv) {
    int fd = socket(AF_INET, SOCK_STREAM, 0);
    // Cast pointer to other pointer type
    // (sockaddr_in*)&conn_info
    uint16_t hostPort = 1313;
    uint16_t networkPort = htons(hostPort);
    sockaddr_in con_info;
    con_info.sin_port = networkPort;
    con_info.sin_family = AF_INET; 
    con_info.sin_addr.s_addr = inet_addr("127.0.0.1");
    connect(fd, (sockaddr*)&con_info, sizeof(sockaddr));
    char buf[128];
    if ((read(fd, buf, 128)) == -1)
        _exit(-1);
    printf("%s\n", buf);
    close(fd);
    return 0;
}
