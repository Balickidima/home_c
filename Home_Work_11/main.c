#include <stdio.h>
#include "temp_api.h"

int main() {
    Statistics temp_data[] = {
        {2023, 12, 31, 23, 59, -10},
        {2024,  1,  1,  0,  0,  5},
        {2024,  1,  5, 12, 30,  7},
        {2024,  2, 15, 12, 30, 25}
    };
    int size = sizeof(temp_data) / sizeof(temp_data[0]);

    printf("Weather Statistics:\n");
    print_statistics(temp_data, size);
    
	//Демонстрация работы заглушек
    print_month_stats(temp_data, size, 2024, 1); //Среднемесечная температура 
    print_month_min_temp(temp_data, size, 2024, 1); // минимальная температура в текущем месяце
    print_month_max_temp(temp_data, size, 2024, 2); // максимальная температура в текущем месяце

    print_year_avg_temp(temp_data, size, 2024);  // Средне годоваая температура 
    print_year_min_temp(temp_data, size, 2024);	// Минимальная годоваая температура 
    print_year_max_temp(temp_data, size, 2024);	// Максимальная годоваая температура 


    return 0;
}