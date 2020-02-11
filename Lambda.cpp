// ConsoleApplication1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <array>

using std::cout;
using std::endl;

void printVector(std::vector<int>& v)
{
    std::for_each(v.begin(), v.end(), [](int i) { cout << i << " "; });
    cout << endl;
}

int main()
{
    std::vector<int> v = { 3, 5, 9, 2, 1, 4, 7 , 6 , 2, 3};
    std::vector<int> v1 = { 3, 5, 4, 2, 6, 4, 7 , 6 };
    int arr[] = {1, 2 , 3, 4, 5, 6, 7, 8 ,9, 10};
    int N = 5;

    printVector(v);
    std::sort(v.begin(), v.end(), [](const int& a, const int& b) {return a > b; });
    cout << "sorted vector:";
    printVector(v);

    std::vector<int>::iterator p = std::unique(v.begin(), v.end(), [](int a, int b) {return a == b; });
    v.resize(distance(v.begin(), p));
    cout << "after deleting duplicates:";
    printVector(v);

    int count = std::count_if(v.begin(), v.end(), [=](int a) {return (a >= N); });
    cout << "number of elements greater than " << N << ": "<< count << endl;

    int fact = std::accumulate(arr, arr + 10, 1, [](int i, int j) {return i * j; });
    cout << "factorial of 10:" << fact << endl;

    auto square = [](int i) {return i * i; };
    cout << "square of " << N << " = " << square(N) << endl;

    std::vector<int>::iterator p1 = std::find_if(v1.begin(), v1.end(), [N](int i) {return i > N; });
    cout << "first number greater than " << N << ": " << *p1 << endl;


}