#include <iostream>
#include <mutex>
#include <thread>
#include <vector>
#include <Windows.h>
#include <chrono>
#include <condition_variable>

std::mutex out, section;

std::condition_variable Event_1, Event_2, Event_3;

void Work(std::vector<double>& array, int n, int& k) {

	std::unique_lock lock_section(section);
	Event_3.wait(lock_section);

	int cs_r = 0;

	for (int i = 0; i < n; ++i) {

		if (array[i] > 0) {
			std::swap(array[cs_r], array[i]);
			cs_r++;
		}
	}

	lock_section.unlock();
	// std::cout << k << std::endl;
	Event_1.notify_all();
}

void countElement(std::vector<double>& array, int n, int& k, int& result) {

	std::unique_lock lock_out(section);
	Event_1.wait(lock_out);

	for (int i = 0; i < k; ++i) if (array[i] == (int)array[i]) result++;

	lock_out.unlock();

	Event_2.notify_one();

}


int main() {


	std::cout << "Enter array size: ";
	int n, k, result = 0; std::cin >> n;
	std::vector <double> array(n);


	std::cout << "Enter elements: ";
	for (int i = 0; i < n; ++i) std::cin >> array[i];

	std::cout << "Array size: " << n << "\nArray: ";
	for (int i = 0; i < n; ++i) std::cout << array[i] << " ";

	std::thread work(Work, std::ref(array), n, std::ref(k));
	std::thread CountElement(countElement, std::ref(array), n, std::ref(k), std::ref(result));

	std::cout << "Enter k:" << std::endl; std::cin >> k;

	std::unique_lock lock_section(section);
	Event_3.notify_one();
	
	Event_1.wait(lock_section);

	for (int i = 0; i < k; ++i) std::cout << array[i] << " ";
	Event_2.wait(lock_section);

	std::cout << "\nResult = " << result << std::endl;
	for (int i = k; i < n; ++i) std::cout << array[i] << " ";

	lock_section.unlock(); work.detach(); CountElement.detach();
	return 0;

}
