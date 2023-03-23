//
// Created by mok_a on 3/12/2023.
//
#include "UI.h"
#include "Repo.h"
#include "Services.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

UI* create_ui(){
    UI *ui = (UI*)malloc(sizeof(UI));
    Repo* repo = create_repo();
    Services *ser = create_service(repo);
    ui->service = ser;
    return ui;
}

int get_op(UI *ui){
    return ui->op;
}

void start(UI *ui){
    add_material_service(get_service(ui),"Flour","CompanyCo",200,20,4,2020);
    add_material_service(get_service(ui),"Sugar","CompanyCo",150,19,2,2020);
    add_material_service(get_service(ui),"Salt","CompanyCoAgain",100,4,10,2019);
    add_material_service(get_service(ui),"Water","BorsecCo",1000,13,2,2022);
    add_material_service(get_service(ui),"Wheat","CompanyCo2",500,12,9,2021);
    add_material_service(get_service(ui),"Eggs","CompanyCo2",450,8,1,2021);
    add_material_service(get_service(ui),"Butter","CompanyCo3",200,30,10,2022);
    add_material_service(get_service(ui),"Vanilla","CompanyCo3",300,20,7,2022);
    add_material_service(get_service(ui),"Milk","Napoca",280,29,3,2022);
    add_material_service(get_service(ui),"Baking Powder","Napoca",130,22,8,2022);

    while(1){

        printf("[1] Add a material\n");
        printf("[2] Remove a material\n");
        printf("[3] Update a material\n");
        printf("[4] Filter materials\n");
        printf("[6] Print materials\n");

        printf("[0] Exit\n");

        scanf("%d",&ui->op);
        if(get_op(ui)==1){
            char* name;
            name=(char*)malloc(64*sizeof(char));
            char* supplier;
            supplier=(char*)malloc(64*sizeof(char));
            int quant;
            int day;
            int month;
            int year;
            Date date;
            printf("Name:\n");
            scanf("%64s",name);
            printf("Supplier:\n");
            scanf("%64s",supplier);
            printf("quant:\n");
            scanf("%d",&quant);
            printf("Date:\n");
            printf("Day:\n");
            scanf("%d",&day);
            printf("Month:\n");
            scanf("%d",&month);
            printf("Year:\n");
            scanf("%d",&year);

//            get_repo(get_service(ui))=add_material_service(get_service(ui), name, supplier, quant, day, month, year);
            add_material_service(get_service(ui), name, supplier, quant, day, month, year);
            //printf("Material added!\n");
        }
        else{
            if(ui->op==2){
                char* name;
                name=(char*)malloc(10*sizeof(char));
                printf("Name:");
                scanf("%64s",name);
                remove_material_service(get_service(ui),name);
            }
            else{
                if(get_op(ui)==3){
                    char* name;
                    name=(char*)malloc(10*sizeof(char));
                    char* new_supplier;
                    new_supplier=(char*)malloc(10*sizeof(char));
                    int new_quant;
                    int new_day;
                    int new_month;
                    int new_year;
                    printf("Name:\n");
                    scanf("%64s",name);
                    printf("New supplier:\n");
                    scanf("%64s",new_supplier);
                    printf("New quantity:\n");
                    scanf("%d",&new_quant);
                    printf("New date\n");
                    printf("New day:\n");
                    scanf("%d",&new_day);
                    printf("New month:\n");
                    scanf("%d",&new_month);
                    printf("New year:\n");
                    scanf("%d",&new_year);
                    Date new_date= create_date(new_day,new_month,new_year);
                    update_material_service(ui->service,name,new_supplier,new_quant,new_date);
                }
                if(get_op(ui)==4){
                    char* filtering;
                    filtering=(char*) malloc(64*sizeof(char));
                    printf("Containing string: \n");
                    scanf("%s",filtering);
                    if(!strcmp(filtering,"0"))
                        print_repo(get_repo(get_service(ui)));
                    //print_repo(get_repo(get_service(ui)));
                }
                else
                    if(get_op(ui)==0){
                        return;
                    }
                    else{
                        if(get_op(ui)==6){
                            print_repo(get_repo(get_service(ui)));
                        }
                    }
            }
        }
    }
}

void print_repo(Repo* repo){
    for(int i=0;i< get_length(repo);i++){
        printf("%d. %s // %s // %d // %d // %d // %d \n",i+1,get_name(get_material(repo,i)),get_supplier(get_material(repo,i)),get_quant(get_material(repo,i)),
               get_day(get_material(repo,i)), get_month(get_material(repo,i)), get_year(get_material(repo,i)));
    }
}

Services* get_service(UI *ui){
    return ui->service;
}





//void destroy_ui(UI **ui);