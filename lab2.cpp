#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;


double gen_numbers() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(-30,100);
    return distribution(gen);
}


// vector <int> &create_vector(vector <int> &vec){
//     const int size = 100;
//     int max_elem = 100;
//     vec.reserve(size);
//     for (int i = 0; i < size; i++){
//         vec.push_back(gen_numbers());
//     }
//     return vec;
// }

void calc(){
    vector <int> vec;
    const int size = 10000;
    int max_elem = 100;
    vec.reserve(size);

     for (int i = 0; i < size; i++){
        vec.push_back(gen_numbers());
    }

    for (auto number: vec){
        if (number < max_elem && number > 0){
            max_elem = number;
        }
    }

}


int main()
{
    calc();
    return 0;
}