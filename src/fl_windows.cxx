//
// "$Id: fl_windows.cxx,v 1.12 1999/11/19 03:59:12 carl Exp $"
//
// Theme plugin file for FLTK
//
// Copyright 1999 Bill Spitzak and others.
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
// Please report all bugs and problems to "fltk-bugs@easysw.com".
//

// Windows-98 style

#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Menu_Item.H>
#include <FL/Fl_Check_Button.H>
#include <FL/Fl_Scrollbar.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Output.H>
#include <FL/Fl_Style.H>
#include <stdio.h>
#include <string.h>

// a labeltype drawing function in fl_engraved_label.cxx
extern void fl_pattern_label(Fl_Labeltype l, const char* label,
                             int X, int Y, int W, int H,
                             Fl_Color fill, Fl_Flags f);

static int engraved_data[2][3] = {{1,1,FL_LIGHT3},{0,0,0}};
static int embossed_data[2][3] = {{-1,-1,FL_LIGHT3},{0,0,0}};

static const Fl_Labeltype_ win98_engraved_label = {fl_pattern_label, engraved_data};
static const Fl_Labeltype_ win98_embossed_label = {fl_pattern_label, embossed_data};

static void win98_labelfunc(Fl_Labeltype, const char* label,
                            int X, int Y, int W, int H,
                            Fl_Color fill, Fl_Flags f)
{
  if (f&FL_INACTIVE) win98_engraved_label.draw(label, X, Y, W, H, fill, f);
  else FL_NORMAL_LABEL->draw(label, X, Y, W, H, fill, f);
}

static const Fl_Labeltype_ win98_label = {win98_labelfunc, engraved_data};

// a boxtype drawing function in fl_boxtype.cxx
extern void fl_frame(Fl_Boxtype b, int x, int y, int w, int h,
                     Fl_Color c, Fl_Flags f);

// a boxtype drawing function in fl_boxtype.cxx
extern void fl_highlightx(Fl_Boxtype b, int x, int y, int w, int h,
			  Fl_Color c, Fl_Flags f);

// some new boxtypes (look familiar?)
static const Fl_Boxtype_ win98_menu_title_box = {
  fl_highlightx, 0, FL_THIN_UP_BOX, 1,1,2,2,1
};

static const Fl_Boxtype_ win98_menu_window_box = {
  fl_frame, "2AARRMMUU", FL_DOWN_BOX, 2,2,4,4, 1
};

int fl_windows() {
  Fl_Style::revert(); // revert to FLTK default styles

  Fl_Style::draw_boxes_inactive = 0;
  Fl_Style::inactive_color_weight = 0.30f;

  Fl_Widget::default_style.set_selection_color(FL_GRAY);
  Fl_Widget::default_style.set_highlight_color(0);
  Fl_Widget::default_style.set_label_type(&win98_label);
  Fl_Widget::default_style.set_label_size(12);

  Fl_Style* s;
  if ((s = Fl_Style::find("menu window"))) {
    s->set_box(&win98_menu_window_box);
    s->set_leading(6);
  }

  if ((s = Fl_Style::find("menu title"))) {
    s->set_box(&win98_menu_title_box);
    s->set_glyph_box(FL_NO_BOX);
  }

  // highlighting must be on both the menu bar and menu title!
  if ((s = Fl_Style::find("menu item"))) {
    s->set_glyph_box(FL_NO_BOX);
  }

  if ((s = Fl_Style::find("menu bar"))) {
    s->set_highlight_color(FL_GRAY); // needed for title highlighting
  }

  if ((s = Fl_Style::find("input"))) {
    s->set_box(FL_DOWN_BOX);
  }

  if ((s = Fl_Style::find("slider"))) {
//    s->set_glyph_box(&win98_menu_window_box);
    s->set_box(FL_DOWN_BOX);
  }

  if ((s = Fl_Style::find("value slider"))) {
//    s->set_glyph_box(&win98_menu_window_box);
    s->set_box(FL_DOWN_BOX);
  }

  if ((s = Fl_Style::find("scrollbar"))) {
    s->set_glyph_box(&win98_menu_window_box);
  }

  if ((s = Fl_Style::find("output"))) {
    s->set_box(FL_DOWN_BOX);
  }

  if ((s = Fl_Style::find("counter"))) {
    s->set_box(FL_DOWN_BOX);
  }

// use FLTK default Windows colors
  if ((s = Fl_Style::find("output"))) {
    s->set_color(FL_WHITE);
  }

  if ((s = Fl_Style::find("counter"))) {
    s->set_color(FL_WHITE);
  }

  if ((s = Fl_Style::find("scrollbar"))) {
    s->set_color(52);
  }

  if ((s = Fl_Style::find("highlight button"))) {
    s->set_highlight_color(FL_GRAY);
  }

  if ((s = Fl_Style::find("menu title"))) {
    s->set_selection_color(FL_GRAY);
    s->set_selection_text_color(FL_BLACK);
    s->set_highlight_color(FL_GRAY);
  }

  static Fl_Boxtype_Definer win98_menu_title("windows menu title", win98_menu_title_box);
  static Fl_Boxtype_Definer win98_menu_window("windows menu window", win98_menu_window_box);
  static Fl_Labeltype_Definer win98_l("windows", win98_label);
  static Fl_Labeltype_Definer win98_engraved("windows engraved", win98_engraved_label);
  static Fl_Labeltype_Definer win98_embossed("windows embossed", win98_embossed_label);

  Fl::redraw();

  return 0;
}

//
// End of "$Id: fl_windows.cxx,v 1.12 1999/11/19 03:59:12 carl Exp $".
//
