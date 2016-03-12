#include "gui.h"
#include "roadrace.h"
#include "gamemodel.h"

GuiManager *GuiManager::instance_ = NULL;

GuiManager& GuiManager::instance() {
    if (instance_ == NULL ) {
        instance_ = new GuiManager();
    }

    return *instance_;
}

void GuiManager::generateSquareGrid() {
    std::cout << getUi()->label->text().toStdString() << std::endl;
}

