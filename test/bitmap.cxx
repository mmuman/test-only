//	test how bitmap label type draws

#include <FL/Fl.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Button.H>
#include <FL/Fl_Bitmap.H>
#include <stdio.h>

#define sorceress_width 75
#define sorceress_height 75
static uchar sorceress_bits[] = {
   0xfc, 0x7e, 0x40, 0x20, 0x90, 0x00, 0x07, 0x80, 0x23, 0x00, 0x00, 0xc6,
   0xc1, 0x41, 0x98, 0xb8, 0x01, 0x07, 0x66, 0x00, 0x15, 0x9f, 0x03, 0x47,
   0x8c, 0xc6, 0xdc, 0x7b, 0xcc, 0x00, 0xb0, 0x71, 0x0e, 0x4d, 0x06, 0x66,
   0x73, 0x8e, 0x8f, 0x01, 0x18, 0xc4, 0x39, 0x4b, 0x02, 0x23, 0x0c, 0x04,
   0x1e, 0x03, 0x0c, 0x08, 0xc7, 0xef, 0x08, 0x30, 0x06, 0x07, 0x1c, 0x02,
   0x06, 0x30, 0x18, 0xae, 0xc8, 0x98, 0x3f, 0x78, 0x20, 0x06, 0x02, 0x20,
   0x60, 0xa0, 0xc4, 0x1d, 0xc0, 0xff, 0x41, 0x04, 0xfa, 0x63, 0x80, 0xa1,
   0xa4, 0x3d, 0x00, 0x84, 0xbf, 0x04, 0x0f, 0x06, 0xfc, 0xa1, 0x34, 0x6b,
   0x01, 0x1c, 0xc9, 0x05, 0x06, 0xc7, 0x06, 0xbe, 0x11, 0x1e, 0x43, 0x30,
   0x91, 0x05, 0xc3, 0x61, 0x02, 0x30, 0x1b, 0x30, 0xcc, 0x20, 0x11, 0x00,
   0xc1, 0x3c, 0x03, 0x20, 0x0a, 0x00, 0xe8, 0x60, 0x21, 0x00, 0x61, 0x1b,
   0xc1, 0x63, 0x08, 0xf0, 0xc6, 0xc7, 0x21, 0x03, 0xf8, 0x08, 0xe1, 0xcf,
   0x0a, 0xfc, 0x4d, 0x99, 0x43, 0x07, 0x3c, 0x0c, 0xf1, 0x9f, 0x0b, 0xfc,
   0x5b, 0x81, 0x47, 0x02, 0x16, 0x04, 0x31, 0x1c, 0x0b, 0x1f, 0x17, 0x89,
   0x4d, 0x06, 0x1a, 0x04, 0x31, 0x38, 0x02, 0x07, 0x56, 0x89, 0x49, 0x04,
   0x0b, 0x04, 0xb1, 0x72, 0x82, 0xa1, 0x54, 0x9a, 0x49, 0x04, 0x1d, 0x66,
   0x50, 0xe7, 0xc2, 0xf0, 0x54, 0x9a, 0x58, 0x04, 0x0d, 0x62, 0xc1, 0x1f,
   0x44, 0xfc, 0x51, 0x90, 0x90, 0x04, 0x86, 0x63, 0xe0, 0x74, 0x04, 0xef,
   0x31, 0x1a, 0x91, 0x00, 0x02, 0xe2, 0xc1, 0xfd, 0x84, 0xf9, 0x30, 0x0a,
   0x91, 0x00, 0x82, 0xa9, 0xc0, 0xb9, 0x84, 0xf9, 0x31, 0x16, 0x81, 0x00,
   0x42, 0xa9, 0xdb, 0x7f, 0x0c, 0xff, 0x1c, 0x16, 0x11, 0x00, 0x02, 0x28,
   0x0b, 0x07, 0x08, 0x60, 0x1c, 0x02, 0x91, 0x00, 0x46, 0x29, 0x0e, 0x00,
   0x00, 0x00, 0x10, 0x16, 0x11, 0x02, 0x06, 0x29, 0x04, 0x00, 0x00, 0x00,
   0x10, 0x16, 0x91, 0x06, 0xa6, 0x2a, 0x04, 0x00, 0x00, 0x00, 0x18, 0x24,
   0x91, 0x04, 0x86, 0x2a, 0x04, 0x00, 0x00, 0x00, 0x18, 0x27, 0x93, 0x04,
   0x96, 0x4a, 0x04, 0x00, 0x00, 0x00, 0x04, 0x02, 0x91, 0x04, 0x86, 0x4a,
   0x0c, 0x00, 0x00, 0x00, 0x1e, 0x23, 0x93, 0x04, 0x56, 0x88, 0x08, 0x00,
   0x00, 0x00, 0x90, 0x21, 0x93, 0x04, 0x52, 0x0a, 0x09, 0x80, 0x01, 0x00,
   0xd0, 0x21, 0x95, 0x04, 0x57, 0x0a, 0x0f, 0x80, 0x27, 0x00, 0xd8, 0x20,
   0x9d, 0x04, 0x5d, 0x08, 0x1c, 0x80, 0x67, 0x00, 0xe4, 0x01, 0x85, 0x04,
   0x79, 0x8a, 0x3f, 0x00, 0x00, 0x00, 0xf4, 0x11, 0x85, 0x06, 0x39, 0x08,
   0x7d, 0x00, 0x00, 0x18, 0xb7, 0x10, 0x81, 0x03, 0x29, 0x12, 0xcb, 0x00,
   0x7e, 0x30, 0x28, 0x00, 0x85, 0x03, 0x29, 0x10, 0xbe, 0x81, 0xff, 0x27,
   0x0c, 0x10, 0x85, 0x03, 0x29, 0x32, 0xfa, 0xc1, 0xff, 0x27, 0x94, 0x11,
   0x85, 0x03, 0x28, 0x20, 0x6c, 0xe1, 0xff, 0x07, 0x0c, 0x01, 0x85, 0x01,
   0x28, 0x62, 0x5c, 0xe3, 0x8f, 0x03, 0x4e, 0x91, 0x80, 0x05, 0x39, 0x40,
   0xf4, 0xc2, 0xff, 0x00, 0x9f, 0x91, 0x84, 0x05, 0x31, 0xc6, 0xe8, 0x07,
   0x7f, 0x80, 0xcd, 0x00, 0xc4, 0x04, 0x31, 0x06, 0xc9, 0x0e, 0x00, 0xc0,
   0x48, 0x88, 0xe0, 0x04, 0x79, 0x04, 0xdb, 0x12, 0x00, 0x30, 0x0c, 0xc8,
   0xe4, 0x04, 0x6d, 0x06, 0xb6, 0x23, 0x00, 0x18, 0x1c, 0xc0, 0x84, 0x04,
   0x25, 0x0c, 0xff, 0xc2, 0x00, 0x4e, 0x06, 0xb0, 0x80, 0x04, 0x3f, 0x8a,
   0xb3, 0x83, 0xff, 0xc3, 0x03, 0x91, 0x84, 0x04, 0x2e, 0xd8, 0x0f, 0x3f,
   0x00, 0x00, 0x5f, 0x83, 0x84, 0x04, 0x2a, 0x70, 0xfd, 0x7f, 0x00, 0x00,
   0xc8, 0xc0, 0x84, 0x04, 0x4b, 0xe2, 0x2f, 0x01, 0x00, 0x08, 0x58, 0x60,
   0x80, 0x04, 0x5b, 0x82, 0xff, 0x01, 0x00, 0x08, 0xd0, 0xa0, 0x84, 0x04,
   0x72, 0x80, 0xe5, 0x00, 0x00, 0x08, 0xd2, 0x20, 0x44, 0x04, 0xca, 0x02,
   0xff, 0x00, 0x00, 0x08, 0xde, 0xa0, 0x44, 0x04, 0x82, 0x02, 0x6d, 0x00,
   0x00, 0x08, 0xf6, 0xb0, 0x40, 0x02, 0x82, 0x07, 0x3f, 0x00, 0x00, 0x08,
   0x44, 0x58, 0x44, 0x02, 0x93, 0x3f, 0x1f, 0x00, 0x00, 0x30, 0x88, 0x4f,
   0x44, 0x03, 0x83, 0x23, 0x3e, 0x00, 0x00, 0x00, 0x18, 0x60, 0xe0, 0x07,
   0xe3, 0x0f, 0xfe, 0x00, 0x00, 0x00, 0x70, 0x70, 0xe4, 0x07, 0xc7, 0x1b,
   0xfe, 0x01, 0x00, 0x00, 0xe0, 0x3c, 0xe4, 0x07, 0xc7, 0xe3, 0xfe, 0x1f,
   0x00, 0x00, 0xff, 0x1f, 0xfc, 0x07, 0xc7, 0x03, 0xf8, 0x33, 0x00, 0xc0,
   0xf0, 0x07, 0xff, 0x07, 0x87, 0x02, 0xfc, 0x43, 0x00, 0x60, 0xf0, 0xff,
   0xff, 0x07, 0x8f, 0x06, 0xbe, 0x87, 0x00, 0x30, 0xf8, 0xff, 0xff, 0x07,
   0x8f, 0x14, 0x9c, 0x8f, 0x00, 0x00, 0xfc, 0xff, 0xff, 0x07, 0x9f, 0x8d,
   0x8a, 0x0f, 0x00, 0x00, 0xfe, 0xff, 0xff, 0x07, 0xbf, 0x0b, 0x80, 0x1f,
   0x00, 0x00, 0xff, 0xff, 0xff, 0x07, 0x7f, 0x3a, 0x80, 0x3f, 0x00, 0x80,
   0xff, 0xff, 0xff, 0x07, 0xff, 0x20, 0xc0, 0x3f, 0x00, 0x80, 0xff, 0xff,
   0xff, 0x07, 0xff, 0x01, 0xe0, 0x7f, 0x00, 0xc0, 0xff, 0xff, 0xff, 0x07,
   0xff, 0x0f, 0xf8, 0xff, 0x40, 0xe0, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff,
   0xff, 0xff, 0x40, 0xf0, 0xff, 0xff, 0xff, 0x07, 0xff, 0xff, 0xff, 0xff,
   0x41, 0xf0, 0xff, 0xff, 0xff, 0x07};

