//
// Created by mok_a on 3/12/2023.
//

#include "Services.h"
#include "Repo.h"
#pragma once

typedef struct{
    Services *service;
    int op;
} UI;

UI* create_ui();

Services* get_service(UI *ui);
void start(UI *ui);

void destroy_ui(UI **ui);

void print_repo(Repo* repo);

int get_op(UI *ui);
