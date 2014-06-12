/*
 *  This file is part of the XForms library package.
 *
 *  XForms is free software; you can redistribute it and/or modify it
 *  under the terms of the GNU Lesser General Public License as
 *  published by the Free Software Foundation; either version 2.1, or
 *  (at your option) any later version.
 *
 *  XForms is distributed in the hope that it will be useful, but
 *  WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with XForms.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 *  \file pslider.h
 *
 *  This file is part of the XForms library package.
 *  Copyright (c) 1995-1997  T.C. Zhao and Mark Overmars
 *  All rights reserved.
 *
 * private header for slider object
 */


#ifndef PSLIDER_H_
#define PSLIDER_H_

#include "pvaluator.h"

typedef FLI_VALUATOR_SPEC FLI_SLIDER_SPEC;

#define MINKNOB_SB     16       /* scrollbar        */
#define MINKNOB_SL     14       /* regular sliders  */

#define IS_HSLIDER( o )      ( ( o )->type & FL_HOR_FLAG )

#define IS_VSLIDER( o )      ( ! IS_HSLIDER( o ) )

#define IS_FILL( o )         (    ( o )->type & FL_VERT_FILL_SLIDER    \
                               || ( o )->type & FL_VERT_PROGRESS_BAR )

#define IS_SCROLLBAR( o )    ( ( o )->type & FL_SCROLL_FLAG )

#define IS_FLATBOX( bt )     (    ( bt ) == FL_FRAME_BOX         \
                               || ( bt ) == FL_EMBOSSED_BOX      \
                               || ( bt ) == FL_BORDER_BOX        \
                               || ( bt ) == FL_ROUNDED_BOX )


#define FLI_SLIDER_BW1       FL_BOUND_WIDTH
#define FLI_SLIDER_BW2       FL_abs( FL_BOUND_WIDTH )
#define FLI_SLIDER_BOXTYPE   FL_DOWN_BOX
#define FLI_SLIDER_COL1      FL_COL1
#define FLI_SLIDER_COL2      FL_COL1
#define FLI_SLIDER_LCOL      FL_LCOL
#define FLI_SLIDER_ALIGN     FL_ALIGN_BOTTOM

#define FLI_SLIDER_FINE      0.25


#endif /* PSLIDER_H_ */


/*
 * Local variables:
 * tab-width: 4
 * indent-tabs-mode: nil
 * End:
 */
