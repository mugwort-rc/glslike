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


template <typename R, typename T, R T::*pm>
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



template <typename T, typename ResultT, typename SelfT, T SelfT::* attr1, T SelfT::* attr2>
class Swizzle2 {
public:
    Swizzle2(SelfT *self)
        : self(self)
    {}

    operator ResultT() const {
        return ResultT(
            self->*attr1,
            self->*attr2
        );
    }

    const SelfT *self;
};


#define GLSLIKE_VECTOR2_SWIZZLE() \
    r(this) \
    , g(this) \
    , s(this) \
    , t(this) \
    , xy(this) \
    , yx(this) \
    , xx(this) \
    , yy(this) \
    , rg(this) \
    , gr(this) \
    , rr(this) \
    , gg(this) \
    , st(this) \
    , ts(this) \
    , ss(this) \
    , tt(this)


template <typename T>
class Vector2 {
public:
    typedef T type_t;

public:
    Vector2(T x, T y)
        : x(x)
        , y(y)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

    Vector2(const Vector2<T> &copy)
        : x(copy.x)
        , y(copy.y)
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

    Vector2(Vector2<T> &&move)
        : x(std::move(move.x))
        , y(std::move(move.y))
        , GLSLIKE_VECTOR2_SWIZZLE()
    {}

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
        x = copy.x;
        y = copy.y;
        return *this;
    }
    Vector2<T> &operator =(Vector2<T> &&move) {
        x = std::move(move.x);
        y = std::move(move.y);
        return *this;
    }

    T x, y;

public:
    // rgba
    alias<T, Vector2<T>, &Vector2<T>::x> r;
    alias<T, Vector2<T>, &Vector2<T>::y> g;
    // stpq
    alias<T, Vector2<T>, &Vector2<T>::x> s;
    alias<T, Vector2<T>, &Vector2<T>::y> t;

public:
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::x, &Vector2<T>::y> xy;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::y, &Vector2<T>::x> yx;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::x, &Vector2<T>::x> xx;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::y, &Vector2<T>::y> yy;
    // alias rg
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::x, &Vector2<T>::y> rg;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::y, &Vector2<T>::x> gr;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::x, &Vector2<T>::x> rr;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::y, &Vector2<T>::y> gg;
    // alias st
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::x, &Vector2<T>::y> st;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::y, &Vector2<T>::x> ts;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::x, &Vector2<T>::x> ss;
    Swizzle2<T, Vector2<T>, Vector2<T>, &Vector2<T>::y, &Vector2<T>::y> tt;
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

#ifdef GLSLIKE_USE_HALIDE
typedef Vector2<Halide::Expr> vec2;
#else
typedef Vector2<float> vec2;
#endif  // GLSLIKE_USE_HALIDE


template <typename T, typename ReturnT, typename SelfT, T SelfT::* attr1, T SelfT::* attr2, T SelfT::* attr3>
class Swizzle3 {
public:
    Swizzle3(SelfT *self)
        : self(self)
    {}

    operator ReturnT() const {
        return ReturnT(
            self->*attr1,
            self->*attr2,
            self->*attr3
        );
    }

    const SelfT *self;
};


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
    , yy(this) \
    , yz(this) \
    , zz(this) \
    , yx(this) \
    , zx(this) \
    , zy(this) \
    , rr(this) \
    , rg(this) \
    , rb(this) \
    , gg(this) \
    , gb(this) \
    , bb(this) \
    , gr(this) \
    , br(this) \
    , bg(this) \
    , ss(this) \
    , st(this) \
    , sp(this) \
    , tt(this) \
    , tp(this) \
    , pp(this) \
    , ts(this) \
    , ps(this) \
    , pt(this) \
    , xxx(this) \
    , xxy(this) \
    , xxz(this) \
    , xyy(this) \
    , xyz(this) \
    , xzz(this) \
    , yyy(this) \
    , yyz(this) \
    , yzz(this) \
    , zzz(this) \
    , xyx(this) \
    , xzx(this) \
    , yyx(this) \
    , yzx(this) \
    , zzx(this) \
    , yzy(this) \
    , zzy(this) \
    , yxx(this) \
    , zxx(this) \
    , yxy(this) \
    , zxy(this) \
    , zxz(this) \
    , zyy(this) \
    , zyz(this) \
    , rrr(this) \
    , rrg(this) \
    , rrb(this) \
    , rgg(this) \
    , rgb(this) \
    , rbb(this) \
    , ggg(this) \
    , ggb(this) \
    , gbb(this) \
    , bbb(this) \
    , rgr(this) \
    , rbr(this) \
    , ggr(this) \
    , gbr(this) \
    , bbr(this) \
    , gbg(this) \
    , bbg(this) \
    , grr(this) \
    , brr(this) \
    , grg(this) \
    , brg(this) \
    , brb(this) \
    , bgg(this) \
    , bgb(this) \
    , sss(this) \
    , sst(this) \
    , ssp(this) \
    , stt(this) \
    , stp(this) \
    , spp(this) \
    , ttt(this) \
    , ttp(this) \
    , tpp(this) \
    , ppp(this) \
    , sts(this) \
    , sps(this) \
    , tts(this) \
    , tps(this) \
    , pps(this) \
    , tpt(this) \
    , ppt(this) \
    , tss(this) \
    , pss(this) \
    , tst(this) \
    , pst(this) \
    , psp(this) \
    , ptt(this) \
    , ptp(this)


