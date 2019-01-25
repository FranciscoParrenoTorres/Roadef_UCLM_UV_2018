#include "GlassDefect.h"

GlassDefect::GlassDefect()
{
    //ctor
}

GlassDefect::GlassDefect(unsigned int id, unsigned int pid, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
    defect_id = id;
    plate_id = pid;
    pos_x = x;
    pos_y = y;
    width = w;
    height = h;
	used_x = false;
	used_y = false;
}

GlassDefect::~GlassDefect()
{
    //dtor
}
