#pragma once

//
// glslike.hpp
//
// Copyright 2022 mugwort_rc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//    http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.
//

// windows.h is evil
#ifdef min
#undef min
#endif  // min
#ifdef max
#undef max
#endif  // max

#include <algorithm>
#include <cmath>
#include <cstdint>
#include <type_traits>

//#define GLSLIKE_USE_HALIDE
#ifdef GLSLIKE_USE_HALIDE
#include <Halide.h>
typedef Halide::Expr Bool_t;
#else
typedef bool Bool_t;
#endif  // GLSLIKE_USE_HALIDE


namespace glslike {

template<typename C>
class math {
private:
    math();
    math(const math &);
    math(math &&);

public:
    static constexpr C pi = static_cast<C>(3.1415926535897932384626433832795029);

public:
    // 8.1 Angle and Trigonometry Functions

    static C radians(C degrees) {
        return degrees * pi / 180.0f;
    }

    static C degrees(C radians) {
        return radians * 180.0f / pi;
    }

    static C sin(C angle) {
        return std::sin(angle);
    }

    static C cos(C angle) {
        return std::cos(angle);
    }

    static C tan(C angle) {
        return std::tan(angle);
    }

    static C asin(C x) {
        return std::sin(x);
    }

    static C acos(C x) {
        return std::cos(x);
    }

    static C atan(C y, C x) {
        return std::atan2(y, x);
    }

    static C atan(C y_over_x) {
        return std::atan(y_over_x);
    }

    static C sinh(C x) {
        return std::sinh(x);
    }

    static C cosh(C x) {
        return std::cosh(x);
    }

    static C tanh(C x) {
        return std::tanh(x);
    }

    static C asinh(C x) {
        return std::asinh(x);
    }

    static C acosh(C x) {
        return std::acosh(x);
    }

    static C atanh(C x) {
        return std::atanh(x);
    }

    // 8.2 Exponential Functions

    template <typename ExpT>
    static C pow(C base, ExpT exp) {
        return std::pow(base, exp);
    }

    static C exp(C scalar) {
        return std::exp(scalar);
    }

    static C log(C x) {
        return std::log(x);
    }

    static C exp2(C scalar) {
        return std::exp2(scalar);
    }

    static C log2(C x) {
        return std::log2(x);
    }

    static C sqrt(C scalar) {
        return std::sqrt(scalar);
    }

    static C inversesqrt(C scalar) {
        return 1.0f / std::sqrt(scalar);
    }

    // 8.3 Common Functions

    static C abs(C x) {
        return std::abs(x);
    }

    static C sign(C x) {
        return (x > 0.0f ? 1.0f : (x < 0.0f ? -1.0f : 0.0f));
    }

    static C floor(C x) {
        return std::floor(x);
    }

    static C trunc(C x) {
        return std::trunc(x);
    }

    static C round(C x) {
        return std::round(x);
    }

    static C roundEven(C x) {
        return round(x / 2.0f) * 2.0f;
    }

    static C ceil(C x) {
        return std::ceil(x);
    }

    static C fract(C x) {
        return x - floor(x);
    }

    static C mod(C x, C y) {
        return x - y * floor(x / y);
    }

    static C modf(C x, C *i) {
        return std::modf(x, i);
    }

    static C min(C a, C b) {
        return std::min(a, b);
    }

    static C max(C a, C b) {
        return std::max(a, b);
    }

    static C clamp(C value, C min, C max) {
        return std::clamp(value, min, max);
    }

    static C mix(C x, C y, C a) {
        return x * (1 - a) + y * a;
    }

    static C mix(C x, C y, bool a) {
        return a ? y : x;
    }

    static C step(C edge, C x) {
        return x < edge ? 0.0f : 1.0f;
    }

    static C smoothstep(C edge0, C edge1, C x) {
        //assert(edge0 < edge1)
        C t = clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
        return t * t * (3.0f - 2.0f * t);
    }

    static bool isnan(C x) {
        return std::isnan(x);
    }

    static bool isinf(C x) {
        return std::isinf(x);
    }

    //template <typename IntT>
    //IntT floatBitsToInt(C value) {
    //    //
    //}
    //template <typename IntT>
    //IntT floatBitsToUint(C value) {
    //    //
    //}
    //template <typename IntT>
    //C intBitsToFloat(IntT value) {
    //    //
    //}
    //template <typename IntT>
    //C uintBitsToFloat(IntT value) {
    //    //
    //}

    C fma(C a, C b, C c) {
        return a * b + c;
    }

    //template <typename IntT>
    //C frexp(C x, IntT *exp) {
    //
    //}
    //template <typename IntT>
    //C ldexp(C x, IntT exp) {
    //
    //}

};

template <typename T>
inline static T select(bool cond, T true_value, T false_value) {
    return cond ? true_value : false_value;
}

#ifdef GLSLIKE_USE_HALIDE

template<>
class math<Halide::Expr> {
private:
    math();
    math(const math &);
    math(math &&);
public:

public:
    // 8.1 Angle and Trigonometry Functions

    static C radians(C degrees) {
        return degrees * pi / 180.0f;
    }

    static C degrees(C radians) {
        return radians * 180.0f / pi;
    }

    static C sin(C angle) {
        return Halide::sin(angle);
    }

    static C cos(C angle) {
        return Halide::cos(angle);
    }

    static C tan(C angle) {
        return Halide::tan(angle);
    }

    static C asin(C x) {
        return Halide::sin(x);
    }

    static C acos(C x) {
        return Halide::cos(x);
    }

    static C atan(C y, C x) {
        return Halide::atan2(y, x);
    }

    static C atan(C y_over_x) {
        return Halide::atan(y_over_x);
    }

    static C sinh(C x) {
        return Halide::sinh(x);
    }

    static C cosh(C x) {
        return Halide::cosh(x);
    }

    static C tanh(C x) {
        return Halide::tanh(x);
    }

    static C asinh(C x) {
        return Halide::asinh(x);
    }

    static C acosh(C x) {
        return Halide::acosh(x);
    }

    static C atanh(C x) {
        return Halide::atanh(x);
    }

    // 8.2 Exponential Functions

    template <typename ExpT>
    static C pow(C base, ExpT exp) {
        return Halide::pow(base, exp);
    }

    static C exp(C scalar) {
        return Halide::exp(scalar);
    }

    static C log(C x) {
        return Halide::log(x);
    }

    static C exp2(C scalar) {
        return Halide::pow(2.0f, scalar);
    }

    static C log2(C x) {
        return Halide::log(x) / Halide::log(2.0f);
    }

    static C sqrt(C scalar) {
        return Halide::sqrt(scalar);
    }

    static C inversesqrt(C scalar) {
        return 1.0f / Halide::sqrt(scalar);
    }

    // 8.3 Common Functions

    static C abs(C x) {
        return Halide::abs(x);
    }

    static C sign(C x) {
        return Halide::select(
            x > 0.0f,
            1.0f,
            Halide::select(
                x < 0.0f,
                -1.0f,
                 0.0f
            )
        );
    }

    static C floor(C x) {
        return Halide::floor(x);
    }

    static C trunc(C x) {
        return Halide::trunc(x);
    }

    static C round(C x) {
        return Halide::round(x);
    }

    static C roundEven(C x) {
        return round(x / 2.0f) * 2.0f;
    }

    static C ceil(C x) {
        return Halide::ceil(x);
    }

    static C fract(C x) {
        return x - floor(x);
    }

    static C mod(C x, C y) {
        return x - y * floor(x / y);
    }

    static C modf(C x, C *i) {
        const auto int_part = Halide::cast<std::int64_t>(x);
        if (i) {
            *i = int_part;
        }
        return copysign(
            Halide::select(
                isinf(x),
                0.0f,
                value - int_part
            ),
            value
        );
    }

    static C min(C a, C b) {
        return Halide::min(a, b);
    }

    static C max(C a, C b) {
        return Halide::max(a, b);
    }

    static C clamp(C value, C min, C max) {
        return Halide::clamp(value, min, max);
    }

    static C mix(C x, C y, C a) {
        return x * (1 - a) + y * a;
    }

    static C mix(C x, C y, Halide::Expr a) {
        return Halide::select(a, y, x);
    }

    static C step(C edge, C x) {
        return Halide::select(x < edge, 0.0f, 1.0f);
    }

    static C smoothstep(C edge0, C edge1, C x) {
        //assert(edge0 < edge1)
        C t = clamp((x - edge0) / (edge1 - edge0), 0.0f, 1.0f);
        return t * t * (3.0 - 2.0 * t);
    }

    static bool isnan(C x) {
        return Halide::is_nan(x);
    }

    static bool isinf(C x) {
        return Halide::is_inf(x);
    }

    //template <typename IntT>
    //IntT floatBitsToInt(C value) {
    //    //
    //}
    //template <typename IntT>
    //IntT floatBitsToUint(C value) {
    //    //
    //}
    //template <typename IntT>
    //C intBitsToFloat(IntT value) {
    //    //
    //}
    //template <typename IntT>
    //C uintBitsToFloat(IntT value) {
    //    //
    //}

    C fma(C a, C b, C c) {
        return a * b + c;
    }

    //template <typename IntT>
    //C frexp(C x, IntT *exp) {
    //
    //}
    //template <typename IntT>
    //C ldexp(C x, IntT exp) {
    //
    //}

protected:
    C copysign(C x, C y) {
        const auto absolute_value = Halide::select(
            isnan(x),
            Halide::Expr(std::numeric_limits<float>::quiet_NaN()),
            abs(x)
        );
        return Halide::select(
            y >= 0.0f,
            absolute_value,
            -absolute_value
        );
    }

};

template <typename T>
inline static T select(Halide::Expr cond, T true_value, T false_value) {
    return Halide::select(cond, true_value, false_value);
}

#endif

//
// 8.1 Angle and Trigonometry Functions
// These all operate component-wise.
//

template <typename T>
T radians(T degrees) {
    return math<T>::radians(degrees);
}

template <typename T>
T degrees(T radians) {
    return math<T>::degrees(radians);
}

template <typename T>
T sin(T angle) {
    return math<T>::sin(angle);
}

template <typename T>
T cos(T angle) {
    return math<T>::cos(angle);
}

template <typename T>
T tan(T angle) {
    return math<T>::tan(angle);
}

template <typename T>
T asin(T x) {
    return math<T>::asin(x);
}

template <typename T>
T acos(T x) {
    return math<T>::acos(x);
}

template <typename T>
T atan(T y, T x) {
    return math<T>::atan(y, x);
}

template <typename T>
T atan(T y_over_x) {
    return math<T>::atan(y_over_x);
}

template <typename T>
T sinh(T angle) {
    return math<T>::sinh(angle);
}

template <typename T>
T cosh(T angle) {
    return math<T>::cosh(angle);
}

template <typename T>
T tanh(T angle) {
    return math<T>::tanh(angle);
}

template <typename T>
T asinh(T x) {
    return math<T>::asinh(x);
}

template <typename T>
T acosh(T x) {
    return math<T>::acosh(x);
}

template <typename T>
T atanh(T x) {
    return math<T>::atanh(x);
}

//
// 8.2 Exponential Functions
//

template <typename T, typename ScalarT>
T pow(T scalar, ScalarT n) {
    return math<T>::pow(scalar, n);
}

template <typename T>
T exp(T scalar) {
    return math<T>::exp(scalar);
}

template <typename T>
T log(T scalar) {
    return math<T>::log(scalar);
}

template <typename T>
T exp2(T scalar) {
    return math<T>::exp2(scalar);
}

template <typename T>
T log2(T scalar) {
    return math<T>::log2(scalar);
}

template <typename T>
T sqrt(T scalar) {
    return math<T>::sqrt(scalar);
}

template <typename T>
T inversesqrt(T scalar) {
    return math<T>::inversesqrt(scalar);
}

//
// 8.3 Common Functions
//

template <typename T>
T abs(T x) {
    return math<T>::abs(x);
}

template <typename T>
T sign(T x) {
    return math<T>::sign(x);
}

template <typename T>
T floor(T x) {
    return math<T>::floor(x);
}

template <typename T>
T trunc(T x) {
    return math<T>::trunc(x);
}

template <typename T>
T round(T x) {
    return math<T>::round(x);
}

template <typename T>
T roundEven(T x) {
    return math<T>::roundEven(x);
}

template <typename T>
T ceil(T x) {
    return math<T>::ceil(x);
}

template <typename T>
T fract(T x) {
    return math<T>::fract(x);
}

template <typename T>
T mod(T x, T y) {
    return math<T>::mod(x, y);
}

template <typename T>
T modf(T x, T *i) {
    return math<T>::modf(x, i);
}

template <typename T>
T min(T a, T b) {
    return math<T>::min(a, b);
}

template <typename T>
T max(T a, T b) {
    return math<T>::max(a, b);
}

template <typename T>
T clamp(T value, T min, T max) {
    return math<T>::clamp(value, min, max);
}

template <typename T>
T mix(T x, T y, T a) {
    return math<T>::mix(x, y, a);
}

template <typename T>
T step(T edge, T x) {
    return math<T>::step(edge, x);
}

template <typename T>
T smoothstep(T edge0, T edge1, T x) {
    return math<T>::smoothstep(edge0, edge1, x);
}

template <typename T>
bool isnan(T x) {
    return math<T>::isnan(x);
}

template <typename T>
bool isinf(T x) {
    return math<T>::isinf(x);
}

//
// TODO:
// * floatBitToInt
// * floatBitToUint
// * intBitsToFloat
// * fma
// * frexp
// * ldexp
//

// 8.4 Floating-Point Pack and Unpack Functions
//
// * packUnorm2x16
// * packSnorm2x16
// * packUnorm4x8
// * packSnorm4x8
// * unpackUnorm2x16
// * unpackSnorm2x16
// * unpackUnorm4x8
// * unpackSnorm4x8
// * packDouble2x32
// * unpackDouble2x32
// * packHalf2x16
// * unpackHalf2x16
//
// 8.5 Geometric Functions
//

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T length(T x) {
    return math<T>::abs(x);
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T distance(T p0, T p1) {
    return length(p0 - p1);
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T dot(T x, T y) {
    return x * y;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T normalize(T x) {
    return 1.0f;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T faceforward(T n, T i, T nref) {
    return select(dot(nref, i) < 0.0f, n, -n);
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T reflect(T i, T n) {
    return i - 2 * dot(n, i) * n;
}

template <typename T, typename = typename std::enable_if<std::is_arithmetic<T>::value>::type>
T refract(T i, T n, float eta) {
    const auto k = 1.0f - eta * eta * (1.0f - dot(n, i) * dot(n, i));
    return select(
        k < 0.0f,
        0.0f,
        eta * i - (eta * dot(n, i) + sqrt(k)) * n
    );
}

// 8.6 Matrix Functions
//
// * matrixCompMult
// * outerProduct
// * transpose
// * determinant
// * inverse
//
// 8.7 Vector Relational Functions
//
// * lessThan
// * lessThanEqual
// * greaterThan
// * greaterThanEqual
// * equal
// * notEqual
// * any
// * all
// * not
//
// 8.8 Integer Functions
//
// * uaddCarry
// * usubBorrow
// * umulExtended
// * imulExtended
// * bitfieldExtract
// * bitfieldInsert
// * bitfieldReverse
// * bitCount
// * findLSB
// * findMSB


template <typename R, typename T, R T::Base_t::*pm>
class alias {
public:
    alias(const T *self)
        : self(self)
    {}

    operator R() const {
        return self->*pm;
    }

    const T *self;
};


template <typename T>
class Vector2Core {
public:
    Vector2Core(T x)
        : x(x)
        , y(x)
    {}
    Vector2Core(T x, T y)
        : x(x)
        , y(y)
    {}

    Vector2Core(const Vector2Core<T> &copy)
        : x(copy.x)
        , y(copy.y)
    {}

    Vector2Core(Vector2Core<T> &&move)
        : x(std::move(move.x))
        , y(std::move(move.y))
    {}

    Vector2Core<T> &operator =(const Vector2Core<T> &copy) {
        x = copy.x;
        y = copy.y;
        return *this;
    }

    Vector2Core<T> &operator =(Vector2Core<T> &&move) {
        x = std::move(move.x);
        y = std::move(move.y);
        return *this;
    }

    T x, y;
};


template <typename T>
class Vector3Core {
public:
    Vector3Core(T x)
        : x(x)
        , y(x)
        , z(x)
    {}
    Vector3Core(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
    {}

    Vector3Core(const Vector3Core<T> &copy)
        : x(copy.x)
        , y(copy.y)
        , z(copy.z)
    {}

    Vector3Core(Vector3Core<T> &&move)
        : x(std::move(move.x))
        , y(std::move(move.y))
        , z(std::move(move.z))
    {}

    Vector3Core<T> &operator =(const Vector3Core<T> &copy) {
        x = copy.x;
        y = copy.y;
        z = copy.z;
        return *this;
    }

    Vector3Core<T> &operator =(Vector3Core<T> &&move) {
        x = std::move(move.x);
        y = std::move(move.y);
        z = std::move(move.z);
        return *this;
    }

    T x, y, z;
};


template <typename T>
class Vector4Core {
public:
    Vector4Core(T x)
        : x(x)
        , y(x)
        , z(x)
        , w(x)
    {}
    Vector4Core(T x, T y, T z, T w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {}

    Vector4Core(const Vector4Core<T> &copy)
        : x(copy.x)
        , y(copy.y)
        , z(copy.z)
        , w(copy.w)
    {}

    Vector4Core(Vector4Core<T> &&move)
        : x(std::move(move.x))
        , y(std::move(move.y))
        , z(std::move(move.z))
        , w(std::move(move.w))
    {}

    Vector4Core<T> &operator =(const Vector4Core<T> &copy) {
        x = copy.x;
        y = copy.y;
        z = copy.z;
        w = copy.w;
        return *this;
    }

    Vector4Core<T> &operator =(Vector4Core<T> &&move) {
        x = std::move(move.x);
        y = std::move(move.y);
        z = std::move(move.z);
        w = std::move(move.w);
        return *this;
    }

    T x, y, z, w;
};


#ifndef GLSLIKE_DISABLE_SWIZZLE

template <typename T>
class Swizzle2 {
public:
    Swizzle2(T &x, T &y)
        : x(x)
        , y(y)
    {}

    operator Vector2Core<T>() const {
        return Vector2Core<T>(
            x,
            y
        );
    }

    T &x;
    T &y;
};


template <typename T>
class Swizzle3 {
public:
    Swizzle3(T &x, T &y, T &z)
        : x(x)
        , y(y)
        , z(z)
    {}

    operator Vector3Core<T>() const {
        return Vector3Core<T>(
            x,
            y,
            z
        );
    }

    T &x;
    T &y;
    T &z;
};


template <typename T>
class Swizzle4 {
public:
    Swizzle4(T &x, T &y, T &z, T &w)
        : x(x)
        , y(y)
        , z(z)
        , w(w)
    {}

    operator Vector4Core<T>() const {
        return Vector4Core<T>(
            x,
            y,
            z,
            w
        );
    }

    T &x;
    T &y;
    T &z;
    T &w;
};

#endif  // GLSLIKE_DISABLE_SWIZZLE


#ifdef GLSLIKE_DISABLE_SWIZZLE
#define GLSLIKE_VECTOR2_SWIZZLE() \
    r(this->x) \
    , g(this->y) \
    , s(this->x) \
    , t(this->y)
#else
#define GLSLIKE_VECTOR2_SWIZZLE() \
    r(this->x) \
    , g(this->y) \
    , s(this->x) \
    , t(this->y) \
    , xx(this->x, this->x) \
    , xy(this->x, this->y) \
    , yx(this->y, this->x) \
    , yy(this->y, this->y) \
    , rr(this->x, this->x) \
    , rg(this->x, this->y) \
    , gr(this->y, this->x) \
    , gg(this->y, this->y) \
    , ss(this->x, this->x) \
    , st(this->x, this->y) \
    , ts(this->y, this->x) \
    , tt(this->y, this->y) \
    , xxx(this->x, this->x, this->x) \
    , xxy(this->x, this->x, this->y) \
    , xyx(this->x, this->y, this->x) \
    , xyy(this->x, this->y, this->y) \
    , yxx(this->y, this->x, this->x) \
    , yxy(this->y, this->x, this->y) \
    , yyx(this->y, this->y, this->x) \
    , yyy(this->y, this->y, this->y) \
    , rrr(this->x, this->x, this->x) \
    , rrg(this->x, this->x, this->y) \
    , rgr(this->x, this->y, this->x) \
    , rgg(this->x, this->y, this->y) \
    , grr(this->y, this->x, this->x) \
    , grg(this->y, this->x, this->y) \
    , ggr(this->y, this->y, this->x) \
    , ggg(this->y, this->y, this->y) \
    , sss(this->x, this->x, this->x) \
    , sst(this->x, this->x, this->y) \
    , sts(this->x, this->y, this->x) \
    , stt(this->x, this->y, this->y) \
    , tss(this->y, this->x, this->x) \
    , tst(this->y, this->x, this->y) \
    , tts(this->y, this->y, this->x) \
    , ttt(this->y, this->y, this->y) \
    , xxxx(this->x, this->x, this->x, this->x) \
    , xxxy(this->x, this->x, this->x, this->y) \
    , xxyx(this->x, this->x, this->y, this->x) \
    , xxyy(this->x, this->x, this->y, this->y) \
    , xyxx(this->x, this->y, this->x, this->x) \
    , xyxy(this->x, this->y, this->x, this->y) \
    , xyyx(this->x, this->y, this->y, this->x) \
    , xyyy(this->x, this->y, this->y, this->y) \
    , yxxx(this->y, this->x, this->x, this->x) \
    , yxxy(this->y, this->x, this->x, this->y) \
    , yxyx(this->y, this->x, this->y, this->x) \
    , yxyy(this->y, this->x, this->y, this->y) \
    , yyxx(this->y, this->y, this->x, this->x) \
    , yyxy(this->y, this->y, this->x, this->y) \
    , yyyx(this->y, this->y, this->y, this->x) \
    , yyyy(this->y, this->y, this->y, this->y) \
    , rrrr(this->x, this->x, this->x, this->x) \
    , rrrg(this->x, this->x, this->x, this->y) \
    , rrgr(this->x, this->x, this->y, this->x) \
    , rrgg(this->x, this->x, this->y, this->y) \
    , rgrr(this->x, this->y, this->x, this->x) \
    , rgrg(this->x, this->y, this->x, this->y) \
    , rggr(this->x, this->y, this->y, this->x) \
    , rggg(this->x, this->y, this->y, this->y) \
    , grrr(this->y, this->x, this->x, this->x) \
    , grrg(this->y, this->x, this->x, this->y) \
    , grgr(this->y, this->x, this->y, this->x) \
    , grgg(this->y, this->x, this->y, this->y) \
    , ggrr(this->y, this->y, this->x, this->x) \
    , ggrg(this->y, this->y, this->x, this->y) \
    , gggr(this->y, this->y, this->y, this->x) \
    , gggg(this->y, this->y, this->y, this->y) \
    , ssss(this->x, this->x, this->x, this->x) \
    , ssst(this->x, this->x, this->x, this->y) \
    , ssts(this->x, this->x, this->y, this->x) \
    , sstt(this->x, this->x, this->y, this->y) \
    , stss(this->x, this->y, this->x, this->x) \
    , stst(this->x, this->y, this->x, this->y) \
    , stts(this->x, this->y, this->y, this->x) \
    , sttt(this->x, this->y, this->y, this->y) \
    , tsss(this->y, this->x, this->x, this->x) \
    , tsst(this->y, this->x, this->x, this->y) \
    , tsts(this->y, this->x, this->y, this->x) \
    , tstt(this->y, this->x, this->y, this->y) \
    , ttss(this->y, this->y, this->x, this->x) \
    , ttst(this->y, this->y, this->x, this->y) \
    , ttts(this->y, this->y, this->y, this->x) \
    , tttt(this->y, this->y, this->y, this->y)
#endif  // GLSLIKE_DISABLE_SWIZZLE

template <typename T>
class Vector2 : public Vector2Core<T> {
public:
    typedef Vector2Core<T> Base_t;
    typedef T Type_t;
    using Vector2Core<T>::Vector2Core;
    using Vector2Core<T>::x;
    using Vector2Core<T>::y;

public:
    explicit Vector2(T x)
        : Vector2Core<T>::Vector2Core(x)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}
    Vector2(T x, T y)
        : Vector2Core<T>::Vector2Core(x, y)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

    Vector2(const Vector2<T> &copy)
        : Vector2Core<T>::Vector2Core(copy)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

    Vector2(Vector2<T> &&move)
        : Vector2Core<T>::Vector2Core(move)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

    Vector2(const Vector2Core<T> &core)
        : Vector2Core<T>::Vector2Core(core)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

#ifndef GLSLIKE_DISABLE_SWIZZLE
    template <typename SwizzleT, typename std::enable_if<std::is_convertible<SwizzleT, Vector2Core<T>>::value>::type * = nullptr>
    Vector2(const SwizzleT &core)
        : Vector2Core<T>::Vector2Core(static_cast<Vector2Core<T>>(core))
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}
#endif  // GLSLIKE_DISABLE_SWIZZLE

    T operator [](int i) const {
        switch (i) {
        case 0:
            return x;
        case 1:
            return y;
        default:
            throw std::out_of_range("index out of range");
        }
    }

    Vector2<T> clone() const {
        return Vector2<T>(x, y);
    }

    Vector2<T> &copy(const Vector2<T> &vec) {
        x = vec.x;
        y = vec.y;
        return *this;
    }

    Vector2<T> &set(T fXVal, T fYVal) {
        x = fXVal;
        y = fYVal;
        return *this;
    }

    Vector2<T> &add(const Vector2<T> &vec) {
        x += vec.x;
        y += vec.y;
        return *this;
    }

    Vector2<T> &addScalar(T scalar) {
        x += scalar;
        y += scalar;
        return *this;
    }

    Vector2<T> &multiplyScalar(T scalar) {
        x *= scalar;
        y *= scalar;
        return *this;
    }

    Vector2<T> &divideScalar(T scalar) {
        x /= scalar;
        y /= scalar;
        return *this;
    }

    // 8.5 Geometric Functions

    T length() const {
        return glslike::math<T>::sqrt(x * x + y * y);
    }

    T distance(const Vector2<T> &v) const {
        return (*this - v).length();
    }

    T dot(const Vector2<T> &vec) const {
        return x * vec.x + y * vec.y;
    }

    Vector2<T> normalize() {
        const auto len = length();
        //assert(len != 0.0f);
        return divideScalar(len);
    }

    std::array<T, 2> toArray() const {
        return {x, y};
    }

    //
    // glsl-like interface
    //

    Vector2<T> operator +() const {
        return Vector2<T>(
            +x,
            +y
        );
    }

    Vector2<T> operator -() const {
        return Vector2<T>(
            -x,
            -y
        );
    }

    Vector2<T> operator +(T rhs) const {
        return Vector2<T>(
            x + rhs,
            y + rhs
        );
    }
    Vector2<T> &operator +=(T rhs) {
        x += rhs;
        y += rhs;
        return *this;
    }
    Vector2<T> operator +(const Vector2<T> &rhs) const {
        return Vector2<T>(
            x + rhs.x,
            y + rhs.y
        );
    }
    Vector2<T> &operator +=(const Vector2<T> &rhs) {
        x += rhs.x;
        y += rhs.y;
        return *this;
    }
    Vector2<T> operator -(T rhs) const {
        return Vector2<T>(
            x - rhs,
            y - rhs
        );
    }
    Vector2<T> &operator -=(T rhs) {
        x -= rhs;
        y -= rhs;
        return *this;
    }
    Vector2<T> operator -(const Vector2<T> &rhs) const {
        return Vector2<T>(
            x - rhs.x,
            y - rhs.y
        );
    }
    Vector2<T> &operator -=(const Vector2<T> &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        return *this;
    }
    Vector2<T> operator *(T rhs) const {
        return Vector2<T>(
            x * rhs,
            y * rhs
        );
    }
    Vector2<T> &operator *=(T rhs) {
        x *= rhs;
        y *= rhs;
        return *this;
    }
    Vector2<T> operator *(const Vector2<T> &rhs) const {
        return Vector2<T>(
            x * rhs.x,
            y * rhs.y
        );
    }
    Vector2<T> &operator *=(const Vector2<T> &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        return *this;
    }
    Vector2<T> operator /(T rhs) const {
        return Vector2<T>(
            x / rhs,
            y / rhs
        );
    }
    Vector2<T> &operator /=(T rhs) {
        x /= rhs;
        y /= rhs;
        return *this;
    }
    Vector2<T> operator /(const Vector2<T> &rhs) const {
        return Vector2<T>(
            x / rhs.x,
            y / rhs.y
        );
    }
    Vector2<T> &operator /=(const Vector2<T> &rhs) {
        x /= rhs.x;
        y /= rhs.y;
        return *this;
    }

    Vector2<T> &operator =(const Vector2<T> &copy) {
        Vector2Core<T>::operator =(copy);
        return *this;
    }
    Vector2<T> &operator =(Vector2<T> &&move) {
        Vector2Core<T>::operator =(move);
        return *this;
    }

public:
    // rgba
    T &r;
    T &g;
    // stpq
    T &s;
    T &t;

#ifndef GLSLIKE_DISABLE_SWIZZLE
public:
    Swizzle2<T> xx;
    Swizzle2<T> xy;
    Swizzle2<T> yx;
    Swizzle2<T> yy;
    // alias rg
    Swizzle2<T> rr;
    Swizzle2<T> rg;
    Swizzle2<T> gr;
    Swizzle2<T> gg;
    // alias st
    Swizzle2<T> ss;
    Swizzle2<T> st;
    Swizzle2<T> ts;
    Swizzle2<T> tt;

public:
    Swizzle3<T> xxx;
    Swizzle3<T> xxy;
    Swizzle3<T> xyx;
    Swizzle3<T> xyy;
    Swizzle3<T> yxx;
    Swizzle3<T> yxy;
    Swizzle3<T> yyx;
    Swizzle3<T> yyy;
    // alias rg
    Swizzle3<T> rrr;
    Swizzle3<T> rrg;
    Swizzle3<T> rgr;
    Swizzle3<T> rgg;
    Swizzle3<T> grr;
    Swizzle3<T> grg;
    Swizzle3<T> ggr;
    Swizzle3<T> ggg;
    // alias st
    Swizzle3<T> sss;
    Swizzle3<T> sst;
    Swizzle3<T> sts;
    Swizzle3<T> stt;
    Swizzle3<T> tss;
    Swizzle3<T> tst;
    Swizzle3<T> tts;
    Swizzle3<T> ttt;

public:
    Swizzle4<T> xxxx;
    Swizzle4<T> xxxy;
    Swizzle4<T> xxyx;
    Swizzle4<T> xxyy;
    Swizzle4<T> xyxx;
    Swizzle4<T> xyxy;
    Swizzle4<T> xyyx;
    Swizzle4<T> xyyy;
    Swizzle4<T> yxxx;
    Swizzle4<T> yxxy;
    Swizzle4<T> yxyx;
    Swizzle4<T> yxyy;
    Swizzle4<T> yyxx;
    Swizzle4<T> yyxy;
    Swizzle4<T> yyyx;
    Swizzle4<T> yyyy;
    // alias rg
    Swizzle4<T> rrrr;
    Swizzle4<T> rrrg;
    Swizzle4<T> rrgr;
    Swizzle4<T> rrgg;
    Swizzle4<T> rgrr;
    Swizzle4<T> rgrg;
    Swizzle4<T> rggr;
    Swizzle4<T> rggg;
    Swizzle4<T> grrr;
    Swizzle4<T> grrg;
    Swizzle4<T> grgr;
    Swizzle4<T> grgg;
    Swizzle4<T> ggrr;
    Swizzle4<T> ggrg;
    Swizzle4<T> gggr;
    Swizzle4<T> gggg;
    // alias st
    Swizzle4<T> ssss;
    Swizzle4<T> ssst;
    Swizzle4<T> ssts;
    Swizzle4<T> sstt;
    Swizzle4<T> stss;
    Swizzle4<T> stst;
    Swizzle4<T> stts;
    Swizzle4<T> sttt;
    Swizzle4<T> tsss;
    Swizzle4<T> tsst;
    Swizzle4<T> tsts;
    Swizzle4<T> tstt;
    Swizzle4<T> ttss;
    Swizzle4<T> ttst;
    Swizzle4<T> ttts;
    Swizzle4<T> tttt;
#endif  // GLSLIKE_DISABLE_SWIZZLE

};

//
// 8.1 Angle and Trigonometry Functions
// These all operate component-wise.
//

template <typename T>
Vector2<T> radians(const Vector2<T> &degrees) {
    return Vector2<T>(
        math<T>::radians(degrees.x),
        math<T>::radians(degrees.y)
    );
}

template <typename T>
Vector2<T> degrees(const Vector2<T> &radians) {
    return Vector2<T>(
        math<T>::degrees(radians.x),
        math<T>::degrees(radians.y)
    );
}

template <typename T>
Vector2<T> sin(const Vector2<T> &angle) {
    return Vector2<T>(
        math<T>::sin(angle.x),
        math<T>::sin(angle.y)
    );
}

template <typename T>
Vector2<T> cos(const Vector2<T> &angle) {
    return Vector2<T>(
        math<T>::cos(angle.x),
        math<T>::cos(angle.y)
    );
}

template <typename T>
Vector2<T> tan(const Vector2<T> & angle) {
    return Vector2<T>(
        math<T>::tan(angle.x),
        math<T>::tan(angle.y)
    );
}

template <typename T>
Vector2<T> asin(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::asin(x.x),
        math<T>::asin(x.y)
    );
}

template <typename T>
Vector2<T> acos(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::acos(x.x),
        math<T>::acos(x.y)
    );
}

template <typename T>
Vector2<T> atan(const Vector2<T> &y, const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::atan(y.x, x.x),
        math<T>::atan(y.y, x.y)
    );
}

template <typename T>
Vector2<T> atan(const Vector2<T> &y_over_x) {
    return Vector2<T>(
        math<T>::atan(y_over_x.x),
        math<T>::atan(y_over_x.y)
    );
}

template <typename T>
Vector2<T> sinh(const Vector2<T> &angle) {
    return Vector2<T>(
        math<T>::sinh(angle.x),
        math<T>::sinh(angle.y)
    );
}

template <typename T>
Vector2<T> cosh(const Vector2<T> &angle) {
    return Vector2<T>(
        math<T>::cosh(angle.x),
        math<T>::cosh(angle.y)
    );
}

template <typename T>
Vector2<T> tanh(const Vector2<T> &angle) {
    return Vector2<T>(
        math<T>::tanh(angle.x),
        math<T>::tanh(angle.y)
    );
}

template <typename T>
Vector2<T> asinh(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::asinh(x.x),
        math<T>::asinh(x.y)
    );
}

template <typename T>
Vector2<T> acosh(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::acosh(x.x),
        math<T>::acosh(x.y)
    );
}

template <typename T>
Vector2<T> atanh(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::atanh(x.x),
        math<T>::atanh(x.y)
    );
}

