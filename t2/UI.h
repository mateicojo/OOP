//
// Created by mok_a on 5/8/2023.
//

#pragma once
#include "Service.h"
#include <iostream>
class UI{
private:
    Service ser;
public:
    UI(Service ser){
        this->ser=ser;
    }
    void printMenu(){
        std::cout<<"1. Add a building\n";
        std::cout<<"2. Show all buildings.\n";
        std::cout<<"3. Show all buildings that can be demolished.\n";
    }
    void start(){
        int op;
        while(true){
            this->printMenu();
            std::cin>>op;
            if(op==1){
                std::cout<<"Enter the year of construction\n";
                int yearOfConstruction;
                std::cin>>yearOfConstruction;
                std::cout<<"Select type of building:\n";
                std::cout<<"1. Block.\n";
                std::cout<<"2. House.\n";
                int type;
                std::cin>>type;
                if(type==1){
                    int totalApartaments;
                    int ocuppiedApartments;
                    std::cout<<"Enter the total no of apartments.\n";
                    std::cin>>totalApartaments;
                    std::cout<<"Enter the no of ocuppied apartments.\n";
                    std::cin>>ocuppiedApartments;
                    Block newBlock(totalApartaments,ocuppiedApartments,yearOfConstruction);
                    this->ser.addBuilding(newBlock);
                }
                if(type==2){
                    std::cout<<"The House is:\n";
                    std::cout<<"1. Historical\n";
                    std::cout<<"2. Not historical\n";
                    bool isHistorical;
                    int ans;
                    std::cin>>ans;
                    if(ans==1)
                        isHistorical=true;
                    else
                        isHistorical=false;
                    House newHouse(isHistorical,yearOfConstruction);
                    this->ser.addBuilding(newHouse);
                }
            }
            if(op==2){
                printBuildings();
            }
        }
    }
    void printBuildings(){
        std::vector<Building*> buildings=ser.getAllBuildings();
        for(auto building:buildings){
            if(building->type()=="House"){
                std::cout<<building->toString();
            }
            if(building->type()=="Block"){
                std::cout<<building->toString();
            }
        }
    }
    void addBuildings(){
        Block b1(10,4,1998);
        ser.addBuilding(b1);
        House h1(true, 1900);
        ser.addBuilding(h1);
        Block b2(12,7,2000);
        ser.addBuilding(b2);
    }
};
