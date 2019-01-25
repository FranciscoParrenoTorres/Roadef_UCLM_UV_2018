#ifndef GLASSITEM_H
#define GLASSITEM_H

#include <stdio.h>

#include <algorithm>
#include "list"

using namespace std;

/* This class is created
 * to model a batch item instance with its all attributes 
**/
class GlassItem
{
    public:
        GlassItem();
        virtual ~GlassItem();
        int Getitem_id() { return item_id; }
		unsigned int Getitem_w(bool h) { return (h==true) ? (max(item_w,item_h)): (min(item_w, item_h)); }
		unsigned int Getitem_h(bool h) { return (h==true) ? (min(item_w, item_h)) : (max(item_w, item_h));}
        unsigned int Getitem_w() { return item_w; }
        unsigned int Getitem_h() { return item_h; }
        unsigned int Getitem_stack() { return item_stack; }
        unsigned int Getitem_seq() { return item_seq; }
		unsigned int Getitem_num() { return item_num; }
		inline unsigned int Getitem_area() { return (item_h*item_w); }
		inline unsigned int Getitem_max() { return (item_w > item_h)?item_w:item_h; }
		inline unsigned int Getitem_min() { return (item_w > item_h)?item_h:item_w; }
		void Setitem_id(int val) { item_id = val; }
        void Setitem_w(unsigned int val) { item_w = val; }
        void Setitem_h(unsigned int val) { item_h = val; }
        void Setitem_stack(unsigned int val) { item_stack = val; }
        void Setitem_seq(unsigned int val) { item_seq = val; }
		void Setitem_num(unsigned int val) { item_num = val; }
		void Add_num() { item_num++; }
		bool item_compare(const GlassItem &GA, const GlassItem &GB);
		void Print(bool a=false) { if (a==true) printf("Pieza %d Stack %d w %d h %d\n", item_id,item_stack,item_h,item_w); };
		
    protected:
    private:
        int item_id; // Item's Id.
        unsigned int item_w; // Item's width.
        unsigned int item_h; // Item's height.
        unsigned int item_stack; // Item's stack Id
        unsigned int item_seq; // Item's stack sequence.
		unsigned int item_num;//Item's num copies.
		
};

#endif // GLASSITEM_H
