#include <stdio.h>
#include <string.h>
#include <stdint.h>

#include "1m_block.h"


//polynomial rolling hash function
long long int hash_func(char* str){
    int num = strlen(str);
    long long int hash = 0;
    long long int mod = HASH_MOD;
    long long int pow = HASH_POW;
    long long int p_pow = 1;
    for(int i = 0; i < num; ++i){
        hash = (hash + (str[i] - 'a' + 1) * p_pow) % mod;
        p_pow = (pow * p_pow) % mod;
    }
    return hash;
}
