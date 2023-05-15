//
// Created by mok_a on 5/13/2023.
//

#include "Validator.h"
void Validator::validate_add_repo(Repo repository, Tutorial add) {
    if (repository.tutorialExists(add) == true)
        throw RepoError("Tutorial already exists!");
}

void Validator::validate_update_repo(Repo repository, Tutorial update) {
    if (repository.tutorialExists(update) == false)
        throw RepoError("Tutorial does not exist!");
}

void Validator::validate_remove_repo(Repo repository, string title) {
    if (repository.tutorialExistsTitle(title) == false)
        throw RepoError("Tutorial does not exist!");
}

