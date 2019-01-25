#ifndef GLASSNODEB_H
#define GLASSNODEB_H

#include <ostream>
#include <vector>
#include <list>
#include "GlassRsol.h"
/* This class is created
* to model a solution node instance with its all attributes
**/
class GlassNodeB {
public:
	GlassNodeB();
	GlassNodeB(unsigned int Inicio, unsigned int Plates, unsigned int Total_area,	unsigned int Total_area_used,unsigned int Total_width_bin,	unsigned int Objective_function,
	unsigned int Partial_objective_function,	unsigned int MinDimensionPieza, std::vector< std::vector < int > > Matrix_Items,	std::vector< int > Vector_Stacks,
	std::vector< bool > Vector_Items,	std::list< GlassRsol> Sol_Items);
	virtual ~GlassNodeB();
	double Utilization() {
		return _Utilization;
	};
	double Utilization2() {
		return _Utilization2;
	};
	unsigned int Inicio() {
		return _Inicio;
	};
	unsigned int Plates() {
		return _Plates;
	};
	unsigned int Total_area() {
		return _Total_area;
	}; // Sum of total area of items.
	unsigned int Total_area_used()
	{
		return _Total_area_used;
	};//Suma of used area partial
	unsigned int Total_width_bin()
	{
		return _Total_width_bin;
	};
	unsigned int Max_First_Bin()
	{
		return _Max_First_Bin;
	};
	unsigned int Objective_function()
	{
		return _Objective_function;
	};
	unsigned int Partial_objective_function()
	{
		return _Partial_objective_function;
	};// Percentaje per thousand
	unsigned int MinDimensionPieza()
	{
		return _MinDimensionPieza;
	};
	unsigned int MaxMinDimensionPieza()
	{
		return _MaxMinDimensionPieza;
	};
	std::vector< std::vector < int > > &Matrix_Items()
	{
		return _Matrix_Items;
	};
	// the size of this vector is the number of stacks, the first number is 
	//which is the first item possible to place
	std::vector< int > &Vector_Stacks(){
		return _Vector_Stacks;
	};
	std::vector< bool > &Vector_Items(){
		return _Vector_Items;
	};
	
	std::list< GlassRsol> &Sol_Items(){
		return _Sol_Items;
	};
	//set functions
	void Inicio(unsigned int a)
	{
		_Inicio = a;
	};
	void Plates(unsigned int a)
	{
		_Plates = a;
	};
	void Total_area(unsigned int a) {
		_Total_area=a;
	}; // Sum of total area of items.
	void Total_area_used(unsigned int a)
	{
		_Total_area_used=a;
	};//Suma of used area partial
	void Total_width_bin(unsigned int a)
	{
		_Total_width_bin=a;
	};
	void Max_First_Bin(unsigned int a)
	{
		_Max_First_Bin = a;
	};
	void Objective_function(unsigned int a)
	{
		_Objective_function=a;
	};
	void Utilization(double a)
	{
		_Utilization = a;
	};
	void Utilization2(double a)
	{
		_Utilization2 = a;
	};
	void Partial_objective_function(unsigned int a)
	{
		_Partial_objective_function=a;
	};// Percentaje per thousand
	void MinDimensionPieza(unsigned int a)
	{
		_MinDimensionPieza=a;
	};
	void MaxMinDimensionPieza(unsigned int a)
	{
		_MaxMinDimensionPieza = a;
	};
	void Matrix_Items(std::vector< std::vector < int > > a)
	{
		_Matrix_Items=a;
	};
	// the size of this vector is the number of stacks, the first number is 
	//which is the first item possible to place
	void Vector_Stacks(std::vector< int > a) {
		_Vector_Stacks=a;
	};
	void Vector_Items(std::vector< bool > a) {
		_Vector_Items=a;
	};

	void Sol_Items(std::list< GlassRsol> a) {
		_Sol_Items=a;
	};
/*	friend std::ostream & operator<<(std::ostream& os, GlassNode node) {
		os << "Node (p,id,x,y,w,h,t,s) = (" << node._plateId << "," << node._id << "," << node._x << "," << node._y << "," << node._w << "," << node._h << "," << node._nodeType << "," << node.cut << ")";
		return os;
	}*/

//public:
//	GlassNode * successor; // Successor nodes list.
protected:
private:
	double _Utilization;
	double _Utilization2=0;
	unsigned int _Inicio;
	unsigned int _Plates;
	unsigned int _Total_area; // Sum of total area of items.
	unsigned int _Total_area_used;//Suma of used area partial
	unsigned int _Total_width_bin;
	unsigned int _Max_First_Bin=0;
	unsigned int _Objective_function;
	unsigned int _Partial_objective_function;// Percentaje per thousand
	unsigned int _MinDimensionPieza;
	unsigned int _MaxMinDimensionPieza;
	std::vector< std::vector < int > > _Matrix_Items;
	// the size of this vector is the number of stacks, the first number is 
	//which is the first item possible to place
	std::vector< int > _Vector_Stacks;
	std::vector< bool > _Vector_Items;

	std::list< GlassRsol> _Sol_Items;
};

#endif // GLASSNODEB_H
