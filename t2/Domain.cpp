////
//// Created by mok_a on 5/8/2023.
////
//
//#include "Domain.h"
//
//Building::Building(int constructionYear) {
//    this->constructionYear=constructionYear;
//}
//Block::Block(int totalApartments,int ocuppiedApartments, int constructionYear) : Building(constructionYear){
//    this->totalApartments=totalApartments;
//    this->occupiedApartments=ocuppiedApartments;
//}
//
//bool Block::mustBeRestored() {
//    if(2023-this->constructionYear>40 and this->occupiedApartments*100/this->totalApartments>80)
//        return true;
//    return false;
//}
//
//bool Block::canBeDemolished() {
//    if(this->occupiedApartments*100/this->totalApartments<5){
//        return true;
//    }
//    return false;
//}
//
//string Block::toString() {
//    return "Block";
//}
//
//House::House(bool isHistorical, int constructionYear) : Building(constructionYear){
//    this->isHistorical=isHistorical;
//}
//
//bool House::mustBeRestored() {
//    if(2023-this->constructionYear>100)
//        return true;
//    return false;
//}
//
//bool House::canBeDemolished(){
//    if(!this->isHistorical)
//        return true;
//    return false;
//}
//
//string House::toString() {
//    return "House";
//}
//
//
