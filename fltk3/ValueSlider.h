//
// "$Id: ValueSlider.h 7981 2010-12-08 23:53:04Z greg.ercolano $"
//
// Value slider header file for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2010 by Bill Spitzak and others.
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
// Please report all bugs and problems on the following page:
//
//     http://www.fltk.org/str.php
//

/* \file
 fltk3::ValueSlider widget . */

#ifndef Fltk3_Value_Slider_H
#define Fltk3_Value_Slider_H

#include "Slider.h"

namespace fltk3 {
  
  /**
   The fltk3::ValueSlider widget is a fltk3::Slider widget
   with a box displaying the current value.
   <P ALIGN=CENTER>\image html value_slider.png 
   \image latex  value_slider.png "fltk3::ValueSlider" width=4cm
   */
  class FLTK3_EXPORT ValueSlider : public fltk3::Slider {
    fltk3::Font textfont_;
    fltk3::Fontsize textsize_;
    fltk3::Color textcolor_;
  protected:
    void draw();
  public:
    int handle(int);
    ValueSlider(int x,int y,int w,int h, const char *l = 0);
    /**    Gets the typeface of the text in the value box.  */
    fltk3::Font textfont() const {return textfont_;}
    /**    Sets the typeface of the text in the value box.  */
    void textfont(fltk3::Font s) {textfont_ = s;}
    /**    Gets the size of the text in the value box.  */
    fltk3::Fontsize textsize() const {return textsize_;}
    /**    Sets the size of the text in the value box.  */
    void textsize(fltk3::Fontsize s) {textsize_ = s;}
    /**    Gets the color of the text in the value box.  */
    fltk3::Color textcolor() const {return textcolor_;}
    /**    Sets the color of the text in the value box.  */
    void textcolor(fltk3::Color s) {textcolor_ = s;}
  };
  
}

#endif

//
// End of "$Id: ValueSlider.h 7981 2010-12-08 23:53:04Z greg.ercolano $".
//
