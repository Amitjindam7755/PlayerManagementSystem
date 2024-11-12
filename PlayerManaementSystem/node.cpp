#include "node.h"

void Node::setData(const Player& player) {
    this->player = player;
}

Player Node::getData() const {
    return this->player;
}

void Node::setNext(Node* next) {
    this->next = next;
}

Node* Node::getNext() const {
    return this->next;
}

void Node::setPrev(Node* prev) {
    this->prev = prev;
}

Node* Node::getPrev() const {
    return this->prev;
}
