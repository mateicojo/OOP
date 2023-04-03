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

void destroy_repo(Repo* repo){
    if(repo==NULL){
        return;
    }
    for(int i=0;i<get_length(repo);i++){
        if(&repo->materials[i]!=NULL)
            destroy_material(&repo->materials[i]);
    }
    free(repo->materials);
    free(repo);
}

Repo* copy_repo(Repo* repo) {
    Repo* new_repo = (Repo*)malloc(sizeof(Repo));
    if(new_repo == NULL) {
        return NULL;
    }

    new_repo->length = repo->length;
    new_repo->capacity = repo->capacity;
    new_repo->materials = (Material*)malloc(new_repo->capacity * sizeof(Material));
    if(new_repo->materials == NULL) {
        free(new_repo);
        return NULL;
    }

    for(int i = 0; i < repo->length; i++) {
        Material* material_copy = copy_material(&repo->materials[i]);
        if(material_copy == NULL) {
            for(int j = 0; j < i; j++) {
                free(new_repo->materials[j].name);
                free(new_repo->materials[j].supplier);
            }
            free(new_repo->materials);
            free(new_repo);
            return NULL;
        }
        new_repo->materials[i] = *material_copy;
    }
    return new_repo;
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
            destroy_material(&materials[i]);
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
Repo* expired_materials(Repo* repo, Date today){
    Repo* expireds=create_repo();
    for(int i=0;i< get_length(repo);i++){
        if(get_year(get_material(repo,i))<today.year){
            add_material(expireds, get_material(repo,i));
        }
        else{
            if(get_month(get_material(repo,i))<today.month){
                add_material(expireds, get_material(repo,i));
            }
            else{
                if(get_day(get_material(repo,i))<today.day){
                    add_material(expireds, get_material(repo,i));
                }
            }
        }
    }
    if(expireds==NULL){
        return NULL;
    }
    return expireds;
}

void set_material_on_pos(Repo* repo, Material material, int index){
    repo->materials[index]=material;
}

Repo* sort_by_quant(Repo* repo,char* supplier,int min_quant){
    Repo* repo2=create_repo();
    for(int i=0;i< get_length(repo);i++){
        if(!strcmp(get_supplier(get_material(repo,i)),supplier) && get_quant(get_material(repo,i))<min_quant){
            add_material(repo2, get_material(repo,i));
        }
    }

    for(int i=0;i< get_length(repo2)-1;i++){
        for(int j=i+1;j< get_length(repo2);j++){
            if(get_quant(get_material(repo2,i))> get_quant(get_material(repo2,j))){
                Material temp = get_material(repo2,i);
                set_material_on_pos(repo2, get_material(repo2,j),i);
                set_material_on_pos(repo2,temp,j);
            }
        }
    }

    return repo2;
}



