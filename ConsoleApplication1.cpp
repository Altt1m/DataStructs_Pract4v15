#include <iostream>;

using namespace std;

// 15.1 | Функція, яка обчислює добуток цифр числа за допомогою рекурсії
int digitProduct(int number)
{
    // Якщо число однозначне, повертаємо його як добуток
    if (number < 10)
    {
        return number;
    }
    // Рекурсивно викликаємо функцію для решти числа
    else
    {
        return (number % 10) * digitProduct(number / 10);
    }
}

void Task1()
{
    int number;
    std::cout << "Input number: ";
    std::cin >> number;

    int product = digitProduct(number);
    std::cout << "Mult of digits of " << number << " = " << product << std::endl;
}

// 15.2 | Дан масив дійсних чисел A розміру N. Напишіть рекурсивну функцію, яка знаходить добуток елементів масиву.
double arrayProduct(double arr[], int size)
{
    // Якщо масив порожній, повертаємо 1
    if (size == 0)
    {
        return 1.0;
    }
    // Множимо перший елемент на добуток решти масиву
    else
    {
        return arr[0] * arrayProduct(arr + 1, size - 1);
    }
}

void Task2()
{
    // Створюємо масив з введеним розміром
    double arr[5];
    std::cout << "Input array elements:\n";
    for (int i = 0; i < 5; ++i)
    {
        std::cin >> arr[i];
    }

    // Обчислюємо добуток елементів масиву та виводимо результат
    double product = arrayProduct(arr, 5);
    std::cout << "Mult of elements = " << (int)product << std::endl;
}

int main()
{
    Task1();
    //Task2();
}
