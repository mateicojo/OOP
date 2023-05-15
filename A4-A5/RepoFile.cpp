#include "RepoFile.h"
#include "Domain.h"
#include <fstream>
#include <string>
#include "Validator.h"
using namespace std;


Repo::Repo() : elements(){
    this->filename="../Data.txt";
    this->watchlist_format="CSV";
}
RepoCSV::RepoCSV() : Repo(){
    this->watchlist_filename="../Watchlist.csv";
}
RepoHTML::RepoHTML() : Repo(){
    this->watchlist_filename="../Watchlist.html";
}

vector<string> split(const string& str, const string& delim)
/* takes parameter a string and a delimiter and returns a vector of strings split by the delimiter*/
{
    vector<string> result;
    int start = 0;
    int end = str.find(delim);
    while (end != -1) {
        result.push_back(str.substr(start, end - start));
        start = end + delim.length();
        end = str.find(delim, start);
    }
    result.push_back(str.substr(start, end - start));
    return result;
}

void Repo::readData(string filename){
    //TODO:implement this
    //reads file from filename, updates repo
    ifstream ins;
    ins.open(filename);
    string line;
    while(getline(ins,line)){
        int i=0;
        vector<string> r= split(line,";");
        Tutorial t(r[0],r[1],stoi(r[2]),stoi(r[3]),r[4]);
        this->elements.push_back(t);
    }
    ins.close();
}

void Repo::setFilename(string filename){
    this->filename=filename;
}

string Repo::getFilename() {
    return this->filename;
}

void Repo::updateFile(string filename) {
    ofstream ofs;
    ofs.open(filename,ios::trunc);
    for (int i =0;i<this->getNumTutorials();i++){
        ofs<<this->elements[i].getTitle()<< ";" <<elements[i].getPresenter()<< ";" <<elements[i].getLikes()<< ";" <<elements[i].getDuration()<< ";" <<elements[i].getLink()<<"\n";
    }
    ofs.close();
}



void Repo::addTutorial(Tutorial& tutorial){
    Validator::validate_add_repo(*this,tutorial);
    if(tutorialExists(tutorial))
        return;
    this->elements.push_back(tutorial);
}

void Repo::removeTutorial(string title) {
    Validator::validate_remove_repo(*this,title);
    for (auto it = this->elements.begin(); it != this->elements.end(); ++it) {
        if (it->getTitle() == title) {
            this->elements.erase(it);
            break;
        }
    }
}

void Repo::updateTutorial(string title, Tutorial& tutorial){
    Validator::validate_update_repo(*this,tutorial);
    for (auto& i : this->elements){
        if (i.getTitle() == title) {
            i=tutorial;
            break;
        }
    }
}

Tutorial& Repo::getTutorial(int index){
    return this->elements[index];
}

int Repo::getNumTutorials() const{
    return this->elements.size();
}

void Repo::addTenEntities(){
    Tutorial t1 = Tutorial("Introduction to C++", "John", 60, 100, "https://example.com/cpp-intro");
    elements.push_back(t1);
    Tutorial t2 = Tutorial("Object-Oriented Programming with Java", "Jane", 90, 200, "https://example.com/java-oop");
    elements.push_back(t2);
    Tutorial t3 = Tutorial("Python Fundamentals", "Bob", 120, 300, "https://example.com/python-fundamentals");
    elements.push_back(t3);
    Tutorial t4 = Tutorial("Web Development with HTML, CSS, and JavaScript", "Sarah", 180, 500, "https://example.com/web-dev");
    elements.push_back(t4);
    Tutorial t5 = Tutorial("Data Structures and Algorithms in C", "Chris", 150, 400, "https://example.com/c-dsa");
    elements.push_back(t5);
    Tutorial t6 = Tutorial("Machine Learning Basics", "Kate", 120, 350, "https://example.com/ml-basics");
    elements.push_back(t6);
    Tutorial t7=Tutorial("Artificial Intelligence Ethics", "Tom", 90, 250, "https://example.com/ai-ethics");
    elements.push_back(t7);
    Tutorial t8 = Tutorial("Databases for Beginners", "Alex", 75, 150, "https://example.com/db-basics");
    elements.push_back(t8);
    Tutorial t9=Tutorial("Functional Programming in Haskell", "Emily", 100, 200, "https://example.com/haskell-fp");
    elements.push_back(t9);
    Tutorial t10=Tutorial("Software Testing Techniques", "Mike", 60, 100, "https://example.com/software-testing");
    elements.push_back(t10);
//    readData(getFilename());
}

bool Repo::tutorialExists(Tutorial tutorial) {
    for (auto x : this->elements) {
        if (x.getTitle()==tutorial.getTitle()) {
            return true;
        }
    }
    return false;
}

bool Repo::tutorialExistsTitle(string title) {
    for (auto x : this->elements) {
        if (x.getTitle()==title) {
            return true;
        }
    }
    return false;
}

void Repo::setWatchlistFormat(string format) {
    this->watchlist_format=format;
}

void RepoCSV::readWatchlistFromFile() {
    ifstream ins;
    ins.open("../Watchlist.csv");
    string line;
    while(getline(ins,line)){
        int i=0;
        vector<string> r= split(line,",");
        Tutorial t(r[0],r[1],stoi(r[2]),stoi(r[3]),r[4]);
        this->elements.push_back(t);
    }
    ins.close();
}

void RepoCSV::writeWatchlistToFile() {
    ofstream ofs;
    ofs.open("../Watchlist.csv",ios::trunc);
    for (int i =0;i<this->getNumTutorials();i++){
        ofs<<this->elements[i].getTitle()<< "," <<elements[i].getPresenter()<< "," <<elements[i].getLikes()<< "," <<elements[i].getDuration()<< "," <<elements[i].getLink()<<"\n";
    }
    ofs.close();
}

void RepoHTML::readWatchlistFromFile() {
    ifstream ins;
    ins.open("../Watchlist.html");
    string line;
    for(int i=0;i<8;i++){
        getline(ins,line);
    }
    while(getline(ins,line)){
        int i=0;
        vector<string> r= split(line,"<td>");
//        cout<<r[0]<<r[1]<<r[2]<<r[3]<<r[4]<<endl;
//        Tutorial t(r[0],r[1],stoi(r[2]),stoi(r[3]),r[4]);
//        this->elements.push_back(t);
    }
    ins.close();
}

void RepoHTML::writeWatchlistToFile(){
    ofstream ofs;
    ofs.open("../Watchlist.html",ios::trunc);
    ofs << "<!DOCTYPE html>\n<html>\n<head>\n<title>Watchlist</title>\n</head>\n<body>\n<table border=\"1\">\n";
    for (int i =0;i<this->getNumTutorials();i++){
        ofs<<"<tr>\n<td>"<<this->elements[i].getTitle()<< "</td>\n<td>" <<elements[i].getPresenter()<< "</td>\n<td>" <<elements[i].getLikes()<< "</td>\n<td>" <<elements[i].getDuration()<< "</td>\n<td>" <<elements[i].getLink()<<"</td>\n</tr>\n";
    }
    ofs<<"</table>\n</body>\n</html>";
    ofs.close();
}
