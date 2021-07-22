#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

int
func(double t, const double x[], double f[],
    void* params)
{
    (void)(t); /* avoid unused parameter warning */
    //double mu = *(double*)params;
    f[0] = x[1];
    f[1] = -1*x[0] - 1*x[1];
    return GSL_SUCCESS;
}