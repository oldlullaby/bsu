#include <iostream>
#include <windows.h>

HANDLE Writer[3], Reader[3], Exit[2];

wchar_t const* mwriter[3]{ L"W_Exit", L"W_A", L"W_B" }, *mreader[3]{ L"R_Exit", L"R_C", L"R_D" }, *exit_messages[2]{ L"1", L"0" };

int main()
{
    Writer[0] = CreateEvent(NULL, FALSE, FALSE, mwriter[0]);
    Reader[0] = CreateEvent(NULL, FALSE, FALSE, mreader[0]);

    Writer[1] = CreateEvent(NULL, FALSE, FALSE, mwriter[1]);
    Reader[1] = CreateEvent(NULL, TRUE, FALSE, mreader[1]);

    Writer[2] = CreateEvent(NULL, FALSE, FALSE, mwriter[2]);
    Reader[2] = CreateEvent(NULL, TRUE, FALSE, mreader[2]);

    for (int i = 0; i < 2; ++i) { Exit[i] = CreateEvent(NULL, FALSE, FALSE, exit_messages[i]); }

    int n_of_proc;
    std::cout << "Number of process: ";
    std::cin >> n_of_proc;

    HANDLE hSemaphore = CreateSemaphore(NULL, 2, 2, L"Semaphore");
    HANDLE hMutex = CreateMutex(NULL, 0, L"Mutex");
    STARTUPINFO* Wstp = new STARTUPINFO[n_of_proc], * Rstp = new STARTUPINFO[n_of_proc];
    PROCESS_INFORMATION* Wpi = new PROCESS_INFORMATION[n_of_proc], * Rpi = new PROCESS_INFORMATION[n_of_proc];

    for (int i = 0; i < n_of_proc; ++i){

        ZeroMemory(&Wstp[i], sizeof(STARTUPINFO));
        Wstp[i].cb = sizeof(STARTUPINFO);
        ZeroMemory(&Rstp[i], sizeof(STARTUPINFO));
        Rstp[i].cb = sizeof(STARTUPINFO);

        std::wstring writer = L"Writer.exe", reader = L"Reader.exe";

        CreateProcess(NULL, &writer[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &Wstp[i], &Wpi[i]);
        CreateProcess(NULL, &writer[1], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &Wstp[i], &Wpi[i]);

        CreateProcess(NULL, &reader[0], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &Rstp[i], &Rpi[i]);
        CreateProcess(NULL, &reader[1], NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &Rstp[i], &Rpi[i]);
    
    }

    int counter = 1;
    for (int i = 0; i < n_of_proc; ++i) {

        while (true) {

            DWORD message_ = WaitForMultipleObjects(3, Writer, FALSE, INFINITE);
            SetEvent(Reader[message_]);
            std::wcout << mwriter[message_] << std::endl;
            DWORD message = WaitForMultipleObjects(2, Exit, FALSE, INFINITE);
            if (message == WAIT_OBJECT_0) {

                std::cout << "Reader " << counter << " ended his work\n";
                counter += 1;
                break;
            }
        }
        std::cout << "Writer " << i + 1 << " ended his work\n";
    }

    for (int i = 0; i < 3; i++) {

        CloseHandle(Writer[i]);
        CloseHandle(Reader[i]);
    
    }

    for (int i = 0; i < 2; i++) CloseHandle(Exit[i]);

    for (int i = 0; i < n_of_proc; i++) {

        CloseHandle(Wpi[i].hThread);
        CloseHandle(Wpi[i].hProcess);
        CloseHandle(Rpi[i].hThread);
        CloseHandle(Rpi[i].hProcess);
    
    }

    CloseHandle(hSemaphore);
    return 0;
}
