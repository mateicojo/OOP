//
// Created by mok_a on 3/12/2023.
//

#pragma once
#include "Material.h"
#include "Repo.h"

typedef struct{
    Repo* repo;
    Date today;

}Services;

Services* create_service(Repo* repo);
void add_material_service(Services* ser, char* name, char* supplier, int quant, int day, int month, int year);
void update_material_service(Services* ser, char* name, char* supplier, int quant, Date date);
void remove_material_service(Services* ser, char* name);



