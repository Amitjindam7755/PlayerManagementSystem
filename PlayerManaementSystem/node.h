#ifndef NODE_H
#define NODE_H

#include "player.h"

#define SET_NEXT(node, next_node) (node)->setNext(next_node)
#define GET_NEXT(node) (node)->getNext()
#define SET_PREV(node, prev_node) (node)->setPrev(prev_node)
#define GET_PREV(node) (node)->getPrev()

class Node {
private:
    Player player;
    Node* next;
    Node* prev;

public:
    void setData(const Player& player);
    Player getData() const;
    void setNext(Node* next);
    Node* getNext() const;
    void setPrev(Node* prev);
    Node* getPrev() const;
};

#endif // NODE_H
