/*
 [auto_generated]
 boost/numeric/odeint/util/copy.hpp

 [begin_description]
 Copy abstraction for the usage in the steppers.
 [end_description]

 Copyright 2009-2011 Karsten Ahnert
 Copyright 2009-2011 Mario Mulansky

 Distributed under the Boost Software License, Version 1.0.
 (See accompanying file LICENSE_1_0.txt or
 copy at http://www.boost.org/LICENSE_1_0.txt)
 */


#ifndef OMPLEXT_BOOST_NUMERIC_ODEINT_UTIL_COPY_HPP_INCLUDED
#define OMPLEXT_BOOST_NUMERIC_ODEINT_UTIL_COPY_HPP_INCLUDED


#include <boost/range/algorithm/copy.hpp>

#include <boost/utility/enable_if.hpp>

#include <omplext_odeint/boost/numeric/odeint/util/detail/is_range.hpp>

namespace boost {
namespace numeric {
namespace omplext_odeint {

namespace detail
{

template< class Container1 , class Container2 >
void do_copying( const Container1 &from , Container2 &to , boost::mpl::true_ )
{
    boost::range::copy( from , boost::begin( to ) );
}

template< class Container1 , class Container2 >
void do_copying( const Container1 &from , Container2 &to , boost::mpl::false_ )
{
    to = from;
}
}

/*
 * Default implementation of the copy operation used the assign operator
 * gsl_vector must copied differently
 */
template< class Container1, class Container2 >
struct copy_impl
{
    static void copy( const Container1 &from , Container2 &to )
    {
        typedef typename boost::numeric::omplext_odeint::detail::is_range< Container1 >::type is_range_type;
        detail::do_copying( from , to , is_range_type() );
    }
};

template< class Container1 , class Container2 >
void copy( const Container1 &from , Container2 &to )
{
    copy_impl< Container1 , Container2 >::copy( from , to );
}


} // namespace omplext_odeint
} // namespace numeric
} // namespace boost


#endif // BOOST_NUMERIC_ODEINT_UTIL_COPY_HPP_INCLUDED