//code to for lossless stream data transfer via pru_bridge

#include <stdint.h>
#include "pru_defs.h"
int main()
{
   struct circular_buffers
    {
        uint8_t data[12000];
    };

    volatile struct circular_buffers* ring = (volatile struct circular_buffers*)(DPRAM_SHARED);

    int j =0;
    uint8_t i = 0;
    while(1)
    {
        if(j<12000)           //checking if the buffer is full or not
        {
            ring ->data[j] = i;
            i++;
            j++;
        }
    }
return 0;
}
