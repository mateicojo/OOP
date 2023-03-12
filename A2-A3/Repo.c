//
// Created by mok_a on 3/12/2023.
//

#include "Repo.h"
#include <stdlib.h>
#include <string.h>

Repo* create_repo(){
    Repo* repo = (Repo*)malloc(sizeof(Repo));
    if(repo==NULL){
        return NULL;
    }
    repo->length=0;
    repo->materials=(Material*)malloc(repo->capacity*sizeof(Material));
    return repo;
}

Material* get_materials(Repo* repo){
    return repo->materials;
}

int get_length(Repo* repo){
    return repo->length;
}


void set_materials(Repo* repo, Material* materials){
    repo->materials=materials;
}

int material_exists(Repo* repo, char* name){
    Material* materials=repo->materials;
    for(int i=0;i<repo->length;i++){
        if(!strcmp(get_name(materials[i]),name)){
            return 1;
        }
    }
    return 0;
}

void remove_material(Repo* repo, char* name){
    Material* materials = repo->materials;
    int pos =-1;
    for (int i=0;i<repo->length;i++){
        if(!strcmp(get_name(materials[i]),name)){
            pos=i;
            destroy_material(materials[i]);
        }
    }
    for(int i=pos;i<repo->length-1;i++){
        materials[i]=materials[i+1];
    }
    repo->length--;
}

void add_material(Repo* repo, Material material){
    repo->materials=(Material*)realloc(repo->materials,(repo->length+1)*sizeof(Material));
    repo->length++;
    ((Material*)repo->materials)[repo->length]=material;//check this line if errors!
}

void update_material(Repo* repo, char* name, char* supplier, int quant, Date date){
    Material* material=repo->materials;
    int pos=-1;
    for(int i=0;i<repo->length;i++){
        if(!strcmp(material[i].name,name)){
            set_name(&((Material*)repo->materials)[i],name);
            set_supplier(&((Material*)repo->materials)[i],supplier);
            set_quant(&((Material*)repo->materials)[i],quant);
            set_date(&((Material*)repo->materials)[i],date);
        }
    }
}
