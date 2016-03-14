#ifndef LEVELMANAGER_H
#define LEVELMANAGER_H

class levelManager {

private:
    static levelManager *instance_;

    levelManager(){}
 public:
    static levelManager& instance();

};


#endif // LEVELMANAGER_H
