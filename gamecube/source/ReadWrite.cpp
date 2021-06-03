//
// NGC
// Save.cpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#include "ReadWrite.hpp"
#include <fat.h>
#include <gccore.h>
#include <fstream>

ReadWrite::ReadWrite() {
    fatInitDefault();
}

ReadWrite::~ReadWrite() {}

void ReadWrite::save(int level) {

}

int ReadWrite::load() {
    int level = 0;
    std::ifstream mc;
    mc.open("brekanoid.sav", std::ifstream::in);

    if(!mc.fail()) {
        mc >> level;
    }
    mc.close();
    return level;
}