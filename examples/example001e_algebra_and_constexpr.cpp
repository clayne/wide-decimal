///////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2020 - 2022.                 //
//  Distributed under the Boost Software License,                //
//  Version 1.0. (See accompanying file LICENSE_1_0.txt          //
//  or copy at http://www.boost.org/LICENSE_1_0.txt)             //
///////////////////////////////////////////////////////////////////

#include <cstdint>

#include <examples/example_decwide_t.h>
#include <math/wide_decimal/decwide_t.h>

#if defined(WIDE_DECIMAL_NAMESPACE)
auto WIDE_DECIMAL_NAMESPACE::math::wide_decimal::example001e_algebra_and_constexpr() -> bool
#else
auto ::math::wide_decimal::example001e_algebra_and_constexpr() -> bool
#endif
{
  using local_limb_type = std::uint32_t;

  constexpr std::int32_t wide_decimal_digits10 = INT32_C(100);

  #if defined(WIDE_DECIMAL_NAMESPACE)
  using wide_decimal_type = WIDE_DECIMAL_NAMESPACE::math::wide_decimal::decwide_t<wide_decimal_digits10, local_limb_type, void>;
  #else
  using wide_decimal_type = ::math::wide_decimal::decwide_t<wide_decimal_digits10, local_limb_type, void>;
  #endif

  bool result_is_ok = true;

  WIDE_DECIMAL_CONSTEXPR wide_decimal_type local_quarter_a(wide_decimal_type(static_cast<unsigned>(UINT8_C(25))) / static_cast<unsigned>(UINT8_C(100)));
  WIDE_DECIMAL_CONSTEXPR wide_decimal_type local_quarter_b(0.25F);

  #if (defined(WIDE_DECIMAL_CONSTEXPR_IS_COMPILE_TIME_CONST) && (WIDE_DECIMAL_CONSTEXPR_IS_COMPILE_TIME_CONST != 0))
  static_assert(local_quarter_a == local_quarter_b, "Error: Constexpr construction of built-in float is incorrect");
  #endif

  return result_is_ok;
}

// Enable this if you would like to activate this main() as a standalone example.
#if defined(WIDE_DECIMAL_STANDALONE_EXAMPLE001E_ALGEBRA_AND_CONSTEXPR)

#include <iomanip>
#include <iostream>

auto main() -> int
{
  const auto result_is_ok = ::math::wide_decimal::example001e_algebra_and_constexpr();

  std::cout << "result_is_ok: " << std::boolalpha << result_is_ok << std::endl;
}

#endif
