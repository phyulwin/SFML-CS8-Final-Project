//
// Created by Kelly Lwin on 3/9/2023.
//

#include "History.h"

void History::pushHistory(const HistoryNode &historyNode) {
    stack.push(historyNode);
}

HistoryNode &History::topHistory() {
    return stack.top();
}

void History::popHistory() {
    stack.pop();
//    stack.top().component->applySnapshot(stack.top().snapshot);
}

void History::addEventHandler(sf::RenderWindow &window, sf::Event event) {

}
