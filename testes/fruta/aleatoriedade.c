#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
        int i;
        int buffer[8];
        int fd = open("/dev/urandom", O_RDONLY);
        read(fd, buffer, 8);
        //buffer now contains the random data
        close(fd);
        for(i = 0; i < 8; ++i)
                printf("%02X", buffer[i]);
        printf("\n");
        return 0;
}
