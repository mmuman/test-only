//
// "$Id: Fl_arg.cxx,v 1.43 2003/10/28 17:45:15 spitzak Exp $"
//
// Optional argument initialization code for the Fast Light Tool Kit (FLTK).
//
// Copyright 1998-2003 by Bill Spitzak and others.
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

// OPTIONAL initialization code for a program using fltk.
// You do not need to call this!  Feel free to make up your own switches.

#include <fltk/run.h>
#include <fltk/Window.h>
#include <fltk/filename.h>
#include <fltk/error.h>
#include <fltk/Monitor.h>
#include <ctype.h>
#include <string.h>
#include <stdio.h>
#include <limits.h>

#include <fltk/x.h>
#if defined(_WIN32) || (defined(__APPLE__) && !USE_X11)
int XParseGeometry(const char*, int*, int*, unsigned int*, unsigned int*);
#define NoValue		0x0000
#define XValue  	0x0001
#define YValue		0x0002
#define WidthValue  	0x0004
#define HeightValue  	0x0008
#define AllValues 	0x000F
#define XNegative 	0x0010
#define YNegative 	0x0020
#endif

using namespace fltk;

static int match(const char *a, const char *match, int atleast = 1) {
  const char *b = match;
  while (*a && (*a == *b || tolower(*a) == *b)) {a++; b++;}
  return !*a && b >= match+atleast;
}

// flags set by previously parsed arguments:
extern bool fl_show_iconic;
static bool arg_called;
static bool return_i;
static const char* name;
static const char* geometry;
extern Color fl_bg_switch;	// in Style.cxx

// consume a switch from argv.  Returns number of words eaten, 0 on error:
int fltk::arg(int argc, char **argv, int &i) {
  arg_called = true;

  const char *s = argv[i];

  if (!s) {i++; return 1;}	// something removed by calling program?

  // a word that does not start with '-', or a word after a '--', or
  // the word '-' by itself all start the "non-switch arguments" to
  // a program.  Return 0 to indicate that we don't understand the
  // word, but set a flag (return_i) so that args() will return at
  // that point:
  if (s[0] != '-' || s[1] == '-' || !s[1]) {return_i = true; return 0;}
  s++; // point after the dash

  if (match(s, "iconic")) {
    fl_show_iconic = true;
    i++;
    return 1;
  }

  const char *v = argv[i+1];
  if (i >= argc-1 || !v)
    return 0;	// all the rest need an argument, so if missing it is an error

  if (match(s, "geometry")) {

    int flags, gx, gy; unsigned int gw, gh;
    flags = XParseGeometry(v, &gx, &gy, &gw, &gh);
    if (!flags) return 0;
    geometry = v;

  } else if (match(s, "display")) {
    display(v);

  } else if (match(s, "name")) {
    name = v;

  } else if (match(s, "bg") || match(s, "background")) {
    fl_bg_switch = color(v);
    if (!fl_bg_switch) error("Unknown color \"%s\"", v);

  } else return 0; // unrecognized

  i += 2;
  return 2;
}

// consume all switches from argv.  Returns number of words eaten.
// Returns zero on error.  'i' will either point at first word that
// does not start with '-', at the error word, or after a '--', or at
// argc.  If your program does not take any word arguments you can
// report an error if i < argc.

int fltk::args(int argc, char** argv, int& i, int (*cb)(int,char**,int&)) {
  arg_called = true;
  i = 1; // skip argv[0]
  while (i < argc) {
    if (cb && cb(argc,argv,i)) continue;
    if (!arg(argc,argv,i)) {if (!return_i) i = 0; break;}
  }
  return i;
}

// show a main window, use any parsed arguments
void Window::show(int argc, char **argv) {
  if (argc < 1) {show(); return;}
  if (!arg_called) args(argc,argv);

  if (geometry) {
    sizes();//to allocate the array if this window was not end()ed...
    int flags = 0, gx = x(), gy = y(); unsigned int gw = w(), gh = h();
    flags = XParseGeometry(geometry, &gx, &gy, &gw, &gh);
    if (flags & XNegative) gx = Monitor::all().w()-w()+gx;
    if (flags & YNegative) gy = Monitor::all().h()-h()+gy;
    //  int mw,mh; minsize(mw,mh);
    //  if (mw > gw) gw = mw;
    //  if (mh > gh) gh = mh;
    Widget *r = resizable();
    if (!r) resizable(this);
    // for _WIN32 we assume window is not mapped yet:
    if (flags & (XValue | YValue))
      x(-1), resize(gx,gy,gw,gh);
    else
      size(gw,gh);
    layout();
    resizable(r);
    geometry = 0;
  }

  // can't just assume argv[0], since you don't always *have* one on win32...
  if(argc && !name)  name = filename_name(argv[0]);
  // make sure name exists and isn't empty...
  // Windows doesn't like empty window class names
  if(name && *name) xclass(name);
  if (!label()) label(name);

  show();

#if !defined(_WIN32) && !(defined(__APPLE__) && !USE_X11)
  // set the command string, used by state-saving window managers:
  int i;
  int n=0; for (i=0; i<argc; i++) n += strlen(argv[i])+1;
  char *buffer = new char[n];
  char *p = buffer;
  for (i=0; i<argc; i++) for (const char *q = argv[i]; (*p++ = *q++););
  XChangeProperty(xdisplay, xid(this), XA_WM_COMMAND, XA_STRING, 8, 0,
		  (unsigned char *)buffer, p-buffer-1);
  delete[] buffer;
#endif
}