//
// 8.2 Exponential Functions
// These all operate component-wise.
//

template <typename T>
Vector2<T> pow(const Vector2<T> &vec, T n) {
    return Vector2<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n)
    );
}

template <typename T>
Vector2<T> exp(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::exp(vec.x),
        math<T>::exp(vec.y)
    );
}

template <typename T>
Vector2<T> log(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::log(vec.x),
        math<T>::log(vec.y)
    );
}

template <typename T>
Vector2<T> exp2(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::exp2(vec.x),
        math<T>::exp2(vec.y)
    );
}

template <typename T>
Vector2<T> log2(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::log2(vec.x),
        math<T>::log2(vec.y)
    );
}

template <typename T>
Vector2<T> sqrt(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::sqrt(vec.x),
        math<T>::sqrt(vec.y)
    );
}

template <typename T>
Vector2<T> inversesqrt(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::inversesqrt(vec.x),
        math<T>::inversesqrt(vec.y)
    );
}

//
// 8.3 Common Functions
//

template <typename T>
Vector2<T> abs(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::abs(x.x),
        math<T>::abs(x.y)
    );
}

template <typename T>
Vector2<T> sign(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::sign(x.x),
        math<T>::sign(x.y)
    );
}

template <typename T>
Vector2<T> floor(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::floor(x.x),
        math<T>::floor(x.y)
    );
}

template <typename T>
Vector2<T> trunc(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::trunc(x.x),
        math<T>::trunc(x.y)
    );
}

template <typename T>
Vector2<T> round(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::round(x.x),
        math<T>::round(x.y)
    );
}

template <typename T>
Vector2<T> roundEven(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::roundEven(x.x),
        math<T>::roundEven(x.y)
    );
}

template <typename T>
Vector2<T> ceil(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::ceil(x.x),
        math<T>::ceil(x.y)
    );
}

template <typename T>
Vector2<T> fract(const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::fract(x.x),
        math<T>::fract(x.y)
    );
}

template <typename T>
Vector2<T> mod(const Vector2<T> &x, const Vector2<T> &y) {
    return Vector2<T>(
        math<T>::mod(x.x, y.x),
        math<T>::mod(x.y, y.y)
    );
}

template <typename T>
Vector2<T> mod(const Vector2<T> &x, T y) {
    return Vector2<T>(
        math<T>::mod(x.x, y),
        math<T>::mod(x.y, y)
    );
}

template <typename T>
Vector2<T> modf(const Vector2<T> &x, Vector2<T> *i) {
    return Vector2<T>(
        math<T>::modf(x.x, &i->x),
        math<T>::modf(x.y, &i->y)
    );
}

template <typename T>
Vector2<T> min(const Vector2<T> &a, const Vector2<T> &b) {
    return Vector2<T>(
        math<T>::min(a.x, b.x),
        math<T>::min(a.y, b.y)
    );
}

template <typename T>
Vector2<T> min(const Vector2<T> &a, T b) {
    return Vector2<T>(
        math<T>::min(a.x, b),
        math<T>::min(a.y, b)
    );
}

template <typename T>
Vector2<T> max(const Vector2<T> &a, const Vector2<T> &b) {
    return Vector2<T>(
        math<T>::max(a.x, b.x),
        math<T>::max(a.y, b.y)
    );
}

template <typename T>
Vector2<T> max(const Vector2<T> &a, T b) {
    return Vector2<T>(
        math<T>::max(a.x, b),
        math<T>::max(a.y, b)
    );
}

template <typename T>
Vector2<T> clamp(const Vector2<T> &value, const Vector2<T> &min, const Vector2<T> &max) {
    return Vector2<T>(
        math<T>::clamp(value.x, min.x, max.x),
        math<T>::clamp(value.y, min.y, max.y)
    );
}

template <typename T>
Vector2<T> clamp(const Vector2<T> &value, T min, T max) {
    return Vector2<T>(
        math<T>::clamp(value.x, min, max),
        math<T>::clamp(value.y, min, max)
    );
}

template <typename T>
Vector2<T> mix(const Vector2<T> &x, const Vector2<T> &y, const Vector2<T> &a) {
    return Vector2<T>(
        math<T>::mix(x.x, y.x, a.x),
        math<T>::mix(x.y, y.y, a.y)
    );
}

template <typename T>
Vector2<T> mix(const Vector2<T> &x, const Vector2<T> &y, T a) {
    return Vector2<T>(
        math<T>::mix(x.x, y.x, a),
        math<T>::mix(x.y, y.y, a)
    );
}

template <typename T>
Vector2<T> step(const Vector2<T> &edge, const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::step(edge.x, x.x),
        math<T>::step(edge.y, x.y)
    );
}

template <typename T>
Vector2<T> step(T edge, const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::step(edge, x.x),
        math<T>::step(edge, x.y)
    );
}

template <typename T>
Vector2<T> smoothstep(const Vector2<T> &edge0, const Vector2<T> &edge1, const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::smoothstep(edge0.x, edge1.x, x.x),
        math<T>::smoothstep(edge0.y, edge1.y, x.y)
    );
}

template <typename T>
Vector2<T> smoothstep(T edge0, T edge1, const Vector2<T> &x) {
    return Vector2<T>(
        math<T>::smoothstep(edge0, edge1, x.x),
        math<T>::smoothstep(edge0, edge1, x.y)
    );
}

template <typename T>
Vector2<Bool_t> isnan(const Vector2<T> &x) {
    return Vector2<Bool_t>(
        math<T>::isnan(x.x),
        math<T>::isnan(x.y)
    );
}

template <typename T>
Vector2<Bool_t> isinf(const Vector2<T> &x) {
    return Vector2<Bool_t>(
        math<T>::isinf(x.x),
        math<T>::isinf(x.y)
    );
}

//
// TODO:
// * floatBitToInt
// * floatBitToUint
// * intBitsToFloat
// * fma
// * frexp
// * ldexp
//

// 8.4 Floating-Point Pack and Unpack Functions
//
// * packUnorm2x16
// * packSnorm2x16
// * packUnorm4x8
// * packSnorm4x8
// * unpackUnorm2x16
// * unpackSnorm2x16
// * unpackUnorm4x8
// * unpackSnorm4x8
// * packDouble2x32
// * unpackDouble2x32
// * packHalf2x16
// * unpackHalf2x16
//
// 8.6 Matrix Functions
//
// * matrixCompMult
// * outerProduct
// * transpose
// * determinant
// * inverse
//
// 8.7 Vector Relational Functions
//
// * lessThan
// * lessThanEqual
// * greaterThan
// * greaterThanEqual
// * equal
// * notEqual
// * any
// * all
// * not
//
// 8.8 Integer Functions
//
// * uaddCarry
// * usubBorrow
// * umulExtended
// * imulExtended
// * bitfieldExtract
// * bitfieldInsert
// * bitfieldReverse
// * bitCount
// * findLSB
// * findMSB


template <typename T>
Vector2<T> operator +(T a, const Vector2<T> &b) {
    return Vector2<T>(
        a + b.x,
        a + b.y
    );
}

template <typename T>
Vector2<T> operator -(T a, const Vector2<T> &b) {
    return Vector2<T>(
        a - b.x,
        a - b.y
    );
}

template <typename T>
Vector2<T> operator *(T a, const Vector2<T> &b) {
    return Vector2<T>(
        a * b.x,
        a * b.y
    );
}

template <typename T>
Vector2<T> operator /(T a, const Vector2<T> &b) {
    return Vector2<T>(
        a / b.x,
        a / b.y
    );
}

#ifndef GLSLIKE_DISABLE_SWIZZLE

template <typename T>
Vector2<T> operator +(const Swizzle2<T> &a, const Vector2<T> &b) {
    return Vector2<T>(
        a.x + b.x,
        a.y + b.y
    );
}

template <typename T>
Vector2<T> operator -(const Swizzle2<T> &a, const Vector2<T> &b) {
    return Vector2<T>(
        a.x - b.x,
        a.y - b.y
    );
}

template <typename T>
Vector2<T> operator *(const Swizzle2<T> &a, const Vector2<T> &b) {
    return Vector2<T>(
        a.x * b.x,
        a.y * b.y
    );
}

template <typename T>
Vector2<T> operator /(const Swizzle2<T> &a, const Vector2<T> &b) {
    return Vector2<T>(
        a.x / b.x,
        a.y / b.y
    );
}

template <typename T>
Vector2<T> operator +(const Vector2<T> & a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x + b.x,
        a.y + b.y
    );
}

template <typename T>
Vector2<T> operator -(const Vector2<T> & a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x - b.x,
        a.y - b.y
    );
}

template <typename T>
Vector2<T> operator *(const Vector2<T> & a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x * b.x,
        a.y * b.y
    );
}

template <typename T>
Vector2<T> operator /(const Vector2<T> & a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x / b.x,
        a.y / b.y
    );
}

template <typename T>
Vector2<T> operator +(const Swizzle2<T> &a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x + b.x,
        a.y + b.y
    );
}

template <typename T>
Vector2<T> operator -(const Swizzle2<T> &a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x - b.x,
        a.y - b.y
    );
}

template <typename T>
Vector2<T> operator *(const Swizzle2<T> &a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x * b.x,
        a.y * b.y
    );
}

template <typename T>
Vector2<T> operator /(const Swizzle2<T> &a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a.x / b.x,
        a.y / b.y
    );
}

template <typename T>
Vector2<T> operator +(const Swizzle2<T> &a, T b) {
    return Vector2<T>(
        a.x + b,
        a.y + b
    );
}

template <typename T>
Vector2<T> operator -(const Swizzle2<T> &a, T b) {
    return Vector2<T>(
        a.x - b,
        a.y - b
    );
}

template <typename T>
Vector2<T> operator *(const Swizzle2<T> &a, T b) {
    return Vector2<T>(
        a.x * b,
        a.y * b
    );
}

template <typename T>
Vector2<T> operator /(const Swizzle2<T> &a, T b) {
    return Vector2<T>(
        a.x / b,
        a.y / b
    );
}

template <typename T>
Vector2<T> operator +(T a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a + b.x,
        a + b.y
    );
}

template <typename T>
Vector2<T> operator -(T a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a - b.x,
        a - b.y
    );
}

template <typename T>
Vector2<T> operator *(T a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a * b.x,
        a * b.y
    );
}

template <typename T>
Vector2<T> operator /(T a, const Swizzle2<T> &b) {
    return Vector2<T>(
        a / b.x,
        a / b.y
    );
}

#endif  // GLSLIKE_DISABLE_SWIZZLE

#ifdef GLSLIKE_DISABLE_SWIZZLE
#define GLSLIKE_VECTOR3_SWIZZLE() \
    r(this->x) \
    , g(this->y) \
    , b(this->z) \
    , s(this->x) \
    , t(this->y) \
    , p(this->z)
#else
#define GLSLIKE_VECTOR3_SWIZZLE() \
    r(this->x) \
    , g(this->y) \
    , b(this->z) \
    , s(this->x) \
    , t(this->y) \
    , p(this->z) \
    , xx(this->x, this->x) \
    , xy(this->x, this->y) \
    , xz(this->x, this->z) \
    , yx(this->y, this->x) \
    , yy(this->y, this->y) \
    , yz(this->y, this->z) \
    , zx(this->z, this->x) \
    , zy(this->z, this->y) \
    , zz(this->z, this->z) \
    , rr(this->x, this->x) \
    , rg(this->x, this->y) \
    , rb(this->x, this->z) \
    , gr(this->y, this->x) \
    , gg(this->y, this->y) \
    , gb(this->y, this->z) \
    , br(this->z, this->x) \
    , bg(this->z, this->y) \
    , bb(this->z, this->z) \
    , ss(this->x, this->x) \
    , st(this->x, this->y) \
    , sp(this->x, this->z) \
    , ts(this->y, this->x) \
    , tt(this->y, this->y) \
    , tp(this->y, this->z) \
    , ps(this->z, this->x) \
    , pt(this->z, this->y) \
    , pp(this->z, this->z) \
    , xxx(this->x, this->x, this->x) \
    , xxy(this->x, this->x, this->y) \
    , xxz(this->x, this->x, this->z) \
    , xyx(this->x, this->y, this->x) \
    , xyy(this->x, this->y, this->y) \
    , xyz(this->x, this->y, this->z) \
    , xzx(this->x, this->z, this->x) \
    , xzy(this->x, this->z, this->y) \
    , xzz(this->x, this->z, this->z) \
    , yxx(this->y, this->x, this->x) \
    , yxy(this->y, this->x, this->y) \
    , yxz(this->y, this->x, this->z) \
    , yyx(this->y, this->y, this->x) \
    , yyy(this->y, this->y, this->y) \
    , yyz(this->y, this->y, this->z) \
    , yzx(this->y, this->z, this->x) \
    , yzy(this->y, this->z, this->y) \
    , yzz(this->y, this->z, this->z) \
    , zxx(this->z, this->x, this->x) \
    , zxy(this->z, this->x, this->y) \
    , zxz(this->z, this->x, this->z) \
    , zyx(this->z, this->y, this->x) \
    , zyy(this->z, this->y, this->y) \
    , zyz(this->z, this->y, this->z) \
    , zzx(this->z, this->z, this->x) \
    , zzy(this->z, this->z, this->y) \
    , zzz(this->z, this->z, this->z) \
    , rrr(this->x, this->x, this->x) \
    , rrg(this->x, this->x, this->y) \
    , rrb(this->x, this->x, this->z) \
    , rgr(this->x, this->y, this->x) \
    , rgg(this->x, this->y, this->y) \
    , rgb(this->x, this->y, this->z) \
    , rbr(this->x, this->z, this->x) \
    , rbg(this->x, this->z, this->y) \
    , rbb(this->x, this->z, this->z) \
    , grr(this->y, this->x, this->x) \
    , grg(this->y, this->x, this->y) \
    , grb(this->y, this->x, this->z) \
    , ggr(this->y, this->y, this->x) \
    , ggg(this->y, this->y, this->y) \
    , ggb(this->y, this->y, this->z) \
    , gbr(this->y, this->z, this->x) \
    , gbg(this->y, this->z, this->y) \
    , gbb(this->y, this->z, this->z) \
    , brr(this->z, this->x, this->x) \
    , brg(this->z, this->x, this->y) \
    , brb(this->z, this->x, this->z) \
    , bgr(this->z, this->y, this->x) \
    , bgg(this->z, this->y, this->y) \
    , bgb(this->z, this->y, this->z) \
    , bbr(this->z, this->z, this->x) \
    , bbg(this->z, this->z, this->y) \
    , bbb(this->z, this->z, this->z) \
    , sss(this->x, this->x, this->x) \
    , sst(this->x, this->x, this->y) \
    , ssp(this->x, this->x, this->z) \
    , sts(this->x, this->y, this->x) \
    , stt(this->x, this->y, this->y) \
    , stp(this->x, this->y, this->z) \
    , sps(this->x, this->z, this->x) \
    , spt(this->x, this->z, this->y) \
    , spp(this->x, this->z, this->z) \
    , tss(this->y, this->x, this->x) \
    , tst(this->y, this->x, this->y) \
    , tsp(this->y, this->x, this->z) \
    , tts(this->y, this->y, this->x) \
    , ttt(this->y, this->y, this->y) \
    , ttp(this->y, this->y, this->z) \
    , tps(this->y, this->z, this->x) \
    , tpt(this->y, this->z, this->y) \
    , tpp(this->y, this->z, this->z) \
    , pss(this->z, this->x, this->x) \
    , pst(this->z, this->x, this->y) \
    , psp(this->z, this->x, this->z) \
    , pts(this->z, this->y, this->x) \
    , ptt(this->z, this->y, this->y) \
    , ptp(this->z, this->y, this->z) \
    , pps(this->z, this->z, this->x) \
    , ppt(this->z, this->z, this->y) \
    , ppp(this->z, this->z, this->z) \
    , xxxx(this->x, this->x, this->x, this->x) \
    , xxxy(this->x, this->x, this->x, this->y) \
    , xxxz(this->x, this->x, this->x, this->z) \
    , xxyx(this->x, this->x, this->y, this->x) \
    , xxyy(this->x, this->x, this->y, this->y) \
    , xxyz(this->x, this->x, this->y, this->z) \
    , xxzx(this->x, this->x, this->z, this->x) \
    , xxzy(this->x, this->x, this->z, this->y) \
    , xxzz(this->x, this->x, this->z, this->z) \
    , xyxx(this->x, this->y, this->x, this->x) \
    , xyxy(this->x, this->y, this->x, this->y) \
    , xyxz(this->x, this->y, this->x, this->z) \
    , xyyx(this->x, this->y, this->y, this->x) \
    , xyyy(this->x, this->y, this->y, this->y) \
    , xyyz(this->x, this->y, this->y, this->z) \
    , xyzx(this->x, this->y, this->z, this->x) \
    , xyzy(this->x, this->y, this->z, this->y) \
    , xyzz(this->x, this->y, this->z, this->z) \
    , xzxx(this->x, this->z, this->x, this->x) \
    , xzxy(this->x, this->z, this->x, this->y) \
    , xzxz(this->x, this->z, this->x, this->z) \
    , xzyx(this->x, this->z, this->y, this->x) \
    , xzyy(this->x, this->z, this->y, this->y) \
    , xzyz(this->x, this->z, this->y, this->z) \
    , xzzx(this->x, this->z, this->z, this->x) \
    , xzzy(this->x, this->z, this->z, this->y) \
    , xzzz(this->x, this->z, this->z, this->z) \
    , yxxx(this->y, this->x, this->x, this->x) \
    , yxxy(this->y, this->x, this->x, this->y) \
    , yxxz(this->y, this->x, this->x, this->z) \
    , yxyx(this->y, this->x, this->y, this->x) \
    , yxyy(this->y, this->x, this->y, this->y) \
    , yxyz(this->y, this->x, this->y, this->z) \
    , yxzx(this->y, this->x, this->z, this->x) \
    , yxzy(this->y, this->x, this->z, this->y) \
    , yxzz(this->y, this->x, this->z, this->z) \
    , yyxx(this->y, this->y, this->x, this->x) \
    , yyxy(this->y, this->y, this->x, this->y) \
    , yyxz(this->y, this->y, this->x, this->z) \
    , yyyx(this->y, this->y, this->y, this->x) \
    , yyyy(this->y, this->y, this->y, this->y) \
    , yyyz(this->y, this->y, this->y, this->z) \
    , yyzx(this->y, this->y, this->z, this->x) \
    , yyzy(this->y, this->y, this->z, this->y) \
    , yyzz(this->y, this->y, this->z, this->z) \
    , yzxx(this->y, this->z, this->x, this->x) \
    , yzxy(this->y, this->z, this->x, this->y) \
    , yzxz(this->y, this->z, this->x, this->z) \
    , yzyx(this->y, this->z, this->y, this->x) \
    , yzyy(this->y, this->z, this->y, this->y) \
    , yzyz(this->y, this->z, this->y, this->z) \
    , yzzx(this->y, this->z, this->z, this->x) \
    , yzzy(this->y, this->z, this->z, this->y) \
    , yzzz(this->y, this->z, this->z, this->z) \
    , zxxx(this->z, this->x, this->x, this->x) \
    , zxxy(this->z, this->x, this->x, this->y) \
    , zxxz(this->z, this->x, this->x, this->z) \
    , zxyx(this->z, this->x, this->y, this->x) \
    , zxyy(this->z, this->x, this->y, this->y) \
    , zxyz(this->z, this->x, this->y, this->z) \
    , zxzx(this->z, this->x, this->z, this->x) \
    , zxzy(this->z, this->x, this->z, this->y) \
    , zxzz(this->z, this->x, this->z, this->z) \
    , zyxx(this->z, this->y, this->x, this->x) \
    , zyxy(this->z, this->y, this->x, this->y) \
    , zyxz(this->z, this->y, this->x, this->z) \
    , zyyx(this->z, this->y, this->y, this->x) \
    , zyyy(this->z, this->y, this->y, this->y) \
    , zyyz(this->z, this->y, this->y, this->z) \
    , zyzx(this->z, this->y, this->z, this->x) \
    , zyzy(this->z, this->y, this->z, this->y) \
    , zyzz(this->z, this->y, this->z, this->z) \
    , zzxx(this->z, this->z, this->x, this->x) \
    , zzxy(this->z, this->z, this->x, this->y) \
    , zzxz(this->z, this->z, this->x, this->z) \
    , zzyx(this->z, this->z, this->y, this->x) \
    , zzyy(this->z, this->z, this->y, this->y) \
    , zzyz(this->z, this->z, this->y, this->z) \
    , zzzx(this->z, this->z, this->z, this->x) \
    , zzzy(this->z, this->z, this->z, this->y) \
    , zzzz(this->z, this->z, this->z, this->z) \
    , rrrr(this->x, this->x, this->x, this->x) \
    , rrrg(this->x, this->x, this->x, this->y) \
    , rrrb(this->x, this->x, this->x, this->z) \
    , rrgr(this->x, this->x, this->y, this->x) \
    , rrgg(this->x, this->x, this->y, this->y) \
    , rrgb(this->x, this->x, this->y, this->z) \
    , rrbr(this->x, this->x, this->z, this->x) \
    , rrbg(this->x, this->x, this->z, this->y) \
    , rrbb(this->x, this->x, this->z, this->z) \
    , rgrr(this->x, this->y, this->x, this->x) \
    , rgrg(this->x, this->y, this->x, this->y) \
    , rgrb(this->x, this->y, this->x, this->z) \
    , rggr(this->x, this->y, this->y, this->x) \
    , rggg(this->x, this->y, this->y, this->y) \
    , rggb(this->x, this->y, this->y, this->z) \
    , rgbr(this->x, this->y, this->z, this->x) \
    , rgbg(this->x, this->y, this->z, this->y) \
    , rgbb(this->x, this->y, this->z, this->z) \
    , rbrr(this->x, this->z, this->x, this->x) \
    , rbrg(this->x, this->z, this->x, this->y) \
    , rbrb(this->x, this->z, this->x, this->z) \
    , rbgr(this->x, this->z, this->y, this->x) \
    , rbgg(this->x, this->z, this->y, this->y) \
    , rbgb(this->x, this->z, this->y, this->z) \
    , rbbr(this->x, this->z, this->z, this->x) \
    , rbbg(this->x, this->z, this->z, this->y) \
    , rbbb(this->x, this->z, this->z, this->z) \
    , grrr(this->y, this->x, this->x, this->x) \
    , grrg(this->y, this->x, this->x, this->y) \
    , grrb(this->y, this->x, this->x, this->z) \
    , grgr(this->y, this->x, this->y, this->x) \
    , grgg(this->y, this->x, this->y, this->y) \
    , grgb(this->y, this->x, this->y, this->z) \
    , grbr(this->y, this->x, this->z, this->x) \
    , grbg(this->y, this->x, this->z, this->y) \
    , grbb(this->y, this->x, this->z, this->z) \
    , ggrr(this->y, this->y, this->x, this->x) \
    , ggrg(this->y, this->y, this->x, this->y) \
    , ggrb(this->y, this->y, this->x, this->z) \
    , gggr(this->y, this->y, this->y, this->x) \
    , gggg(this->y, this->y, this->y, this->y) \
    , gggb(this->y, this->y, this->y, this->z) \
    , ggbr(this->y, this->y, this->z, this->x) \
    , ggbg(this->y, this->y, this->z, this->y) \
    , ggbb(this->y, this->y, this->z, this->z) \
    , gbrr(this->y, this->z, this->x, this->x) \
    , gbrg(this->y, this->z, this->x, this->y) \
    , gbrb(this->y, this->z, this->x, this->z) \
    , gbgr(this->y, this->z, this->y, this->x) \
    , gbgg(this->y, this->z, this->y, this->y) \
    , gbgb(this->y, this->z, this->y, this->z) \
    , gbbr(this->y, this->z, this->z, this->x) \
    , gbbg(this->y, this->z, this->z, this->y) \
    , gbbb(this->y, this->z, this->z, this->z) \
    , brrr(this->z, this->x, this->x, this->x) \
    , brrg(this->z, this->x, this->x, this->y) \
    , brrb(this->z, this->x, this->x, this->z) \
    , brgr(this->z, this->x, this->y, this->x) \
    , brgg(this->z, this->x, this->y, this->y) \
    , brgb(this->z, this->x, this->y, this->z) \
    , brbr(this->z, this->x, this->z, this->x) \
    , brbg(this->z, this->x, this->z, this->y) \
    , brbb(this->z, this->x, this->z, this->z) \
    , bgrr(this->z, this->y, this->x, this->x) \
    , bgrg(this->z, this->y, this->x, this->y) \
    , bgrb(this->z, this->y, this->x, this->z) \
    , bggr(this->z, this->y, this->y, this->x) \
    , bggg(this->z, this->y, this->y, this->y) \
    , bggb(this->z, this->y, this->y, this->z) \
    , bgbr(this->z, this->y, this->z, this->x) \
    , bgbg(this->z, this->y, this->z, this->y) \
    , bgbb(this->z, this->y, this->z, this->z) \
    , bbrr(this->z, this->z, this->x, this->x) \
    , bbrg(this->z, this->z, this->x, this->y) \
    , bbrb(this->z, this->z, this->x, this->z) \
    , bbgr(this->z, this->z, this->y, this->x) \
    , bbgg(this->z, this->z, this->y, this->y) \
    , bbgb(this->z, this->z, this->y, this->z) \
    , bbbr(this->z, this->z, this->z, this->x) \
    , bbbg(this->z, this->z, this->z, this->y) \
    , bbbb(this->z, this->z, this->z, this->z) \
    , ssss(this->x, this->x, this->x, this->x) \
    , ssst(this->x, this->x, this->x, this->y) \
    , sssp(this->x, this->x, this->x, this->z) \
    , ssts(this->x, this->x, this->y, this->x) \
    , sstt(this->x, this->x, this->y, this->y) \
    , sstp(this->x, this->x, this->y, this->z) \
    , ssps(this->x, this->x, this->z, this->x) \
    , sspt(this->x, this->x, this->z, this->y) \
    , sspp(this->x, this->x, this->z, this->z) \
    , stss(this->x, this->y, this->x, this->x) \
    , stst(this->x, this->y, this->x, this->y) \
    , stsp(this->x, this->y, this->x, this->z) \
    , stts(this->x, this->y, this->y, this->x) \
    , sttt(this->x, this->y, this->y, this->y) \
    , sttp(this->x, this->y, this->y, this->z) \
    , stps(this->x, this->y, this->z, this->x) \
    , stpt(this->x, this->y, this->z, this->y) \
    , stpp(this->x, this->y, this->z, this->z) \
    , spss(this->x, this->z, this->x, this->x) \
    , spst(this->x, this->z, this->x, this->y) \
    , spsp(this->x, this->z, this->x, this->z) \
    , spts(this->x, this->z, this->y, this->x) \
    , sptt(this->x, this->z, this->y, this->y) \
    , sptp(this->x, this->z, this->y, this->z) \
    , spps(this->x, this->z, this->z, this->x) \
    , sppt(this->x, this->z, this->z, this->y) \
    , sppp(this->x, this->z, this->z, this->z) \
    , tsss(this->y, this->x, this->x, this->x) \
    , tsst(this->y, this->x, this->x, this->y) \
    , tssp(this->y, this->x, this->x, this->z) \
    , tsts(this->y, this->x, this->y, this->x) \
    , tstt(this->y, this->x, this->y, this->y) \
    , tstp(this->y, this->x, this->y, this->z) \
    , tsps(this->y, this->x, this->z, this->x) \
    , tspt(this->y, this->x, this->z, this->y) \
    , tspp(this->y, this->x, this->z, this->z) \
    , ttss(this->y, this->y, this->x, this->x) \
    , ttst(this->y, this->y, this->x, this->y) \
    , ttsp(this->y, this->y, this->x, this->z) \
    , ttts(this->y, this->y, this->y, this->x) \
    , tttt(this->y, this->y, this->y, this->y) \
    , tttp(this->y, this->y, this->y, this->z) \
    , ttps(this->y, this->y, this->z, this->x) \
    , ttpt(this->y, this->y, this->z, this->y) \
    , ttpp(this->y, this->y, this->z, this->z) \
    , tpss(this->y, this->z, this->x, this->x) \
    , tpst(this->y, this->z, this->x, this->y) \
    , tpsp(this->y, this->z, this->x, this->z) \
    , tpts(this->y, this->z, this->y, this->x) \
    , tptt(this->y, this->z, this->y, this->y) \
    , tptp(this->y, this->z, this->y, this->z) \
    , tpps(this->y, this->z, this->z, this->x) \
    , tppt(this->y, this->z, this->z, this->y) \
    , tppp(this->y, this->z, this->z, this->z) \
    , psss(this->z, this->x, this->x, this->x) \
    , psst(this->z, this->x, this->x, this->y) \
    , pssp(this->z, this->x, this->x, this->z) \
    , psts(this->z, this->x, this->y, this->x) \
    , pstt(this->z, this->x, this->y, this->y) \
    , pstp(this->z, this->x, this->y, this->z) \
    , psps(this->z, this->x, this->z, this->x) \
    , pspt(this->z, this->x, this->z, this->y) \
    , pspp(this->z, this->x, this->z, this->z) \
    , ptss(this->z, this->y, this->x, this->x) \
    , ptst(this->z, this->y, this->x, this->y) \
    , ptsp(this->z, this->y, this->x, this->z) \
    , ptts(this->z, this->y, this->y, this->x) \
    , pttt(this->z, this->y, this->y, this->y) \
    , pttp(this->z, this->y, this->y, this->z) \
    , ptps(this->z, this->y, this->z, this->x) \
    , ptpt(this->z, this->y, this->z, this->y) \
    , ptpp(this->z, this->y, this->z, this->z) \
    , ppss(this->z, this->z, this->x, this->x) \
    , ppst(this->z, this->z, this->x, this->y) \
    , ppsp(this->z, this->z, this->x, this->z) \
    , ppts(this->z, this->z, this->y, this->x) \
    , pptt(this->z, this->z, this->y, this->y) \
    , pptp(this->z, this->z, this->y, this->z) \
    , ppps(this->z, this->z, this->z, this->x) \
    , pppt(this->z, this->z, this->z, this->y) \
    , pppp(this->z, this->z, this->z, this->z)
