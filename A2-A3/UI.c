//
// Created by mok_a on 3/12/2023.
//
#include "UI.h"
#include "Repo.h"
#include "Services.h"
#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

UI* create_ui(){
    UI *ui = (UI*)malloc(sizeof(UI));
    Repo* repo = create_repo();
    Services *new_service = create_service(repo);
    ui->service = new_service;
    return ui;
}

void start(UI *ui){
    while(1){
        printf("1. Add a material\n");
        printf("2. Remove a material\n");
        printf("3. Update a material\n");
    }
}

//void destroy_ui(UI **ui);