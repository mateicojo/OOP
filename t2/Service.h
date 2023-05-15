//
// Created by mok_a on 5/8/2023.
//

#pragma once
#include "Domain.h"
#include <vector>

class Service {
private:
    std::vector<Building*> buildings;
    int size;
public:
    Service(){
        this->size=0;
    }
    void addBuilding(Building& building){
        this->buildings.push_back(&building);
        this->size++;
    }
    std::vector<Building*> getAllBuildings(){
        return this->buildings;
    }
    std::vector<Building*> getAllToBeRestored(){
        std::vector<Building*> toBeRestored;
        return toBeRestored;
    }
    std::vector<Building*> getAllToBeDemolished(){
        return this->buildings;
    }
};
