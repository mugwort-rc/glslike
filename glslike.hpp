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
#endif  // GLSLIKE_USE_HALIDE


namespace glslike {

template<typename C>
class math {
private:
    math();
    math(const math &);
    math(math &&);
public:
    static C min(C a, C b) {
        return std::min(a, b);
    }
    static C max(C a, C b) {
        return std::max(a, b);
    }
    static C clamp(C value, C min, C max) {
        return std::clamp(value, min, max);
    }

    static C exp(C scalar) {
        return std::exp(scalar);
    }
    template <typename ExpT>
    static C pow(C base, ExpT exp) {
        return std::pow(base, exp);
    }
    static C sqrt(C scalar) {
        return std::sqrt(scalar);
    }

};

#ifdef GLSLIKE_USE_HALIDE

template<>
class math<Halide::Expr> {
private:
    math();
    math(const math &);
    math(math &&);
public:
    static Halide::Expr min(Halide::Expr a, Halide::Expr b) {
        return Halide::min(a, b);
    }
    static Halide::Expr max(Halide::Expr a, Halide::Expr b) {
        return Halide::max(a, b);
    }
    static Halide::Expr clamp(Halide::Expr value, Halide::Expr min, Halide::Expr max) {
        return Halide::clamp(value, min, max);
    }

    static Halide::Expr exp(Halide::Expr scalar) {
        return Halide::exp(scalar);
    }
    template <typename ExpT>
    static Halide::Expr pow(Halide::Expr base, ExpT exp) {
        return Halide::pow(base, exp);
    }
    static Halide::Expr sqrt(Halide::Expr scalar) {
        return Halide::sqrt(scalar);
    }

};

#endif

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
T exp(T scalar) {
    return math<T>::exp(scalar);
}

template <typename T, typename ScalarT>
T pow(T scalar, ScalarT n) {
    return math<T>::pow(scalar, n);
}


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


template <typename T, typename SelfT, T SelfT::Base_t::* attr1, T SelfT::Base_t::* attr2>
class Swizzle2 {
public:
    Swizzle2(SelfT *self)
        : self(self)
    {}

    operator Vector2Core<T>() const {
        return Vector2Core<T>(
            self->*attr1,
            self->*attr2
        );
    }

    const SelfT *self;
};


template <typename T, typename SelfT, T SelfT::Base_t::* attr1, T SelfT::Base_t::* attr2, T SelfT::Base_t::* attr3>
class Swizzle3 {
public:
    Swizzle3(SelfT *self)
        : self(self)
    {}

    operator Vector3Core<T>() const {
        return Vector3Core<T>(
            self->*attr1,
            self->*attr2,
            self->*attr3
        );
    }

    const SelfT *self;
};


template <typename T, typename SelfT, T SelfT::Base_t::* attr1, T SelfT::Base_t::* attr2, T SelfT::Base_t::* attr3, T SelfT::Base_t::*attr4>
class Swizzle4 {
public:
    Swizzle4(SelfT *self)
        : self(self)
    {}

    operator Vector4Core<T>() const {
        return Vector4Core<T>(
            self->*attr1,
            self->*attr2,
            self->*attr3,
            self->*attr4
        );
    }

    const SelfT *self;
};


#define GLSLIKE_VECTOR2_SWIZZLE() \
    r(this) \
    , g(this) \
    , s(this) \
    , t(this) \
    , xx(this) \
    , xy(this) \
    , yx(this) \
    , yy(this) \
    , rr(this) \
    , rg(this) \
    , gr(this) \
    , gg(this) \
    , ss(this) \
    , st(this) \
    , ts(this) \
    , tt(this) \
    , xxx(this) \
    , xxy(this) \
    , xyx(this) \
    , xyy(this) \
    , yxx(this) \
    , yxy(this) \
    , yyx(this) \
    , yyy(this) \
    , rrr(this) \
    , rrg(this) \
    , rgr(this) \
    , rgg(this) \
    , grr(this) \
    , grg(this) \
    , ggr(this) \
    , ggg(this) \
    , sss(this) \
    , sst(this) \
    , sts(this) \
    , stt(this) \
    , tss(this) \
    , tst(this) \
    , tts(this) \
    , ttt(this) \
    , xxxx(this) \
    , xxxy(this) \
    , xxyx(this) \
    , xxyy(this) \
    , xyxx(this) \
    , xyxy(this) \
    , xyyx(this) \
    , xyyy(this) \
    , yxxx(this) \
    , yxxy(this) \
    , yxyx(this) \
    , yxyy(this) \
    , yyxx(this) \
    , yyxy(this) \
    , yyyx(this) \
    , yyyy(this) \
    , rrrr(this) \
    , rrrg(this) \
    , rrgr(this) \
    , rrgg(this) \
    , rgrr(this) \
    , rgrg(this) \
    , rggr(this) \
    , rggg(this) \
    , grrr(this) \
    , grrg(this) \
    , grgr(this) \
    , grgg(this) \
    , ggrr(this) \
    , ggrg(this) \
    , gggr(this) \
    , gggg(this) \
    , ssss(this) \
    , ssst(this) \
    , ssts(this) \
    , sstt(this) \
    , stss(this) \
    , stst(this) \
    , stts(this) \
    , sttt(this) \
    , tsss(this) \
    , tsst(this) \
    , tsts(this) \
    , tstt(this) \
    , ttss(this) \
    , ttst(this) \
    , ttts(this) \
    , tttt(this)


template <typename T>
class Vector2 : public Vector2Core<T> {
public:
    typedef Vector2Core<T> Base_t;
    typedef T Type_t;
    using Vector2Core<T>::Vector2Core;
    using Vector2Core<T>::x;
    using Vector2Core<T>::y;

public:
    Vector2(T x)
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

    template <typename SwizzleT, typename std::enable_if<std::is_convertible<SwizzleT, Vector2Core<T>>::value>::type * = nullptr>
    Vector2(const SwizzleT &core)
        : Vector2Core<T>::Vector2Core(static_cast<Vector2Core<T>>(core))
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

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

    Vector2<T> normalize() {
        const auto len = length();
        //assert(len != 0.0f);
        return divideScalar(len);
    }

    T length() const {
        return glslike::math<T>::sqrt(x * x + y * y);
    }

    T dot(const Vector2<T> &vec) const {
        return x * vec.x + y * vec.y;
    }

    std::array<T, 2> toArray() const {
        return {x, y};
    }

    //
    // glsl-like interface
    //

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
    alias<T, Vector2<T>, &Vector2Core<T>::x> r;
    alias<T, Vector2<T>, &Vector2Core<T>::y> g;
    // stpq
    alias<T, Vector2<T>, &Vector2Core<T>::x> s;
    alias<T, Vector2<T>, &Vector2Core<T>::y> t;

public:
    // >>> for v in itertools.product("xy", repeat=2): print("".join(v))
    // ...
    // xx
    // xy
    // yx
    // yy
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x> xx;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y> xy;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x> yx;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y> yy;
    // alias rg
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x> rr;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y> rg;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x> gr;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y> gg;
    // alias st
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x> ss;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y> st;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x> ts;
    Swizzle2<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y> tt;

public:
    // >>> for v in itertools.product("xy", repeat=3): print("".join(v))
    // ...
    // xxx
    // xxy
    // xyx
    // xyy
    // yxx
    // yxy
    // yyx
    // yyy
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> xxx;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> xxy;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> xyx;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> xyy;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> yxx;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> yxy;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> yyx;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> yyy;
    // alias rg
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> rrr;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> rrg;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> rgr;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> rgg;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> grr;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> grg;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> ggr;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> ggg;
    // alias st
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> sss;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> sst;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> sts;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> stt;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> tss;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> tst;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> tts;
    Swizzle3<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> ttt;

public:
    // >>> for v in itertools.product("xy", repeat=4): print("".join(v))
    // ...
    // xxxx
    // xxxy
    // xxyx
    // xxyy
    // xyxx
    // xyxy
    // xyyx
    // xyyy
    // yxxx
    // yxxy
    // yxyx
    // yxyy
    // yyxx
    // yyxy
    // yyyx
    // yyyy
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> xxxx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> xxxy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> xxyx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> xxyy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> xyxx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> xyxy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> xyyx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> xyyy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> yxxx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> yxxy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> yxyx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> yxyy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> yyxx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> yyxy;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> yyyx;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> yyyy;
    // alias rg
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> rrrr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> rrrg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> rrgr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> rrgg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> rgrr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> rgrg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> rggr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> rggg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> grrr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> grrg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> grgr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> grgg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> ggrr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> ggrg;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> gggr;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> gggg;
    // alias st
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> ssss;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> ssst;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> ssts;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> sstt;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> stss;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> stst;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> stts;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> sttt;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::x> tsss;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x, &Vector2Core<T>::y> tsst;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::x> tsts;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y, &Vector2Core<T>::y> tstt;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::x> ttss;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x, &Vector2Core<T>::y> ttst;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::x> ttts;
    Swizzle4<T, Vector2<T>, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y, &Vector2Core<T>::y> tttt;

};


template <typename T>
Vector2<T> clamp(const Vector2<T> value, T min, T max) {
    return Vector2<T>(
        math<T>::clamp(value.x, min, max),
        math<T>::clamp(value.y, min, max)
    );
}

template <typename T>
T length(const Vector2<T> &vec) {
    return vec.length();
}

template <typename T>
Vector2<T> normalize(const Vector2<T> &vec) {
    return vec.clone().normalize();
}

template <typename T>
Vector2<T> exp(const Vector2<T> &vec) {
    return Vector2<T>(
        math<T>::exp(vec.x),
        math<T>::exp(vec.y)
    );
}

template <typename T>
Vector2<T> pow(const Vector2<T> &vec, T n) {
    return Vector2<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n)
    );
}

