//
// Created by mok_a on 3/12/2023.
//

#pragma once

typedef struct{
    int day;
    int month;
    int year;
}Date;

Date create_date(int day, int month, int year);


typedef struct{
    char* name;
    char* supplier;
    int quant;
    Date date;
}Material;

Material create_material(char* name, char* supplier, int quant, Date date);
Material* copy_material(Material* material);
char* get_name(Material material);
char* get_supplier(Material material);
int get_quant(Material material);
Date get_date(Material material);

void set_name(Material *material, char* name);
void set_supplier(Material *material, char* supplier);
void set_quant(Material *material, int quant);
void set_date(Material *material, Date date);

int get_day(Material material);
int get_month(Material material);
int get_year(Material material);

void destroy_material(Material* material);
void stringcpy(const char* original, char* copy);
