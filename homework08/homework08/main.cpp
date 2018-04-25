#include <iostream>
#include <iomanip>

double **makeDoubleArray2D(double *&vect,const int size1,const int size2){
    double **mat2d;
    vect=new double[size1*size2];
    mat2d=new double*[size1];
    for(int i=0; i < size1; i++){
        mat2d[i]=vect+size2*i;
    }
    return mat2d;
}

void destroyDoubleArray2D(double *vect,double **mat2d){
    delete [] vect;
    delete [] mat2d;
}



int main(int argc, const char * argv[]) {
    const int size1 = 3;
    const int size2 = 4;
    double *vect;
    double **mat2d = makeDoubleArray2D(vect,size1,size2);
    
    // set
    for (int i = 0 ; i < size1 ; i++){
        for (int j = 0 ; j < size2 ; j++){
            mat2d[i][j] = static_cast<double>(i + 1) / (j + 1);
        }
    }
    
    // print
    std::cout << "matrix\n";
    std::cout.setf(std::ios::scientific);
    std::cout.precision(2);
    for (int i = 0 ; i < size1 ; i++){
        for (int j = 0 ; j < size2 ; j++){
            std::cout << std::setw(9) << mat2d[i][j];
        }
        std::cout << std::endl;
    }
    std::cout << "vector\n";
    for (int i = 0 ; i < size1 * size2 ; i++){
        std::cout << vect[i] << std::endl;
    }
    
    destroyDoubleArray2D(vect,mat2d);
    return 0;
}

