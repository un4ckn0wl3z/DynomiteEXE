#include "util.h"


int main() {

	HWND hwnd_dm = FindWindowA(NULL, "Dynomite Deluxe");
	if (hwnd_dm != FALSE) {
		DWORD pid = NULL;
		GetWindowThreadProcessId(hwnd_dm, &pid);
		HANDLE pHandle = NULL;
		pHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, pid);
		if (pHandle == INVALID_HANDLE_VALUE || pHandle == NULL) {
			return 1;
		}

		char gameModule[] = "Dynomite.exe";
		DWORD gameBaseAddress = util::GetModuleBaseAddress(_T(gameModule), pid );

		DWORD pointAddr = 0x131EDC;
		std::vector<DWORD> pointOffsets{ 0x68 };
		DWORD pointPtrAddr = util::GetPointerAddress(hwnd_dm, gameBaseAddress, pointAddr, pointOffsets);

		if (pointPtrAddr == 1) {
			return 1;
		}

		while (true)
		{
			int point = 9971337;
			WriteProcessMemory(pHandle, (LPVOID*)(pointPtrAddr), &point, 4, 0);
			Sleep(500);
		}

	}
}


