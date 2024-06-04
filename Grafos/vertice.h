#ifndef VERTICE_H
#define VERTICE_H

#include <iostream>
#include <string>

using namespace std;

class Vertice {

    public:
        Vertice(string id);
        string getId();
    
    private:
        string _id;

};

#endif // VERTICE_H
