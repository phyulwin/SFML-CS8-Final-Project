//
// Created by Kelly Lwin on 3/9/2023.
//

#ifndef SFML_TEMPLATE_HISTORY_H
#define SFML_TEMPLATE_HISTORY_H
#include <stack>
#include "../GUI_Component.h"

struct HistoryNode
{
    Snapshot* snapshot; //Snapshot* snapshot
    GUI_Component* component;
};

class History  {
private:
    inline static std::stack<HistoryNode> stack;
public:
    static void pushHistory(const HistoryNode& historyNode);
    static HistoryNode& topHistory();
    static void popHistory();
    static void addEventHandler(sf::RenderWindow& window, sf::Event event);
};

#endif //SFML_TEMPLATE_HISTORY_H
