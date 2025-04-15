#include <stdio.h>

//Задача F2 ДЗ 9
/*Написать только одну функцию, которая ставит в начало массива все четные элементы, а в конец – все нечетные. Не нарушайте порядок следования чисел между собой. Строго согласно прототипу:.
void sort_even_odd(int n, int a[])
*/

// Объявление функции сортировки
void sort_even_odd(int n, int a[]);

// Функция для вывода массива
void print_array(int size, int a[]) {
    for (int i = 0; i < size; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
}

// Реализация функции сортировки
void sort_even_odd(int n, int a[]) {
    int temp[n];
    int index = 0;

    // Собираем четные элементы
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 == 0) {
            temp[index++] = a[i];
        }
    }

    // Собираем нечетные элементы
    for (int i = 0; i < n; i++) {
        if (a[i] % 2 != 0) {
            temp[index++] = a[i];
        }
    }

    // Перезаписываем исходный массив
    for (int i = 0; i < n; i++) {
        a[i] = temp[i];
    }
}


int main() {
    // Пример тестового случая
    int arr[] = {20,19,18,17,16,15,14,13,12,11,10,9,8,7,6,5,4,3,2,1};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("do Sartirovki:\n");
    print_array(size, arr);
    
    sort_even_odd(size, arr);
    
    printf("Posle sartirovki\n");
    print_array(size, arr);

    return 0;
}




