#ifndef PLAYER_H
#define PLAYER_H

#include <string>

class Player {
private:
    int jerseyNumber;
    std::string name;
    int runs;
    int wickets;
    int matchesPlayed;

public:
    void setData(int jerseyNumber, const std::string& name, int runs, int wickets, int matchesPlayed);
    int getJerseyNumber() const;
    std::string getName() const;
    int getRuns() const;
    int getWickets() const;
    int getMatchesPlayed() const;
    void updateStats(int runs, int wickets, int matchesPlayed);
};

#endif // PLAYER_H
