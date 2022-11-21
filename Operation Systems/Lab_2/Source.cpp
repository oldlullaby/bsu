#include <iostream>
#include <Windows.h>
#include <string>

void main(int argc, char* argv[]) {
	
	int n;
	int k;

	std::cout << "Enter n: ";
	std::cin >> n;
	auto* arr = new double[n] ;
	std::cout << "Enter array elements: ";
	for (int i = 0; i < n; ++i) {
		std::cin >> arr[i];
	}

	std::cout << "Enter k: ";
	std::cin >> k;

	std::wstring s = L"Child.exe ";
	s += std::to_wstring(n) + L" ";
	s += std::to_wstring(k) + L" ";
	for (int i = 0; i < n; ++i) {
		s += std::to_wstring(arr[i]) + L" ";
	}
	auto* str = new wchar_t[s.length()];
	wcscpy_s(str, s.length() + 1, s.c_str());
	STARTUPINFO lpStartUpInfo;

	PROCESS_INFORMATION lpProcessInformation;
	ZeroMemory(&lpStartUpInfo, sizeof(STARTUPINFO));
	lpStartUpInfo.dwFlags = STARTF_USEFILLATTRIBUTE;
	lpStartUpInfo.dwFillAttribute = BACKGROUND_INTENSITY;
	if (!CreateProcess(nullptr, str, nullptr, nullptr, FALSE, NULL, nullptr, nullptr, &lpStartUpInfo, &lpProcessInformation)) {
		std::cout << "Process is not created";
	}
	else {
		std::cout << "Process is created" << std::endl;
		WaitForSingleObject(lpProcessInformation.hProcess, INFINITE);
	}
	CloseHandle(lpProcessInformation.hThread);
	CloseHandle(lpProcessInformation.hProcess);
	system("pause");
}
