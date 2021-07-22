// AUF.cpp : Defines the entry point for the application.
//

#include "model.h"
#include "jacobian.h"
#include <AUF_sim.h>
#include <stdio.h>
#include <gsl/gsl_errno.h>
#include <gsl/gsl_matrix.h>
#include <gsl/gsl_odeiv2.h>

#include <fstream>
#include <iostream>
#include <string>
#include "save_data.h"

using namespace std;





int
main(void)
{
    double mu = 10;
    gsl_odeiv2_system sys = { func, jac, 2};

    gsl_odeiv2_driver* d =
        gsl_odeiv2_driver_alloc_y_new(&sys, gsl_odeiv2_step_rk4,
            1e-3, 1e-8, 1e-8);

    const int T = 100;
    const int dim = 3;
    const double eps = 1e-3;
    const long int N = T / eps;
    double t = 0.0;
    double y[2] = { 1.0, 0.0 };
    double out[T][2];
    int i, s;

    gsl_matrix* Mat = gsl_matrix_alloc(T, dim);

    gsl_matrix_set(Mat, 0, 0, t);
    gsl_matrix_set(Mat, 0, 1, y[0]);
    gsl_matrix_set(Mat, 0, 2, y[1]);

    for (i = 1; i < T; i++)
    {
        s = gsl_odeiv2_driver_apply_fixed_step(d, &t, eps, 1000, y);

        if (s != GSL_SUCCESS)
        {
            printf("error: driver returned %d\n", s);
            break;
        }

        //if (i == 1) { printf("t,        y0,         y1 \n"); }
        //printf("%.5e %.5e %.5e\n", t, y[0], y[1]);
        gsl_matrix_set(Mat, i, 0, t);
        gsl_matrix_set(Mat, i, 1, y[0]);
        gsl_matrix_set(Mat, i, 2, y[1]);

        

    }

    gsl_odeiv2_driver_free(d);

   /* for (i = 0; i < N + 1; i++) {
        if (i == 1) { printf("t,        y0,         y1 \n"); }
        printf("%.5e %.5e %.5e\n", t, y[0], y[1]);
        gsl_matrix_set(Mat, i, 0, t);
        gsl_matrix_set(Mat, i, 1, y[0]);
        gsl_matrix_set(Mat, i, 2, y[1]);
    } */
    int error;
   
    save_data save_my_file;
    
    error = save_my_file.csvWriteGsl(Mat, "MatGsl.csv", 20, T, dim);

    gsl_matrix_free(Mat);

    //return 0;
    return s;
}