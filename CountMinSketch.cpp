#include <limits>
#include "CountMinSketch.h"
#include "HashFunctions.h"

/**
 * Implement increment() correctly
 */
void CountMinSketch::increment(const string & s) {
    /* YOUR CODE HERE */
    for(unsigned int i=0;i<K;i++){
        int X = hash_functions[0](s);
        count[i][X%M]+=1;
    }
}

/**
 * Implement find() correctly
 */
unsigned int CountMinSketch::find(const string & s) {
    /* YOUR CODE HERE */
    unsigned int MC = numeric_limits<int>::max();
    for(unsigned int i=0;i<K;i++){
        unsigned int X = hash_functions[0](s);
        MC = min(count[i][X%M],MC);
    }
 return MC;
}
