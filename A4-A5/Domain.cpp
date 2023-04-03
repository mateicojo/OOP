#include "Domain.h"
Tutorial::Tutorial(string title,string presenter,int duration,int likes,string link){
this->title=title;
this->presenter=presenter;
this->duration=duration;
this->likes=likes;
this->link=link;
}

string Tutorial::getTitle() const{
    return this->title;
}
string Tutorial::getPresenter() const{
    return this->presenter;
}
string Tutorial::getLink() const{
    return this->link;
}
int Tutorial::getDuration() const{
    return this->duration;
}
int Tutorial::getLikes() const{
    return this->likes;
}
void Tutorial::setTitle(string title){
    this->title=title;
}
void Tutorial::setPresenter(string presenter){
    this->presenter=presenter;
}
void Tutorial::setLink(string link){
    this->link=link;
}
void Tutorial::setDuration(int duration){
    this->duration=duration;
}
void Tutorial::setLikes(int likes){
    this->likes=likes;
}