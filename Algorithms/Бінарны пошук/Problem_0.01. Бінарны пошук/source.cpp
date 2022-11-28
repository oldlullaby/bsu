#include <iostream>
#include <cstdlib>

int compare (const void * a, const void * b)
{
    if( *(long long int*)a - *(long long int*)b < 0 )
        return -1;
    if( *(long long int*)a - *(long long int*)b > 0 )
        return 1;
    return 0;
}

long long int next_strict(const long long int *arr, long long int target, long long int end) {

    long long int start = 0;
    long long int ans = -1;

    while (start <= end) {

        long long int mid = (start + end) / 2;
        if (arr[mid] <= target)
            start = mid + 1;

        else {
            ans = mid;
            end = mid - 1;
        }
    }

    return ans;
}

long long int next_not_strict(const long long int *arr, long long int target, long long int end) {

    long long int start = 0;
    long long int ans = -1;

    while (start <= end) {

        long long int mid = (start + end) / 2;
        if (arr[mid] < target)
            start = mid + 1;

        else {
            ans = mid;
            end = mid - 1;
        }
    }

    return ans;
}

long long int bins_s(const long long int *arr, const long long int &l,
                     const long long int &r, const long long int &x) {

    if (r >= l) {
        long long int mid = l + (r - l) / 2;

        if (arr[mid] == x) return mid;
        if (arr[mid] > x) return bins_s(arr, l, mid - 1, x);

        return bins_s(arr, mid + 1, r, x);
    }

    return -1;
}


void bs (long long int arr[], const long long int &N, const long long int &x) {

    if (bins_s(arr, 0, N - 1, x) != -1) std::cout << 1 << " ";
    else std::cout << 0 << " ";


    long long int xxp = next_not_strict(arr, x, N - 1);

    if (xxp != -1) std::cout << xxp << " ";
    else std::cout << N << " ";

    xxp = next_strict(arr, x, N - 1);

    if (xxp != -1) std::cout << xxp << std::endl;
    else std::cout << N << std::endl;

}

int main() {

    int N; std::cin >> N;
    auto* arr = new long long int[N];
    for (auto i = 0; i < N; ++i)
        std::cin >> arr[i];

    std::qsort(arr, N, sizeof(long long int), compare);

    int queryN; std::cin >> queryN;
    auto* arr2 = new long long int[queryN];

    for (auto i = 0; i < queryN; ++i) {
        std::cin >> arr2[i];
    }

    for (auto i = 0; i < queryN; ++i) {
        bs(arr, N, arr2[i]);
    }

    delete[] arr;
    delete[] arr2;

    return 0;
}
