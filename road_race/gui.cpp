#include "gui.h"

GuiManager& GuiManager::instance() {
    if (instance_ == NULL ) {
        instance_ = new GuiManager();
    }

    return *instance_;
}

