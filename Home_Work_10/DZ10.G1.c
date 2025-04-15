#include <stdio.h>
#include <string.h>
#include <ctype.h>

//Задача G1 ДЗ 10
/*В файле input.txt дана строка. Вывести ее в файл output.txt три раза через запятую и показать количество символов в ней.

Формат входных данных
Строка из английских букв и пробелов. Не более 100 символов. В конце могут быть незначащие переносы строк.
Формат результата
*/


void process_string(const char *input, char *output) 
{
    // Удаляем символы переноса строки и возврата каретки
    size_t len = strlen(input);
    while (len > 0 && (input[len-1] == '\n' || input[len-1] == '\r')) 
    {
        len--;
    }
    
    // Формируем итоговую строку
    sprintf(output, "%.*s, %.*s, %.*s %zu", 
            (int)len, input, 
            (int)len, input, 
            (int)len, input, 
            len);
}

int main() 
{
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");
    char buffer[102], result[310];

    if (!inputfile || !outputfile) 
    {
        printf("Ошибка открытия файлов!");
        return 1;
    }

    // Чтение строки с обработкой
    if (fgets(buffer, sizeof(buffer), inputfile)) 
    {
        process_string(buffer, result);
        fputs(result, outputfile);
    }

    fclose(inputfile);
    fclose(outputfile);
    return 0;
}

