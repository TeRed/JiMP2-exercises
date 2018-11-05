//
// Created by albert on 13.03.17.
//
#include <climits>
#include <iostream>
#include <algorithm>
#include "GreatestProduct.h"

using namespace std;

int GreatestProduct(const std::vector<int> &numbers, int k){
    int product = 1;
    if(k == numbers.size()){
        for(int v : numbers){
            product *= v;
        }
        return product;
    }

    vector<int> max;
    vector<int> min;
    int min_ind = 0, max_ind = 0;

    for(int i = 0; i < k; i++){
        max.push_back(INT_MIN);
        min.push_back(INT_MAX);
    }

    for(int v : numbers){
        for(int i = 0; i < k; i++){
            if(v > max[max_ind]){
                max[max_ind] = v;
            }
            if(v < min[min_ind]){
                min[min_ind] = v;
            }
        }
        for(int i = 0; i < k; i++){
            if(max[i] < max[max_ind]) max_ind = i;
            if(min[i] > min[min_ind]) min_ind = i;
        }
    }

    sort(max.begin(), max.end());
    sort(min.begin(), min.end());
    reverse(max.begin(), max.end());

    max_ind = 0;
    min_ind = 0;
    int count = 0;
    if(k % 2){
        if(max[0] < 0){
            for(int v : max) product *= v;

            return product;
        }
        while(count < k-1) {
            if (min[min_ind]*min[min_ind + 1] > max[max_ind]*max[max_ind + 1]){
                product *= min[min_ind]*min[min_ind + 1];
                min_ind += 2;
                count += 2;
            }
            else {
                product *= max[max_ind]*max[max_ind + 1];
                max_ind += 2;
                count += 2;
            }
        }
        product *= max[max_ind];
    }
    else{
        while(count < k) {
            if (min[min_ind]*min[min_ind + 1] > max[max_ind]*max[max_ind + 1]){
                product *= min[min_ind]*min[min_ind + 1];
                min_ind += 2;
                count += 2;
            }
            else{
                product *= max[max_ind]*max[max_ind + 1];
                max_ind += 2;
                count += 2;
            }
        }
    }
    
    return product;
}