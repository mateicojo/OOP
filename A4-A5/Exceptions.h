//
// Created by mok_a on 5/13/2023.
//

#pragma once
#include <exception>
#include <string>

using namespace std;

class ValueError : public std::exception{
private:
    string message;
public:
    ValueError(string message);
};

class RepoError : public std::exception{
private:
    string message;
public:
    RepoError(string message);
};