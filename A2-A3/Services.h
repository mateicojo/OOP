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

typedef struct{
    Repo** repos;
    int length;
    int capacity;
}Stack;

Services* create_service(Repo* repo);
void destroy_service(Services* ser);
Services* add_material_service(Services* ser, char* name, char* supplier, int quant, int day, int month, int year);
void update_material_service(Services* ser, char* name, char* supplier, int quant, Date date);
Services* remove_material_service(Services* ser, char* name);
Repo* get_repo(Services* ser);
Date get_today(Services* ser);
Repo* filter_services(Services* ser,char* str);
Repo* short_in_supply(Services* ser,char* supplier,int min_quant);
void set_repo(Services* ser,Repo* new_repo);

void empty_stack(Stack* stack);
Stack* create_stack();
void push(Stack* stack,Repo* repo);
Repo* pop(Stack* stack);
void destroy_stack(Stack* stack);




