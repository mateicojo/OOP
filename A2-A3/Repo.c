//
// Created by mok_a on 3/12/2023.
//

#include "Repo.h"
#include "Material.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

Repo* create_repo(){
    Repo* repo = (Repo*)malloc(sizeof(Repo));
    if(repo==NULL){
        return NULL;
    }
    repo->length=0;
    repo->capacity=20;
    repo->materials=(Material*)malloc(get_capacity(repo)*sizeof(Material));
    return repo;
}

Material* get_materials(Repo* repo){
    return repo->materials;
}

int get_length(Repo* repo){
    return repo->length;
}

int get_capacity(Repo* repo){
    return repo->capacity;
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

Repo* remove_material(Repo* repo, char* name){
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
    repo->materials=materials;
    return repo;
}

Repo* add_material(Repo* repo, Material material){
    if(get_capacity(repo)== get_length(repo)){
        repo->capacity*=2;
        Material* aux=repo->materials;
        repo->materials=(Material*)realloc(aux,(get_capacity(repo))*sizeof(Material));
    }

    ((Material*) get_materials(repo))[get_length(repo)]=material;//check this line if errors!
    repo->length+=1;
    //repo->materials[repo->length]=material;//check this line if errors!
    return repo;
}

Repo* update_material(Repo* repo, char* name, char* supplier, int quant, Date date){
    Material* material=repo->materials;
    int pos=-1;
    for(int i=0;i<repo->length;i++){
        if(!strcmp(material[i].name,name)){
            set_name(&((Material*)repo->materials)[i],name);
            set_supplier(&((Material*)repo->materials)[i],supplier);
            set_quant(&((Material*)repo->materials)[i],quant);
            set_date(&((Material*)repo->materials)[i],date);
            return repo;
        }
    }

}

Material get_material(Repo* repo, int index ){
    if(index< get_length(repo))
        return repo->materials[index];
    return create_material("","",0, create_date(0,0,0));
}

Repo* filter(Repo* repo, char* str){
    Material* materials= get_materials(repo);
    Repo* repo2=create_repo();
    for(int i=0;i< get_length(repo);i++){
        if (strstr(get_name(materials[i]), str) != NULL) {
            add_material(repo2,materials[i]);
        }
    }
    if(repo2==NULL){
        return NULL;
    }
    else{
        return repo2;
    }
}


