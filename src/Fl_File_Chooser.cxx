//
// "$Id$"
//
// Fl_File_Chooser dialog for the Fast Light Tool Kit (FLTK).
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

// generated by Fast Light User Interface Designer (fluid) version 1.0300

#include "../fltk3/FileChooser.h"
#include <fltk3/draw.h>

void Fl_File_Chooser::cb_window_i(fltk3::DoubleWindow*, void*) {
  fileName->value("");
fileList->deselect();
fltk3::remove_timeout((fltk3::TimeoutHandler)previewCB, this);
window->hide();
}
void Fl_File_Chooser::cb_window(fltk3::DoubleWindow* o, void* v) {
  ((Fl_File_Chooser*)(o->user_data()))->cb_window_i(o,v);
}

void Fl_File_Chooser::cb_showChoice_i(Fl_Choice*, void*) {
  showChoiceCB();
}
void Fl_File_Chooser::cb_showChoice(Fl_Choice* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_showChoice_i(o,v);
}

void Fl_File_Chooser::cb_favoritesButton_i(Fl_Menu_Button*, void*) {
  favoritesButtonCB();
}
void Fl_File_Chooser::cb_favoritesButton(Fl_Menu_Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_favoritesButton_i(o,v);
}

void Fl_File_Chooser::cb_newButton_i(fltk3::Button*, void*) {
  newdir();
}
void Fl_File_Chooser::cb_newButton(fltk3::Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_newButton_i(o,v);
}

#include <fltk3/Bitmap.h>
static unsigned char idata_new[] =
{0,0,120,0,132,0,2,1,1,254,1,128,49,128,49,128,253,128,253,128,49,128,49,
128,1,128,1,128,255,255,0,0};
static Fl_Bitmap image_new(idata_new, 16, 16);

void Fl_File_Chooser::cb__i(Fl_Tile*, void*) {
  update_preview();
}
void Fl_File_Chooser::cb_(Fl_Tile* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->user_data()))->cb__i(o,v);
}

void Fl_File_Chooser::cb_fileList_i(Fl_File_Browser*, void*) {
  fileListCB();
}
void Fl_File_Chooser::cb_fileList(Fl_File_Browser* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_fileList_i(o,v);
}

void Fl_File_Chooser::cb_previewButton_i(Fl_Check_Button*, void*) {
  preview(previewButton->value());
}
void Fl_File_Chooser::cb_previewButton(Fl_Check_Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->parent()->user_data()))->cb_previewButton_i(o,v);
}
#ifndef WIN32
void Fl_File_Chooser::remove_hidden_files()
{
  int count = fileList->size();
  for(int num = count; num >= 1; num--) {
    const char *p = fileList->text(num);
    if (*p == '.' && strcmp(p, "../") != 0) fileList->remove(num);
  }
  fileList->topline(1);
}

void Fl_File_Chooser::show_hidden_cb(Fl_Check_Button* o, void* data) {
  Fl_File_Chooser *mychooser = (Fl_File_Chooser *)data;
  if (o->value()) {
    mychooser->browser()->load(mychooser->directory());
  } else {
    mychooser->remove_hidden_files();
    mychooser->browser()->redraw();
  }
}
#endif
void Fl_File_Chooser::cb_fileName_i(Fl_File_Input*, void*) {
  fileNameCB();
}
void Fl_File_Chooser::cb_fileName(Fl_File_Input* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_fileName_i(o,v);
}

void Fl_File_Chooser::cb_okButton_i(Fl_Return_Button*, void*) {
  window->hide();

// Do any callback that is registered...
if (callback_)
  (*callback_)(this, data_);
}
void Fl_File_Chooser::cb_okButton(Fl_Return_Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->parent()->user_data()))->cb_okButton_i(o,v);
}

void Fl_File_Chooser::cb_cancelButton_i(fltk3::Button*, void*) {
  fileName->value("");
fileList->deselect();
fltk3::remove_timeout((fltk3::TimeoutHandler)previewCB, this);
window->hide();
}
void Fl_File_Chooser::cb_cancelButton(fltk3::Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->parent()->user_data()))->cb_cancelButton_i(o,v);
}

void Fl_File_Chooser::cb_favList_i(Fl_File_Browser*, void*) {
  favoritesCB(favList);
}
void Fl_File_Chooser::cb_favList(Fl_File_Browser* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->user_data()))->cb_favList_i(o,v);
}

