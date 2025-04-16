#include <stdio.h>
#include <locale.h>  // Добавляем для работы с локалями
#include "temp_api.h"

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

// Заглушка для месячной статистики
void print_month_stats(Statistics *data, int size, int year, int month) 
{
    (void)data; // Явно указываем, что параметр не используется
    (void)size; // (для подавления предупреждения)
    (void)year;
    (void)month;
    printf("\nMonthly stats for %d-%02d:\n", year, month);
    printf("Average temperature: [calculation in progress]\n");
    printf("Min temperature:     [calculation in progress]\n");
    printf("Max temperature:     [calculation in progress]\n");
}

// Заглушка для минимальной температуры месяца
void print_month_min_temp(Statistics *data, int size, int year, int month) 
{
    (void)data; // Явно указываем, что параметр не используется
    (void)size; // для подавления предупреждения
    (void)year;
    (void)month;

    printf("\nMinimum temperature for %d-%02d:\n", year, month);
    printf("[Not implemented yet] Check back later!\n");
    printf("Expected format: MIN TEMP = -15°C at 2024-01-15 03:45\n");
}

// Заглушка для максимальной температуры месяца
void print_month_max_temp(Statistics *data, int size, int year, int month) 
{
    (void)data; 
    (void)size; 
    (void)year; 
    (void)month;

    printf("\nMaximum temperature for %d-%02d:\n", year, month);
    printf("[Not implemented yet] Check back later!\n");
    printf("Expected format: MAX TEMP = +35°C at 2024-07-20 15:00\n");
}

// Заглушка для годовой статистики

void print_year_avg_temp(Statistics *data, int size, int year) 
{
    (void)data; (void)size; (void)year;
    printf("\nAverage annual temperature for %d:\n", year);
    printf("[Not implemented yet] Coming soon!\n");
    printf("Expected format: YEAR 2024 AVG TEMP = +5.3°C\n");
}

// Заглушка для минимальноей температуры за год  статистики
void print_year_min_temp(Statistics *data, int size, int year) 
{
    (void)data; (void)size; (void)year;
    printf("\nAnnual minimum temperature for %d:\n", year);
    printf("[Not implemented] Data analysis in progress\n");
    printf("Expected format: YEAR 2024 MIN TEMP = -25°C at 2024-01-20 05:30\n");
}

// Заглушка для максимальной  статистики за год
void print_year_max_temp(Statistics *data, int size, int year) 
{
    (void)data; (void)size; (void)year;
    printf("\nAnnual maximum temperature for %d:\n", year);
    printf("[Not implemented] Data analysis in progress\n");
    printf("Expected format: YEAR 2024 MAX TEMP = +40°C at 2024-07-15 14:45\n");
}