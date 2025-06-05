#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>

using namespace std;


class Addres {

private:

    string city;
    string street;
    string house;
    string flat;


public:

    void setinfo(string city, string street, string house, string flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }

    string outprep() {
        string block1 = city + ", " + street + ", ";
        string block2 = house + ", " + flat;


        return block1 + block2;
    }

    Addres(string city, string street, string house, string flat) {
        this->city = city;
        this->street = street;
        this->house = house;
        this->flat = flat;
    }
};





int main() {


    string city;
    string street;
    string house;
    string flat;
    int s;

    ifstream fin;
    fin.open("in.txt");
    if (!fin.is_open()) {
        cout << "Файл не открылся >:(";
    }
    fin >> s;


    ofstream fout("out.txt");
    fout << s << "\n";

    string* storage = new string[s + 1];

    fin >> city;
    fin >> street;
    fin >> house;
    fin >> flat;

    Addres adr(city, street, house, flat);
    storage[0] = adr.outprep();

    for (int i = 1; i < s; i++) {
        fin >> city;
        fin >> street;
        fin >> house;
        fin >> flat;

        adr.setinfo(city, street, house, flat);
        storage[i] = adr.outprep();
    }

    sort(storage, storage+s);


    for (int i = 0; i < s; i++) {
        fout << storage[i] << "\n";
    }

    delete[] storage;
    return 0;
}
