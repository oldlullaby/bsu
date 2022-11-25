#include <iostream>
#include <string>
#include <windows.h>

wchar_t const* messages[3]{ L"R_Exit", L"R_C", L"R_D" };
wchar_t const* exit_messages[2]{ L"1", L"0" };

int main() {

    HANDLE message_events[3], messages_exit[2];

    std::string number;
    HANDLE hSemaphore = OpenSemaphore(SEMAPHORE_ALL_ACCESS, FALSE, L"Semaphore");
    WaitForSingleObject(hSemaphore, INFINITE);

    std::cout << "Reader is started" << std::endl;
    std::cout << "Process is active" << std::endl;
    
    for (int i = 0; i < 3; ++i) { message_events[i] = OpenEvent(EVENT_ALL_ACCESS, FALSE, messages[i]); }
    for (int i = 0; i < 2; ++i) { messages_exit[i] = OpenEvent(EVENT_ALL_ACCESS, FALSE, exit_messages[i]); }

    while (true) {

        DWORD m = WaitForMultipleObjects(3, message_events, FALSE, INFINITE);
        std::wcout << messages[m] << L'\n';
        std::cout << "Press 0 to continue or 1 to exit" << std::endl;
        std::cin >> number;
        wstring wline(number.begin(), number.end());

        if (wline._Equal(exit_messages[0])) { SetEvent(messages_exit[0]); break; }
        if (wline._Equal(exit_messages[1])) { SetEvent(messages_exit[1]); }
    }
    ReleaseSemaphore(hSemaphore, 1, NULL);
    return 0;
}
