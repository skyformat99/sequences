// Copyright (c) 2015-2017 Daniel Frey
// Please see LICENSE for license or visit https://github.com/taocpp/sequences/

#ifndef TAOCPP_SEQUENCES_INCLUDE_MIN_HPP
#define TAOCPP_SEQUENCES_INCLUDE_MIN_HPP

#include "fold.hpp"

#include <type_traits>

namespace tao
{
   namespace seq
   {
      namespace impl
      {
         template< typename T, T A, T B >
         using min = std::integral_constant< T, ( ( A < B ) ? A : B ) >;
      }

      template< typename T, T... Ns >
      struct min
         : fold< impl::min, T, Ns... >
      {
      };

      template< typename T, T... Ns >
      struct min< integer_sequence< T, Ns... > >
         : min< T, Ns... >
      {
      };
   }
}

#endif  // TAOCPP_SEQUENCES_INCLUDE_MIN_HPP
