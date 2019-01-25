#ifndef GLASSRECTANGLE_H
#define GLASSRECTANGLE_H

//#include "definitions.h"
#include "Glass.h"
#include "list"

#pragma warning(disable:4996)
using namespace std;

/* This class is created
 * to model a batch item instance with its all attributes 
**/
 class Glass;

class GlassRectangle
{

	
	unsigned int rectangle_id; // rectangle's Id.
	unsigned int rectangle_x; // rectangle's x position
	unsigned int rectangle_y; //rectangle's y position
	unsigned int pos_x; //candidate to put a item
	unsigned int pos_y; //candidate to put a item
	unsigned int rectangle_w; // rectangle's width.
	unsigned int rectangle_h; // rectangle's height.
	unsigned int parent;
	unsigned int R_w; // rectangle's width.
	unsigned int R_h; // rectangle's height.
	unsigned int rectangle_minx_defect; // rectangle's x position
	unsigned int rectangle_miny_defect; //rectangle's y position		
	int rectangle_nd; //rectangle's number of  defects
	unsigned int rectangle_scut; //1 vertical // 2  horizontal // 3 vertical
	std::list< GlassDefect > rectangle_defect_list; //lista de defectos del rectángulo
	static Glass *m_Glass;
    public:
		
        GlassRectangle(Glass *p);
		GlassRectangle(int, int x, int y, int w, int h, int side, int d,Glass *p);
//		GlassRectangle(int, GlassPlate &Plate);
		GlassRectangle(int id, int w, int h, std::list< GlassDefect > &, Glass *p, int ini=0);
		
		GlassRectangle(int, std::pair< std::pair< int, int >, std::pair< int, int > > &, GlassRectangle &R, Glass *p);
        virtual ~GlassRectangle();
        int GetRectangle_id() { return rectangle_id; }
		void Add_H(int a) { rectangle_h += a; R_h += a; };
		void Add_W(int a) { rectangle_w += a; R_w += a; };
		unsigned int Get_H() { return R_h; };
        unsigned int Get_w() { return rectangle_w; }
        unsigned int Get_h() { return rectangle_h; }
		unsigned int Getdefectminw() { return rectangle_minx_defect; }
		unsigned int Getdefectminh() { return rectangle_miny_defect; }
		unsigned int Getpos_x() { return rectangle_x; }
		unsigned int Getpos_y() { return rectangle_y; }
		unsigned int Get_x() { return pos_x; }
		unsigned int Get_y() { return pos_y; }
		unsigned int GetParent() { return parent; }
		void Addcut() { rectangle_scut++; }
		inline unsigned int Getpos_X() { return max(rectangle_x,pos_x)+rectangle_w; }
		inline unsigned int Getpos_Y() { return max(rectangle_y,pos_y)+rectangle_h; }
		inline unsigned int Getmin(){ return min(rectangle_w,rectangle_h); }
		inline unsigned int Getmax() { return max(rectangle_w, rectangle_h); }
		inline unsigned int GetArea() { return rectangle_w * rectangle_h; };
		unsigned int GetMin() { return min(rectangle_w, rectangle_h); }
		unsigned int Getnumdefects() { return rectangle_defect_list.size(); }
		std::list< GlassDefect > & Getdefectlist() { return rectangle_defect_list; };
		unsigned int  Getsidecut() { return rectangle_scut; }
		void Set_id(int val) { rectangle_id = val; }
		void Setcut(int val) { 
			rectangle_scut = val; }

		void Set_w(unsigned int val) { rectangle_w = val; R_w = val; }
        void Set_h(unsigned int val) { rectangle_h = val; R_h = val; }
		void Setpos_x(unsigned int val) { rectangle_x = val; pos_x = val; R_w = rectangle_w; }
		void Setpos_y(unsigned int val) { rectangle_y = val; pos_y = val; R_h = rectangle_h;}
		void SetParent(unsigned int val) { parent = val; }


		//Compute
		bool EverythingOK(int a);
		int BuscarPositionX(int,int);
		int BuscarPositionY(int,int);
		bool ChangePositionToPlaceNearest(int type);
		void InsertDefect(GlassDefect &D);
		void InsertDefectN(GlassDefect D);
		void ComputeLowest(void);
		void InsertDefects(std::list< GlassDefect >  & lista);
		void InsertDefectsRotate(std::list< GlassDefect >  & lista);
		void ChangeDimensionsNextDefect();
		void ModifyDefects();
		bool FindTheFollowingDefect(int x, int type);
		bool Overlap(int x1, int y1, int X1, int Y1);
		std::pair< int, int > NextDefect();
		//
		void Print();
		void PrintSolution();
		std::pair<int, int > ItemGreaterRN();
		std::pair<int, int > ItemGreaterR();



};

#endif // GLASSRECTANGLE_H
