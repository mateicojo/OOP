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

int get_length(Repo* repo);


void set_materials(Repo* repo, Material* materials);

int material_exists(Repo* repo, char* name);

void remove_material(Repo* repo, char* name);

void add_material(Repo* repo, Material material);

void update_material(Repo* repo, char* name, char* supplier, int quant, Date date);
