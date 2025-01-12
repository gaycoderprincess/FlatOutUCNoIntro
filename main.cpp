#include <windows.h>
#include "nya_commonhooklib.h"
#include "fo2versioncheck.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			DoFlatOutVersionCheck(FO2Version::FOUC_GFWL);
			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x55B969, 0x55BA58); // skip copyright screen
			NyaHookLib::Patch<uint8_t>(0x55B29D, 0xEB); // skip intros
		} break;
		default:
			break;
	}
	return TRUE;
}