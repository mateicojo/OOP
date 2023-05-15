//
// Created by mok_a on 5/13/2023.
//

#include "Exceptions.h"

ValueError::ValueError(string message) {
    this->message = message;
}

RepoError::RepoError(string message) {
    this->message = message;
}
