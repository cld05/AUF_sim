#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int
jac(double t, const double y[], double* dfdy, double dfdt[], void* params)
{
    (void)(t); /* avoid unused parameter warning */
    double mu = *(double*)params;
    gsl_matrix_view dfdy_mat
        = gsl_matrix_view_array(dfdy, 2, 2);
    gsl_matrix* m = &dfdy_mat.matrix;
    gsl_matrix_set(m, 0, 0, 0.0);
    gsl_matrix_set(m, 0, 1, 0.0);
    gsl_matrix_set(m, 1, 0, 0);
    gsl_matrix_set(m, 1, 1, 0);
    dfdt[0] = 0.0;
    dfdt[1] = 0.0;
    return GSL_SUCCESS;
}