#pragma once

#include <gsl/gsl_matrix.h>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class save_data
{
public:
	int csvWriteGsl(const gsl_matrix* inputMatrix, const string& fileName, const streamsize dPrec, const int ROW, const int COL);

	int csvWrite(double inputMatrix[][2], const string& fileName, const streamsize dPrec);


};