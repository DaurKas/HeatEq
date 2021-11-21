#ifndef EXAMPLECHECK_H
#define EXAMPLECHECK_H
#include "linSys.h"

class Example : public LinSystem {
 
public:
    Example(Grid _grid);
    void setExampleMatrix();
    
};

#endif