//
// Created by mok_a on 5/21/2023.
//

#include "Repo.h"
#include "Car.h"

vector<string> Repo::split(const string &str, const string &delim) {
    vector<string> result;
    int start = 0;
    int end = str.find(delim);
    while (end != -1) {
        result.push_back(str.substr(start, end - start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    result.push_back(str.substr(start, end - start));
    return result;
}

void Repo::readData() {
    ifstream ins;
    ins.open("../cars.txt");
    string line;
    while(getline(ins,line)){
        int i=0;
        vector<string> r= split(line,"|");
        Car c=Car(r[0],r[1],stoi(r[2]),r[3]);
        cars.push_back(c);
    }
    ins.close();
}

void Repo::addCar(Car c) {
    cars.push_back(c);
}
