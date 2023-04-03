//
// Created by mok_a on 4/2/2023.
//

#pragma once
#include "Domain.h"
#include "DynArray.h"

class Repo{
private:
    DynamicVector<Tutorial> elements;
public:
    Repo();
    void addTutorial(Tutorial& tutorial);
    void removeTutorial(string title);
    void updateTutorial(string title, Tutorial& tutorial);
    void addTenEntities();
    Tutorial& getTutorial(int index);
    int getNumTutorials() const;
    bool tutorialExists(Tutorial tutorial);
    void setRepo(Repo& repo);
};
