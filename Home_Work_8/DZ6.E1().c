#include <stdio.h>

//Задача E1 ДЗ
//Ввести c клавиатуры массив из 5 элементов, найти среднее арифметическое всех элементов массива.

//Формат входных данных
//5 целых не нулевых чисел через пробел

int main() {
    int mass[5];
    int summ = 0;
    double otvet;
    
    // Чтение пяти чисел
    for (int i = 0; i < 5; i++) 
    {
        scanf("%d", &mass[i]);
        summ = mass[i] + summ;
    }
    
    // Вычисление среднего арифметического
   otvet = (double)summ / 5.0;
    
    // Вывод результата с тремя знаками после запятой
    printf("%.3f\n", otvet);
    
    return 0;
}

