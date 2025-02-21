#include <stdio.h>
#include <inttypes.h>

//Задача B1 5 ДЗ
//Ввести два целых числа a и b (a ≤ b) и вывести квадраты всех чисел от a до b.
//


int main (void)
{

     int  i;
     int  a,c,d;


     scanf("%d %d", &a , &c); //~Ожидает ввода знаений переменных от пользователя
     if (a <= c)
     {
         for (i = a; i <= c; i++)
            {

                d = i*i; //для первого столба

                printf (" %d ", d); // тогда выводим в стоку без переноса
            }

     }
     else printf (" The number entered  %d >= %d not according to the terms! \n", a , c); // исключение
    return 0;
}

