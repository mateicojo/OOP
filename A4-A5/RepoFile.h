//
// Created by mok_a on 4/2/2023.
//

#pragma once
#include "Domain.h"
#include "DynArray.h"
#include <vector>
using namespace std;

class Repo{
protected:
    vector<Tutorial> elements;
    string filename;
    string watchlist_format;
    string watchlist_filename;
public:
    Repo();
    virtual void writeWatchlistToFile(){
        return;
    }
    virtual void readWatchlistFromFile(){
        return;
    }
    void addTutorial(Tutorial& tutorial);
    void removeTutorial(string title);
    void updateTutorial(string title, Tutorial& tutorial);
    void addTenEntities();
    Tutorial& getTutorial(int index);
    int getNumTutorials() const;
    bool tutorialExists(Tutorial tutorial);
    void setRepo(Repo& repo);
    void updateFile(string filename);
    string getFilename();
    void setFilename(string filename);
    void readData(string filename);
    bool tutorialExistsTitle(string title);
    void setWatchlistFormat(string format);
};

class RepoCSV: public Repo{
    public:
    RepoCSV();
    void writeWatchlistToFile();
    void readWatchlistFromFile();
};

class RepoHTML: public Repo{
public:
    RepoHTML();
    void writeWatchlistToFile();
    void readWatchlistFromFile();
};

