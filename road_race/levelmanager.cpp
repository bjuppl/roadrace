#include "levelmanager.h"

levelManager *levelManager::instance_ = nullptr;

levelManager& levelManager::instance() {
    if (instance_ == nullptr ) {
        instance_ = new levelManager();
    }

    return *instance_;
}
