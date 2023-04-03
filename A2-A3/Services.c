//
// Created by mok_a on 3/12/2023.
//

#include "Services.h"
#include "Repo.h"
#include "stdlib.h"
#include "string.h"

Stack* create_stack(){
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->length=0;
    stack->capacity=30;
    stack->repos=(Repo**)malloc(stack->capacity*sizeof(Repo*));
    return stack;
}

void empty_stack(Stack* stack){
    stack->length = 0;
}

void push(Stack* stack, Repo* repo){
    if(stack->length >= stack->capacity) {
        return;
    }
    if (stack->repos[stack->length] != NULL) {
        destroy_repo(stack->repos[stack->length]);
    }
    if (stack->length > 0) {
        destroy_repo(stack->repos[stack->length - 1]);
    }
    Repo* repocopy= copy_repo(repo);
    stack->repos[stack->length] = repocopy;
    destroy_repo(repocopy);
    stack->length++;
}



Repo* pop(Stack* stack){
    if(stack->length == 0) {
        return NULL;
    }
//    destroy_repo(stack->repos[stack->length]);
    stack->length--;
    return stack->repos[stack->length];
}

void destroy_stack(Stack* stack) {
    if (stack == NULL) {
        return;
    }
    for(int i=0; i<stack->length; i++) {
        if (stack->repos[i] != NULL) {
            destroy_repo(stack->repos[i]);
        }
    }
    if(stack->repos!=NULL)
        free(stack->repos);
    stack->repos = NULL;
    free(stack);
}


Services* create_service(Repo* repo){
    Services* ser = (Services*)malloc(sizeof(Services));
    if (ser == NULL)
        return NULL;
    ser->repo=repo;
    ser->today= create_date(13,3,2023);
    return ser;
}

void destroy_service(Services* ser) {
    if (ser == NULL)
        return;
    if(ser->repo!=NULL)
        destroy_repo(ser->repo);
    free(ser);
}

Services* add_material_service(Services* ser, char* name, char* supplier, int quant, int day, int month, int year){
    /*
     * this function takes parameter the service and the needed attributes to create a new material, calls the funciton from the repo file
     * and returns a pointer to the updated service
     */
    Date date= create_date(day,month,year);
    Material material= create_material(name,supplier,quant,date);
//    if(material_exists(ser->repo,material.name)){
//        return NULL;
//    }
    ser->repo=add_material(get_repo(ser),material);
    return ser;
}
void update_material_service(Services* ser, char* name, char* supplier, int quant, Date date){
    /*
 * this function takes parameter the service and the name of an existing material, the attributes to update a material, calls the funciton from the repo file
 * and returns a pointer to the updated service
 */
    if(!material_exists(ser->repo,name))
        return;
    update_material(ser->repo,name,supplier,quant,date);
}
Services* remove_material_service(Services* ser, char* name){
    /*
 * this function takes parameter the service and the name of an existing material, calls the funciton from the repo file
 * and returns a pointer to the updated service
 */
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

void set_repo(Services* ser,Repo* new_repo){
    if(new_repo!=NULL){
        ser->repo=new_repo;
    }
}

Date get_today(Services* ser){
    return ser->today;
}

Repo* filter_services(Services* ser,char* str){
    Repo* expireds= expired_materials(get_repo(ser), get_today(ser));
    Repo* repo2 = create_repo();
    for(int i=0;i< get_length(expireds);i++){
        if (strstr(get_name(get_material(expireds,i)), str) != NULL) {
            add_material(repo2, get_material(expireds,i));
        }
    }
    if(repo2==NULL){
        return NULL;
    }
    destroy_repo(expireds);
    return repo2;
}