#include <stdio.h>

//Задача F1 ДЗ 9
/*Написать только одну функцию, которая сортирует массив по возрастанию. Необходимо реализовать только одну функцию, всю программу составлять не надо.
Строго согласно прототипу. Имя функции и все аргументы должны быть: void sort_array(int size, int a[]).
Всю программу загружать не надо, только одну эту функцию. Можно просто закомментировать текст всей программы, кроме данной функции.

Формат входных данных
Функция принимает на вход, первый аргумент - размер массива, второй аргумент - адрес нулевого элемента.
*/


// Объявление функции сортировки
void sort_array(int size, int a[]);



// Реализация сортировки пузырьком
void sort_array(int size, int a[]) 
{
    for (int i = 0; i < size-1; i++) 
    {
        for (int j = 0; j < size-i-1; j++) 
        {
            if (a[j] > a[j+1]) //Сравневаем и  Меняем местами значения если не попарядку
            {
                int temp = a[j];
                a[j] = a[j+1];
                a[j+1] = temp;
            }
        }
    }
}

// Функция для вывода массива
void print_array(int size, int a[]) 
{
    for (int i = 0; i < size; i++) 
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}

int main() 
{
    int arr1[] = {20,19,4,3,2,1,18,17,13,12,11,16,15,14,10,9,8,7,6,5};
    int size1 = sizeof(arr1)/sizeof(arr1[0]);
    
    printf("do Sartirovki:\n");
    print_array(size1, arr1);
    
    sort_array(size1, arr1);
    
    printf("Posle sartirovki:\n");
    print_array(size1, arr1);
    printf("\n");

    return 0;

}
