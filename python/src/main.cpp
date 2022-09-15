#include <sstream>
#include <pybind11/pybind11.h>
#include <pybind11/numpy.h>
#include <pybind11/stl.h>

#define GLSLIKE_DISABLE_SWIZZLE
#include "glslike.hpp"
#include "glslike_io.hpp"

using namespace glslike;

// for realizeNd
std::uint8_t to256(float value) {
    return static_cast<std::uint8_t>(std::clamp(value, 0.0f, 1.0f) * 255.0f);
}

template <typename T>
std::string repr(const T &value) {
    return pybind11::repr(pybind11::cast(value));
}

template <typename T, int Dim>
pybind11::array_t<std::uint8_t> realize(const pybind11::object &func, int size) {
    const float half = size / 2.0f;
    pybind11::array_t<std::uint8_t> arr({size, size, Dim});
    auto req = arr.request();
    auto *raw = static_cast<std::uint8_t *>(req.ptr);
    for (int y = 0; y < size; ++y) {
        const auto x0 = y * size;
        for (int x = 0; x < size; ++x) {
            // create position
            const auto vx = (x - half) / half;
            const auto vy = (y - half) / half;
            const vec2 coordinate(vx, vy);
            const auto result = func(coordinate);
            const T v = pybind11::cast<T>(result);

            const auto c0 = (x0 + x) * Dim;
            for (int c = 0; c < Dim; ++c) {
                raw[c0 + c] = to256(v[c]);
            }
        }
    }
    return arr;
}


