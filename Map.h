#ifndef MAP_H
#define MAP_H
#define Height 50
#define Width 50
#include "Goat.h"
#include "Grass.h"
enum feature{
        GOAT,
        GRASS,
        EMPTY
};
enum direction{
        UP,
        DOWN,
        RIGHT,
        LEFT
};
class map_node{
        public:
                map_node();
                ~map_node();
                void setFeature(feature);
                void setPosition(int,int);
                void setAge(int);
                void setLife(int);
                void setCLR(bool);
                int getPositionX();
                int getPositionY();
                int getAge();
                int getLife();
                bool getCLR();
                feature getFeature();
		void nodeclear();
        private:
                goat goat_pixel;
                grass grass_pixel;
                int node_pixel;// 0 is empty;1 is goat;2 is grass
                bool node_clr;
};
class map{
        public:
                map();
                ~map();
                bool is_at_border(int,int,direction);
                map_node nodes[Height][Width];//Height 20;Width 35
};
#endif //MAP_H

