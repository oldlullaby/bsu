#include <stdlib.h>
#include <iostream>
#include <vector>

void main(int argc, char* argv[]) {
	if (argc > 1) {
		int n = atoi(argv[1]);
		int k = atoi(argv[2]);
		std::cout << "n = " << n << ", k = " << k << "\n";
		int cs = 0;
		std::vector <double> tmp(n);
		for (int i = 0; i < n; ++i) {
			tmp[i] = *argv[i + 3] - '0';
		}
		for (int i = 0; i < n; ++i) {
			if (tmp[i] > k) {
				tmp[cs] = tmp[i];
				cs++;
			}
		}
		for (int i = cs; i < n; ++i) {
			tmp[i] = 0;
		}

		std::cout << "Elements of array > k: " << std::endl;
		for (auto i = 0; i < n; ++i) {
			std::cout << tmp[i] << " ";
		}
		std::cout << std::endl;
	}
	else {
		std::cout << "ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR ERROR" << std::endl;
	}
	system("pause");
}
