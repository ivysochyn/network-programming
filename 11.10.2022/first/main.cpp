#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
using namespace std;

int main(int argc, char **argv){
    int n = 30;
    char buf[n];
    int file = open("date", 0600);
    if (file == -1)
        _exit(-1);
    ssize_t read_bytes = read(file, buf, n);
    if (read_bytes == -1)
        _exit(-1);
    printf("%s\n", buf);
    if ((close(file)) == -1)
        _exit(-1);
    return 0;
}
