#ifndef MAP_H
#define MAP_H
#include"Goat.h"
#include"Grass.h"
#define Height 20
#define Width 35
enum class feature{
	GRASS,
	GOAT,
	EMPTY
};
class map_node{
	public:
		map_node();
		~map_node();
		void setPixel(goat *,grass *);//
		void clearPixel();//
		feature getPixel();//
		map_node operator=(map_node);//
		goat *getGoatPixel();//
		grass *getGrassPixel();//
		void deletePixel();
		int getGoatLife();
		void addGoatLife();
		void minusGoatLife();
		int getYear();
		void addYear();		
	protected:
	private:
		grass *grass_pixel;
		goat *goat_pixel;
		
};
class map{
	public:
		map();
		~map();
		bool is_at_border(int &,int &,direction);//
		map_node all_node[Height][Width];
	protected:
	private:
};
#endif //MAP_H
