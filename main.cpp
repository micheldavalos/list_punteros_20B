#include <iostream>
#include <list>

using namespace std;

int main() {
    list<int*> punteros;

    for (size_t i = 0; i < 10; i++)
    {
        // int *e = new int(i);
        // punteros.push_back(e);
        punteros.push_back(new int(i));
    }

    // for (auto it=punteros.begin(); it != punteros.end(); it++) {
    //     auto &e = *it; // int*
    //     cout << *e << endl;
    // }

    for (auto const &e: punteros) {
        cout << *e << endl;
    }
    
    list<int*> copia(punteros);

    punteros.remove_if([](int *e){
        if (*e % 2 == 0) {
            delete e;
            return true;
        } else {
            return false;
        }
    });

    cout << "Punteros: " << endl;
    for (auto const &e: punteros) {
        cout << *e << endl;
    }
    cout << "Copia: " << endl;
    for (auto const &e: copia) {
        cout << *e << endl;
    }


    return 0;
}