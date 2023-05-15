//
// Created by mok_a on 5/4/2023.
//
#pragma once
#include "Repository.h"
class Action{
public:
    virtual void executeUndo()=0;
    virtual void executeRedo()=0;
};

class ActionAdd:Action{
private:
    Song addedSong;
    Repository& repo;
public:
    ActionAdd(Song addedSong, Repository& repo) : repo{repo} , addedSong{addedSong} {
        this->addedSong=addedSong;
        this->repo=repo;
    }
    void executeUndo() override{
        repo.removeSong(addedSong);
    }
    void executeRedo() override{
        repo.addSong(addedSong);
    }
};

class ActionRemove:Action{
private:
    Song deletedSong;
    Repository& repo;
public:
    ActionRemove(Song deletedSong, Repository& repo):deletedSong{deletedSong}, repo{repo}{
        this->deletedSong=deletedSong;
        this->repo=repo;
    }
    void executeUndo() override{
        repo.addSong(deletedSong);
    }
    void executeRedo() override{
        repo.removeSong(deletedSong);
    }
};

class ActionUpdate:Action{
private:
    Song oldSong;
    Song updatedSong;
    Repository& repo;

public:
    ActionUpdate(Song oldSong, Song updatedSong, Repository& repo):repo{repo}, oldSong{oldSong}, updatedSong{updatedSong}{
        this->oldSong=oldSong;
        this->updatedSong=updatedSong;
        this->repo=repo;
    }
    void executeUndo() override{
        repo.removeSong(updatedSong);
        repo.addSong(oldSong);
    }
    void executeRedo() override{
        repo.removeSong(oldSong);
        repo.addSong(updatedSong);
    }
};
