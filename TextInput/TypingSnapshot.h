//
// Created by Kelly Lwin on 3/20/2023.
//

#ifndef SFML_TEMPLATE_TYPINGSNAPSHOT_H
#define SFML_TEMPLATE_TYPINGSNAPSHOT_H
#include <iostream>
#include <stack>

#include "MultiText.h"

struct TypingSnaps {
    std::list<Letter> list;
};

class TypingSnapshot {
private:
    std::stack<TypingSnaps> stack;
public:
    void pushHistory(const TypingSnaps& historyNode) {
        stack.push(historyNode);
    }
    TypingSnaps& topHistory() {
        if(!stack.empty()) {
            return stack.top();
        }
    }
    void popHistory() {
        if(!stack.empty()) {
            stack.pop();
        }
    }
};

#endif //SFML_TEMPLATE_TYPINGSNAPSHOT_H
