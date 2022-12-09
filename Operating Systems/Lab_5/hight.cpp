#include <conio.h>
#include <iostream>
#include <Windows.h>

void main(int argc, char** argv) {

    srand(time(NULL)); int n;

    std::cout << "Hight:\n Enter numbers N:";
    std::cin >> n;

    HANDLE hWritePipe = (HANDLE)atoi(argv[1]);
    HANDLE hReadPipe = (HANDLE)atoi(argv[2]);
    HANDLE hEvent = OpenEvent(EVENT_ALL_ACCESS, FALSE, L"Event");

    __int16 temp;
    DWORD dwBytesRead;
    ReadFile(hReadPipe, &temp, sizeof(__int16), &dwBytesRead, NULL);

    DWORD dwBytesRead1;
    __int16* arr = new __int16[temp];

    ReadFile(hReadPipe, arr, sizeof(__int16) * temp, &dwBytesRead1, NULL);

    for (int i = 0; i < temp; i++) { arr[i] = rand() % 100; }
    for (int i = 0; i < n; i++) { std::cout << arr[i] << " "; } std::cout << "\n";

    int s = 0;
    for (int i = 0; i < temp; ++i) if (arr[i] > n) s++;

    DWORD dwBytesWritten1;
    WriteFile(hWritePipe, &s, sizeof(int), &dwBytesWritten1, NULL);

    DWORD dwBytesWritten;
    for (int i = 0; i < temp; ++i) if (arr[i] > n) WriteFile(hWritePipe, &arr[i], sizeof(__int16), &dwBytesWritten, NULL);
    

    SetEvent(hEvent);
    CloseHandle(hWritePipe);
    CloseHandle(hReadPipe);
    CloseHandle(hEvent);

    std::cout << "\nEnter 0 for exit\n";
    while (_getch() != '0') {}
}
