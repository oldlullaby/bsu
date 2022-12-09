#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <condition_variable>

std::mutex cs;
std::mutex Event_1;
std::mutex Event_2;

void Work(std::vector<double>& array, int n, int& k) {

	std::unique_lock cs_locker(cs);

	int cs_r = 0;

	for (int i = 0; i < n; ++i) {

		if (array[i] > 0) {
			std::swap(array[cs_r], array[i]);
			cs_r++;
		}
	}

	cs_locker.unlock();
	std::unique_lock event_locker(Event_1);
}

void countElement(std::vector<double>& array, int n, int& k, int &result) {

	for (int i = 0; i < k; ++i) if (array[i] == (int)array[i]) result++;
	std::unique_lock event_locker(Event_2);
}


int main() {

	std::cout << "Enter array size: ";
	int n, k, result = 0; std::cin >> n;
	std::vector <double> array(n);


	std::cout << "Enter elements: ";
	for (int i = 0; i < n; ++i) std::cin >> array[i];

	std::cout << "Array size: " << n << "\nArray: ";
	for (int i = 0; i < n; ++i) std::cout << array[i] << " ";

	std::cout << "Enter k:" << std::endl; std::cin >> k;

	// -*****************************************************

	std::unique_lock cs_locker(cs);


	std::jthread work(Work, std::ref(array), n, std::ref(k));
	std::jthread CountElement(countElement, std::ref(array), std::ref(k), std::ref(result));


	cs_locker.unlock();

	for (int i = 0; i < k; ++i) std::cout << array[i] << " ";

	std::cout << "\nResult = " << result << std::endl;

	for (int i = k; i < n; ++i) std::cout << array[i] << " ";
	

	return 0;

}
