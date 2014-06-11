/*
 * main.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: syrozhyk
 */

#include <thread>
#include <iostream>
using std::cout;
using std::endl;

#include "deadlock.hpp"

int main()
{
    //Deadlock simulation
    /*deadlock a(4), b(5);

    std::thread extra_thread(&deadlock::operator<, &a, std::ref(b));

    b.operator<(a);

    extra_thread.join();*/

    //Non-deadlock
    Value v1(4), v2(56);
    cout << "v1=" << v1 << ", v2=" << v2 << endl;

    swap(v1, v2);

    cout << "v1=" << v1 << ", v2=" << v2 << endl;


    cout << "Happy end!\n";

    return 0;
}