#endif  // GLSLIKE_DISABLE_SWIZZLE


template <typename T>
class Vector3 : public Vector3Core<T> {
public:
    typedef Vector3Core<T> Base_t;
    typedef T Type_t;
    using Vector3Core<T>::Vector3Core;
    using Vector3Core<T>::x;
    using Vector3Core<T>::y;
    using Vector3Core<T>::z;

public:
    explicit Vector3(T x)
        : Vector3Core<T>::Vector3Core(x)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}
    Vector3(T x, T y, T z)
        : Vector3Core<T>::Vector3Core(x, y, z)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}
    Vector3(const Vector2<T> &xy, T z)
        : Vector3Core<T>::Vector3Core(xy.x, xy.y, z)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}
    Vector3(T x, const Vector2<T> &yz)
        : Vector3Core<T>::Vector3Core(x, yz.x, yz.y)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

    Vector3(const Vector3<T> &copy)
        : Vector3Core<T>::Vector3Core(copy)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

    Vector3(Vector3<T> &&move)
        : Vector3Core<T>::Vector3Core(move)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

#ifndef GLSLIKE_DISABLE_SWIZZLE
    template <typename SwizzleT, typename std::enable_if<std::is_convertible<SwizzleT, Vector3Core<T>>::value>::type * = nullptr>
    Vector3(const SwizzleT &core)
        : Vector3Core<T>::Vector3Core(static_cast<Vector3Core<T>>(core))
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}
#endif  // GLSLIKE_DISABLE_SWIZZLE

    T operator [](int i) const {
        switch (i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        default:
            throw std::out_of_range("index out of range");
        }
    }

    Vector3<T> clone() const {
        return Vector3<T>(x, y, z);
    }

    Vector3<T> &copy(const Vector3<T> &vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        return *this;
    }

    Vector3<T> &set(T fXVal, T fYVal, T fZVal) {
        x = fXVal;
        y = fYVal;
        z = fZVal;
        return *this;
    }

    Vector3<T> &add(const Vector3<T> &vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        return *this;
    }

    Vector3<T> &addScalar(T scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
        return *this;
    }

    Vector3<T> &multiplyScalar(T scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        return *this;
    }

    Vector3<T> &divideScalar(T scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        return *this;
    }

    // 8.5 Geometric Functions

    T length() const {
        return glslike::math<T>::sqrt(x * x + y * y + z * z);
    }

    T distance(const Vector3<T> &v) const {
        return (*this - v).length();
    }

    T dot(const Vector3<T> &vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    Vector3<T> cross(const Vector3<T> &vec) const {
        return Vector3<T>(
            y * vec.z - vec.y * z,
            z * vec.x - vec.z * x,
            x * vec.y - vec.x * y
        );
    }

    Vector3<T> normalize() {
        const auto len = length();
        //assert(len != 0.0f);
        return divideScalar(len);
    }

    std::array<T, 3> toArray() const {
        return {x, y, z};
    }

    //
    // glsl-like interface
    //

    Vector3<T> operator +() const {
        return Vector3<T>(
            +x,
            +y,
            +z
        );
    }

    Vector3<T> operator -() const {
        return Vector3<T>(
            -x,
            -y,
            -z
        );
    }

    Vector3<T> operator +(T rhs) const {
        return Vector3<T>(
            x + rhs,
            y + rhs,
            z + rhs
        );
    }
    Vector3<T> &operator +=(T rhs) {
        x += rhs;
        y += rhs;
        z += rhs;
        return *this;
    }
    Vector3<T> operator +(const Vector3<T> &rhs) const {
        return Vector3<T>(
            x + rhs.x,
            y + rhs.y,
            z + rhs.z
        );
    }
    Vector3<T> &operator +=(const Vector3<T> &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        return *this;
    }
    Vector3<T> operator -(T rhs) const {
        return Vector3<T>(
            x - rhs,
            y - rhs,
            z - rhs
        );
    }
    Vector3<T> &operator -=(T rhs) {
        x -= rhs;
        y -= rhs;
        z -= rhs;
        return *this;
    }
    Vector3<T> operator -(const Vector3<T> &rhs) const {
        return Vector3<T>(
            x - rhs.x,
            y - rhs.y,
            z - rhs.z
        );
    }
    Vector3<T> &operator -=(const Vector3<T> &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        return *this;
    }
    Vector3<T> operator *(T rhs) const {
        return Vector3<T>(
            x * rhs,
            y * rhs,
            z * rhs
        );
    }
    Vector3<T> &operator *=(T rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        return *this;
    }
    Vector3<T> operator *(const Vector3<T> &rhs) const {
        return Vector3<T>(
            x * rhs.x,
            y * rhs.y,
            z * rhs.z
        );
    }
    Vector3<T> &operator *=(const Vector3<T> &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        return *this;
    }
    Vector3<T> operator /(T rhs) const {
        return Vector3<T>(
            x / rhs,
            y / rhs,
            z / rhs
        );
    }
    Vector3<T> &operator /=(T rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        return *this;
    }
    Vector3<T> operator /(const Vector3<T> &rhs) const {
        return Vector3<T>(
            x / rhs.x,
            y / rhs.y,
            z / rhs.z
        );
    }
    Vector3<T> &operator /=(const Vector3<T> &rhs) {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        return *this;
    }

    Vector3<T> &operator =(const Vector3<T> &copy) {
        x = copy.x;
        y = copy.y;
        z = copy.z;
        return *this;
    }
    Vector3<T> &operator =(Vector3<T> &&move) {
        x = std::move(move.x);
        y = std::move(move.y);
        z = std::move(move.z);
        return *this;
    }

public:
    T &r;
    T &g;
    T &b;
    T &s;
    T &t;
    T &p;

#ifndef GLSLIKE_DISABLE_SWIZZLE
public:
    Swizzle2<T> xx;
    Swizzle2<T> xy;
    Swizzle2<T> xz;
    Swizzle2<T> yx;
    Swizzle2<T> yy;
    Swizzle2<T> yz;
    Swizzle2<T> zx;
    Swizzle2<T> zy;
    Swizzle2<T> zz;
    // alias rgb
    Swizzle2<T> rr;
    Swizzle2<T> rg;
    Swizzle2<T> rb;
    Swizzle2<T> gr;
    Swizzle2<T> gg;
    Swizzle2<T> gb;
    Swizzle2<T> br;
    Swizzle2<T> bg;
    Swizzle2<T> bb;
    // alias stp
    Swizzle2<T> ss;
    Swizzle2<T> st;
    Swizzle2<T> sp;
    Swizzle2<T> ts;
    Swizzle2<T> tt;
    Swizzle2<T> tp;
    Swizzle2<T> ps;
    Swizzle2<T> pt;
    Swizzle2<T> pp;

public:
    Swizzle3<T> xxx;
    Swizzle3<T> xxy;
    Swizzle3<T> xxz;
    Swizzle3<T> xyx;
    Swizzle3<T> xyy;
    Swizzle3<T> xyz;
    Swizzle3<T> xzx;
    Swizzle3<T> xzy;
    Swizzle3<T> xzz;
    Swizzle3<T> yxx;
    Swizzle3<T> yxy;
    Swizzle3<T> yxz;
    Swizzle3<T> yyx;
    Swizzle3<T> yyy;
    Swizzle3<T> yyz;
    Swizzle3<T> yzx;
    Swizzle3<T> yzy;
    Swizzle3<T> yzz;
    Swizzle3<T> zxx;
    Swizzle3<T> zxy;
    Swizzle3<T> zxz;
    Swizzle3<T> zyx;
    Swizzle3<T> zyy;
    Swizzle3<T> zyz;
    Swizzle3<T> zzx;
    Swizzle3<T> zzy;
    Swizzle3<T> zzz;
    // alias rgb
    Swizzle3<T> rrr;
    Swizzle3<T> rrg;
    Swizzle3<T> rrb;
    Swizzle3<T> rgr;
    Swizzle3<T> rgg;
    Swizzle3<T> rgb;
    Swizzle3<T> rbr;
    Swizzle3<T> rbg;
    Swizzle3<T> rbb;
    Swizzle3<T> grr;
    Swizzle3<T> grg;
    Swizzle3<T> grb;
    Swizzle3<T> ggr;
    Swizzle3<T> ggg;
    Swizzle3<T> ggb;
    Swizzle3<T> gbr;
    Swizzle3<T> gbg;
    Swizzle3<T> gbb;
    Swizzle3<T> brr;
    Swizzle3<T> brg;
    Swizzle3<T> brb;
    Swizzle3<T> bgr;
    Swizzle3<T> bgg;
    Swizzle3<T> bgb;
    Swizzle3<T> bbr;
    Swizzle3<T> bbg;
    Swizzle3<T> bbb;
    // alias stp
    Swizzle3<T> sss;
    Swizzle3<T> sst;
    Swizzle3<T> ssp;
    Swizzle3<T> sts;
    Swizzle3<T> stt;
    Swizzle3<T> stp;
    Swizzle3<T> sps;
    Swizzle3<T> spt;
    Swizzle3<T> spp;
    Swizzle3<T> tss;
    Swizzle3<T> tst;
    Swizzle3<T> tsp;
    Swizzle3<T> tts;
    Swizzle3<T> ttt;
    Swizzle3<T> ttp;
    Swizzle3<T> tps;
    Swizzle3<T> tpt;
    Swizzle3<T> tpp;
    Swizzle3<T> pss;
    Swizzle3<T> pst;
    Swizzle3<T> psp;
    Swizzle3<T> pts;
    Swizzle3<T> ptt;
    Swizzle3<T> ptp;
    Swizzle3<T> pps;
    Swizzle3<T> ppt;
    Swizzle3<T> ppp;

public:
    Swizzle4<T> xxxx;
    Swizzle4<T> xxxy;
    Swizzle4<T> xxxz;
    Swizzle4<T> xxyx;
    Swizzle4<T> xxyy;
    Swizzle4<T> xxyz;
    Swizzle4<T> xxzx;
    Swizzle4<T> xxzy;
    Swizzle4<T> xxzz;
    Swizzle4<T> xyxx;
    Swizzle4<T> xyxy;
    Swizzle4<T> xyxz;
    Swizzle4<T> xyyx;
    Swizzle4<T> xyyy;
    Swizzle4<T> xyyz;
    Swizzle4<T> xyzx;
    Swizzle4<T> xyzy;
    Swizzle4<T> xyzz;
    Swizzle4<T> xzxx;
    Swizzle4<T> xzxy;
    Swizzle4<T> xzxz;
    Swizzle4<T> xzyx;
    Swizzle4<T> xzyy;
    Swizzle4<T> xzyz;
    Swizzle4<T> xzzx;
    Swizzle4<T> xzzy;
    Swizzle4<T> xzzz;
    Swizzle4<T> yxxx;
    Swizzle4<T> yxxy;
    Swizzle4<T> yxxz;
    Swizzle4<T> yxyx;
    Swizzle4<T> yxyy;
    Swizzle4<T> yxyz;
    Swizzle4<T> yxzx;
    Swizzle4<T> yxzy;
    Swizzle4<T> yxzz;
    Swizzle4<T> yyxx;
    Swizzle4<T> yyxy;
    Swizzle4<T> yyxz;
    Swizzle4<T> yyyx;
    Swizzle4<T> yyyy;
    Swizzle4<T> yyyz;
    Swizzle4<T> yyzx;
    Swizzle4<T> yyzy;
    Swizzle4<T> yyzz;
    Swizzle4<T> yzxx;
    Swizzle4<T> yzxy;
    Swizzle4<T> yzxz;
    Swizzle4<T> yzyx;
    Swizzle4<T> yzyy;
    Swizzle4<T> yzyz;
    Swizzle4<T> yzzx;
    Swizzle4<T> yzzy;
    Swizzle4<T> yzzz;
    Swizzle4<T> zxxx;
    Swizzle4<T> zxxy;
    Swizzle4<T> zxxz;
    Swizzle4<T> zxyx;
    Swizzle4<T> zxyy;
    Swizzle4<T> zxyz;
    Swizzle4<T> zxzx;
    Swizzle4<T> zxzy;
    Swizzle4<T> zxzz;
    Swizzle4<T> zyxx;
    Swizzle4<T> zyxy;
    Swizzle4<T> zyxz;
    Swizzle4<T> zyyx;
    Swizzle4<T> zyyy;
    Swizzle4<T> zyyz;
    Swizzle4<T> zyzx;
    Swizzle4<T> zyzy;
    Swizzle4<T> zyzz;
    Swizzle4<T> zzxx;
    Swizzle4<T> zzxy;
    Swizzle4<T> zzxz;
    Swizzle4<T> zzyx;
    Swizzle4<T> zzyy;
    Swizzle4<T> zzyz;
    Swizzle4<T> zzzx;
    Swizzle4<T> zzzy;
    Swizzle4<T> zzzz;
    // alias rgb
    Swizzle4<T> rrrr;
    Swizzle4<T> rrrg;
    Swizzle4<T> rrrb;
    Swizzle4<T> rrgr;
    Swizzle4<T> rrgg;
    Swizzle4<T> rrgb;
    Swizzle4<T> rrbr;
    Swizzle4<T> rrbg;
    Swizzle4<T> rrbb;
    Swizzle4<T> rgrr;
    Swizzle4<T> rgrg;
    Swizzle4<T> rgrb;
    Swizzle4<T> rggr;
    Swizzle4<T> rggg;
    Swizzle4<T> rggb;
    Swizzle4<T> rgbr;
    Swizzle4<T> rgbg;
    Swizzle4<T> rgbb;
    Swizzle4<T> rbrr;
    Swizzle4<T> rbrg;
    Swizzle4<T> rbrb;
    Swizzle4<T> rbgr;
    Swizzle4<T> rbgg;
    Swizzle4<T> rbgb;
    Swizzle4<T> rbbr;
    Swizzle4<T> rbbg;
    Swizzle4<T> rbbb;
    Swizzle4<T> grrr;
    Swizzle4<T> grrg;
    Swizzle4<T> grrb;
    Swizzle4<T> grgr;
    Swizzle4<T> grgg;
    Swizzle4<T> grgb;
    Swizzle4<T> grbr;
    Swizzle4<T> grbg;
    Swizzle4<T> grbb;
    Swizzle4<T> ggrr;
    Swizzle4<T> ggrg;
    Swizzle4<T> ggrb;
    Swizzle4<T> gggr;
    Swizzle4<T> gggg;
    Swizzle4<T> gggb;
    Swizzle4<T> ggbr;
    Swizzle4<T> ggbg;
    Swizzle4<T> ggbb;
    Swizzle4<T> gbrr;
    Swizzle4<T> gbrg;
    Swizzle4<T> gbrb;
    Swizzle4<T> gbgr;
    Swizzle4<T> gbgg;
    Swizzle4<T> gbgb;
    Swizzle4<T> gbbr;
    Swizzle4<T> gbbg;
    Swizzle4<T> gbbb;
    Swizzle4<T> brrr;
    Swizzle4<T> brrg;
    Swizzle4<T> brrb;
    Swizzle4<T> brgr;
    Swizzle4<T> brgg;
    Swizzle4<T> brgb;
    Swizzle4<T> brbr;
    Swizzle4<T> brbg;
    Swizzle4<T> brbb;
    Swizzle4<T> bgrr;
    Swizzle4<T> bgrg;
    Swizzle4<T> bgrb;
    Swizzle4<T> bggr;
    Swizzle4<T> bggg;
    Swizzle4<T> bggb;
    Swizzle4<T> bgbr;
    Swizzle4<T> bgbg;
    Swizzle4<T> bgbb;
    Swizzle4<T> bbrr;
    Swizzle4<T> bbrg;
    Swizzle4<T> bbrb;
    Swizzle4<T> bbgr;
    Swizzle4<T> bbgg;
    Swizzle4<T> bbgb;
    Swizzle4<T> bbbr;
    Swizzle4<T> bbbg;
    Swizzle4<T> bbbb;
    // alias stp
    Swizzle4<T> ssss;
    Swizzle4<T> ssst;
    Swizzle4<T> sssp;
    Swizzle4<T> ssts;
    Swizzle4<T> sstt;
    Swizzle4<T> sstp;
    Swizzle4<T> ssps;
    Swizzle4<T> sspt;
    Swizzle4<T> sspp;
    Swizzle4<T> stss;
    Swizzle4<T> stst;
    Swizzle4<T> stsp;
    Swizzle4<T> stts;
    Swizzle4<T> sttt;
    Swizzle4<T> sttp;
    Swizzle4<T> stps;
    Swizzle4<T> stpt;
    Swizzle4<T> stpp;
    Swizzle4<T> spss;
    Swizzle4<T> spst;
    Swizzle4<T> spsp;
    Swizzle4<T> spts;
    Swizzle4<T> sptt;
    Swizzle4<T> sptp;
    Swizzle4<T> spps;
    Swizzle4<T> sppt;
    Swizzle4<T> sppp;
    Swizzle4<T> tsss;
    Swizzle4<T> tsst;
    Swizzle4<T> tssp;
    Swizzle4<T> tsts;
    Swizzle4<T> tstt;
    Swizzle4<T> tstp;
    Swizzle4<T> tsps;
    Swizzle4<T> tspt;
    Swizzle4<T> tspp;
    Swizzle4<T> ttss;
    Swizzle4<T> ttst;
    Swizzle4<T> ttsp;
    Swizzle4<T> ttts;
    Swizzle4<T> tttt;
    Swizzle4<T> tttp;
    Swizzle4<T> ttps;
    Swizzle4<T> ttpt;
    Swizzle4<T> ttpp;
    Swizzle4<T> tpss;
    Swizzle4<T> tpst;
    Swizzle4<T> tpsp;
    Swizzle4<T> tpts;
    Swizzle4<T> tptt;
    Swizzle4<T> tptp;
    Swizzle4<T> tpps;
    Swizzle4<T> tppt;
    Swizzle4<T> tppp;
    Swizzle4<T> psss;
    Swizzle4<T> psst;
    Swizzle4<T> pssp;
    Swizzle4<T> psts;
    Swizzle4<T> pstt;
    Swizzle4<T> pstp;
    Swizzle4<T> psps;
    Swizzle4<T> pspt;
    Swizzle4<T> pspp;
    Swizzle4<T> ptss;
    Swizzle4<T> ptst;
    Swizzle4<T> ptsp;
    Swizzle4<T> ptts;
    Swizzle4<T> pttt;
    Swizzle4<T> pttp;
    Swizzle4<T> ptps;
    Swizzle4<T> ptpt;
    Swizzle4<T> ptpp;
    Swizzle4<T> ppss;
    Swizzle4<T> ppst;
    Swizzle4<T> ppsp;
    Swizzle4<T> ppts;
    Swizzle4<T> pptt;
    Swizzle4<T> pptp;
    Swizzle4<T> ppps;
    Swizzle4<T> pppt;
    Swizzle4<T> pppp;
#endif  // GLSLIKE_DISABLE_SWIZZLE

};

//
// 8.1 Angle and Trigonometry Functions
// These all operate component-wise.
//

template <typename T>
Vector3<T> radians(const Vector3<T> &degrees) {
    return Vector3<T>(
        math<T>::radians(degrees.x),
        math<T>::radians(degrees.y),
        math<T>::radians(degrees.z)
    );
}

template <typename T>
Vector3<T> degrees(const Vector3<T> &radians) {
    return Vector3<T>(
        math<T>::degrees(radians.x),
        math<T>::degrees(radians.y),
        math<T>::degrees(radians.z)
    );
}

template <typename T>
Vector3<T> sin(const Vector3<T> &angle) {
    return Vector3<T>(
        math<T>::sin(angle.x),
        math<T>::sin(angle.y),
        math<T>::sin(angle.z)
    );
}

template <typename T>
Vector3<T> cos(const Vector3<T> &angle) {
    return Vector3<T>(
        math<T>::cos(angle.x),
        math<T>::cos(angle.y),
        math<T>::cos(angle.z)
    );
}

template <typename T>
Vector3<T> tan(const Vector3<T> & angle) {
    return Vector3<T>(
        math<T>::tan(angle.x),
        math<T>::tan(angle.y),
        math<T>::tan(angle.z)
    );
}

template <typename T>
Vector3<T> asin(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::asin(x.x),
        math<T>::asin(x.y),
        math<T>::asin(x.z)
    );
}

template <typename T>
Vector3<T> acos(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::acos(x.x),
        math<T>::acos(x.y),
        math<T>::acos(x.z)
    );
}

template <typename T>
Vector3<T> atan(const Vector3<T> &y, const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::atan(y.x, x.x),
        math<T>::atan(y.y, x.y),
        math<T>::atan(y.z, x.z)
    );
}

template <typename T>
Vector3<T> atan(const Vector3<T> &y_over_x) {
    return Vector3<T>(
        math<T>::atan(y_over_x.x),
        math<T>::atan(y_over_x.y),
        math<T>::atan(y_over_x.z)
    );
}

template <typename T>
Vector3<T> sinh(const Vector3<T> &angle) {
    return Vector3<T>(
        math<T>::sinh(angle.x),
        math<T>::sinh(angle.y),
        math<T>::sinh(angle.z)
    );
}

template <typename T>
Vector3<T> cosh(const Vector3<T> &angle) {
    return Vector3<T>(
        math<T>::cosh(angle.x),
        math<T>::cosh(angle.y),
        math<T>::cosh(angle.z)
    );
}

template <typename T>
Vector3<T> tanh(const Vector3<T> &angle) {
    return Vector3<T>(
        math<T>::tanh(angle.x),
        math<T>::tanh(angle.y),
        math<T>::tanh(angle.z)
    );
}

template <typename T>
Vector3<T> asinh(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::asinh(x.x),
        math<T>::asinh(x.y),
        math<T>::asinh(x.z)
    );
}