void Fl_File_Chooser::cb_favUpButton_i(fltk3::Button*, void*) {
  favoritesCB(favUpButton);
}
void Fl_File_Chooser::cb_favUpButton(fltk3::Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_favUpButton_i(o,v);
}

void Fl_File_Chooser::cb_favDeleteButton_i(fltk3::Button*, void*) {
  favoritesCB(favDeleteButton);
}
void Fl_File_Chooser::cb_favDeleteButton(fltk3::Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_favDeleteButton_i(o,v);
}

void Fl_File_Chooser::cb_favDownButton_i(fltk3::Button*, void*) {
  favoritesCB(favDownButton);
}
void Fl_File_Chooser::cb_favDownButton(fltk3::Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_favDownButton_i(o,v);
}

void Fl_File_Chooser::cb_favCancelButton_i(fltk3::Button*, void*) {
  favWindow->hide();
}
void Fl_File_Chooser::cb_favCancelButton(fltk3::Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_favCancelButton_i(o,v);
}

void Fl_File_Chooser::cb_favOkButton_i(Fl_Return_Button*, void*) {
  favoritesCB(favOkButton);
}
void Fl_File_Chooser::cb_favOkButton(Fl_Return_Button* o, void* v) {
  ((Fl_File_Chooser*)(o->parent()->parent()->user_data()))->cb_favOkButton_i(o,v);
}

