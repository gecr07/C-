#include <Windows.h>
#include <Tchar.h>
#include <strsafe.h>

extern "C" const IMAGE_DOS_HEADER __ImageBase;
void DumpModule() {
	// Get the base address of the running application.
	// Can be different from the running module if this code is in a DLL.
	HMODULE hModule = GetModuleHandle(NULL);
	_tprintf(TEXT("with GetModuleHandle(NULL) = 0x%x\r\n"), hModule);
	// Use the pseudo-variable __ImageBase to get
	// the address of the current module hModule/hInstance.
	_tprintf(TEXT("with __ImageBase = 0x%x\r\n"), (HINSTANCE)&__ImageBase);
	// Pass the address of the current method DumpModule
	// as parameter to GetModuleHandleEx to get the address
	// of the current module hModule/hInstance.
	hModule = NULL;
	GetModuleHandleEx(
		GET_MODULE_HANDLE_EX_FLAG_FROM_ADDRESS,
		(PCTSTR)DumpModule,
		&hModule);
	_tprintf(TEXT("with GetModuleHandleEx = 0x%x\r\n"), hModule);
}


void DumpEnvStrings() {
	PTSTR pEnvBlock = GetEnvironmentStrings();
	// Parse the block with the following format:
	// =::=::\
    // =...
	// var=value\0
	// ...
	// var=value\0\0
	// Note that some other strings might begin with '='.
	// Here is an example when the application is started from a network share.
	// [0] =::=::\
    // [1] =C:=C:\Windows\System32
	// [2] =ExitCode=00000000
	//
	TCHAR szName[MAX_PATH];
	TCHAR szValue[MAX_PATH];
	PTSTR pszCurrent = pEnvBlock;
	HRESULT hr = S_OK;
	PCTSTR pszPos = NULL;
	int current = 0;
	while (pszCurrent != NULL) {
		// Skip the meaningless strings like:
		// "=::=::\"
		if (*pszCurrent != TEXT('=')) {
			// Look for '=' separator.
			pszPos = _tcschr(pszCurrent, TEXT('='));
			// Point now to the first character of the value.
			pszPos++;
			// Copy the variable name.
			size_t cbNameLength = // Without the' ='
				(size_t)pszPos - (size_t)pszCurrent - sizeof(TCHAR);
			hr = StringCbCopyN(szName, MAX_PATH, pszCurrent, cbNameLength);
			if (FAILED(hr)) {
				break;
			}
			// Copy the variable value with the last NULL character
			// and allow truncation because this is for UI only.
			hr = StringCchCopyN(szValue, MAX_PATH, pszPos, _tcslen(pszPos) + 1);
			if (SUCCEEDED(hr)) {

				_tprintf(TEXT("[%u] %s=%s\r\n"), current, szName, szValue);
			}
			else // something wrong happened; check for truncation.
				if (hr == STRSAFE_E_INSUFFICIENT_BUFFER) {
					_tprintf(TEXT("[%u] %s=%s...\r\n"), current, szName, szValue);
				}
				else { // This should never occur.
					_tprintf(
						TEXT("[%u] %s=???\r\n"), current, szName
					);
					break;
				}
		}
		else {
			_tprintf(TEXT("[%u] %s\r\n"), current, pszCurrent);
		}
		// Next variable please.
		current++;
		// Move to the end of the string.
		while (*pszCurrent != TEXT('\0'))
			pszCurrent++;
		pszCurrent++;
		// Check if it was not the last string.
		if (*pszCurrent == TEXT('\0'))
			break;
	};
	// Don't forget to free the memory.
	FreeEnvironmentStrings(pEnvBlock);
}



void PrintEnvironmentVariable(PCTSTR pszVariableName) {
	PTSTR pszValue = NULL;
	// Get the size of the buffer that is required to store the value
	DWORD dwResult = GetEnvironmentVariable(pszVariableName, pszValue, 0);
	if (dwResult != 0) {
		// Allocate the buffer to store the environment variable value
		DWORD size = dwResult * sizeof(TCHAR);
		pszValue = (PTSTR)malloc(size);
		GetEnvironmentVariable(pszVariableName, pszValue, size);
		_tprintf(TEXT("%s=%s\n"), pszVariableName, pszValue);
		free(pszValue);
	}
	else {
		_tprintf(TEXT("'%s'=<unknown value>\n"), pszVariableName);
	}
}

#define BUFSIZE MAX_PATH

void currentDir() {
	
	TCHAR Buffer[BUFSIZE];

	DWORD dwResult = GetCurrentDirectory(BUFSIZE, Buffer);

	_tprintf(TEXT("Deberia mostrar el directorio actual (%s)\n"), Buffer);


}

int main() {
	currentDir();
	//PrintEnvironmentVariable(L"APPDATA");
	//DumpModule();
	//DumpEnvStrings();
	//_tprintf(L"Hola soy una cadena unicode");
	//MessageBox(NULL, L"Texto", L"Titulo", 0);
	return 0;
}
