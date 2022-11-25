#include <iostream>
#include <windows.h>

wchar_t const* messages[3]{ L"W_Exit", L"W_A", L"W_B" };

int main() {

    std::string line;
    HANDLE hMutex = OpenMutex(MUTEX_ALL_ACCESS, FALSE, L"Mutex");
    WaitForSingleObject(hMutex, INFINITE);

    std::cout << "Writer is started" << std::endl;
    std::cout << "Process is active" << std::endl;

    HANDLE mesEv[3];
    for (int i = 0; i < 3; ++i) { mesEv[i] = OpenEvent(EVENT_MODIFY_STATE, FALSE, messages[i]); }
    while (true) {

        std::cin >> line;
        line = "W_" + line;
        wstring wline(line.begin(), line.end());
        if (wline._Equal(messages[0])) { SetEvent(mesEv[0]); break; }
        if (wline._Equal(messages[1])) { SetEvent(mesEv[1]); }
        if (wline._Equal(messages[2])) { SetEvent(mesEv[2]); }

    }
    ReleaseMutex(hMutex);
    return 0;

}