template <typename T>
T dot(const Vector2<T> &a, const Vector2<T> &b) {
    return a.dot(b);
}

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


#define GLSLIKE_VECTOR3_SWIZZLE() \
    r(this) \
    , g(this) \
    , b(this) \
    , s(this) \
    , t(this) \
    , p(this) \
    , xx(this) \
    , xy(this) \
    , xz(this) \
    , yx(this) \
    , yy(this) \
    , yz(this) \
    , zx(this) \
    , zy(this) \
    , zz(this) \
    , rr(this) \
    , rg(this) \
    , rb(this) \
    , gr(this) \
    , gg(this) \
    , gb(this) \
    , br(this) \
    , bg(this) \
    , bb(this) \
    , ss(this) \
    , st(this) \
    , sp(this) \
    , ts(this) \
    , tt(this) \
    , tp(this) \
    , ps(this) \
    , pt(this) \
    , pp(this) \
    , xxx(this) \
    , xxy(this) \
    , xxz(this) \
    , xyx(this) \
    , xyy(this) \
    , xyz(this) \
    , xzx(this) \
    , xzy(this) \
    , xzz(this) \
    , yxx(this) \
    , yxy(this) \
    , yxz(this) \
    , yyx(this) \
    , yyy(this) \
    , yyz(this) \
    , yzx(this) \
    , yzy(this) \
    , yzz(this) \
    , zxx(this) \
    , zxy(this) \
    , zxz(this) \
    , zyx(this) \
    , zyy(this) \
    , zyz(this) \
    , zzx(this) \
    , zzy(this) \
    , zzz(this) \
    , rrr(this) \
    , rrg(this) \
    , rrb(this) \
    , rgr(this) \
    , rgg(this) \
    , rgb(this) \
    , rbr(this) \
    , rbg(this) \
    , rbb(this) \
    , grr(this) \
    , grg(this) \
    , grb(this) \
    , ggr(this) \
    , ggg(this) \
    , ggb(this) \
    , gbr(this) \
    , gbg(this) \
    , gbb(this) \
    , brr(this) \
    , brg(this) \
    , brb(this) \
    , bgr(this) \
    , bgg(this) \
    , bgb(this) \
    , bbr(this) \
    , bbg(this) \
    , bbb(this) \
    , sss(this) \
    , sst(this) \
    , ssp(this) \
    , sts(this) \
    , stt(this) \
    , stp(this) \
    , sps(this) \
    , spt(this) \
    , spp(this) \
    , tss(this) \
    , tst(this) \
    , tsp(this) \
    , tts(this) \
    , ttt(this) \
    , ttp(this) \
    , tps(this) \
    , tpt(this) \
    , tpp(this) \
    , pss(this) \
    , pst(this) \
    , psp(this) \
    , pts(this) \
    , ptt(this) \
    , ptp(this) \
    , pps(this) \
    , ppt(this) \
    , ppp(this) \
    , xxxx(this) \
    , xxxy(this) \
    , xxxz(this) \
    , xxyx(this) \
    , xxyy(this) \
    , xxyz(this) \
    , xxzx(this) \
    , xxzy(this) \
    , xxzz(this) \
    , xyxx(this) \
    , xyxy(this) \
    , xyxz(this) \
    , xyyx(this) \
    , xyyy(this) \
    , xyyz(this) \
    , xyzx(this) \
    , xyzy(this) \
    , xyzz(this) \
    , xzxx(this) \
    , xzxy(this) \
    , xzxz(this) \
    , xzyx(this) \
    , xzyy(this) \
    , xzyz(this) \
    , xzzx(this) \
    , xzzy(this) \
    , xzzz(this) \
    , yxxx(this) \
    , yxxy(this) \
    , yxxz(this) \
    , yxyx(this) \
    , yxyy(this) \
    , yxyz(this) \
    , yxzx(this) \
    , yxzy(this) \
    , yxzz(this) \
    , yyxx(this) \
    , yyxy(this) \
    , yyxz(this) \
    , yyyx(this) \
    , yyyy(this) \
    , yyyz(this) \
    , yyzx(this) \
    , yyzy(this) \
    , yyzz(this) \
    , yzxx(this) \
    , yzxy(this) \
    , yzxz(this) \
    , yzyx(this) \
    , yzyy(this) \
    , yzyz(this) \
    , yzzx(this) \
    , yzzy(this) \
    , yzzz(this) \
    , zxxx(this) \
    , zxxy(this) \
    , zxxz(this) \
    , zxyx(this) \
    , zxyy(this) \
    , zxyz(this) \
    , zxzx(this) \
    , zxzy(this) \
    , zxzz(this) \
    , zyxx(this) \
    , zyxy(this) \
    , zyxz(this) \
    , zyyx(this) \
    , zyyy(this) \
    , zyyz(this) \
    , zyzx(this) \
    , zyzy(this) \
    , zyzz(this) \
    , zzxx(this) \
    , zzxy(this) \
    , zzxz(this) \
    , zzyx(this) \
    , zzyy(this) \
    , zzyz(this) \
    , zzzx(this) \
    , zzzy(this) \
    , zzzz(this) \
    , rrrr(this) \
    , rrrg(this) \
    , rrrb(this) \
    , rrgr(this) \
    , rrgg(this) \
    , rrgb(this) \
    , rrbr(this) \
    , rrbg(this) \
    , rrbb(this) \
    , rgrr(this) \
    , rgrg(this) \
    , rgrb(this) \
    , rggr(this) \
    , rggg(this) \
    , rggb(this) \
    , rgbr(this) \
    , rgbg(this) \
    , rgbb(this) \
    , rbrr(this) \
    , rbrg(this) \
    , rbrb(this) \
    , rbgr(this) \
    , rbgg(this) \
    , rbgb(this) \
    , rbbr(this) \
    , rbbg(this) \
    , rbbb(this) \
    , grrr(this) \
    , grrg(this) \
    , grrb(this) \
    , grgr(this) \
    , grgg(this) \
    , grgb(this) \
    , grbr(this) \
    , grbg(this) \
    , grbb(this) \
    , ggrr(this) \
    , ggrg(this) \
    , ggrb(this) \
    , gggr(this) \
    , gggg(this) \
    , gggb(this) \
    , ggbr(this) \
    , ggbg(this) \
    , ggbb(this) \
    , gbrr(this) \
    , gbrg(this) \
    , gbrb(this) \
    , gbgr(this) \
    , gbgg(this) \
    , gbgb(this) \
    , gbbr(this) \
    , gbbg(this) \
    , gbbb(this) \
    , brrr(this) \
    , brrg(this) \
    , brrb(this) \
    , brgr(this) \
    , brgg(this) \
    , brgb(this) \
    , brbr(this) \
    , brbg(this) \
    , brbb(this) \
    , bgrr(this) \
    , bgrg(this) \
    , bgrb(this) \
    , bggr(this) \
    , bggg(this) \
    , bggb(this) \
    , bgbr(this) \
    , bgbg(this) \
    , bgbb(this) \
    , bbrr(this) \
    , bbrg(this) \
    , bbrb(this) \
    , bbgr(this) \
    , bbgg(this) \
    , bbgb(this) \
    , bbbr(this) \
    , bbbg(this) \
    , bbbb(this) \
    , ssss(this) \
    , ssst(this) \
    , sssp(this) \
    , ssts(this) \
    , sstt(this) \
    , sstp(this) \
    , ssps(this) \
    , sspt(this) \
    , sspp(this) \
    , stss(this) \
    , stst(this) \
    , stsp(this) \
    , stts(this) \
    , sttt(this) \
    , sttp(this) \
    , stps(this) \
    , stpt(this) \
    , stpp(this) \
    , spss(this) \
    , spst(this) \
    , spsp(this) \
    , spts(this) \
    , sptt(this) \
    , sptp(this) \
    , spps(this) \
    , sppt(this) \
    , sppp(this) \
    , tsss(this) \
    , tsst(this) \
    , tssp(this) \
    , tsts(this) \
    , tstt(this) \
    , tstp(this) \
    , tsps(this) \
    , tspt(this) \
    , tspp(this) \
    , ttss(this) \
    , ttst(this) \
    , ttsp(this) \
    , ttts(this) \
    , tttt(this) \
    , tttp(this) \
    , ttps(this) \
    , ttpt(this) \
    , ttpp(this) \
    , tpss(this) \
    , tpst(this) \
    , tpsp(this) \
    , tpts(this) \
    , tptt(this) \
    , tptp(this) \
    , tpps(this) \
    , tppt(this) \
    , tppp(this) \
    , psss(this) \
    , psst(this) \
    , pssp(this) \
    , psts(this) \
    , pstt(this) \
    , pstp(this) \
    , psps(this) \
    , pspt(this) \
    , pspp(this) \
    , ptss(this) \
    , ptst(this) \
    , ptsp(this) \
    , ptts(this) \
    , pttt(this) \
    , pttp(this) \
    , ptps(this) \
    , ptpt(this) \
    , ptpp(this) \
    , ppss(this) \
    , ppst(this) \
    , ppsp(this) \
    , ppts(this) \
    , pptt(this) \
    , pptp(this) \
    , ppps(this) \
    , pppt(this) \
    , pppp(this)


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
    Vector3(T x)
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

    template <typename SwizzleT, typename std::enable_if<std::is_convertible<SwizzleT, Vector3Core<T>>::value>::type * = nullptr>
    Vector3(const SwizzleT &core)
        : Vector3Core<T>::Vector3Core(static_cast<Vector3Core<T>>(core))
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

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

    Vector3<T> normalize() {
        const auto len = length();
        //assert(len != 0.0f);
        return divideScalar(len);
    }

    T length() const {
        return glslike::math<T>::sqrt(x * x + y * y + z * z);
    }

    T dot(const Vector3<T> &vec) const {
        return x * vec.x + y * vec.y + z * vec.z;
    }

    std::array<T, 3> toArray() const {
        return {x, y, z};
    }

    //
    // glsl-like interface
    //

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
    alias<T, Vector3<T>, &Vector3Core<T>::x> r;
    alias<T, Vector3<T>, &Vector3Core<T>::y> g;
    alias<T, Vector3<T>, &Vector3Core<T>::z> b;
    alias<T, Vector3<T>, &Vector3Core<T>::x> s;
    alias<T, Vector3<T>, &Vector3Core<T>::y> t;
    alias<T, Vector3<T>, &Vector3Core<T>::z> p;

