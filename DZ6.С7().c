#include <stdio.h>

//Задача С7 ДЗ
//Составить функцию, которая переводит число N из десятичной системы счисления в P-ичную систему счисления.
//Два целых числа. N ≥ 0 и 2 ≤ P ≤ 9


int perevod(int n, int p) 
{
    if (n == 0) return 0;  // при нуле выводим всегда 0 
    
    int ostatki[32]; // Массив для хранения остатков
    int i = 0; // Счётчик цифр
    // Собираем остатки в обратном порядке
    
    while (n > 0) {
        ostatki[i++] = n % p;
        n = n / p;
    }
    
    // Собираем результат в правильном порядке
    int result = 0;
    for (int j = i - 1; j >= 0; j--) {
        result = result * 10 + ostatki[j];
    }
    
    return result;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    printf("%d", perevod(n, p));
    return 0;
}

