#ifndef DLL_H
#define DLL_H

#include "node.h"
#include <string>

#define DISPLAY_MENU() std::cout << "Player Management System\n" \
                                << "1. Add Player\n" \
                                << "2. Remove Player\n" \
                                << "3. Search Player by Jersey Number\n" \
                                << "4. Search Player by Name\n" \
                                << "5. Update Player\n" \
                                << "6. Display All Players\n" \
                                << "7. Display Top Players\n" \
                                << "8. Save to File\n" \
                                << "9. Load from File\n" \
                                << "0. Exit\n"

class DoublyLinkedList {
private:
    Node* head;
    Node* tail;

public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    
    void addPlayer(int jerseyNumber, const std::string& name, int runs, int wickets, int matchesPlayed);
    void removePlayer(int jerseyNumber);
    Node* searchPlayer(int jerseyNumber);
    Node* searchPlayerByName(const std::string& name);
    void updatePlayer(int jerseyNumber, int runs, int wickets, int matchesPlayed);
    void displayAllPlayers() const;
    void displayTopPlayers() const;
    void saveToFile(const std::string& filename) const;
    void loadFromFile(const std::string& filename);
};

#endif // DLL_H
