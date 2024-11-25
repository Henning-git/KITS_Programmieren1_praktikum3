#include <iostream>
#include <limits>
#include <vector>
#include <string>
#include <variant>

using namespace std;

template<class T>
void input_value(vector<T>& buffer) {
    // clear console
    system("cls");

    cout << "Gib einen Wert ein: ";

    T input;
    cin >> input;
    buffer.push_back(input);
}

template<class T>
void print_buffer(const vector<T>& buffer) {
    // clear console
    system("cls");

    for(auto value : buffer) {
        cout << value << " ";
    }

    // wait for exit
    cout << endl
         << "Back: beliebiges ZEICHEN + ENTER";

    char value;
    cin >> value;
}

template<class T>
void find_value(const vector<T>& buffer) {
    // clear console
    system("cls");

    cout << "Nach welchem Wert soll ich suchen: ";
    T input;
    cin >> input;

    bool found = false;
    for(auto value : buffer) {
        if(value == input) {
            cout << "Ist enthalten" << endl;
            found = true;
            break;
        }
    }
    if(!found) {
        cout << "Ist nicht enthalten" << endl;
    }

    // wait for exit
    // ignore all chars until line break
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl
         << "Back: beliebiges ZEICHEN + ENTER";

    char value;
    cin >> value;
}

template<class T>
void check_sort(const vector<T>& buffer) {
    // clear console
    system("cls");

    if(buffer.size() <= 1) {
        cout << "Der Speicher muss 2 Werte enthalten." << endl;
    }
    else {
        bool sorted = true;
        for(int i = 1; i < buffer.size(); i++) {
            if(buffer[i-1] > buffer[i]) {
                cout << "Nicht sortiert" << endl;
                sorted = false;
                break;
            }
        }
        if(sorted) {
            cout << "Sortiert" << endl;
        }
    }

    // wait for exit
    // ignore all chars until line break
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << endl
         << "Back: beliebiges ZEICHEN + ENTER";

    char value;
    cin >> value;
}

template<class T>
void main_menue(vector<T>& buffer) {
    // main loop
    while(true) {
        // clear console
        system("cls");

        // print menu
        cout << "Hauptmenue" << endl
             << "Werte Verwalten:" << endl
             << "  (1) Wert eingeben" << endl
             << "  (2) Werte ausgeben" << endl
             << "  (3) Wert suchen" << endl
             << "  (4) Auf Sortierung pruefen" << endl
             << "  (x) Ende" << endl;

        // ignore all chars until line break
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        char option;
        cin >> option;

        if(cin.fail()) {
            // reset cin errors
            cin.clear();

            // ignore all chars until line break
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch(option) {
        case '1':
            input_value(buffer);
            break;

        case '2':
            print_buffer(buffer);
            break;

        case '3':
            find_value(buffer);
            break;

        case '4':
            check_sort(buffer);
            break;

        case 'x':
            return;

        default:
            continue;
        }
    }
}

int main() {
    while(true) {
        // clear console
        system("cls");

        // print menu
        cout << "Fuer welchen Datentypen moechtest du das Programm ausfuehren?" << endl
             << "Datentyp:" << endl
             << "  (1) int" << endl
             << "  (2) float" << endl
             << "  (3) string" << endl;

        char option;
        cin >> option;

        if(cin.fail()) {
            // reset cin errors
            cin.clear();

            // ignore all chars until line break
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            continue;
        }

        switch(option) {
        case '1': {
            vector<int> buffer;
            main_menue(buffer);
            return 0;
        }

        case '2': {
            vector<float> buffer;
            main_menue(buffer);
            return 0;
        }

        case '3': {
            vector<string> buffer;
            main_menue(buffer);
            return 0;
        }

        default:
            continue;
        }
    }
}