template <typename T>
Vector3<T> acosh(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::acosh(x.x),
        math<T>::acosh(x.y),
        math<T>::acosh(x.z)
    );
}

template <typename T>
Vector3<T> atanh(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::atanh(x.x),
        math<T>::atanh(x.y),
        math<T>::atanh(x.z)
    );
}

//
// 8.2 Exponential Functions
// These all operate component-wise.
//

template <typename T>
Vector3<T> pow(const Vector3<T> &vec, T n) {
    return Vector3<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n),
        math<T>::pow(vec.z, n)
    );
}

template <typename T>
Vector3<T> exp(const Vector3<T> &vec) {
    return Vector3<T>(
        math<T>::exp(vec.x),
        math<T>::exp(vec.y),
        math<T>::exp(vec.z)
    );
}

template <typename T>
Vector3<T> log(const Vector3<T> &vec) {
    return Vector3<T>(
        math<T>::log(vec.x),
        math<T>::log(vec.y),
        math<T>::log(vec.z)
    );
}

template <typename T>
Vector3<T> exp2(const Vector3<T> &vec) {
    return Vector3<T>(
        math<T>::exp2(vec.x),
        math<T>::exp2(vec.y),
        math<T>::exp2(vec.z)
    );
}

template <typename T>
Vector3<T> log2(const Vector3<T> &vec) {
    return Vector3<T>(
        math<T>::log2(vec.x),
        math<T>::log2(vec.y),
        math<T>::log2(vec.z)
    );
}

template <typename T>
Vector3<T> sqrt(const Vector3<T> &vec) {
    return Vector3<T>(
        math<T>::sqrt(vec.x),
        math<T>::sqrt(vec.y),
        math<T>::sqrt(vec.z)
    );
}

template <typename T>
Vector3<T> inversesqrt(const Vector3<T> &vec) {
    return Vector3<T>(
        math<T>::inversesqrt(vec.x),
        math<T>::inversesqrt(vec.y),
        math<T>::inversesqrt(vec.z)
    );
}

//
// 8.3 Common Functions
//

template <typename T>
Vector3<T> abs(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::abs(x.x),
        math<T>::abs(x.y),
        math<T>::abs(x.z)
    );
}

template <typename T>
Vector3<T> sign(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::sign(x.x),
        math<T>::sign(x.y),
        math<T>::sign(x.z)
    );
}

template <typename T>
Vector3<T> floor(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::floor(x.x),
        math<T>::floor(x.y),
        math<T>::floor(x.z)
    );
}

template <typename T>
Vector3<T> trunc(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::trunc(x.x),
        math<T>::trunc(x.y),
        math<T>::trunc(x.z)
    );
}

template <typename T>
Vector3<T> round(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::round(x.x),
        math<T>::round(x.y),
        math<T>::round(x.z)
    );
}

template <typename T>
Vector3<T> roundEven(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::roundEven(x.x),
        math<T>::roundEven(x.y),
        math<T>::roundEven(x.z)
    );
}

template <typename T>
Vector3<T> ceil(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::ceil(x.x),
        math<T>::ceil(x.y),
        math<T>::ceil(x.z)
    );
}

template <typename T>
Vector3<T> fract(const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::fract(x.x),
        math<T>::fract(x.y),
        math<T>::fract(x.z)
    );
}

template <typename T>
Vector3<T> mod(const Vector3<T> &x, const Vector3<T> &y) {
    return Vector3<T>(
        math<T>::mod(x.x, y.x),
        math<T>::mod(x.y, y.y),
        math<T>::mod(x.z, y.z)
    );
}

template <typename T>
Vector3<T> mod(const Vector3<T> &x, T y) {
    return Vector3<T>(
        math<T>::mod(x.x, y),
        math<T>::mod(x.y, y),
        math<T>::mod(x.z, y)
    );
}

template <typename T>
Vector3<T> modf(const Vector3<T> &x, Vector3<T> *i) {
    return Vector3<T>(
        math<T>::modf(x.x, &i->x),
        math<T>::modf(x.y, &i->y),
        math<T>::modf(x.z, &i->z)
    );
}

template <typename T>
Vector3<T> min(const Vector3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(
        math<T>::min(a.x, b.x),
        math<T>::min(a.y, b.y),
        math<T>::min(a.z, b.z)
    );
}

template <typename T>
Vector3<T> min(const Vector3<T> &a, T b) {
    return Vector3<T>(
        math<T>::min(a.x, b),
        math<T>::min(a.y, b),
        math<T>::min(a.z, b)
    );
}

template <typename T>
Vector3<T> max(const Vector3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(
        math<T>::max(a.x, b.x),
        math<T>::max(a.y, b.y),
        math<T>::max(a.z, b.z)
    );
}

template <typename T>
Vector3<T> max(const Vector3<T> &a, T b) {
    return Vector3<T>(
        math<T>::max(a.x, b),
        math<T>::max(a.y, b),
        math<T>::max(a.z, b)
    );
}

template <typename T>
Vector3<T> clamp(const Vector3<T> &value, const Vector3<T> &min, const Vector3<T> &max) {
    return Vector3<T>(
        math<T>::clamp(value.x, min.x, max.x),
        math<T>::clamp(value.y, min.y, max.y),
        math<T>::clamp(value.z, min.z, max.z)
    );
}

template <typename T>
Vector3<T> clamp(const Vector3<T> &value, T min, T max) {
    return Vector3<T>(
        math<T>::clamp(value.x, min, max),
        math<T>::clamp(value.y, min, max),
        math<T>::clamp(value.z, min, max)
    );
}

template <typename T>
Vector3<T> mix(const Vector3<T> &x, const Vector3<T> &y, const Vector3<T> &a) {
    return Vector3<T>(
        math<T>::mix(x.x, y.x, a.x),
        math<T>::mix(x.y, y.y, a.y),
        math<T>::mix(x.z, y.z, a.z)
    );
}

template <typename T>
Vector3<T> mix(const Vector3<T> &x, const Vector3<T> &y, T a) {
    return Vector3<T>(
        math<T>::mix(x.x, y.x, a),
        math<T>::mix(x.y, y.y, a),
        math<T>::mix(x.z, y.z, a)
    );
}

template <typename T>
Vector3<T> step(const Vector3<T> &edge, const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::step(edge.x, x.x),
        math<T>::step(edge.y, x.y),
        math<T>::step(edge.z, x.z)
    );
}

template <typename T>
Vector3<T> step(T edge, const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::step(edge, x.x),
        math<T>::step(edge, x.y),
        math<T>::step(edge, x.z)
    );
}

template <typename T>
Vector3<T> smoothstep(const Vector3<T> &edge0, const Vector3<T> &edge1, const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::smoothstep(edge0.x, edge1.x, x.x),
        math<T>::smoothstep(edge0.y, edge1.y, x.y),
        math<T>::smoothstep(edge0.z, edge1.z, x.z)
    );
}

template <typename T>
Vector3<T> smoothstep(T edge0, T edge1, const Vector3<T> &x) {
    return Vector3<T>(
        math<T>::smoothstep(edge0, edge1, x.x),
        math<T>::smoothstep(edge0, edge1, x.y),
        math<T>::smoothstep(edge0, edge1, x.z)
    );
}

template <typename T>
Vector3<Bool_t> isnan(const Vector3<T> &x) {
    return Vector3<Bool_t>(
        math<T>::isnan(x.x),
        math<T>::isnan(x.y),
        math<T>::isnan(x.z)
    );
}

template <typename T>
Vector3<Bool_t> isinf(const Vector3<T> &x) {
    return Vector3<Bool_t>(
        math<T>::isinf(x.x),
        math<T>::isinf(x.y),
        math<T>::isinf(x.z)
    );
}

//
// TODO:
// * floatBitToInt
// * floatBitToUint
// * intBitsToFloat
// * fma
// * frexp
// * ldexp
//

// 8.4 Floating-Point Pack and Unpack Functions
//
// * packUnorm2x16
// * packSnorm2x16
// * packUnorm4x8
// * packSnorm4x8
// * unpackUnorm2x16
// * unpackSnorm2x16
// * unpackUnorm4x8
// * unpackSnorm4x8
// * packDouble2x32
// * unpackDouble2x32
// * packHalf2x16
// * unpackHalf2x16
//
// 8.5 Geometric Functions
//

template <typename T>
Vector3<T> cross(const Vector3<T> &x, const Vector3<T> &y) {
    return x.cross(y);
}

// 8.6 Matrix Functions
//
// * matrixCompMult
// * outerProduct
// * transpose
// * determinant
// * inverse
//
// 8.7 Vector Relational Functions
//
// * lessThan
// * lessThanEqual
// * greaterThan
// * greaterThanEqual
// * equal
// * notEqual
// * any
// * all
// * not
//
// 8.8 Integer Functions
//
// * uaddCarry
// * usubBorrow
// * umulExtended
// * imulExtended
// * bitfieldExtract
// * bitfieldInsert
// * bitfieldReverse
// * bitCount
// * findLSB
// * findMSB

template <typename T>
Vector3<T> operator +(T a, const Vector3<T> &b) {
    return Vector3<T>(
        a + b.x,
        a + b.y,
        a + b.z
    );
}

template <typename T>
Vector3<T> operator -(T a, const Vector3<T> &b) {
    return Vector3<T>(
        a - b.x,
        a - b.y,
        a - b.z
    );
}

template <typename T>
Vector3<T> operator *(T a, const Vector3<T> &b) {
    return Vector3<T>(
        a * b.x,
        a * b.y,
        a * b.z
    );
}

template <typename T>
Vector3<T> operator /(T a, const Vector3<T> &b) {
    return Vector3<T>(
        a / b.x,
        a / b.y,
        a / b.z
    );
}


#ifndef GLSLIKE_DISABLE_SWIZZLE

template <typename T>
Vector3<T> operator +(const Swizzle3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    );
}

template <typename T>
Vector3<T> operator -(const Swizzle3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    );
}

template <typename T>
Vector3<T> operator *(const Swizzle3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    );
}

template <typename T>
Vector3<T> operator /(const Swizzle3<T> &a, const Vector3<T> &b) {
    return Vector3<T>(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
    );
}

template <typename T>
Vector3<T> operator +(const Vector3<T> & a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    );
}

template <typename T>
Vector3<T> operator -(const Vector3<T> & a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    );
}

template <typename T>
Vector3<T> operator *(const Vector3<T> & a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    );
}

template <typename T>
Vector3<T> operator /(const Vector3<T> & a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
    );
}

template <typename T>
Vector3<T> operator +(const Swizzle3<T> &a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z
    );
}

template <typename T>
Vector3<T> operator -(const Swizzle3<T> &a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z
    );
}

template <typename T>
Vector3<T> operator *(const Swizzle3<T> &a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z
    );
}

template <typename T>
Vector3<T> operator /(const Swizzle3<T> &a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z
    );
}

template <typename T>
Vector3<T> operator +(const Swizzle3<T> &a, T b) {
    return Vector3<T>(
        a.x + b,
        a.y + b,
        a.z + b
    );
}

template <typename T>
Vector3<T> operator -(const Swizzle3<T> &a, T b) {
    return Vector3<T>(
        a.x - b,
        a.y - b,
        a.z - b
    );
}

template <typename T>
Vector3<T> operator *(const Swizzle3<T> &a, T b) {
    return Vector3<T>(
        a.x * b,
        a.y * b,
        a.z * b
    );
}

template <typename T>
Vector3<T> operator /(const Swizzle3<T> &a, T b) {
    return Vector3<T>(
        a.x / b,
        a.y / b,
        a.z / b
    );
}

template <typename T>
Vector3<T> operator +(T a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a + b.x,
        a + b.y,
        a + b.z
    );
}

template <typename T>
Vector3<T> operator -(T a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a - b.x,
        a - b.y,
        a - b.z
    );
}

template <typename T>
Vector3<T> operator *(T a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a * b.x,
        a * b.y,
        a * b.z
    );
}

template <typename T>
Vector3<T> operator /(T a, const Swizzle3<T> &b) {
    return Vector3<T>(
        a / b.x,
        a / b.y,
        a / b.z
    );
}

#endif  // GLSLIKE_DISABLE_SWIZZLE


#ifdef GLSLIKE_DISABLE_SWIZZLE
#define GLSLIKE_VECTOR4_SWIZZLE() \
    r(this->x) \
    , g(this->y) \
    , b(this->z) \
    , a(this->w) \
    , s(this->x) \
    , t(this->y) \
    , p(this->z) \
    , q(this->w)
