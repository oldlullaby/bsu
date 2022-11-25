#include <iostream>
#include <Windows.h>

CRITICAL_SECTION cs;

HANDLE Event_1;
HANDLE Event_2;

struct Array {
	int k;
	int n;
	double* arr;
	int result;
};

DWORD WINAPI work(LPVOID Arr) {

	EnterCriticalSection(&cs);
	auto massiv = (Array*)(Arr);

	int cs_r = 0;

	for (int i = 0; i < massiv->n; ++i) {

		if (massiv->arr[i] > 0) {
			std::swap(massiv->arr[cs_r], massiv->arr[i]);
			cs_r++;
		}
	}

	LeaveCriticalSection(&cs);
	SetEvent(Event_1);
	return 0;
}

DWORD WINAPI countElement(LPVOID Arr) {
	WaitForSingleObject(Event_1, INFINITE);

	auto massiv = (Array*)Arr;

	massiv->result = 0;
	for (int i = 0; i < massiv->k; ++i) {
		if (massiv->arr[i] == (int)massiv->arr[i]) massiv->result++;
	}

	SetEvent(Event_2);
	return 0;
}

int main() {

	DWORD IDThread_1;
	DWORD IDThread_2;
	InitializeCriticalSection(&cs);

	Event_1 = CreateEvent(NULL, TRUE, FALSE, NULL);
	if (Event_1 == NULL) return GetLastError();

	Event_2 = CreateEvent(NULL, FALSE, FALSE, NULL);
	if (Event_2 == NULL)
		return GetLastError();

	Array massiv;
	std::cout << "Enter array size: ";
	std::cin >> massiv.n;
	massiv.arr = new double[massiv.n];

	std::cout << "Enter elements: ";
	for (int i = 0; i < massiv.n; ++i) {
		std::cin >> massiv.arr[i];
	}

	std::cout << "Array size: " << massiv.n << "\nArray: ";
	for (int i = 0; i < massiv.n; ++i) {
		std::cout << massiv.arr[i] << " ";
	}

	// -*****************************************************

	EnterCriticalSection(&cs);


	HANDLE Work = CreateThread(nullptr, NULL, work, &massiv, 0, &IDThread_1);
	HANDLE CountElement = CreateThread(nullptr, NULL, countElement, &massiv, 0, &IDThread_2);
	std::cout << "\nEnter k: ";
	std::cin >> massiv.k;

	LeaveCriticalSection(&cs);

	WaitForSingleObject(Event_1, INFINITE);

	for (int i = 0; i < massiv.k; ++i) {
		std::cout << massiv.arr[i] << " ";
	}

	WaitForSingleObject(Event_2, INFINITE);

	std::cout << "\nResult = " << massiv.result << std::endl;

	for (int i = massiv.k; i < massiv.n; ++i) {
		std::cout << massiv.arr[i] << " ";
	}

	CloseHandle(Work);
	CloseHandle(CountElement);
	CloseHandle(Event_1);
	CloseHandle(Event_2);

	DeleteCriticalSection(&cs);

	return 0;

}
