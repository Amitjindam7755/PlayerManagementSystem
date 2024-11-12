#include "player.h"

void Player::setData(int jerseyNumber, const std::string& name, int runs, int wickets, int matchesPlayed) {
    this->jerseyNumber = jerseyNumber;
    this->name = name;
    this->runs = runs;
    this->wickets = wickets;
    this->matchesPlayed = matchesPlayed;
}

int Player::getJerseyNumber() const {
    return this->jerseyNumber;
}

std::string Player::getName() const {
    return this->name;
}

int Player::getRuns() const {
    return this->runs;
}

int Player::getWickets() const {
    return this->wickets;
}

int Player::getMatchesPlayed() const {
    return this->matchesPlayed;
}

void Player::updateStats(int runs, int wickets, int matchesPlayed) {
    this->runs = runs;
    this->wickets = wickets;
    this->matchesPlayed = matchesPlayed;
}
