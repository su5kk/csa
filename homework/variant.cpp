//------------------------------------------------------------------------------
// main.cpp - Формирование описания задачи и функции по номеру варианта
// дисциплина: Архитектура ВС
// 2021-2022 учебный год
// Номер варианта задания задается параметром, указанным в командной строке
// В результате формируется номер задачи из таблицы задач
// и номер функции обработки контейнера из таблицы функций
//------------------------------------------------------------------------------

#include <stdlib.h>
#include <iostream>
using namespace std;

//------------------------------------------------------------------------------

int main(int argc, char* argv[])
{
    if(argc !=2)
    {
        cout << "Incorrect comman line. Necessary to do: "
                "variant variant_number (from 1 to 350)" << endl;
        exit(1);
    }

    int num = atoi(argv[1]);
    if((num < 1)||(num > 350))
    {
        cout << "Incorrect variant number equal " << argv[1] << "." 
            << endl
            << "Necessary to write variant number from 1 to 350" 
            << endl;
        exit(1);
    }

    cout << "Variant number = " << num << endl;
    
    int num_of_task = (num-1) % 14 + 1;
    int num_of_func = ((num-1) / 14) % 25 + 1;

    cout << "Number of task = " << num_of_task << endl;
    cout << "Number of function = " << num_of_func << endl;

    return 0;
}