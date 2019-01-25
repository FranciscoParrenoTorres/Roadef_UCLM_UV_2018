#ifndef GLASSRSOL_H
#define GLASSRSOL_H

#include <ostream>

/* This class is created
* to model a solution Rsol instance with its all attributes
**/
class GlassRsol {
public:
	GlassRsol();
	GlassRsol(unsigned int plate, unsigned int Rsol, unsigned int x,
	unsigned int y, unsigned int w, unsigned int h,
		int t, unsigned int c, unsigned int p, unsigned int n);
	GlassRsol(unsigned int plate, unsigned int Rsol, unsigned int x,
		unsigned int y, unsigned int w, unsigned int h,
		int t, unsigned int c, unsigned int p);
	GlassRsol(unsigned int plate, unsigned int Rsol, unsigned int x,
		unsigned int y, unsigned int w, unsigned int h,
		int t, unsigned int c);
	virtual ~GlassRsol();

	unsigned int plateId() {
		return _plateId;
	}

	unsigned int id() {
		return _id;
	}

	unsigned int x() {
		return _x;
	}

	unsigned int y() {
		return _y;
	}

	unsigned int w() {
		return _w;
	}

	unsigned int h() {
		return _h;
	}
	unsigned int X() {
		return _X;
	}

	unsigned int Y() {
		return _Y;
	}
	int RsolType() {
		return _RsolType;
	}

	unsigned int Getcut() {
		return cut;
	}
	unsigned int copiesx() {
		return _copiesx;
	}
	unsigned int copiesy() {
		return _copiesy;
	}
	unsigned int iditem() {
		return _iditem;
	}
	unsigned int Getparent() {
		return parent;
	}

	unsigned int Getsuccessor_nbr() {
		return successor_nbr;
	}



	


	void plateId(unsigned int id) {
		_plateId = id;
	}

	void SetRsol_id(unsigned int id) {
		_id = id;
	}

	void x(unsigned int x) {
		_x = x;
	}

	void y(unsigned int y) {
		_y = y;
	}

	void w(unsigned int w) {
		_w = w;
	}
	void iditem(unsigned int y) {
		_iditem = y;
	}
	void copiesx(unsigned int y) {
		_copiesx = y;
	}
	void copiesy(unsigned int w) {
		_copiesy = w;
	}
	void h(unsigned int h) {
		_h = h;
	}
	void X(unsigned int w) {
		_X = w;
	}

	void Y(unsigned int h) {
		_Y = h;
	}
	void RsolType(int t) {
		_RsolType = t;
	}

	void Setcut(unsigned int c) {
		cut = c;
	}

	void Setparent(unsigned int p) {
		parent = p;
	}

	void Setchild_nbr(unsigned int nbr) {
		successor_nbr = nbr;
	}



	friend std::ostream & operator<<(std::ostream& os, GlassRsol Rsol) {
		os << "Rsol (p,id,x,y,w,h,t,s) = (" << Rsol._plateId << "," << Rsol._id << "," << Rsol._x << "," << Rsol._y << "," << Rsol._w << "," << Rsol._h << "," << Rsol._RsolType << "," << Rsol.cut << ")";
		return os;
	}


protected:
private:
	unsigned int _plateId; // Plate Id.
	unsigned int _id; // Rsol Id.
	unsigned int _iditem; // Rsol Id.
	unsigned int _x; // x position.
	unsigned int _y; // y position.
	unsigned int _w; // Plate's width.
	unsigned int _h; // Plate's height.
	unsigned int _X; // Plate's width.
	unsigned int _Y; // Plate's height.
	unsigned int _copiesx; // Plate's width.
	unsigned int _copiesy; // Plate's height.

	int _RsolType; /* Rsol type
				   * > 0 glass piece index in batch file.
				   * = -1 wasted glass.
				   * = -2 branch.
				   * = -3 residual.
				   */
	unsigned int cut; // cut G_level (there are 1, 2, 3 and 4-cut G_level, could not be 0-cut because GlassRsol class instance can't be an entire plate).
	unsigned int parent; // parent Rsol Id.
	unsigned int successor_nbr; // number of G_children for this Rsol instance.
};

#endif // GLASSRSOL_H
