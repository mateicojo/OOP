//
// Created by mok_a on 4/2/2023.
//

#pragma once
#include <iostream>
#include "Service.h"
#include "RepoFile.h"
#include "Domain.h"
#include <algorithm>

using namespace std;
class UI{
private:
    Services service;
    string operation;
    string admin_mode;
public:
    UI();
    void printRepo(Repo repo);
    void printRepo_presenter(Repo repo,string presenter);
    Services& getService();
    void printFirstMenu();
    void printAdminMenu();
    void printUserMenu();
    void printTutorial(int index);
    void openWatchlist(string filename);
};
