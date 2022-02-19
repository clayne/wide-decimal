///////////////////////////////////////////////////////////////////
//  Copyright Christopher Kormanyos 2020 - 2022.                 //
//  Distributed under the Boost Software License,                //
//  Version 1.0. (See accompanying file LICENSE_1_0.txt          //
//  or copy at http://www.boost.org/LICENSE_1_0.txt)             //
///////////////////////////////////////////////////////////////////

#ifndef INDEPENDENT_ALGEBRA_TEST_DECWIDE_T_WIDE_DECIMAL_2020_10_17_H
  #define INDEPENDENT_ALGEBRA_TEST_DECWIDE_T_WIDE_DECIMAL_2020_10_17_H

  #include <iomanip>
  #include <sstream>

  #include <math/wide_decimal/decwide_t.h>
  #include <test/independent_algebra_test_decwide_t_base.h>

  WIDE_DECIMAL_NAMESPACE_BEGIN

  #if(__cplusplus >= 201703L)
  namespace test::independent_algebra {
  #else
  namespace test { namespace independent_algebra { // NOLINT(modernize-concat-nested-namespaces)
  #endif

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  class independent_algebra_test_decwide_t_decwide_t : public independent_algebra_test_decwide_t_base
  {
  public:
    using float_type = math::wide_decimal::decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>;

    float_type my_decwide_t;

    independent_algebra_test_decwide_t_decwide_t() : my_decwide_t() { }

    independent_algebra_test_decwide_t_decwide_t(const char* str)
      : my_decwide_t(str) { }

    virtual ~independent_algebra_test_decwide_t_decwide_t() { }

    virtual void get_string(std::string& str) const
    {
      std::stringstream ss;

      ss << std::scientific
         << std::uppercase
         << std::setprecision(std::streamsize(std::numeric_limits<float_type>::digits10 + 1))
         << my_decwide_t;

      str = ss.str();
    }
  };

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  void eval_add(      independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& result,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& a,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& b)
  {
    result.my_decwide_t = a.my_decwide_t + b.my_decwide_t;
  }

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  void eval_sub(      independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& result,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& a,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& b)
  {
    result.my_decwide_t = a.my_decwide_t - b.my_decwide_t;
  }

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  void eval_mul(      independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& result,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& a,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& b)
  {
    result.my_decwide_t = a.my_decwide_t * b.my_decwide_t;
  }

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  void eval_div(      independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& result,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& a,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& b)
  {
    result.my_decwide_t = a.my_decwide_t / b.my_decwide_t;
  }

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  void eval_sqrt(      independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& result,
                 const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& a)
  {
    result.my_decwide_t = sqrt(a.my_decwide_t);
  }

  template<const std::int32_t ParamDigitsBaseTen, typename LimbType, typename AllocatorType, typename InternalFloatType, typename ExponentType, typename FftFloatType>
  void eval_log(      independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& result,
                const independent_algebra_test_decwide_t_decwide_t<ParamDigitsBaseTen, LimbType, AllocatorType, InternalFloatType, ExponentType, FftFloatType>& a)
  {
    result.my_decwide_t = log(a.my_decwide_t);
  }

  #if(__cplusplus >= 201703L)
  } // namespace test::independent_algebra
  #else
  } // namespace independent_algebra
  } // namespace test
  #endif

  WIDE_DECIMAL_NAMESPACE_END

#endif // INDEPENDENT_ALGEBRA_TEST_DECWIDE_T_WIDE_DECIMAL_2020_10_17_H
