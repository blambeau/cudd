#include "util.h"
#include "cudd.h"

int main(){
    DdManager *manager;
    DdNode *x, *y, *z;
    int length, i;
    int support[2];

    manager = Cudd_Init(0,0,CUDD_UNIQUE_SLOTS,CUDD_CACHE_SLOTS,0);

    x = Cudd_bddNewVar(manager);
    y = Cudd_bddNewVar(manager);

    z = Cudd_bddOr(manager, Cudd_Not(x), Cudd_Not(y));
    Cudd_Ref(z);

    Cudd_ShortestPath(manager, z, NULL, support, &length);
    printf("%i\n", length);
    for (i=0; i<2; i++) {
        printf("%i ", support[i]);
    }
    printf("\n");

    Cudd_PrintMinterm(manager, z);

    Cudd_Quit(manager);

    return 0;
}