#else
#define GLSLIKE_VECTOR4_SWIZZLE() \
    r(this->x) \
    , g(this->y) \
    , b(this->z) \
    , a(this->w) \
    , s(this->x) \
    , t(this->y) \
    , p(this->z) \
    , q(this->w) \
    , xx(this->x, this->x) \
    , xy(this->x, this->y) \
    , xz(this->x, this->z) \
    , xw(this->x, this->w) \
    , yx(this->y, this->x) \
    , yy(this->y, this->y) \
    , yz(this->y, this->z) \
    , yw(this->y, this->w) \
    , zx(this->z, this->x) \
    , zy(this->z, this->y) \
    , zz(this->z, this->z) \
    , zw(this->z, this->w) \
    , wx(this->w, this->x) \
    , wy(this->w, this->y) \
    , wz(this->w, this->z) \
    , ww(this->w, this->w) \
    , rr(this->x, this->x) \
    , rg(this->x, this->y) \
    , rb(this->x, this->z) \
    , ra(this->x, this->w) \
    , gr(this->y, this->x) \
    , gg(this->y, this->y) \
    , gb(this->y, this->z) \
    , ga(this->y, this->w) \
    , br(this->z, this->x) \
    , bg(this->z, this->y) \
    , bb(this->z, this->z) \
    , ba(this->z, this->w) \
    , ar(this->w, this->x) \
    , ag(this->w, this->y) \
    , ab(this->w, this->z) \
    , aa(this->w, this->w) \
    , ss(this->x, this->x) \
    , st(this->x, this->y) \
    , sp(this->x, this->z) \
    , sq(this->x, this->w) \
    , ts(this->y, this->x) \
    , tt(this->y, this->y) \
    , tp(this->y, this->z) \
    , tq(this->y, this->w) \
    , ps(this->z, this->x) \
    , pt(this->z, this->y) \
    , pp(this->z, this->z) \
    , pq(this->z, this->w) \
    , qs(this->w, this->x) \
    , qt(this->w, this->y) \
    , qp(this->w, this->z) \
    , qq(this->w, this->w) \
    , xxx(this->x, this->x, this->x) \
    , xxy(this->x, this->x, this->y) \
    , xxz(this->x, this->x, this->z) \
    , xxw(this->x, this->x, this->w) \
    , xyx(this->x, this->y, this->x) \
    , xyy(this->x, this->y, this->y) \
    , xyz(this->x, this->y, this->z) \
    , xyw(this->x, this->y, this->w) \
    , xzx(this->x, this->z, this->x) \
    , xzy(this->x, this->z, this->y) \
    , xzz(this->x, this->z, this->z) \
    , xzw(this->x, this->z, this->w) \
    , xwx(this->x, this->w, this->x) \
    , xwy(this->x, this->w, this->y) \
    , xwz(this->x, this->w, this->z) \
    , xww(this->x, this->w, this->w) \
    , yxx(this->y, this->x, this->x) \
    , yxy(this->y, this->x, this->y) \
    , yxz(this->y, this->x, this->z) \
    , yxw(this->y, this->x, this->w) \
    , yyx(this->y, this->y, this->x) \
    , yyy(this->y, this->y, this->y) \
    , yyz(this->y, this->y, this->z) \
    , yyw(this->y, this->y, this->w) \
    , yzx(this->y, this->z, this->x) \
    , yzy(this->y, this->z, this->y) \
    , yzz(this->y, this->z, this->z) \
    , yzw(this->y, this->z, this->w) \
    , ywx(this->y, this->w, this->x) \
    , ywy(this->y, this->w, this->y) \
    , ywz(this->y, this->w, this->z) \
    , yww(this->y, this->w, this->w) \
    , zxx(this->z, this->x, this->x) \
    , zxy(this->z, this->x, this->y) \
    , zxz(this->z, this->x, this->z) \
    , zxw(this->z, this->x, this->w) \
    , zyx(this->z, this->y, this->x) \
    , zyy(this->z, this->y, this->y) \
    , zyz(this->z, this->y, this->z) \
    , zyw(this->z, this->y, this->w) \
    , zzx(this->z, this->z, this->x) \
    , zzy(this->z, this->z, this->y) \
    , zzz(this->z, this->z, this->z) \
    , zzw(this->z, this->z, this->w) \
    , zwx(this->z, this->w, this->x) \
    , zwy(this->z, this->w, this->y) \
    , zwz(this->z, this->w, this->z) \
    , zww(this->z, this->w, this->w) \
    , wxx(this->w, this->x, this->x) \
    , wxy(this->w, this->x, this->y) \
    , wxz(this->w, this->x, this->z) \
    , wxw(this->w, this->x, this->w) \
    , wyx(this->w, this->y, this->x) \
    , wyy(this->w, this->y, this->y) \
    , wyz(this->w, this->y, this->z) \
    , wyw(this->w, this->y, this->w) \
    , wzx(this->w, this->z, this->x) \
    , wzy(this->w, this->z, this->y) \
    , wzz(this->w, this->z, this->z) \
    , wzw(this->w, this->z, this->w) \
    , wwx(this->w, this->w, this->x) \
    , wwy(this->w, this->w, this->y) \
    , wwz(this->w, this->w, this->z) \
    , www(this->w, this->w, this->w) \
    , rrr(this->x, this->x, this->x) \
    , rrg(this->x, this->x, this->y) \
    , rrb(this->x, this->x, this->z) \
    , rra(this->x, this->x, this->w) \
    , rgr(this->x, this->y, this->x) \
    , rgg(this->x, this->y, this->y) \
    , rgb(this->x, this->y, this->z) \
    , rga(this->x, this->y, this->w) \
    , rbr(this->x, this->z, this->x) \
    , rbg(this->x, this->z, this->y) \
    , rbb(this->x, this->z, this->z) \
    , rba(this->x, this->z, this->w) \
    , rar(this->x, this->w, this->x) \
    , rag(this->x, this->w, this->y) \
    , rab(this->x, this->w, this->z) \
    , raa(this->x, this->w, this->w) \
    , grr(this->y, this->x, this->x) \
    , grg(this->y, this->x, this->y) \
    , grb(this->y, this->x, this->z) \
    , gra(this->y, this->x, this->w) \
    , ggr(this->y, this->y, this->x) \
    , ggg(this->y, this->y, this->y) \
    , ggb(this->y, this->y, this->z) \
    , gga(this->y, this->y, this->w) \
    , gbr(this->y, this->z, this->x) \
    , gbg(this->y, this->z, this->y) \
    , gbb(this->y, this->z, this->z) \
    , gba(this->y, this->z, this->w) \
    , gar(this->y, this->w, this->x) \
    , gag(this->y, this->w, this->y) \
    , gab(this->y, this->w, this->z) \
    , gaa(this->y, this->w, this->w) \
    , brr(this->z, this->x, this->x) \
    , brg(this->z, this->x, this->y) \
    , brb(this->z, this->x, this->z) \
    , bra(this->z, this->x, this->w) \
    , bgr(this->z, this->y, this->x) \
    , bgg(this->z, this->y, this->y) \
    , bgb(this->z, this->y, this->z) \
    , bga(this->z, this->y, this->w) \
    , bbr(this->z, this->z, this->x) \
    , bbg(this->z, this->z, this->y) \
    , bbb(this->z, this->z, this->z) \
    , bba(this->z, this->z, this->w) \
    , bar(this->z, this->w, this->x) \
    , bag(this->z, this->w, this->y) \
    , bab(this->z, this->w, this->z) \
    , baa(this->z, this->w, this->w) \
    , arr(this->w, this->x, this->x) \
    , arg(this->w, this->x, this->y) \
    , arb(this->w, this->x, this->z) \
    , ara(this->w, this->x, this->w) \
    , agr(this->w, this->y, this->x) \
    , agg(this->w, this->y, this->y) \
    , agb(this->w, this->y, this->z) \
    , aga(this->w, this->y, this->w) \
    , abr(this->w, this->z, this->x) \
    , abg(this->w, this->z, this->y) \
    , abb(this->w, this->z, this->z) \
    , aba(this->w, this->z, this->w) \
    , aar(this->w, this->w, this->x) \
    , aag(this->w, this->w, this->y) \
    , aab(this->w, this->w, this->z) \
    , aaa(this->w, this->w, this->w) \
    , sss(this->x, this->x, this->x) \
    , sst(this->x, this->x, this->y) \
    , ssp(this->x, this->x, this->z) \
    , ssq(this->x, this->x, this->w) \
    , sts(this->x, this->y, this->x) \
    , stt(this->x, this->y, this->y) \
    , stp(this->x, this->y, this->z) \
    , stq(this->x, this->y, this->w) \
    , sps(this->x, this->z, this->x) \
    , spt(this->x, this->z, this->y) \
    , spp(this->x, this->z, this->z) \
    , spq(this->x, this->z, this->w) \
    , sqs(this->x, this->w, this->x) \
    , sqt(this->x, this->w, this->y) \
    , sqp(this->x, this->w, this->z) \
    , sqq(this->x, this->w, this->w) \
    , tss(this->y, this->x, this->x) \
    , tst(this->y, this->x, this->y) \
    , tsp(this->y, this->x, this->z) \
    , tsq(this->y, this->x, this->w) \
    , tts(this->y, this->y, this->x) \
    , ttt(this->y, this->y, this->y) \
    , ttp(this->y, this->y, this->z) \
    , ttq(this->y, this->y, this->w) \
    , tps(this->y, this->z, this->x) \
    , tpt(this->y, this->z, this->y) \
    , tpp(this->y, this->z, this->z) \
    , tpq(this->y, this->z, this->w) \
    , tqs(this->y, this->w, this->x) \
    , tqt(this->y, this->w, this->y) \
    , tqp(this->y, this->w, this->z) \
    , tqq(this->y, this->w, this->w) \
    , pss(this->z, this->x, this->x) \
    , pst(this->z, this->x, this->y) \
    , psp(this->z, this->x, this->z) \
    , psq(this->z, this->x, this->w) \
    , pts(this->z, this->y, this->x) \
    , ptt(this->z, this->y, this->y) \
    , ptp(this->z, this->y, this->z) \
    , ptq(this->z, this->y, this->w) \
    , pps(this->z, this->z, this->x) \
    , ppt(this->z, this->z, this->y) \
    , ppp(this->z, this->z, this->z) \
    , ppq(this->z, this->z, this->w) \
    , pqs(this->z, this->w, this->x) \
    , pqt(this->z, this->w, this->y) \
    , pqp(this->z, this->w, this->z) \
    , pqq(this->z, this->w, this->w) \
    , qss(this->w, this->x, this->x) \
    , qst(this->w, this->x, this->y) \
    , qsp(this->w, this->x, this->z) \
    , qsq(this->w, this->x, this->w) \
    , qts(this->w, this->y, this->x) \
    , qtt(this->w, this->y, this->y) \
    , qtp(this->w, this->y, this->z) \
    , qtq(this->w, this->y, this->w) \
    , qps(this->w, this->z, this->x) \
    , qpt(this->w, this->z, this->y) \
    , qpp(this->w, this->z, this->z) \
    , qpq(this->w, this->z, this->w) \
    , qqs(this->w, this->w, this->x) \
    , qqt(this->w, this->w, this->y) \
    , qqp(this->w, this->w, this->z) \
    , qqq(this->w, this->w, this->w) \
    , xxxx(this->x, this->x, this->x, this->x) \
    , xxxy(this->x, this->x, this->x, this->y) \
    , xxxz(this->x, this->x, this->x, this->z) \
    , xxxw(this->x, this->x, this->x, this->w) \
    , xxyx(this->x, this->x, this->y, this->x) \
    , xxyy(this->x, this->x, this->y, this->y) \
    , xxyz(this->x, this->x, this->y, this->z) \
    , xxyw(this->x, this->x, this->y, this->w) \
    , xxzx(this->x, this->x, this->z, this->x) \
    , xxzy(this->x, this->x, this->z, this->y) \
    , xxzz(this->x, this->x, this->z, this->z) \
    , xxzw(this->x, this->x, this->z, this->w) \
    , xxwx(this->x, this->x, this->w, this->x) \
    , xxwy(this->x, this->x, this->w, this->y) \
    , xxwz(this->x, this->x, this->w, this->z) \
    , xxww(this->x, this->x, this->w, this->w) \
    , xyxx(this->x, this->y, this->x, this->x) \
    , xyxy(this->x, this->y, this->x, this->y) \
    , xyxz(this->x, this->y, this->x, this->z) \
    , xyxw(this->x, this->y, this->x, this->w) \
    , xyyx(this->x, this->y, this->y, this->x) \
    , xyyy(this->x, this->y, this->y, this->y) \
    , xyyz(this->x, this->y, this->y, this->z) \
    , xyyw(this->x, this->y, this->y, this->w) \
    , xyzx(this->x, this->y, this->z, this->x) \
    , xyzy(this->x, this->y, this->z, this->y) \
    , xyzz(this->x, this->y, this->z, this->z) \
    , xyzw(this->x, this->y, this->z, this->w) \
    , xywx(this->x, this->y, this->w, this->x) \
    , xywy(this->x, this->y, this->w, this->y) \
    , xywz(this->x, this->y, this->w, this->z) \
    , xyww(this->x, this->y, this->w, this->w) \
    , xzxx(this->x, this->z, this->x, this->x) \
    , xzxy(this->x, this->z, this->x, this->y) \
    , xzxz(this->x, this->z, this->x, this->z) \
    , xzxw(this->x, this->z, this->x, this->w) \
    , xzyx(this->x, this->z, this->y, this->x) \
    , xzyy(this->x, this->z, this->y, this->y) \
    , xzyz(this->x, this->z, this->y, this->z) \
    , xzyw(this->x, this->z, this->y, this->w) \
    , xzzx(this->x, this->z, this->z, this->x) \
    , xzzy(this->x, this->z, this->z, this->y) \
    , xzzz(this->x, this->z, this->z, this->z) \
    , xzzw(this->x, this->z, this->z, this->w) \
    , xzwx(this->x, this->z, this->w, this->x) \
    , xzwy(this->x, this->z, this->w, this->y) \
    , xzwz(this->x, this->z, this->w, this->z) \
    , xzww(this->x, this->z, this->w, this->w) \
    , xwxx(this->x, this->w, this->x, this->x) \
    , xwxy(this->x, this->w, this->x, this->y) \
    , xwxz(this->x, this->w, this->x, this->z) \
    , xwxw(this->x, this->w, this->x, this->w) \
    , xwyx(this->x, this->w, this->y, this->x) \
    , xwyy(this->x, this->w, this->y, this->y) \
    , xwyz(this->x, this->w, this->y, this->z) \
    , xwyw(this->x, this->w, this->y, this->w) \
    , xwzx(this->x, this->w, this->z, this->x) \
    , xwzy(this->x, this->w, this->z, this->y) \
    , xwzz(this->x, this->w, this->z, this->z) \
    , xwzw(this->x, this->w, this->z, this->w) \
    , xwwx(this->x, this->w, this->w, this->x) \
    , xwwy(this->x, this->w, this->w, this->y) \
    , xwwz(this->x, this->w, this->w, this->z) \
    , xwww(this->x, this->w, this->w, this->w) \
    , yxxx(this->y, this->x, this->x, this->x) \
    , yxxy(this->y, this->x, this->x, this->y) \
    , yxxz(this->y, this->x, this->x, this->z) \
    , yxxw(this->y, this->x, this->x, this->w) \
    , yxyx(this->y, this->x, this->y, this->x) \
    , yxyy(this->y, this->x, this->y, this->y) \
    , yxyz(this->y, this->x, this->y, this->z) \
    , yxyw(this->y, this->x, this->y, this->w) \
    , yxzx(this->y, this->x, this->z, this->x) \
    , yxzy(this->y, this->x, this->z, this->y) \
    , yxzz(this->y, this->x, this->z, this->z) \
    , yxzw(this->y, this->x, this->z, this->w) \
    , yxwx(this->y, this->x, this->w, this->x) \
    , yxwy(this->y, this->x, this->w, this->y) \
    , yxwz(this->y, this->x, this->w, this->z) \
    , yxww(this->y, this->x, this->w, this->w) \
    , yyxx(this->y, this->y, this->x, this->x) \
    , yyxy(this->y, this->y, this->x, this->y) \
    , yyxz(this->y, this->y, this->x, this->z) \
    , yyxw(this->y, this->y, this->x, this->w) \
    , yyyx(this->y, this->y, this->y, this->x) \
    , yyyy(this->y, this->y, this->y, this->y) \
    , yyyz(this->y, this->y, this->y, this->z) \
    , yyyw(this->y, this->y, this->y, this->w) \
    , yyzx(this->y, this->y, this->z, this->x) \
    , yyzy(this->y, this->y, this->z, this->y) \
    , yyzz(this->y, this->y, this->z, this->z) \
    , yyzw(this->y, this->y, this->z, this->w) \
    , yywx(this->y, this->y, this->w, this->x) \
    , yywy(this->y, this->y, this->w, this->y) \
    , yywz(this->y, this->y, this->w, this->z) \
    , yyww(this->y, this->y, this->w, this->w) \
    , yzxx(this->y, this->z, this->x, this->x) \
    , yzxy(this->y, this->z, this->x, this->y) \
    , yzxz(this->y, this->z, this->x, this->z) \
    , yzxw(this->y, this->z, this->x, this->w) \
    , yzyx(this->y, this->z, this->y, this->x) \
    , yzyy(this->y, this->z, this->y, this->y) \
    , yzyz(this->y, this->z, this->y, this->z) \
    , yzyw(this->y, this->z, this->y, this->w) \
    , yzzx(this->y, this->z, this->z, this->x) \
    , yzzy(this->y, this->z, this->z, this->y) \
    , yzzz(this->y, this->z, this->z, this->z) \
    , yzzw(this->y, this->z, this->z, this->w) \
    , yzwx(this->y, this->z, this->w, this->x) \
    , yzwy(this->y, this->z, this->w, this->y) \
    , yzwz(this->y, this->z, this->w, this->z) \
    , yzww(this->y, this->z, this->w, this->w) \
    , ywxx(this->y, this->w, this->x, this->x) \
    , ywxy(this->y, this->w, this->x, this->y) \
    , ywxz(this->y, this->w, this->x, this->z) \
    , ywxw(this->y, this->w, this->x, this->w) \
    , ywyx(this->y, this->w, this->y, this->x) \
    , ywyy(this->y, this->w, this->y, this->y) \
    , ywyz(this->y, this->w, this->y, this->z) \
    , ywyw(this->y, this->w, this->y, this->w) \
    , ywzx(this->y, this->w, this->z, this->x) \
    , ywzy(this->y, this->w, this->z, this->y) \
    , ywzz(this->y, this->w, this->z, this->z) \
    , ywzw(this->y, this->w, this->z, this->w) \
    , ywwx(this->y, this->w, this->w, this->x) \
    , ywwy(this->y, this->w, this->w, this->y) \
    , ywwz(this->y, this->w, this->w, this->z) \
    , ywww(this->y, this->w, this->w, this->w) \
    , zxxx(this->z, this->x, this->x, this->x) \
    , zxxy(this->z, this->x, this->x, this->y) \
    , zxxz(this->z, this->x, this->x, this->z) \
    , zxxw(this->z, this->x, this->x, this->w) \
    , zxyx(this->z, this->x, this->y, this->x) \
    , zxyy(this->z, this->x, this->y, this->y) \
    , zxyz(this->z, this->x, this->y, this->z) \
    , zxyw(this->z, this->x, this->y, this->w) \
    , zxzx(this->z, this->x, this->z, this->x) \
    , zxzy(this->z, this->x, this->z, this->y) \
    , zxzz(this->z, this->x, this->z, this->z) \
    , zxzw(this->z, this->x, this->z, this->w) \
    , zxwx(this->z, this->x, this->w, this->x) \
    , zxwy(this->z, this->x, this->w, this->y) \
    , zxwz(this->z, this->x, this->w, this->z) \
    , zxww(this->z, this->x, this->w, this->w) \
    , zyxx(this->z, this->y, this->x, this->x) \
    , zyxy(this->z, this->y, this->x, this->y) \
    , zyxz(this->z, this->y, this->x, this->z) \
    , zyxw(this->z, this->y, this->x, this->w) \
    , zyyx(this->z, this->y, this->y, this->x) \
    , zyyy(this->z, this->y, this->y, this->y) \
    , zyyz(this->z, this->y, this->y, this->z) \
    , zyyw(this->z, this->y, this->y, this->w) \
    , zyzx(this->z, this->y, this->z, this->x) \
    , zyzy(this->z, this->y, this->z, this->y) \
    , zyzz(this->z, this->y, this->z, this->z) \
    , zyzw(this->z, this->y, this->z, this->w) \
    , zywx(this->z, this->y, this->w, this->x) \
    , zywy(this->z, this->y, this->w, this->y) \
    , zywz(this->z, this->y, this->w, this->z) \
    , zyww(this->z, this->y, this->w, this->w) \
    , zzxx(this->z, this->z, this->x, this->x) \
    , zzxy(this->z, this->z, this->x, this->y) \
    , zzxz(this->z, this->z, this->x, this->z) \
    , zzxw(this->z, this->z, this->x, this->w) \
    , zzyx(this->z, this->z, this->y, this->x) \
    , zzyy(this->z, this->z, this->y, this->y) \
    , zzyz(this->z, this->z, this->y, this->z) \
    , zzyw(this->z, this->z, this->y, this->w) \
    , zzzx(this->z, this->z, this->z, this->x) \
    , zzzy(this->z, this->z, this->z, this->y) \
    , zzzz(this->z, this->z, this->z, this->z) \
    , zzzw(this->z, this->z, this->z, this->w) \
    , zzwx(this->z, this->z, this->w, this->x) \
    , zzwy(this->z, this->z, this->w, this->y) \
    , zzwz(this->z, this->z, this->w, this->z) \
    , zzww(this->z, this->z, this->w, this->w) \
    , zwxx(this->z, this->w, this->x, this->x) \
    , zwxy(this->z, this->w, this->x, this->y) \
    , zwxz(this->z, this->w, this->x, this->z) \
    , zwxw(this->z, this->w, this->x, this->w) \
    , zwyx(this->z, this->w, this->y, this->x) \
    , zwyy(this->z, this->w, this->y, this->y) \
    , zwyz(this->z, this->w, this->y, this->z) \
    , zwyw(this->z, this->w, this->y, this->w) \
    , zwzx(this->z, this->w, this->z, this->x) \
    , zwzy(this->z, this->w, this->z, this->y) \
    , zwzz(this->z, this->w, this->z, this->z) \
    , zwzw(this->z, this->w, this->z, this->w) \
    , zwwx(this->z, this->w, this->w, this->x) \
    , zwwy(this->z, this->w, this->w, this->y) \
    , zwwz(this->z, this->w, this->w, this->z) \
    , zwww(this->z, this->w, this->w, this->w) \
    , wxxx(this->w, this->x, this->x, this->x) \
    , wxxy(this->w, this->x, this->x, this->y) \
    , wxxz(this->w, this->x, this->x, this->z) \
    , wxxw(this->w, this->x, this->x, this->w) \
    , wxyx(this->w, this->x, this->y, this->x) \
    , wxyy(this->w, this->x, this->y, this->y) \
    , wxyz(this->w, this->x, this->y, this->z) \
    , wxyw(this->w, this->x, this->y, this->w) \
    , wxzx(this->w, this->x, this->z, this->x) \
    , wxzy(this->w, this->x, this->z, this->y) \
    , wxzz(this->w, this->x, this->z, this->z) \
    , wxzw(this->w, this->x, this->z, this->w) \
    , wxwx(this->w, this->x, this->w, this->x) \
    , wxwy(this->w, this->x, this->w, this->y) \
    , wxwz(this->w, this->x, this->w, this->z) \
    , wxww(this->w, this->x, this->w, this->w) \
    , wyxx(this->w, this->y, this->x, this->x) \
    , wyxy(this->w, this->y, this->x, this->y) \
    , wyxz(this->w, this->y, this->x, this->z) \
    , wyxw(this->w, this->y, this->x, this->w) \
    , wyyx(this->w, this->y, this->y, this->x) \
    , wyyy(this->w, this->y, this->y, this->y) \
    , wyyz(this->w, this->y, this->y, this->z) \
    , wyyw(this->w, this->y, this->y, this->w) \
    , wyzx(this->w, this->y, this->z, this->x) \
    , wyzy(this->w, this->y, this->z, this->y) \
    , wyzz(this->w, this->y, this->z, this->z) \
    , wyzw(this->w, this->y, this->z, this->w) \
    , wywx(this->w, this->y, this->w, this->x) \
    , wywy(this->w, this->y, this->w, this->y) \
    , wywz(this->w, this->y, this->w, this->z) \
    , wyww(this->w, this->y, this->w, this->w) \
    , wzxx(this->w, this->z, this->x, this->x) \
    , wzxy(this->w, this->z, this->x, this->y) \
    , wzxz(this->w, this->z, this->x, this->z) \
    , wzxw(this->w, this->z, this->x, this->w) \
    , wzyx(this->w, this->z, this->y, this->x) \
    , wzyy(this->w, this->z, this->y, this->y) \
    , wzyz(this->w, this->z, this->y, this->z) \
    , wzyw(this->w, this->z, this->y, this->w) \
    , wzzx(this->w, this->z, this->z, this->x) \
    , wzzy(this->w, this->z, this->z, this->y) \
    , wzzz(this->w, this->z, this->z, this->z) \
    , wzzw(this->w, this->z, this->z, this->w) \
    , wzwx(this->w, this->z, this->w, this->x) \
    , wzwy(this->w, this->z, this->w, this->y) \
    , wzwz(this->w, this->z, this->w, this->z) \
    , wzww(this->w, this->z, this->w, this->w) \
    , wwxx(this->w, this->w, this->x, this->x) \
    , wwxy(this->w, this->w, this->x, this->y) \
    , wwxz(this->w, this->w, this->x, this->z) \
    , wwxw(this->w, this->w, this->x, this->w) \
    , wwyx(this->w, this->w, this->y, this->x) \
    , wwyy(this->w, this->w, this->y, this->y) \
    , wwyz(this->w, this->w, this->y, this->z) \
    , wwyw(this->w, this->w, this->y, this->w) \
    , wwzx(this->w, this->w, this->z, this->x) \
    , wwzy(this->w, this->w, this->z, this->y) \
    , wwzz(this->w, this->w, this->z, this->z) \
    , wwzw(this->w, this->w, this->z, this->w) \
    , wwwx(this->w, this->w, this->w, this->x) \
    , wwwy(this->w, this->w, this->w, this->y) \
    , wwwz(this->w, this->w, this->w, this->z) \
    , wwww(this->w, this->w, this->w, this->w) \
    , rrrr(this->x, this->x, this->x, this->x) \
    , rrrg(this->x, this->x, this->x, this->y) \
    , rrrb(this->x, this->x, this->x, this->z) \
    , rrra(this->x, this->x, this->x, this->w) \
    , rrgr(this->x, this->x, this->y, this->x) \
    , rrgg(this->x, this->x, this->y, this->y) \
    , rrgb(this->x, this->x, this->y, this->z) \
    , rrga(this->x, this->x, this->y, this->w) \
    , rrbr(this->x, this->x, this->z, this->x) \
    , rrbg(this->x, this->x, this->z, this->y) \
    , rrbb(this->x, this->x, this->z, this->z) \
    , rrba(this->x, this->x, this->z, this->w) \
    , rrar(this->x, this->x, this->w, this->x) \
    , rrag(this->x, this->x, this->w, this->y) \
    , rrab(this->x, this->x, this->w, this->z) \
    , rraa(this->x, this->x, this->w, this->w) \
    , rgrr(this->x, this->y, this->x, this->x) \
    , rgrg(this->x, this->y, this->x, this->y) \
    , rgrb(this->x, this->y, this->x, this->z) \
    , rgra(this->x, this->y, this->x, this->w) \
    , rggr(this->x, this->y, this->y, this->x) \
    , rggg(this->x, this->y, this->y, this->y) \
    , rggb(this->x, this->y, this->y, this->z) \
    , rgga(this->x, this->y, this->y, this->w) \
    , rgbr(this->x, this->y, this->z, this->x) \
    , rgbg(this->x, this->y, this->z, this->y) \
    , rgbb(this->x, this->y, this->z, this->z) \
    , rgba(this->x, this->y, this->z, this->w) \
    , rgar(this->x, this->y, this->w, this->x) \
    , rgag(this->x, this->y, this->w, this->y) \
    , rgab(this->x, this->y, this->w, this->z) \
    , rgaa(this->x, this->y, this->w, this->w) \
    , rbrr(this->x, this->z, this->x, this->x) \
    , rbrg(this->x, this->z, this->x, this->y) \
    , rbrb(this->x, this->z, this->x, this->z) \
    , rbra(this->x, this->z, this->x, this->w) \
    , rbgr(this->x, this->z, this->y, this->x) \
    , rbgg(this->x, this->z, this->y, this->y) \
    , rbgb(this->x, this->z, this->y, this->z) \
    , rbga(this->x, this->z, this->y, this->w) \
    , rbbr(this->x, this->z, this->z, this->x) \
    , rbbg(this->x, this->z, this->z, this->y) \
    , rbbb(this->x, this->z, this->z, this->z) \
    , rbba(this->x, this->z, this->z, this->w) \
    , rbar(this->x, this->z, this->w, this->x) \
    , rbag(this->x, this->z, this->w, this->y) \
    , rbab(this->x, this->z, this->w, this->z) \
    , rbaa(this->x, this->z, this->w, this->w) \
    , rarr(this->x, this->w, this->x, this->x) \
    , rarg(this->x, this->w, this->x, this->y) \
    , rarb(this->x, this->w, this->x, this->z) \
    , rara(this->x, this->w, this->x, this->w) \
    , ragr(this->x, this->w, this->y, this->x) \
    , ragg(this->x, this->w, this->y, this->y) \
    , ragb(this->x, this->w, this->y, this->z) \
    , raga(this->x, this->w, this->y, this->w) \
    , rabr(this->x, this->w, this->z, this->x) \
    , rabg(this->x, this->w, this->z, this->y) \
    , rabb(this->x, this->w, this->z, this->z) \
    , raba(this->x, this->w, this->z, this->w) \
    , raar(this->x, this->w, this->w, this->x) \
    , raag(this->x, this->w, this->w, this->y) \
    , raab(this->x, this->w, this->w, this->z) \
    , raaa(this->x, this->w, this->w, this->w) \
    , grrr(this->y, this->x, this->x, this->x) \
    , grrg(this->y, this->x, this->x, this->y) \
    , grrb(this->y, this->x, this->x, this->z) \
    , grra(this->y, this->x, this->x, this->w) \
    , grgr(this->y, this->x, this->y, this->x) \
    , grgg(this->y, this->x, this->y, this->y) \
    , grgb(this->y, this->x, this->y, this->z) \
    , grga(this->y, this->x, this->y, this->w) \
    , grbr(this->y, this->x, this->z, this->x) \
    , grbg(this->y, this->x, this->z, this->y) \
    , grbb(this->y, this->x, this->z, this->z) \
    , grba(this->y, this->x, this->z, this->w) \
    , grar(this->y, this->x, this->w, this->x) \
    , grag(this->y, this->x, this->w, this->y) \
    , grab(this->y, this->x, this->w, this->z) \
    , graa(this->y, this->x, this->w, this->w) \
    , ggrr(this->y, this->y, this->x, this->x) \
    , ggrg(this->y, this->y, this->x, this->y) \
    , ggrb(this->y, this->y, this->x, this->z) \
    , ggra(this->y, this->y, this->x, this->w) \
    , gggr(this->y, this->y, this->y, this->x) \
    , gggg(this->y, this->y, this->y, this->y) \
    , gggb(this->y, this->y, this->y, this->z) \
    , ggga(this->y, this->y, this->y, this->w) \
    , ggbr(this->y, this->y, this->z, this->x) \
    , ggbg(this->y, this->y, this->z, this->y) \
    , ggbb(this->y, this->y, this->z, this->z) \
    , ggba(this->y, this->y, this->z, this->w) \
    , ggar(this->y, this->y, this->w, this->x) \
    , ggag(this->y, this->y, this->w, this->y) \
    , ggab(this->y, this->y, this->w, this->z) \
    , ggaa(this->y, this->y, this->w, this->w) \
    , gbrr(this->y, this->z, this->x, this->x) \
    , gbrg(this->y, this->z, this->x, this->y) \
    , gbrb(this->y, this->z, this->x, this->z) \
    , gbra(this->y, this->z, this->x, this->w) \
    , gbgr(this->y, this->z, this->y, this->x) \
    , gbgg(this->y, this->z, this->y, this->y) \
    , gbgb(this->y, this->z, this->y, this->z) \
    , gbga(this->y, this->z, this->y, this->w) \
    , gbbr(this->y, this->z, this->z, this->x) \
    , gbbg(this->y, this->z, this->z, this->y) \
    , gbbb(this->y, this->z, this->z, this->z) \
    , gbba(this->y, this->z, this->z, this->w) \
    , gbar(this->y, this->z, this->w, this->x) \
    , gbag(this->y, this->z, this->w, this->y) \
    , gbab(this->y, this->z, this->w, this->z) \
    , gbaa(this->y, this->z, this->w, this->w) \
    , garr(this->y, this->w, this->x, this->x) \
    , garg(this->y, this->w, this->x, this->y) \
    , garb(this->y, this->w, this->x, this->z) \
    , gara(this->y, this->w, this->x, this->w) \
    , gagr(this->y, this->w, this->y, this->x) \
    , gagg(this->y, this->w, this->y, this->y) \
    , gagb(this->y, this->w, this->y, this->z) \
    , gaga(this->y, this->w, this->y, this->w) \
    , gabr(this->y, this->w, this->z, this->x) \
    , gabg(this->y, this->w, this->z, this->y) \
    , gabb(this->y, this->w, this->z, this->z) \
    , gaba(this->y, this->w, this->z, this->w) \
    , gaar(this->y, this->w, this->w, this->x) \
    , gaag(this->y, this->w, this->w, this->y) \
    , gaab(this->y, this->w, this->w, this->z) \
    , gaaa(this->y, this->w, this->w, this->w) \
    , brrr(this->z, this->x, this->x, this->x) \
    , brrg(this->z, this->x, this->x, this->y) \
    , brrb(this->z, this->x, this->x, this->z) \
    , brra(this->z, this->x, this->x, this->w) \
    , brgr(this->z, this->x, this->y, this->x) \
    , brgg(this->z, this->x, this->y, this->y) \
    , brgb(this->z, this->x, this->y, this->z) \
    , brga(this->z, this->x, this->y, this->w) \
    , brbr(this->z, this->x, this->z, this->x) \
    , brbg(this->z, this->x, this->z, this->y) \
    , brbb(this->z, this->x, this->z, this->z) \
    , brba(this->z, this->x, this->z, this->w) \
    , brar(this->z, this->x, this->w, this->x) \
    , brag(this->z, this->x, this->w, this->y) \
    , brab(this->z, this->x, this->w, this->z) \
    , braa(this->z, this->x, this->w, this->w) \
    , bgrr(this->z, this->y, this->x, this->x) \
    , bgrg(this->z, this->y, this->x, this->y) \
    , bgrb(this->z, this->y, this->x, this->z) \
    , bgra(this->z, this->y, this->x, this->w) \
    , bggr(this->z, this->y, this->y, this->x) \
    , bggg(this->z, this->y, this->y, this->y) \
    , bggb(this->z, this->y, this->y, this->z) \
    , bgga(this->z, this->y, this->y, this->w) \
    , bgbr(this->z, this->y, this->z, this->x) \
    , bgbg(this->z, this->y, this->z, this->y) \
    , bgbb(this->z, this->y, this->z, this->z) \
    , bgba(this->z, this->y, this->z, this->w) \
    , bgar(this->z, this->y, this->w, this->x) \
    , bgag(this->z, this->y, this->w, this->y) \
    , bgab(this->z, this->y, this->w, this->z) \
    , bgaa(this->z, this->y, this->w, this->w) \
    , bbrr(this->z, this->z, this->x, this->x) \
    , bbrg(this->z, this->z, this->x, this->y) \
    , bbrb(this->z, this->z, this->x, this->z) \
    , bbra(this->z, this->z, this->x, this->w) \
    , bbgr(this->z, this->z, this->y, this->x) \
    , bbgg(this->z, this->z, this->y, this->y) \
    , bbgb(this->z, this->z, this->y, this->z) \
    , bbga(this->z, this->z, this->y, this->w) \
    , bbbr(this->z, this->z, this->z, this->x) \
    , bbbg(this->z, this->z, this->z, this->y) \
    , bbbb(this->z, this->z, this->z, this->z) \
    , bbba(this->z, this->z, this->z, this->w) \
    , bbar(this->z, this->z, this->w, this->x) \
    , bbag(this->z, this->z, this->w, this->y) \
    , bbab(this->z, this->z, this->w, this->z) \
    , bbaa(this->z, this->z, this->w, this->w) \
    , barr(this->z, this->w, this->x, this->x) \
    , barg(this->z, this->w, this->x, this->y) \
    , barb(this->z, this->w, this->x, this->z) \
    , bara(this->z, this->w, this->x, this->w) \
    , bagr(this->z, this->w, this->y, this->x) \
    , bagg(this->z, this->w, this->y, this->y) \
    , bagb(this->z, this->w, this->y, this->z) \
    , baga(this->z, this->w, this->y, this->w) \
    , babr(this->z, this->w, this->z, this->x) \
    , babg(this->z, this->w, this->z, this->y) \
    , babb(this->z, this->w, this->z, this->z) \
    , baba(this->z, this->w, this->z, this->w) \
    , baar(this->z, this->w, this->w, this->x) \
    , baag(this->z, this->w, this->w, this->y) \
    , baab(this->z, this->w, this->w, this->z) \
    , baaa(this->z, this->w, this->w, this->w) \
    , arrr(this->w, this->x, this->x, this->x) \
    , arrg(this->w, this->x, this->x, this->y) \
    , arrb(this->w, this->x, this->x, this->z) \
    , arra(this->w, this->x, this->x, this->w) \
    , argr(this->w, this->x, this->y, this->x) \
    , argg(this->w, this->x, this->y, this->y) \
    , argb(this->w, this->x, this->y, this->z) \
    , arga(this->w, this->x, this->y, this->w) \
    , arbr(this->w, this->x, this->z, this->x) \
    , arbg(this->w, this->x, this->z, this->y) \
    , arbb(this->w, this->x, this->z, this->z) \
    , arba(this->w, this->x, this->z, this->w) \
    , arar(this->w, this->x, this->w, this->x) \
    , arag(this->w, this->x, this->w, this->y) \
    , arab(this->w, this->x, this->w, this->z) \
    , araa(this->w, this->x, this->w, this->w) \
    , agrr(this->w, this->y, this->x, this->x) \
    , agrg(this->w, this->y, this->x, this->y) \
    , agrb(this->w, this->y, this->x, this->z) \
    , agra(this->w, this->y, this->x, this->w) \
    , aggr(this->w, this->y, this->y, this->x) \
    , aggg(this->w, this->y, this->y, this->y) \
    , aggb(this->w, this->y, this->y, this->z) \
    , agga(this->w, this->y, this->y, this->w) \
    , agbr(this->w, this->y, this->z, this->x) \
    , agbg(this->w, this->y, this->z, this->y) \
    , agbb(this->w, this->y, this->z, this->z) \
    , agba(this->w, this->y, this->z, this->w) \
    , agar(this->w, this->y, this->w, this->x) \
    , agag(this->w, this->y, this->w, this->y) \
    , agab(this->w, this->y, this->w, this->z) \
    , agaa(this->w, this->y, this->w, this->w) \
    , abrr(this->w, this->z, this->x, this->x) \
    , abrg(this->w, this->z, this->x, this->y) \
    , abrb(this->w, this->z, this->x, this->z) \
    , abra(this->w, this->z, this->x, this->w) \
    , abgr(this->w, this->z, this->y, this->x) \
    , abgg(this->w, this->z, this->y, this->y) \
    , abgb(this->w, this->z, this->y, this->z) \
    , abga(this->w, this->z, this->y, this->w) \
    , abbr(this->w, this->z, this->z, this->x) \
    , abbg(this->w, this->z, this->z, this->y) \
    , abbb(this->w, this->z, this->z, this->z) \
    , abba(this->w, this->z, this->z, this->w) \
    , abar(this->w, this->z, this->w, this->x) \
    , abag(this->w, this->z, this->w, this->y) \
    , abab(this->w, this->z, this->w, this->z) \
    , abaa(this->w, this->z, this->w, this->w) \
    , aarr(this->w, this->w, this->x, this->x) \
    , aarg(this->w, this->w, this->x, this->y) \
    , aarb(this->w, this->w, this->x, this->z) \
    , aara(this->w, this->w, this->x, this->w) \
    , aagr(this->w, this->w, this->y, this->x) \
    , aagg(this->w, this->w, this->y, this->y) \
    , aagb(this->w, this->w, this->y, this->z) \
    , aaga(this->w, this->w, this->y, this->w) \
    , aabr(this->w, this->w, this->z, this->x) \
    , aabg(this->w, this->w, this->z, this->y) \
    , aabb(this->w, this->w, this->z, this->z) \
    , aaba(this->w, this->w, this->z, this->w) \
    , aaar(this->w, this->w, this->w, this->x) \
    , aaag(this->w, this->w, this->w, this->y) \
    , aaab(this->w, this->w, this->w, this->z) \
    , aaaa(this->w, this->w, this->w, this->w) \
    , ssss(this->x, this->x, this->x, this->x) \
    , ssst(this->x, this->x, this->x, this->y) \
    , sssp(this->x, this->x, this->x, this->z) \
    , sssq(this->x, this->x, this->x, this->w) \
    , ssts(this->x, this->x, this->y, this->x) \
    , sstt(this->x, this->x, this->y, this->y) \
    , sstp(this->x, this->x, this->y, this->z) \
    , sstq(this->x, this->x, this->y, this->w) \
    , ssps(this->x, this->x, this->z, this->x) \
    , sspt(this->x, this->x, this->z, this->y) \
    , sspp(this->x, this->x, this->z, this->z) \
    , sspq(this->x, this->x, this->z, this->w) \
    , ssqs(this->x, this->x, this->w, this->x) \
    , ssqt(this->x, this->x, this->w, this->y) \
    , ssqp(this->x, this->x, this->w, this->z) \
    , ssqq(this->x, this->x, this->w, this->w) \
    , stss(this->x, this->y, this->x, this->x) \
    , stst(this->x, this->y, this->x, this->y) \
    , stsp(this->x, this->y, this->x, this->z) \
    , stsq(this->x, this->y, this->x, this->w) \
    , stts(this->x, this->y, this->y, this->x) \
    , sttt(this->x, this->y, this->y, this->y) \
    , sttp(this->x, this->y, this->y, this->z) \
    , sttq(this->x, this->y, this->y, this->w) \
    , stps(this->x, this->y, this->z, this->x) \
    , stpt(this->x, this->y, this->z, this->y) \
    , stpp(this->x, this->y, this->z, this->z) \
    , stpq(this->x, this->y, this->z, this->w) \
    , stqs(this->x, this->y, this->w, this->x) \
    , stqt(this->x, this->y, this->w, this->y) \
    , stqp(this->x, this->y, this->w, this->z) \
    , stqq(this->x, this->y, this->w, this->w) \
    , spss(this->x, this->z, this->x, this->x) \
    , spst(this->x, this->z, this->x, this->y) \
    , spsp(this->x, this->z, this->x, this->z) \
    , spsq(this->x, this->z, this->x, this->w) \
    , spts(this->x, this->z, this->y, this->x) \
    , sptt(this->x, this->z, this->y, this->y) \
    , sptp(this->x, this->z, this->y, this->z) \
    , sptq(this->x, this->z, this->y, this->w) \
    , spps(this->x, this->z, this->z, this->x) \
    , sppt(this->x, this->z, this->z, this->y) \
    , sppp(this->x, this->z, this->z, this->z) \
    , sppq(this->x, this->z, this->z, this->w) \
    , spqs(this->x, this->z, this->w, this->x) \
    , spqt(this->x, this->z, this->w, this->y) \
    , spqp(this->x, this->z, this->w, this->z) \
    , spqq(this->x, this->z, this->w, this->w) \
    , sqss(this->x, this->w, this->x, this->x) \
    , sqst(this->x, this->w, this->x, this->y) \
    , sqsp(this->x, this->w, this->x, this->z) \
    , sqsq(this->x, this->w, this->x, this->w) \
    , sqts(this->x, this->w, this->y, this->x) \
    , sqtt(this->x, this->w, this->y, this->y) \
    , sqtp(this->x, this->w, this->y, this->z) \
    , sqtq(this->x, this->w, this->y, this->w) \
    , sqps(this->x, this->w, this->z, this->x) \
    , sqpt(this->x, this->w, this->z, this->y) \
    , sqpp(this->x, this->w, this->z, this->z) \
    , sqpq(this->x, this->w, this->z, this->w) \
    , sqqs(this->x, this->w, this->w, this->x) \
    , sqqt(this->x, this->w, this->w, this->y) \
    , sqqp(this->x, this->w, this->w, this->z) \
    , sqqq(this->x, this->w, this->w, this->w) \
    , tsss(this->y, this->x, this->x, this->x) \
    , tsst(this->y, this->x, this->x, this->y) \
    , tssp(this->y, this->x, this->x, this->z) \
    , tssq(this->y, this->x, this->x, this->w) \
    , tsts(this->y, this->x, this->y, this->x) \
    , tstt(this->y, this->x, this->y, this->y) \
    , tstp(this->y, this->x, this->y, this->z) \
    , tstq(this->y, this->x, this->y, this->w) \
    , tsps(this->y, this->x, this->z, this->x) \
    , tspt(this->y, this->x, this->z, this->y) \
    , tspp(this->y, this->x, this->z, this->z) \
    , tspq(this->y, this->x, this->z, this->w) \
    , tsqs(this->y, this->x, this->w, this->x) \
    , tsqt(this->y, this->x, this->w, this->y) \
    , tsqp(this->y, this->x, this->w, this->z) \
    , tsqq(this->y, this->x, this->w, this->w) \
    , ttss(this->y, this->y, this->x, this->x) \
    , ttst(this->y, this->y, this->x, this->y) \
    , ttsp(this->y, this->y, this->x, this->z) \
    , ttsq(this->y, this->y, this->x, this->w) \
    , ttts(this->y, this->y, this->y, this->x) \
    , tttt(this->y, this->y, this->y, this->y) \
    , tttp(this->y, this->y, this->y, this->z) \
    , tttq(this->y, this->y, this->y, this->w) \
    , ttps(this->y, this->y, this->z, this->x) \
    , ttpt(this->y, this->y, this->z, this->y) \
    , ttpp(this->y, this->y, this->z, this->z) \
    , ttpq(this->y, this->y, this->z, this->w) \
    , ttqs(this->y, this->y, this->w, this->x) \
    , ttqt(this->y, this->y, this->w, this->y) \
    , ttqp(this->y, this->y, this->w, this->z) \
    , ttqq(this->y, this->y, this->w, this->w) \
    , tpss(this->y, this->z, this->x, this->x) \
    , tpst(this->y, this->z, this->x, this->y) \
    , tpsp(this->y, this->z, this->x, this->z) \
    , tpsq(this->y, this->z, this->x, this->w) \
    , tpts(this->y, this->z, this->y, this->x) \
    , tptt(this->y, this->z, this->y, this->y) \
    , tptp(this->y, this->z, this->y, this->z) \
    , tptq(this->y, this->z, this->y, this->w) \
    , tpps(this->y, this->z, this->z, this->x) \
    , tppt(this->y, this->z, this->z, this->y) \
    , tppp(this->y, this->z, this->z, this->z) \
    , tppq(this->y, this->z, this->z, this->w) \
    , tpqs(this->y, this->z, this->w, this->x) \
    , tpqt(this->y, this->z, this->w, this->y) \
    , tpqp(this->y, this->z, this->w, this->z) \
    , tpqq(this->y, this->z, this->w, this->w) \
    , tqss(this->y, this->w, this->x, this->x) \
    , tqst(this->y, this->w, this->x, this->y) \
    , tqsp(this->y, this->w, this->x, this->z) \
    , tqsq(this->y, this->w, this->x, this->w) \
    , tqts(this->y, this->w, this->y, this->x) \
    , tqtt(this->y, this->w, this->y, this->y) \
    , tqtp(this->y, this->w, this->y, this->z) \
    , tqtq(this->y, this->w, this->y, this->w) \
    , tqps(this->y, this->w, this->z, this->x) \
    , tqpt(this->y, this->w, this->z, this->y) \
    , tqpp(this->y, this->w, this->z, this->z) \
    , tqpq(this->y, this->w, this->z, this->w) \
    , tqqs(this->y, this->w, this->w, this->x) \
    , tqqt(this->y, this->w, this->w, this->y) \
    , tqqp(this->y, this->w, this->w, this->z) \
    , tqqq(this->y, this->w, this->w, this->w) \
    , psss(this->z, this->x, this->x, this->x) \
    , psst(this->z, this->x, this->x, this->y) \
    , pssp(this->z, this->x, this->x, this->z) \
    , pssq(this->z, this->x, this->x, this->w) \
    , psts(this->z, this->x, this->y, this->x) \
    , pstt(this->z, this->x, this->y, this->y) \
    , pstp(this->z, this->x, this->y, this->z) \
    , pstq(this->z, this->x, this->y, this->w) \
    , psps(this->z, this->x, this->z, this->x) \
    , pspt(this->z, this->x, this->z, this->y) \
    , pspp(this->z, this->x, this->z, this->z) \
    , pspq(this->z, this->x, this->z, this->w) \
    , psqs(this->z, this->x, this->w, this->x) \
    , psqt(this->z, this->x, this->w, this->y) \
    , psqp(this->z, this->x, this->w, this->z) \
    , psqq(this->z, this->x, this->w, this->w) \
    , ptss(this->z, this->y, this->x, this->x) \
    , ptst(this->z, this->y, this->x, this->y) \
    , ptsp(this->z, this->y, this->x, this->z) \
    , ptsq(this->z, this->y, this->x, this->w) \
    , ptts(this->z, this->y, this->y, this->x) \
    , pttt(this->z, this->y, this->y, this->y) \
    , pttp(this->z, this->y, this->y, this->z) \
    , pttq(this->z, this->y, this->y, this->w) \
    , ptps(this->z, this->y, this->z, this->x) \
    , ptpt(this->z, this->y, this->z, this->y) \
    , ptpp(this->z, this->y, this->z, this->z) \
    , ptpq(this->z, this->y, this->z, this->w) \
    , ptqs(this->z, this->y, this->w, this->x) \
    , ptqt(this->z, this->y, this->w, this->y) \
    , ptqp(this->z, this->y, this->w, this->z) \
    , ptqq(this->z, this->y, this->w, this->w) \
    , ppss(this->z, this->z, this->x, this->x) \
    , ppst(this->z, this->z, this->x, this->y) \
    , ppsp(this->z, this->z, this->x, this->z) \
    , ppsq(this->z, this->z, this->x, this->w) \
    , ppts(this->z, this->z, this->y, this->x) \
    , pptt(this->z, this->z, this->y, this->y) \
    , pptp(this->z, this->z, this->y, this->z) \
    , pptq(this->z, this->z, this->y, this->w) \
    , ppps(this->z, this->z, this->z, this->x) \
    , pppt(this->z, this->z, this->z, this->y) \
    , pppp(this->z, this->z, this->z, this->z) \
    , pppq(this->z, this->z, this->z, this->w) \
    , ppqs(this->z, this->z, this->w, this->x) \
    , ppqt(this->z, this->z, this->w, this->y) \
    , ppqp(this->z, this->z, this->w, this->z) \
    , ppqq(this->z, this->z, this->w, this->w) \
    , pqss(this->z, this->w, this->x, this->x) \
    , pqst(this->z, this->w, this->x, this->y) \
    , pqsp(this->z, this->w, this->x, this->z) \
    , pqsq(this->z, this->w, this->x, this->w) \
    , pqts(this->z, this->w, this->y, this->x) \
    , pqtt(this->z, this->w, this->y, this->y) \
    , pqtp(this->z, this->w, this->y, this->z) \
    , pqtq(this->z, this->w, this->y, this->w) \
    , pqps(this->z, this->w, this->z, this->x) \
    , pqpt(this->z, this->w, this->z, this->y) \
    , pqpp(this->z, this->w, this->z, this->z) \
    , pqpq(this->z, this->w, this->z, this->w) \
    , pqqs(this->z, this->w, this->w, this->x) \
    , pqqt(this->z, this->w, this->w, this->y) \
    , pqqp(this->z, this->w, this->w, this->z) \
    , pqqq(this->z, this->w, this->w, this->w) \
    , qsss(this->w, this->x, this->x, this->x) \
    , qsst(this->w, this->x, this->x, this->y) \
    , qssp(this->w, this->x, this->x, this->z) \
    , qssq(this->w, this->x, this->x, this->w) \
    , qsts(this->w, this->x, this->y, this->x) \
    , qstt(this->w, this->x, this->y, this->y) \
    , qstp(this->w, this->x, this->y, this->z) \
    , qstq(this->w, this->x, this->y, this->w) \
    , qsps(this->w, this->x, this->z, this->x) \
    , qspt(this->w, this->x, this->z, this->y) \
    , qspp(this->w, this->x, this->z, this->z) \
    , qspq(this->w, this->x, this->z, this->w) \
    , qsqs(this->w, this->x, this->w, this->x) \
    , qsqt(this->w, this->x, this->w, this->y) \
    , qsqp(this->w, this->x, this->w, this->z) \
    , qsqq(this->w, this->x, this->w, this->w) \
    , qtss(this->w, this->y, this->x, this->x) \
    , qtst(this->w, this->y, this->x, this->y) \
    , qtsp(this->w, this->y, this->x, this->z) \
    , qtsq(this->w, this->y, this->x, this->w) \
    , qtts(this->w, this->y, this->y, this->x) \
    , qttt(this->w, this->y, this->y, this->y) \
    , qttp(this->w, this->y, this->y, this->z) \
    , qttq(this->w, this->y, this->y, this->w) \
    , qtps(this->w, this->y, this->z, this->x) \
    , qtpt(this->w, this->y, this->z, this->y) \
    , qtpp(this->w, this->y, this->z, this->z) \
    , qtpq(this->w, this->y, this->z, this->w) \
    , qtqs(this->w, this->y, this->w, this->x) \
    , qtqt(this->w, this->y, this->w, this->y) \
    , qtqp(this->w, this->y, this->w, this->z) \
    , qtqq(this->w, this->y, this->w, this->w) \
    , qpss(this->w, this->z, this->x, this->x) \
    , qpst(this->w, this->z, this->x, this->y) \
    , qpsp(this->w, this->z, this->x, this->z) \
    , qpsq(this->w, this->z, this->x, this->w) \
    , qpts(this->w, this->z, this->y, this->x) \
    , qptt(this->w, this->z, this->y, this->y) \
    , qptp(this->w, this->z, this->y, this->z) \
    , qptq(this->w, this->z, this->y, this->w) \
    , qpps(this->w, this->z, this->z, this->x) \
    , qppt(this->w, this->z, this->z, this->y) \
    , qppp(this->w, this->z, this->z, this->z) \
    , qppq(this->w, this->z, this->z, this->w) \
    , qpqs(this->w, this->z, this->w, this->x) \
    , qpqt(this->w, this->z, this->w, this->y) \
    , qpqp(this->w, this->z, this->w, this->z) \
    , qpqq(this->w, this->z, this->w, this->w) \
    , qqss(this->w, this->w, this->x, this->x) \
    , qqst(this->w, this->w, this->x, this->y) \
    , qqsp(this->w, this->w, this->x, this->z) \
    , qqsq(this->w, this->w, this->x, this->w) \
    , qqts(this->w, this->w, this->y, this->x) \
    , qqtt(this->w, this->w, this->y, this->y) \
    , qqtp(this->w, this->w, this->y, this->z) \
    , qqtq(this->w, this->w, this->y, this->w) \
    , qqps(this->w, this->w, this->z, this->x) \
    , qqpt(this->w, this->w, this->z, this->y) \
    , qqpp(this->w, this->w, this->z, this->z) \
    , qqpq(this->w, this->w, this->z, this->w) \
    , qqqs(this->w, this->w, this->w, this->x) \
    , qqqt(this->w, this->w, this->w, this->y) \
    , qqqp(this->w, this->w, this->w, this->z) \
    , qqqq(this->w, this->w, this->w, this->w)
