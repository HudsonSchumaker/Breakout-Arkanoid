//
// NGC
// Save.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <stdio.h>
#include <stdlib.h>
#include <gccore.h>
#include <fat.h>

class Save final {
    public: 
        Save();
        ~Save();

        void save(int level);
        int load();

    private:

};
