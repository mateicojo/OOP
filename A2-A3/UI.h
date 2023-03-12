//
// Created by mok_a on 3/12/2023.
//

#include "Services.h"
#pragma once

typedef struct{
    Services *service;
} UI;

UI* create_ui();

void start(UI *ui);

void destroy_ui(UI **ui);
