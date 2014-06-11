/*
 * deadlock.hpp
 *
 *  Created on: Jun 6, 2014
 *      Author: syrozhyk
 */

#ifndef DEADLOCK_HPP_
#define DEADLOCK_HPP_

#include <mutex>
#include <iostream>
#include <unistd.h>

class deadlock {
public:
    deadlock(int x = 0): x_(x) {}

    bool operator<(deadlock & left) {
        std::cout << "Thread in obj(" << x_ << ") trying to lock this->m_\n";
        std::lock_guard<std::mutex> guard_this(this->m_);
        std::cout << "Thread in obj(" << x_ << ") locked this->m_\n";
        sleep(2);
        std::cout << "Thread in obj(" << x_ << ") trying to lock left.m_\n";
        std::lock_guard<std::mutex> guard_that(left.m_);
        std::cout << "Thread in obj(" << x_ << ") locked ledft.m_\n";

        return this->x_ < left.x_;
    }

private:
    int x_;
    std::mutex m_;
};


class Value {
    friend void swap(Value &v1, Value &v2);
    friend std::ostream &operator<<(std::ostream & out, Value &v);
public:
    Value(int v=0): val_(v) {}
private:
    int val_;
    std::mutex m_;
};




#endif /* DEADLOCK_HPP_ */
