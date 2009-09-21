/* Header file generated by fdesign on Fri Sep 11 00:21:03 2009 */

#ifndef FD_spinnerattrib_h_
#define FD_spinnerattrib_h_

#include <forms.h>

/* Callbacks, globals and object handlers */

extern void spn_precision_cb( FL_OBJECT *, long );
extern void spn_minmax_change( FL_OBJECT *, long );
extern void spn_returnsetting_change( FL_OBJECT *, long );
extern void spn_initialvalue_change( FL_OBJECT *, long );
extern void spn_stepchange_cb( FL_OBJECT *, long );


/* Forms and Objects */

typedef struct {
    FL_FORM   * spinnerattrib;
    void      * vdata;
    char      * cdata;
    long        ldata;
    FL_OBJECT * background;
    FL_OBJECT * prec;
    FL_OBJECT * minval;
    FL_OBJECT * maxval;
    FL_OBJECT * returnsetting;
    FL_OBJECT * initialval;
    FL_OBJECT * step;
} FD_spinnerattrib;

extern FD_spinnerattrib * create_form_spinnerattrib( void );

#endif /* FD_spinnerattrib_h_ */