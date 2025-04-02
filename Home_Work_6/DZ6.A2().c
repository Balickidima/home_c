#include <stdio.h>

//Задача A3 ДЗ
//Составить функцию, возведение числа N в степень P. int power(n, p) и привести пример ее использования.
// N по модулю не превосходящих 1000 и P ≥ 0
//

int power(int n, int p) {
    
    
    
    if (p < 0) return 0; // Обработка отрицательных степеней
    if (p == 0) return 1; // Любое число в степени 0 равно 1
    
    int result = 1;
    for (int i = 0; i < p; i++) {
        result *= n;
    }
    return result;
}

int main() {
    int n, p;
    scanf("%d %d", &n, &p);
    
    printf("%d \n" , power(n, p));
    return 0;
}

