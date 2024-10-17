#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;

void Create(int* a, const int size, const int Low, const int High, int i) // Формування масиву
{
    a[i] = Low + rand() % (High - Low + 1);
    if (i < size - 1)
        Create(a, size, Low, High, i + 1);
}

void Print(const int* a, const int size, int i) // Виведення масиву
{
    cout << setw(4) << a[i];
    if (i < size - 1) {
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}
int Count(const int* a, const int size, int i, int N) // Кількість елементів з парними індексами
{
    if (i % 2 == 0)
        N++;
    if (i < size - 1)
        return Count(a, size, i + 1, N);
    else
        return N;
}

int Sum(const int* a, const int size, int i, int S) // Сума елементів з парними індексами
{
    if (i % 2 == 0)
        S += a[i];
    if (i < size - 1)
        return Sum(a, size, i + 1, S);
    else
        return S;
}

double CalculateArithmeticMean(const int* a, const int size, int i, int S, int N) // Обчислення середнього арифметичного
{
    if (i % 2 == 0) {
        S += a[i];
        N++;
    }
    if (i < size - 1)
        return CalculateArithmeticMean(a, size, i + 1, S, N);
    else
        return static_cast<double>(S) / N; 
}

int main()
{
    srand((unsigned)time(NULL)); // Ініціалізація генератора випадкових чисел
    const int n = 21;
    int c[n];
    int Low = 15;
    int High = 85;

    Create(c, n, Low, High, 0);
    Print(c, n, 0);

    // Обчислення середнього арифметичного елементів з парними індексами
    double arithmeticMean = CalculateArithmeticMean(c, n, 0, 0, 0);

    // Виведення результату
    SetConsoleOutputCP(1251); // встановлення кодування Windows-1251 в  потік виведення
    cout << "Середнє арифметичне елементів з парними індексами: " << arithmeticMean << endl;

    return 0;
}
