//#include <iostream>
//#include <math.h>
//#include "vectors.h"

using namespace std;



class Obj {
public:
    mesh B[];
    int num_meshs;
    Obj(ifstream& file){
        file >> num_meshs;
        mesh A[num_meshs](file);
        for (int i = 0; i < num_meshs; i++){
                B[i] = A[i];
//            A[i](file);
//            vector_print(A[i].A);
        }
//        file >> num_meshs2;
//        mesh *A = new mesh[num_meshs](file);
//        for (int i = 0; i < num_meshs; i++)
//            file >> A[i].
    }
};
