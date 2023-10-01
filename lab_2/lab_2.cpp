#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
#include <thread>
#include <chrono>

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
        std::vector<std::thread> threads;

        // Создание и запуск потоков
        auto start_time = std::chrono::high_resolution_clock::now();

        int chunk_size = length / num_threads;
        for (int i = 0; i < num_threads; ++i) {
            int start = i * chunk_size;
            int end = (i == num_threads - 1) ? length : (i + 1) * chunk_size;
            threads.emplace_back(dotProduct, std::ref(A), std::ref(B), start, end, std::ref(result));
        }

        // Ожидание завершения всех потоков
        for (auto& thread : threads) {
            thread.join();
        }

        // Измерение времени выполнения
        auto end_time = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);

        std::cout << "Длина векторов: " << length << ", Время выполнения: " << duration.count() << " миллисекунд" << std::endl;
    }

    return 0;
}