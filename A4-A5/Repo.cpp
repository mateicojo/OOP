#include "Repo.h"
#include "DynArray.h"
#include "Domain.h"

Repo::Repo() : elements(){
}

void Repo::addTutorial(Tutorial& tutorial){
    if(tutorialExists(tutorial))
        return;
    this->elements.add(tutorial);
}

void Repo::removeTutorial(string title){
    for(int i=0;i<this->elements.getSize();i++) {
        if (this->elements.getElemsOnPosition(i).getTitle()==title) {
            this->elements.remove(i);
            break;
        }
    }
}

void Repo::updateTutorial(string title, Tutorial& tutorial){
    for(int i=0;i<this->elements.getSize();i++) {
        if (this->elements.getElemsOnPosition(i).getTitle() == title) {
            this->elements.setElemsOnPosition(i, tutorial);
            break;
        }
    }
}

Tutorial& Repo::getTutorial(int index){
    return this->elements.getElemsOnPosition(index);
}

int Repo::getNumTutorials() const{
    return this->elements.getSize();
}

void Repo::addTenEntities(){
    Tutorial t1 = Tutorial("Introduction to C++", "John", 60, 100, "https://example.com/cpp-intro");
    elements.add(t1);
    Tutorial t2 = Tutorial("Object-Oriented Programming with Java", "Jane", 90, 200, "https://example.com/java-oop");
    elements.add(t2);
    Tutorial t3 = Tutorial("Python Fundamentals", "Bob", 120, 300, "https://example.com/python-fundamentals");
    elements.add(t3);
    Tutorial t4 = Tutorial("Web Development with HTML, CSS, and JavaScript", "Sarah", 180, 500, "https://example.com/web-dev");
    elements.add(t4);
    Tutorial t5 = Tutorial("Data Structures and Algorithms in C", "Chris", 150, 400, "https://example.com/c-dsa");
    elements.add(t5);
    Tutorial t6 = Tutorial("Machine Learning Basics", "Kate", 120, 350, "https://example.com/ml-basics");
    elements.add(t6);
    Tutorial t7=Tutorial("Artificial Intelligence Ethics", "Tom", 90, 250, "https://example.com/ai-ethics");
    elements.add(t7);
    Tutorial t8 = Tutorial("Databases for Beginners", "Alex", 75, 150, "https://example.com/db-basics");
    elements.add(t8);
    Tutorial t9=Tutorial("Functional Programming in Haskell", "Emily", 100, 200, "https://example.com/haskell-fp");
    elements.add(t9);
    Tutorial t10=Tutorial("Software Testing Techniques", "Mike", 60, 100, "https://example.com/software-testing");
    elements.add(t10);
}

bool Repo::tutorialExists(Tutorial tutorial) {
    for (int i = 0; i < this->elements.getSize(); i++) {
        if (this->elements.getElemsOnPosition(i).getTitle()==tutorial.getTitle()) {
            return true;
        }
    }
    return false;
}

void Repo::setRepo(Repo& repo){
    this->elements = repo.elements;
}

