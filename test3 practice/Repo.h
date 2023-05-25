//
// Created by mok_a on 5/21/2023.
//

#pragma once
#include "Car.h"
#include <vector>
#include <fstream>
#include <string>
class Repo{
private:
    vector<Car> cars;
    string filename;
public:
    Repo(){
    }
    vector<string> split(const string& str, const string& delim);

    void addCar(Car c);
    vector<Car> getCars(){
        return cars;
    }
    void readData();
};
