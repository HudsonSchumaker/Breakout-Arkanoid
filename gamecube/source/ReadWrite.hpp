//
// NGC
// Save.hpp
// SchumakerTeam Lab.
// Hudson Schumaker
//

#pragma once
#include <string>

class ReadWrite final {
    public: 
        ReadWrite();
        ~ReadWrite();

        void save(int level);
        int load();

    private:
        static const std::string fileName;

};