#endif  // GLSLIKE_DISABLE_SWIZZLE


template <typename T>
class Vector4 : public Vector4Core<T> {
public:
    typedef Vector4Core<T> Base_t;
    typedef T Type_t;
    using Vector4Core<T>::Vector4Core;
    using Vector4Core<T>::x;
    using Vector4Core<T>::y;
    using Vector4Core<T>::z;
    using Vector4Core<T>::w;

public:
    explicit Vector4(T x)
        : Vector4Core<T>::Vector4Core(x)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(T x, T y, T z, T w)
        : Vector4Core<T>::Vector4Core(x, y, z, w)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(const Vector2<T> &xy, T z, T w)
        : Vector4Core<T>::Vector4Core(xy.x, xy.y, z, w)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(T x, const Vector2<T> &yz, T w)
        : Vector4Core<T>::Vector4Core(x, yz.x, yz.y, w)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(T x, T y, const Vector2<T> &zw)
        : Vector4Core<T>::Vector4Core(x, y, zw.x, zw.y)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(const Vector2<T> &xy, const Vector2<T> &zw)
        : Vector4Core<T>::Vector4Core(xy.x, xy.y, zw.x, zw.y)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(const Vector3<T> &xyz, T w)
        : Vector4Core<T>::Vector4Core(xyz.x, xyz.y, xyz.z, w)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
    Vector4(T x, const Vector3<T> &yzw)
        : Vector4Core<T>::Vector4Core(x, yzw.x, yzw.y, yzw.z)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}

    Vector4(const Vector4<T> &copy)
        : Vector4Core<T>::Vector4Core(copy)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}

    Vector4(Vector4<T> &&move)
        : Vector4Core<T>::Vector4Core(move)
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}

#ifndef GLSLIKE_DISABLE_SWIZZLE
    template <typename SwizzleT, typename std::enable_if<std::is_convertible<SwizzleT, Vector4Core<T>>::value>::type * = nullptr>
    Vector4(const SwizzleT &core)
        : Vector4Core<T>::Vector4Core(static_cast<Vector4Core<T>>(core))
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}
#endif  // GLSLIKE_DISABLE_SWIZZLE

    T operator [](int i) const {
        switch (i) {
        case 0:
            return x;
        case 1:
            return y;
        case 2:
            return z;
        case 3:
            return w;
        default:
            throw std::out_of_range("index out of range");
        }
    }

    Vector4<T> clone() const {
        return Vector4<T>(x, y, z, w);
    }

    Vector4<T> &copy(const Vector4<T> &vec) {
        x = vec.x;
        y = vec.y;
        z = vec.z;
        w = vec.w;
        return *this;
    }

    Vector4<T> &set(T fXVal, T fYVal, T fZVal, T fWVal) {
        x = fXVal;
        y = fYVal;
        z = fZVal;
        w = fWVal;
        return *this;
    }

    Vector4<T> &add(const Vector4<T> &vec) {
        x += vec.x;
        y += vec.y;
        z += vec.z;
        w += vec.w;
        return *this;
    }

    Vector4<T> &addScalar(T scalar) {
        x += scalar;
        y += scalar;
        z += scalar;
        w += scalar;
        return *this;
    }

    Vector4<T> &multiplyScalar(T scalar) {
        x *= scalar;
        y *= scalar;
        z *= scalar;
        w *= scalar;
        return *this;
    }

    Vector4<T> &divideScalar(T scalar) {
        x /= scalar;
        y /= scalar;
        z /= scalar;
        w /= scalar;
        return *this;
    }

    Vector4<T> normalize() {
        const auto len = length();
        //assert(len != 0.0f);
        return divideScalar(len);
    }

    T length() const {
        return glslike::math<T>::sqrt(x * x + y * y + z * z + w * w);
    }

    T dot(const Vector4<T> &vec) const {
        return x * vec.x + y * vec.y + z * vec.z + w * vec.w;
    }

    std::array<T, 4> toArray() const {
        return {x, y, z, w};
    }

    //
    // glsl-like interface
    //

    Vector4<T> operator +() const {
        return Vector4<T>(
            +x,
            +y,
            +z,
            +w
        );
    }

    Vector4<T> operator -() const {
        return Vector4<T>(
            -x,
            -y,
            -z,
            -w
        );
    }

    Vector4<T> operator +(T rhs) const {
        return Vector4<T>(
            x + rhs,
            y + rhs,
            z + rhs,
            w + rhs
        );
    }
    Vector4<T> &operator +=(T rhs) {
        x += rhs;
        y += rhs;
        z += rhs;
        w += rhs;
        return *this;
    }
    Vector4<T> operator +(const Vector4<T> &rhs) const {
        return Vector4<T>(
            x + rhs.x,
            y + rhs.y,
            z + rhs.z,
            w + rhs.w
        );
    }
    Vector4<T> &operator +=(const Vector4<T> &rhs) {
        x += rhs.x;
        y += rhs.y;
        z += rhs.z;
        w += rhs.w;
        return *this;
    }
    Vector4<T> operator -(T rhs) const {
        return Vector4<T>(
            x - rhs,
            y - rhs,
            z - rhs,
            w - rhs
        );
    }
    Vector4<T> &operator -=(T rhs) {
        x -= rhs;
        y -= rhs;
        z -= rhs;
        w -= rhs;
        return *this;
    }
    Vector4<T> operator -(const Vector4<T> &rhs) const {
        return Vector4<T>(
            x - rhs.x,
            y - rhs.y,
            z - rhs.z,
            w - rhs.w
        );
    }
    Vector4<T> &operator -=(const Vector4<T> &rhs) {
        x -= rhs.x;
        y -= rhs.y;
        z -= rhs.z;
        w -= rhs.w;
        return *this;
    }
    Vector4<T> operator *(T rhs) const {
        return Vector4<T>(
            x * rhs,
            y * rhs,
            z * rhs,
            w * rhs
        );
    }
    Vector4<T> &operator *=(T rhs) {
        x *= rhs;
        y *= rhs;
        z *= rhs;
        w *= rhs;
        return *this;
    }
    Vector4<T> operator *(const Vector4<T> &rhs) const {
        return Vector4<T>(
            x * rhs.x,
            y * rhs.y,
            z * rhs.z,
            w * rhs.w
        );
    }
    Vector4<T> &operator *=(const Vector4<T> &rhs) {
        x *= rhs.x;
        y *= rhs.y;
        z *= rhs.z;
        w *= rhs.w;
        return *this;
    }
    Vector4<T> operator /(T rhs) const {
        return Vector4<T>(
            x / rhs,
            y / rhs,
            z / rhs,
            w / rhs
        );
    }
    Vector4<T> &operator /=(T rhs) {
        x /= rhs;
        y /= rhs;
        z /= rhs;
        w /= rhs;
        return *this;
    }
    Vector4<T> operator /(const Vector4<T> &rhs) const {
        return Vector4<T>(
            x / rhs.x,
            y / rhs.y,
            z / rhs.z,
            w / rhs.w
        );
    }
    Vector4<T> &operator /=(const Vector4<T> &rhs) {
        x /= rhs.x;
        y /= rhs.y;
        z /= rhs.z;
        w /= rhs.w;
        return *this;
    }

    Vector4<T> &operator =(const Vector4<T> &copy) {
        x = copy.x;
        y = copy.y;
        z = copy.z;
        w = copy.w;
        return *this;
    }
    Vector4<T> &operator =(Vector4<T> &&move) {
        x = std::move(move.x);
        y = std::move(move.y);
        z = std::move(move.z);
        w = std::move(move.w);
        return *this;
    }

public:
    T &r;
    T &g;
    T &b;
    T &a;
    T &s;
    T &t;
    T &p;
    T &q;

#ifndef GLSLIKE_DISABLE_SWIZZLE
public:
    Swizzle2<T> xx;
    Swizzle2<T> xy;
    Swizzle2<T> xz;
    Swizzle2<T> xw;
    Swizzle2<T> yx;
    Swizzle2<T> yy;
    Swizzle2<T> yz;
    Swizzle2<T> yw;
    Swizzle2<T> zx;
    Swizzle2<T> zy;
    Swizzle2<T> zz;
    Swizzle2<T> zw;
    Swizzle2<T> wx;
    Swizzle2<T> wy;
    Swizzle2<T> wz;
    Swizzle2<T> ww;
    // alias rgba
    Swizzle2<T> rr;
    Swizzle2<T> rg;
    Swizzle2<T> rb;
    Swizzle2<T> ra;
    Swizzle2<T> gr;
    Swizzle2<T> gg;
    Swizzle2<T> gb;
    Swizzle2<T> ga;
    Swizzle2<T> br;
    Swizzle2<T> bg;
    Swizzle2<T> bb;
    Swizzle2<T> ba;
    Swizzle2<T> ar;
    Swizzle2<T> ag;
    Swizzle2<T> ab;
    Swizzle2<T> aa;
    // alias stpq
    Swizzle2<T> ss;
    Swizzle2<T> st;
    Swizzle2<T> sp;
    Swizzle2<T> sq;
    Swizzle2<T> ts;
    Swizzle2<T> tt;
    Swizzle2<T> tp;
    Swizzle2<T> tq;
    Swizzle2<T> ps;
    Swizzle2<T> pt;
    Swizzle2<T> pp;
    Swizzle2<T> pq;
    Swizzle2<T> qs;
    Swizzle2<T> qt;
    Swizzle2<T> qp;
    Swizzle2<T> qq;

public:
    Swizzle3<T> xxx;
    Swizzle3<T> xxy;
    Swizzle3<T> xxz;
    Swizzle3<T> xxw;
    Swizzle3<T> xyx;
    Swizzle3<T> xyy;
    Swizzle3<T> xyz;
    Swizzle3<T> xyw;
    Swizzle3<T> xzx;
    Swizzle3<T> xzy;
    Swizzle3<T> xzz;
    Swizzle3<T> xzw;
    Swizzle3<T> xwx;
    Swizzle3<T> xwy;
    Swizzle3<T> xwz;
    Swizzle3<T> xww;
    Swizzle3<T> yxx;
    Swizzle3<T> yxy;
    Swizzle3<T> yxz;
    Swizzle3<T> yxw;
    Swizzle3<T> yyx;
    Swizzle3<T> yyy;
    Swizzle3<T> yyz;
    Swizzle3<T> yyw;
    Swizzle3<T> yzx;
    Swizzle3<T> yzy;
    Swizzle3<T> yzz;
    Swizzle3<T> yzw;
    Swizzle3<T> ywx;
    Swizzle3<T> ywy;
    Swizzle3<T> ywz;
    Swizzle3<T> yww;
    Swizzle3<T> zxx;
    Swizzle3<T> zxy;
    Swizzle3<T> zxz;
    Swizzle3<T> zxw;
    Swizzle3<T> zyx;
    Swizzle3<T> zyy;
    Swizzle3<T> zyz;
    Swizzle3<T> zyw;
    Swizzle3<T> zzx;
    Swizzle3<T> zzy;
    Swizzle3<T> zzz;
    Swizzle3<T> zzw;
    Swizzle3<T> zwx;
    Swizzle3<T> zwy;
    Swizzle3<T> zwz;
    Swizzle3<T> zww;
    Swizzle3<T> wxx;
    Swizzle3<T> wxy;
    Swizzle3<T> wxz;
    Swizzle3<T> wxw;
    Swizzle3<T> wyx;
    Swizzle3<T> wyy;
    Swizzle3<T> wyz;
    Swizzle3<T> wyw;
    Swizzle3<T> wzx;
    Swizzle3<T> wzy;
    Swizzle3<T> wzz;
    Swizzle3<T> wzw;
    Swizzle3<T> wwx;
    Swizzle3<T> wwy;
    Swizzle3<T> wwz;
    Swizzle3<T> www;
    // alias rgba
    Swizzle3<T> rrr;
    Swizzle3<T> rrg;
    Swizzle3<T> rrb;
    Swizzle3<T> rra;
    Swizzle3<T> rgr;
    Swizzle3<T> rgg;
    Swizzle3<T> rgb;
    Swizzle3<T> rga;
    Swizzle3<T> rbr;
    Swizzle3<T> rbg;
    Swizzle3<T> rbb;
    Swizzle3<T> rba;
    Swizzle3<T> rar;
    Swizzle3<T> rag;
    Swizzle3<T> rab;
    Swizzle3<T> raa;
    Swizzle3<T> grr;
    Swizzle3<T> grg;
    Swizzle3<T> grb;
    Swizzle3<T> gra;
    Swizzle3<T> ggr;
    Swizzle3<T> ggg;
    Swizzle3<T> ggb;
    Swizzle3<T> gga;
    Swizzle3<T> gbr;
    Swizzle3<T> gbg;
    Swizzle3<T> gbb;
    Swizzle3<T> gba;
    Swizzle3<T> gar;
    Swizzle3<T> gag;
    Swizzle3<T> gab;
    Swizzle3<T> gaa;
    Swizzle3<T> brr;
    Swizzle3<T> brg;
    Swizzle3<T> brb;
    Swizzle3<T> bra;
    Swizzle3<T> bgr;
    Swizzle3<T> bgg;
    Swizzle3<T> bgb;
    Swizzle3<T> bga;
    Swizzle3<T> bbr;
    Swizzle3<T> bbg;
    Swizzle3<T> bbb;
    Swizzle3<T> bba;
    Swizzle3<T> bar;
    Swizzle3<T> bag;
    Swizzle3<T> bab;
    Swizzle3<T> baa;
    Swizzle3<T> arr;
    Swizzle3<T> arg;
    Swizzle3<T> arb;
    Swizzle3<T> ara;
    Swizzle3<T> agr;
    Swizzle3<T> agg;
    Swizzle3<T> agb;
    Swizzle3<T> aga;
    Swizzle3<T> abr;
    Swizzle3<T> abg;
    Swizzle3<T> abb;
    Swizzle3<T> aba;
    Swizzle3<T> aar;
    Swizzle3<T> aag;
    Swizzle3<T> aab;
    Swizzle3<T> aaa;
    // alias stpq
    Swizzle3<T> sss;
    Swizzle3<T> sst;
    Swizzle3<T> ssp;
    Swizzle3<T> ssq;
    Swizzle3<T> sts;
    Swizzle3<T> stt;
    Swizzle3<T> stp;
    Swizzle3<T> stq;
    Swizzle3<T> sps;
    Swizzle3<T> spt;
    Swizzle3<T> spp;
    Swizzle3<T> spq;
    Swizzle3<T> sqs;
    Swizzle3<T> sqt;
    Swizzle3<T> sqp;
    Swizzle3<T> sqq;
    Swizzle3<T> tss;
    Swizzle3<T> tst;
    Swizzle3<T> tsp;
    Swizzle3<T> tsq;
    Swizzle3<T> tts;
    Swizzle3<T> ttt;
    Swizzle3<T> ttp;
    Swizzle3<T> ttq;
    Swizzle3<T> tps;
    Swizzle3<T> tpt;
    Swizzle3<T> tpp;
    Swizzle3<T> tpq;
    Swizzle3<T> tqs;
    Swizzle3<T> tqt;
    Swizzle3<T> tqp;
    Swizzle3<T> tqq;
    Swizzle3<T> pss;
    Swizzle3<T> pst;
    Swizzle3<T> psp;
    Swizzle3<T> psq;
    Swizzle3<T> pts;
    Swizzle3<T> ptt;
    Swizzle3<T> ptp;
    Swizzle3<T> ptq;
    Swizzle3<T> pps;
    Swizzle3<T> ppt;
    Swizzle3<T> ppp;
    Swizzle3<T> ppq;
    Swizzle3<T> pqs;
    Swizzle3<T> pqt;
    Swizzle3<T> pqp;
    Swizzle3<T> pqq;
    Swizzle3<T> qss;
    Swizzle3<T> qst;
    Swizzle3<T> qsp;
    Swizzle3<T> qsq;
    Swizzle3<T> qts;
    Swizzle3<T> qtt;
    Swizzle3<T> qtp;
    Swizzle3<T> qtq;
    Swizzle3<T> qps;
    Swizzle3<T> qpt;
    Swizzle3<T> qpp;
    Swizzle3<T> qpq;
    Swizzle3<T> qqs;
    Swizzle3<T> qqt;
    Swizzle3<T> qqp;
    Swizzle3<T> qqq;

