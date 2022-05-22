#include <Windows.h>

#include "fmt/core.h"

BOOL WINAPI DllMain(HMODULE instance, unsigned long reason, void* reserved)
{
	switch (reason)
	{
		case DLL_PROCESS_ATTACH:
		{
			AllocConsole();

			freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(0)), "conin$", "r", static_cast<_iobuf*>(__acrt_iob_func(0)));
			freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(1)), "conout$", "w", static_cast<_iobuf*>(__acrt_iob_func(1)));
			freopen_s(reinterpret_cast<_iobuf**>(__acrt_iob_func(2)), "conout$", "w", static_cast<_iobuf*>(__acrt_iob_func(2)));

			fmt::print("fmt example");
			break;
		}
	}

	return TRUE;
}