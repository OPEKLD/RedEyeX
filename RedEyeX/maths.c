#include "maths.h"

void performantdelay(UINT8 numloops)
{
    UINT8 i;
    for(i = 0; i < numloops; i++)
    {
        wait_vbl_done();
    }     
}