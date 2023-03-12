//
// Created by mok_a on 3/12/2023.
//

#include "Material.h"
#include <stdlib.h>
#include <string.h>

Material create_material(char* name, char* supplier, int quant, Date date){
    Material material;
    material.name=(char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(material.name,name);
    material.supplier=(char*)malloc((strlen(supplier)+1)*sizeof(char));
    strcpy(material.supplier,supplier);
    material.quant=quant;
    material.date= date;
    return material;
}

Date create_date(int day, int month, int year){
    Date date;
    date.day=day;
    date.month=month;
    date.year=year;
    return date;
}

char* get_name(Material material){
    return material.name;
}

char* get_supplier(Material material){
    return material.supplier;
}

int get_quant(Material material){
    return material.quant;
}

Date get_date(Material material){
    return material.date;
}

void set_name(Material *material, char* name){
    free(material->name);
    material->name=(char*)malloc((strlen(name)+1)*sizeof(char));
    strcpy(material->name,name);
}

void set_supplier(Material *material, char* supplier){
    free(material->supplier);
    material->supplier=(char*)malloc((strlen(supplier)+1)*sizeof(char));
    strcpy(material->supplier,supplier);
}
void set_quant(Material *material, int quant){
    material->quant=quant;
}
void set_date(Material *material, Date date){
    material->date=date;
}

void delete_material(Material material){
    free(material.name);
    free(material.supplier);
}