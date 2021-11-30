//
//  main.cpp
//  lab_Zoo_class
//
//  Created by Dmitriy Garkin on 30.11.2021.
//

#include "Zoo.h"
#include "func.h"

int main() {
    //открываем файлы для удобной записи входных и выходных данных
        std::ifstream in = Open_file_in();
        std::ofstream out = Open_file_out();
        /*
        std::ifstream in;
        in.open("/Users/dmitriygarkin/Desktop/яп_лаб_2/задача 2/fin2.txt");
        if(!(in.is_open())) {
            std::cout << "file not find\n";
            exit(0);
        }
        std::ofstream out;
        out.open("/Users/dmitriygarkin/Desktop/яп_лаб_2/задача 2/fout2.txt");
        if(!(out.is_open())) {
            std::cout << "file not find\n";
            exit(0);
        }
    */
        //создем массив зоопарков. пригодится позже
        Zoo * all_data;

        //иллюстрируем работу конструктора без параметров
        Zoo a;
        out << "Конструктор без параметров\n";
        a.Print(out);
        string name, country;
        int count, cost;
        string * data;


        in >> name;
        in >> country;
        in >> count;
        data = new string[count];
        for(int i = 0; i < count; i++) {
            in >> data[i];
        }
        int * time;
        time = new int [4];
        in >> time[0];
        in >> time[1];
        in >> time[2];
        in >> time[3];
        in >> cost;
        //иллюстрируем работу коструктора с параметрами
        Zoo b(name, country, data, count, time, cost);
        out << "конструктор с поравметрами\n";
        b.Print(out);

        //иллюстрируем работу конструктора копирования
        Zoo c(b);
        out << "конструктор копирования\n";
        c.Print(out);

        //иллюстриуем работу изменения переменных
        a.Change_name("Zoo_a");
        string * data_1;
        data_1 = new string[1]{"tiger"};
        a.Change_data(data_1, 1);
        a.Change_cost(10000);
        a.Change_country("USA");
        //иллюстрируем работу вывода переменных
        a.Print_name(out);

        b.Change_name("Zoo_b");
        c.Change_name("Zoo_c");

        //иллюстрируем работу задания 1
        out << b.How_much(40) << std::endl;

        //иллюстрируем работу задания 2
        int all_count = 3;
        all_data = new Zoo[all_count];
        all_data[0] = a;
        all_data[1] = b;
        all_data[2] = c;
        Sort_all_data(all_data, all_count);
        for(int i = 0; i < all_count; i++) {
            out << all_data[i].Get_name() << " ";
        }
        out << std::endl << "_________" << std::endl;

        //иллюстрируем работу задания 3
        Zoo * country_data;
        country_data = new Zoo[all_count];
        int country_count = 0;
        In_country(all_data, country_data, all_count, country_count, "USA");
        for(int i = 0; i < country_count; i++) {
            out << country_data[i].Get_name() << "  ";
        }
        out << std::endl;


        return 0;
}
