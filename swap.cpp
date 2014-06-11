/*
 * swap.cpp
 *
 *  Created on: Jun 6, 2014
 *      Author: syrozhyk
 */

#include <algorithm>
#include "deadlock.hpp"

void swap(Value &v1, Value &v2)
{
    if (&v1 == &v2)
        return;

    std::lock(v1.m_, v2.m_);
    std::lock_guard<std::mutex> guard_left(v1.m_, std::adopt_lock);
    std::lock_guard<std::mutex> guard_right(v2.m_, std::adopt_lock);

    std::swap(v1.val_, v2.val_);
}

std::ostream &operator<<(std::ostream &out, Value &v)
{
    out << v.val_;
    return out;
}
