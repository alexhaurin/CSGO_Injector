#pragma once

#include <Windows.h>
#include <TlHelp32.h>
#include <iostream>

#include <time.h>
#include <comdef.h> // For _bstr_t: to convert WCHAR* to type compatable with const char*

// ==================== NOTES =======================
//
// 1. _CRT_SECURE_NO_WARNINGS is enabled

/*
Credits:
1. https://github.com/AMATEURZ1337/load-lib-injector ( Little bit of code used ).
2. Cyborg Elf: https://www.youtube.com/channel/UC_bMnu_fYu9-2_EY7GUfclQ
3. Discord: xo1337 https://discord.gg/NwRFmp3J2J

*/