#include <stdio.h>
//Задача А8 3Д
// Первый вариант решения


int main (void)
{
    int a= 0; //~ Первое значение
    int b= 0; //~ Второе значение
    int c= 0; //~ Третье значение
    int d0=0; //~Промежуточное значение
    int d1=0; //~Промежуточное значение


   scanf("%d %d %d", &a, &b, &c); //~Ожидает ввода знаений переменных от пользователя
    d0 = a + b; // складоваем для определения  кто больше в долнейшем
    d1 = b + c; // складоваем для определения  кто больше в долнейшем

    if (d0>=d1) // Если резултат первого выражения больше
    {
        if (a>=b) printf ("%d ", a); else printf ("%d ", b); // тогда выводим одино значение  из вырожения
    }
    else
    {
        if (b>=c) printf ("%d ", b); else printf ("%d ", c); // тогда выводим одино значение  из вырожения
    }
    return 0;
}

