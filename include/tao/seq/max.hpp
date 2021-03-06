// Copyright (c) 2015-2017 Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/sequences/

#ifndef TAOCPP_SEQUENCES_INCLUDE_MAX_HPP
#define TAOCPP_SEQUENCES_INCLUDE_MAX_HPP

#include "fold.hpp"

#include <type_traits>

namespace tao
{
   namespace seq
   {
      namespace impl
      {
         template< typename T, T A, T B >
         using max = std::integral_constant< T, ( ( A > B ) ? A : B ) >;
      }

      template< typename T, T... Ns >
      struct max
         : fold< impl::max, T, Ns... >
      {
      };

      template< typename T, T... Ns >
      struct max< integer_sequence< T, Ns... > >
         : max< T, Ns... >
      {
      };
   }
}

#endif  // TAOCPP_SEQUENCES_INCLUDE_MAX_HPP
