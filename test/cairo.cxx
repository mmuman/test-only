//
// "$Id: arc.cxx 5115 2006-05-12 16:00:00Z fabien $"
//
// Arc drawing test program for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2006 by Bill Spitzak and others.
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Library General Public
// License as published by the Free Software Foundation; either
// version 2 of the License, or (at your option) any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Library General Public License for more details.
//
// You should have received a copy of the GNU Library General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA 02111-1307
// USA.
//
// Please report all bugs and problems to "fltk-bugs@fltk.org".
//

#include <config.h>

#if USE_CAIRO

#include <fltk/run.h>
#include <fltk/x.h>
#include <fltk/DoubleBufferWindow.h>
#include <fltk/ValueSlider.h>
#include <fltk/draw.h>
#include <fltk/math.h>

#define DEF_WIDTH 0.03

using namespace fltk;

class CairoWindow : public Window {
public:
    CairoWindow(int w, int h) : Window(w,h),draw_cb_(0) {}

    void draw() {
	Window::draw();
	if (draw_cb_)draw_cb_(*this, cc); // enjoy cairo features here !
    }
    
    typedef void (*draw_cb) (CairoWindow& self, cairo_t* def);
    void set_draw_cb(draw_cb  cb){draw_cb_=cb;}
private:
    draw_cb draw_cb_;
};

// put your drawing stuff here
float drawargs[7] = {90, 90, 100, 100, 0, 360, 0};
const char* name[7] = {"X", "Y", "W", "H", "start", "end", "rotate"};


void centered_text(cairo_t* cr, double x0,double y0,double w0,double h0, const char * my_text) {
    cairo_select_font_face (cr, "Sans", CAIRO_FONT_SLANT_OBLIQUE,CAIRO_FONT_WEIGHT_BOLD);
    cairo_set_source_rgba (cr, 0.9, 0.9, 0.4, 0.6);
    cairo_text_extents_t extents;
    cairo_text_extents (cr, my_text, &extents);
    double x = (extents.width/2 + extents.x_bearing);
    double y = (extents.height/2 + extents.y_bearing);
    cairo_move_to  (cr, x0+w0/2-x, y0+h0/2 - y);
    cairo_text_path(cr,my_text);
    cairo_fill_preserve (cr);
    cairo_set_source_rgba (cr, 0, 0, 0,1);
    cairo_set_line_width (cr, 0.004);
    cairo_stroke (cr);
    cairo_set_line_width (cr, DEF_WIDTH);


}

void round_button(cairo_t* cr, double x0, double y0, 
		  double rect_width, double rect_height, double radius,
		  double r, double g, double b) {
    
    double x1,y1;
    
    
    x1=x0+rect_width;
    y1=y0+rect_height;
    if (!rect_width || !rect_height)
	return;
    if (rect_width/2<radius) {
	if (rect_height/2<radius) {
	    cairo_move_to  (cr, x0, (y0 + y1)/2);
	    cairo_curve_to (cr, x0 ,y0, x0, y0, (x0 + x1)/2, y0);
	    cairo_curve_to (cr, x1, y0, x1, y0, x1, (y0 + y1)/2);
	    cairo_curve_to (cr, x1, y1, x1, y1, (x1 + x0)/2, y1);
	    cairo_curve_to (cr, x0, y1, x0, y1, x0, (y0 + y1)/2);
	} else {
	    cairo_move_to  (cr, x0, y0 + radius);
	    cairo_curve_to (cr, x0 ,y0, x0, y0, (x0 + x1)/2, y0);
	    cairo_curve_to (cr, x1, y0, x1, y0, x1, y0 + radius);
	    cairo_line_to (cr, x1 , y1 - radius);
	    cairo_curve_to (cr, x1, y1, x1, y1, (x1 + x0)/2, y1);
	    cairo_curve_to (cr, x0, y1, x0, y1, x0, y1- radius);
	}
    } else {
	if (rect_height/2<radius) {
	    cairo_move_to  (cr, x0, (y0 + y1)/2);
	    cairo_curve_to (cr, x0 , y0, x0 , y0, x0 + radius, y0);
	    cairo_line_to (cr, x1 - radius, y0);
	    cairo_curve_to (cr, x1, y0, x1, y0, x1, (y0 + y1)/2);
	    cairo_curve_to (cr, x1, y1, x1, y1, x1 - radius, y1);
	    cairo_line_to (cr, x0 + radius, y1);
	    cairo_curve_to (cr, x0, y1, x0, y1, x0, (y0 + y1)/2);
	} else {
	    cairo_move_to  (cr, x0, y0 + radius);
	    cairo_curve_to (cr, x0 , y0, x0 , y0, x0 + radius, y0);
	    cairo_line_to (cr, x1 - radius, y0);
	    cairo_curve_to (cr, x1, y0, x1, y0, x1, y0 + radius);
	    cairo_line_to (cr, x1 , y1 - radius);
	    cairo_curve_to (cr, x1, y1, x1, y1, x1 - radius, y1);
	    cairo_line_to (cr, x0 + radius, y1);
	    cairo_curve_to (cr, x0, y1, x0, y1, x0, y1- radius);
	}
    }
    cairo_close_path (cr);
    
    cairo_pattern_t *pat= 
	//cairo_pattern_create_linear (0.0, 0.0,  0.0, 1.0);
        cairo_pattern_create_radial (0.25, 0.24, 0.11, 0.24,  0.14, 0.35);
    cairo_pattern_set_extend (pat, CAIRO_EXTEND_REFLECT);
    
    cairo_pattern_add_color_stop_rgba (pat, 1.0, r, g, b, 1);
    cairo_pattern_add_color_stop_rgba (pat, 0.0, 1, 1, 1, 1);
    cairo_set_source (cr, pat);
    cairo_fill_preserve (cr);
    cairo_pattern_destroy (pat);

    //cairo_set_source_rgb (cr, 0.5,0.5,1);    cairo_fill_preserve (cr);
    cairo_set_source_rgba (cr, 0, 0, 0.5, 0.3);
    cairo_stroke (cr);

    cairo_set_font_size (cr, 0.08);
    centered_text(cr,x0,y0,rect_width, rect_height, "FLTK loves Cairo!");

}
void my_cairo_draw_cb(CairoWindow& window, cairo_t* cr) {
	
    int w= window.w(), h = window.h(); 

	
    double xc = 0.5;
    double yc = 0.5;
    double radius = 0.4;
    double angle1 = 45.0  * (M_PI/180.0);  /* angles are specified */
    double angle2 = 180.0 * (M_PI/180.0);  /* in radians           */
    
    cairo_set_line_width (cr, DEF_WIDTH);
    cairo_scale (cr, w,h);

    round_button(cr,0.1,0.05,0.8,0.2,0.4,0,0,1);
    round_button(cr,0.1,0.35,0.8,0.2,0.4,1,0,0);
    round_button(cr,0.1,0.65,0.8,0.2,0.4,0,1,0);
    return;


}

int main(int argc, char** argv) {
    CairoWindow window(300,300);
    window.resizable(&window);
    window.color(fltk::WHITE);
    window.show(argc,argv);
    window.set_draw_cb(my_cairo_draw_cb);
    
    return fltk::run();
}
#else
#include <fltk/ask.h>
int main(int argc, char** argv) {
  fltk::message("please configure fltk with CAIRO enabled (--enable-cairo)"); 
  return 0;
}

#endif

//
// End of "$Id: arc.cxx 5115 2006-05-12 16:00:00Z fabien $".
//
