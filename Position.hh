#pragma once
#include <string>
#include <vector>
#include <memory>

using coord= signed short;

class Position{
	public:
		/*constructeurs*/
		Position(coord x, coord y,int maxX,int maxY):
			x(x),y(y),maxX(maxX),maxY(maxY){}
		Position(Position const & p) =default;

		/*operator equal*/
		Position & operator=(Position const & p) =default;

		/*accesseur*/
		coord getX() const{return x;}
		coord getY() const{return y;}
		void setX(coord x){x=x;}
		void setY(coord y){y=y;}

		/*operators*/
		bool operator==(Position const & p) const{return (x==p.x)&&(y==p.y);}
		bool operator!=(Position const & p) const{return !operator==(p);}
		bool estValide() const{return ((x>= 0) && (x<=maxX) && (y>=0) && (y<=maxY));}

	private:
		coord x;
		coord y;
		int maxX;
		int maxY;
};
