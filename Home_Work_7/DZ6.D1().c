#include <stdio.h>

//Задача D1 ДЗ
//Составить рекурсивную функцию, печать всех чисел от 1 до N

//Формат входных данных
//Одно натуральное число

void print_n(int n) {
    if (n == 1) 
    {
        printf("1"); //что бы не было бесконечной рекурсии
    } 
    else 
    {
        print_n(n - 1);
        printf(" %d", n);
    }
}

int main() {
    int n;
    scanf("%d", &n); //~Ожидает ввода  от пользователя
    
    if (n >= 1)  //Проверяем что число натуральное 
    {
        print_n(n);
    }
    
    return 0;
}

