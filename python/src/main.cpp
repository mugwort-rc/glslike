#include <sstream>
#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#define GLSLIKE_DISABLE_SWIZZLE
#include "glslike.hpp"
#include "glslike_io.hpp"

using namespace glslike;


PYBIND11_MODULE(__glslike, module) {
    module
        // scalar
        .def("min", &min<float>)
        .def("max", &max<float>)
        .def("clamp", static_cast<float(*)(float, float, float)>(&clamp<float>))
        .def("exp", static_cast<float(*)(float)>(&exp<float>))
        .def("pow", static_cast<float(*)(float, float)>(&pow<float>))
        // vec2
        .def("clamp", static_cast<vec2(*)(const vec2 &, float, float)>(&clamp<float>))
        .def("exp", static_cast<vec2(*)(const vec2 &)>(&exp<float>))
        .def("pow", static_cast<vec2(*)(const vec2 &, float)>(&pow<float>))
        .def("length", static_cast<float(*)(const vec2 &)>(&length<vec2>))
        .def("distance", static_cast<float(*)(const vec2 &, const vec2 &)>(&distance<vec2>))
        .def("normalize", static_cast<vec2(*)(const vec2 &)>(&normalize<vec2>))
        .def("dot", static_cast<float(*)(const vec2 &, const vec2 &)>(&dot<vec2>))
        // vec3
        .def("clamp", static_cast<vec3(*)(const vec3 &, float, float)>(&clamp<float>))
        .def("exp", static_cast<vec3(*)(const vec3 &)>(&exp<float>))
        .def("pow", static_cast<vec3(*)(const vec3 &, float)>(&pow<float>))
        .def("length", static_cast<float(*)(const vec3 &)>(&length<vec3>))
        .def("distance", static_cast<float(*)(const vec3 &, const vec3 &)>(&distance<vec3>))
        .def("normalize", static_cast<vec3(*)(const vec3 &)>(&normalize<vec3>))
        .def("dot", static_cast<float(*)(const vec3 &, const vec3 &)>(&dot<vec3>))
        .def("cross", &cross<float>)
        // vec4
        .def("clamp", static_cast<vec4(*)(const vec4 &, float, float)>(&clamp<float>))
        .def("exp", static_cast<vec4(*)(const vec4 &)>(&exp<float>))
        .def("pow", static_cast<vec4(*)(const vec4 &, float)>(&pow<float>))
        .def("length", static_cast<float(*)(const vec4 &)>(&length<vec4>))
        .def("distance", static_cast<float(*)(const vec4 &, const vec4 &)>(&distance<vec4>))
        .def("normalize", static_cast<vec4(*)(const vec4 &)>(&normalize<vec4>))
        .def("dot", static_cast<float(*)(const vec4 &, const vec4 &)>(&dot<vec4>))
        ;

    pybind11::class_<vec2>(module, "vec2")
        .def(pybind11::init<float>())
        .def(pybind11::init<float, float>())
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
            oss << std::scientific << "<vec2: (" << self.x << ", " << self.y << ")>";
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
            oss << std::scientific << "<vec3: (" << self.x << ", " << self.y << ", " << self.z << ")>";
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
            oss << std::scientific << "<vec4: (" << self.x << ", " << self.y << ", " << self.z << ", " << self.w << ")>";
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
            oss << std::scientific << "<mat2: ("
                << self.f11 << ", " << self.f21 << ", "
                << self.f12 << ", " << self.f22
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
            oss << std::scientific << "<mat3: ("
                << self.f11 << ", " << self.f21 << ", " << self.f31 << ", "
                << self.f12 << ", " << self.f22 << ", " << self.f32 << ", "
                << self.f13 << ", " << self.f23 << ", " << self.f33
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
            oss << std::scientific << "<mat4: ("
                << self.f11 << ", " << self.f21 << ", " << self.f31 << ", " << self.f41 << ", "
                << self.f12 << ", " << self.f22 << ", " << self.f32 << ", " << self.f42 << ", "
                << self.f13 << ", " << self.f23 << ", " << self.f33 << ", " << self.f43 << ", "
                << self.f14 << ", " << self.f24 << ", " << self.f34 << ", " << self.f44
                << ")>";
            return oss.str();
        })
        ;
}
