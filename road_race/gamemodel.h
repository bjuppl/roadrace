#ifndef GAMEMODEL_
#define GAMEMODEL_

#endif // GAMEMODEL_
class game{

  private:

  public:
    bool save();
    string load(instream file);
    void update();



};

class Command{
public:
    virtual bool execute();
    virtual ~command(){};
};

class buildCommand: public Command{
private:
    int id;
public:
    buildCommmand(int newId){
        id = newId;
    }

    bool execute();
};
class destroyCommand: public Command{
private:
    int id;
public:
    destroyCommand(int newId){
        id = newId;
    }
    bool execute();
};
class resourceCommand: public Command{
private:
    int resources;
    int squareid;
    int playerId;
public:
    resourceCommand(int id1,id2){
        squareid = id1;
        playerId = id2;
    }
    bool execute();
    bool get();
    bool store();
};
class dragonCommand: public Command{
private:
    int playerId;
    int x;
    int y;
    int hp;
    bool status;
public:
    dragonCommand(int sendId){
        playerId = sendId;
    }
    bool execute();
    bool die();
    bool damage();
};
