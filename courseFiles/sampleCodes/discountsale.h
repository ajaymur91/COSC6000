//
//  discountsale.hpp
//  sample
//
//  Created by Hideki Fujioka on 4/18/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//
#ifndef discountsale_h
#define discountsale_h
#include "sale.h"

namespace cosc3000
{
    class DiscountSale : public Sale
    {
    public:
        /// Default constructor
        DiscountSale();
        /// Discount is expressed as a percent of the price.
        DiscountSale(double the_price,double the_discount);
        /// Returns the bill
        virtual double bill() const;
    protected:
        double discount; ///< percent of discount
    };
}//cosc3000

#endif /* discountsale_h */
