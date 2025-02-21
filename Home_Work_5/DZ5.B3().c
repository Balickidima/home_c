#include <stdio.h>
#include <inttypes.h>

//Задача B3 5 ДЗ
//Ввести два целых числа a и b (a ≤ b) и вывести сумму квадратов всех чисел от a до b.
//


int main (void)
{

     int  i;
     int  a,b,c,d;

     a=b=c=d=0;


     scanf("%d %d", &a , &c); //~Ожидает ввода знаений переменных от пользователя
     if (a <= c)
     {
         for (i = a; i <= c; i++)
            {

                d = i*i; //для первого столба
                b = d+b; //сумму квадратов
            }

     }
     else printf (" The number entered  %d >= %d not according to the terms! \n", a , c); // исключение
     printf (" %d ", b); // выводим сумму
    return 0;
}

