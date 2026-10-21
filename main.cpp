#include <iostream>
#include <cstddef>
#include "arraylib.h"

int main() {
    int data[] = {5, -3, 8, 0, -1, 9, 2, -4, 0, 7};
    const std::size_t n = sizeof(data) / sizeof(data[0]);

    std::cout << "Массив (" << n << " кол-во элементов): ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << data[i] << ' ';
    }
    std::cout << "\n\n";

    std::cout << "Sum:            " << arr_sum(data, n)            << '\n';
    std::cout << "Max:            " << arr_max(data, n)            << '\n';
    std::cout << "Min:            " << arr_min(data, n)            << '\n';
    std::cout << "Average:        " << arr_average(data, n)        << '\n';
    std::cout << "Count positive: " << arr_count_positive(data, n) << '\n';
    std::cout << "Count negative: " << arr_count_negative(data, n) << '\n';
    std::cout << "Count zero:     " << arr_count_zero(data, n)     << '\n';
    std::cout << "Product:        " << arr_product(data, n)        << '\n';
    std::cout << "Median:         " << arr_median(data, n)         << '\n';

    std::cout << "\nМассив после работы функции вычисления медианы: ";
    for (std::size_t i = 0; i < n; ++i) {
        std::cout << data[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}