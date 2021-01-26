#ifndef GOAT_H
#define GOAT_H
#include "Animal.h"

class goat:public animal{
        public:
                goat();
                ~goat();
                void setLife(int);
                int getLife();
        private:
                int Life;
};


#endif //GOAT_H

