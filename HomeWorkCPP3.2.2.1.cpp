#include <iostream>
#include <locale.h>
#include <cstdlib>

void fibonacci(unsigned long*& arr_num, int& num, int& i, unsigned long& fib_i1, unsigned long fib_i = 1) {
    if (num >= i) {
        if (i == 0) {
            arr_num[i] = fib_i1;
            fibonacci(arr_num, num, ++i, fib_i1);
        }
        else {
            arr_num[i] = fib_i;
            fibonacci(arr_num, num, ++i, fib_i, fib_i + fib_i1);
        }
    }
}

void create_arr(unsigned long*& arr_num, int& size) {
    arr_num = new unsigned long[size + 1] {};
}

void delete_arr(unsigned long*& arr_num) {
    delete[] arr_num;
    arr_num = nullptr;
}

int main() {
    setlocale(LC_ALL, "Russian");
    unsigned long fib = 0, fib_i1 = 0;
    int num = 0, size = 0, i = 0;
    unsigned long* arr_num;
    create_arr(arr_num, size);
    do {
        std::cout << "Введите элемент числовой последовательности Фибоначчи или 0 для завершения программы: ";
        std::cin >> num;
        std::system("cls");
        if (num > size) {
            int i = 0;
            size = num;
            delete_arr(arr_num);
            create_arr(arr_num, size);
            fibonacci(arr_num, num, i, fib_i1);
        }
        std::cout << "Число соответствующие " << num << " элементу числовой последовательности Фибоначчи: " << arr_num[num] << "\n" << std::endl;
    } while (num > 0);
    delete_arr(arr_num);
}