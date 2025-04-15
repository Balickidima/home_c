#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Задача F4 ДЗ 9
/*Написать только одну функцию. Всю программу отправлять не надо. Вывести в порядке возрастания цифры, входящие в строку. Цифра - количество. Функция должно строго соответствовать прототипу:
void print_digit(char s[])

Формат входных данных
Строка из английских букв, пробелов, знаков препинания и цифр
*/

void print_digit(char s[]) {
    int counts[10] = {0}; // Массив для подсчета цифр 0-9

    // Подсчет цифр в строке
    for (int i = 0; s[i] != '\0'; i++) {
        if (isdigit(s[i])) {
            int digit = s[i] - '0';
            counts[digit]++;
        }
    }

    // Вывод цифр в порядке возрастания
    for (int i = 0; i < 10; i++) {
        if (counts[i] > 0) {
            printf("%d %d\n", i, counts[i]);
        }
    }
}

int main() {
    char input[1000];
    
    // Читаем строки с пробелами
    if (fgets(input, sizeof(input), stdin) == NULL) {
        return 1;
    }

    // Удаление символа перевода строки
    for (int i = 0; input[i] != '\0'; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }

    print_digit(input);
    return 0;
}


