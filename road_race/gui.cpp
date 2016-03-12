#include "gui.h"

GuiManager *GuiManager::instance_ = NULL;

GuiManager& GuiManager::instance() {
    if (instance_ == NULL ) {
        instance_ = new GuiManager();
    }

    return *instance_;
}

void GuiManager::generateSquareGrid() {

}

