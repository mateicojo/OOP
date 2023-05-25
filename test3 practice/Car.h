//
// Created by mok_a on 5/21/2023.
//

#pragma once
#include <string>
using namespace std;

class Car{
private:
    string manufacturer;
    string model;
    int year;
    string color;
public:
    Car(string manufacturer, string model, int year, string color){
        this->manufacturer = manufacturer;
        this->model = model;
        this->year = year;
        this->color = color;
    }
    string getManufacturer() const{
        return manufacturer;
    }
    string getModel()const{
        return model;
    }
    int getYear()const{
        return year;
    }
    string getColor()const{
        return color;
    }

    void setManufacturer(string manufacturer){
        this->manufacturer = manufacturer;
    }
    void setModel(string model){
        this->model = model;
    }
    void setYear(int year){
        this->year = year;
    }
    void setColor(string color){
        this->color = color;
    }
};
