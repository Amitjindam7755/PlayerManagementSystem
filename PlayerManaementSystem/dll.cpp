#include "dll.h"
#include <iostream>
#include <fstream>

DoublyLinkedList::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

DoublyLinkedList::~DoublyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = GET_NEXT(current);
        delete current;
        current = next;
    }
}

void DoublyLinkedList::addPlayer(int jerseyNumber, const std::string& name, int runs, int wickets, int matchesPlayed) {
    Player newPlayer;
    newPlayer.setData(jerseyNumber, name, runs, wickets, matchesPlayed);
    Node* newNode = new Node();
    newNode->setData(newPlayer);
    SET_NEXT(newNode, nullptr);
    SET_PREV(newNode, nullptr);

    if (head == nullptr) {
        head = tail = newNode;
    } else {
        Node* current = head;
        while (current != nullptr && current->getData().getJerseyNumber() < jerseyNumber) {
            current = GET_NEXT(current);
        }

        if (current == head) {
            SET_NEXT(newNode, head);
            head->setPrev(newNode);
            head = newNode;
        } else if (current == nullptr) {
            SET_NEXT(tail, newNode);
            newNode->setPrev(tail);
            tail = newNode;
        } else {
            SET_NEXT(newNode, current);
            SET_PREV(newNode, current->getPrev());
            current->getPrev()->setNext(newNode);
            current->setPrev(newNode);
        }
    }
}

void DoublyLinkedList::removePlayer(int jerseyNumber) {
    Node* target = searchPlayer(jerseyNumber);
    if (target == nullptr) {
        std::cout << "Player not found." << std::endl;
        return;
    }

    if (target == head) {
        head = GET_NEXT(head);
        if (head) head->setPrev(nullptr);
    } else if (target == tail) {
        tail = GET_PREV(tail);
        if (tail) tail->setNext(nullptr);
    } else {
        GET_PREV(target)->setNext(GET_NEXT(target));
        GET_NEXT(target)->setPrev(GET_PREV(target));
    }

    delete target;
    std::cout << "Player removed." << std::endl;
}

Node* DoublyLinkedList::searchPlayer(int jerseyNumber) {
    Node* current = head;
    while (current != nullptr && current->getData().getJerseyNumber() != jerseyNumber) {
        current = GET_NEXT(current);
    }
    return current;
}

Node* DoublyLinkedList::searchPlayerByName(const std::string& name) {
    Node* current = head;
    while (current != nullptr && current->getData().getName() != name) {
        current = GET_NEXT(current);
    }
    return current;
}

void DoublyLinkedList::updatePlayer(int jerseyNumber, int runs, int wickets, int matchesPlayed) {
    Node* target = searchPlayer(jerseyNumber);
    if (target != nullptr) {
        target->getData().updateStats(runs, wickets, matchesPlayed);
        std::cout << "Player updated." << std::endl;
    } else {
        std::cout << "Player not found." << std::endl;
    }
}

void DoublyLinkedList::displayAllPlayers() const {
    Node* current = head;
    while (current != nullptr) {
        Player p = current->getData();
        std::cout << "Jersey Number: " << p.getJerseyNumber() << ", Name: " << p.getName()
                  << ", Runs: " << p.getRuns() << ", Wickets: " << p.getWickets() 
                  << ", Matches Played: " << p.getMatchesPlayed() << std::endl;
        current = GET_NEXT(current);
    }
}

void DoublyLinkedList::displayTopPlayers() const {
    Node* current = head;
    Node* topRuns[3] = {nullptr, nullptr, nullptr};
    Node* topWickets[3] = {nullptr, nullptr, nullptr};

    while (current != nullptr) {
        for (int i = 0; i < 3; i++) {
            if (topRuns[i] == nullptr || current->getData().getRuns() > topRuns[i]->getData().getRuns()) {
                for (int j = 2; j > i; j--) {
                    topRuns[j] = topRuns[j-1];
                }
                topRuns[i] = current;
                break;
            }
        }

        for (int i = 0; i < 3; i++) {
            if (topWickets[i] == nullptr || current->getData().getWickets() > topWickets[i]->getData().getWickets()) {
                for (int j = 2; j > i; j--) {
                    topWickets[j] = topWickets[j-1];
                }
                topWickets[i] = current;
                break;
            }
        }
        current = GET_NEXT(current);
    }

    std::cout << "Top 3 Players by Runs:" << std::endl;
    for (int i = 0; i < 3 && topRuns[i] != nullptr; i++) {
        Player p = topRuns[i]->getData();
        std::cout << p.getName() << " - " << p.getRuns() << " Runs" << std::endl;
    }

    std::cout << "Top 3 Players by Wickets:" << std::endl;
    for (int i = 0; i < 3 && topWickets[i] != nullptr; i++) {
        Player p = topWickets[i]->getData();
        std::cout << p.getName() << " - " << p.getWickets() << " Wickets" << std::endl;
    }
}

void DoublyLinkedList::saveToFile(const std::string& filename) const {
    std::ofstream outFile(filename);
    Node* current = head;
    while (current != nullptr) {
        Player p = current->getData();
        outFile << p.getJerseyNumber() << " " << p.getName() << " " 
                << p.getRuns() << " " << p.getWickets() << " " 
                << p.getMatchesPlayed() << std::endl;
        current = GET_NEXT(current);
    }
    outFile.close();
}

void DoublyLinkedList::loadFromFile(const std::string& filename) {
    std::ifstream inFile(filename);
    if (!inFile.is_open()) return;

    int jn, r, w, mp;
    std::string n;

    while (inFile >> jn >> n >> r >> w >> mp) {
        addPlayer(jn, n, r, w, mp);
    }

    inFile.close();
}
