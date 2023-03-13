//
// Created by mok_a on 3/12/2023.
//

#include "Services.h"
#include "stdlib.h"
#include "string.h"
#include <stdio.h>

Services* create_service(Repo* repo){
    Services* ser = (Services*)malloc(sizeof(Services));
    if (ser == NULL)
        return NULL;
    ser->repo=repo;
    ser->today= create_date(13,3,2023);
    return ser;
}

void add_material_service(Services* ser, char* name, char* supplier, int quant, int day, int month, int year){
    Date date= create_date(day,month,year);
    Material material= create_material(name,supplier,quant,date);

//    if(material_exists(ser->repo,material.name)){
//        return;
//    }
    add_material(ser,material);
    printf("AAAAA");
}
void update_material_service(Services* ser, char* name, char* supplier, int quant, Date date){
    if(!material_exists(ser->repo,name))
        return;
    update_material(ser->repo,name,supplier,quant,date);
}
void remove_material_service(Services* ser, char* name){
    if(!material_exists(ser->repo,name))
        return;
    remove_material(ser->repo,name);
}
