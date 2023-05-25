//
// Created by mok_a on 5/21/2023.
//

#pragma once
#include "Car.h"
#include "Repo.h"

class Service{
private:
    Repo repo;
public:
    Service(){

    }
    void addCar(string manufacturer, string model, int year, string color){
        Car c(manufacturer,model,year,color);
        repo.addCar(c);
    }
    Repo& getRepo(){
        return this->repo;
    }
};
