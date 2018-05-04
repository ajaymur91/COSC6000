//
//  discountsale.cpp
//  sample
//
//  Created by Hideki Fujioka on 4/18/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//

#include "discountsale.h"

namespace cosc3000
{
    DiscountSale::DiscountSale():Sale(),discount(0)
    {
        /// nothing to do
    }
    DiscountSale::DiscountSale(double the_price,double the_discount)
    :Sale(the_price),discount(the_discount)
    {
        /// nothing to do
    }
    double DiscountSale::bill() const
    {
        double fraction = discount / 100;
        return (1 - fraction) * price;
    }
}