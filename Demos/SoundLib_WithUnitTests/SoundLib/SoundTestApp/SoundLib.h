// The following ifdef block is the standard way of creating macros which make exporting
// from a DLL simpler. All files within this DLL are compiled with the SOUNDLIB_EXPORTS
// symbol defined on the command line. This symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see
// SOUNDLIB_API functions as being imported from a DLL, whereas this DLL sees symbols
// defined with this macro as being exported.
#ifdef SOUNDLIB_EXPORTS
#define SOUNDLIB_API __declspec(dllexport)
#else
#define SOUNDLIB_API __declspec(dllimport)
#endif

// This class is exported from the dll
class SOUNDLIB_API CSoundLib {
public:
	CSoundLib(void);
	// TODO: add your methods here.
};

extern SOUNDLIB_API int nSoundLib;

SOUNDLIB_API int fnSoundLib(void);

SOUNDLIB_API char* GetTeam();