public:
    Swizzle4<T> xxxx;
    Swizzle4<T> xxxy;
    Swizzle4<T> xxxz;
    Swizzle4<T> xxxw;
    Swizzle4<T> xxyx;
    Swizzle4<T> xxyy;
    Swizzle4<T> xxyz;
    Swizzle4<T> xxyw;
    Swizzle4<T> xxzx;
    Swizzle4<T> xxzy;
    Swizzle4<T> xxzz;
    Swizzle4<T> xxzw;
    Swizzle4<T> xxwx;
    Swizzle4<T> xxwy;
    Swizzle4<T> xxwz;
    Swizzle4<T> xxww;
    Swizzle4<T> xyxx;
    Swizzle4<T> xyxy;
    Swizzle4<T> xyxz;
    Swizzle4<T> xyxw;
    Swizzle4<T> xyyx;
    Swizzle4<T> xyyy;
    Swizzle4<T> xyyz;
    Swizzle4<T> xyyw;
    Swizzle4<T> xyzx;
    Swizzle4<T> xyzy;
    Swizzle4<T> xyzz;
    Swizzle4<T> xyzw;
    Swizzle4<T> xywx;
    Swizzle4<T> xywy;
    Swizzle4<T> xywz;
    Swizzle4<T> xyww;
    Swizzle4<T> xzxx;
    Swizzle4<T> xzxy;
    Swizzle4<T> xzxz;
    Swizzle4<T> xzxw;
    Swizzle4<T> xzyx;
    Swizzle4<T> xzyy;
    Swizzle4<T> xzyz;
    Swizzle4<T> xzyw;
    Swizzle4<T> xzzx;
    Swizzle4<T> xzzy;
    Swizzle4<T> xzzz;
    Swizzle4<T> xzzw;
    Swizzle4<T> xzwx;
    Swizzle4<T> xzwy;
    Swizzle4<T> xzwz;
    Swizzle4<T> xzww;
    Swizzle4<T> xwxx;
    Swizzle4<T> xwxy;
    Swizzle4<T> xwxz;
    Swizzle4<T> xwxw;
    Swizzle4<T> xwyx;
    Swizzle4<T> xwyy;
    Swizzle4<T> xwyz;
    Swizzle4<T> xwyw;
    Swizzle4<T> xwzx;
    Swizzle4<T> xwzy;
    Swizzle4<T> xwzz;
    Swizzle4<T> xwzw;
    Swizzle4<T> xwwx;
    Swizzle4<T> xwwy;
    Swizzle4<T> xwwz;
    Swizzle4<T> xwww;
    Swizzle4<T> yxxx;
    Swizzle4<T> yxxy;
    Swizzle4<T> yxxz;
    Swizzle4<T> yxxw;
    Swizzle4<T> yxyx;
    Swizzle4<T> yxyy;
    Swizzle4<T> yxyz;
    Swizzle4<T> yxyw;
    Swizzle4<T> yxzx;
    Swizzle4<T> yxzy;
    Swizzle4<T> yxzz;
    Swizzle4<T> yxzw;
    Swizzle4<T> yxwx;
    Swizzle4<T> yxwy;
    Swizzle4<T> yxwz;
    Swizzle4<T> yxww;
    Swizzle4<T> yyxx;
    Swizzle4<T> yyxy;
    Swizzle4<T> yyxz;
    Swizzle4<T> yyxw;
    Swizzle4<T> yyyx;
    Swizzle4<T> yyyy;
    Swizzle4<T> yyyz;
    Swizzle4<T> yyyw;
    Swizzle4<T> yyzx;
    Swizzle4<T> yyzy;
    Swizzle4<T> yyzz;
    Swizzle4<T> yyzw;
    Swizzle4<T> yywx;
    Swizzle4<T> yywy;
    Swizzle4<T> yywz;
    Swizzle4<T> yyww;
    Swizzle4<T> yzxx;
    Swizzle4<T> yzxy;
    Swizzle4<T> yzxz;
    Swizzle4<T> yzxw;
    Swizzle4<T> yzyx;
    Swizzle4<T> yzyy;
    Swizzle4<T> yzyz;
    Swizzle4<T> yzyw;
    Swizzle4<T> yzzx;
    Swizzle4<T> yzzy;
    Swizzle4<T> yzzz;
    Swizzle4<T> yzzw;
    Swizzle4<T> yzwx;
    Swizzle4<T> yzwy;
    Swizzle4<T> yzwz;
    Swizzle4<T> yzww;
    Swizzle4<T> ywxx;
    Swizzle4<T> ywxy;
    Swizzle4<T> ywxz;
    Swizzle4<T> ywxw;
    Swizzle4<T> ywyx;
    Swizzle4<T> ywyy;
    Swizzle4<T> ywyz;
    Swizzle4<T> ywyw;
    Swizzle4<T> ywzx;
    Swizzle4<T> ywzy;
    Swizzle4<T> ywzz;
    Swizzle4<T> ywzw;
    Swizzle4<T> ywwx;
    Swizzle4<T> ywwy;
    Swizzle4<T> ywwz;
    Swizzle4<T> ywww;
    Swizzle4<T> zxxx;
    Swizzle4<T> zxxy;
    Swizzle4<T> zxxz;
    Swizzle4<T> zxxw;
    Swizzle4<T> zxyx;
    Swizzle4<T> zxyy;
    Swizzle4<T> zxyz;
    Swizzle4<T> zxyw;
    Swizzle4<T> zxzx;
    Swizzle4<T> zxzy;
    Swizzle4<T> zxzz;
    Swizzle4<T> zxzw;
    Swizzle4<T> zxwx;
    Swizzle4<T> zxwy;
    Swizzle4<T> zxwz;
    Swizzle4<T> zxww;
    Swizzle4<T> zyxx;
    Swizzle4<T> zyxy;
    Swizzle4<T> zyxz;
    Swizzle4<T> zyxw;
    Swizzle4<T> zyyx;
    Swizzle4<T> zyyy;
    Swizzle4<T> zyyz;
    Swizzle4<T> zyyw;
    Swizzle4<T> zyzx;
    Swizzle4<T> zyzy;
    Swizzle4<T> zyzz;
    Swizzle4<T> zyzw;
    Swizzle4<T> zywx;
    Swizzle4<T> zywy;
    Swizzle4<T> zywz;
    Swizzle4<T> zyww;
    Swizzle4<T> zzxx;
    Swizzle4<T> zzxy;
    Swizzle4<T> zzxz;
    Swizzle4<T> zzxw;
    Swizzle4<T> zzyx;
    Swizzle4<T> zzyy;
    Swizzle4<T> zzyz;
    Swizzle4<T> zzyw;
    Swizzle4<T> zzzx;
    Swizzle4<T> zzzy;
    Swizzle4<T> zzzz;
    Swizzle4<T> zzzw;
    Swizzle4<T> zzwx;
    Swizzle4<T> zzwy;
    Swizzle4<T> zzwz;
    Swizzle4<T> zzww;
    Swizzle4<T> zwxx;
    Swizzle4<T> zwxy;
    Swizzle4<T> zwxz;
    Swizzle4<T> zwxw;
    Swizzle4<T> zwyx;
    Swizzle4<T> zwyy;
    Swizzle4<T> zwyz;
    Swizzle4<T> zwyw;
    Swizzle4<T> zwzx;
    Swizzle4<T> zwzy;
    Swizzle4<T> zwzz;
    Swizzle4<T> zwzw;
    Swizzle4<T> zwwx;
    Swizzle4<T> zwwy;
    Swizzle4<T> zwwz;
    Swizzle4<T> zwww;
    Swizzle4<T> wxxx;
    Swizzle4<T> wxxy;
    Swizzle4<T> wxxz;
    Swizzle4<T> wxxw;
    Swizzle4<T> wxyx;
    Swizzle4<T> wxyy;
    Swizzle4<T> wxyz;
    Swizzle4<T> wxyw;
    Swizzle4<T> wxzx;
    Swizzle4<T> wxzy;
    Swizzle4<T> wxzz;
    Swizzle4<T> wxzw;
    Swizzle4<T> wxwx;
    Swizzle4<T> wxwy;
    Swizzle4<T> wxwz;
    Swizzle4<T> wxww;
    Swizzle4<T> wyxx;
    Swizzle4<T> wyxy;
    Swizzle4<T> wyxz;
    Swizzle4<T> wyxw;
    Swizzle4<T> wyyx;
    Swizzle4<T> wyyy;
    Swizzle4<T> wyyz;
    Swizzle4<T> wyyw;
    Swizzle4<T> wyzx;
    Swizzle4<T> wyzy;
    Swizzle4<T> wyzz;
    Swizzle4<T> wyzw;
    Swizzle4<T> wywx;
    Swizzle4<T> wywy;
    Swizzle4<T> wywz;
    Swizzle4<T> wyww;
    Swizzle4<T> wzxx;
    Swizzle4<T> wzxy;
    Swizzle4<T> wzxz;
    Swizzle4<T> wzxw;
    Swizzle4<T> wzyx;
    Swizzle4<T> wzyy;
    Swizzle4<T> wzyz;
    Swizzle4<T> wzyw;
    Swizzle4<T> wzzx;
    Swizzle4<T> wzzy;
    Swizzle4<T> wzzz;
    Swizzle4<T> wzzw;
    Swizzle4<T> wzwx;
    Swizzle4<T> wzwy;
    Swizzle4<T> wzwz;
    Swizzle4<T> wzww;
    Swizzle4<T> wwxx;
    Swizzle4<T> wwxy;
    Swizzle4<T> wwxz;
    Swizzle4<T> wwxw;
    Swizzle4<T> wwyx;
    Swizzle4<T> wwyy;
    Swizzle4<T> wwyz;
    Swizzle4<T> wwyw;
    Swizzle4<T> wwzx;
    Swizzle4<T> wwzy;
    Swizzle4<T> wwzz;
    Swizzle4<T> wwzw;
    Swizzle4<T> wwwx;
    Swizzle4<T> wwwy;
    Swizzle4<T> wwwz;
    Swizzle4<T> wwww;
    // alias rgba
    Swizzle4<T> rrrr;
    Swizzle4<T> rrrg;
    Swizzle4<T> rrrb;
    Swizzle4<T> rrra;
    Swizzle4<T> rrgr;
    Swizzle4<T> rrgg;
    Swizzle4<T> rrgb;
    Swizzle4<T> rrga;
    Swizzle4<T> rrbr;
    Swizzle4<T> rrbg;
    Swizzle4<T> rrbb;
    Swizzle4<T> rrba;
    Swizzle4<T> rrar;
    Swizzle4<T> rrag;
    Swizzle4<T> rrab;
    Swizzle4<T> rraa;
    Swizzle4<T> rgrr;
    Swizzle4<T> rgrg;
    Swizzle4<T> rgrb;
    Swizzle4<T> rgra;
    Swizzle4<T> rggr;
    Swizzle4<T> rggg;
    Swizzle4<T> rggb;
    Swizzle4<T> rgga;
    Swizzle4<T> rgbr;
    Swizzle4<T> rgbg;
    Swizzle4<T> rgbb;
    Swizzle4<T> rgba;
    Swizzle4<T> rgar;
    Swizzle4<T> rgag;
    Swizzle4<T> rgab;
    Swizzle4<T> rgaa;
    Swizzle4<T> rbrr;
    Swizzle4<T> rbrg;
    Swizzle4<T> rbrb;
    Swizzle4<T> rbra;
    Swizzle4<T> rbgr;
    Swizzle4<T> rbgg;
    Swizzle4<T> rbgb;
    Swizzle4<T> rbga;
    Swizzle4<T> rbbr;
    Swizzle4<T> rbbg;
    Swizzle4<T> rbbb;
    Swizzle4<T> rbba;
    Swizzle4<T> rbar;
    Swizzle4<T> rbag;
    Swizzle4<T> rbab;
    Swizzle4<T> rbaa;
    Swizzle4<T> rarr;
    Swizzle4<T> rarg;
    Swizzle4<T> rarb;
    Swizzle4<T> rara;
    Swizzle4<T> ragr;
    Swizzle4<T> ragg;
    Swizzle4<T> ragb;
    Swizzle4<T> raga;
    Swizzle4<T> rabr;
    Swizzle4<T> rabg;
    Swizzle4<T> rabb;
    Swizzle4<T> raba;
    Swizzle4<T> raar;
    Swizzle4<T> raag;
    Swizzle4<T> raab;
    Swizzle4<T> raaa;
    Swizzle4<T> grrr;
    Swizzle4<T> grrg;
    Swizzle4<T> grrb;
    Swizzle4<T> grra;
    Swizzle4<T> grgr;
    Swizzle4<T> grgg;
    Swizzle4<T> grgb;
    Swizzle4<T> grga;
    Swizzle4<T> grbr;
    Swizzle4<T> grbg;
    Swizzle4<T> grbb;
    Swizzle4<T> grba;
    Swizzle4<T> grar;
    Swizzle4<T> grag;
    Swizzle4<T> grab;
    Swizzle4<T> graa;
    Swizzle4<T> ggrr;
    Swizzle4<T> ggrg;
    Swizzle4<T> ggrb;
    Swizzle4<T> ggra;
    Swizzle4<T> gggr;
    Swizzle4<T> gggg;
    Swizzle4<T> gggb;
    Swizzle4<T> ggga;
    Swizzle4<T> ggbr;
    Swizzle4<T> ggbg;
    Swizzle4<T> ggbb;
    Swizzle4<T> ggba;
    Swizzle4<T> ggar;
    Swizzle4<T> ggag;
    Swizzle4<T> ggab;
    Swizzle4<T> ggaa;
    Swizzle4<T> gbrr;
    Swizzle4<T> gbrg;
    Swizzle4<T> gbrb;
    Swizzle4<T> gbra;
    Swizzle4<T> gbgr;
    Swizzle4<T> gbgg;
    Swizzle4<T> gbgb;
    Swizzle4<T> gbga;
    Swizzle4<T> gbbr;
    Swizzle4<T> gbbg;
    Swizzle4<T> gbbb;
    Swizzle4<T> gbba;
    Swizzle4<T> gbar;
    Swizzle4<T> gbag;
    Swizzle4<T> gbab;
    Swizzle4<T> gbaa;
    Swizzle4<T> garr;
    Swizzle4<T> garg;
    Swizzle4<T> garb;
    Swizzle4<T> gara;
    Swizzle4<T> gagr;
    Swizzle4<T> gagg;
    Swizzle4<T> gagb;
    Swizzle4<T> gaga;
    Swizzle4<T> gabr;
    Swizzle4<T> gabg;
    Swizzle4<T> gabb;
    Swizzle4<T> gaba;
    Swizzle4<T> gaar;
    Swizzle4<T> gaag;
    Swizzle4<T> gaab;
    Swizzle4<T> gaaa;
    Swizzle4<T> brrr;
    Swizzle4<T> brrg;
    Swizzle4<T> brrb;
    Swizzle4<T> brra;
    Swizzle4<T> brgr;
    Swizzle4<T> brgg;
    Swizzle4<T> brgb;
    Swizzle4<T> brga;
    Swizzle4<T> brbr;
    Swizzle4<T> brbg;
    Swizzle4<T> brbb;
    Swizzle4<T> brba;
    Swizzle4<T> brar;
    Swizzle4<T> brag;
    Swizzle4<T> brab;
    Swizzle4<T> braa;
    Swizzle4<T> bgrr;
    Swizzle4<T> bgrg;
    Swizzle4<T> bgrb;
    Swizzle4<T> bgra;
    Swizzle4<T> bggr;
    Swizzle4<T> bggg;
    Swizzle4<T> bggb;
    Swizzle4<T> bgga;
    Swizzle4<T> bgbr;
    Swizzle4<T> bgbg;
    Swizzle4<T> bgbb;
    Swizzle4<T> bgba;
    Swizzle4<T> bgar;
    Swizzle4<T> bgag;
    Swizzle4<T> bgab;
    Swizzle4<T> bgaa;
    Swizzle4<T> bbrr;
    Swizzle4<T> bbrg;
    Swizzle4<T> bbrb;
    Swizzle4<T> bbra;
    Swizzle4<T> bbgr;
    Swizzle4<T> bbgg;
    Swizzle4<T> bbgb;
    Swizzle4<T> bbga;
    Swizzle4<T> bbbr;
    Swizzle4<T> bbbg;
    Swizzle4<T> bbbb;
    Swizzle4<T> bbba;
    Swizzle4<T> bbar;
    Swizzle4<T> bbag;
    Swizzle4<T> bbab;
    Swizzle4<T> bbaa;
    Swizzle4<T> barr;
    Swizzle4<T> barg;
    Swizzle4<T> barb;
    Swizzle4<T> bara;
    Swizzle4<T> bagr;
    Swizzle4<T> bagg;
    Swizzle4<T> bagb;
    Swizzle4<T> baga;
    Swizzle4<T> babr;
    Swizzle4<T> babg;
    Swizzle4<T> babb;
    Swizzle4<T> baba;
    Swizzle4<T> baar;
    Swizzle4<T> baag;
    Swizzle4<T> baab;
    Swizzle4<T> baaa;
    Swizzle4<T> arrr;
    Swizzle4<T> arrg;
    Swizzle4<T> arrb;
    Swizzle4<T> arra;
    Swizzle4<T> argr;
    Swizzle4<T> argg;
    Swizzle4<T> argb;
    Swizzle4<T> arga;
    Swizzle4<T> arbr;
    Swizzle4<T> arbg;
    Swizzle4<T> arbb;
    Swizzle4<T> arba;
    Swizzle4<T> arar;
    Swizzle4<T> arag;
    Swizzle4<T> arab;
    Swizzle4<T> araa;
    Swizzle4<T> agrr;
    Swizzle4<T> agrg;
    Swizzle4<T> agrb;
    Swizzle4<T> agra;
    Swizzle4<T> aggr;
    Swizzle4<T> aggg;
    Swizzle4<T> aggb;
    Swizzle4<T> agga;
    Swizzle4<T> agbr;
    Swizzle4<T> agbg;
    Swizzle4<T> agbb;
    Swizzle4<T> agba;
    Swizzle4<T> agar;
    Swizzle4<T> agag;
    Swizzle4<T> agab;
    Swizzle4<T> agaa;
    Swizzle4<T> abrr;
    Swizzle4<T> abrg;
    Swizzle4<T> abrb;
    Swizzle4<T> abra;
    Swizzle4<T> abgr;
    Swizzle4<T> abgg;
    Swizzle4<T> abgb;
    Swizzle4<T> abga;
    Swizzle4<T> abbr;
    Swizzle4<T> abbg;
    Swizzle4<T> abbb;
    Swizzle4<T> abba;
    Swizzle4<T> abar;
    Swizzle4<T> abag;
    Swizzle4<T> abab;
    Swizzle4<T> abaa;
    Swizzle4<T> aarr;
    Swizzle4<T> aarg;
    Swizzle4<T> aarb;
    Swizzle4<T> aara;
    Swizzle4<T> aagr;
    Swizzle4<T> aagg;
    Swizzle4<T> aagb;
    Swizzle4<T> aaga;
    Swizzle4<T> aabr;
    Swizzle4<T> aabg;
    Swizzle4<T> aabb;
    Swizzle4<T> aaba;
    Swizzle4<T> aaar;
    Swizzle4<T> aaag;
    Swizzle4<T> aaab;
    Swizzle4<T> aaaa;
    // alias stpq
    Swizzle4<T> ssss;
    Swizzle4<T> ssst;
    Swizzle4<T> sssp;
    Swizzle4<T> sssq;
    Swizzle4<T> ssts;
    Swizzle4<T> sstt;
    Swizzle4<T> sstp;
    Swizzle4<T> sstq;
    Swizzle4<T> ssps;
    Swizzle4<T> sspt;
    Swizzle4<T> sspp;
    Swizzle4<T> sspq;
    Swizzle4<T> ssqs;
    Swizzle4<T> ssqt;
    Swizzle4<T> ssqp;
    Swizzle4<T> ssqq;
    Swizzle4<T> stss;
    Swizzle4<T> stst;
    Swizzle4<T> stsp;
    Swizzle4<T> stsq;
    Swizzle4<T> stts;
    Swizzle4<T> sttt;
    Swizzle4<T> sttp;
    Swizzle4<T> sttq;
    Swizzle4<T> stps;
    Swizzle4<T> stpt;
    Swizzle4<T> stpp;
    Swizzle4<T> stpq;
    Swizzle4<T> stqs;
    Swizzle4<T> stqt;
    Swizzle4<T> stqp;
    Swizzle4<T> stqq;
    Swizzle4<T> spss;
    Swizzle4<T> spst;
    Swizzle4<T> spsp;
    Swizzle4<T> spsq;
    Swizzle4<T> spts;
    Swizzle4<T> sptt;
    Swizzle4<T> sptp;
    Swizzle4<T> sptq;
    Swizzle4<T> spps;
    Swizzle4<T> sppt;
    Swizzle4<T> sppp;
    Swizzle4<T> sppq;
    Swizzle4<T> spqs;
    Swizzle4<T> spqt;
    Swizzle4<T> spqp;
    Swizzle4<T> spqq;
    Swizzle4<T> sqss;
    Swizzle4<T> sqst;
    Swizzle4<T> sqsp;
    Swizzle4<T> sqsq;
    Swizzle4<T> sqts;
    Swizzle4<T> sqtt;
    Swizzle4<T> sqtp;
    Swizzle4<T> sqtq;
    Swizzle4<T> sqps;
    Swizzle4<T> sqpt;
    Swizzle4<T> sqpp;
    Swizzle4<T> sqpq;
    Swizzle4<T> sqqs;
    Swizzle4<T> sqqt;
    Swizzle4<T> sqqp;
    Swizzle4<T> sqqq;
    Swizzle4<T> tsss;
    Swizzle4<T> tsst;
    Swizzle4<T> tssp;
    Swizzle4<T> tssq;
    Swizzle4<T> tsts;
    Swizzle4<T> tstt;
    Swizzle4<T> tstp;
    Swizzle4<T> tstq;
    Swizzle4<T> tsps;
    Swizzle4<T> tspt;
    Swizzle4<T> tspp;
    Swizzle4<T> tspq;
    Swizzle4<T> tsqs;
    Swizzle4<T> tsqt;
    Swizzle4<T> tsqp;
    Swizzle4<T> tsqq;
    Swizzle4<T> ttss;
    Swizzle4<T> ttst;
    Swizzle4<T> ttsp;
    Swizzle4<T> ttsq;
    Swizzle4<T> ttts;
    Swizzle4<T> tttt;
    Swizzle4<T> tttp;
    Swizzle4<T> tttq;
    Swizzle4<T> ttps;
    Swizzle4<T> ttpt;
    Swizzle4<T> ttpp;
    Swizzle4<T> ttpq;
    Swizzle4<T> ttqs;
    Swizzle4<T> ttqt;
    Swizzle4<T> ttqp;
    Swizzle4<T> ttqq;
    Swizzle4<T> tpss;
    Swizzle4<T> tpst;
    Swizzle4<T> tpsp;
    Swizzle4<T> tpsq;
    Swizzle4<T> tpts;
    Swizzle4<T> tptt;
    Swizzle4<T> tptp;
    Swizzle4<T> tptq;
    Swizzle4<T> tpps;
    Swizzle4<T> tppt;
    Swizzle4<T> tppp;
    Swizzle4<T> tppq;
    Swizzle4<T> tpqs;
    Swizzle4<T> tpqt;
    Swizzle4<T> tpqp;
    Swizzle4<T> tpqq;
    Swizzle4<T> tqss;
    Swizzle4<T> tqst;
    Swizzle4<T> tqsp;
    Swizzle4<T> tqsq;
    Swizzle4<T> tqts;
    Swizzle4<T> tqtt;
    Swizzle4<T> tqtp;
    Swizzle4<T> tqtq;
    Swizzle4<T> tqps;
    Swizzle4<T> tqpt;
    Swizzle4<T> tqpp;
    Swizzle4<T> tqpq;
    Swizzle4<T> tqqs;
    Swizzle4<T> tqqt;
    Swizzle4<T> tqqp;
    Swizzle4<T> tqqq;
    Swizzle4<T> psss;
    Swizzle4<T> psst;
    Swizzle4<T> pssp;
    Swizzle4<T> pssq;
    Swizzle4<T> psts;
    Swizzle4<T> pstt;
    Swizzle4<T> pstp;
    Swizzle4<T> pstq;
    Swizzle4<T> psps;
    Swizzle4<T> pspt;
    Swizzle4<T> pspp;
    Swizzle4<T> pspq;
    Swizzle4<T> psqs;
    Swizzle4<T> psqt;
    Swizzle4<T> psqp;
    Swizzle4<T> psqq;
    Swizzle4<T> ptss;
    Swizzle4<T> ptst;
    Swizzle4<T> ptsp;
    Swizzle4<T> ptsq;
    Swizzle4<T> ptts;
    Swizzle4<T> pttt;
    Swizzle4<T> pttp;
    Swizzle4<T> pttq;
    Swizzle4<T> ptps;
    Swizzle4<T> ptpt;
    Swizzle4<T> ptpp;
    Swizzle4<T> ptpq;
    Swizzle4<T> ptqs;
    Swizzle4<T> ptqt;
    Swizzle4<T> ptqp;
    Swizzle4<T> ptqq;
    Swizzle4<T> ppss;
    Swizzle4<T> ppst;
    Swizzle4<T> ppsp;
    Swizzle4<T> ppsq;
    Swizzle4<T> ppts;
    Swizzle4<T> pptt;
    Swizzle4<T> pptp;
    Swizzle4<T> pptq;
    Swizzle4<T> ppps;
    Swizzle4<T> pppt;
    Swizzle4<T> pppp;
    Swizzle4<T> pppq;
    Swizzle4<T> ppqs;
    Swizzle4<T> ppqt;
    Swizzle4<T> ppqp;
    Swizzle4<T> ppqq;
    Swizzle4<T> pqss;
    Swizzle4<T> pqst;
    Swizzle4<T> pqsp;
    Swizzle4<T> pqsq;
    Swizzle4<T> pqts;
    Swizzle4<T> pqtt;
    Swizzle4<T> pqtp;
    Swizzle4<T> pqtq;
    Swizzle4<T> pqps;
    Swizzle4<T> pqpt;
    Swizzle4<T> pqpp;
    Swizzle4<T> pqpq;
    Swizzle4<T> pqqs;
    Swizzle4<T> pqqt;
    Swizzle4<T> pqqp;
    Swizzle4<T> pqqq;
    Swizzle4<T> qsss;
    Swizzle4<T> qsst;
    Swizzle4<T> qssp;
    Swizzle4<T> qssq;
    Swizzle4<T> qsts;
    Swizzle4<T> qstt;
    Swizzle4<T> qstp;
    Swizzle4<T> qstq;
    Swizzle4<T> qsps;
    Swizzle4<T> qspt;
    Swizzle4<T> qspp;
    Swizzle4<T> qspq;
    Swizzle4<T> qsqs;
    Swizzle4<T> qsqt;
    Swizzle4<T> qsqp;
    Swizzle4<T> qsqq;
    Swizzle4<T> qtss;
    Swizzle4<T> qtst;
    Swizzle4<T> qtsp;
    Swizzle4<T> qtsq;
    Swizzle4<T> qtts;
    Swizzle4<T> qttt;
    Swizzle4<T> qttp;
    Swizzle4<T> qttq;
    Swizzle4<T> qtps;
    Swizzle4<T> qtpt;
    Swizzle4<T> qtpp;
    Swizzle4<T> qtpq;
    Swizzle4<T> qtqs;
    Swizzle4<T> qtqt;
    Swizzle4<T> qtqp;
    Swizzle4<T> qtqq;
    Swizzle4<T> qpss;
    Swizzle4<T> qpst;
    Swizzle4<T> qpsp;
    Swizzle4<T> qpsq;
    Swizzle4<T> qpts;
    Swizzle4<T> qptt;
    Swizzle4<T> qptp;
    Swizzle4<T> qptq;
    Swizzle4<T> qpps;
    Swizzle4<T> qppt;
    Swizzle4<T> qppp;
    Swizzle4<T> qppq;
    Swizzle4<T> qpqs;
    Swizzle4<T> qpqt;
    Swizzle4<T> qpqp;
    Swizzle4<T> qpqq;
    Swizzle4<T> qqss;
    Swizzle4<T> qqst;
    Swizzle4<T> qqsp;
    Swizzle4<T> qqsq;
    Swizzle4<T> qqts;
    Swizzle4<T> qqtt;
    Swizzle4<T> qqtp;
    Swizzle4<T> qqtq;
    Swizzle4<T> qqps;
    Swizzle4<T> qqpt;
    Swizzle4<T> qqpp;
    Swizzle4<T> qqpq;
    Swizzle4<T> qqqs;
    Swizzle4<T> qqqt;
    Swizzle4<T> qqqp;
    Swizzle4<T> qqqq;
#endif  // GLSLIKE_DISABLE_SWIZZLE

};

//
// 8.1 Angle and Trigonometry Functions
// These all operate component-wise.
//

template <typename T>
Vector4<T> radians(const Vector4<T> &degrees) {
    return Vector4<T>(
        math<T>::radians(degrees.x),
        math<T>::radians(degrees.y),
        math<T>::radians(degrees.z),
        math<T>::radians(degrees.w)
    );
}

template <typename T>
Vector4<T> degrees(const Vector4<T> &radians) {
    return Vector4<T>(
        math<T>::degrees(radians.x),
        math<T>::degrees(radians.y),
        math<T>::degrees(radians.z),
        math<T>::degrees(radians.w)
    );
}

template <typename T>
Vector4<T> sin(const Vector4<T> &angle) {
    return Vector4<T>(
        math<T>::sin(angle.x),
        math<T>::sin(angle.y),
        math<T>::sin(angle.z),
        math<T>::sin(angle.w)
    );
}

template <typename T>
Vector4<T> cos(const Vector4<T> &angle) {
    return Vector4<T>(
        math<T>::cos(angle.x),
        math<T>::cos(angle.y),
        math<T>::cos(angle.z),
        math<T>::cos(angle.w)
    );
}

template <typename T>
Vector4<T> tan(const Vector4<T> & angle) {
    return Vector4<T>(
        math<T>::tan(angle.x),
        math<T>::tan(angle.y),
        math<T>::tan(angle.z),
        math<T>::tan(angle.w)
    );
}

template <typename T>
Vector4<T> asin(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::asin(x.x),
        math<T>::asin(x.y),
        math<T>::asin(x.z),
        math<T>::asin(x.w)
    );
}

template <typename T>
Vector4<T> acos(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::acos(x.x),
        math<T>::acos(x.y),
        math<T>::acos(x.z),
        math<T>::acos(x.w)
    );
}

template <typename T>
Vector4<T> atan(const Vector4<T> &y, const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::atan(y.x, x.x),
        math<T>::atan(y.y, x.y),
        math<T>::atan(y.z, x.z),
        math<T>::atan(y.w, x.w)
    );
}

