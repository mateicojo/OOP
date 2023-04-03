//
// Created by mok_a on 4/2/2023.
//

#include "Service.h"
#include "Domain.h"
#include "Repo.h"
Services::Services() : repository() {
}
void Services::addTutorialSer(string title, string presenter, int duration, int likes, string link){
    Tutorial t1=Tutorial(title,presenter,duration,likes,link);
    this->repository.addTutorial(t1);
}

void Services::addTutorialSer_user(Repo& watchlist,Tutorial add){
    watchlist.addTutorial(add);
}

void Services::updateTutorialSer(string title, string newPresenter, int newDuration, int newLikes, string newLink){
    Tutorial t1= Tutorial(title,newPresenter,newDuration,newLikes,newLink);
    this->repository.updateTutorial(title,t1);
}
void Services::removeTutorialSer(string title){
    this->repository.removeTutorial(title);
}

void Services::removeTutorialSer_user(Repo& watchlist,string title){
    watchlist.removeTutorial(title);
}
Repo& Services::getRepo(){
    return this->repository;
}

void Services::setRepo(Repo repo){
    this->repository=repo;
}
