#include "graphnode.h"
#include "garray.h"


typedef struct Graph {
    GraphNode* node;
    GArray* edges;

} Graph;
