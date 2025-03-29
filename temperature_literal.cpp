/*
    https://cpprefjp.github.io/lang/cpp11/scoped_enum.html
*/
#include <cmath>
#include <cassert>
#include <iostream>

bool are_equal(double const d1, double const d2,
               double const epsilon = 0.001) {
    return std::fabs(d1 - d2) < epsilon;
}

namespace temperature {

    // enum for temperature unit, class for temperature value
    enum class scale {celsius, fahrenheit, kelvin};

    template <scale S>
    class quantity {
        double const amount;

        public:
            constexpr explicit quantity(double const a) : amount(a) {}
            explicit operator double() const {return amount;}
    };

    // conparing operators of quantity<S>
    template <scale S>
    inline bool operator==(quantity<S> const & lhs, quantity<S> const & rhs) {
        return are_equal(static_cast<double>(lhs), static_cast<double>(rhs));
    }

    template <scale S>
    inline bool operator!=(quantity<S> const & lhs, quantity<S> const & rhs) {
        return !(lhs == rhs);
    }

    template <scale S>
    inline bool operator<(quantity<S> const & lhs, quantity<S> const & rhs) {
        return static_cast<double>(lhs) < static_cast<double>(rhs);
    }

    template <scale S>
    inline bool operator>(quantity<S> const & lhs, quantity<S> const & rhs) {
        return rhs < lhs;
    }

    template <scale S>
    inline bool operator<=(quantity<S> const & lhs, quantity<S> const & rhs) {
        return !(lhs > rhs);
    }

    template <scale S>
    inline bool operator>=(quantity<S> const & lhs, quantity<S> const & rhs) {
        return !(lhs < rhs);
    }

    template <scale S>
    constexpr quantity<S> operator+(quantity<S> const &q1,
                                 quantity<S> const &q2) {
        return quantity<S>(static_cast<double>(q1) + static_cast<double>(q2));
    }

    template <scale S>
    constexpr quantity<S> operator-(quantity<S> const &q1,
                                    quantity<S> const &q2){
        return quantity<S>(static_cast<double>(q1) - static_cast<double>(q2));
    }

    // unit conversion
    template <scale S, scale R>
    struct conversion_traits {
        static double convert(double const value) = delete;
    };

    template <>
    struct conversion_traits<scale::celsius, scale::fahrenheit> {
        static double convert(double const value) {
            return (value * 9) / 5 + 32;
        }
    };

    template <>
    struct conversion_traits<scale::fahrenheit, scale::celsius> {
        static double convert(double const value) {
            return (value -32) * 5 / 9;
        }
    };

    template <scale R, scale S>
    constexpr quantity<R> temperature_cast(quantity<S> const q) {
        return quantity<R>(conversion_traits<S, R>::convert(static_cast<double>(q)));
    }
}

namespace temperature::temperature_scale_literals {
    constexpr quantity<scale::celsius> operator ""_deg(long double const amount) {
        return quantity<scale::celsius> {static_cast<double>(amount)};
    }

    constexpr quantity<scale::fahrenheit> operator "" _f(long double const amount) {
        return quantity<scale::fahrenheit> {static_cast<double>(amount)};
    }

    constexpr quantity<scale::kelvin> operator ""_k(long double const amount) {
        return quantity<scale::kelvin> {static_cast<double>(amount)};
    }
}

int main() {
    using namespace temperature;
    using namespace temperature::temperature_scale_literals;

    double pi = 3.1415;
    double pi2 = 3.1414;
    assert(are_equal(pi, pi2));

    auto t1{36.5_deg};
    auto t2{79.0_f};

    auto tf = temperature_cast<scale::fahrenheit>(t1);
    auto tc = temperature_cast<scale::celsius>(tf);
    assert(t1 == tc);

    return 0;
}