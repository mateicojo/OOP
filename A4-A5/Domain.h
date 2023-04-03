#pragma once
#include <iostream>
using namespace std;
class Tutorial{
private:
string title;
string presenter;
int duration;
int likes;
string link;
public:
    Tutorial()=default;
    Tutorial(string title,string presenter,int duration,int likes,string link);
    string getTitle() const;
    string getPresenter() const;
    string getLink() const;
    int getDuration() const;
    int getLikes() const;
    void setTitle(string title);
    void setPresenter(string presenter);
    void setLink(string link);
    void setDuration(int duration);
    void setLikes(int likes);
};