template <typename T>
class Vector3 {
public:
    typedef T type_t;

public:
    Vector3(T x, T y, T z)
        : x(x)
        , y(y)
        , z(z)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

    Vector3(const Vector3<T> &copy)
        : x(copy.x)
        , y(copy.y)
        , z(copy.z)
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

    Vector3(Vector3<T> &&move)
        : x(std::move(move.x))
        , y(std::move(move.y))
        , z(std::move(move.z))
        , GLSLIKE_VECTOR3_SWIZZLE()
    {}

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

    T x, y, z;

public:
    alias<T, Vector3<T>, &Vector3<T>::x> r;
    alias<T, Vector3<T>, &Vector3<T>::y> g;
    alias<T, Vector3<T>, &Vector3<T>::z> b;
    alias<T, Vector3<T>, &Vector3<T>::x> s;
    alias<T, Vector3<T>, &Vector3<T>::y> t;
    alias<T, Vector3<T>, &Vector3<T>::z> p;

public:
    // for v in itertools.combinations_with_replacement("xyz", 2): print("".join(v))
    // ...
    // xx
    // xy
    // xz
    // yy
    // yz
    // zz
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x> xx;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y> xy;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z> xz;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y> yy;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z> yz;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z> zz;
    // shift-1
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x> yx;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x> zx;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y> zy;

    // alias rgb
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x> rr;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y> rg;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z> rb;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y> gg;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z> gb;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z> bb;
    // shift-1
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x> gr;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x> br;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y> bg;

    // alias stp
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x> ss;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y> st;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z> sp;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y> tt;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z> tp;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z> pp;
    // shift-1
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x> ts;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x> ps;
    Swizzle2<T, Vector2<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y> pt;

public:
    // >>> for v in itertools.combinations_with_replacement("xyz", 3): print("".join(v))
    // ...
    // xxx
    // xxy
    // xxz
    // xyy
    // xyz
    // xzz
    // yyy
    // yyz
    // yzz
    // zzz
    //
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::x> xxx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::y> xxy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::z> xxz;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::y> xyy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::z> xyz;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z, &Vector3<T>::z> xzz;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::y> yyy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::z> yyz;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::z> yzz;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::z> zzz;
    // shift-1
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::x> xyx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z, &Vector3<T>::x> xzx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::x> yyx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::x> yzx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::x> zzx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::y> yzy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::y> zzy;
    // shift-2
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x, &Vector3<T>::x> yxx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::x> zxx;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x, &Vector3<T>::y> yxy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::y> zxy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::z> zxz;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y, &Vector3<T>::y> zyy;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y, &Vector3<T>::z> zyz;

    // alias rgb
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::x> rrr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::y> rrg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::z> rrb;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::y> rgg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::z> rgb;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z, &Vector3<T>::z> rbb;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::y> ggg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::z> ggb;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::z> gbb;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::z> bbb;
    // shift-1
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::x> rgr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z, &Vector3<T>::x> rbr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::x> ggr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::x> gbr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::x> bbr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::y> gbg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::y> bbg;
    // shift-2
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x, &Vector3<T>::x> grr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::x> brr;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x, &Vector3<T>::y> grg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::y> brg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::z> brb;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y, &Vector3<T>::y> bgg;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y, &Vector3<T>::z> bgb;

    // alias stp
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::x> sss;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::y> sst;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::x, &Vector3<T>::z> ssp;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::y> stt;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::z> stp;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z, &Vector3<T>::z> spp;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::y> ttt;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::z> ttp;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::z> tpp;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::z> ppp;
    // shift-1
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::y, &Vector3<T>::x> sts;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::x, &Vector3<T>::z, &Vector3<T>::x> sps;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::y, &Vector3<T>::x> tts;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::x> tps;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::x> pps;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::z, &Vector3<T>::y> tpt;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::z, &Vector3<T>::y> ppt;
    // shift-2
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x, &Vector3<T>::x> tss;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::x> pss;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::y, &Vector3<T>::x, &Vector3<T>::y> tst;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::y> pst;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::x, &Vector3<T>::z> psp;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y, &Vector3<T>::y> ptt;
    Swizzle3<T, Vector3<T>, Vector3<T>, &Vector3<T>::z, &Vector3<T>::y, &Vector3<T>::z> ptp;

};

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
T exp(T scalar) {
    return math<T>::exp(scalar);
}

template <typename T>
Vector3<T> pow(const Vector3<T> &vec, T n) {
    return Vector3<T>(
        math<T>::pow(vec.x, n),
        math<T>::pow(vec.y, n),
        math<T>::pow(vec.z, n)
    );
}

template <typename T, typename ScalarT>
T pow(T scalar, ScalarT n) {
    return math<T>::pow(scalar, n);
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

#ifdef GLSLIKE_USE_HALIDE
typedef Vector3<Halide::Expr> vec3;
#else
typedef Vector3<float> vec3;
#endif  // GLSLIKE_USE_HALIDE

}  // namespace glslike
