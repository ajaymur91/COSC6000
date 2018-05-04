//
//  sale.cpp
//  sample
//
//  Created by Hideki Fujioka on 4/18/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//

#include "sale.h"

namespace cosc3000
{
    Sale::Sale(): price(0)
    {
        /// nothing to do
    }
    Sale::Sale(double the_price) : price(the_price)
    {
        /// nothing to do
    }
    double Sale::bill() const
    {
        return price;
    }
    double Sale::savings(const Sale& other) const
    {
        return (bill() - other.bill());
    }
    bool operator < (const Sale &first, const Sale &second)
    {
        return (first.bill() < second.bill());
    }
}//cosc3000