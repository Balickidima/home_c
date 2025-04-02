#include <stdio.h>



//Задача A4 ДЗ
//Описать функцию вычисления f(x) по формуле:
//f(x)= x*x при -2 ≤ x < 2;
//x*x+4x+5 при x ≥ 2;
//4 при x < -2.
//Используя эту функцию для n заданных чисел, вычислить f(x). Среди вычисленных значений найти наибольшее.


int Vicheslenie_funks(int x) {
    if (x < -2) {
        return 4;
    } else if (x < 2) {
        return x * x;
    } else {
        return x * x + 4 * x + 5;
    }
}

int main() {
    int n, max, flag = 1; //flag для определения первого числа
    
    while(1) {
        scanf("%d", &n);
        if(n == 0) break;
        
        // Инициализируем max первым значением
        if(flag) {
            max = Vicheslenie_funks(n);
            flag = 0;
        } else {
            int result = Vicheslenie_funks(n);
            if(result > max) max = result;
        }
    }
    
    printf("%d", max);
    return 0;
}
