#ifndef GLASSDEFECT_H
#define GLASSDEFECT_H

/* This class is created
 * to model a defect instance with its all attributes 
**/
class GlassDefect
{
    public:
        GlassDefect();
        GlassDefect(unsigned int id, unsigned int pid, unsigned int x, unsigned int y, unsigned int w, unsigned int h);
        virtual ~GlassDefect();
        unsigned int Getdefect_id() { return defect_id; }
        unsigned int Getplate_id() { return plate_id; }
        unsigned int Getpos_x() { return pos_x; }
        unsigned int Getpos_y() { return pos_y; }
        unsigned int Getwidth() { return width; }
        unsigned int Getheight() { return height; }
		bool GetUsedx() { return used_x; }
		bool GetUsedy() { return used_y; }


        void Setdefect_id(unsigned int val) { defect_id = val; }
        void Setplate_id(unsigned int val) { plate_id = val; }
        void Setpos_x(unsigned int val) { pos_x = val; }
        void Setpos_y(unsigned int val) { pos_y = val; }
        void Setwidth(unsigned int val) { width = val; }
        void Setheight(unsigned int val) { height = val; }
		void SetUsed(bool a) { used_x = a; used_y = a; }
		void SetUsedx(bool a) { used_x = a; };
		void SetUsedy(bool a) { used_y = a; };
    protected:
    private:
        unsigned int defect_id; // Defect's Id.
        unsigned int plate_id; // Defect's plate Id
        unsigned int pos_x; // x position.
        unsigned int pos_y; // y position.
        unsigned int width; // Defect's width.
        unsigned int height; // Defect's height.
		bool used_x; //if we have used this deffect in x
		bool used_y; //if we have used this deffect in y
};

#endif // GLASSDEFECT_H
