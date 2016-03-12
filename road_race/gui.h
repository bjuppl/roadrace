#ifndef GUI_H
#define GUI_H

class GuiManager {

private:
    GuiManager *instance_;
    GuiManager();
 public:
    GuiManager& instance();

};


#endif // GUI_H
