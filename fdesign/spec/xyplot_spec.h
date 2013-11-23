/* Header file generated by fdesign on Sat Nov 23 23:00:46 2013 */

#ifndef FD_xyplotattrib_h_
#define FD_xyplotattrib_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

void grid_change_cb( FL_OBJECT *, long );
void xscale_change_cb( FL_OBJECT *, long );
void yscale_change_cb( FL_OBJECT *, long );
void ymajorminor_change_cb( FL_OBJECT *, long );
void xmajorminor_change_cb( FL_OBJECT *, long );
void xyplot_returnsetting_change( FL_OBJECT *, long );
void gridstyle_change_cb( FL_OBJECT *, long );
void markactive_change_cb( FL_OBJECT *, long );


/* Forms and Objects */

typedef struct {
    FL_FORM   * xyplotattrib;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * xgrid;
    FL_OBJECT * ygrid;
    FL_OBJECT * xscale;
    FL_OBJECT * yscale;
    FL_OBJECT * ymajor;
    FL_OBJECT * yminor;
    FL_OBJECT * xmajor;
    FL_OBJECT * xminor;
    FL_OBJECT * xbase;
    FL_OBJECT * ybase;
    FL_OBJECT * how_return;
    FL_OBJECT * gridstyle;
    FL_OBJECT * mark_active;
} FD_xyplotattrib;

FD_xyplotattrib * create_form_xyplotattrib( void );

#endif /* FD_xyplotattrib_h_ */