public:
    // >>> for v in itertools.product("xyz", repeat=2): print("".join(v))
    // ...
    // xx
    // xy
    // xz
    // yx
    // yy
    // yz
    // zx
    // zy
    // zz
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x> xx;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y> xy;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z> xz;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x> yx;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y> yy;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z> yz;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x> zx;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y> zy;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z> zz;
    // alias rgb
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x> rr;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y> rg;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z> rb;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x> gr;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y> gg;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z> gb;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x> br;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y> bg;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z> bb;
    // alias stp
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x> ss;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y> st;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z> sp;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x> ts;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y> tt;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z> tp;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x> ps;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y> pt;
    Swizzle2<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z> pp;

public:
    // >>> for v in itertools.product("xyz", repeat=3): print("".join(v))
    // ...
    // xxx
    // xxy
    // xxz
    // xyx
    // xyy
    // xyz
    // xzx
    // xzy
    // xzz
    // yxx
    // yxy
    // yxz
    // yyx
    // yyy
    // yyz
    // yzx
    // yzy
    // yzz
    // zxx
    // zxy
    // zxz
    // zyx
    // zyy
    // zyz
    // zzx
    // zzy
    // zzz
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> xxx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> xxy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> xxz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> xyx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> xyy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> xyz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> xzx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> xzy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> xzz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> yxx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> yxy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> yxz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> yyx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> yyy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> yyz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> yzx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> yzy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> yzz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> zxx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> zxy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> zxz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> zyx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> zyy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> zyz;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> zzx;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> zzy;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> zzz;
    // alias rgb
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> rrr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> rrg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> rrb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> rgr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> rgg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> rgb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> rbr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> rbg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> rbb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> grr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> grg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> grb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> ggr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> ggg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> ggb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> gbr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> gbg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> gbb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> brr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> brg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> brb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> bgr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> bgg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> bgb;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> bbr;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> bbg;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> bbb;
    // alias stp
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> sss;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> sst;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> ssp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> sts;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> stt;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> stp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> sps;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> spt;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> spp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> tss;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> tst;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> tsp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> tts;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> ttt;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> ttp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> tps;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> tpt;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> tpp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> pss;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> pst;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> psp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> pts;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> ptt;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> ptp;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> pps;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> ppt;
    Swizzle3<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> ppp;

public:
    // >>> for v in itertools.product("xyz", repeat=4): print("".join(v))
    // ...
    // xxxx
    // xxxy
    // xxxz
    // xxyx
    // xxyy
    // xxyz
    // xxzx
    // xxzy
    // xxzz
    // xyxx
    // xyxy
    // xyxz
    // xyyx
    // xyyy
    // xyyz
    // xyzx
    // xyzy
    // xyzz
    // xzxx
    // xzxy
    // xzxz
    // xzyx
    // xzyy
    // xzyz
    // xzzx
    // xzzy
    // xzzz
    // yxxx
    // yxxy
    // yxxz
    // yxyx
    // yxyy
    // yxyz
    // yxzx
    // yxzy
    // yxzz
    // yyxx
    // yyxy
    // yyxz
    // yyyx
    // yyyy
    // yyyz
    // yyzx
    // yyzy
    // yyzz
    // yzxx
    // yzxy
    // yzxz
    // yzyx
    // yzyy
    // yzyz
    // yzzx
    // yzzy
    // yzzz
    // zxxx
    // zxxy
    // zxxz
    // zxyx
    // zxyy
    // zxyz
    // zxzx
    // zxzy
    // zxzz
    // zyxx
    // zyxy
    // zyxz
    // zyyx
    // zyyy
    // zyyz
    // zyzx
    // zyzy
    // zyzz
    // zzxx
    // zzxy
    // zzxz
    // zzyx
    // zzyy
    // zzyz
    // zzzx
    // zzzy
    // zzzz
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> xxxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> xxxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> xxxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> xxyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> xxyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> xxyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> xxzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> xxzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> xxzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> xyxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> xyxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> xyxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> xyyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> xyyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> xyyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> xyzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> xyzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> xyzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> xzxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> xzxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> xzxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> xzyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> xzyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> xzyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> xzzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> xzzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> xzzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> yxxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> yxxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> yxxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> yxyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> yxyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> yxyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> yxzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> yxzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> yxzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> yyxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> yyxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> yyxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> yyyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> yyyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> yyyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> yyzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> yyzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> yyzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> yzxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> yzxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> yzxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> yzyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> yzyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> yzyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> yzzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> yzzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> yzzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> zxxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> zxxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> zxxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> zxyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> zxyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> zxyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> zxzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> zxzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> zxzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> zyxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> zyxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> zyxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> zyyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> zyyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> zyyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> zyzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> zyzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> zyzz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> zzxx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> zzxy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> zzxz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> zzyx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> zzyy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> zzyz;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> zzzx;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> zzzy;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> zzzz;
    // alias rgb
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> rrrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> rrrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> rrrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> rrgr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> rrgg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> rrgb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> rrbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> rrbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> rrbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> rgrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> rgrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> rgrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> rggr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> rggg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> rggb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> rgbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> rgbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> rgbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> rbrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> rbrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> rbrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> rbgr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> rbgg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> rbgb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> rbbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> rbbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> rbbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> grrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> grrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> grrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> grgr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> grgg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> grgb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> grbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> grbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> grbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> ggrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> ggrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> ggrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> gggr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> gggg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> gggb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> ggbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> ggbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> ggbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> gbrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> gbrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> gbrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> gbgr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> gbgg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> gbgb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> gbbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> gbbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> gbbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> brrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> brrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> brrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> brgr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> brgg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> brgb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> brbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> brbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> brbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> bgrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> bgrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> bgrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> bggr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> bggg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> bggb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> bgbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> bgbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> bgbb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> bbrr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> bbrg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> bbrb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> bbgr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> bbgg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> bbgb;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> bbbr;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> bbbg;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> bbbb;
    // alias stp
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> ssss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> ssst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> sssp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> ssts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> sstt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> sstp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> ssps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> sspt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> sspp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> stss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> stst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> stsp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> stts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> sttt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> sttp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> stps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> stpt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> stpp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> spss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> spst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> spsp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> spts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> sptt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> sptp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> spps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> sppt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> sppp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> tsss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> tsst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> tssp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> tsts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> tstt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> tstp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> tsps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> tspt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> tspp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> ttss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> ttst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> ttsp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> ttts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> tttt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> tttp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> ttps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> ttpt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> ttpp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> tpss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> tpst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> tpsp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> tpts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> tptt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> tptp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> tpps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> tppt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> tppp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::x> psss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::y> psst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x, &Vector3Core<T>::z> pssp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::x> psts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::y> pstt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y, &Vector3Core<T>::z> pstp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::x> psps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::y> pspt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z, &Vector3Core<T>::z> pspp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::x> ptss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::y> ptst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x, &Vector3Core<T>::z> ptsp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::x> ptts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::y> pttt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y, &Vector3Core<T>::z> pttp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::x> ptps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::y> ptpt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z, &Vector3Core<T>::z> ptpp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::x> ppss;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::y> ppst;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x, &Vector3Core<T>::z> ppsp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::x> ppts;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::y> pptt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y, &Vector3Core<T>::z> pptp;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::x> ppps;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::y> pppt;
    Swizzle4<T, Vector3<T>, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z, &Vector3Core<T>::z> pppp;

};

template <typename T>
Vector3<T> clamp(const Vector3<T> value, T min, T max) {
    return Vector3<T>(
        math<T>::clamp(value.x, min, max),
        math<T>::clamp(value.y, min, max),
        math<T>::clamp(value.z, min, max)
    );
}

template <typename T>
T length(const Vector3<T> &vec) {
    return vec.length();
}

template <typename T>
Vector3<T> normalize(const Vector3<T> &vec) {
    return vec.clone().normalize();
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
Vector3<T> pow(const Vector3<T> &vec, T n) {
    return Vector3<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n),
        math<T>::pow(vec.z, n)
    );
}

template <typename T>
T dot(const Vector3<T> &a, const Vector3<T> &b) {
    return a.dot(b);
}

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


