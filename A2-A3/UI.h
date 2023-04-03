//
// Created by mok_a on 3/12/2023.
//

#include "Services.h"
#include "Repo.h"
#pragma once

typedef struct{
    Services *service;
    Stack *undo_stack;
    Stack *redo_stack;
    int op;
} UI;

UI* create_ui();

Services* get_service(UI *ui);
Stack* get_undo_stack(UI *ui);
Stack* get_redo_stack(UI *ui);
void set_redo_stack(UI* ui, Stack* new_stack);
void set_undo_stack(UI* ui, Stack* new_stack);

void start(UI *ui);

void destroy_ui(UI *ui);

void print_repo(Repo* repo);

int get_op(UI *ui);
