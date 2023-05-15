//
// Created by mok_a on 5/13/2023.
//

#pragma once
#include "Exceptions.h"
#include "Domain.h"
#include "RepoFile.h"
#include "Service.h"

class Validator{
public:
static void validate_add_repo(Repo repository, Tutorial add);
static void validate_update_repo(Repo repository, Tutorial update);
static void validate_remove_repo(Repo repository, string title);
static void validate_useradd_service(Repo repository, Repo watchlist, Tutorial add);
static void validate_userremove_service(Repo repository, Repo watchlist, string title);
static void validate_operation_ui(string operation);
};
