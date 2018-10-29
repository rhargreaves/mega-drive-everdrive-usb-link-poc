#include <genesis.h>
#include <reader.h>
#include <ssf.h>

static void vsync(void);

int main(void)
{
    ssf_init();
    SYS_setVIntCallback(vsync);
    while (TRUE)
    {
        VDP_showFPS(FALSE);
        reader_tick();
        VDP_waitVSync();
        
      
    }
}

static void vsync(void) 
{
    u16 byteCount = reader_count();
    char buffer[10];
    sprintf(buffer, "Bytes: %d", byteCount);
    VDP_drawText(buffer, 0, 0);
}
