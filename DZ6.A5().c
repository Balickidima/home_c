#include <stdio.h>

//Задача A5 ДЗ
//Составить функцию, которая определяет сумму всех чисел от 1 до N и привести пример ее использования.



int sum(int n) {
    return n * (n + 1) / 2;
}

int main() {
	int a;
	scanf("%d", &a);
    printf("%d", sum(a)); 
    return 0;
}