Fl_File_Chooser::Fl_File_Chooser(const char *d, const char *p, int t, const char *title) {
  fltk3::Group *prev_current = fltk3::Group::current();
  { window = new fltk3::DoubleWindow(490, 380, "Choose File");
    window->callback((fltk3::Callback*)cb_window, (void*)(this));
    { fltk3::Group* o = new fltk3::Group(10, 10, 470, 25);
      { showChoice = new Fl_Choice(65, 10, 215, 25, "Show:");
        showChoice->down_box(fltk3::BORDER_BOX);
        showChoice->labelfont(1);
        showChoice->callback((fltk3::Callback*)cb_showChoice);
        fltk3::Group::current()->resizable(showChoice);
        showChoice->label(show_label);
      } // Fl_Choice* showChoice
      { favoritesButton = new Fl_Menu_Button(290, 10, 155, 25, "Favorites");
        favoritesButton->down_box(fltk3::BORDER_BOX);
        favoritesButton->callback((fltk3::Callback*)cb_favoritesButton);
        favoritesButton->align(fltk3::Align(fltk3::ALIGN_LEFT|fltk3::ALIGN_INSIDE));
        favoritesButton->label(favorites_label);
      } // Fl_Menu_Button* favoritesButton
      { fltk3::Button* o = newButton = new fltk3::Button(455, 10, 25, 25);
        newButton->image(image_new);
        newButton->labelsize(8);
        newButton->callback((fltk3::Callback*)cb_newButton);
        o->tooltip(new_directory_tooltip);
      } // fltk3::Button* newButton
      o->end();
    } // fltk3::Group* o
    { Fl_Tile* o = new Fl_Tile(10, 45, 470, 225);
      o->callback((fltk3::Callback*)cb_);
      { fileList = new Fl_File_Browser(10, 45, 295, 225);
        fileList->type(2);
        fileList->callback((fltk3::Callback*)cb_fileList);
        fileList->window()->hotspot(fileList);
      } // Fl_File_Browser* fileList
      { previewBox = new fltk3::Box(305, 45, 175, 225, "?");
        previewBox->box(fltk3::DOWN_BOX);
        previewBox->labelsize(100);
        previewBox->align(fltk3::Align(fltk3::ALIGN_CLIP|fltk3::ALIGN_INSIDE));
      } // fltk3::Box* previewBox
      o->end();
      fltk3::Group::current()->resizable(o);
    } // Fl_Tile* o
    { fltk3::Group* o = new fltk3::Group(10, 275, 470, 95);
      { fltk3::Group* o = new fltk3::Group(10, 275, 470, 20);
        { previewButton = new Fl_Check_Button(10, 275, 73, 20, "Preview");
          previewButton->shortcut(0x80070);
          previewButton->down_box(fltk3::DOWN_BOX);
          previewButton->value(1);
          previewButton->callback((fltk3::Callback*)cb_previewButton);
          previewButton->label(preview_label);
        } // Fl_Check_Button* previewButton
#ifndef WIN32	
        { show_hidden = new Fl_Check_Button(
	    previewButton->x() + previewButton->w() + 30, 275, 140, 20, "Show hidden files");
          show_hidden->down_box(fltk3::DOWN_BOX);
          show_hidden->value(0);
          show_hidden->callback((fltk3::Callback*)show_hidden_cb, this);
          show_hidden->label(hidden_label);
        } // Fl_Check_Button* show_hidden
#endif	
        { fltk3::Box* o = new fltk3::Box(115, 275, 365, 20);
          fltk3::Group::current()->resizable(o);
        } // fltk3::Box* o
        o->end();
      } // fltk3::Group* o
      { fileName = new Fl_File_Input(115, 300, 365, 35);
        fileName->labelfont(1);
        fileName->callback((fltk3::Callback*)cb_fileName);
        fileName->when(fltk3::WHEN_ENTER_KEY);
        fltk3::Group::current()->resizable(fileName);
        fileName->when(fltk3::WHEN_CHANGED | fltk3::WHEN_ENTER_KEY);
      } // Fl_File_Input* fileName
      { fltk3::Box* o = new fltk3::Box(10, 310, 105, 25, "Filename:");
        o->labelfont(1);
        o->align(fltk3::Align(fltk3::ALIGN_RIGHT|fltk3::ALIGN_INSIDE));
        o->label(filename_label);
      } // fltk3::Box* o
      { fltk3::Group* o = new fltk3::Group(10, 345, 470, 25);
        { okButton = new Fl_Return_Button(313, 345, 85, 25, "OK");
          okButton->callback((fltk3::Callback*)cb_okButton);
          okButton->label(fl_ok);
        } // Fl_Return_Button* okButton
        { fltk3::Button* o = cancelButton = new fltk3::Button(408, 345, 72, 25, "Cancel");
          cancelButton->callback((fltk3::Callback*)cb_cancelButton);
          o->label(fl_cancel);
        } // fltk3::Button* cancelButton
        { fltk3::Box* o = new fltk3::Box(10, 345, 30, 25);
          fltk3::Group::current()->resizable(o);
        } // fltk3::Box* o
        o->end();
      } // fltk3::Group* o
      o->end();
    } // fltk3::Group* o
    if (title) window->label(title);
    window->set_modal();
    window->end();
  } // fltk3::DoubleWindow* window
  { favWindow = new fltk3::DoubleWindow(355, 150, "Manage Favorites");
    favWindow->user_data((void*)(this));
    { favList = new Fl_File_Browser(10, 10, 300, 95);
      favList->type(2);
      favList->callback((fltk3::Callback*)cb_favList);
      fltk3::Group::current()->resizable(favList);
    } // Fl_File_Browser* favList
    { fltk3::Group* o = new fltk3::Group(320, 10, 25, 95);
      { favUpButton = new fltk3::Button(320, 10, 25, 25, "@8>");
        favUpButton->callback((fltk3::Callback*)cb_favUpButton);
      } // fltk3::Button* favUpButton
      { favDeleteButton = new fltk3::Button(320, 45, 25, 25, "X");
        favDeleteButton->labelfont(1);
        favDeleteButton->callback((fltk3::Callback*)cb_favDeleteButton);
        fltk3::Group::current()->resizable(favDeleteButton);
      } // fltk3::Button* favDeleteButton
      { favDownButton = new fltk3::Button(320, 80, 25, 25, "@2>");
        favDownButton->callback((fltk3::Callback*)cb_favDownButton);
      } // fltk3::Button* favDownButton
      o->end();
    } // fltk3::Group* o
    { fltk3::Group* o = new fltk3::Group(10, 113, 335, 29);
      { favCancelButton = new fltk3::Button(273, 115, 72, 25, "Cancel");
        favCancelButton->callback((fltk3::Callback*)cb_favCancelButton);
        favCancelButton->label(fl_cancel);
      } // fltk3::Button* favCancelButton
      { favOkButton = new Fl_Return_Button(181, 115, 79, 25, "Save");
        favOkButton->callback((fltk3::Callback*)cb_favOkButton);
        favOkButton->label(save_label);
      } // Fl_Return_Button* favOkButton
      { fltk3::Box* o = new fltk3::Box(10, 115, 161, 25);
        fltk3::Group::current()->resizable(o);
      } // fltk3::Box* o
      o->end();
    } // fltk3::Group* o
    favWindow->label(manage_favorites_label);
    favWindow->set_modal();
    favWindow->size_range(181, 150);
    favWindow->end();
  } // fltk3::DoubleWindow* favWindow
  callback_ = 0;
data_ = 0;
directory_[0] = 0;
window->size_range(window->w(), window->h(), fltk3::w(), fltk3::h());
type(t);
filter(p);
update_favorites();
value(d);
type(t);
int e;
prefs_.get("preview", e, 1);
preview(e);
fltk3::Group::current(prev_current);
  ext_group=(fltk3::Widget*)0;
}

