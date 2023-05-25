
#include "UI.h"
#include <iostream>
#include <cstdlib>
#include <windows.h>

UI::UI(){
}
void UI::printRepo(Repo repo){
    for(int i=0;i<repo.getNumTutorials();i++){
        const Tutorial& tutorial = repo.getTutorial(i);
        cout << tutorial.getTitle() << " - " << tutorial.getPresenter() << " - " << tutorial.getDuration() << "s - " << tutorial.getLikes() << " - " << tutorial.getLink() << "\n";
    }
}

void printRepo_presenter(Repo repo,string presenter){
    for(int i=0;i<repo.getNumTutorials();i++){
        const Tutorial& tutorial = repo.getTutorial(i);
        if(tutorial.getPresenter()==presenter){
            cout << tutorial.getTitle() << " - " << tutorial.getPresenter() << " - " << tutorial.getDuration() << "s - " << tutorial.getLikes() << " - " << tutorial.getLink() << "\n";
        }
    }
}

void UI::printFirstMenu() {
    admin_mode="-1";
    while (admin_mode=="-1"){
        printf("[1] Choose user mode.\n");
        printf("[2] Choose admin mode.\n");
        printf("[0] Exit.\n");
        cin>>admin_mode;
    }
    if(admin_mode=="0")
        exit(1);
    else{
        if(admin_mode=="2"){
            printAdminMenu();
        }
        else{
            printUserMenu();
        }
    }
}

void UI::printAdminMenu(){
    while(true){
        printf("[1] Add a tutorial.\n");
        printf("[2] Update a tutorial.\n");
        printf("[3] Remove a tutorial.\n");
        printf("[4] Print all tutorials.\n");
        printf("[0] Exit.\n");

        cin>>operation;
        if(operation=="1"){
            string title;
            string presenter;
            int duration;
            int likes;
            string link;
            printf("Title:\n");
            cin>>title;
            printf("Presenter:\n");
            cin>>presenter;
            printf("Duration in seconds:\n");
            cin>>duration;
            printf("Likes:\n");
            cin>>likes;
            printf("Link:\n");
            cin>>link;
            service.addTutorialSer(title,presenter,duration,likes,link);
        }
        if(operation=="4"){
            printRepo(service.getRepo());
        }
        if(operation=="0"){
            this->printFirstMenu();
        }
        if(operation=="2"){
            string title;
            string newPresenter;
            int newDuration;
            int newLikes;
            string newLink;
            printf("Title:\n");
            cin>>title;
            printf("New Presenter:\n");
            cin>>newPresenter;
            printf("New Duration in seconds:\n");
            cin>>newDuration;
            printf("New Likes:\n");
            cin>>newLikes;
            printf("New Link:\n");
            cin>>newLink;
            service.updateTutorialSer(title,newPresenter,newDuration,newLikes,newLink);
        }
        if(operation=="3"){
            string title;
            printf("Title:\n");
            getline(cin>>ws,title);
            service.removeTutorialSer(title);
        }
    }
}



void UI::printUserMenu(){
    Repo* watchlist1;
    printf("Choose the format of the watchlist (set to CSV by default):\n");
    printf("[1] CSV\n");
    printf("[2] HTML\n");
    printf("[0] Exit.\n");
    cin >> operation;
    if (operation == "1") {
        service.getRepo().setWatchlistFormat("CSV");
        watchlist1 = new RepoCSV();
    }
    if (operation == "2"){
        service.getRepo().setWatchlistFormat("HTML");
        watchlist1 = new RepoHTML();
    }
    if (operation == "0")
        this->printFirstMenu();
    Repo& watchlist = dynamic_cast<Repo&>(*watchlist1);
//    watchlist.readWatchlistFromFile(); // do not uncomment this line
    while(true){
        printf("[1] See the tutorials from a presenter.\n");
        printf("[2] Remove a tutorial.\n");
        printf("[3] See the watch list.\n");
        printf("[0] Exit.\n");
        cin>>operation;
        if(operation=="1"){
            string presenter;
            printf("Enter the name of the presenter:\n");
            printf("'-' is considered the empty string\n");

            cin>>presenter;

            if(presenter=="-"){
                int index=0;
                while(index<this->getService().getRepo().getNumTutorials()){
                    string operation2;
                    printTutorial(index);
                    printf("[1] Add to watch list.\n");
                    printf("[2] Skip.\n");
                    printf("[0] Stop.\n");
                    cin>>operation2;
                    if(operation2=="1"){
                        Tutorial add=this->getService().getRepo().getTutorial(index);
                        this->getService().addTutorialSer_user(watchlist,add);
                        watchlist.writeWatchlistToFile();
                        index++;
                    }
                    if(operation2=="2"){
                        index++;
                    }
                    if(operation2=="0"){
                        break;
                    }
                    if(index==this->getService().getRepo().getNumTutorials())
                        index=0;
                }
            }
            else{
                int index=0;
                while(index<this->getService().getRepo().getNumTutorials()){
                    string operation2;
                    if(this->getService().getRepo().getTutorial(index).getPresenter()==presenter){
                        printTutorial(index);
                        printf("[1] Add to watch list.\n");
                        printf("[2] Skip.\n");
                        printf("[0] Stop.\n");
                        cin>>operation2;
                        if(operation2=="1"){
                            Tutorial add=this->getService().getRepo().getTutorial(index);
                            this->getService().addTutorialSer_user(watchlist,add);
                            watchlist.writeWatchlistToFile();
                            index++;
                        }
                        if(operation2=="2"){
                            index++;
                        }
                        if(operation2=="0"){
                            break;
                        }
                    }
                    else{
                        index++;
                    }
                    if(index==this->getService().getRepo().getNumTutorials())
                        index=0;
                }
            }
        }
        if(operation=="0"){
            this->printFirstMenu();
        }
        if(operation=="3"){
            printRepo(watchlist);
            watchlist.showWatchlistFromFile();
        }
        if(operation=="2"){
            string title;
            printf("Title of the tutorial you want to remove:\n");
            getline(cin>>ws,title);
            this->getService().removeTutorialSer_user(watchlist,title);
            watchlist.writeWatchlistToFile();
        }
    }
}

Services& UI::getService(){
    return this->service;
}

void UI::printTutorial(int index){
    Tutorial tutorial=this->getService().getRepo().getTutorial(index);
    cout << tutorial.getTitle() << " - " << tutorial.getPresenter() << " - " << tutorial.getDuration() << "s - " << tutorial.getLikes() << " - " << tutorial.getLink() << "\n";
}

