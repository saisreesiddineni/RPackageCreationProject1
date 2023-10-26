#include "gmm.h"
#include <R_ext/Rdynload.h>

//void fitGMM_interface(
//    std::vector<double>& data,
  //  int *numComponents, 
//    int *maxIters
//){
  //fitGMM(data, *numComponents, *maxIters);
//}

void fitGMM_interface(
    std::vector<double>& data, 
    int *numComponents, 
    int *maxIters)
{
  fitGMM(data, *numComponents, *maxIters);
}


R_CMethodDef cMethods[] = {
  {"fitGMM_interface", (DL_FUNC) &fitGMM_interface, 3},
  {NULL,NULL,0}
};

extern "C"{
  void R_init_RPackageCreationProject1(DllInfo *info)
  {
    R_registerRoutines(info, cMethods, NULL, NULL, NULL);
    R_useDynamicSymbols(info, FALSE);
  }
}