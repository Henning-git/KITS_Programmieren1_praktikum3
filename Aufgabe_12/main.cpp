#include <iostream>
#include <iomanip>
#include <array>
#include <string>

using namespace std;

enum class vertrag_type_t {
    ohne_bindung,
    super_30,
    super_50,
    super_100,
    super_200
};

struct Vertrag {
    vertrag_type_t type;
    string name;
    int grundgebuehr;
    int inklusiv_minuten;
    double preis_pro_minute;
};

array<Vertrag, 5> vertraege;

void init() {
    // Vertrag 1
    vertraege[0].type = vertrag_type_t::ohne_bindung;
    vertraege[0].name = "Ohne Bindung";
    vertraege[0].grundgebuehr = 0;
    vertraege[0].inklusiv_minuten = 0;
    vertraege[0].preis_pro_minute = 0.1;

    // Vertrag 2
    vertraege[1].type = vertrag_type_t::super_30;
    vertraege[1].name = "Super 30";
    vertraege[1].grundgebuehr = 5;
    vertraege[1].inklusiv_minuten = 30;
    vertraege[1].preis_pro_minute = 0.1;

    // Vertrag 3
    vertraege[2].type = vertrag_type_t::super_50;
    vertraege[2].name = "Super 50";
    vertraege[2].grundgebuehr = 6;
    vertraege[2].inklusiv_minuten = 50;
    vertraege[2].preis_pro_minute = 0.09;

    // Vertrag 4
    vertraege[3].type = vertrag_type_t::super_100;
    vertraege[3].name = "Super 100";
    vertraege[3].grundgebuehr = 10;
    vertraege[3].inklusiv_minuten = 100;
    vertraege[3].preis_pro_minute = 0.08;

    // Vertrag 5
    vertraege[4].type = vertrag_type_t::super_200;
    vertraege[4].name = "Super 200";
    vertraege[4].grundgebuehr = 15;
    vertraege[4].inklusiv_minuten = 200;
    vertraege[4].preis_pro_minute = 0.07;
}

void print_table() {
    // for each line of output
    for(int line = 0; line < 29; line++) {
        int minuten = (line - 3) * 10;

        if(line == 0) { // vertrag name
            cout << setw(17) << "";
        }
        else if(line == 1) { // Grundgebühr
            cout << setw(17) << "Grundgebuehr";
        }
        else if(line == 2) { // Inklusiv-Minuten
            cout << setw(17) << "Inklusiv-Minuten";
        }
        else if(line == 3) { // Preis je weitere Minute
            cout << setw(17) << "Preis pro Minute";
        }
        else {
            string str = "mtl. fuer " + to_string(minuten) + "min.";
            cout << setw(17) << str;
        }

        // for each vertrag
        for(Vertrag& vertrag : vertraege) {
            if(line == 0) { // vertrag name
                cout << setw(14) << vertrag.name;
            }
            else if(line == 1) { // Grundgebühr
                string str = to_string(vertrag.grundgebuehr);
                cout << setw(14) << str;
            }
            else if(line == 2) { // Inklusiv-Minuten
                cout << setw(14) << vertrag.inklusiv_minuten;
            }
            else if(line == 3) { // Preis je weitere Minute
                cout << setw(14) << vertrag.preis_pro_minute;
            }
            else {
                double kosten = vertrag.grundgebuehr;

                if(minuten - vertrag.inklusiv_minuten > 0) {
                    kosten += (minuten - vertrag.inklusiv_minuten) * vertrag.preis_pro_minute;
                }

                cout << setw(14) << kosten;
            }
        }
        cout << endl;
    }
}

int main()
{
    init();
    print_table();
    //cout << "Hello World!" << endl;
    return 0;
}
