#include <reader.h>
#include <genesis.h>
#include <foo.h>

void reader_tick(void) 
{
    u16 result = (u16)add(2, 2);

    char str[2];
    sprintf(str, "%d", result);
    VDP_drawText(str, 0, 0);
}