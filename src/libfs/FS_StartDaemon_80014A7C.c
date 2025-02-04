#include "linker.h"
#include "mts_new.h"

void SetMem_8009944C(int);
void CDFS_Init_80021EC4(void);
void sio_output_stop_8008C5B0(void);

void FS_StartDaemon_80014A7C(void)
{
    // CPU exception if >= 2MB ram range is used since retail consoles have 2 MB and dev have 8 MB.
    SetMem_8009944C(2);
    CDFS_Init_80021EC4(); // init cd and the likes
    sio_output_stop_8008C5B0(); // empty func
}

void FS_Null_80014AAC()
{

}

int CdReadCallback_80014AB4()
{
    return 0;
}

void CdReadMode_80014ABC()
{

}

extern const char aDsdatacallback[];
extern const char aDsreadycallbac[];

void DsReadyCallback_80014AC4(int a1)
{
    mts_printf_8008BBA0(aDsreadycallbac, a1);
}

void DsDataCallback_80014AEC(int a1)
{
    mts_printf_8008BBA0(aDsdatacallback, a1);
}

int PCinit_80014B14()
{
    return -1;
}
