#include <stdio.h>
#include <inttypes.h>

//Задача B1 5 ДЗ
// Ввести натуральное число вывести квадраты и кубы всех чисел от 1 до этого числа. Число не превосходит 100.
//


int main (void)
{
     int  b[3]; //в масив резултаты расчёта для вывода
     int  i;
     int  a,c;


     scanf("%d %d", &a , &c); //~Ожидает ввода знаений переменных от пользователя
     if (a <= c)
     {
         for (i = 1; i <= a; i++)
            {
                b[0] = i; //для первого столба
                b[1] = i*i; // в квадрат
                b[2] = i*i*i; //В куб
                printf (" %d %d %d \n", b[0], b[1], b[2]); // тогда выводим
            }

     }
     else printf (" The number entered  %d >= %d not according to the terms! \n", a , c); // исключение
    return 0;
}

