#include <stdio.h>
#include <locale.h>  // Добавляем для работы с локалями
#include "temp_api.h"
#include <stdlib.h> // Для работы realloc

void print_statistics(Statistics *data, int size) 
{
    setlocale(LC_ALL, "en_US.UTF-8");
    for (int i = 0; i < size; i++) 
	{
        printf("[%04d-%02d-%02d %02d:%02d] Temp: %3d°C\n",
               data[i].dddd, data[i].mm, data[i].dd,
               data[i].hh, data[i].mi,
               data[i].temperature);
    	}
}



//  минимальная температура месяца
void print_month_min_temp(Statistics *data, int size, int year, int month) 
{
    int min_temp = 0;
    int found = 0;
    int min_index = -1;

    // Ищем первую запись за указанный месяц и год
    for (int i = 0; i < size; i++) 
    {
        if (data[i].dddd == year && data[i].mm == month) 
	{
            min_temp = data[i].temperature;
            min_index = i;
            found = 1;
            break;
        }
    }

    // Если записи не найдены
    if (!found) 
    {
        printf("\nНет данных за указанный %d-%02d\n", year, month);
        return;
    }

    // Ищем минимальную температуру
    for (int i = min_index + 1; i < size; i++) 
    {
        if (data[i].dddd == year && 
            data[i].mm == month && 
            data[i].temperature < min_temp) 
        {
            min_temp = data[i].temperature;
            min_index = i;
        }
    }

    // Форматированный вывод
    printf("\nМинимальная температура %d-%02d:\n", year, month);
    printf("MIN TEMP = %d°C at %04d-%02d-%02d %02d:%02d\n",
           min_temp,
           data[min_index].dddd,
           data[min_index].mm,
           data[min_index].dd,
           data[min_index].hh,
           data[min_index].mi);
}