// Calls useful for simple demo programs, with automatic help message:

static const char * const helpmsg =
"options are:\n"
#if !defined(_WIN32) && !(defined(__APPLE__) && !USE_X11)
" -d[isplay] host:n.n\n"
#endif
" -g[eometry] WxH+X+Y\n"
" -n[ame] windowname\n"
" -i[conic]\n"
" -bg color";

const char * const fltk::help = helpmsg+13;

void fltk::args(int argc, char **argv) {
  int i; if (args(argc,argv,i) < argc) error(helpmsg);
}

#if defined(_WIN32) || (defined(__APPLE__) && !USE_X11)

/* the following function was stolen from the X sources as indicated. */

/* Copyright 	Massachusetts Institute of Technology  1985, 1986, 1987 */
/* $XConsortium: XParseGeom.c,v 11.18 91/02/21 17:23:05 rws Exp $ */

/*
Permission to use, copy, modify, distribute, and sell this software and its
documentation for any purpose is hereby granted without fee, provided that
the above copyright notice appear in all copies and that both that
copyright notice and this permission notice appear in supporting
documentation, and that the name of M.I.T. not be used in advertising or
publicity pertaining to distribution of the software without specific,
written prior permission.  M.I.T. makes no representations about the
suitability of this software for any purpose.  It is provided "as is"
without express or implied warranty.
*/

/*
 *    XParseGeometry parses strings of the form
 *   "=<width>x<height>{+-}<xoffset>{+-}<yoffset>", where
 *   width, height, xoffset, and yoffset are unsigned integers.
 *   Example:  "=80x24+300-49"
 *   The equal sign is optional.
 *   It returns a bitmask that indicates which of the four values
 *   were actually found in the string.  For each value found,
 *   the corresponding argument is updated;  for each value
 *   not found, the corresponding argument is left unchanged. 
 */

static int ReadInteger(char* string, char** NextString)
{
  register int Result = 0;
  int Sign = 1;
    
  if (*string == '+')
    string++;
  else if (*string == '-') {
    string++;
    Sign = -1;
  }
  for (; (*string >= '0') && (*string <= '9'); string++) {
    Result = (Result * 10) + (*string - '0');
  }
  *NextString = string;
  if (Sign >= 0)
    return (Result);
  else
    return (-Result);
}

int XParseGeometry(const char* string, int* x, int* y,
		   unsigned int* width, unsigned int* height)
{
  int mask = NoValue;
  register char *strind;
  unsigned int tempWidth, tempHeight;
  int tempX, tempY;
  char *nextCharacter;

  if ( (string == NULL) || (*string == '\0')) return(mask);
  if (*string == '=')
    string++;  /* ignore possible '=' at beg of geometry spec */

  strind = (char *)string;
  if (*strind != '+' && *strind != '-' && *strind != 'x') {
    tempWidth = ReadInteger(strind, &nextCharacter);
    if (strind == nextCharacter) 
      return (0);
    strind = nextCharacter;
    mask |= WidthValue;
  }

  if (*strind == 'x' || *strind == 'X') {	
    strind++;
    tempHeight = ReadInteger(strind, &nextCharacter);
    if (strind == nextCharacter)
      return (0);
    strind = nextCharacter;
    mask |= HeightValue;
  }

  if ((*strind == '+') || (*strind == '-')) {
    if (*strind == '-') {
      strind++;
      tempX = -ReadInteger(strind, &nextCharacter);
      if (strind == nextCharacter)
	return (0);
      strind = nextCharacter;
      mask |= XNegative;

    } else {
      strind++;
      tempX = ReadInteger(strind, &nextCharacter);
      if (strind == nextCharacter)
	return(0);
      strind = nextCharacter;
      }
    mask |= XValue;
    if ((*strind == '+') || (*strind == '-')) {
      if (*strind == '-') {
	strind++;
	tempY = -ReadInteger(strind, &nextCharacter);
	if (strind == nextCharacter)
	  return(0);
	strind = nextCharacter;
	mask |= YNegative;

      } else {
	strind++;
	tempY = ReadInteger(strind, &nextCharacter);
	if (strind == nextCharacter)
	  return(0);
	strind = nextCharacter;
      }
      mask |= YValue;
    }
  }
	
  /* If strind isn't at the end of the string the it's an invalid
     geometry specification. */

  if (*strind != '\0') return (0);

  if (mask & XValue)
    *x = tempX;
  if (mask & YValue)
    *y = tempY;
  if (mask & WidthValue)
    *width = tempWidth;
  if (mask & HeightValue)
    *height = tempHeight;
  return (mask);
}

#endif // ifdef _WIN32

//
// End of "$Id: Fl_arg.cxx,v 1.43 2003/10/28 17:45:15 spitzak Exp $".
//
