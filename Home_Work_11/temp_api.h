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
void print_month_stats(Statistics *data, int size, int year, int month);
void print_month_min_temp(Statistics *data, int size, int year, int month);
void print_month_max_temp(Statistics *data, int size, int year, int month);

void print_year_avg_temp(Statistics *data, int size, int year); 
void print_year_min_temp(Statistics *data, int size, int year);
void print_year_max_temp(Statistics *data, int size, int year);

#endif