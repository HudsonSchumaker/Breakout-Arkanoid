//
// NGC
// Save.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "Save.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <fat.h>

Save::Save() {
    fatInitDefault();
}

Save::~Save() {}

void Save::save(int level) {

}

int Save::load() {
    int level = 0;
    std::ifstream save;
    save.open("brekanoid.sav", std::ifstream::in);

    if(!save.fail()) {
        save >> level;
    }
    save.close();
    return level;
}