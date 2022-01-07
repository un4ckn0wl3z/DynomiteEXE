#pragma once
#include <stdlib.h>
#include <Windows.h>
#include <tchar.h>
#include <iostream>
#include <TlHelp32.h>
#include <vector>

namespace util 
{
	DWORD GetModuleBaseAddress(TCHAR* lpszModuleName, DWORD pID);
	DWORD GetPointerAddress(HWND hwnd, DWORD gameBaseAddr, DWORD address, std::vector<DWORD> offsets);

}