Fl_File_Chooser::~Fl_File_Chooser() {
  fltk3::remove_timeout((fltk3::TimeoutHandler)previewCB, this);
if(ext_group)window->remove(ext_group);
delete window;
delete favWindow;
}

void Fl_File_Chooser::callback(void (*cb)(Fl_File_Chooser *, void *), void *d ) {
  callback_ = cb;
data_     = d;
}

void Fl_File_Chooser::color(fltk3::Color c) {
  fileList->color(c);
}

fltk3::Color Fl_File_Chooser::color() {
  return (fileList->color());
}

char * Fl_File_Chooser::directory() {
  return directory_;
}

const char * Fl_File_Chooser::filter() {
  return (fileList->filter());
}

int Fl_File_Chooser::filter_value() {
  return showChoice->value();
}

void Fl_File_Chooser::filter_value(int f) {
  showChoice->value(f);
showChoiceCB();
}

void Fl_File_Chooser::hide() {
  window->hide();
}

void Fl_File_Chooser::iconsize(uchar s) {
  fileList->iconsize(s);
}

uchar Fl_File_Chooser::iconsize() {
  return (fileList->iconsize());
}

void Fl_File_Chooser::label(const char *l) {
  window->label(l);
}

const char * Fl_File_Chooser::label() {
  return (window->label());
}

void Fl_File_Chooser::ok_label(const char *l) {
  okButton->label(l);
int w=0, h=0;
okButton->measure_label(w, h);
okButton->resize(cancelButton->x() - 50 - w, cancelButton->y(),
                 w + 40, 25);
okButton->parent()->init_sizes();
}

const char * Fl_File_Chooser::ok_label() {
  return (okButton->label());
}

void Fl_File_Chooser::show() {
  window->hotspot(fileList);
window->show();
fltk3::flush();
fltk3::cursor(fltk3::CURSOR_WAIT);
rescan_keep_filename();
fltk3::cursor(fltk3::CURSOR_DEFAULT);
fileName->take_focus();
}

int Fl_File_Chooser::shown() {
  return window->shown();
}

void Fl_File_Chooser::textcolor(fltk3::Color c) {
  fileList->textcolor(c);
}

fltk3::Color Fl_File_Chooser::textcolor() {
  return (fileList->textcolor());
}

void Fl_File_Chooser::textfont(fltk3::Font f) {
  fileList->textfont(f);
}

fltk3::Font Fl_File_Chooser::textfont() {
  return (fileList->textfont());
}

void Fl_File_Chooser::textsize(fltk3::Fontsize s) {
  fileList->textsize(s);
}

fltk3::Fontsize Fl_File_Chooser::textsize() {
  return (fileList->textsize());
}

void Fl_File_Chooser::type(int t) {
  type_ = t;
if (t & MULTI)
  fileList->type(FL_MULTI_BROWSER);
else
  fileList->type(FL_HOLD_BROWSER);
if (t & CREATE)
  newButton->activate();
else
  newButton->deactivate();
if (t & DIRECTORY)
  fileList->filetype(Fl_File_Browser::DIRECTORIES);
else
  fileList->filetype(Fl_File_Browser::FILES);
}

int Fl_File_Chooser::type() {
  return (type_);
}

void * Fl_File_Chooser::user_data() const {
  return (data_);
}

void Fl_File_Chooser::user_data(void *d) {
  data_ = d;
}

int Fl_File_Chooser::visible() {
  return window->visible();
}

fltk3::Widget* Fl_File_Chooser::add_extra(fltk3::Widget* gr) {
  fltk3::Widget* ret=ext_group;
  if (gr==ext_group) {
    return ret;
      }
      if (ext_group) {
        int sh=ext_group->h()+4;
fltk3::Widget* svres=window->resizable();
window->resizable(NULL);
window->size(window->w(),window->h()-sh);
window->remove(ext_group);
ext_group=NULL;
window->resizable(svres);
          }
          if (gr) {
            int nh=window->h()+gr->h()+4;
fltk3::Widget* svres=window->resizable();
window->resizable(NULL);
window->size(window->w(),nh);
gr->position(2,okButton->y()+okButton->h()+2);
window->add(gr);
ext_group=gr;
window->resizable(svres);
              }
              return ret;
}

//
// End of "$Id$".
//
