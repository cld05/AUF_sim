#include "save_data.h"
#include <string>

using namespace std;

int save_data::csvWriteGsl(const gsl_matrix* inputMatrix, const string& fileName, const streamsize dPrec, const int ROW, const int COL) {
    int i, j;
    
    std::ofstream outputData;
    outputData.open(fileName);
    
    if (!outputData){
        printf("outputData not opened!");
        return -1;
    }
    outputData.precision(dPrec);
    
    for (i = 0; i < ROW; i++) {
       
        for (j = 0; j < COL; j++) {
           
            outputData << gsl_matrix_get(inputMatrix, i, j);
           
            if (j < COL)
                outputData << ",";
        }
        if (i < ROW)
            outputData << endl;
    }
    outputData.close();
    if (!outputData) {
        printf("outputData not closed!");
        return -2;
    }
    return 0;
}

int save_data::csvWrite(double inputMatrix[][2], const string& fileName, const streamsize dPrec) {
    int i, j;
    std::ofstream outputData;
    outputData.open(fileName);
    if (!outputData)
        return -1;
    outputData.precision(dPrec);
    for (i = 0; i < 2; i++) {
        for (j = 0; j < 2; j++) {
            outputData << inputMatrix[i][j];
            if (j < 2)
                outputData << ",";
        }
        if (i < 2)
            outputData << endl;
    }
    outputData.close();
    if (!outputData)
        return -1;
    return 0;
}

