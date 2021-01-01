#ifndef GOAT_H
#define GOAT_H
#include "Creature.h"

class goat:public creature{
        public:
                goat();
                ~goat();
                void setLife(int);
                int getLife();
        private:
                int Life;
};


#endif //GOAT_H

