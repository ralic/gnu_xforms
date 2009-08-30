/*
 * This file is part of XForms.
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
 *  You should have received a copy of the GNU Lesser General Public License
 *  along with XForms.  If not, see <http://www.gnu.org/licenses/>.
 */


/**
 * \file sp_dial.c
 *
 *  This file is part of XForms package
 *  Copyright (c) 1996-2002  T.C. Zhao and Mark Overmars
 *  All rights reserved.
 *
 *  Settting dial class specific attributes. We hang the spec
 *  structure on ob->u_vdata. The real spec ob->spec is affected
 *  by testing and can't be used.
 */

#ifdef HAVE_CONFIG_H
#include <config.h>
#endif

#include "include/forms.h"
#include "fd_main.h"
#include "fd_spec.h"
#include "private/pdial.h"
#include "spec/dial_spec.h"

extern FD_dialattrib *create_form_dialattrib( void );

static FD_dialattrib *dial_attrib;
static SuperSPEC *dial_spec;
static void show_spec(SuperSPEC *);

#define VN( a )  { a, #a }

static FLI_VN_PAIR dial_dir[ ] =
{
    VN( FL_DIAL_CW ),
    VN( FL_DIAL_CCW ),
    { -1, NULL }
};


/***************************************
 ***************************************/

int
get_direction_value( const char * s )
{
    return fli_get_vn_value( dial_dir, s );
}


/***************************************
 ***************************************/

void *
get_dial_spec_fdform( void )
{
    if ( ! dial_attrib )
    {
		dial_attrib = create_form_dialattrib( );
		fl_addto_choice( dial_attrib->dir, dial_dir[ 0 ].name );
		fl_addto_choice( dial_attrib->dir, dial_dir[ 1 ].name );

		set_up_how_return_menu( dial_attrib->returnsetting );
		fl_set_menu_item_mode( dial_attrib->returnsetting, 5,
							   FL_PUP_BOX | FL_PUP_GRAY );
		fl_set_menu_item_mode( dial_attrib->returnsetting, 6,
							   FL_PUP_BOX | FL_PUP_GRAY );
    }

    return dial_attrib;
}


/***************************************
 ***************************************/

void
dial_spec_restore( FL_OBJECT * ob    FL_UNUSED_ARG,
				   long        data  FL_UNUSED_ARG )
{
    FL_OBJECT *edited = dial_attrib->vdata;

    superspec_to_spec( edited );
    show_spec( get_superspec( edited ) );
    redraw_the_form( 0 );
}


/***************************************
 ***************************************/

static void
show_spec( SuperSPEC * spec )
{
    set_finput_value( dial_attrib->minval,     spec->min, -1 );
    set_finput_value( dial_attrib->maxval,     spec->max, -1 );
    set_finput_value( dial_attrib->initialval, spec->val, -1 );
    set_finput_value( dial_attrib->thetai,     spec->thetai, -1 );
    set_finput_value( dial_attrib->thetaf,     spec->thetaf, -1 );
    set_finput_value( dial_attrib->step,       spec->step, -1 );

    fl_set_choice_text( dial_attrib->dir,
						fli_get_vn_name( dial_dir, spec->direction ) );

	reset_how_return_menu( dial_attrib->returnsetting, spec->how_return );
}


/***************************************
 ***************************************/

int
set_dial_attrib( FL_OBJECT * ob )
{
    dial_attrib->vdata = ob;
    dial_spec = get_superspec( ob );
    show_spec( dial_spec );
    return 0;
}


/***************************************
 ***************************************/

void
emit_dial_code( FILE      * fp,
				FL_OBJECT * ob )
{
    FL_OBJECT *defobj;
    SuperSPEC *sp,
		      *defspec;

    if ( ob->objclass != FL_DIAL )
		return;

    /* create a default object */

    defobj = fl_create_dial( ob->type, 0, 0, 0, 0, "" );

    defspec = get_superspec( defobj );
    sp = get_superspec( ob );

    if ( sp->min != defspec->min || sp->max != defspec->max )
		fprintf( fp, "    fl_set_dial_bounds( obj, %g, %g );\n",
				 sp->min, sp->max );

    if ( sp->thetai != defspec->thetai || sp->thetaf != defspec->thetaf )
		fprintf( fp, "    fl_set_dial_angles( obj, %g, %g );\n",
				 sp->thetai, sp->thetaf );

    if ( sp->val != defspec->val )
		fprintf( fp, "    fl_set_dial_value( obj, %g );\n", sp->val );

    if ( sp->step != defspec->step )
		fprintf( fp, "    fl_set_dial_step( obj, %g );\n", sp->step );

    if ( sp->direction != defspec->direction )
		fprintf( fp, "    fl_set_dial_direction( obj, %s );\n",
				 fli_get_vn_name( dial_dir, sp->direction ) );

    fl_free_object( defobj );
}


