#ifndef CREATURE_H
#define CREATURE_H
class creature{
        public:
                creature();
                ~creature();
                void setPosition(int,int);
                void setAge(int);
                int getPositionX();
                int getPositionY();
                int getAge();
        private:
                int X;
                int Y;
                int Age;
};
#endif //CTREATURE

