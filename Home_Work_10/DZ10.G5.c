#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Задача G5 ДЗ 10
/*В файле input.txt дана символьная строка не более 1000 символов. Необходимо заменить все буквы "а" на буквы "b" и наоборот, как заглавные, так и строчные. Результат записать в output.txt.

Формат входных данных
Строка из маленьких и больших английских букв, знаков препинания и пробелов.
*/


void two_word() {
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");
    char line[1001]; // Максимальная длина строки + '\0'

    if (!inputfile || !outputfile) {
        if (inputfile) fclose(inputfile);
        if (outputfile) fclose(outputfile);
        return;
    }

    if (fgets(line, sizeof(line), inputfile)) {
        // Удаляем символ перевода строки
        line[strcspn(line, "\n")] = '\0';

        // Замена символов a <-> b и A <-> B
        for (int i = 0; line[i] != '\0'; i++) {
            switch (line[i]) {
                case 'a': line[i] = 'b'; break;
                case 'b': line[i] = 'a'; break;
                case 'A': line[i] = 'B'; break;
                case 'B': line[i] = 'A'; break;
                // Остальные символы остаются без изменений
            }
        }

        // Запись результата
        fprintf(outputfile, "%s", line);
    }

    fclose(inputfile);
    fclose(outputfile);
}

int main() {
    two_word();
    return 0;
}
