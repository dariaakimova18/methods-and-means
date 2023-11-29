#include <iostream>
#include <cstdlib>
#include <ctime>
#include <mpi.h>

int main(int argc, char** argv) {
    setlocale(LC_ALL, "ru");
    // Инициализация MPI
    MPI_Init(&argc, &argv);

    // Получение общего количества процессов и ранга текущего процесса
    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Количество студентов в классе
    const int students_count = 10;

    // Массив для хранения оценок студентов
    int* grades = new int[students_count];

    // Процесс 0 (профессор) генерирует оценки для студентов
    if (world_rank == 0) {
        std::cout << "Профессор находится в аудитории.\n";

        srand(time(nullptr));

        // Генерация оценок для студентов
        for (int student = 0; student < students_count; ++student) {
            grades[student] = rand() % 4 + 2; // Случайная оценка от 2 до 5
            std::cout << "Профессор поставил студенту " << student + 1 << " оценку: " << grades[student] << std::endl;
        }
    }

    // Рассылка оценок студентов всем процессам
    MPI_Bcast(grades, students_count, MPI_INT, 0, MPI_COMM_WORLD);

    // Вывод оценок для студентов (каждый процесс выводит свою оценку)
    if (world_rank != 0) {
        std::cout << "Студент " << world_rank << " получил оценку: " << grades[world_rank - 1] << std::endl;
    }

    // Завершение MPI
    MPI_Finalize();

    // Процесс 0 вычисляет и выводит среднюю оценку по классу
    if (world_rank == 0) {
        double total = 0;
        for (int i = 0; i < students_count; ++i) {
            total += grades[i];
        }

        double average = total / students_count;
        std::cout << "Средний балл: " << average << std::endl;

        // Освобождение выделенной памяти
        delete[] grades;
    }

    return 0;
}