Fl_Bitmap fl_bitmap(sorceress_bits, sorceress_width, sorceress_height);

#include <FL/Fl_Toggle_Button.H>

Fl_Toggle_Button *leftb,*rightb,*topb,*bottomb,*insideb;
Fl_Button *b;
Fl_Window *w;

void button_cb(Fl_Widget *,void *) {
  int i = 0;
  if (leftb->value()) i |= FL_ALIGN_LEFT;
  if (rightb->value()) i |= FL_ALIGN_RIGHT;
  if (topb->value()) i |= FL_ALIGN_TOP;
  if (bottomb->value()) i |= FL_ALIGN_BOTTOM;
  if (insideb->value()) i |= FL_ALIGN_INSIDE;
  b->align(i);
  w->redraw();
}

int main(int argc, char **argv) {
  Fl_Window window(400,400); ::w = &window;
  Fl_Button b(140,160,120,120,0); ::b = &b;
  //(new Fl_Bitmap(sorceress_bits,sorceress_width,sorceress_height))->label(&b);
  fl_bitmap.label(&b);
  leftb = new Fl_Toggle_Button(50,75,50,25,"left");
  leftb->callback(button_cb);
  rightb = new Fl_Toggle_Button(100,75,50,25,"right");
  rightb->callback(button_cb);
  topb = new Fl_Toggle_Button(150,75,50,25,"top");
  topb->callback(button_cb);
  bottomb = new Fl_Toggle_Button(200,75,50,25,"bottom");
  bottomb->callback(button_cb);
  insideb = new Fl_Toggle_Button(250,75,50,25,"inside");
  insideb->callback(button_cb);
  window.resizable(window);
  window.end();
  window.show(argc, argv);
  return Fl::run();
}