PYBIND11_MODULE(__glslike, module) {
    module
        // scalar
        //
        // 8.1 Angle and Trigonometry Functions
        //
        .def("radians", static_cast<float(*)(float)>(&radians<float>))
        .def("degrees", static_cast<float(*)(float)>(&degrees<float>))
        .def("sin", static_cast<float(*)(float)>(&sin<float>))
        .def("cos", static_cast<float(*)(float)>(&cos<float>))
        .def("tan", static_cast<float(*)(float)>(&tan<float>))
        .def("asin", static_cast<float(*)(float)>(&asin<float>))
        .def("acos", static_cast<float(*)(float)>(&acos<float>))
        .def("atan", static_cast<float(*)(float, float)>(&atan<float>))
        .def("atan", static_cast<float(*)(float)>(&atan<float>))
        .def("sinh", static_cast<float(*)(float)>(&sinh<float>))
        .def("cosh", static_cast<float(*)(float)>(&cosh<float>))
        .def("tanh", static_cast<float(*)(float)>(&tanh<float>))
        .def("asinh", static_cast<float(*)(float)>(&asinh<float>))
        .def("acosh", static_cast<float(*)(float)>(&acosh<float>))
        .def("atanh", static_cast<float(*)(float)>(&atanh<float>))
        //
        // 8.2 Exponential Functions
        //
        .def("pow", static_cast<float(*)(float, float)>(&pow<float>))
        .def("exp", static_cast<float(*)(float)>(&exp<float>))
        .def("log", static_cast<float(*)(float)>(&log<float>))
        .def("exp2", static_cast<float(*)(float)>(&exp2<float>))
        .def("log2", static_cast<float(*)(float)>(&log2<float>))
        .def("sqrt", static_cast<float(*)(float)>(&sqrt<float>))
        .def("inversesqrt", static_cast<float(*)(float)>(&inversesqrt<float>))
        //
        // 8.3 Common Functions
        //
        .def("abs", static_cast<float(*)(float)>(&abs<float>))
        .def("sign", static_cast<float(*)(float)>(&sign<float>))
        .def("floor", static_cast<float(*)(float)>(&floor<float>))
        .def("trunc", static_cast<float(*)(float)>(&trunc<float>))
        .def("round", static_cast<float(*)(float)>(&round<float>))
        .def("roundEven", static_cast<float(*)(float)>(&roundEven<float>))
        .def("ceil", static_cast<float(*)(float)>(&ceil<float>))
        .def("fract", static_cast<float(*)(float)>(&fract<float>))
        .def("mod", static_cast<float(*)(float, float)>(&mod<float>))
        .def("modf", [](float x) {
            float int_part;
            const float result = modf(x, &int_part);
            // same as math.modf()
            return std::make_tuple(result, int_part);
        })
        .def("min", static_cast<float(*)(float, float)>(&min<float>))
        .def("max", static_cast<float(*)(float, float)>(&max<float>))
        .def("clamp", static_cast<float(*)(float, float, float)>(&clamp<float>))
        .def("mix", static_cast<float(*)(float, float, float)>(&mix<float>))
        .def("step", static_cast<float(*)(float, float)>(&step<float>))
        .def("smoothstep", static_cast<float(*)(float, float, float)>(&smoothstep<float>))
        .def("isnan", static_cast<bool(*)(float)>(&isnan<float>))
        .def("isinf", static_cast<bool(*)(float)>(&isinf<float>))
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
        .def("length", static_cast<float(*)(float)>(&length<float>))
        .def("distance", static_cast<float(*)(float, float)>(&distance<float>))
        .def("dot", static_cast<float(*)(float, float)>(&dot<float>))
        .def("normalize", static_cast<float(*)(float)>(&normalize<float>))
        .def("faceforward", static_cast<float(*)(float, float, float)>(&faceforward<float>))
        .def("reflect", static_cast<float(*)(float, float)>(&reflect<float>))
        .def("refract", static_cast<float(*)(float, float, float)>(&refract<float>))
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
        //
        //=====================================================================
        // vec2
        //=====================================================================
        //
        // 8.1 Angle and Trigonometry Functions
        //
        .def("radians", static_cast<vec2(*)(const vec2 &)>(&radians<float>))
        .def("degrees", static_cast<vec2(*)(const vec2 &)>(&degrees<float>))
        .def("sin", static_cast<vec2(*)(const vec2 &)>(&sin<float>))
        .def("cos", static_cast<vec2(*)(const vec2 &)>(&cos<float>))
        .def("tan", static_cast<vec2(*)(const vec2 &)>(&tan<float>))
        .def("asin", static_cast<vec2(*)(const vec2 &)>(&asin<float>))
        .def("acos", static_cast<vec2(*)(const vec2 &)>(&acos<float>))
        .def("atan", static_cast<vec2(*)(const vec2 &, const vec2 &)>(&atan<float>))
        .def("atan", static_cast<vec2(*)(const vec2 &)>(&atan<float>))
        .def("sinh", static_cast<vec2(*)(const vec2 &)>(&sinh<float>))
        .def("cosh", static_cast<vec2(*)(const vec2 &)>(&cosh<float>))
        .def("tanh", static_cast<vec2(*)(const vec2 &)>(&tanh<float>))
        .def("asinh", static_cast<vec2(*)(const vec2 &)>(&asinh<float>))
        .def("acosh", static_cast<vec2(*)(const vec2 &)>(&acosh<float>))
        .def("atanh", static_cast<vec2(*)(const vec2 &)>(&atanh<float>))
        //
        // 8.2 Exponential Functions
        //
        .def("pow", static_cast<vec2(*)(const vec2 &, float)>(&pow<float>))
        .def("exp", static_cast<vec2(*)(const vec2 &)>(&exp<float>))
        .def("log", static_cast<vec2(*)(const vec2 &)>(&log<float>))
        .def("exp2", static_cast<vec2(*)(const vec2 &)>(&exp2<float>))
        .def("log2", static_cast<vec2(*)(const vec2 &)>(&log2<float>))
        .def("sqrt", static_cast<vec2(*)(const vec2 &)>(&sqrt<float>))
        .def("inversesqrt", static_cast<vec2(*)(const vec2 &)>(&inversesqrt<float>))
        //
        // 8.3 Common Functions
        //
        .def("abs", static_cast<vec2(*)(const vec2 &)>(&abs<float>))
        .def("sign", static_cast<vec2(*)(const vec2 &)>(&sign<float>))
        .def("floor", static_cast<vec2(*)(const vec2 &)>(&floor<float>))
        .def("trunc", static_cast<vec2(*)(const vec2 &)>(&trunc<float>))
        .def("round", static_cast<vec2(*)(const vec2 &)>(&round<float>))
        .def("roundEven", static_cast<vec2(*)(const vec2 &)>(&roundEven<float>))
        .def("ceil", static_cast<vec2(*)(const vec2 &)>(&ceil<float>))
        .def("fract", static_cast<vec2(*)(const vec2 &)>(&fract<float>))
        .def("mod", static_cast<vec2(*)(const vec2 &, const vec2 &)>(&mod<float>))
        .def("mod", static_cast<vec2(*)(const vec2 &, float)>(&mod<float>))
        .def("modf", [](const vec2 &x) {
            vec2 int_part(0.0);
            const vec2 result = modf(x, &int_part);
            // same as math.modf()
            return std::make_tuple(result, int_part);
        })
        .def("min", static_cast<vec2(*)(const vec2 &, const vec2 &)>(&min<float>))
        .def("min", static_cast<vec2(*)(const vec2 &, float)>(&min<float>))
        .def("max", static_cast<vec2(*)(const vec2 &, const vec2 &)>(&max<float>))
        .def("max", static_cast<vec2(*)(const vec2 &, float)>(&max<float>))
        .def("clamp", static_cast<vec2(*)(const vec2 &, const vec2 &, const vec2 &)>(&clamp<float>))
        .def("clamp", static_cast<vec2(*)(const vec2 &, float, float)>(&clamp<float>))
        .def("mix", static_cast<vec2(*)(const vec2 &, const vec2 &, const vec2 &)>(&mix<float>))
        .def("mix", static_cast<vec2(*)(const vec2 &, const vec2 &, float)>(&mix<float>))
        .def("step", static_cast<vec2(*)(const vec2 &, const vec2 &)>(&step<float>))
        .def("smoothstep", static_cast<vec2(*)(const vec2 &, const vec2 &, const vec2 &)>(&smoothstep<float>))
        .def("smoothstep", static_cast<vec2(*)(float, float, const vec2 &)>(&smoothstep<float>))
        .def("isnan", static_cast<bvec2(*)(const vec2 &)>(&isnan<float>))
        .def("isinf", static_cast<bvec2(*)(const vec2 &)>(&isinf<float>))
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
        .def("length", static_cast<float(*)(const vec2 &)>(&length<vec2>))
        .def("distance", static_cast<float(*)(const vec2 &, const vec2 &)>(&distance<vec2>))
        .def("dot", static_cast<float(*)(const vec2 &, const vec2 &)>(&dot<vec2>))
        .def("normalize", static_cast<vec2(*)(const vec2 &)>(&normalize<vec2>))
        .def("faceforward", static_cast<vec2(*)(const vec2 &, const vec2 &, const vec2 &)>(&faceforward<vec2>))
        .def("reflect", static_cast<vec2(*)(const vec2 &, const vec2 &)>(&reflect<vec2>))
        .def("refract", static_cast<vec2(*)(const vec2 &, const vec2 &, float)>(&refract<vec2>))
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
        //
        //=====================================================================
        // vec3
        //=====================================================================
        //
        // 8.1 Angle and Trigonometry Functions
        //
        .def("radians", static_cast<vec3(*)(const vec3 &)>(&radians<float>))
        .def("degrees", static_cast<vec3(*)(const vec3 &)>(&degrees<float>))
        .def("sin", static_cast<vec3(*)(const vec3 &)>(&sin<float>))
        .def("cos", static_cast<vec3(*)(const vec3 &)>(&cos<float>))
        .def("tan", static_cast<vec3(*)(const vec3 &)>(&tan<float>))
        .def("asin", static_cast<vec3(*)(const vec3 &)>(&asin<float>))
        .def("acos", static_cast<vec3(*)(const vec3 &)>(&acos<float>))
        .def("atan", static_cast<vec3(*)(const vec3 &, const vec3 &)>(&atan<float>))
        .def("atan", static_cast<vec3(*)(const vec3 &)>(&atan<float>))
        .def("sinh", static_cast<vec3(*)(const vec3 &)>(&sinh<float>))
        .def("cosh", static_cast<vec3(*)(const vec3 &)>(&cosh<float>))
        .def("tanh", static_cast<vec3(*)(const vec3 &)>(&tanh<float>))
        .def("asinh", static_cast<vec3(*)(const vec3 &)>(&asinh<float>))
        .def("acosh", static_cast<vec3(*)(const vec3 &)>(&acosh<float>))
        .def("atanh", static_cast<vec3(*)(const vec3 &)>(&atanh<float>))
        //
        // 8.2 Exponential Functions
        //
        .def("pow", static_cast<vec3(*)(const vec3 &, float)>(&pow<float>))
        .def("exp", static_cast<vec3(*)(const vec3 &)>(&exp<float>))
        .def("log", static_cast<vec3(*)(const vec3 &)>(&log<float>))
        .def("exp2", static_cast<vec3(*)(const vec3 &)>(&exp2<float>))
        .def("log2", static_cast<vec3(*)(const vec3 &)>(&log2<float>))
        .def("sqrt", static_cast<vec3(*)(const vec3 &)>(&sqrt<float>))
        .def("inversesqrt", static_cast<vec3(*)(const vec3 &)>(&inversesqrt<float>))
        //
        // 8.3 Common Functions
        //
        .def("abs", static_cast<vec3(*)(const vec3 &)>(&abs<float>))
        .def("sign", static_cast<vec3(*)(const vec3 &)>(&sign<float>))
        .def("floor", static_cast<vec3(*)(const vec3 &)>(&floor<float>))
        .def("trunc", static_cast<vec3(*)(const vec3 &)>(&trunc<float>))
        .def("round", static_cast<vec3(*)(const vec3 &)>(&round<float>))
        .def("roundEven", static_cast<vec3(*)(const vec3 &)>(&roundEven<float>))
        .def("ceil", static_cast<vec3(*)(const vec3 &)>(&ceil<float>))
        .def("fract", static_cast<vec3(*)(const vec3 &)>(&fract<float>))
        .def("mod", static_cast<vec3(*)(const vec3 &, const vec3 &)>(&mod<float>))
        .def("mod", static_cast<vec3(*)(const vec3 &, float)>(&mod<float>))
        .def("modf", [](const vec3 &x) {
            vec3 int_part(0.0);
            const vec3 result = modf(x, &int_part);
            // same as math.modf()
            return std::make_tuple(result, int_part);
        })
        .def("min", static_cast<vec3(*)(const vec3 &, const vec3 &)>(&min<float>))
        .def("min", static_cast<vec3(*)(const vec3 &, float)>(&min<float>))
        .def("max", static_cast<vec3(*)(const vec3 &, const vec3 &)>(&max<float>))
        .def("max", static_cast<vec3(*)(const vec3 &, float)>(&max<float>))
        .def("clamp", static_cast<vec3(*)(const vec3 &, const vec3 &, const vec3 &)>(&clamp<float>))
        .def("clamp", static_cast<vec3(*)(const vec3 &, float, float)>(&clamp<float>))
        .def("mix", static_cast<vec3(*)(const vec3 &, const vec3 &, const vec3 &)>(&mix<float>))
        .def("mix", static_cast<vec3(*)(const vec3 &, const vec3 &, float)>(&mix<float>))
        .def("step", static_cast<vec3(*)(const vec3 &, const vec3 &)>(&step<float>))
        .def("smoothstep", static_cast<vec3(*)(const vec3 &, const vec3 &, const vec3 &)>(&smoothstep<float>))
        .def("smoothstep", static_cast<vec3(*)(float, float, const vec3 &)>(&smoothstep<float>))
        .def("isnan", static_cast<bvec3(*)(const vec3 &)>(&isnan<float>))
        .def("isinf", static_cast<bvec3(*)(const vec3 &)>(&isinf<float>))
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
        .def("length", static_cast<float(*)(const vec3 &)>(&length<vec3>))
        .def("distance", static_cast<float(*)(const vec3 &, const vec3 &)>(&distance<vec3>))
        .def("dot", static_cast<float(*)(const vec3 &, const vec3 &)>(&dot<vec3>))
        .def("cross", &cross<float>)
        .def("normalize", static_cast<vec3(*)(const vec3 &)>(&normalize<vec3>))
        .def("faceforward", static_cast<vec3(*)(const vec3 &, const vec3 &, const vec3 &)>(&faceforward<vec3>))
        .def("reflect", static_cast<vec3(*)(const vec3 &, const vec3 &)>(&reflect<vec3>))
        .def("refract", static_cast<vec3(*)(const vec3 &, const vec3 &, float)>(&refract<vec3>))
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
        //
        //=====================================================================
        // vec4
        //=====================================================================
        //
        // 8.1 Angle and Trigonometry Functions
        //
        .def("radians", static_cast<vec4(*)(const vec4 &)>(&radians<float>))
        .def("degrees", static_cast<vec4(*)(const vec4 &)>(&degrees<float>))
        .def("sin", static_cast<vec4(*)(const vec4 &)>(&sin<float>))
        .def("cos", static_cast<vec4(*)(const vec4 &)>(&cos<float>))
        .def("tan", static_cast<vec4(*)(const vec4 &)>(&tan<float>))
        .def("asin", static_cast<vec4(*)(const vec4 &)>(&asin<float>))
        .def("acos", static_cast<vec4(*)(const vec4 &)>(&acos<float>))
        .def("atan", static_cast<vec4(*)(const vec4 &, const vec4 &)>(&atan<float>))
        .def("atan", static_cast<vec4(*)(const vec4 &)>(&atan<float>))
        .def("sinh", static_cast<vec4(*)(const vec4 &)>(&sinh<float>))
        .def("cosh", static_cast<vec4(*)(const vec4 &)>(&cosh<float>))
        .def("tanh", static_cast<vec4(*)(const vec4 &)>(&tanh<float>))
        .def("asinh", static_cast<vec4(*)(const vec4 &)>(&asinh<float>))
        .def("acosh", static_cast<vec4(*)(const vec4 &)>(&acosh<float>))
        .def("atanh", static_cast<vec4(*)(const vec4 &)>(&atanh<float>))
        //
        // 8.2 Exponential Functions
        //
        .def("pow", static_cast<vec4(*)(const vec4 &, float)>(&pow<float>))
        .def("exp", static_cast<vec4(*)(const vec4 &)>(&exp<float>))
        .def("log", static_cast<vec4(*)(const vec4 &)>(&log<float>))
        .def("exp2", static_cast<vec4(*)(const vec4 &)>(&exp2<float>))
        .def("log2", static_cast<vec4(*)(const vec4 &)>(&log2<float>))
        .def("sqrt", static_cast<vec4(*)(const vec4 &)>(&sqrt<float>))
        .def("inversesqrt", static_cast<vec4(*)(const vec4 &)>(&inversesqrt<float>))
        //
        // 8.3 Common Functions
        //
        .def("abs", static_cast<vec4(*)(const vec4 &)>(&abs<float>))
        .def("sign", static_cast<vec4(*)(const vec4 &)>(&sign<float>))
        .def("floor", static_cast<vec4(*)(const vec4 &)>(&floor<float>))
        .def("trunc", static_cast<vec4(*)(const vec4 &)>(&trunc<float>))
        .def("round", static_cast<vec4(*)(const vec4 &)>(&round<float>))
        .def("roundEven", static_cast<vec4(*)(const vec4 &)>(&roundEven<float>))
        .def("ceil", static_cast<vec4(*)(const vec4 &)>(&ceil<float>))
        .def("fract", static_cast<vec4(*)(const vec4 &)>(&fract<float>))
        .def("mod", static_cast<vec4(*)(const vec4 &, const vec4 &)>(&mod<float>))
        .def("mod", static_cast<vec4(*)(const vec4 &, float)>(&mod<float>))
        .def("modf", [](const vec4 &x) {
            vec4 int_part(0.0);
            const vec4 result = modf(x, &int_part);
            // same as math.modf()
            return std::make_tuple(result, int_part);
        })
        .def("min", static_cast<vec4(*)(const vec4 &, const vec4 &)>(&min<float>))
        .def("min", static_cast<vec4(*)(const vec4 &, float)>(&min<float>))
        .def("max", static_cast<vec4(*)(const vec4 &, const vec4 &)>(&max<float>))
        .def("max", static_cast<vec4(*)(const vec4 &, float)>(&max<float>))
        .def("clamp", static_cast<vec4(*)(const vec4 &, const vec4 &, const vec4 &)>(&clamp<float>))
        .def("clamp", static_cast<vec4(*)(const vec4 &, float, float)>(&clamp<float>))
        .def("mix", static_cast<vec4(*)(const vec4 &, const vec4 &, const vec4 &)>(&mix<float>))
        .def("mix", static_cast<vec4(*)(const vec4 &, const vec4 &, float)>(&mix<float>))
        .def("step", static_cast<vec4(*)(const vec4 &, const vec4 &)>(&step<float>))
        .def("smoothstep", static_cast<vec4(*)(const vec4 &, const vec4 &, const vec4 &)>(&smoothstep<float>))
        .def("smoothstep", static_cast<vec4(*)(float, float, const vec4 &)>(&smoothstep<float>))
        .def("isnan", static_cast<bvec4(*)(const vec4 &)>(&isnan<float>))
        .def("isinf", static_cast<bvec4(*)(const vec4 &)>(&isinf<float>))
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
        .def("length", static_cast<float(*)(const vec4 &)>(&length<vec4>))
        .def("distance", static_cast<float(*)(const vec4 &, const vec4 &)>(&distance<vec4>))
        .def("dot", static_cast<float(*)(const vec4 &, const vec4 &)>(&dot<vec4>))
        .def("normalize", static_cast<vec4(*)(const vec4 &)>(&normalize<vec4>))
        .def("faceforward", static_cast<vec4(*)(const vec4 &, const vec4 &, const vec4 &)>(&faceforward<vec4>))
        .def("reflect", static_cast<vec4(*)(const vec4 &, const vec4 &)>(&reflect<vec4>))
        .def("refract", static_cast<vec4(*)(const vec4 &, const vec4 &, float)>(&refract<vec4>))
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
        ;

    pybind11::class_<vec2>(module, "vec2")
        .def(pybind11::init<float>())
        .def(pybind11::init<float, float>())
        .def("__pos__", static_cast<vec2(vec2::*)()const>(&vec2::operator +))
        .def("__neg__", static_cast<vec2(vec2::*)()const>(&vec2::operator -))
        .def("__add__", static_cast<vec2(vec2::*)(float)const>(&vec2::operator +))
        .def("__add__", static_cast<vec2(vec2::*)(const vec2 &)const>(&vec2::operator +))
        .def("__sub__", static_cast<vec2(vec2::*)(float)const>(&vec2::operator -))
        .def("__sub__", static_cast<vec2(vec2::*)(const vec2 &)const>(&vec2::operator -))
        .def("__mul__", static_cast<vec2(vec2::*)(float)const>(&vec2::operator *))
        .def("__mul__", static_cast<vec2(vec2::*)(const vec2 &)const>(&vec2::operator *))
        .def("__truediv__", static_cast<vec2(vec2::*)(float)const>(&vec2::operator /))
        .def("__truediv__", static_cast<vec2(vec2::*)(const vec2 &)const>(&vec2::operator /))
        .def("__iadd__", static_cast<vec2 &(vec2::*)(float)>(&vec2::operator +=))
        .def("__iadd__", static_cast<vec2 &(vec2::*)(const vec2 &)>(&vec2::operator +=))
        .def("__isub__", static_cast<vec2 &(vec2::*)(float)>(&vec2::operator -=))
        .def("__isub__", static_cast<vec2 &(vec2::*)(const vec2 &)>(&vec2::operator -=))
        .def("__imul__", static_cast<vec2 &(vec2::*)(float)>(&vec2::operator *=))
        .def("__imul__", static_cast<vec2 &(vec2::*)(const vec2 &)>(&vec2::operator *=))
        .def("__itruediv__", static_cast<vec2 &(vec2::*)(float)>(&vec2::operator /=))
        .def("__itruediv__", static_cast<vec2 &(vec2::*)(const vec2& )>(&vec2::operator /=))
        .def("__repr__", [](const vec2 &self) {
            std::ostringstream oss;
            oss << "<vec2: (" << repr(self.x) << ", " << repr(self.y) << ")>";
            return oss.str();
        })
        .def_property("x", [](const vec2 &self) {
            return self.x;
        }, [](vec2 &self, vec2::Type_t x) {
            self.x = x;
        })
        .def_property("y", [](const vec2 &self) {
            return self.y;
        }, [](vec2 &self, vec2::Type_t y) {
            self.y = y;
        })
        .def_property("r", [](const vec2 &self) {
            return self.x;
        }, [](vec2 &self, vec2::Type_t x) {
            self.x = x;
        })
        .def_property("g", [](const vec2 &self) {
            return self.y;
        }, [](vec2 &self, vec2::Type_t y) {
            self.y = y;
        })
        .def_property("s", [](const vec2 &self) {
            return self.x;
        }, [](vec2 &self, vec2::Type_t x) {
            self.x = x;
        })
        .def_property("t", [](const vec2 &self) {
            return self.y;
        }, [](vec2 &self, vec2::Type_t y) {
            self.y = y;
        })
        // swizzle
        .def("__getattr__", [](const vec2 &self, const std::string &name) -> pybind11::object {
            int xyzw = 0, rgba = 0, stpq = 0;
            bool swizzle = true;
            for (std::size_t i = 0; i < name.size(); ++i) {
                switch (name[i]) {
                case 'x':
                case 'y':
                    xyzw += 1;
                    break;
                case 'r':
                case 'g':
                    rgba += 1;
                    break;
                case 's':
                case 't':
                    stpq += 1;
                    break;
                default:
                    swizzle = false;
                    break;
                }
            }
            if ( swizzle ) {
                if ( xyzw > 0 ) {
                    if ( rgba + stpq > 0 || xyzw > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 'x':
                            tmp[i] = self.x;
                            break;
                        case 'y':
                            tmp[i] = self.y;
                            break;
                        }
                    }
                    switch (xyzw) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else if ( rgba > 0 ) {
                    if ( xyzw + stpq > 0 || rgba > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 'r':
                            tmp[i] = self.x;
                            break;
                        case 'g':
                            tmp[i] = self.y;
                            break;
                        }
                    }
                    switch (rgba) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else if ( stpq > 0 ) {
                    if ( xyzw + rgba > 0 || stpq > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 's':
                            tmp[i] = self.x;
                            break;
                        case 't':
                            tmp[i] = self.y;
                            break;
                        }
                    }
                    switch (stpq) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else {
                    throw pybind11::attribute_error("no such attribute: " + name);
                }
            }
            throw pybind11::attribute_error("no such attribute: " + name);
        })
        ;
    pybind11::class_<vec3>(module, "vec3")
        .def(pybind11::init<float>())
        .def(pybind11::init<float, float, float>())
        .def(pybind11::init<const vec2 &, float>())
        .def(pybind11::init<float, const vec2 &>())
        .def("__pos__", static_cast<vec3(vec3::*)()const>(&vec3::operator +))
        .def("__neg__", static_cast<vec3(vec3::*)()const>(&vec3::operator -))
        .def("__add__", static_cast<vec3(vec3::*)(float)const>(&vec3::operator +))
        .def("__add__", static_cast<vec3(vec3::*)(const vec3 &)const>(&vec3::operator +))
        .def("__sub__", static_cast<vec3(vec3::*)(float)const>(&vec3::operator -))
        .def("__sub__", static_cast<vec3(vec3::*)(const vec3 &)const>(&vec3::operator -))
        .def("__mul__", static_cast<vec3(vec3::*)(float)const>(&vec3::operator *))
        .def("__mul__", static_cast<vec3(vec3::*)(const vec3 &)const>(&vec3::operator *))
        .def("__truediv__", static_cast<vec3(vec3::*)(float)const>(&vec3::operator /))
        .def("__truediv__", static_cast<vec3(vec3::*)(const vec3 &)const>(&vec3::operator /))
        .def("__iadd__", static_cast<vec3 &(vec3::*)(float)>(&vec3::operator +=))
        .def("__iadd__", static_cast<vec3 &(vec3::*)(const vec3 &)>(&vec3::operator +=))
        .def("__isub__", static_cast<vec3 &(vec3::*)(float)>(&vec3::operator -=))
        .def("__isub__", static_cast<vec3 &(vec3::*)(const vec3 &)>(&vec3::operator -=))
        .def("__imul__", static_cast<vec3 &(vec3::*)(float)>(&vec3::operator *=))
        .def("__imul__", static_cast<vec3 &(vec3::*)(const vec3 &)>(&vec3::operator *=))
        .def("__itruediv__", static_cast<vec3 &(vec3::*)(float)>(&vec3::operator /=))
        .def("__itruediv__", static_cast<vec3 &(vec3::*)(const vec3& )>(&vec3::operator /=))
        .def("__repr__", [](const vec3 &self) {
            std::ostringstream oss;
            oss << "<vec3: (" << repr(self.x) << ", " << repr(self.y) << ", " << repr(self.z) << ")>";
            return oss.str();
        })
        .def_property("x", [](const vec3 &self) {
            return self.x;
        }, [](vec3 &self, vec3::Type_t x) {
            self.x = x;
        })
        .def_property("y", [](const vec3 &self) {
            return self.y;
        }, [](vec3 &self, vec3::Type_t y) {
            self.y = y;
        })
        .def_property("z", [](const vec3 &self) {
            return self.z;
        }, [](vec3 &self, vec3::Type_t z) {
            self.z = z;
        })
        .def_property("r", [](const vec3 &self) {
            return self.x;
        }, [](vec3 &self, vec3::Type_t x) {
            self.x = x;
        })
        .def_property("g", [](const vec3 &self) {
            return self.y;
        }, [](vec3 &self, vec3::Type_t y) {
            self.y = y;
        })
        .def_property("b", [](const vec3 &self) {
            return self.z;
        }, [](vec3 &self, vec3::Type_t z) {
            self.z = z;
        })
        .def_property("s", [](const vec3 &self) {
            return self.x;
        }, [](vec3 &self, vec3::Type_t x) {
            self.x = x;
        })
        .def_property("t", [](const vec3 &self) {
            return self.y;
        }, [](vec3 &self, vec3::Type_t y) {
            self.y = y;
        })
        .def_property("p", [](const vec3 &self) {
            return self.z;
        }, [](vec3 &self, vec3::Type_t z) {
            self.z = z;
        })
        // swizzle
        .def("__getattr__", [](const vec3 &self, const std::string &name) -> pybind11::object {
            int xyzw = 0, rgba = 0, stpq = 0;
            bool swizzle = true;
            for (std::size_t i = 0; i < name.size(); ++i) {
                switch (name[i]) {
                case 'x':
                case 'y':
                case 'z':
                    xyzw += 1;
                    break;
                case 'r':
                case 'g':
                case 'b':
                    rgba += 1;
                    break;
                case 's':
                case 't':
                case 'p':
                    stpq += 1;
                    break;
                default:
                    swizzle = false;
                    break;
                }
            }
            if ( swizzle ) {
                if ( xyzw > 0 ) {
                    if ( rgba + stpq > 0 || xyzw > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 'x':
                            tmp[i] = self.x;
                            break;
                        case 'y':
                            tmp[i] = self.y;
                            break;
                        case 'z':
                            tmp[i] = self.z;
                            break;
                        }
                    }
                    switch (xyzw) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else if ( rgba > 0 ) {
                    if ( xyzw + stpq > 0 || rgba > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 'r':
                            tmp[i] = self.x;
                            break;
                        case 'g':
                            tmp[i] = self.y;
                            break;
                        case 'b':
                            tmp[i] = self.z;
                            break;
                        }
                    }
                    switch (rgba) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else if ( stpq > 0 ) {
                    if ( xyzw + rgba > 0 || stpq > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 's':
                            tmp[i] = self.x;
                            break;
                        case 't':
                            tmp[i] = self.y;
                            break;
                        case 'p':
                            tmp[i] = self.z;
                            break;
                        }
                    }
                    switch (stpq) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else {
                    throw pybind11::attribute_error("no such attribute: " + name);
                }
            }
            throw pybind11::attribute_error("no such attribute: " + name);
        })
        ;
    pybind11::class_<vec4>(module, "vec4")
        .def(pybind11::init<float>())
        .def(pybind11::init<float, float, float, float>())
        .def(pybind11::init<const vec2 &, float, float>())
        .def(pybind11::init<float, const vec2 &, float>())
        .def(pybind11::init<float, float, const vec2 &>())
        .def(pybind11::init<const vec2 &, const vec2 &>())
        .def(pybind11::init<const vec3 &, float>())
        .def(pybind11::init<float, const vec3 &>())
        .def("__pos__", static_cast<vec4(vec4::*)()const>(&vec4::operator +))
        .def("__neg__", static_cast<vec4(vec4::*)()const>(&vec4::operator -))
        .def("__add__", static_cast<vec4(vec4::*)(float)const>(&vec4::operator +))
        .def("__add__", static_cast<vec4(vec4::*)(const vec4 &)const>(&vec4::operator +))
        .def("__sub__", static_cast<vec4(vec4::*)(float)const>(&vec4::operator -))
        .def("__sub__", static_cast<vec4(vec4::*)(const vec4 &)const>(&vec4::operator -))
        .def("__mul__", static_cast<vec4(vec4::*)(float)const>(&vec4::operator *))
        .def("__mul__", static_cast<vec4(vec4::*)(const vec4 &)const>(&vec4::operator *))
        .def("__truediv__", static_cast<vec4(vec4::*)(float)const>(&vec4::operator /))
        .def("__truediv__", static_cast<vec4(vec4::*)(const vec4 &)const>(&vec4::operator /))
        .def("__iadd__", static_cast<vec4 &(vec4::*)(float)>(&vec4::operator +=))
        .def("__iadd__", static_cast<vec4 &(vec4::*)(const vec4 &)>(&vec4::operator +=))
        .def("__isub__", static_cast<vec4 &(vec4::*)(float)>(&vec4::operator -=))
        .def("__isub__", static_cast<vec4 &(vec4::*)(const vec4 &)>(&vec4::operator -=))
        .def("__imul__", static_cast<vec4 &(vec4::*)(float)>(&vec4::operator *=))
        .def("__imul__", static_cast<vec4 &(vec4::*)(const vec4 &)>(&vec4::operator *=))
        .def("__itruediv__", static_cast<vec4 &(vec4::*)(float)>(&vec4::operator /=))
        .def("__itruediv__", static_cast<vec4 &(vec4::*)(const vec4& )>(&vec4::operator /=))
        .def("__repr__", [](const vec4 &self) {
            std::ostringstream oss;
            oss << "<vec4: (" << repr(self.x) << ", " << repr(self.y) << ", " << repr(self.z) << ", " << repr(self.w) << ")>";
            return oss.str();
        })
        .def_property("x", [](const vec4 &self) {
            return self.x;
        }, [](vec4 &self, vec4::Type_t x) {
            self.x = x;
        })
        .def_property("y", [](const vec4 &self) {
            return self.y;
        }, [](vec4 &self, vec4::Type_t y) {
            self.y = y;
        })
        .def_property("z", [](const vec4 &self) {
            return self.z;
        }, [](vec4 &self, vec4::Type_t z) {
            self.z = z;
        })
        .def_property("w", [](const vec4 &self) {
            return self.w;
        }, [](vec4 &self, vec4::Type_t w) {
            self.w = w;
        })
        .def_property("r", [](const vec4 &self) {
            return self.x;
        }, [](vec4 &self, vec4::Type_t x) {
            self.x = x;
        })
        .def_property("g", [](const vec4 &self) {
            return self.y;
        }, [](vec4 &self, vec4::Type_t y) {
            self.y = y;
        })
        .def_property("b", [](const vec4 &self) {
            return self.z;
        }, [](vec4 &self, vec4::Type_t z) {
            self.z = z;
        })
        .def_property("a", [](const vec4 &self) {
            return self.w;
        }, [](vec4 &self, vec4::Type_t w) {
            self.w = w;
        })
        .def_property("s", [](const vec4 &self) {
            return self.x;
        }, [](vec4 &self, vec4::Type_t x) {
            self.x = x;
        })
        .def_property("t", [](const vec4 &self) {
            return self.y;
        }, [](vec4 &self, vec4::Type_t y) {
            self.y = y;
        })
        .def_property("p", [](const vec4 &self) {
            return self.z;
        }, [](vec4 &self, vec4::Type_t z) {
            self.z = z;
        })
        .def_property("q", [](const vec4 &self) {
            return self.w;
        }, [](vec4 &self, vec4::Type_t w) {
            self.w = w;
        })
        // swizzle
        .def("__getattr__", [](const vec4 &self, const std::string &name) -> pybind11::object {
            int xyzw = 0, rgba = 0, stpq = 0;
            bool swizzle = true;
            for (std::size_t i = 0; i < name.size(); ++i) {
                switch (name[i]) {
                case 'x':
                case 'y':
                case 'z':
                case 'w':
                    xyzw += 1;
                    break;
                case 'r':
                case 'g':
                case 'b':
                case 'a':
                    rgba += 1;
                    break;
                case 's':
                case 't':
                case 'p':
                case 'q':
                    stpq += 1;
                    break;
                default:
                    swizzle = false;
                    break;
                }
                if ( !swizzle ) {
                    break;
                }
            }
            if ( swizzle ) {
                if ( xyzw > 0 ) {
                    if ( rgba + stpq > 0 || xyzw > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 'x':
                            tmp[i] = self.x;
                            break;
                        case 'y':
                            tmp[i] = self.y;
                            break;
                        case 'z':
                            tmp[i] = self.z;
                            break;
                        case 'w':
                            tmp[i] = self.w;
                            break;
                        }
                    }
                    switch (xyzw) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else if ( rgba > 0 ) {
                    if ( xyzw + stpq > 0 || rgba > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 'r':
                            tmp[i] = self.x;
                            break;
                        case 'g':
                            tmp[i] = self.y;
                            break;
                        case 'b':
                            tmp[i] = self.z;
                            break;
                        case 'a':
                            tmp[i] = self.w;
                            break;
                        }
                    }
                    switch (rgba) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else if ( stpq > 0 ) {
                    if ( xyzw + rgba > 0 || stpq > 4 ) {
                        throw pybind11::attribute_error("illegal attribute: " + name);
                    }
                    std::array<float, 4> tmp;
                    for (std::size_t i = 0; i < name.size(); ++i) {
                        switch (name[i]) {
                        case 's':
                            tmp[i] = self.x;
                            break;
                        case 't':
                            tmp[i] = self.y;
                            break;
                        case 'p':
                            tmp[i] = self.z;
                            break;
                        case 'q':
                            tmp[i] = self.w;
                            break;
                        }
                    }
                    switch (stpq) {
                    case 2:
                        return pybind11::cast(vec2(tmp[0], tmp[1]));
                    case 3:
                        return pybind11::cast(vec3(tmp[0], tmp[1], tmp[2]));
                    case 4:
                        return pybind11::cast(vec4(tmp[0], tmp[1], tmp[2], tmp[3]));
                    default:
                        throw std::invalid_argument("never");
                    }
                } else {
                    throw pybind11::attribute_error("no such attribute: " + name);
                }
            }
            throw pybind11::attribute_error("no such attribute: " + name);
        })
        ;

    pybind11::class_<mat2>(module, "mat2")
        .def(pybind11::init<>())
        .def(pybind11::init<
            float, float,
            float, float>())
        .def(pybind11::init<const vec2 &, const vec2 &>())
        .def("__mul__", static_cast<vec2 (mat2::*)(const vec2 &) const>(&mat2::operator *))
        .def("__mul__", static_cast<mat2 (mat2::*)(const mat2 &) const>(&mat2::operator *))
        .def("__repr__", [](const mat2 &self) {
            std::ostringstream oss;
            oss << "<mat2: ("
                << repr(self.f11) << ", " << repr(self.f21) << ", "
                << repr(self.f12) << ", " << repr(self.f22)
                << ")>";
            return oss.str();
        })
        ;

    pybind11::class_<mat3>(module, "mat3")
        .def(pybind11::init<>())
        .def(pybind11::init<
            float, float, float,
            float, float, float,
            float, float, float>())
        .def(pybind11::init<const vec3 &, const vec3 &, const vec3 &>())
        .def("__mul__", static_cast<vec3 (mat3::*)(const vec3 &) const>(&mat3::operator *))
        .def("__mul__", static_cast<mat3 (mat3::*)(const mat3 &) const>(&mat3::operator *))
        .def("__repr__", [](const mat3 &self) {
            std::ostringstream oss;
            oss << "<mat3: ("
                << repr(self.f11) << ", " << repr(self.f21) << ", " << repr(self.f31) << ", "
                << repr(self.f12) << ", " << repr(self.f22) << ", " << repr(self.f32) << ", "
                << repr(self.f13) << ", " << repr(self.f23) << ", " << repr(self.f33)
                << ")>";
            return oss.str();
        })
        ;

    pybind11::class_<mat4>(module, "mat4")
        .def(pybind11::init<>())
        .def(pybind11::init<
            float, float, float, float,
            float, float, float, float,
            float, float, float, float,
            float, float, float, float>())
        .def(pybind11::init<const vec4 &, const vec4 &, const vec4 &, const vec4 &>())
        .def("__mul__", static_cast<vec4 (mat4::*)(const vec4 &) const>(&mat4::operator *))
        .def("__mul__", static_cast<mat4 (mat4::*)(const mat4 &) const>(&mat4::operator *))
        .def("__repr__", [](const mat4 &self) {
            std::ostringstream oss;
            oss << "<mat4: ("
                << repr(self.f11) << ", " << repr(self.f21) << ", " << repr(self.f31) << ", " << repr(self.f41) << ", "
                << repr(self.f12) << ", " << repr(self.f22) << ", " << repr(self.f32) << ", " << repr(self.f42) << ", "
                << repr(self.f13) << ", " << repr(self.f23) << ", " << repr(self.f33) << ", " << repr(self.f43) << ", "
                << repr(self.f14) << ", " << repr(self.f24) << ", " << repr(self.f34) << ", " << repr(self.f44)
                << ")>";
            return oss.str();
        })
        ;

    module.def("realize4", &realize<vec4, 4>);
    module.def("realize3", &realize<vec3, 3>);
}
