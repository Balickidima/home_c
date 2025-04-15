#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Задача G2 ДЗ 10
/*В файле input.txt дана строка из не более 1000 символов. Показать номера символов, совпадающих с последним символом строки.
Результат записать в файл output.txt

Формат входных данных
Строка из не более 1000 символов
*/


void find_last_char_positions(const char *str, FILE *output) {
    int length = strlen(str);
    
    // Удаление завершающих переносов строки
    while (length > 0 && (str[length-1] == '\n' || str[length-1] == '\r')) {
        length--;
    }
    
    // Если строка пустая или состоит из одного символа
    if (length <= 1) return;
    
    char target = str[length-1]; // Последний символ
    int first = 1; // Флаг для первого вывода
    
    // Проход по всем символам, кроме последнего
    for (int i = 0; i < length-1; i++) {
        if (str[i] == target) {
            if (first) {
                fprintf(output, "%d", i);
                first = 0;
            } else {
                fprintf(output, " %d", i);
            }
        }
    }
}

int main() {
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");
    char buffer[1001]; // +1 для '\0'

    if (!inputfile || !outputfile) {
        printf("Ошибка открытия файлов!\n");
        return 1;
    }

    // Чтение строки из файла
    if (!fgets(buffer, sizeof(buffer), inputfile)) {
        printf("Файл пуст!\n");
        return 1;
    }

    find_last_char_positions(buffer, outputfile);

    fclose(inputfile);
    fclose(outputfile);
    return 0;
}
