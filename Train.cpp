#include <iostream>
#include "Train.h"

Train::Train()
: Moyen(1000, 250, 1.5)
{
    std::cout << "Train créé" << std::endl;
}

Train::~Train()
{}
