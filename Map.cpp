#include "Map.h"
map_node::map_node(){
        node_pixel = 0;
	node_clr = false;
}

map_node::~map_node(){;}

void map_node::setFeature(feature f){
        switch(f){
                case feature::GOAT:
                        node_pixel = 1;
                        break;
                case feature::GRASS:
                        node_pixel = 2;
                        break;
                case feature::EMPTY:
                        node_pixel = 0;
                        break;  
        }
        return ;
}

void map_node::setPosition(int x,int y){
        if(node_pixel == 1)goat_pixel.setPosition(x,y);
        if(node_pixel == 2)grass_pixel.setPosition(x,y);
        return ;
}

void map_node::setAge(int a){
        if(node_pixel == 1)goat_pixel.setAge(a);
        if(node_pixel == 2)grass_pixel.setAge(a);
        return ;
}

void map_node::setLife(int l){
        if(node_pixel == 1)goat_pixel.setLife(l);
        return ;
}

void map_node::setClr(bool c){
	node_clr = c;
}
feature map_node::getFeature(){
        switch(node_pixel){
                case 0:
                        return feature::EMPTY;
                case 1:
                        return feature::GOAT;
                case 2:
                        return feature::GRASS;
        }
}

int map_node::getPositionX(){
        if(node_pixel == 1)return goat_pixel.getPositionX();
        if(node_pixel == 2)return grass_pixel.getPositionX();
}

int map_node::getPositionY(){
        if(node_pixel == 1)return goat_pixel.getPositionY();
        if(node_pixel == 2)return grass_pixel.getPositionY();
}

int map_node::getAge(){
        if(node_pixel == 1)return goat_pixel.getAge();
        if(node_pixel == 2)return grass_pixel.getAge();
}

int map_node::getLife(){
        if(node_pixel == 1)return goat_pixel.getLife();
}

bool map_node::getCLR(){
	return node_clr;
}
map::map(){
	for(int i=0;i<Height;i++)
		for(int j=0;j<Width;j++)
			nodes[i][j].setFeature(feature::EMPTY);
}

map::~map(){;}

bool map::is_at_border(int height,int width,direction d){
        switch(d){
                case direction::UP:
                        if(height+1 <= Height)return true;
                        else return false;
                case direction::DOWN:
                        if(height-1 <= Height)return true;
                        else return false;
                case direction::RIGHT:
                        if(width+1 <= Width)return true;
                        else return false;
                case direction::LEFT:
                        if(width-1 <= Width)return true;
                        else return false;
        }
}
