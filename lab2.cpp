#include <iostream>
#include <thread>
#include <vector>
#include <random>
#include <algorithm>
#include <iterator>

using namespace std;


double genNumbers() {
    static mt19937 gen(time(nullptr));
    uniform_int_distribution<> dist(-30, 100);
    return dist(gen);
}

int calculation(vector <int> vec){
    int max_elem = 100;

    for (auto number: vec){
        if (number < max_elem && number > 0){
            max_elem = number;
        }
    }
    return max_elem;
}

void threadStarter(int thread_count){
    const unsigned size = 10000000;
    int max_elem = 100;
    vector <int> vec(size);
    vector <thread> thread_vector;
    thread_vector.reserve(thread_count);
    generate(vec.begin(), vec.end(), genNumbers);

    size_t sample_size = vec.size() / thread_count;
    for (int i = 0; i < vec.size(); i += sample_size){
        vector<int> int_vector(vec.begin() + i, vec.begin() + i + sample_size); 
        thread_vector.push_back(thread(calculation, int_vector));
    }

    for (int i = 0; i < thread_count; i++){
        thread_vector.at(i).join();
    }
}

int main()
{
    threadStarter(4);
    // threadStarter(10);
    // threadStarter(20);
    // threadStarter(40);
    return 0;
}