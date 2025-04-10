///////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2022- 2025.                  //
//  Distributed under the Boost Software License,                //
//  Version 1.0. (See accompanying file LICENSE_1_0.txt          //
//  or copy at http://www.boost.org/LICENSE_1_0.txt)             //
///////////////////////////////////////////////////////////////////

#include <array>
#include <atomic>
#include <cmath>
#include <ctime>
#include <iomanip>
#include <iostream>
#include <sstream>

#if !defined(WIDE_DECIMAL_NAMESPACE)
#define WIDE_DECIMAL_NAMESPACE ckormanyos
#endif

#include <boost/multiprecision/mpfr.hpp>

#include <math/wide_decimal/decwide_t.h>
#include <test/parallel_for.h>

// cd /mnt/c/Users/User/Documents/Ks/PC_Software/NumericalPrograms/ExtendedNumberTypes/wide_decimal
// When using g++ and -std=c++20
// g++ -finline-functions -march=native -mtune=native -O3 -Werror -Wall -Wextra -std=c++20 -DWIDE_DECIMAL_NAMESPACE=ckormanyos -I. -I/mnt/c/boost/boost_1_83_0 test/test_high_precision_log.cpp -pthread -lpthread -lgmp -lmpfr -o test_high_precision_log.exe
// ./test_high_precision_log.exe

namespace test_high_precision_log
{
  constexpr auto my_digits10 = static_cast<std::int32_t>(INT32_C(1000011));

  using local_boost_high_precision_backend_type = boost::multiprecision::mpfr_float_backend<my_digits10, boost::multiprecision::allocate_dynamic>;
  using local_boost_high_precision_number_type  = boost::multiprecision::number<local_boost_high_precision_backend_type, boost::multiprecision::et_off>;

  using local_wide_decimal_high_precision_number_type = ckormanyos::math::wide_decimal::decwide_t<my_digits10, std::uint32_t, std::allocator<void>>;
} // namespace test_high_precision_log

namespace local
{
  #if defined(__clang__)
  constexpr auto adders_array_size = static_cast<std::size_t>(UINT8_C(5));
  #else
  constexpr auto adders_array_size = static_cast<std::size_t>(UINT8_C(8));
  #endif

  using adders_array_type = std::array<std::uint64_t, adders_array_size>;

  #if defined(__clang__)
  constexpr adders_array_type adders =
  {
    static_cast<std::uint64_t>(UINT8_C(0)),
    static_cast<std::uint64_t>(UINT8_C(6)),
    static_cast<std::uint64_t>(UINT8_C(12)),
    static_cast<std::uint64_t>(UINT16_C(9999)),
    static_cast<std::uint64_t>(UINT64_C(999999999999999999))
  };
  #else
  constexpr adders_array_type adders =
  {
    static_cast<std::uint64_t>(UINT8_C(0)),
    static_cast<std::uint64_t>(UINT8_C(3)),
    static_cast<std::uint64_t>(UINT8_C(6)),
    static_cast<std::uint64_t>(UINT8_C(9)),
    static_cast<std::uint64_t>(UINT8_C(12)),
    static_cast<std::uint64_t>(UINT8_C(15)),
    static_cast<std::uint64_t>(UINT16_C(9999)),
    static_cast<std::uint64_t>(UINT64_C(999999999999999999))
  };
  #endif

  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[0U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[1U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[2U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[3U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[4U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  #if defined(__clang__)
  #else
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[5U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[6U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  static_assert(static_cast<unsigned>(static_cast<std::uint64_t>(adders[7U] + static_cast<std::uint64_t>(UINT64_C(3))) % 3U) == static_cast<unsigned>(UINT8_C(0)), "Error adder must provie fractional part 1/3 in this test");
  #endif

  template<typename HighPrecisionFloatLeftType,
           typename HighPrecisionFloatRightType>
  static auto do_calcs_log() -> bool
  {
    using local_hp_float_left_type  = HighPrecisionFloatLeftType;
    using local_hp_float_right_type = HighPrecisionFloatRightType;

    const auto tol =
      local_hp_float_left_type
      (
          std::numeric_limits<local_hp_float_left_type>::epsilon()
        * static_cast<std::uint32_t>(UINT32_C(100000000))
      );

    auto result_is_ok = true;

    std::atomic_flag do_calcs_log_lock = ATOMIC_FLAG_INIT;

    using local_size_type = typename adders_array_type::size_type;

    const auto my_one = local_hp_float_left_type(static_cast<unsigned>(UINT8_C(1)));

    my_concurrency::parallel_for
    (
      static_cast<local_size_type>(UINT8_C(0)),
      static_cast<local_size_type>(local::adders_array_size),
      [&result_is_ok, &do_calcs_log_lock, &tol, &my_one](typename adders_array_type::size_type index)
      {
        const auto one_plus_adder_at_index = static_cast<std::uint64_t>(static_cast<std::uint64_t>(UINT64_C(1)) + adders[index]);

        const auto x_left  = local_hp_float_left_type (one_plus_adder_at_index) / static_cast<unsigned>(UINT8_C(3));
        const auto x_right = local_hp_float_right_type(one_plus_adder_at_index) / static_cast<unsigned>(UINT8_C(3));

        using std::log;

        const auto y_left  = log(x_left);
        const auto y_right = log(x_right);

        local_hp_float_left_type ratio { };

        {
          std::stringstream strm;

          strm << std::setprecision(test_high_precision_log::my_digits10) << y_right;

          ratio = y_left / local_hp_float_left_type(strm.str().c_str());
        }

        while(do_calcs_log_lock.test_and_set()) { ; }
        using std::fabs;

        const auto delta = ((my_one > ratio) ? (my_one - ratio) : (ratio - my_one));

        const auto is_close_fraction = (delta < tol);

        result_is_ok = (is_close_fraction && result_is_ok);

        {
          std::stringstream strm;

          strm << "index: "
               << index
               << ", is_close_fraction: "
               << std::boolalpha
               << is_close_fraction;

          const auto str_from_strm = strm.str();

          std::cout << str_from_strm << std::endl;
        }

        do_calcs_log_lock.clear();
      }
    );

    return result_is_ok;
  }
} // namespace local

auto main() -> int
{
  using local_hp_float_left_type  = test_high_precision_log::local_wide_decimal_high_precision_number_type;
  using local_hp_float_right_type = test_high_precision_log::local_boost_high_precision_number_type;

  const auto begin = std::clock();

  const auto result_is_ok = local::do_calcs_log<local_hp_float_left_type, local_hp_float_right_type>();

  const auto end = std::clock();

  const auto elapsed = static_cast<float>(static_cast<float>(end - begin) / CLOCKS_PER_SEC);

  std::cout << "result_is_ok: " << std::boolalpha << result_is_ok << std::endl;

  std::cout << "High-precision calculations took: " << std::fixed << std::setprecision(1) << elapsed << "s" << std::endl;

  return (result_is_ok ? 0 : -1);
}
