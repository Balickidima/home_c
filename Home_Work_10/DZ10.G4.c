#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//Задача G4 ДЗ 10
/*В файле input.txt даны два слова не более 100 символов каждое, разделенные одним пробелом. Найдите только те символы слов, которые встречаются в обоих словах только один раз. Напечатайте их через пробел в файл output.txt в лексикографическом порядке.

Формат входных данных
Два слова из маленьких английских букв через пробел. Длинна каждого слова не больше 100 символов.
*/


void two_word() {
    FILE *inputfile = fopen("input.txt", "r");
    FILE *outputfile = fopen("output.txt", "w");
    char line[202]; // Максимум 100 + 1 (пробел) + 100 + '\0'
    char word1[101], word2[101];
    int count1[26] = {0}, count2[26] = {0};
    char result[26];
    int result_count = 0;

    if (!inputfile || !outputfile) return; //проверяем, успешно ли открылись оба файла.

    if (fgets(line, sizeof(line), inputfile)) 
    {
        line[strcspn(line, "\n")] = '\0'; // Удаляем символ перевода строки
        char *whitespace = strtok(line, " ");
        if (whitespace) 
        {
			strcpy(word1, whitespace);
		}
			else 
			{ 
				fclose(inputfile); fclose(outputfile); return; 
			}

        whitespace = strtok(NULL, " ");
        
        if (whitespace) 
			{
				strcpy(word2, whitespace);
			}
		else 
			{ 
				fclose(inputfile); fclose(outputfile); return; 
			}
		
		} 
    else 
    { 
		fclose(inputfile); fclose(outputfile); return; 
	}

    // Подсчет частот символов в первом слове
    for (int i = 0; word1[i] != '\0'; i++) {
        if (islower(word1[i])) 
            count1[word1[i] - 'a']++;
    }

    // Подсчет частот символов во втором слове
    for (int i = 0; word2[i] != '\0'; i++) 
    {
        if (islower(word2[i])) 
        {
            count2[word2[i] - 'a']++;
        }
    }

    // Сбор символов, встречающихся ровно 1 раз в обоих словах
    for (char c = 'a'; c <= 'z'; c++) 
    {
        int idx = c - 'a';
        if (count1[idx] == 1 && count2[idx] == 1)
        {
            result[result_count++] = c;
        }
    }

    // Вывод результатов через пробел
    for (int i = 0; i < result_count; i++) 
    {
        if (i > 0) 
			{
			fprintf(outputfile, " ");
			}
        fprintf(outputfile, "%c", result[i]);
    }

    fclose(inputfile);
    fclose(outputfile);
}

int main() {
    two_word();
    return 0;
}
