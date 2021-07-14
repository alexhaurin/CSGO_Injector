#include "Functions.h"

const std::string DLL_PATH = "DLL/cheats.dll";

void InjectDLL(const DWORD ProcessID, const HANDLE gameHandle, const std::string& dllPath) {
	if (Functions::DoesFileExist(DLL_PATH.c_str())) // Name of dll
	{

		if (!Functions::Internal::ExecuteBypass(gameHandle)) { // Make sure we can bypass VAC
			Cleanup("Could not bypass :(");
		}

		if (Functions::LoadLibraryInject(ProcessID, DLL_PATH.c_str())) {
			Functions::Internal::Backup(gameHandle);
			Cleanup("Injected!");
		}
		else {
			Cleanup("Could not inject :(");
		}
	}
	else
	{
		Cleanup("Could not find dll file");
	}
}

int main() {
	SetConsoleTitleA(RandomString(26).c_str()); // Some anticheats can detetct console titles

	// Get necesarry data
	const DWORD ProcessID = Functions::GetProcessId("csgo.exe");

	if (!ProcessID) { Cleanup("Could not find CSGO's process ID :("); }

	const HANDLE game = OpenProcess(PROCESS_ALL_ACCESS, FALSE, ProcessID);
	uintptr_t ModuleBase = Functions::GetModuleBaseAddress(ProcessID, "client.dll");

	// Inject DLL
	InjectDLL(ProcessID, game, DLL_PATH);
	
	Cleanup("Code ran successfully! :)");
}