//  максимальная температуры месяца
void print_month_max_temp(Statistics *data, int size, int year, int month) 
{
    int max_temp = 0;
    int found = 0;
    int max_index = -1;

    // Поиск первой записи за указанный месяц
    for (int i = 0; i < size; i++) 
	{
        if (data[i].dddd == year && data[i].mm == month) 
	{
            max_temp = data[i].temperature;
            max_index = i;
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nНет данных за указанный %d-%02d\n", year, month);
        return;
    }

    // Поиск максимальной температуры
    for (int i = max_index + 1; i < size; i++) 
    {
        if (data[i].dddd == year && 
            data[i].mm == month && 
            data[i].temperature > max_temp) 
        {
            max_temp = data[i].temperature;
            max_index = i;
        }
    }

    // Вывод в формате аналогичном минимальной температуре
    printf("\nMaximum temperature for %d-%02d:\n", year, month);
    printf("MAX TEMP = %d°C at %04d-%02d-%02d %02d:%02d\n",
           max_temp,
           data[max_index].dddd,
           data[max_index].mm,
           data[max_index].dd,
           data[max_index].hh,
           data[max_index].mi);
   }

// для годовой статистики
void print_year_avg_temp(Statistics *data, int size, int year) 
{
    int sum = 0;
    int count = 0;
    
    // Суммируем температуры за указанный год
    for (int i = 0; i < size; i++) 
    {
        if (data[i].dddd == year) 
        {
            sum += data[i].temperature;
            count++;
        }
    }
    
    // Обработка отсутствия данных
    if (count == 0) 
    {
        printf("\nNo temperature data available for year %d\n", year);
        return;
    }
    
    // Расчет и вывод средней температуры
    float avg_temp = (float)sum / count;
    printf("\nAverage annual temperature for %d:\n", year);
    printf("YEAR %d AVG TEMP = %+.1f°C\n", year, avg_temp);
}

// минимальноей температуры за год  статистики
void print_year_min_temp(Statistics *data, int size, int year) 
    {
    int min_temp = 0;
    int found = 0;
    int min_index = -1;

    // Ищем первую запись за указанный год
    for (int i = 0; i < size; i++) 
	{
        if (data[i].dddd == year) 
	{
            min_temp = data[i].temperature;
            min_index = i;
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nНет данных за указанный год %d\n", year);
        return;
    }

    // Ищем абсолютный минимум за год
    for (int i = min_index + 1; i < size; i++) 
	{
        if (data[i].dddd == year && 
            data[i].temperature < min_temp) 
        {
            min_temp = data[i].temperature;
            min_index = i;
        }
    }

    // Форматированный вывод
    printf("\nAnnual minimum temperature for %d:\n", year);
    printf("MIN TEMP = %d°C at %04d-%02d-%02d %02d:%02d\n",
           min_temp,
           data[min_index].dddd,
           data[min_index].mm,
           data[min_index].dd,
           data[min_index].hh,
           data[min_index].mi);
}

// Максимальной  статистики за год
void print_year_max_temp(Statistics *data, int size, int year) 
{
    int max_temp = 0;
    int found = 0;
    int max_index = -1;

    // Ищем первую запись за указанный год
    for (int i = 0; i < size; i++) 
     {
        if (data[i].dddd == year) 
	{
            max_temp = data[i].temperature;
            max_index = i;
            found = 1;
            break;
        }
    }

    if (!found) 
    {
        printf("\nНет данных за указанный год%d\n", year);
        return;
    }

    // Ищем абсолютный максимум за год
    for (int i = max_index + 1; i < size; i++) 
    {
        if (data[i].dddd == year && 
            data[i].temperature > max_temp) 
        {
            max_temp = data[i].temperature;
            max_index = i;
        }
    }

    // Форматированный вывод
    printf("\nAnnual maximum temperature for %d:\n", year);
    printf("MAX TEMP = %d°C at %04d-%02d-%02d %02d:%02d\n",
           max_temp,
           data[max_index].dddd,
           data[max_index].mm,
           data[max_index].dd,
           data[max_index].hh,
           data[max_index].mi);
}


Statistics* add_stat_record(Statistics* arr, int* size, Statistics new_record) 
{
    // Увеличиваем размер массива на 1
    Statistics* new_arr = realloc(arr, (*size + 1) * sizeof(Statistics));
    
    if (!new_arr) {
        // Обработка ошибки выделения памяти
        return NULL;
    }
    
    // Добавляем новую запись в конец
    new_arr[*size] = new_record;
    (*size)++; // Увеличиваем счетчик размера
    
    return new_arr; // Возвращаем новый указатель на массив
}

Statistics* remove_stat_record(Statistics* arr, int* size, int index) 
    {
    // Проверка корректности индекса
    if (index < 0 || index >= *size) {
        fprintf(stderr, "Ошибка: Некорректный индекс для удаления!\n");
        return arr; // Возвращаем исходный массив
    }

    // Сдвигаем элементы справа от индекса на 1 позицию влево
    for (int i = index; i < *size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    // Уменьшаем размер массива
    Statistics* new_arr = realloc(arr, (*size - 1) * sizeof(Statistics));
    if (!new_arr) {
        fprintf(stderr, "Ошибка перераспределения памяти!\n");
        return arr; // Возвращаем исходный массив
    }

    (*size)--; // Обновляем размер
    return new_arr;
}

//Описания сортировки
// Вспомогательная функция для сравнения дат и времени
static int compare_dates(const Statistics *a, const Statistics *b) 
{
    if (a->dddd != b->dddd) return a->dddd - b->dddd;    // Год
    if (a->mm != b->mm) return a->mm - b->mm;            // Месяц
    if (a->dd != b->dd) return a->dd - b->dd;            // День
    if (a->hh != b->hh) return a->hh - b->hh;            // Часы
    return a->mi - b->mi;                                // Минуты
}

// Сортировка по дате/времени (от старых к новым)
void bubble_sort_by_date(Statistics *arr, int size) 
{
    for (int i = 0; i < size - 1; i++) 
	{
        for (int j = 0; j < size - i - 1; j++) 
	{
            if (compare_dates(&arr[j], &arr[j+1]) > 0) 
	{
                // Обмен местами
                Statistics temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Сортировка по температуре (от меньшей к большей)
void bubble_sort_by_temp(Statistics *arr, int size) 
{
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++)
 {
            if (arr[j].temperature > arr[j+1].temperature) 
{
                // Обмен местами
                Statistics temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Сохранить масив структур в файл
int save_to_csv(const char* filename, Statistics* data, int size) {
    if (!filename || !data || size <= 0) {
        fprintf(stderr, "Ошибка: Некорректные параметры!\n");
        return -1;
    }

    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("Ошибка открытия файла");
        return -1;
    }

    // Заголовок CSV
    fprintf(file, "Year,Month,Day,Hour,Minute,Temperature\n");

    // Запись данных
    for (int i = 0; i < size; i++) 
	{
        fprintf(file, "%04d,%02d,%02d,%02d,%02d,%d\n",
                data[i].dddd,
                data[i].mm,
                data[i].dd,
                data[i].hh,
                data[i].mi,
                data[i].temperature);
    }

    fclose(file);
    return 0; // Успех
}

//Реализация загрузки в масив структур из файла 
int parse_csv(const char* filename, Statistics** arr, int* size)
 {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Ошибка открытия файла");
        return -1;
    }

    char line[256];
    int line_num = 0;
    *size = 0;

    // Пропускаем заголовок (первую строку)
    if (fgets(line, sizeof(line), file)) 
	{ 
        line_num++;
    }

    while (fgets(line, sizeof(line), file)) 
{ 
        line_num++;
        int year, month, day, hour, minute, temp;
        
        // Парсим строку
        if (sscanf(line, "%d,%d,%d,%d,%d,%d", 
                   &year, &month, &day, &hour, &minute, &temp) != 6) 
        {
            fprintf(stderr, "Ошибка в строке %d: некорректный формат\n", line_num);
            continue;
        }

        // Валидация данных
        if (year < 1900 || year > 2100 ||
            month < 1 || month > 12 ||
            day < 1 || day > 31 ||
            hour < 0 || hour > 23 ||
            minute < 0 || minute > 59 ||
            temp < -100 || temp > 100) 
        {
            fprintf(stderr, "Ошибка в строке %d: некорректные данные\n", line_num);
            continue;
        }

        // Добавляем запись в массив
        Statistics record = {year, month, day, hour, minute, temp};
        Statistics* tmp = add_stat_record(*arr, size, record);
        if (!tmp) {
            fprintf(stderr, "Ошибка выделения памяти\n");
            fclose(file);
            return -1;
        }
        *arr = tmp;
    }

    fclose(file);
    return 0; // Явный возврат значения
}

//Реализация вывода статистики за указанный месяц
void print_month_stats(Statistics *data, int size, int year, int month) 
{
    int sum = 0, count = 0;
    int min_temp = 100, max_temp = -100;

    for (int i = 0; i < size; i++) {
        if ((year == 0 || data[i].dddd == year) && 
            (month == 0 || data[i].mm == month)) 
        {
            sum += data[i].temperature;
            count++;
            if (data[i].temperature < min_temp) min_temp = data[i].temperature;
            if (data[i].temperature > max_temp) max_temp = data[i].temperature;
        }
    }

    if (count == 0) {
        printf("Нет данных за указанный период\n");
        return;
    }

    printf("Средняя температура: %.1f°C\n", (float)sum / count);
    printf("Минимальная температура: %d°C\n", min_temp);
    printf("Максимальная температура: %d°C\n", max_temp);
}
