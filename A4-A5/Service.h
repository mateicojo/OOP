//
// Created by mok_a on 4/2/2023.
//

#pragma once
#include "Repo.h"
#include "Domain.h"
#include <iostream>

class Services{
private:
    Repo repository;

public:
    Services();
    void addTutorialSer(string title, string presenter, int duration, int likes, string link);
    void addTutorialSer_user(Repo& watchlist,Tutorial add);
    void updateTutorialSer(string title, string newPresenter, int newDuration, int newLikes, string newLink);
    void removeTutorialSer(string title);
    void removeTutorialSer_user(Repo& watchlist,string title);
    Repo& getRepo();
    void setRepo(Repo repo);

};
