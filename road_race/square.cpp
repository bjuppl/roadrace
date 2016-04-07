#include "square.h"
#include "gamemodel.h"
#include <QMouseEvent>
#include <QWidget>
#include <QLabel>
#include <QMessageBox>

int Square::count = 0, Square::size = 0, Square::border = 0;

std::string Square::getResourceType() {
    // Pl = plain, Ri = river, Mo = mountain, Fo = forest, Ca = canyon, Wi = winning block
    if ( type == "Pl") {
        return "";
    } else if ( type == "Ri" ) {
        return "Wa";
    } else if ( type == "Mo" ) {
        return "St";
    } else if ( type == "Fo" ) {
        return "Wo";
    } else if ( type == "Ca") {
        return "Go";
    } else if ( type == "Wi") {
        return "Wi";
    } else {
        return "";
    }
}


