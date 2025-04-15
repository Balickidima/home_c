#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Задача G2 ДЗ 10
/*Считать число N из файла input.txt. Сформировать строку из N символов. N четное число, не превосходящее 26. На четных позициях должны находится четные цифры в порядке возрастания, кроме 0, на нечетных позициях - заглавные буквы в порядке следования в английском алфавите. Результат записать в файл output.txt

Формат входных данных
Четное N ≤ 26
*/


void generate_string(int N, char *result) {
    char current_char = 'A'; // Начинаем с буквы 'A'
    int current_num = 2;     // Начинаем с цифры 2
    for (int i = 0; i < N; i++) {
        if (i % 2 == 0) {    // Четные позиции (0, 2, 4...) для букв
            result[i] = current_char++;
        } else {             // Нечетные позиции (1, 3, 5...) для цифр
            result[i] = current_num + '0';
            current_num += 2;
            if (current_num > 8) current_num = 2; // Цикл 2→4→6→8→2
        }
    }
    result[N] = '\0'; // Завершающий нулевой символ
}

int main() {
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");
    int N;
    
    if (!inputfile || !outputfile) {
        printf("Ошибка открытия файлов!\n");
        return 1;
    }
    
    // Чтение числа N из файла
    if (fscanf(inputfile, "%d", &N) != 1) {
        printf("Ошибка чтения N!\n");
        return 1;
    }
    
    // Проверка на четность и ограничение длины
    if (N % 2 != 0 || N > 26) {
        printf("Некорректное значение N!\n");
        return 1;
    }
    
    char *result = (char*)malloc(N + 1); // Память под строку
    generate_string(N, result);          // Генерация строки
    fprintf(outputfile, "%s", result);         // Запись в файл
    
    free(result);
    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
