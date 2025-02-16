#include <stdio.h>
#include <inttypes.h>

//Задача А17 4 Дp
// времена года
//


int main (void)
{
     int  a; //~ Произвольное целое число

     scanf("%d", &a); //~Ожидает ввода знаений переменных от пользователя

    if (a>=1 && a<=2) printf ("winter"); // тогда выводим Зима
    if (a==12) printf ("winter"); // тогда выводим Зима

    if (a>=3 && a<=5) printf ("spring"); // тогда выводим Весна
    if (a>=6 && a<=8) printf ("summer"); // тогда выводим Лето
    if (a>=9 && a<=11) printf ("autumn"); // тогда выводим Осень

    if (a<=0 || a>=13) printf ("the month does not exist"); // Обработка исключения

    return 0;
}

