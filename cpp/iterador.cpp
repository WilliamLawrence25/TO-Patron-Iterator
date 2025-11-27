#include <iostream>
#include <vector>
using namespace std;

class Iterador {
private:
    vector<string> array;
    int cursor = 0;

public:
    Iterador(const vector<string>& arr) : array(arr) {}

    bool has_next() {
        return cursor < array.size();
    }

    string next() {
        return array[cursor++];
    }
};

int main() {
    vector<string> dias = {"lunes", "martes", "miércoles", "jueves", "viernes"};
    Iterador it(dias);

    while (it.has_next()) {
        cout << "Todavía queda un elemento: " << it.next() << endl;
    }

    cout << "Ya he terminado" << endl;
    return 0;
}
