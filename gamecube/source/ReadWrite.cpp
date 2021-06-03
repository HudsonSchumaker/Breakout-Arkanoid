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

const std::string ReadWrite::fileName = "breakanoid.sav";

ReadWrite::ReadWrite() {
    fatInitDefault();
}

ReadWrite::~ReadWrite() {}

void ReadWrite::save(int level) {
    std::ofstream mc;
    mc.open(fileName);
    mc << level;
    mc.close();
}

int ReadWrite::load() {
    int level = 0;
    std::ifstream mc;
    mc.open(fileName, std::ifstream::in);

    if(!mc.fail()) {
        mc >> level;
    }
    mc.close();
    return level;
}