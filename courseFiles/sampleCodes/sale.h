//
//  sale.h
//  sample
//
//  Created by Hideki Fujioka on 4/18/16.
//  Copyright © 2016 Hideki Fujioka. All rights reserved.
//
#ifndef sale_h
#define sale_h
#include <iostream>

namespace cosc3000
{
    class Sale
    {
    public:
        /// Default constructor
        Sale();
        /// constructor takes the price
        Sale(double the_price);
        /// Returns the bill
        virtual double bill() const;
        /// Returns the savings if you buy other
        /// instead of the calling object.
        double savings(const Sale& other) const;
    protected:
        double price;///< retail price of item
    };
    
    /// Compares tei sales to see which is larger
    bool operator < (const Sale &first,const Sale &second);
} // cosc3000
#endif /* sale_h */
