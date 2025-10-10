//#include <gsl/gsl_math.h>
//#include <FL/fl_draw.H>
#include <math.H>
#include "fl_small_stuff.h"

void Fl_Rotated_Label::draw(){
    draw_box();
    fl_color(color());
    fl_rectf(x(),y(),w(),h());

    fl_font(labelfont(), labelsize());
    fl_color(labelcolor());
    int dx(0),dy(0);

    if(rt_align&FL_ALIGN_CLIP)fl_push_clip(x(),y(),w(),h());
    else fl_push_no_clip();
    fl_measure(rt_text.c_str(),dx,dy);
    if(rt_align&FL_ALIGN_LEFT){
      dx=dy=0;
    }else if(rt_align&FL_ALIGN_RIGHT){
      dy=(int)(-sin(M_PI*(double)(rt_angle+180)/180.)*(double)dx);
      dx=(int)(cos(M_PI*(double)(rt_angle+180)/180.)*(double)dx);
    }else{
      dy=(int)(sin(M_PI*(double)rt_angle/180.)*(double)dx);
      dx=(int)(-cos(M_PI*(double)rt_angle/180.)*(double)dx);
      dx/=2;dy/=2;
    }
    fl_draw(rt_angle,rt_text.c_str(),x()+w()/2+dx,y()+h()/2+dy);
    fl_pop_clip();

  };
