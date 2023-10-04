#include <iostream>
#include <vector>
#include <chrono>
#include <omp.h>


// Функция для вычисления скалярного произведения части векторов A и B
void dotProduct(const std::vector<int>& A, const std::vector<int>& B, int start, int end, long long& result) {
    for (int i = start; i < end; ++i) {
        result += A[i] * B[i];
    }
}

int main() {
    setlocale(LC_ALL, "ru");
    srand(time(nullptr));
    // Размеры векторов
    std::vector<int> vector_lengths = { 10000, 100000, 1000000, 10000000 };
    int num_threads = 10;

    // Измерение времени для каждой длины векторов
    for (int length : vector_lengths) {
        std::vector<int> A(length);
        std::vector<int> B(length);

        // Заполнение векторов случайными числами от 0 до 100
        for (int i = 0; i < length; ++i) {
            A[i] = rand() % 101;
            B[i] = rand() % 101;
        }

        long long result = 0;

        // Создание и запуск потоков
        auto start_time = std::chrono::high_resolution_clock::now();
#pragma omp parallel num_threads(num_threads)
        {
            int thread_id = omp_get_thread_num();
            int num_threads = omp_get_num_threads();
            int chunk_size = length / num_threads;
            int start = thread_id * chunk_size;
            int end = start + chunk_size;

            // Вычисление скалярного произведения части векторов
            dotProduct(A, B, start, end, result);
        }

        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "Длина векторов: " << length << std::endl;
        std::cout << "Время выполнения: " << duration.count() << " мс" << std::endl;
        std::cout << "Скалярное произведение: " << result << std::endl;
    }

    return 0;
}
