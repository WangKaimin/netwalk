/* The colour scheme
 * Ben Lynn
 */
/*
Copyright (C) 2004 Benjamin Lynn (blynn@cs.stanford.edu)

This program is free software; you can redistribute it and/or
modify it under the terms of the GNU General Public License
as published by the Free Software Foundation; either version 2
of the License, or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
*/
#ifndef COLOUR_H
#define COLOUR_H

#include <SDL/SDL.h>

enum {
    c_darkshadow,
    c_shadow,
    c_text,
    c_invtext,
    c_canvas,
    c_background,
    c_menubg,
    c_buttonborder,
    c_server,
    c_serverwon,
    c_on,
    c_off,
    c_up,
    c_down,
    c_windowborder,
    c_border,
    c_borderwon,
    c_highlight,
    c_edgematch,
    c_pulse,
    c_unmarkedbg,
    c_markedbg,
    c_max
};

extern SDL_Color rgbtable[c_max];
extern int ctable[c_max];
void init_rgb(int c, int r, int g, int b);
void init_rgbtable();
void init_ctable();

#endif //COLOUR_H
