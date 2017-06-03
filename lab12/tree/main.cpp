//
// Created by albert on 31.05.17.
//

#include "Tree.h"

int main() {
    tree::Tree<int> t{889};
    t.Insert(15);
    t.Insert(17);
    t.Insert(24);
    t.Insert(22);
    t.Insert(220);
    std::cout << t.Value() << std::endl;
    return 0;
}