#define GLSLIKE_VECTOR4_SWIZZLE() \
    r(this) \
    , g(this) \
    , b(this) \
    , a(this) \
    , s(this) \
    , t(this) \
    , p(this) \
    , q(this) \
    , xx(this) \
    , xy(this) \
    , xz(this) \
    , xw(this) \
    , yx(this) \
    , yy(this) \
    , yz(this) \
    , yw(this) \
    , zx(this) \
    , zy(this) \
    , zz(this) \
    , zw(this) \
    , wx(this) \
    , wy(this) \
    , wz(this) \
    , ww(this) \
    , rr(this) \
    , rg(this) \
    , rb(this) \
    , ra(this) \
    , gr(this) \
    , gg(this) \
    , gb(this) \
    , ga(this) \
    , br(this) \
    , bg(this) \
    , bb(this) \
    , ba(this) \
    , ar(this) \
    , ag(this) \
    , ab(this) \
    , aa(this) \
    , ss(this) \
    , st(this) \
    , sp(this) \
    , sq(this) \
    , ts(this) \
    , tt(this) \
    , tp(this) \
    , tq(this) \
    , ps(this) \
    , pt(this) \
    , pp(this) \
    , pq(this) \
    , qs(this) \
    , qt(this) \
    , qp(this) \
    , qq(this) \
    , xxx(this) \
    , xxy(this) \
    , xxz(this) \
    , xxw(this) \
    , xyx(this) \
    , xyy(this) \
    , xyz(this) \
    , xyw(this) \
    , xzx(this) \
    , xzy(this) \
    , xzz(this) \
    , xzw(this) \
    , xwx(this) \
    , xwy(this) \
    , xwz(this) \
    , xww(this) \
    , yxx(this) \
    , yxy(this) \
    , yxz(this) \
    , yxw(this) \
    , yyx(this) \
    , yyy(this) \
    , yyz(this) \
    , yyw(this) \
    , yzx(this) \
    , yzy(this) \
    , yzz(this) \
    , yzw(this) \
    , ywx(this) \
    , ywy(this) \
    , ywz(this) \
    , yww(this) \
    , zxx(this) \
    , zxy(this) \
    , zxz(this) \
    , zxw(this) \
    , zyx(this) \
    , zyy(this) \
    , zyz(this) \
    , zyw(this) \
    , zzx(this) \
    , zzy(this) \
    , zzz(this) \
    , zzw(this) \
    , zwx(this) \
    , zwy(this) \
    , zwz(this) \
    , zww(this) \
    , wxx(this) \
    , wxy(this) \
    , wxz(this) \
    , wxw(this) \
    , wyx(this) \
    , wyy(this) \
    , wyz(this) \
    , wyw(this) \
    , wzx(this) \
    , wzy(this) \
    , wzz(this) \
    , wzw(this) \
    , wwx(this) \
    , wwy(this) \
    , wwz(this) \
    , www(this) \
    , rrr(this) \
    , rrg(this) \
    , rrb(this) \
    , rra(this) \
    , rgr(this) \
    , rgg(this) \
    , rgb(this) \
    , rga(this) \
    , rbr(this) \
    , rbg(this) \
    , rbb(this) \
    , rba(this) \
    , rar(this) \
    , rag(this) \
    , rab(this) \
    , raa(this) \
    , grr(this) \
    , grg(this) \
    , grb(this) \
    , gra(this) \
    , ggr(this) \
    , ggg(this) \
    , ggb(this) \
    , gga(this) \
    , gbr(this) \
    , gbg(this) \
    , gbb(this) \
    , gba(this) \
    , gar(this) \
    , gag(this) \
    , gab(this) \
    , gaa(this) \
    , brr(this) \
    , brg(this) \
    , brb(this) \
    , bra(this) \
    , bgr(this) \
    , bgg(this) \
    , bgb(this) \
    , bga(this) \
    , bbr(this) \
    , bbg(this) \
    , bbb(this) \
    , bba(this) \
    , bar(this) \
    , bag(this) \
    , bab(this) \
    , baa(this) \
    , arr(this) \
    , arg(this) \
    , arb(this) \
    , ara(this) \
    , agr(this) \
    , agg(this) \
    , agb(this) \
    , aga(this) \
    , abr(this) \
    , abg(this) \
    , abb(this) \
    , aba(this) \
    , aar(this) \
    , aag(this) \
    , aab(this) \
    , aaa(this) \
    , sss(this) \
    , sst(this) \
    , ssp(this) \
    , ssq(this) \
    , sts(this) \
    , stt(this) \
    , stp(this) \
    , stq(this) \
    , sps(this) \
    , spt(this) \
    , spp(this) \
    , spq(this) \
    , sqs(this) \
    , sqt(this) \
    , sqp(this) \
    , sqq(this) \
    , tss(this) \
    , tst(this) \
    , tsp(this) \
    , tsq(this) \
    , tts(this) \
    , ttt(this) \
    , ttp(this) \
    , ttq(this) \
    , tps(this) \
    , tpt(this) \
    , tpp(this) \
    , tpq(this) \
    , tqs(this) \
    , tqt(this) \
    , tqp(this) \
    , tqq(this) \
    , pss(this) \
    , pst(this) \
    , psp(this) \
    , psq(this) \
    , pts(this) \
    , ptt(this) \
    , ptp(this) \
    , ptq(this) \
    , pps(this) \
    , ppt(this) \
    , ppp(this) \
    , ppq(this) \
    , pqs(this) \
    , pqt(this) \
    , pqp(this) \
    , pqq(this) \
    , qss(this) \
    , qst(this) \
    , qsp(this) \
    , qsq(this) \
    , qts(this) \
    , qtt(this) \
    , qtp(this) \
    , qtq(this) \
    , qps(this) \
    , qpt(this) \
    , qpp(this) \
    , qpq(this) \
    , qqs(this) \
    , qqt(this) \
    , qqp(this) \
    , qqq(this) \
    , xxxx(this) \
    , xxxy(this) \
    , xxxz(this) \
    , xxxw(this) \
    , xxyx(this) \
    , xxyy(this) \
    , xxyz(this) \
    , xxyw(this) \
    , xxzx(this) \
    , xxzy(this) \
    , xxzz(this) \
    , xxzw(this) \
    , xxwx(this) \
    , xxwy(this) \
    , xxwz(this) \
    , xxww(this) \
    , xyxx(this) \
    , xyxy(this) \
    , xyxz(this) \
    , xyxw(this) \
    , xyyx(this) \
    , xyyy(this) \
    , xyyz(this) \
    , xyyw(this) \
    , xyzx(this) \
    , xyzy(this) \
    , xyzz(this) \
    , xyzw(this) \
    , xywx(this) \
    , xywy(this) \
    , xywz(this) \
    , xyww(this) \
    , xzxx(this) \
    , xzxy(this) \
    , xzxz(this) \
    , xzxw(this) \
    , xzyx(this) \
    , xzyy(this) \
    , xzyz(this) \
    , xzyw(this) \
    , xzzx(this) \
    , xzzy(this) \
    , xzzz(this) \
    , xzzw(this) \
    , xzwx(this) \
    , xzwy(this) \
    , xzwz(this) \
    , xzww(this) \
    , xwxx(this) \
    , xwxy(this) \
    , xwxz(this) \
    , xwxw(this) \
    , xwyx(this) \
    , xwyy(this) \
    , xwyz(this) \
    , xwyw(this) \
    , xwzx(this) \
    , xwzy(this) \
    , xwzz(this) \
    , xwzw(this) \
    , xwwx(this) \
    , xwwy(this) \
    , xwwz(this) \
    , xwww(this) \
    , yxxx(this) \
    , yxxy(this) \
    , yxxz(this) \
    , yxxw(this) \
    , yxyx(this) \
    , yxyy(this) \
    , yxyz(this) \
    , yxyw(this) \
    , yxzx(this) \
    , yxzy(this) \
    , yxzz(this) \
    , yxzw(this) \
    , yxwx(this) \
    , yxwy(this) \
    , yxwz(this) \
    , yxww(this) \
    , yyxx(this) \
    , yyxy(this) \
    , yyxz(this) \
    , yyxw(this) \
    , yyyx(this) \
    , yyyy(this) \
    , yyyz(this) \
    , yyyw(this) \
    , yyzx(this) \
    , yyzy(this) \
    , yyzz(this) \
    , yyzw(this) \
    , yywx(this) \
    , yywy(this) \
    , yywz(this) \
    , yyww(this) \
    , yzxx(this) \
    , yzxy(this) \
    , yzxz(this) \
    , yzxw(this) \
    , yzyx(this) \
    , yzyy(this) \
    , yzyz(this) \
    , yzyw(this) \
    , yzzx(this) \
    , yzzy(this) \
    , yzzz(this) \
    , yzzw(this) \
    , yzwx(this) \
    , yzwy(this) \
    , yzwz(this) \
    , yzww(this) \
    , ywxx(this) \
    , ywxy(this) \
    , ywxz(this) \
    , ywxw(this) \
    , ywyx(this) \
    , ywyy(this) \
    , ywyz(this) \
    , ywyw(this) \
    , ywzx(this) \
    , ywzy(this) \
    , ywzz(this) \
    , ywzw(this) \
    , ywwx(this) \
    , ywwy(this) \
    , ywwz(this) \
    , ywww(this) \
    , zxxx(this) \
    , zxxy(this) \
    , zxxz(this) \
    , zxxw(this) \
    , zxyx(this) \
    , zxyy(this) \
    , zxyz(this) \
    , zxyw(this) \
    , zxzx(this) \
    , zxzy(this) \
    , zxzz(this) \
    , zxzw(this) \
    , zxwx(this) \
    , zxwy(this) \
    , zxwz(this) \
    , zxww(this) \
    , zyxx(this) \
    , zyxy(this) \
    , zyxz(this) \
    , zyxw(this) \
    , zyyx(this) \
    , zyyy(this) \
    , zyyz(this) \
    , zyyw(this) \
    , zyzx(this) \
    , zyzy(this) \
    , zyzz(this) \
    , zyzw(this) \
    , zywx(this) \
    , zywy(this) \
    , zywz(this) \
    , zyww(this) \
    , zzxx(this) \
    , zzxy(this) \
    , zzxz(this) \
    , zzxw(this) \
    , zzyx(this) \
    , zzyy(this) \
    , zzyz(this) \
    , zzyw(this) \
    , zzzx(this) \
    , zzzy(this) \
    , zzzz(this) \
    , zzzw(this) \
    , zzwx(this) \
    , zzwy(this) \
    , zzwz(this) \
    , zzww(this) \
    , zwxx(this) \
    , zwxy(this) \
    , zwxz(this) \
    , zwxw(this) \
    , zwyx(this) \
    , zwyy(this) \
    , zwyz(this) \
    , zwyw(this) \
    , zwzx(this) \
    , zwzy(this) \
    , zwzz(this) \
    , zwzw(this) \
    , zwwx(this) \
    , zwwy(this) \
    , zwwz(this) \
    , zwww(this) \
    , wxxx(this) \
    , wxxy(this) \
    , wxxz(this) \
    , wxxw(this) \
    , wxyx(this) \
    , wxyy(this) \
    , wxyz(this) \
    , wxyw(this) \
    , wxzx(this) \
    , wxzy(this) \
    , wxzz(this) \
    , wxzw(this) \
    , wxwx(this) \
    , wxwy(this) \
    , wxwz(this) \
    , wxww(this) \
    , wyxx(this) \
    , wyxy(this) \
    , wyxz(this) \
    , wyxw(this) \
    , wyyx(this) \
    , wyyy(this) \
    , wyyz(this) \
    , wyyw(this) \
    , wyzx(this) \
    , wyzy(this) \
    , wyzz(this) \
    , wyzw(this) \
    , wywx(this) \
    , wywy(this) \
    , wywz(this) \
    , wyww(this) \
    , wzxx(this) \
    , wzxy(this) \
    , wzxz(this) \
    , wzxw(this) \
    , wzyx(this) \
    , wzyy(this) \
    , wzyz(this) \
    , wzyw(this) \
    , wzzx(this) \
    , wzzy(this) \
    , wzzz(this) \
    , wzzw(this) \
    , wzwx(this) \
    , wzwy(this) \
    , wzwz(this) \
    , wzww(this) \
    , wwxx(this) \
    , wwxy(this) \
    , wwxz(this) \
    , wwxw(this) \
    , wwyx(this) \
    , wwyy(this) \
    , wwyz(this) \
    , wwyw(this) \
    , wwzx(this) \
    , wwzy(this) \
    , wwzz(this) \
    , wwzw(this) \
    , wwwx(this) \
    , wwwy(this) \
    , wwwz(this) \
    , wwww(this) \
    , rrrr(this) \
    , rrrg(this) \
    , rrrb(this) \
    , rrra(this) \
    , rrgr(this) \
    , rrgg(this) \
    , rrgb(this) \
    , rrga(this) \
    , rrbr(this) \
    , rrbg(this) \
    , rrbb(this) \
    , rrba(this) \
    , rrar(this) \
    , rrag(this) \
    , rrab(this) \
    , rraa(this) \
    , rgrr(this) \
    , rgrg(this) \
    , rgrb(this) \
    , rgra(this) \
    , rggr(this) \
    , rggg(this) \
    , rggb(this) \
    , rgga(this) \
    , rgbr(this) \
    , rgbg(this) \
    , rgbb(this) \
    , rgba(this) \
    , rgar(this) \
    , rgag(this) \
    , rgab(this) \
    , rgaa(this) \
    , rbrr(this) \
    , rbrg(this) \
    , rbrb(this) \
    , rbra(this) \
    , rbgr(this) \
    , rbgg(this) \
    , rbgb(this) \
    , rbga(this) \
    , rbbr(this) \
    , rbbg(this) \
    , rbbb(this) \
    , rbba(this) \
    , rbar(this) \
    , rbag(this) \
    , rbab(this) \
    , rbaa(this) \
    , rarr(this) \
    , rarg(this) \
    , rarb(this) \
    , rara(this) \
    , ragr(this) \
    , ragg(this) \
    , ragb(this) \
    , raga(this) \
    , rabr(this) \
    , rabg(this) \
    , rabb(this) \
    , raba(this) \
    , raar(this) \
    , raag(this) \
    , raab(this) \
    , raaa(this) \
    , grrr(this) \
    , grrg(this) \
    , grrb(this) \
    , grra(this) \
    , grgr(this) \
    , grgg(this) \
    , grgb(this) \
    , grga(this) \
    , grbr(this) \
    , grbg(this) \
    , grbb(this) \
    , grba(this) \
    , grar(this) \
    , grag(this) \
    , grab(this) \
    , graa(this) \
    , ggrr(this) \
    , ggrg(this) \
    , ggrb(this) \
    , ggra(this) \
    , gggr(this) \
    , gggg(this) \
    , gggb(this) \
    , ggga(this) \
    , ggbr(this) \
    , ggbg(this) \
    , ggbb(this) \
    , ggba(this) \
    , ggar(this) \
    , ggag(this) \
    , ggab(this) \
    , ggaa(this) \
    , gbrr(this) \
    , gbrg(this) \
    , gbrb(this) \
    , gbra(this) \
    , gbgr(this) \
    , gbgg(this) \
    , gbgb(this) \
    , gbga(this) \
    , gbbr(this) \
    , gbbg(this) \
    , gbbb(this) \
    , gbba(this) \
    , gbar(this) \
    , gbag(this) \
    , gbab(this) \
    , gbaa(this) \
    , garr(this) \
    , garg(this) \
    , garb(this) \
    , gara(this) \
    , gagr(this) \
    , gagg(this) \
    , gagb(this) \
    , gaga(this) \
    , gabr(this) \
    , gabg(this) \
    , gabb(this) \
    , gaba(this) \
    , gaar(this) \
    , gaag(this) \
    , gaab(this) \
    , gaaa(this) \
    , brrr(this) \
    , brrg(this) \
    , brrb(this) \
    , brra(this) \
    , brgr(this) \
    , brgg(this) \
    , brgb(this) \
    , brga(this) \
    , brbr(this) \
    , brbg(this) \
    , brbb(this) \
    , brba(this) \
    , brar(this) \
    , brag(this) \
    , brab(this) \
    , braa(this) \
    , bgrr(this) \
    , bgrg(this) \
    , bgrb(this) \
    , bgra(this) \
    , bggr(this) \
    , bggg(this) \
    , bggb(this) \
    , bgga(this) \
    , bgbr(this) \
    , bgbg(this) \
    , bgbb(this) \
    , bgba(this) \
    , bgar(this) \
    , bgag(this) \
    , bgab(this) \
    , bgaa(this) \
    , bbrr(this) \
    , bbrg(this) \
    , bbrb(this) \
    , bbra(this) \
    , bbgr(this) \
    , bbgg(this) \
    , bbgb(this) \
    , bbga(this) \
    , bbbr(this) \
    , bbbg(this) \
    , bbbb(this) \
    , bbba(this) \
    , bbar(this) \
    , bbag(this) \
    , bbab(this) \
    , bbaa(this) \
    , barr(this) \
    , barg(this) \
    , barb(this) \
    , bara(this) \
    , bagr(this) \
    , bagg(this) \
    , bagb(this) \
    , baga(this) \
    , babr(this) \
    , babg(this) \
    , babb(this) \
    , baba(this) \
    , baar(this) \
    , baag(this) \
    , baab(this) \
    , baaa(this) \
    , arrr(this) \
    , arrg(this) \
    , arrb(this) \
    , arra(this) \
    , argr(this) \
    , argg(this) \
    , argb(this) \
    , arga(this) \
    , arbr(this) \
    , arbg(this) \
    , arbb(this) \
    , arba(this) \
    , arar(this) \
    , arag(this) \
    , arab(this) \
    , araa(this) \
    , agrr(this) \
    , agrg(this) \
    , agrb(this) \
    , agra(this) \
    , aggr(this) \
    , aggg(this) \
    , aggb(this) \
    , agga(this) \
    , agbr(this) \
    , agbg(this) \
    , agbb(this) \
    , agba(this) \
    , agar(this) \
    , agag(this) \
    , agab(this) \
    , agaa(this) \
    , abrr(this) \
    , abrg(this) \
    , abrb(this) \
    , abra(this) \
    , abgr(this) \
    , abgg(this) \
    , abgb(this) \
    , abga(this) \
    , abbr(this) \
    , abbg(this) \
    , abbb(this) \
    , abba(this) \
    , abar(this) \
    , abag(this) \
    , abab(this) \
    , abaa(this) \
    , aarr(this) \
    , aarg(this) \
    , aarb(this) \
    , aara(this) \
    , aagr(this) \
    , aagg(this) \
    , aagb(this) \
    , aaga(this) \
    , aabr(this) \
    , aabg(this) \
    , aabb(this) \
    , aaba(this) \
    , aaar(this) \
    , aaag(this) \
    , aaab(this) \
    , aaaa(this) \
    , ssss(this) \
    , ssst(this) \
    , sssp(this) \
    , sssq(this) \
    , ssts(this) \
    , sstt(this) \
    , sstp(this) \
    , sstq(this) \
    , ssps(this) \
    , sspt(this) \
    , sspp(this) \
    , sspq(this) \
    , ssqs(this) \
    , ssqt(this) \
    , ssqp(this) \
    , ssqq(this) \
    , stss(this) \
    , stst(this) \
    , stsp(this) \
    , stsq(this) \
    , stts(this) \
    , sttt(this) \
    , sttp(this) \
    , sttq(this) \
    , stps(this) \
    , stpt(this) \
    , stpp(this) \
    , stpq(this) \
    , stqs(this) \
    , stqt(this) \
    , stqp(this) \
    , stqq(this) \
    , spss(this) \
    , spst(this) \
    , spsp(this) \
    , spsq(this) \
    , spts(this) \
    , sptt(this) \
    , sptp(this) \
    , sptq(this) \
    , spps(this) \
    , sppt(this) \
    , sppp(this) \
    , sppq(this) \
    , spqs(this) \
    , spqt(this) \
    , spqp(this) \
    , spqq(this) \
    , sqss(this) \
    , sqst(this) \
    , sqsp(this) \
    , sqsq(this) \
    , sqts(this) \
    , sqtt(this) \
    , sqtp(this) \
    , sqtq(this) \
    , sqps(this) \
    , sqpt(this) \
    , sqpp(this) \
    , sqpq(this) \
    , sqqs(this) \
    , sqqt(this) \
    , sqqp(this) \
    , sqqq(this) \
    , tsss(this) \
    , tsst(this) \
    , tssp(this) \
    , tssq(this) \
    , tsts(this) \
    , tstt(this) \
    , tstp(this) \
    , tstq(this) \
    , tsps(this) \
    , tspt(this) \
    , tspp(this) \
    , tspq(this) \
    , tsqs(this) \
    , tsqt(this) \
    , tsqp(this) \
    , tsqq(this) \
    , ttss(this) \
    , ttst(this) \
    , ttsp(this) \
    , ttsq(this) \
    , ttts(this) \
    , tttt(this) \
    , tttp(this) \
    , tttq(this) \
    , ttps(this) \
    , ttpt(this) \
    , ttpp(this) \
    , ttpq(this) \
    , ttqs(this) \
    , ttqt(this) \
    , ttqp(this) \
    , ttqq(this) \
    , tpss(this) \
    , tpst(this) \
    , tpsp(this) \
    , tpsq(this) \
    , tpts(this) \
    , tptt(this) \
    , tptp(this) \
    , tptq(this) \
    , tpps(this) \
    , tppt(this) \
    , tppp(this) \
    , tppq(this) \
    , tpqs(this) \
    , tpqt(this) \
    , tpqp(this) \
    , tpqq(this) \
    , tqss(this) \
    , tqst(this) \
    , tqsp(this) \
    , tqsq(this) \
    , tqts(this) \
    , tqtt(this) \
    , tqtp(this) \
    , tqtq(this) \
    , tqps(this) \
    , tqpt(this) \
    , tqpp(this) \
    , tqpq(this) \
    , tqqs(this) \
    , tqqt(this) \
    , tqqp(this) \
    , tqqq(this) \
    , psss(this) \
    , psst(this) \
    , pssp(this) \
    , pssq(this) \
    , psts(this) \
    , pstt(this) \
    , pstp(this) \
    , pstq(this) \
    , psps(this) \
    , pspt(this) \
    , pspp(this) \
    , pspq(this) \
    , psqs(this) \
    , psqt(this) \
    , psqp(this) \
    , psqq(this) \
    , ptss(this) \
    , ptst(this) \
    , ptsp(this) \
    , ptsq(this) \
    , ptts(this) \
    , pttt(this) \
    , pttp(this) \
    , pttq(this) \
    , ptps(this) \
    , ptpt(this) \
    , ptpp(this) \
    , ptpq(this) \
    , ptqs(this) \
    , ptqt(this) \
    , ptqp(this) \
    , ptqq(this) \
    , ppss(this) \
    , ppst(this) \
    , ppsp(this) \
    , ppsq(this) \
    , ppts(this) \
    , pptt(this) \
    , pptp(this) \
    , pptq(this) \
    , ppps(this) \
    , pppt(this) \
    , pppp(this) \
    , pppq(this) \
    , ppqs(this) \
    , ppqt(this) \
    , ppqp(this) \
    , ppqq(this) \
    , pqss(this) \
    , pqst(this) \
    , pqsp(this) \
    , pqsq(this) \
    , pqts(this) \
    , pqtt(this) \
    , pqtp(this) \
    , pqtq(this) \
    , pqps(this) \
    , pqpt(this) \
    , pqpp(this) \
    , pqpq(this) \
    , pqqs(this) \
    , pqqt(this) \
    , pqqp(this) \
    , pqqq(this) \
    , qsss(this) \
    , qsst(this) \
    , qssp(this) \
    , qssq(this) \
    , qsts(this) \
    , qstt(this) \
    , qstp(this) \
    , qstq(this) \
    , qsps(this) \
    , qspt(this) \
    , qspp(this) \
    , qspq(this) \
    , qsqs(this) \
    , qsqt(this) \
    , qsqp(this) \
    , qsqq(this) \
    , qtss(this) \
    , qtst(this) \
    , qtsp(this) \
    , qtsq(this) \
    , qtts(this) \
    , qttt(this) \
    , qttp(this) \
    , qttq(this) \
    , qtps(this) \
    , qtpt(this) \
    , qtpp(this) \
    , qtpq(this) \
    , qtqs(this) \
    , qtqt(this) \
    , qtqp(this) \
    , qtqq(this) \
    , qpss(this) \
    , qpst(this) \
    , qpsp(this) \
    , qpsq(this) \
    , qpts(this) \
    , qptt(this) \
    , qptp(this) \
    , qptq(this) \
    , qpps(this) \
    , qppt(this) \
    , qppp(this) \
    , qppq(this) \
    , qpqs(this) \
    , qpqt(this) \
    , qpqp(this) \
    , qpqq(this) \
    , qqss(this) \
    , qqst(this) \
    , qqsp(this) \
    , qqsq(this) \
    , qqts(this) \
    , qqtt(this) \
    , qqtp(this) \
    , qqtq(this) \
    , qqps(this) \
    , qqpt(this) \
    , qqpp(this) \
    , qqpq(this) \
    , qqqs(this) \
    , qqqt(this) \
    , qqqp(this) \
    , qqqq(this)


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
    Vector4(T x)
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

    template <typename SwizzleT, typename std::enable_if<std::is_convertible<SwizzleT, Vector4Core<T>>::value>::type * = nullptr>
    Vector4(const SwizzleT &core)
        : Vector4Core<T>::Vector4Core(static_cast<Vector4Core<T>>(core))
        , GLSLIKE_VECTOR4_SWIZZLE()
    {}

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
        return Vector3<T>(
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
        return Vector3<T>(
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
    alias<T, Vector4<T>, &Vector4Core<T>::x> r;
    alias<T, Vector4<T>, &Vector4Core<T>::y> g;
    alias<T, Vector4<T>, &Vector4Core<T>::z> b;
    alias<T, Vector4<T>, &Vector4Core<T>::w> a;
    alias<T, Vector4<T>, &Vector4Core<T>::x> s;
    alias<T, Vector4<T>, &Vector4Core<T>::y> t;
    alias<T, Vector4<T>, &Vector4Core<T>::z> p;
    alias<T, Vector4<T>, &Vector4Core<T>::w> q;

public:
    // >>> for v in itertools.product("xyzw", repeat=2): print("".join(v))
    // ...
    // xx
    // xy
    // xz
    // xw
    // yx
    // yy
    // yz
    // yw
    // zx
    // zy
    // zz
    // zw
    // wx
    // wy
    // wz
    // ww
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x> xx;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y> xy;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z> xz;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w> xw;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x> yx;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y> yy;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z> yz;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w> yw;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x> zx;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y> zy;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z> zz;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w> zw;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x> wx;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y> wy;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z> wz;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w> ww;
    // alias rgba
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x> rr;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y> rg;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z> rb;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w> ra;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x> gr;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y> gg;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z> gb;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w> ga;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x> br;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y> bg;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z> bb;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w> ba;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x> ar;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y> ag;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z> ab;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w> aa;
    // alias stpq
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x> ss;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y> st;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z> sp;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w> sq;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x> ts;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y> tt;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z> tp;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w> tq;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x> ps;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y> pt;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z> pp;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w> pq;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x> qs;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y> qt;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z> qp;
    Swizzle2<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w> qq;

public:
    // >>> for v in itertools.product("xyzw", repeat=3): print("".join(v))
    // ...
    // xxx
    // xxy
    // xxz
    // xxw
    // xyx
    // xyy
    // xyz
    // xyw
    // xzx
    // xzy
    // xzz
    // xzw
    // xwx
    // xwy
    // xwz
    // xww
    // yxx
    // yxy
    // yxz
    // yxw
    // yyx
    // yyy
    // yyz
    // yyw
    // yzx
    // yzy
    // yzz
    // yzw
    // ywx
    // ywy
    // ywz
    // yww
    // zxx
    // zxy
    // zxz
    // zxw
    // zyx
    // zyy
    // zyz
    // zyw
    // zzx
    // zzy
    // zzz
    // zzw
    // zwx
    // zwy
    // zwz
    // zww
    // wxx
    // wxy
    // wxz
    // wxw
    // wyx
    // wyy
    // wyz
    // wyw
    // wzx
    // wzy
    // wzz
    // wzw
    // wwx
    // wwy
    // wwz
    // www
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> xxx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> xxy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> xxz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> xxw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> xyx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> xyy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> xyz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> xyw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> xzx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> xzy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> xzz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> xzw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> xwx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> xwy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> xwz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> xww;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> yxx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> yxy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> yxz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> yxw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> yyx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> yyy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> yyz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> yyw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> yzx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> yzy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> yzz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> yzw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> ywx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> ywy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> ywz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> yww;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> zxx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> zxy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> zxz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> zxw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> zyx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> zyy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> zyz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> zyw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> zzx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> zzy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> zzz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> zzw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> zwx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> zwy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> zwz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> zww;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> wxx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> wxy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> wxz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> wxw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> wyx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> wyy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> wyz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> wyw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> wzx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> wzy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> wzz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> wzw;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> wwx;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> wwy;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> wwz;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> www;
    // alias rgba
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> rrr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> rrg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> rrb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> rra;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> rgr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> rgg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> rgb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> rga;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> rbr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> rbg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> rbb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> rba;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> rar;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> rag;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> rab;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> raa;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> grr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> grg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> grb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> gra;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> ggr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> ggg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> ggb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> gga;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> gbr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> gbg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> gbb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> gba;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> gar;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> gag;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> gab;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> gaa;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> brr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> brg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> brb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> bra;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> bgr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> bgg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> bgb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> bga;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> bbr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> bbg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> bbb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> bba;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> bar;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> bag;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> bab;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> baa;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> arr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> arg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> arb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> ara;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> agr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> agg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> agb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> aga;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> abr;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> abg;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> abb;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> aba;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> aar;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> aag;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> aab;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> aaa;
    // alias stpq
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> sss;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> sst;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> ssp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> ssq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> sts;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> stt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> stp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> stq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> sps;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> spt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> spp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> spq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> sqs;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> sqt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> sqp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> sqq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> tss;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> tst;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> tsp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> tsq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> tts;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> ttt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> ttp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> ttq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> tps;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> tpt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> tpp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> tpq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> tqs;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> tqt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> tqp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> tqq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> pss;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> pst;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> psp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> psq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> pts;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> ptt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> ptp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> ptq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> pps;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> ppt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> ppp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> ppq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> pqs;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> pqt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> pqp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> pqq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> qss;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> qst;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> qsp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> qsq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> qts;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> qtt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> qtp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> qtq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> qps;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> qpt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> qpp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> qpq;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> qqs;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> qqt;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> qqp;
    Swizzle3<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> qqq;

public:
    // >>> for v in itertools.product("xyzw", repeat=4): print("".join(v))
    // ...
    // xxxx
    // xxxy
    // xxxz
    // xxxw
    // xxyx
    // xxyy
    // xxyz
    // xxyw
    // xxzx
    // xxzy
    // xxzz
    // xxzw
    // xxwx
    // xxwy
    // xxwz
    // xxww
    // xyxx
    // xyxy
    // xyxz
    // xyxw
    // xyyx
    // xyyy
    // xyyz
    // xyyw
    // xyzx
    // xyzy
    // xyzz
    // xyzw
    // xywx
    // xywy
    // xywz
    // xyww
    // xzxx
    // xzxy
    // xzxz
    // xzxw
    // xzyx
    // xzyy
    // xzyz
    // xzyw
    // xzzx
    // xzzy
    // xzzz
    // xzzw
    // xzwx
    // xzwy
    // xzwz
    // xzww
    // xwxx
    // xwxy
    // xwxz
    // xwxw
    // xwyx
    // xwyy
    // xwyz
    // xwyw
    // xwzx
    // xwzy
    // xwzz
    // xwzw
    // xwwx
    // xwwy
    // xwwz
    // xwww
    // yxxx
    // yxxy
    // yxxz
    // yxxw
    // yxyx
    // yxyy
    // yxyz
    // yxyw
    // yxzx
    // yxzy
    // yxzz
    // yxzw
    // yxwx
    // yxwy
    // yxwz
    // yxww
    // yyxx
    // yyxy
    // yyxz
    // yyxw
    // yyyx
    // yyyy
    // yyyz
    // yyyw
    // yyzx
    // yyzy
    // yyzz
    // yyzw
    // yywx
    // yywy
    // yywz
    // yyww
    // yzxx
    // yzxy
    // yzxz
    // yzxw
    // yzyx
    // yzyy
    // yzyz
    // yzyw
    // yzzx
    // yzzy
    // yzzz
    // yzzw
    // yzwx
    // yzwy
    // yzwz
    // yzww
    // ywxx
    // ywxy
    // ywxz
    // ywxw
    // ywyx
    // ywyy
    // ywyz
    // ywyw
    // ywzx
    // ywzy
    // ywzz
    // ywzw
    // ywwx
    // ywwy
    // ywwz
    // ywww
    // zxxx
    // zxxy
    // zxxz
    // zxxw
    // zxyx
    // zxyy
    // zxyz
    // zxyw
    // zxzx
    // zxzy
    // zxzz
    // zxzw
    // zxwx
    // zxwy
    // zxwz
    // zxww
    // zyxx
    // zyxy
    // zyxz
    // zyxw
    // zyyx
    // zyyy
    // zyyz
    // zyyw
    // zyzx
    // zyzy
    // zyzz
    // zyzw
    // zywx
    // zywy
    // zywz
    // zyww
    // zzxx
    // zzxy
    // zzxz
    // zzxw
    // zzyx
    // zzyy
    // zzyz
    // zzyw
    // zzzx
    // zzzy
    // zzzz
    // zzzw
    // zzwx
    // zzwy
    // zzwz
    // zzww
    // zwxx
    // zwxy
    // zwxz
    // zwxw
    // zwyx
    // zwyy
    // zwyz
    // zwyw
    // zwzx
    // zwzy
    // zwzz
    // zwzw
    // zwwx
    // zwwy
    // zwwz
    // zwww
    // wxxx
    // wxxy
    // wxxz
    // wxxw
    // wxyx
    // wxyy
    // wxyz
    // wxyw
    // wxzx
    // wxzy
    // wxzz
    // wxzw
    // wxwx
    // wxwy
    // wxwz
    // wxww
    // wyxx
    // wyxy
    // wyxz
    // wyxw
    // wyyx
    // wyyy
    // wyyz
    // wyyw
    // wyzx
    // wyzy
    // wyzz
    // wyzw
    // wywx
    // wywy
    // wywz
    // wyww
    // wzxx
    // wzxy
    // wzxz
    // wzxw
    // wzyx
    // wzyy
    // wzyz
    // wzyw
    // wzzx
    // wzzy
    // wzzz
    // wzzw
    // wzwx
    // wzwy
    // wzwz
    // wzww
    // wwxx
    // wwxy
    // wwxz
    // wwxw
    // wwyx
    // wwyy
    // wwyz
    // wwyw
    // wwzx
    // wwzy
    // wwzz
    // wwzw
    // wwwx
    // wwwy
    // wwwz
    // wwww
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> xxxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> xxxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> xxxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> xxxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> xxyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> xxyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> xxyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> xxyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> xxzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> xxzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> xxzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> xxzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> xxwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> xxwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> xxwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> xxww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> xyxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> xyxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> xyxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> xyxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> xyyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> xyyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> xyyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> xyyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> xyzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> xyzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> xyzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> xyzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> xywx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> xywy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> xywz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> xyww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> xzxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> xzxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> xzxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> xzxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> xzyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> xzyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> xzyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> xzyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> xzzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> xzzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> xzzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> xzzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> xzwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> xzwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> xzwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> xzww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> xwxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> xwxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> xwxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> xwxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> xwyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> xwyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> xwyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> xwyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> xwzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> xwzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> xwzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> xwzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> xwwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> xwwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> xwwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> xwww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> yxxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> yxxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> yxxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> yxxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> yxyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> yxyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> yxyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> yxyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> yxzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> yxzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> yxzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> yxzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> yxwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> yxwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> yxwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> yxww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> yyxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> yyxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> yyxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> yyxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> yyyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> yyyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> yyyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> yyyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> yyzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> yyzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> yyzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> yyzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> yywx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> yywy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> yywz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> yyww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> yzxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> yzxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> yzxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> yzxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> yzyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> yzyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> yzyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> yzyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> yzzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> yzzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> yzzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> yzzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> yzwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> yzwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> yzwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> yzww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> ywxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> ywxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> ywxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> ywxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> ywyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> ywyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> ywyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> ywyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> ywzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> ywzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> ywzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> ywzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> ywwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> ywwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> ywwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> ywww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> zxxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> zxxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> zxxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> zxxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> zxyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> zxyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> zxyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> zxyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> zxzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> zxzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> zxzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> zxzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> zxwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> zxwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> zxwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> zxww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> zyxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> zyxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> zyxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> zyxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> zyyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> zyyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> zyyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> zyyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> zyzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> zyzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> zyzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> zyzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> zywx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> zywy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> zywz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> zyww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> zzxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> zzxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> zzxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> zzxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> zzyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> zzyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> zzyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> zzyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> zzzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> zzzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> zzzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> zzzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> zzwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> zzwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> zzwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> zzww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> zwxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> zwxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> zwxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> zwxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> zwyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> zwyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> zwyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> zwyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> zwzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> zwzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> zwzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> zwzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> zwwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> zwwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> zwwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> zwww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> wxxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> wxxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> wxxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> wxxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> wxyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> wxyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> wxyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> wxyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> wxzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> wxzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> wxzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> wxzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> wxwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> wxwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> wxwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> wxww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> wyxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> wyxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> wyxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> wyxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> wyyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> wyyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> wyyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> wyyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> wyzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> wyzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> wyzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> wyzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> wywx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> wywy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> wywz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> wyww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> wzxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> wzxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> wzxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> wzxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> wzyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> wzyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> wzyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> wzyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> wzzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> wzzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> wzzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> wzzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> wzwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> wzwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> wzwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> wzww;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> wwxx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> wwxy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> wwxz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> wwxw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> wwyx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> wwyy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> wwyz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> wwyw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> wwzx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> wwzy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> wwzz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> wwzw;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> wwwx;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> wwwy;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> wwwz;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> wwww;
    // alias rgba
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> rrrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> rrrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> rrrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> rrra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> rrgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> rrgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> rrgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> rrga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> rrbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> rrbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> rrbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> rrba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> rrar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> rrag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> rrab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> rraa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> rgrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> rgrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> rgrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> rgra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> rggr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> rggg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> rggb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> rgga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> rgbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> rgbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> rgbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> rgba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> rgar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> rgag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> rgab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> rgaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> rbrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> rbrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> rbrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> rbra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> rbgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> rbgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> rbgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> rbga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> rbbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> rbbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> rbbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> rbba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> rbar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> rbag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> rbab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> rbaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> rarr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> rarg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> rarb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> rara;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> ragr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> ragg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> ragb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> raga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> rabr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> rabg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> rabb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> raba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> raar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> raag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> raab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> raaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> grrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> grrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> grrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> grra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> grgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> grgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> grgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> grga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> grbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> grbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> grbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> grba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> grar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> grag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> grab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> graa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> ggrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> ggrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> ggrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> ggra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> gggr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> gggg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> gggb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> ggga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> ggbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> ggbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> ggbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> ggba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> ggar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> ggag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> ggab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> ggaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> gbrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> gbrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> gbrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> gbra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> gbgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> gbgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> gbgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> gbga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> gbbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> gbbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> gbbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> gbba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> gbar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> gbag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> gbab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> gbaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> garr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> garg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> garb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> gara;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> gagr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> gagg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> gagb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> gaga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> gabr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> gabg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> gabb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> gaba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> gaar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> gaag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> gaab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> gaaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> brrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> brrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> brrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> brra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> brgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> brgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> brgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> brga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> brbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> brbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> brbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> brba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> brar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> brag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> brab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> braa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> bgrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> bgrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> bgrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> bgra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> bggr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> bggg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> bggb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> bgga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> bgbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> bgbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> bgbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> bgba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> bgar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> bgag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> bgab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> bgaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> bbrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> bbrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> bbrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> bbra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> bbgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> bbgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> bbgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> bbga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> bbbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> bbbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> bbbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> bbba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> bbar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> bbag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> bbab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> bbaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> barr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> barg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> barb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> bara;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> bagr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> bagg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> bagb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> baga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> babr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> babg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> babb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> baba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> baar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> baag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> baab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> baaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> arrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> arrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> arrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> arra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> argr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> argg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> argb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> arga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> arbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> arbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> arbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> arba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> arar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> arag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> arab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> araa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> agrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> agrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> agrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> agra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> aggr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> aggg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> aggb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> agga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> agbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> agbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> agbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> agba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> agar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> agag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> agab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> agaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> abrr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> abrg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> abrb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> abra;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> abgr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> abgg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> abgb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> abga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> abbr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> abbg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> abbb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> abba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> abar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> abag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> abab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> abaa;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> aarr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> aarg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> aarb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> aara;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> aagr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> aagg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> aagb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> aaga;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> aabr;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> aabg;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> aabb;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> aaba;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> aaar;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> aaag;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> aaab;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> aaaa;
    // alias stpq
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> ssss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> ssst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> sssp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> sssq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> ssts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> sstt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> sstp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> sstq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> ssps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> sspt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> sspp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> sspq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> ssqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> ssqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> ssqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> ssqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> stss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> stst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> stsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> stsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> stts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> sttt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> sttp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> sttq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> stps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> stpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> stpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> stpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> stqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> stqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> stqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> stqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> spss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> spst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> spsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> spsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> spts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> sptt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> sptp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> sptq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> spps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> sppt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> sppp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> sppq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> spqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> spqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> spqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> spqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> sqss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> sqst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> sqsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> sqsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> sqts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> sqtt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> sqtp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> sqtq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> sqps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> sqpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> sqpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> sqpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> sqqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> sqqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> sqqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> sqqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> tsss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> tsst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> tssp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> tssq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> tsts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> tstt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> tstp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> tstq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> tsps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> tspt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> tspp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> tspq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> tsqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> tsqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> tsqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> tsqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> ttss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> ttst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> ttsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> ttsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> ttts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> tttt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> tttp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> tttq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> ttps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> ttpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> ttpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> ttpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> ttqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> ttqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> ttqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> ttqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> tpss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> tpst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> tpsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> tpsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> tpts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> tptt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> tptp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> tptq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> tpps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> tppt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> tppp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> tppq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> tpqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> tpqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> tpqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> tpqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> tqss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> tqst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> tqsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> tqsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> tqts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> tqtt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> tqtp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> tqtq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> tqps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> tqpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> tqpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> tqpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> tqqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> tqqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> tqqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> tqqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> psss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> psst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> pssp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> pssq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> psts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> pstt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> pstp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> pstq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> psps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> pspt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> pspp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> pspq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> psqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> psqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> psqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> psqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> ptss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> ptst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> ptsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> ptsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> ptts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> pttt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> pttp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> pttq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> ptps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> ptpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> ptpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> ptpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> ptqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> ptqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> ptqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> ptqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> ppss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> ppst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> ppsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> ppsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> ppts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> pptt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> pptp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> pptq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> ppps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> pppt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> pppp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> pppq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> ppqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> ppqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> ppqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> ppqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> pqss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> pqst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> pqsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> pqsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> pqts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> pqtt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> pqtp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> pqtq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> pqps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> pqpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> pqpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> pqpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> pqqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> pqqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> pqqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> pqqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::x> qsss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::y> qsst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::z> qssp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x, &Vector4Core<T>::w> qssq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::x> qsts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::y> qstt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::z> qstp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y, &Vector4Core<T>::w> qstq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::x> qsps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::y> qspt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::z> qspp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z, &Vector4Core<T>::w> qspq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::x> qsqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::y> qsqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::z> qsqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w, &Vector4Core<T>::w> qsqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::x> qtss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::y> qtst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::z> qtsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x, &Vector4Core<T>::w> qtsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::x> qtts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::y> qttt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::z> qttp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y, &Vector4Core<T>::w> qttq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::x> qtps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::y> qtpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::z> qtpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z, &Vector4Core<T>::w> qtpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::x> qtqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::y> qtqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::z> qtqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w, &Vector4Core<T>::w> qtqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::x> qpss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::y> qpst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::z> qpsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x, &Vector4Core<T>::w> qpsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::x> qpts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::y> qptt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::z> qptp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y, &Vector4Core<T>::w> qptq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::x> qpps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::y> qppt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::z> qppp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z, &Vector4Core<T>::w> qppq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::x> qpqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::y> qpqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::z> qpqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w, &Vector4Core<T>::w> qpqq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::x> qqss;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::y> qqst;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::z> qqsp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x, &Vector4Core<T>::w> qqsq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::x> qqts;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::y> qqtt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::z> qqtp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y, &Vector4Core<T>::w> qqtq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::x> qqps;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::y> qqpt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::z> qqpp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z, &Vector4Core<T>::w> qqpq;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::x> qqqs;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::y> qqqt;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::z> qqqp;
    Swizzle4<T, Vector4<T>, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w, &Vector4Core<T>::w> qqqq;

};

template <typename T>
Vector4<T> clamp(const Vector4<T> value, T min, T max) {
    return Vector4<T>(
        math<T>::clamp(value.x, min, max),
        math<T>::clamp(value.y, min, max),
        math<T>::clamp(value.z, min, max),
        math<T>::clamp(value.w, min, max)
    );
}

template <typename T>
T length(const Vector4<T> &vec) {
    return vec.length();
}

template <typename T>
Vector4<T> normalize(const Vector4<T> &vec) {
    return vec.clone().normalize();
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
Vector3<T> pow(const Vector4<T> &vec, T n) {
    return Vector4<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n),
        math<T>::pow(vec.z, n),
        math<T>::pow(vec.w, n)
    );
}

template <typename T>
T dot(const Vector4<T> &a, const Vector4<T> &b) {
    return a.dot(b);
}

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
    return Vector3<T>(
        a - b.x,
        a - b.y,
        a - b.z,
        a - b.w
    );
}

template <typename T>
Vector4<T> operator *(T a, const Vector4<T> &b) {
    return Vector3<T>(
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

}  // namespace glslike
