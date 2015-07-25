#include <stdio.h>
#include <sys/time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <unistd.h>
#include <fcntl.h>
#include <poll.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <stdint.h>

#define PRUSS_SHAREDRAM_BASE     0x4a312000


struct ring_buffer {
    uint8_t buffer[12000];
};

static volatile struct ring_buffer *ring_buffer;

void main(){
	
	int mem_fd = open("/dev/mem", O_RDWR|O_SYNC);
    ring_buffer = (volatile struct ring_buffer*) mmap(0, 12000, PROT_READ|PROT_WRITE, MAP_SHARED, mem_fd, PRUSS_SHAREDRAM_BASE);
    close(mem_fd);
	int i = 0;
    for(i=0;i<12000;i++)
        printf("%d:%d  ",i,ring_buffer->buffer[i]);

}
