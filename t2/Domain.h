//
// Created by mok_a on 5/8/2023.
//

#pragma once
#include <string>
#include <iostream>
#include <vector>


class Building{
protected:
    int constructionYear;
public:
    Building(int constructionYear){
        this->constructionYear=constructionYear;
    }
    virtual bool mustBeRestored()=0;
    virtual bool canBeDemolished()=0;
    virtual std::string toString()=0;
    virtual std::string type()=0;
};

class Block:public Building{
private:
    int totalApartments;
    int occupiedApartments;
public:
    Block(int totalApartments,int ocuppiedApartments, int constructionYear): Building(constructionYear){
        this->totalApartments=totalApartments;
        this->occupiedApartments=ocuppiedApartments;
    }
    bool mustBeRestored() override{
        if(2023-this->constructionYear>40 and this->occupiedApartments*100/this->totalApartments>80)
            return true;
        return false;
    }
    bool canBeDemolished() override{
        if(this->occupiedApartments*100/this->totalApartments<5){
            return true;
        }
        return false;
    }
    std::string toString() override{
        return "Block" + std::to_string(this->totalApartments) + " " + std::to_string(this->occupiedApartments) + " " + std::to_string(this->constructionYear) + "\n";
    }
    std::string type()override {
        return "Block";
    }
};

class House:public Building{
private:
    bool isHistorical;
public:
    House(bool isHistorical, int constructionYear) : Building(constructionYear){
        this->isHistorical=isHistorical;
    }
    bool mustBeRestored() override {
        if(2023-this->constructionYear>100)
            return true;
        return false;
    }
    bool canBeDemolished() override {
        if(!this->isHistorical)
            return true;
        return false;
    }
    std::string toString() override {
        return "House" + std::to_string(this->isHistorical) + " " + std::to_string(this->constructionYear) + "\n";
    }
    std::string type() override {
        return "House";
    }
};
