#include <stdio.h>
//Задача А10 3Д
// берем второй вариант задачи A8 и масштабируем и берем первый элемент масива

int main (void)
{
    int i=0; //~ Счётчик
    int j=0; //~ Счётчик

    int n=5; //~ Количество элементов

    int temp; //~ Переменная для сохрания промежуточных данных

    int a[n]; //~Создадим массив из 3 элементовc

   scanf("%d %d %d %d %d", &a[0], &a[1], &a[2], &a[3], &a[4]); //~Ожидает ввода знаений переменных от пользователя и ложим вмасив

   for(i = 0 ; i < n - 1; i++) // ~Методом пузырька
    {
        for(j = 0 ; j < n - i - 1 ; j++)
        {
            if(a[j] > a[j+1]) { temp = 0 ; temp = a[j]; a[j] = a[j+1] ; a[j+1] = temp;} //Сравневаем и  Меняем местами значения если не попарядку
        }
    }

    printf ("%d", a[0]); // тогда выводим значение первого элемента масива

    return 0;
}

