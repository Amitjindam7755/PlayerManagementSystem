#include "dll.h"
#include <iostream>

int main() {
    DoublyLinkedList playerList;
    int choice;

    do {
        DISPLAY_MENU();
        std::cout << "Enter your choice: ";
        std::cin >> choice;

        int jerseyNumber, runs, wickets, matchesPlayed;
        std::string name;
        Node* result;

        switch (choice) {
            case 1:
                std::cout << "Enter Jersey Number: ";
                std::cin >> jerseyNumber;
                std::cin.ignore();
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                std::cout << "Enter Runs: ";
                std::cin >> runs;
                std::cout << "Enter Wickets: ";
                std::cin >> wickets;
                std::cout << "Enter Matches Played: ";
                std::cin >> matchesPlayed;
                playerList.addPlayer(jerseyNumber, name, runs, wickets, matchesPlayed);
                break;

            case 2:
                std::cout << "Enter Jersey Number: ";
                std::cin >> jerseyNumber;
                playerList.removePlayer(jerseyNumber);
                break;

            case 3:
                std::cout << "Enter Jersey Number: ";
                std::cin >> jerseyNumber;
                result = playerList.searchPlayer(jerseyNumber);
                if (result != nullptr) {
                    Player p = result->getData();
                    std::cout << "Jersey Number: " << p.getJerseyNumber() << ", Name: " << p.getName()
                              << ", Runs: " << p.getRuns() << ", Wickets: " << p.getWickets() 
                              << ", Matches Played: " << p.getMatchesPlayed() << std::endl;
                } else {
                    std::cout << "Player not found." << std::endl;
                }
                break;

            case 4:
                std::cin.ignore();
                std::cout << "Enter Name: ";
                std::getline(std::cin, name);
                result = playerList.searchPlayerByName(name);
                if (result != nullptr) {
                    Player p = result->getData();
                    std::cout << "Jersey Number: " << p.getJerseyNumber() << ", Name: " << p.getName()
                              << ", Runs: " << p.getRuns() << ", Wickets: " << p.getWickets() 
                              << ", Matches Played: " << p.getMatchesPlayed() << std::endl;
                } else {
                    std::cout << "Player not found." << std::endl;
                }
                break;

            case 5:
                std::cout << "Enter Jersey Number: ";
                std::cin >> jerseyNumber;
                std::cout << "Enter Updated Runs: ";
                std::cin >> runs;
                std::cout << "Enter Updated Wickets: ";
                std::cin >> wickets;
                std::cout << "Enter Updated Matches Played: ";
                std::cin >> matchesPlayed;
                playerList.updatePlayer(jerseyNumber, runs, wickets, matchesPlayed);
                break;

            case 6:
                playerList.displayAllPlayers();
                break;

            case 7:
                playerList.displayTopPlayers();
                break;

            case 8:
                playerList.saveToFile("players.txt");
                break;

            case 9:
                playerList.loadFromFile("players.txt");
                break;

            case 0:
                std::cout << "Exiting program." << std::endl;
                break;

            default:
                std::cout << "Invalid choice, please try again." << std::endl;
        }

    } while (choice != 0);

    return 0;
}
