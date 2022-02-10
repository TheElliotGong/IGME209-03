// SoundLib.cpp : Defines the exported functions for the DLL.
//

#include "pch.h"
#include "framework.h"
#include "SoundLib.h"


// This is an example of an exported variable
SOUNDLIB_API int nSoundLib=0;

// This is an example of an exported function.
SOUNDLIB_API int fnSoundLib(void)
{
    nSoundLib++;
    return nSoundLib;
}

const char* team = "Steve and Adi";
SOUNDLIB_API char* GetTeam()
{

    return (char*)team;
}

// This is the constructor of a class that has been exported.
CSoundLib::CSoundLib()
{
    return;
}
