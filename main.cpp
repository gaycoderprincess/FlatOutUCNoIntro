#include <windows.h>
#include "nya_commonhooklib.h"

BOOL WINAPI DllMain(HINSTANCE, DWORD fdwReason, LPVOID) {
	switch( fdwReason ) {
		case DLL_PROCESS_ATTACH: {
			if (NyaHookLib::GetEntryPoint() != 0x24CEF7) {
				MessageBoxA(nullptr, aFOUCVersionFail, "nya?!~", MB_ICONERROR);
				exit(0);
				return TRUE;
			}

			NyaHookLib::PatchRelative(NyaHookLib::JMP, 0x55B969, 0x55BA58); // skip copyright screen
			NyaHookLib::Patch<uint8_t>(0x55B29D, 0xEB); // skip intros
		} break;
		default:
			break;
	}
	return TRUE;
}