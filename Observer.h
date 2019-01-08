//
// Created by frannuca on 06.01.19.
//

#ifndef ATTACKOVERTIME_OBSERVER_H
#define ATTACKOVERTIME_OBSERVER_H
#include <functional>
#include <string>
#include <map>
#include <vector>
#include <memory>


struct CallbackArgs;
class Observer;

class Subject {
public:
    enum class GROUPTYPE {COLLISIONS=0,UPGRADES,INJURED,GAMEOVER};

    Subject();
    void attach(Observer& observer,GROUPTYPE gtype);
    void notify(GROUPTYPE gtype,const CallbackArgs * args);

private:
    std::map<Subject::GROUPTYPE,std::vector<std::reference_wrapper<Observer>>> observerlist;

};

class Observer{
public:
    Observer()= default;
    virtual void notify(const CallbackArgs *args) = 0;
    ~Observer();
};

class CallbackArgs{
public:
    virtual Subject::GROUPTYPE group() const = 0;
};

class UpgradeCallBackArgs:public CallbackArgs{
public:
    int level;
    Subject::GROUPTYPE  group() const override{
        return Subject::GROUPTYPE::UPGRADES;
    }
};

class CollisionCallBackArgs:public CallbackArgs{
public:
    std::string object1tag;
    std::string object2tag;
    CollisionCallBackArgs(std::string o1, std::string o2);
    Subject::GROUPTYPE  group() const override{
        return Subject::GROUPTYPE::COLLISIONS;
    }
};

class InjureCallBackArgs:public CallbackArgs{
public:
    float damage;
    Subject::GROUPTYPE  group() const override{
        return Subject::GROUPTYPE::INJURED;
    }
};

class GameOverCallBackArgs:public CallbackArgs{
public:
    float damage;
    Subject::GROUPTYPE  group() const override{
        return Subject::GROUPTYPE::GAMEOVER;
    }
};


#endif //ATTACKOVERTIME_OBSERVER_H
