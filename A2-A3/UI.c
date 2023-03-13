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

void start(UI *ui){

    while(1){
        printf("1. Add a material\n");
        printf("2. Remove a material\n");
        printf("3. Update a material\n");
        scanf("%d",&ui->op);
        if(ui->op==1){
            char* name;
            char* supplier;
            int quant;
            int day;
            int month;
            int year;
            Date date;
            printf("Name:\n");
            scanf("%s",name);
            printf("Supplier:\n");
            scanf("%s",supplier);
            printf("quant:\n");
            scanf("%d",&quant);
            printf("Date:\n");
            printf("Day:\n");
            scanf("%d",&day);
            printf("Month:\n");
            scanf("%d",&month);
            printf("Year:\n");
            scanf("%d",&year);
            add_material_service(ui->service,name,supplier,quant,day,month,year);
            //printf("Material added!\n");
        }
        else{
            if(ui->op==2){

            }
            else{
                if(ui->op==3){

                }
            }
        }
    }
}

//void destroy_ui(UI **ui);