#include <stdio.h>
#include <stdlib.h> 
#include <string.h>
#include <unistd.h> 
#include "temp_api.h"

// Текст справки
static const char* HELP_MSG = 
    "Учебная программа Статистика 0.5\n"
    "Usage: %s [OPTIONS]\n"
    "Параметры:\n"
    "  -h          Показать список команд\n"
    "  -f <file>   Введите CSV-файл с данными\n"
    "  -y <year>   Фильтровать данные по годам (например, 2024)\n"
    "  -m <month>  Фильтровать данные по месяцам (1-12)\n"
    "\n"
    "Пример:\n"
    "  %s -f data.csv -y 2024 -m 5\n";



int main(int argc, char *argv[]) 
{

   
    int opt; // <-- Объявление переменной opt
    char *filename = NULL; // <-- Объявление filename
    int year_filter = 0;    // Инициализация года (0 = все года)
    int month_filter = 0;   // Инициализация месяца (0 = все месяцы)
    int size = 0;
    Statistics* data = NULL; // Объявляем динамический массив

   //Временный статический массив для инциализации
	Statistics temp_data[] = {
    {2023, 12, 31, 23, 59, -10}, // Год, месяц, день, час, минута, температура
    {2024,  1,  1,  0,  0,  5},
    {2024,  1,  5, 12, 30,  9},
    {2024,  2, 15, 12, 30, 25},
    {2024,  5, 15, 12, 30, -50}
				};

// Описания выбора аргументов
   while ((opt = getopt(argc, argv, "hf:m:y:")) != -1) {
        switch (opt) {
            case 'h':
                printf(HELP_MSG, argv[0], argv[0]);
                return 0;
            case 'f':
                filename = optarg;
                break;
            case 'm':
                month_filter = atoi(optarg);
                if (month_filter < 1 || month_filter > 12) {
                    fprintf(stderr, "Ошибка: месяц должен быть от 1 до 12\n");
                    return 1;
                }
                break;
            case 'y':
                year_filter = atoi(optarg);
                break;
            default:
                fprintf(stderr, "Неизвестный аргумент: -%c\n", optopt);
                return 1;
        }
    }


// Загрузка данных из файла
    if (filename) {
        if (parse_csv(filename, &data, &size) == 0) {
            printf("Загружено %d записей из файла: %s\n", size, filename);
        } else {
            fprintf(stderr, "Ошибка загрузки файла\n");
            return 1;
        }
    } else {
        fprintf(stderr, "Укажите файл через -f <filename> или введите -h для справки\n");
        return 1;
    }


// Вывод статистики
    if (month_filter != 0) {
        printf("\nСтатистика за %d месяц %d года:\n", month_filter, year_filter);
        print_month_stats(data, size, year_filter, month_filter);
    } else {
        printf("\nУкажите месяц через -m <1-12>\n");
    }


	// Переносим записи в динамический массив
    for (size_t i = 0; i < sizeof(temp_data)/sizeof(temp_data[0]); i++) {
        Statistics* tmp = add_stat_record(data, &size, temp_data[i]);
        if (!tmp) {
            fprintf(stderr, "Memory allocation error!\n");
            free(data);
            return 1;
        }
        data = tmp;
    }


// Обработка аргументов командной строки
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-h") == 0) {
            printf(HELP_MSG, argv[0], argv[0]);
            return 0; // Выход после вывода справки
        }
    }

    // Остальной код программы
    printf("Программа работает в обычном режиме...\n");




/*
// ТЕСТОВЫЙ ВЫВОД ДАННЫХ 
printf("\nТестовый вывод данных:\n");

	// Добавление записей напрямую
	data = add_stat_record(data, &size, (Statistics){2024, 1, 15, 12, 7, 25});
        // Поля: dddd=2024, mm=1, dd=15, hh=12, mi=7, temperature=25

// Вывод до удаления
    printf("До удаления (записей: %d):\n", size);
    print_statistics(data, size);

    // Удаляем запись с индексом 1 (вторая запись)
    data = remove_stat_record(data, &size, 1);

    // Вывод после удаления
    printf("\nПосле удаления (записей: %d):\n", size);
    print_statistics(data, size);


   // Сортировка по дате
    bubble_sort_by_date(data, size);
    printf("\nПосле сортировки по дате:\n");
    print_statistics(data, size);

    // Сортировка по температуре
    bubble_sort_by_temp(data, size);
    printf("\nПосле сортировки по температуре:\n");
    print_statistics(data, size);


    // Вывод результатов
    printf("Total records: %d\n", size);
    print_statistics(data, size);

    print_month_stats(data, size, 2024, 1); //Среднемесечная температура 
    print_month_min_temp(data, size, 2024, 1); // минимальная температура в текущем месяце
    print_month_max_temp(data, size, 2024, 2); // максимальная температура в текущем месяце

    print_year_avg_temp(data, size, 2024);  // Средне годоваая температура 
    print_year_min_temp(data, size, 2024);	// Минимальная годоваая температура 
    print_year_max_temp(data, size, 2024);	// Максимальная годоваая температура 
*/
    // Сохранение в файл
    if (save_to_csv("data.csv", temp_data, size) == 0) {
        printf("Данные сохранены в data.csv\n");
    } else {
        printf("Ошибка сохранения!\n");
    }

   
    // Освобождение памяти
    free(data);

    return 0;
}