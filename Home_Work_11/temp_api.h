#ifndef TEMP_API_H
#define TEMP_API_H

// Структура для хранения данных
typedef struct {
    int dddd;       // Год
    int mm;         // Месяц
    int dd;         // День
    int hh;         // Часы
    int mi;         // Минуты
    int temperature;
} Statistics;

// Прототипы функций
void print_statistics(Statistics *data, int size);
void print_month_stats(Statistics *data, int size, int year, int month); //Среднемесечная температура 
void print_month_min_temp(Statistics *data, int size, int year, int month); //минимум за месяц
void print_month_max_temp(Statistics *data, int size, int year, int month); //максимум за месяц

void print_year_avg_temp(Statistics *data, int size, int year); //Средне годовая температура 
void print_year_min_temp(Statistics *data, int size, int year); //минимум за год
void print_year_max_temp(Statistics *data, int size, int year); //максимум за год

Statistics* add_stat_record(Statistics* arr, int* size, Statistics new_record); //прототип добовления записи в масив
Statistics* remove_stat_record(Statistics* arr, int* size, int index); //прототип добовления записи в масив


void bubble_sort_by_date(Statistics *arr, int size);// Сортировка по дате/времени (возрастание)
void bubble_sort_by_temp(Statistics *arr, int size);// Сортировка по температуре (возрастание)


int save_to_csv(const char* filename, Statistics* data, int size);// Сохранить массив в CSV
int parse_csv(const char* filename, Statistics** arr, int* size);// Загрузка данных из CSV

void print_month_stats(Statistics *data, int size, int year, int month);// Вывод статистики за месяц 

#endif