//
// Created by frannuca on 06.01.19.
//

#include "Observer.h"

Subject::Subject() {

}

void Subject::attach(Observer& observer, Subject::GROUPTYPE gtype) {

    if(observerlist.find(gtype) == observerlist.end()){
        observerlist[gtype]= std::vector<std::reference_wrapper<Observer>>();
    }
    observerlist[gtype].push_back(observer);
}

void Subject::notify(Subject::GROUPTYPE gtype, const CallbackArgs *args) {
    if(observerlist.find(gtype) != observerlist.end()){
        for(auto o:observerlist[gtype]){
            o.get().notify(args);
        }
    }
}

Observer::~Observer() {

}

CollisionCallBackArgs::CollisionCallBackArgs(std::string o1, std::string o2):object1tag(o1), object2tag(o2) {

}
