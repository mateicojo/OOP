//
// Created by mok_a on 4/2/2023.
//

#pragma once
#include "Domain.h"
#include "Repo.h"
#include "Service.h"
#include <cassert>

void testDomain(){
    Tutorial tutorial("Introduction to C++", "John Doe", 60, 100, "https://example.com");
    assert(tutorial.getTitle() == "Introduction to C++");
    assert(tutorial.getPresenter() == "John Doe");
    assert(tutorial.getDuration() == 60);
    assert(tutorial.getLikes() == 100);
    assert(tutorial.getLink() == "https://example.com");
    tutorial.setTitle("Advanced C++ Programming");
    tutorial.setPresenter("Jane Smith");
    tutorial.setDuration(90);
    tutorial.setLikes(200);
    tutorial.setLink("https://example.com/advanced-cpp");
    assert(tutorial.getTitle() == "Advanced C++ Programming");
    assert(tutorial.getPresenter() == "Jane Smith");
    assert(tutorial.getDuration() == 90);
    assert(tutorial.getLikes() == 200);
    assert(tutorial.getLink() == "https://example.com/advanced-cpp");
    printf("Domain tested.\n");
}

void testAddTutorial() {
    Repo repo;
    Tutorial tutorial1("Introduction to C++", "John Smith", 60, 100, "https://example.com/cpp-intro");
    repo.addTutorial(tutorial1);
    assert(repo.getNumTutorials() == 1);
    assert(repo.getTutorial(0).getTitle() == "Introduction to C++");
    Tutorial tutorial2("Object-Oriented Programming with Java", "Jane Doe", 90, 200, "https://example.com/java-oop");
    repo.addTutorial(tutorial2);
    assert(repo.getNumTutorials() == 2);
    assert(repo.getTutorial(1).getTitle() == "Object-Oriented Programming with Java");
    repo.addTutorial(tutorial1);
    assert(repo.getNumTutorials() == 2);
}

void testRemoveTutorial() {
    Repo repo;
    Tutorial t1("Introduction to C++", "John Smith", 60, 100, "https://example.com/cpp-intro");
    Tutorial t2("Object-Oriented Programming with Java", "Jane Doe", 90, 200, "https://example.com/java-oop");
    Tutorial t3("Python Fundamentals", "Bob Johnson", 120, 300, "https://example.com/python-fundamentals");
    repo.addTutorial(t1);
    repo.addTutorial(t2);
    repo.addTutorial(t3);
    repo.removeTutorial("Object-Oriented Programming with Java");
    assert(repo.getNumTutorials() == 2);  // should have 2 tutorials left
    assert(repo.getTutorial(0).getTitle() == "Introduction to C++");  // t1 should be at index 0
    assert(repo.getTutorial(1).getTitle() == "Python Fundamentals");  // t3 should be at index 1
    assert(!repo.tutorialExists(t2));  // t2 should no longer exist in the repo
}

void testUpdateTutorial() {
    Repo repo;
    repo.addTenEntities();
    Tutorial updatedTutorial("Python Fundamentals", "Bob Johnson", 120, 350, "https://example.com/python-advanced");
    repo.updateTutorial("Python Fundamentals", updatedTutorial);
    assert(repo.getNumTutorials() == 10);
    assert(repo.getTutorial(2).getTitle() == "Python Fundamentals");
    assert(repo.getTutorial(2).getPresenter() == "Bob Johnson");
    assert(repo.getTutorial(2).getDuration() == 120);
    assert(repo.getTutorial(2).getLikes() == 350);
    assert(repo.getTutorial(2).getLink() == "https://example.com/python-advanced");
    Tutorial nonExistingTutorial("Non-existing tutorial", "John Doe", 90, 200, "https://example.com/non-existing");
    repo.updateTutorial("Non-existing tutorial", nonExistingTutorial);
    assert(repo.getNumTutorials() == 10);
}

void testAddTenEntities() {
    Repo repo;
    repo.addTenEntities();
    assert(repo.getNumTutorials() == 10);
}

void testTutorialExists() {
    Repo repo;
    Tutorial tutorial1("Introduction to C++", "John Smith", 60, 100, "https://example.com/cpp-intro");
    Tutorial tutorial2("Object-Oriented Programming with Java", "Jane Doe", 90, 200, "https://example.com/java-oop");
    Tutorial tutorial3("Python Fundamentals", "Bob Johnson", 120, 300, "https://example.com/python-fundamentals");
    repo.addTutorial(tutorial1);
    repo.addTutorial(tutorial2);
    assert(repo.tutorialExists(tutorial1));
    assert(repo.tutorialExists(tutorial2));
    assert(!repo.tutorialExists(tutorial3));
}

void testRepo(){
    testAddTutorial();
    testRemoveTutorial();
    testAddTenEntities();
    testTutorialExists();
    testUpdateTutorial();
    printf("Repo tested.\n");
}

void test_addTutorialSer() {
    Repo repository;
    Services services=Services();
    assert(services.getRepo().getNumTutorials() == 0);
    services.addTutorialSer("Introduction to C++", "John Smith", 60, 100, "https://example.com/cpp-intro");
    assert(services.getRepo().getNumTutorials() == 1);
    Tutorial t = services.getRepo().getTutorial(0);
    assert(t.getTitle() == "Introduction to C++");
    assert(t.getPresenter() == "John Smith");
    assert(t.getDuration() == 60);
    assert(t.getLikes() == 100);
    assert(t.getLink() == "https://example.com/cpp-intro");
}

void test_updateTutorialSer() {
    Repo repository;
    Services services=Services();
    services.addTutorialSer("Introduction to C++", "John Smith", 60, 100, "https://example.com/cpp-intro");
    services.updateTutorialSer("Introduction to C++", "Jane Doe", 90, 200, "https://example.com/cpp-updated");
    Tutorial t = services.getRepo().getTutorial(0);
    assert(t.getTitle() == "Introduction to C++");
    assert(t.getPresenter() == "Jane Doe");
    assert(t.getDuration() == 90);
    assert(t.getLikes() == 200);
    assert(t.getLink() == "https://example.com/cpp-updated");
}

void test_removeTutorialSer() {
    Repo repository;
    Services services=Services();
    services.addTutorialSer("Introduction to C++", "John Smith", 60, 100, "https://example.com/cpp-intro");
    services.removeTutorialSer("Introduction to C++");
    assert(services.getRepo().getNumTutorials() == 0);
}

void testServices(){
    test_addTutorialSer();
    test_removeTutorialSer();
    test_updateTutorialSer();
    printf("Services tested.\n");
}

void runTests(){
    testDomain();
    testRepo();
    testServices();
}
