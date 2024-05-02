#include "BloomFilter.h"
#include "HashFunctions.h"

/**
 * Implement insert() correctly
 */
void BloomFilter::insert(const string & s) {
    /* YOUR CODE HERE */
    for(unsigned int i=0;i<K;i++){
        int X = hash_functions[i](s);
        bits[X%M]=1;
    }
}

/**
 * Implement find() correctly
 */
bool BloomFilter::find(const string & s) {
    /* YOUR CODE HERE */
    for(unsigned int i=0;i<K;i++){
        int X = hash_functions[i](s);
        if(bits[X%M]==0) return 0;
    }
 return 1;
}
