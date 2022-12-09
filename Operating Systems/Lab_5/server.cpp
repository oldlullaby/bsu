#include <iostream>
#include <string>
#include <Windows.h>

void main(int argc, char** argv) {
  
    __int16 n;
    std::cout << "Server:\n Enter array size: ";
    std::cin >> n;
    __int16* arr = new __int16[n];

    STARTUPINFO si;
    PROCESS_INFORMATION pi;
    HANDLE hWritePipe;
    HANDLE hReadPipe;
    HANDLE hEvent;
    SECURITY_ATTRIBUTES sa;
    sa.nLength = sizeof(SECURITY_ATTRIBUTES);
    sa.lpSecurityDescriptor = nullptr;
    sa.bInheritHandle = TRUE;

    hEvent = CreateEvent(nullptr, FALSE, FALSE, L"Event");

    CreatePipe(&hReadPipe, &hWritePipe, &sa, 0);
    ZeroMemory(&si, sizeof(STARTUPINFO));
    wchar_t* wstr = new wchar_t[80];
    wsprintf(wstr, L"\"hight.exe\" %d %d", (int)hWritePipe, (int)hReadPipe);
    CreateProcess(nullptr, wstr, nullptr, nullptr, TRUE, CREATE_NEW_CONSOLE, FALSE, FALSE, &si, &pi);

    DWORD dwBytesWritten;
    WriteFile(hWritePipe, &n, sizeof(__int16), &dwBytesWritten, nullptr);

    DWORD dwBytesWritten1;
    WriteFile(hWritePipe, arr, sizeof(__int16) * n, &dwBytesWritten1, nullptr);
    WaitForSingleObject(hEvent, INFINITE);

    int size;
    DWORD dwBytesRead1;
    ReadFile(hReadPipe, &size, sizeof(int), &dwBytesRead1, nullptr);

    __int16 anwser;
    DWORD dwBytesRead;
    for (int i = 0; i < size; i++) { ReadFile(hReadPipe, &anwser, sizeof(__int16), &dwBytesRead, nullptr); std::cout << anwser << " "; }

    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    CloseHandle(hEvent);

    std::cout << "\nEnter 0 for exit\n";
    while (_getch() != '0') {}
}