template <typename T>
Vector4<T> atan(const Vector4<T> &y_over_x) {
    return Vector4<T>(
        math<T>::atan(y_over_x.x),
        math<T>::atan(y_over_x.y),
        math<T>::atan(y_over_x.z),
        math<T>::atan(y_over_x.w)
    );
}

template <typename T>
Vector4<T> sinh(const Vector4<T> &angle) {
    return Vector4<T>(
        math<T>::sinh(angle.x),
        math<T>::sinh(angle.y),
        math<T>::sinh(angle.z),
        math<T>::sinh(angle.w)
    );
}

template <typename T>
Vector4<T> cosh(const Vector4<T> &angle) {
    return Vector4<T>(
        math<T>::cosh(angle.x),
        math<T>::cosh(angle.y),
        math<T>::cosh(angle.z),
        math<T>::cosh(angle.w)
    );
}

template <typename T>
Vector4<T> tanh(const Vector4<T> &angle) {
    return Vector4<T>(
        math<T>::tanh(angle.x),
        math<T>::tanh(angle.y),
        math<T>::tanh(angle.z),
        math<T>::tanh(angle.w)
    );
}

template <typename T>
Vector4<T> asinh(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::asinh(x.x),
        math<T>::asinh(x.y),
        math<T>::asinh(x.z),
        math<T>::asinh(x.w)
    );
}

template <typename T>
Vector4<T> acosh(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::acosh(x.x),
        math<T>::acosh(x.y),
        math<T>::acosh(x.z),
        math<T>::acosh(x.w)
    );
}

template <typename T>
Vector4<T> atanh(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::atanh(x.x),
        math<T>::atanh(x.y),
        math<T>::atanh(x.z),
        math<T>::atanh(x.w)
    );
}

//
// 8.2 Exponential Functions
// These all operate component-wise.
//

template <typename T>
Vector4<T> pow(const Vector4<T> &vec, T n) {
    return Vector4<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n),
        math<T>::pow(vec.z, n),
        math<T>::pow(vec.w, n)
    );
}

template <typename T>
Vector4<T> exp(const Vector4<T> &vec) {
    return Vector4<T>(
        math<T>::exp(vec.x),
        math<T>::exp(vec.y),
        math<T>::exp(vec.z),
        math<T>::exp(vec.w)
    );
}

template <typename T>
Vector4<T> log(const Vector4<T> &vec) {
    return Vector4<T>(
        math<T>::log(vec.x),
        math<T>::log(vec.y),
        math<T>::log(vec.z),
        math<T>::log(vec.w)
    );
}

template <typename T>
Vector4<T> exp2(const Vector4<T> &vec) {
    return Vector4<T>(
        math<T>::exp2(vec.x),
        math<T>::exp2(vec.y),
        math<T>::exp2(vec.z),
        math<T>::exp2(vec.w)
    );
}

template <typename T>
Vector4<T> log2(const Vector4<T> &vec) {
    return Vector4<T>(
        math<T>::log2(vec.x),
        math<T>::log2(vec.y),
        math<T>::log2(vec.z),
        math<T>::log2(vec.w)
    );
}

template <typename T>
Vector4<T> sqrt(const Vector4<T> &vec) {
    return Vector4<T>(
        math<T>::sqrt(vec.x),
        math<T>::sqrt(vec.y),
        math<T>::sqrt(vec.z),
        math<T>::sqrt(vec.w)
    );
}

template <typename T>
Vector4<T> inversesqrt(const Vector4<T> &vec) {
    return Vector4<T>(
        math<T>::inversesqrt(vec.x),
        math<T>::inversesqrt(vec.y),
        math<T>::inversesqrt(vec.z),
        math<T>::inversesqrt(vec.w)
    );
}

//
// 8.3 Common Functions
//

template <typename T>
Vector4<T> abs(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::abs(x.x),
        math<T>::abs(x.y),
        math<T>::abs(x.z),
        math<T>::abs(x.w)
    );
}

template <typename T>
Vector4<T> sign(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::sign(x.x),
        math<T>::sign(x.y),
        math<T>::sign(x.z),
        math<T>::sign(x.w)
    );
}

template <typename T>
Vector4<T> floor(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::floor(x.x),
        math<T>::floor(x.y),
        math<T>::floor(x.z),
        math<T>::floor(x.w)
    );
}

template <typename T>
Vector4<T> trunc(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::trunc(x.x),
        math<T>::trunc(x.y),
        math<T>::trunc(x.z),
        math<T>::trunc(x.w)
    );
}

template <typename T>
Vector4<T> round(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::round(x.x),
        math<T>::round(x.y),
        math<T>::round(x.z),
        math<T>::round(x.w)
    );
}

template <typename T>
Vector4<T> roundEven(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::roundEven(x.x),
        math<T>::roundEven(x.y),
        math<T>::roundEven(x.z),
        math<T>::roundEven(x.w)
    );
}

template <typename T>
Vector4<T> ceil(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::ceil(x.x),
        math<T>::ceil(x.y),
        math<T>::ceil(x.z),
        math<T>::ceil(x.w)
    );
}

template <typename T>
Vector4<T> fract(const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::fract(x.x),
        math<T>::fract(x.y),
        math<T>::fract(x.z),
        math<T>::fract(x.w)
    );
}

template <typename T>
Vector4<T> mod(const Vector4<T> &x, const Vector4<T> &y) {
    return Vector4<T>(
        math<T>::mod(x.x, y.x),
        math<T>::mod(x.y, y.y),
        math<T>::mod(x.z, y.z),
        math<T>::mod(x.w, y.w)
    );
}

template <typename T>
Vector4<T> mod(const Vector4<T> &x, T y) {
    return Vector4<T>(
        math<T>::mod(x.x, y),
        math<T>::mod(x.y, y),
        math<T>::mod(x.z, y),
        math<T>::mod(x.w, y)
    );
}

template <typename T>
Vector4<T> modf(const Vector4<T> &x, Vector4<T> *i) {
    return Vector4<T>(
        math<T>::modf(x.x, &i->x),
        math<T>::modf(x.y, &i->y),
        math<T>::modf(x.z, &i->z),
        math<T>::modf(x.w, &i->w)
    );
}

template <typename T>
Vector4<T> min(const Vector4<T> &a, const Vector4<T> &b) {
    return Vector4<T>(
        math<T>::min(a.x, b.x),
        math<T>::min(a.y, b.y),
        math<T>::min(a.z, b.z),
        math<T>::min(a.w, b.w)
    );
}

template <typename T>
Vector4<T> min(const Vector4<T> &a, T b) {
    return Vector4<T>(
        math<T>::min(a.x, b),
        math<T>::min(a.y, b),
        math<T>::min(a.z, b),
        math<T>::min(a.w, b)
    );
}

template <typename T>
Vector4<T> max(const Vector4<T> &a, const Vector4<T> &b) {
    return Vector4<T>(
        math<T>::max(a.x, b.x),
        math<T>::max(a.y, b.y),
        math<T>::max(a.z, b.z),
        math<T>::max(a.w, b.w)
    );
}

template <typename T>
Vector4<T> max(const Vector4<T> &a, T b) {
    return Vector4<T>(
        math<T>::max(a.x, b),
        math<T>::max(a.y, b),
        math<T>::max(a.z, b),
        math<T>::max(a.w, b)
    );
}

template <typename T>
Vector4<T> clamp(const Vector4<T> &value, const Vector4<T> &min, const Vector4<T> &max) {
    return Vector4<T>(
        math<T>::clamp(value.x, min.x, max.x),
        math<T>::clamp(value.y, min.y, max.y),
        math<T>::clamp(value.z, min.z, max.z),
        math<T>::clamp(value.w, min.w, max.w)
    );
}

template <typename T>
Vector4<T> clamp(const Vector4<T> &value, T min, T max) {
    return Vector4<T>(
        math<T>::clamp(value.x, min, max),
        math<T>::clamp(value.y, min, max),
        math<T>::clamp(value.z, min, max),
        math<T>::clamp(value.w, min, max)
    );
}

template <typename T>
Vector4<T> mix(const Vector4<T> &x, const Vector4<T> &y, const Vector4<T> &a) {
    return Vector4<T>(
        math<T>::mix(x.x, y.x, a.x),
        math<T>::mix(x.y, y.y, a.y),
        math<T>::mix(x.z, y.z, a.z),
        math<T>::mix(x.w, y.w, a.w)
    );
}

template <typename T>
Vector4<T> mix(const Vector4<T> &x, const Vector4<T> &y, T a) {
    return Vector4<T>(
        math<T>::mix(x.x, y.x, a),
        math<T>::mix(x.y, y.y, a),
        math<T>::mix(x.z, y.z, a),
        math<T>::mix(x.w, y.w, a)
    );
}

template <typename T>
Vector4<T> step(const Vector4<T> &edge, const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::step(edge.x, x.x),
        math<T>::step(edge.y, x.y),
        math<T>::step(edge.z, x.z),
        math<T>::step(edge.w, x.w)
    );
}

template <typename T>
Vector4<T> step(T edge, const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::step(edge, x.x),
        math<T>::step(edge, x.y),
        math<T>::step(edge, x.z),
        math<T>::step(edge, x.w)
    );
}

template <typename T>
Vector4<T> smoothstep(const Vector4<T> &edge0, const Vector4<T> &edge1, const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::smoothstep(edge0.x, edge1.x, x.x),
        math<T>::smoothstep(edge0.y, edge1.y, x.y),
        math<T>::smoothstep(edge0.z, edge1.z, x.z),
        math<T>::smoothstep(edge0.w, edge1.w, x.w)
    );
}

template <typename T>
Vector4<T> smoothstep(T edge0, T edge1, const Vector4<T> &x) {
    return Vector4<T>(
        math<T>::smoothstep(edge0, edge1, x.x),
        math<T>::smoothstep(edge0, edge1, x.y),
        math<T>::smoothstep(edge0, edge1, x.z),
        math<T>::smoothstep(edge0, edge1, x.w)
    );
}

template <typename T>
Vector4<Bool_t> isnan(const Vector4<T> &x) {
    return Vector4<Bool_t>(
        math<T>::isnan(x.x),
        math<T>::isnan(x.y),
        math<T>::isnan(x.z),
        math<T>::isnan(x.w)
    );
}

template <typename T>
Vector4<Bool_t> isinf(const Vector4<T> &x) {
    return Vector4<Bool_t>(
        math<T>::isinf(x.x),
        math<T>::isinf(x.y),
        math<T>::isinf(x.z),
        math<T>::isinf(x.w)
    );
}

//
// TODO:
// * floatBitToInt
// * floatBitToUint
// * intBitsToFloat
// * fma
// * frexp
// * ldexp
//

// 8.4 Floating-Point Pack and Unpack Functions
//
// * packUnorm2x16
// * packSnorm2x16
// * packUnorm4x8
// * packSnorm4x8
// * unpackUnorm2x16
// * unpackSnorm2x16
// * unpackUnorm4x8
// * unpackSnorm4x8
// * packDouble2x32
// * unpackDouble2x32
// * packHalf2x16
// * unpackHalf2x16
//
// 8.6 Matrix Functions
//
// * matrixCompMult
// * outerProduct
// * transpose
// * determinant
// * inverse
//
// 8.7 Vector Relational Functions
//
// * lessThan
// * lessThanEqual
// * greaterThan
// * greaterThanEqual
// * equal
// * notEqual
// * any
// * all
// * not
//
// 8.8 Integer Functions
//
// * uaddCarry
// * usubBorrow
// * umulExtended
// * imulExtended
// * bitfieldExtract
// * bitfieldInsert
// * bitfieldReverse
// * bitCount
// * findLSB
// * findMSB


template <typename T>
Vector4<T> operator +(T a, const Vector4<T> &b) {
    return Vector4<T>(
        a + b.x,
        a + b.y,
        a + b.z,
        a + b.w
    );
}

template <typename T>
Vector4<T> operator -(T a, const Vector4<T> &b) {
    return Vector4<T>(
        a - b.x,
        a - b.y,
        a - b.z,
        a - b.w
    );
}

template <typename T>
Vector4<T> operator *(T a, const Vector4<T> &b) {
    return Vector4<T>(
        a * b.x,
        a * b.y,
        a * b.z,
        a * b.w
    );
}

template <typename T>
Vector4<T> operator /(T a, const Vector4<T> &b) {
    return Vector4<T>(
        a / b.x,
        a / b.y,
        a / b.z,
        a / b.w
    );
}


#ifndef GLSLIKE_DISABLE_SWIZZLE

template <typename T>
Vector4<T> operator +(const Swizzle4<T> &a, const Vector4<T> &b) {
    return Vector4<T>(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    );
}

template <typename T>
Vector4<T> operator -(const Swizzle4<T> &a, const Vector4<T> &b) {
    return Vector4<T>(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    );
}

template <typename T>
Vector4<T> operator *(const Swizzle4<T> &a, const Vector4<T> &b) {
    return Vector4<T>(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    );
}

template <typename T>
Vector4<T> operator /(const Swizzle4<T> &a, const Vector4<T> &b) {
    return Vector4<T>(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
        a.w / b.w
    );
}

template <typename T>
Vector4<T> operator +(const Vector4<T> & a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    );
}

template <typename T>
Vector4<T> operator -(const Vector4<T> & a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    );
}

template <typename T>
Vector4<T> operator *(const Vector4<T> & a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    );
}

template <typename T>
Vector4<T> operator /(const Vector4<T> & a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
        a.w / b.w
    );
}

template <typename T>
Vector4<T> operator +(const Swizzle4<T> &a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x + b.x,
        a.y + b.y,
        a.z + b.z,
        a.w + b.w
    );
}

template <typename T>
Vector4<T> operator -(const Swizzle4<T> &a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x - b.x,
        a.y - b.y,
        a.z - b.z,
        a.w - b.w
    );
}

template <typename T>
Vector4<T> operator *(const Swizzle4<T> &a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x * b.x,
        a.y * b.y,
        a.z * b.z,
        a.w * b.w
    );
}

template <typename T>
Vector4<T> operator /(const Swizzle4<T> &a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a.x / b.x,
        a.y / b.y,
        a.z / b.z,
        a.w / b.w
    );
}

template <typename T>
Vector4<T> operator +(const Swizzle4<T> &a, T b) {
    return Vector4<T>(
        a.x + b,
        a.y + b,
        a.z + b,
        a.w + b
    );
}

template <typename T>
Vector4<T> operator -(const Swizzle4<T> &a, T b) {
    return Vector4<T>(
        a.x - b,
        a.y - b,
        a.z - b,
        a.w - b
    );
}

template <typename T>
Vector4<T> operator *(const Swizzle4<T> &a, T b) {
    return Vector4<T>(
        a.x * b,
        a.y * b,
        a.z * b,
        a.w * b
    );
}

template <typename T>
Vector4<T> operator /(const Swizzle4<T> &a, T b) {
    return Vector4<T>(
        a.x / b,
        a.y / b,
        a.z / b,
        a.w / b
    );
}

template <typename T>
Vector4<T> operator +(T a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a + b.x,
        a + b.y,
        a + b.z,
        a + b.w
    );
}

template <typename T>
Vector4<T> operator -(T a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a - b.x,
        a - b.y,
        a - b.z,
        a - b.w
    );
}

template <typename T>
Vector4<T> operator *(T a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a * b.x,
        a * b.y,
        a * b.z,
        a * b.w
    );
}

template <typename T>
Vector4<T> operator /(T a, const Swizzle4<T> &b) {
    return Vector4<T>(
        a / b.x,
        a / b.y,
        a / b.z,
        a / b.w
    );
}

#endif  // GLSLIKE_DISABLE_SWIZZLE


//=============================================================================
// vec2, vec3, vec4 template
//=============================================================================

//
// 8.4 Floating-Point Pack and Unpack Functions
//
// * packUnorm2x16
// * packSnorm2x16
// * packUnorm4x8
// * packSnorm4x8
// * unpackUnorm2x16
// * unpackSnorm2x16
// * unpackUnorm4x8
// * unpackSnorm4x8
// * packDouble2x32
// * unpackDouble2x32
// * packHalf2x16
// * unpackHalf2x16
//
// 8.5 Geometric Functions
//
// * length
// * distance
// * dot
// * cross
// * normalize
// * transform
// * faceforward
// * reflect
// * refract
//

template <typename VectorT>
typename VectorT::Type_t length(const VectorT &vec) {
    return vec.length();
}

template <typename VectorT>
typename VectorT::Type_t distance(const VectorT &p0, const VectorT &p1) {
    return length(p0 - p1);
}

template <typename VectorT>
typename VectorT::Type_t dot(const VectorT &a, const VectorT &b) {
    return a.dot(b);
}

template <typename VectorT>
VectorT normalize(const VectorT &vec) {
    return vec.clone().normalize();
}

template <typename VectorT>
VectorT faceforward(const VectorT &n, const VectorT &i, const VectorT &nref) {
    return select(dot(nref, i) < 0.0f, n, -n);
}

template <typename VectorT>
VectorT reflect(const VectorT &i, const VectorT &n) {
    return i - 2 * dot(n, i) * n;
}

template <typename VectorT>
VectorT refract(const VectorT &i, const VectorT &n, float eta) {
    const auto k = 1.0f - eta * eta * (1.0f - dot(n, i) * dot(n, i));
    return select(
        k < 0.0f,
        VectorT(0.0f),
        eta * i - (eta * dot(n, i) + sqrt(k)) * n
    );
}

//
// 8.6 Matrix Functions
//
// * matrixCompMult
// * outerProduct
// * transpose
// * determinant
// * inverse
//
// 8.7 Vector Relational Functions
//
// * lessThan
// * lessThanEqual
// * greaterThan
// * greaterThanEqual
// * equal
// * notEqual
// * any
// * all
// * not
//
// 8.8 Integer Functions
//
// * uaddCarry
// * usubBorrow
// * umulExtended
// * imulExtended
// * bitfieldExtract
// * bitfieldInsert
// * bitfieldReverse
// * bitCount
// * findLSB
// * findMSB


template <typename T>
class Matrix2 {
public:
    Matrix2()
        : f11(1.0f), f21(0.0f)
        , f12(0.0f), f22(1.0f)
    {}

    // NOTE: column order (see GLSL 5.4.2 Vector and Matrix Constructors)
    Matrix2(T f11, T f21,
            T f12, T f22)
        : f11(f11), f21(f21)
        , f12(f12), f22(f22)
    {}

    // NOTE: column order (see GLSL 5.4.2 Vector and Matrix Constructors)
    Matrix2(const Vector2<T> &col1,
            const Vector2<T> &col2)
        : f11(col1.x), f21(col1.y)
        , f12(col2.x), f22(col2.y)
    {}

    Matrix2(const Matrix2<T> &copy)
        : f11(copy.f11), f21(copy.f21)
        , f12(copy.f12), f22(copy.f22)
    {}

    Matrix2(Matrix2<T> &move)
        : f11(std::move(move.f11)), f21(std::move(move.f21))
        , f12(std::move(move.f12)), f22(std::move(move.f22))
    {}

    Vector2<T> operator *(const Vector2<T> &rhs) const {
        const T x = rhs.x, y = rhs.y;
        return Vector2<T>(
            f11 * x + f12 * y,
            f21 * x + f22 * y
        );
    }

    Matrix2<T> operator *(const Matrix2<T> &rhs) const {
        // return this * rhs
        const Matrix2<T> &a = *this;
        const Matrix2<T> &b = rhs;
        return Matrix2<T>(
            a.f11 * b.f11 + a.f12 * b.f21,
            a.f21 * b.f11 + a.f22 * b.f21,
            a.f11 * b.f12 + a.f12 * b.f22,
            a.f21 * b.f12 + a.f22 * b.f22
        );
    }

    T f11, f21;
    T f12, f22;
};


template <typename T>
class Matrix3 {
public:
    Matrix3()
        : f11(1.0f), f21(0.0f), f31(0.0f)
        , f12(0.0f), f22(1.0f), f32(0.0f)
        , f13(0.0f), f23(0.0f), f33(1.0f)
    {}

    // NOTE: column order (see GLSL 5.4.2 Vector and Matrix Constructors)
    Matrix3(T f11, T f21, T f31,
            T f12, T f22, T f32,
            T f13, T f23, T f33)
        : f11(f11), f21(f21), f31(f31)
        , f12(f12), f22(f22), f32(f32)
        , f13(f13), f23(f23), f33(f33)
    {}

    // NOTE: column order (see GLSL 5.4.2 Vector and Matrix Constructors)
    Matrix3(const Vector3<T> &col1,
            const Vector3<T> &col2,
            const Vector3<T> &col3)
        : f11(col1.x), f21(col1.y), f31(col1.z)
        , f12(col2.x), f22(col2.y), f32(col2.z)
        , f13(col3.x), f23(col3.y), f33(col3.z)
    {}

    Matrix3(const Matrix3<T> &copy)
        : f11(copy.f11), f21(copy.f21), f31(copy.f31)
        , f12(copy.f12), f22(copy.f22), f32(copy.f32)
        , f13(copy.f13), f23(copy.f23), f33(copy.f33)
    {}

    Matrix3(Matrix3<T> &move)
        : f11(std::move(move.f11)), f21(std::move(move.f21)), f31(std::move(move.f31))
        , f12(std::move(move.f12)), f22(std::move(move.f22)), f32(std::move(move.f32))
        , f13(std::move(move.f13)), f23(std::move(move.f23)), f33(std::move(move.f33))
    {}

    Vector3<T> operator *(const Vector3<T> &rhs) const {
        const T x = rhs.x, y = rhs.y, z = rhs.z;
        return Vector3<T>(
            f11 * x + f12 * y + f13 * z,
            f21 * x + f22 * y + f23 * z,
            f31 * x + f32 * y + f33 * z
        );
    }

    Matrix3<T> operator *(const Matrix3<T> &rhs) const {
        // return this * rhs
        const Matrix3<T> &a = *this;
        const Matrix3<T> &b = rhs;
        return Matrix3<T>(
            a.f11 * b.f11 + a.f12 * b.f21 + a.f13 * b.f31,
            a.f21 * b.f11 + a.f22 * b.f21 + a.f23 * b.f31,
            a.f31 * b.f11 + a.f32 * b.f21 + a.f33 * b.f31,
            a.f11 * b.f12 + a.f12 * b.f22 + a.f13 * b.f32,
            a.f21 * b.f12 + a.f22 * b.f22 + a.f23 * b.f32,
            a.f31 * b.f12 + a.f32 * b.f22 + a.f33 * b.f32,
            a.f11 * b.f13 + a.f12 * b.f23 + a.f13 * b.f33,
            a.f21 * b.f13 + a.f22 * b.f23 + a.f23 * b.f33,
            a.f31 * b.f13 + a.f32 * b.f23 + a.f33 * b.f33
        );
    }

    T f11, f21, f31;
    T f12, f22, f32;
    T f13, f23, f33;
};


template <typename T>
class Matrix4 {
public:
    Matrix4()
        : f11(1.0f), f21(0.0f), f31(0.0f), f41(0.0f)
        , f12(0.0f), f22(1.0f), f32(0.0f), f42(0.0f)
        , f13(0.0f), f23(0.0f), f33(1.0f), f43(0.0f)
        , f14(0.0f), f24(0.0f), f34(0.0f), f44(1.0f)
    {}

    // NOTE: column order (see GLSL 5.4.2 Vector and Matrix Constructors)
    Matrix4(T f11, T f21, T f31, T f41,
            T f12, T f22, T f32, T f42,
            T f13, T f23, T f33, T f43,
            T f14, T f24, T f34, T f44)
        : f11(f11), f21(f21), f31(f31), f41(f41)
        , f12(f12), f22(f22), f32(f32), f42(f42)
        , f13(f13), f23(f23), f33(f33), f43(f43)
        , f14(f14), f24(f24), f34(f34), f44(f44)
    {}

    // NOTE: column order (see GLSL 5.4.2 Vector and Matrix Constructors)
    Matrix4(const Vector4<T> &col1,
            const Vector4<T> &col2,
            const Vector4<T> &col3,
            const Vector4<T> &col4)
        : f11(col1.x), f21(col1.y), f31(col1.z), f41(col1.w)
        , f12(col2.x), f22(col2.y), f32(col2.z), f42(col2.w)
        , f13(col3.x), f23(col3.y), f33(col3.z), f43(col3.w)
        , f14(col4.x), f24(col4.y), f34(col4.z), f44(col4.w)
    {}

    Matrix4(const Matrix4<T> &copy)
        : f11(copy.f11), f21(copy.f21), f31(copy.f31), f41(copy.f41)
        , f12(copy.f12), f22(copy.f22), f32(copy.f32), f42(copy.f42)
        , f13(copy.f13), f23(copy.f23), f33(copy.f33), f43(copy.f43)
        , f14(copy.f14), f24(copy.f24), f34(copy.f34), f44(copy.f44)
    {}

    Matrix4(Matrix4<T> &move)
        : f11(std::move(move.f11)), f21(std::move(move.f21)), f31(std::move(move.f31)), f41(std::move(move.f41))
        , f12(std::move(move.f12)), f22(std::move(move.f22)), f32(std::move(move.f32)), f42(std::move(move.f42))
        , f13(std::move(move.f13)), f23(std::move(move.f23)), f33(std::move(move.f33)), f43(std::move(move.f43))
        , f14(std::move(move.f14)), f24(std::move(move.f24)), f34(std::move(move.f34)), f44(std::move(move.f44))
    {}

    Vector4<T> operator *(const Vector4<T> &rhs) const {
        const T x = rhs.x, y = rhs.y, z = rhs.z, w = rhs.w;
        return Vector4<T>(
            f11 * x + f12 * y + f13 * z + f14 * w,
            f21 * x + f22 * y + f23 * z + f24 * w,
            f31 * x + f32 * y + f33 * z + f34 * w,
            f41 * x + f42 * y + f43 * z + f44 * w
        );
    }

    Matrix4<T> operator *(const Matrix4<T> &rhs) const {
        // return this * rhs
        const Matrix4<T> &a = *this;
        const Matrix4<T> &b = rhs;
        return Matrix4<T>(
            a.f11 * b.f11 + a.f12 * b.f21 + a.f13 * b.f31 + a.f14 * b.f41,
            a.f21 * b.f11 + a.f22 * b.f21 + a.f23 * b.f31 + a.f24 * b.f41,
            a.f31 * b.f11 + a.f32 * b.f21 + a.f33 * b.f31 + a.f34 * b.f41,
            a.f41 * b.f11 + a.f42 * b.f21 + a.f43 * b.f31 + a.f44 * b.f41,
            a.f11 * b.f12 + a.f12 * b.f22 + a.f13 * b.f32 + a.f14 * b.f42,
            a.f21 * b.f12 + a.f22 * b.f22 + a.f23 * b.f32 + a.f24 * b.f42,
            a.f31 * b.f12 + a.f32 * b.f22 + a.f33 * b.f32 + a.f34 * b.f42,
            a.f41 * b.f12 + a.f42 * b.f22 + a.f43 * b.f32 + a.f44 * b.f42,
            a.f11 * b.f13 + a.f12 * b.f23 + a.f13 * b.f33 + a.f14 * b.f43,
            a.f21 * b.f13 + a.f22 * b.f23 + a.f23 * b.f33 + a.f24 * b.f43,
            a.f31 * b.f13 + a.f32 * b.f23 + a.f33 * b.f33 + a.f34 * b.f43,
            a.f41 * b.f13 + a.f42 * b.f23 + a.f43 * b.f33 + a.f44 * b.f43,
            a.f11 * b.f14 + a.f12 * b.f24 + a.f13 * b.f34 + a.f14 * b.f44,
            a.f21 * b.f14 + a.f22 * b.f24 + a.f23 * b.f34 + a.f24 * b.f44,
            a.f31 * b.f14 + a.f32 * b.f24 + a.f33 * b.f34 + a.f34 * b.f44,
            a.f41 * b.f14 + a.f42 * b.f24 + a.f43 * b.f34 + a.f44 * b.f44
        );
    }

    T f11, f21, f31, f41;
    T f12, f22, f32, f42;
    T f13, f23, f33, f43;
    T f14, f24, f34, f44;
};


#ifdef GLSLIKE_USE_HALIDE
typedef Vector2<Halide::Expr> vec2;
typedef Vector3<Halide::Expr> vec3;
typedef Vector4<Halide::Expr> vec4;
typedef Matrix2<Halide::Expr> mat2;
typedef Matrix3<Halide::Expr> mat3;
typedef Matrix4<Halide::Expr> mat4;
#else
typedef Vector2<float> vec2;
typedef Vector3<float> vec3;
typedef Vector4<float> vec4;
typedef Matrix2<float> mat2;
typedef Matrix3<float> mat3;
typedef Matrix4<float> mat4;
#endif  // GLSLIKE_USE_HALIDE
typedef Vector2<Bool_t> bvec2;
typedef Vector3<Bool_t> bvec3;
typedef Vector4<Bool_t> bvec4;

}  // namespace glslike
