//
// Created by mok_a on 3/12/2023.
//

#include "Services.h"
#include "Repo.h"
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

Services* add_material_service(Services* ser, char* name, char* supplier, int quant, int day, int month, int year){
    Date date= create_date(day,month,year);
    Material material= create_material(name,supplier,quant,date);
//    if(material_exists(ser->repo,material.name)){
//        return NULL;
//    }
    ser->repo=add_material(get_repo(ser),material);
    return ser;
//    return add_material(ser->repo,material);
}
void update_material_service(Services* ser, char* name, char* supplier, int quant, Date date){
    if(!material_exists(ser->repo,name))
        return;
    update_material(ser->repo,name,supplier,quant,date);
}
Services* remove_material_service(Services* ser, char* name){
    if(!material_exists(ser->repo,name))
        return ser;
    ser->repo=remove_material(ser->repo,name);
    return ser;
}

Repo* get_repo(Services* ser){
    if(ser->repo->materials==NULL)
        return NULL;
    return ser->repo;
}


Repo* filter_services(Services* ser,char* str){

}
