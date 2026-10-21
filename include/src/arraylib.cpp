#include "arraylib.h"

int arr_sum(const int* arr, std::size_t n) {
    int s = 0;
    for (std::size_t i = 0; i < n; ++i) {
        s += arr[i];
    }
    return s;
}

int arr_max(const int* arr, std::size_t n) {
    int m = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] > m) m = arr[i];
    }
    return m;
}

int arr_min(const int* arr, std::size_t n) {
    int m = arr[0];
    for (std::size_t i = 1; i < n; ++i) {
        if (arr[i] < m) m = arr[i];
    }
    return m;
}

double arr_average(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;
    return static_cast<double>(arr_sum(arr, n)) / static_cast<double>(n);
}

int arr_count_positive(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] > 0) ++c;
    }
    return c;
}

int arr_count_negative(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] < 0) ++c;
    }
    return c;
}

int arr_count_zero(const int* arr, std::size_t n) {
    int c = 0;
    for (std::size_t i = 0; i < n; ++i) {
        if (arr[i] == 0) ++c;
    }
    return c;
}

int arr_product(const int* arr, std::size_t n) {
    int p = 1;
    for (std::size_t i = 0; i < n; ++i) {
        p *= arr[i];
    }
    return p;
}

static void sort_bubble(int* a, std::size_t n) {
    for (std::size_t i = 0; i + 1 < n; ++i) {
        bool swapped = false;
        for (std::size_t j = 0; j + 1 < n - i; ++j) {
            if (a[j] > a[j + 1]) {
                int t = a[j];
                a[j] = a[j + 1];
                a[j + 1] = t;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

double arr_median(const int* arr, std::size_t n) {
    if (n == 0) return 0.0;

    int* copy = new int[n];
    for (std::size_t i = 0; i < n; ++i) {
        copy[i] = arr[i];
    }
    sort_bubble(copy, n);

    double result;
    if (n % 2 == 1) {
        result = static_cast<double>(copy[n / 2]);
    } else {
        result = (static_cast<double>(copy[n / 2 - 1]) +
                  static_cast<double>(copy[n / 2])) / 2.0;
    }

    delete[] copy;
    return result;
}