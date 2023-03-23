//
// Created by mok_a on 3/12/2023.
//

#include "Material.h"
#pragma once
typedef struct{
    Material* materials;
    int length;
    int capacity;
}Repo;

Repo* create_repo();

Material* get_materials(Repo* repo);

Material get_material(Repo* repo, int index );

int get_length(Repo* repo);

int get_capacity(Repo* repo);


void set_materials(Repo* repo, Material* materials);

int material_exists(Repo* repo, char* name);

Repo* remove_material(Repo* repo, char* name);

Repo* add_material(Repo* repo, Material material);

Repo* update_material(Repo* repo, char* name, char* supplier, int quant, Date date);

Repo* expired_materials(Repo* repo, Date today){
    Repo* expireds=create_repo();
    for(int i=0;i< get_length(repo);i++){
        if(get_year(get_material(repo,i))<today.year){
            add_material(expireds, get_material(repo,i));
        }
    }
}
