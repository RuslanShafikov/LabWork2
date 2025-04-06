
#ifndef GAMERELOADER_H
#define GAMERELOADER_H


#include "../Team/Team.h"
#include <string>
#include <utility> // For std::pair

class GameReloader {
public:
    static std::pair<Team, Team> readFile(const std::string& filename);
    static void saveGame(const Team& teamA, const Team& teamB, const std::string& filename );
};

#endif // GAMERELOADER_H