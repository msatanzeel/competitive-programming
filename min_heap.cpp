#include <bits/stdc++.h>
using namespace std;

void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '\"' << x << '\"'; }
void __print(const string &x) { cerr << '\"' << x << '\"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }
template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}
template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v))
        cerr << ", ";
    _print(v...);
}
#ifndef ONLINE_JUDGE
#define debug(x...)               \
    cerr << "[" << #x << "] = ["; \
    _print(x)
#else
#define debug(x...)
#endif


class min_heap {
    public:
        int size, capacity;
        vector<int> arr;

        min_heap() {
            capacity = 1;
            size = 0;
            arr.resize(capacity, 0);
        }

        min_heap(int capacity) {
            this->capacity = capacity;
            size = 0;
            arr.resize(capacity, 0);
        }

        int left(int ind) {
            return 2*ind + 1;
        }

        int right(int ind) {
            return 2*ind + 2;
        }

        int parent(int ind) {
            return (ind-1)/2;
        }

        void heapify(int ind) {
            while (ind != 0) {
                int par = parent(ind);
                if (arr[par] > arr[ind]) {
                    swap(arr[par], arr[ind]);
                    ind = par;
                }
                else {
                    break;
                }
            }
        }

        int pop(){
            assert ( size>0 );
            int val = arr[0];
            swap(arr[0], arr[size-1]);
            size--;
            
            

            return val;
        }

        int peek(){
            assert ( size>0 );
            return arr[0];
        }

        void add(int val) {
            if (size == capacity) {
                capacity *= 2;
                arr.resize(capacity);
            }
            arr[size] = val;
            heapify(size);
            size++;
            debug(arr);
            debug(size);
        } 

        int get_size() {
            return size;
        }

};

int main()
{
    min_heap heap(10);
    heap.add(2);
    heap.add(1);
    heap.add(4);
    heap.add(3);
    heap.add(5);
    heap.add(6);
    heap.add(7);
    heap.add(8);
    heap.add(9);

    for(int i=0; i<9; i++)
        cout << heap.pop() << " ";

}

[dp] = 
 {{20,19,21},{9,9,9},{2,2,3}}
,{{10,9,8},{5,5,4},{1,2,1}}
,{{3,2,2},{2,1,1},{0,0,1}}}]