/***************************************
 ***************************************/

void
save_dial_attrib( FILE      * fp,
				  FL_OBJECT * ob )
{
    FL_OBJECT *defobj;
    SuperSPEC *defspec,
		      *spec;

    if ( ob->objclass != FL_DIAL )
		return;

    /* create a default object */

    defobj = fl_create_dial( ob->type, 0, 0, 0, 0, "" );

    defspec = get_superspec( defobj );
    spec = get_superspec( ob );

    if ( spec->min != defspec->min || spec->max != defspec->max )
		fprintf( fp, "    bounds: %g %g\n", spec->min, spec->max );

    if ( spec->thetai != defspec->thetai || spec->thetaf != defspec->thetaf )
		fprintf( fp, "    angles: %g %g\n", spec->thetai, spec->thetaf );

    if ( spec->val != defspec->val )
		fprintf( fp, "    value: %g\n", spec->val );

    if ( spec->step != defspec->step )
		fprintf( fp, "    step: %g\n", spec->step );

    if ( spec->direction != defspec->direction )
		fprintf( fp, "    dir: %s\n",
				 fli_get_vn_name( dial_dir, spec->direction ) );

    fl_free_object( defobj );
}


/***************************************
 ***************************************/

void
dial_minmax_change( FL_OBJECT * ob    FL_UNUSED_ARG,
					long        data  FL_UNUSED_ARG )
{
    double min = get_finput_value( dial_attrib->minval );
    double max = get_finput_value( dial_attrib->maxval );

    fl_set_dial_bounds( dial_attrib->vdata, min, max );
    if ( auto_apply )
		redraw_the_form( 0 );
}


/***************************************
 ***************************************/

void
dial_thetachange_cb( FL_OBJECT * ob    FL_UNUSED_ARG,
					 long        data  FL_UNUSED_ARG )
{
    double t1 = get_finput_value( dial_attrib->thetai );
    double t2 = get_finput_value( dial_attrib->thetaf );

    fl_set_dial_angles( dial_attrib->vdata, t1, t2 );
    if ( auto_apply )
		redraw_the_form( 0 );
}


/***************************************
 ***************************************/

void
dial_stepchange_cb( FL_OBJECT * ob    FL_UNUSED_ARG,
					long        data  FL_UNUSED_ARG )
{
    float s = get_finput_value( dial_attrib->step );

    fl_set_dial_step( dial_attrib->vdata, s );
    if ( auto_apply )
		redraw_the_form( 0 );
}


/***************************************
 ***************************************/

void
dial_initialvalue_change( FL_OBJECT * ob    FL_UNUSED_ARG,
						  long        data  FL_UNUSED_ARG )
{
    double val = get_finput_value( dial_attrib->initialval );

    fl_set_dial_value( dial_attrib->vdata, val );
    if ( auto_apply )
		redraw_the_form( 0 );
}


/***************************************
 * direction change
 ***************************************/

void
dir_cb( FL_OBJECT * ob    FL_UNUSED_ARG,
		long        data  FL_UNUSED_ARG )
{
    int dir = fl_get_choice( ob ) - 1;

    if ( dir >= 0 )
    {
		fl_set_dial_direction( dial_attrib->vdata, dial_dir[ dir ].val );
		if ( auto_apply )
			redraw_the_form( 0 );
    }
}


/***************************************
 ***************************************/

void
dial_returnsetting_change( FL_OBJECT * ob    FL_UNUSED_ARG,
						   long        data  FL_UNUSED_ARG )
{
	handle_how_return_changes( dial_attrib->returnsetting,
							   dial_attrib->vdata );
}


#include "spec/dial_spec.c"
