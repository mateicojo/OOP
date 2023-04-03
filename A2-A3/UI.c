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
    ui->undo_stack=create_stack();
    ui->redo_stack=create_stack();
    ui->service = ser;
    return ui;
}

void destroy_ui(UI *ui) {
    if (ui != NULL) {
        destroy_service(get_service(ui));
        destroy_stack(get_redo_stack(ui));
        destroy_stack(get_undo_stack(ui));
        free(ui);
    }
}

int get_op(UI *ui){
    return ui->op;
}

Stack* get_undo_stack(UI *ui){
    return ui->undo_stack;
}
Stack* get_redo_stack(UI *ui){
    return ui->redo_stack;
}

void set_undo_stack(UI* ui, Stack* new_stack) {
    Stack* old_stack = ui->undo_stack;
    if(old_stack != NULL) {
        destroy_stack(old_stack);
    }
    ui->undo_stack = new_stack;
}
void set_redo_stack(UI* ui, Stack* new_stack) {
    Stack* old_stack = ui->redo_stack;
    if(old_stack != NULL) {
        destroy_stack(old_stack);
    }
    ui->redo_stack = new_stack;
}


void start(UI *ui){
//    add_material_service(get_service(ui),"Flour","CompanyCo",200,20,4,2020);
//    add_material_service(get_service(ui),"Sugar","CompanyCo",150,19,2,2020);
//    add_material_service(get_service(ui),"Salt","CompanyCoAgain",100,4,10,2019);
//    add_material_service(get_service(ui),"Water","BorsecCo",1000,13,2,2022);
//    add_material_service(get_service(ui),"Wheat","CompanyCo2",500,12,9,2021);
    add_material_service(get_service(ui),"Eggs","CompanyCo2",450,8,1,2021);
    add_material_service(get_service(ui),"Butter","CompanyCo3",200,30,10,2023);
    add_material_service(get_service(ui),"Vanilla","CompanyCo3",300,20,7,2022);
    add_material_service(get_service(ui),"Milk","Napoca",280,29,3,2022);
    add_material_service(get_service(ui),"Baking Powder","Napoca",130,22,8,2022);

    while(1){
        printf("[1] Add a material\n");
        printf("[2] Remove a material\n");
        printf("[3] Update a material\n");
        printf("[4] Filter materials\n");
        printf("[5] Materials that are short in supply\n");
        printf("[6] Print materials\n");
        printf("[7] Undo last operation\n");
        printf("[8] Redo last operation\n");
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
            //push(get_undo_stack(ui), get_repo(get_service(ui)));
            empty_stack(get_redo_stack(ui));
            add_material_service(get_service(ui), name, supplier, quant, day, month, year);
            free(name);
            free(supplier);
        }
        else{
            if(ui->op==2){
                char* name;
                name=(char*)malloc(10*sizeof(char));
                printf("Name:");
                scanf("%64s",name);
                push(get_undo_stack(ui), get_repo(get_service(ui)));
                empty_stack(get_redo_stack(ui));
                remove_material_service(get_service(ui),name);
                free(name);
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
                    push(get_undo_stack(ui), get_repo(get_service(ui)));
                    empty_stack(get_redo_stack(ui));
                    Date new_date= create_date(new_day,new_month,new_year);
                    update_material_service(get_service(ui),name,new_supplier,new_quant,new_date);
                    if(new_supplier!=NULL){
                        free(new_supplier);
                    }
                    if(name!=NULL){
                        free(name);
                    }
                }
                if(get_op(ui)==4){
                    char* filtering;
                    filtering=(char*) malloc(64*sizeof(char));
                    printf("Containing string: \n");
                    scanf("%s",filtering);
                    if(!strcmp(filtering,"0"))
                        print_repo(expired_materials(get_repo(get_service(ui)), get_today(get_service(ui))));
//                    print_repo(filter_services(get_service(ui),filtering));
                    Repo* filtered= filter_services(get_service(ui),filtering);
                    print_repo(filtered);
                    destroy_repo(filtered);
                    if(filtering!=NULL)
                        free(filtering);
                }
                else
                    if(get_op(ui)==0){
                        destroy_ui(ui);
                        return;
                    }
                    else{
                        if(get_op(ui)==6){
                            print_repo(get_repo(get_service(ui)));
                        }
                        else{
                            if(get_op(ui)==5){
                                char* supply;
                                supply=(char*)malloc(64*sizeof (char));
                                printf("Enter the suppllier's name: \n");
                                scanf("%s",supply);
                                int min_quant;
                                printf("Enter the minimum quantity: \n");
                                scanf("%d",&min_quant);
//                                print_repo(sort_by_quant(get_repo(get_service(ui)),supply,min_quant));
                                Repo* printed = sort_by_quant(get_repo(get_service(ui)),supply,min_quant);
                                print_repo(printed);
                                destroy_repo(printed);
                                if(supply!=NULL)
                                    free(supply);
                            }
                            else{
                                if(get_op(ui)==7){
                                    if(get_undo_stack(ui)->length!=0){
                                        Repo* temp= pop(get_undo_stack(ui));
                                        Repo* temp2 = copy_repo(get_repo(get_service(ui)));
                                        push(get_redo_stack(ui),temp2);
                                        destroy_repo(temp2);
                                        set_repo(get_service(ui),temp);
                                        destroy_repo(temp);
                                    }

//                                    set_undo_stack(ui, copy_stack(temp));
//                                    set_redo_stack(ui,copy_stack(temp));
//                                    destroy_repo(temp);
//                                    set_repo(get_service(ui), temp);
//                                    push(get_redo_stack(ui),temp);
//                                    destroy_repo(temp);
                                }
                                else{
                                    if(get_op(ui)==8){
                                        if(get_redo_stack(ui)->length!=0){
                                            Repo* temp= pop(get_redo_stack(ui));
                                            set_repo(get_service(ui),temp);
                                        }
                                    }
                                }
                            }
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

