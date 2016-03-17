#include "levelmanager.h"

LevelManager *LevelManager::instance_ = nullptr;

LevelManager& LevelManager::instance() {
    if (instance_ == nullptr ) {
        instance_ = new LevelManager();
    }

    return *instance_;
}

std::vector<std::string> LevelManager::getLevel(int num) {
    std::vector<std::string> contents;
    return contents;

}

std::vector<std::string> LevelManager::getLevel(std::string level ) {
    std::vector<std::string> contents;
    const std::string test = "test";
    if ( level == test ) {
        int o = 1;
        if ( o == 1 ) { contents = resourceFileContents("single-player"); }
        else { contents = resourceFileContents("sampleGame"); }
    }
    return contents;

}

std::vector<std::string> LevelManager::resourceFileContents(std::string alias ) {
    QFile file(QString::fromStdString(":/" + alias));
    std::vector<std::string> ret;
    if(file.open(QFile::ReadOnly)) {
        QTextStream conts(&file);

        while(!conts.atEnd()) {
            QString ln = conts.readLine();
            ret.push_back(ln.toStdString());
        }

        file.close();

        return ret;

    } else {
        std::cerr << "Failed to read resource file: '" << alias << "'. " << std::endl;

        return ret;
    }
}
