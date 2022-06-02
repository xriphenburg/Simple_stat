#ifndef SIMPLE_STAT_H
#define SIMPLE_STAT_H
#include "alist.h"
#include "alist.cpp"
#include <set>
#include <cmath>

template<typename C, typename T = typename C::value_type>

class Simple_stat
{
private:
    int SIZE = 10;
    int length = 0;
    AList <T> * itemlist;
    C* ptr;
    C total;
    C mean;
    C SD;
    C min;
    C max;

    void calculate_total() {
        this->total = 0;
        for (int i = 0; i < this->itemlist->length(); i++) {
            this->total = this->total + this->itemlist[i];
        }
    };

    void calculate_mean() {
        calculate_total();
        this->mean = this->total / length;
    };

    void calculate_SD() {
        calculate_total();
        calculate_mean();
        for (int i = 0; i < this->itemlist->length(); i++) {
            this->SD += pow(this->itemlist[i] - mean, 2);
        }
        return sqrt(SD);
    };

    void calculate_min(){
        C min = this->itemlist.listArray[0];
        for (int i = 1; i < this->itemlist.listsize(); i++) {
            if (this->listArray[i] < min) {
                min = this->listArray[i];
            }
            return min;
        }
    };

    void calculate_max(){
        C max = this->itemlist.listArray[0];
        for (int i = 1; i < this->itemlist.listsize(); i++) {
            if (this->listArray[i] > max) {
                max = this->listArray[i];
            }
            return max;
        }
    };


public:
    Simple_stat() {
        this->itemlist = new C[SIZE];
        this->length = SIZE;
    };

    Simple_stat(C const& container){
        this->itemlist = new C[SIZE];
        feed(container);
    };

    C get_mean() {
        return this->mean;
    };

    C get_SD(){
        return this->SD;
    };

    C get_min(){
        return this->min;
    };

    C get_max(){
        return this->max;
    };

    void append(C const& item){
        this->itemlist[length++] = item;
        this->length++;

        calculate_mean();
        calculate_SD();
        calculate_min();
        calculate_max();
    };

    void removem(C const& item, int n){
        int occurrences = 0;
        for (int i = 1; i < this->itemlist.listsize(); i++) {
            if (this->listArray[i] == item && occurrences > n) {
                occurrences++;
                if (occurrences > 0) {
                    this->listArray[i].remove();
                }
            }
        }
        this->length = this->length - n;

        calculate_mean();
        calculate_SD();
        calculate_min();
        calculate_max();
    };

    void empty(){
        this->itemlist.clear();
        this->length = 0;

        calculate_mean();
        calculate_SD();
        calculate_min();
        calculate_max();
    };

    void feed(C const& item){
        this->itemlist[length++] = item;
        this->length++;

        calculate_mean();
        calculate_SD();
        calculate_min();
        calculate_max();
    };

    std::set<C> search(C const& item){
        for (int i = 0; i < this->itemlist.length(); i++) {
            if (this->itemlist[i] == item) {
                return i;
            }
        }
    };

    Simple_stat& operator[](int const& index);
    int length_unique();
    int length_total(){
        return this->length;
    };

    int unique_set();
};

#endif // SIMPLE_STAT_H
