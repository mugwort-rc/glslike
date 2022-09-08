// g++ main.cpp -std=c++17 -I../ -I./googletest-release-1.12.1/googletest/include -L./googletest-release-1.12.1/build/lib -lgtest -lgtest_main -pthread

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


#include <gtest/gtest.h>

#include "glslike.hpp"

using namespace glslike;


TEST(GlslikeVector2, Attributes) {
    vec2 v(1.0f, 2.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
}

TEST(GlslikeVector2, AliasRg) {
    vec2 v(1.0f, 2.0f);
    EXPECT_EQ(v.r, 1.0f);
    EXPECT_EQ(v.g, 2.0f);
}

TEST(GlslikeVector2, AliasSt) {
    vec2 v(1.0f, 2.0f);
    EXPECT_EQ(v.s, 1.0f);
    EXPECT_EQ(v.t, 2.0f);
}

TEST(GlslikeVector2, Index) {
    vec2 v(1.0f, 2.0f);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
}

TEST(GlslikeVector2, Swizzle2Xy) {
    vec2 vec(1.0f, 2.0f);

    // xx
    {
        vec2 v2 = vec.xx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // xy
    {
        vec2 v2 = vec.xy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // yx
    {
        vec2 v2 = vec.yx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // yy
    {
        vec2 v2 = vec.yy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle2Rg) {
    vec2 vec(1.0f, 2.0f);

    // rr
    {
        vec2 v2 = vec.rr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // rg
    {
        vec2 v2 = vec.rg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // gr
    {
        vec2 v2 = vec.gr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // gg
    {
        vec2 v2 = vec.gg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle2St) {
    vec2 vec(1.0f, 2.0f);

    // ss
    {
        vec2 v2 = vec.ss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // st
    {
        vec2 v2 = vec.st;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // ts
    {
        vec2 v2 = vec.ts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // tt
    {
        vec2 v2 = vec.tt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle3Xyz) {
    vec2 vec(1.0f, 2.0f);

    // xxx
    {
        vec3 v2 = vec.xxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xxy
    {
        vec3 v2 = vec.xxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xyx
    {
        vec3 v2 = vec.xyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xyy
    {
        vec3 v2 = vec.xyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yxx
    {
        vec3 v2 = vec.yxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yxy
    {
        vec3 v2 = vec.yxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yyx
    {
        vec3 v2 = vec.yyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yyy
    {
        vec3 v2 = vec.yyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle3Rgb) {
    vec2 vec(1.0f, 2.0f);

    // rrr
    {
        vec3 v2 = vec.rrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rrg
    {
        vec3 v2 = vec.rrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rgr
    {
        vec3 v2 = vec.rgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rgg
    {
        vec3 v2 = vec.rgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // grr
    {
        vec3 v2 = vec.grr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // grg
    {
        vec3 v2 = vec.grg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ggr
    {
        vec3 v2 = vec.ggr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ggg
    {
        vec3 v2 = vec.ggg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle3Stp) {
    vec2 vec(1.0f, 2.0f);

    // sss
    {
        vec3 v2 = vec.sss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // sst
    {
        vec3 v2 = vec.sst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // sts
    {
        vec3 v2 = vec.sts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // stt
    {
        vec3 v2 = vec.stt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tss
    {
        vec3 v2 = vec.tss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // tst
    {
        vec3 v2 = vec.tst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tts
    {
        vec3 v2 = vec.tts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ttt
    {
        vec3 v2 = vec.ttt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle4Xyzw) {
    vec2 vec(1.0f, 2.0f);

    // xxxx
    {
        vec4 v2 = vec.xxxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxxy
    {
        vec4 v2 = vec.xxxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxyx
    {
        vec4 v2 = vec.xxyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxyy
    {
        vec4 v2 = vec.xxyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyxx
    {
        vec4 v2 = vec.xyxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyxy
    {
        vec4 v2 = vec.xyxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyyx
    {
        vec4 v2 = vec.xyyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyyy
    {
        vec4 v2 = vec.xyyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxxx
    {
        vec4 v2 = vec.yxxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxxy
    {
        vec4 v2 = vec.yxxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxyx
    {
        vec4 v2 = vec.yxyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxyy
    {
        vec4 v2 = vec.yxyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyxx
    {
        vec4 v2 = vec.yyxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyxy
    {
        vec4 v2 = vec.yyxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyyx
    {
        vec4 v2 = vec.yyyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyyy
    {
        vec4 v2 = vec.yyyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle4Rgba) {
    vec2 vec(1.0f, 2.0f);

    // rrrr
    {
        vec4 v2 = vec.rrrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrrg
    {
        vec4 v2 = vec.rrrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrgr
    {
        vec4 v2 = vec.rrgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrgg
    {
        vec4 v2 = vec.rrgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rgrr
    {
        vec4 v2 = vec.rgrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rgrg
    {
        vec4 v2 = vec.rgrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rggr
    {
        vec4 v2 = vec.rggr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rggg
    {
        vec4 v2 = vec.rggg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grrr
    {
        vec4 v2 = vec.grrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grrg
    {
        vec4 v2 = vec.grrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grgr
    {
        vec4 v2 = vec.grgr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grgg
    {
        vec4 v2 = vec.grgg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ggrr
    {
        vec4 v2 = vec.ggrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ggrg
    {
        vec4 v2 = vec.ggrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gggr
    {
        vec4 v2 = vec.gggr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gggg
    {
        vec4 v2 = vec.gggg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
}

TEST(GlslikeVector2, Swizzle4Stpq) {
    vec2 vec(1.0f, 2.0f);

    // ssss
    {
        vec4 v2 = vec.ssss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ssst
    {
        vec4 v2 = vec.ssst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ssts
    {
        vec4 v2 = vec.ssts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sstt
    {
        vec4 v2 = vec.sstt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stss
    {
        vec4 v2 = vec.stss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // stst
    {
        vec4 v2 = vec.stst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stts
    {
        vec4 v2 = vec.stts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sttt
    {
        vec4 v2 = vec.sttt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tsss
    {
        vec4 v2 = vec.tsss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tsst
    {
        vec4 v2 = vec.tsst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tsts
    {
        vec4 v2 = vec.tsts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tstt
    {
        vec4 v2 = vec.tstt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttss
    {
        vec4 v2 = vec.ttss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ttst
    {
        vec4 v2 = vec.ttst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttts
    {
        vec4 v2 = vec.ttts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tttt
    {
        vec4 v2 = vec.tttt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
}


TEST(GlslikeVector3, Attributes) {
    vec3 v(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
    EXPECT_EQ(v.z, 3.0f);
}

TEST(GlslikeVector3, AliasRgb) {
    vec3 v(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(v.r, 1.0f);
    EXPECT_EQ(v.g, 2.0f);
    EXPECT_EQ(v.b, 3.0f);
}

TEST(GlslikeVector3, AliasStp) {
    vec3 v(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(v.s, 1.0f);
    EXPECT_EQ(v.t, 2.0f);
    EXPECT_EQ(v.p, 3.0f);
}

TEST(GlslikeVector3, Index) {
    vec3 v(1.0f, 2.0f, 3.0f);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
    EXPECT_EQ(v[2], 3.0f);
}

TEST(GlslikeVector3, Swizzle2Xy) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // xx
    {
        vec2 v2 = vec.xx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // xy
    {
        vec2 v2 = vec.xy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // xz
    {
        vec2 v2 = vec.xz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // yx
    {
        vec2 v2 = vec.yx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // yy
    {
        vec2 v2 = vec.yy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // yz
    {
        vec2 v2 = vec.yz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // zx
    {
        vec2 v2 = vec.zx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // zy
    {
        vec2 v2 = vec.zy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // zz
    {
        vec2 v2 = vec.zz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle2Rg) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // rr
    {
        vec2 v2 = vec.rr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // rg
    {
        vec2 v2 = vec.rg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // rb
    {
        vec2 v2 = vec.rb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // gr
    {
        vec2 v2 = vec.gr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // gg
    {
        vec2 v2 = vec.gg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // gb
    {
        vec2 v2 = vec.gb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // br
    {
        vec2 v2 = vec.br;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // bg
    {
        vec2 v2 = vec.bg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // bb
    {
        vec2 v2 = vec.bb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle2St) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // ss
    {
        vec2 v2 = vec.ss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // st
    {
        vec2 v2 = vec.st;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // sp
    {
        vec2 v2 = vec.sp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // ts
    {
        vec2 v2 = vec.ts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // tt
    {
        vec2 v2 = vec.tt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // tp
    {
        vec2 v2 = vec.tp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // ps
    {
        vec2 v2 = vec.ps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // pt
    {
        vec2 v2 = vec.pt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // pp
    {
        vec2 v2 = vec.pp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle3Xyz) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // xxx
    {
        vec3 v2 = vec.xxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xxy
    {
        vec3 v2 = vec.xxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xxz
    {
        vec3 v2 = vec.xxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // xyx
    {
        vec3 v2 = vec.xyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xyy
    {
        vec3 v2 = vec.xyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xyz
    {
        vec3 v2 = vec.xyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // xzx
    {
        vec3 v2 = vec.xzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xzy
    {
        vec3 v2 = vec.xzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xzz
    {
        vec3 v2 = vec.xzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yxx
    {
        vec3 v2 = vec.yxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yxy
    {
        vec3 v2 = vec.yxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yxz
    {
        vec3 v2 = vec.yxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yyx
    {
        vec3 v2 = vec.yyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yyy
    {
        vec3 v2 = vec.yyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yyz
    {
        vec3 v2 = vec.yyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yzx
    {
        vec3 v2 = vec.yzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yzy
    {
        vec3 v2 = vec.yzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yzz
    {
        vec3 v2 = vec.yzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zxx
    {
        vec3 v2 = vec.zxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zxy
    {
        vec3 v2 = vec.zxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zxz
    {
        vec3 v2 = vec.zxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zyx
    {
        vec3 v2 = vec.zyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zyy
    {
        vec3 v2 = vec.zyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zyz
    {
        vec3 v2 = vec.zyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zzx
    {
        vec3 v2 = vec.zzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zzy
    {
        vec3 v2 = vec.zzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zzz
    {
        vec3 v2 = vec.zzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle3Rgb) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // rrr
    {
        vec3 v2 = vec.rrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rrg
    {
        vec3 v2 = vec.rrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rrb
    {
        vec3 v2 = vec.rrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // rgr
    {
        vec3 v2 = vec.rgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rgg
    {
        vec3 v2 = vec.rgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rgb
    {
        vec3 v2 = vec.rgb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // rbr
    {
        vec3 v2 = vec.rbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rbg
    {
        vec3 v2 = vec.rbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rbb
    {
        vec3 v2 = vec.rbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // grr
    {
        vec3 v2 = vec.grr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // grg
    {
        vec3 v2 = vec.grg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // grb
    {
        vec3 v2 = vec.grb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // ggr
    {
        vec3 v2 = vec.ggr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ggg
    {
        vec3 v2 = vec.ggg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ggb
    {
        vec3 v2 = vec.ggb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // gbr
    {
        vec3 v2 = vec.gbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // gbg
    {
        vec3 v2 = vec.gbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // gbb
    {
        vec3 v2 = vec.gbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // brr
    {
        vec3 v2 = vec.brr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // brg
    {
        vec3 v2 = vec.brg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // brb
    {
        vec3 v2 = vec.brb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // bgr
    {
        vec3 v2 = vec.bgr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // bgg
    {
        vec3 v2 = vec.bgg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // bgb
    {
        vec3 v2 = vec.bgb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // bbr
    {
        vec3 v2 = vec.bbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // bbg
    {
        vec3 v2 = vec.bbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // bbb
    {
        vec3 v2 = vec.bbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle3Stp) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // sss
    {
        vec3 v2 = vec.sss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // sst
    {
        vec3 v2 = vec.sst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ssp
    {
        vec3 v2 = vec.ssp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // sts
    {
        vec3 v2 = vec.sts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // stt
    {
        vec3 v2 = vec.stt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // stp
    {
        vec3 v2 = vec.stp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // sps
    {
        vec3 v2 = vec.sps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // spt
    {
        vec3 v2 = vec.spt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // spp
    {
        vec3 v2 = vec.spp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // tss
    {
        vec3 v2 = vec.tss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // tst
    {
        vec3 v2 = vec.tst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tsp
    {
        vec3 v2 = vec.tsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // tts
    {
        vec3 v2 = vec.tts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ttt
    {
        vec3 v2 = vec.ttt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ttp
    {
        vec3 v2 = vec.ttp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // tps
    {
        vec3 v2 = vec.tps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // tpt
    {
        vec3 v2 = vec.tpt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tpp
    {
        vec3 v2 = vec.tpp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // pss
    {
        vec3 v2 = vec.pss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // pst
    {
        vec3 v2 = vec.pst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // psp
    {
        vec3 v2 = vec.psp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // pts
    {
        vec3 v2 = vec.pts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ptt
    {
        vec3 v2 = vec.ptt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ptp
    {
        vec3 v2 = vec.ptp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // pps
    {
        vec3 v2 = vec.pps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ppt
    {
        vec3 v2 = vec.ppt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ppp
    {
        vec3 v2 = vec.ppp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle4Xyzw) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // xxxx
    {
        vec4 v2 = vec.xxxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxxy
    {
        vec4 v2 = vec.xxxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxxz
    {
        vec4 v2 = vec.xxxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xxyx
    {
        vec4 v2 = vec.xxyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxyy
    {
        vec4 v2 = vec.xxyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxyz
    {
        vec4 v2 = vec.xxyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xxzx
    {
        vec4 v2 = vec.xxzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxzy
    {
        vec4 v2 = vec.xxzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxzz
    {
        vec4 v2 = vec.xxzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyxx
    {
        vec4 v2 = vec.xyxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyxy
    {
        vec4 v2 = vec.xyxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyxz
    {
        vec4 v2 = vec.xyxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyyx
    {
        vec4 v2 = vec.xyyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyyy
    {
        vec4 v2 = vec.xyyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyyz
    {
        vec4 v2 = vec.xyyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyzx
    {
        vec4 v2 = vec.xyzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyzy
    {
        vec4 v2 = vec.xyzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyzz
    {
        vec4 v2 = vec.xyzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzxx
    {
        vec4 v2 = vec.xzxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzxy
    {
        vec4 v2 = vec.xzxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzxz
    {
        vec4 v2 = vec.xzxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzyx
    {
        vec4 v2 = vec.xzyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzyy
    {
        vec4 v2 = vec.xzyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzyz
    {
        vec4 v2 = vec.xzyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzzx
    {
        vec4 v2 = vec.xzzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzzy
    {
        vec4 v2 = vec.xzzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzzz
    {
        vec4 v2 = vec.xzzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxxx
    {
        vec4 v2 = vec.yxxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxxy
    {
        vec4 v2 = vec.yxxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxxz
    {
        vec4 v2 = vec.yxxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxyx
    {
        vec4 v2 = vec.yxyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxyy
    {
        vec4 v2 = vec.yxyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxyz
    {
        vec4 v2 = vec.yxyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxzx
    {
        vec4 v2 = vec.yxzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxzy
    {
        vec4 v2 = vec.yxzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxzz
    {
        vec4 v2 = vec.yxzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyxx
    {
        vec4 v2 = vec.yyxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyxy
    {
        vec4 v2 = vec.yyxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyxz
    {
        vec4 v2 = vec.yyxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyyx
    {
        vec4 v2 = vec.yyyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyyy
    {
        vec4 v2 = vec.yyyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyyz
    {
        vec4 v2 = vec.yyyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyzx
    {
        vec4 v2 = vec.yyzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyzy
    {
        vec4 v2 = vec.yyzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyzz
    {
        vec4 v2 = vec.yyzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzxx
    {
        vec4 v2 = vec.yzxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzxy
    {
        vec4 v2 = vec.yzxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzxz
    {
        vec4 v2 = vec.yzxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzyx
    {
        vec4 v2 = vec.yzyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzyy
    {
        vec4 v2 = vec.yzyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzyz
    {
        vec4 v2 = vec.yzyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzzx
    {
        vec4 v2 = vec.yzzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzzy
    {
        vec4 v2 = vec.yzzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzzz
    {
        vec4 v2 = vec.yzzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxxx
    {
        vec4 v2 = vec.zxxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxxy
    {
        vec4 v2 = vec.zxxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxxz
    {
        vec4 v2 = vec.zxxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxyx
    {
        vec4 v2 = vec.zxyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxyy
    {
        vec4 v2 = vec.zxyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxyz
    {
        vec4 v2 = vec.zxyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxzx
    {
        vec4 v2 = vec.zxzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxzy
    {
        vec4 v2 = vec.zxzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxzz
    {
        vec4 v2 = vec.zxzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyxx
    {
        vec4 v2 = vec.zyxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zyxy
    {
        vec4 v2 = vec.zyxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zyxz
    {
        vec4 v2 = vec.zyxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyyx
    {
        vec4 v2 = vec.zyyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zyyy
    {
        vec4 v2 = vec.zyyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zyyz
    {
        vec4 v2 = vec.zyyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyzx
    {
        vec4 v2 = vec.zyzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zyzy
    {
        vec4 v2 = vec.zyzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zyzz
    {
        vec4 v2 = vec.zyzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzxx
    {
        vec4 v2 = vec.zzxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzxy
    {
        vec4 v2 = vec.zzxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzxz
    {
        vec4 v2 = vec.zzxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzyx
    {
        vec4 v2 = vec.zzyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzyy
    {
        vec4 v2 = vec.zzyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzyz
    {
        vec4 v2 = vec.zzyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzzx
    {
        vec4 v2 = vec.zzzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzzy
    {
        vec4 v2 = vec.zzzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzzz
    {
        vec4 v2 = vec.zzzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle4Rgba) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // rrrr
    {
        vec4 v2 = vec.rrrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrrg
    {
        vec4 v2 = vec.rrrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrrb
    {
        vec4 v2 = vec.rrrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rrgr
    {
        vec4 v2 = vec.rrgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrgg
    {
        vec4 v2 = vec.rrgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrgb
    {
        vec4 v2 = vec.rrgb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rrbr
    {
        vec4 v2 = vec.rrbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrbg
    {
        vec4 v2 = vec.rrbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrbb
    {
        vec4 v2 = vec.rrbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rgrr
    {
        vec4 v2 = vec.rgrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rgrg
    {
        vec4 v2 = vec.rgrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rgrb
    {
        vec4 v2 = vec.rgrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rggr
    {
        vec4 v2 = vec.rggr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rggg
    {
        vec4 v2 = vec.rggg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rggb
    {
        vec4 v2 = vec.rggb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rgbr
    {
        vec4 v2 = vec.rgbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rgbg
    {
        vec4 v2 = vec.rgbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rgbb
    {
        vec4 v2 = vec.rgbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbrr
    {
        vec4 v2 = vec.rbrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbrg
    {
        vec4 v2 = vec.rbrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbrb
    {
        vec4 v2 = vec.rbrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbgr
    {
        vec4 v2 = vec.rbgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbgg
    {
        vec4 v2 = vec.rbgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbgb
    {
        vec4 v2 = vec.rbgb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbbr
    {
        vec4 v2 = vec.rbbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbbg
    {
        vec4 v2 = vec.rbbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbbb
    {
        vec4 v2 = vec.rbbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // grrr
    {
        vec4 v2 = vec.grrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grrg
    {
        vec4 v2 = vec.grrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grrb
    {
        vec4 v2 = vec.grrb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // grgr
    {
        vec4 v2 = vec.grgr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grgg
    {
        vec4 v2 = vec.grgg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grgb
    {
        vec4 v2 = vec.grgb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // grbr
    {
        vec4 v2 = vec.grbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grbg
    {
        vec4 v2 = vec.grbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grbb
    {
        vec4 v2 = vec.grbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ggrr
    {
        vec4 v2 = vec.ggrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ggrg
    {
        vec4 v2 = vec.ggrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ggrb
    {
        vec4 v2 = vec.ggrb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gggr
    {
        vec4 v2 = vec.gggr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gggg
    {
        vec4 v2 = vec.gggg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gggb
    {
        vec4 v2 = vec.gggb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ggbr
    {
        vec4 v2 = vec.ggbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ggbg
    {
        vec4 v2 = vec.ggbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ggbb
    {
        vec4 v2 = vec.ggbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbrr
    {
        vec4 v2 = vec.gbrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbrg
    {
        vec4 v2 = vec.gbrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbrb
    {
        vec4 v2 = vec.gbrb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbgr
    {
        vec4 v2 = vec.gbgr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbgg
    {
        vec4 v2 = vec.gbgg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbgb
    {
        vec4 v2 = vec.gbgb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbbr
    {
        vec4 v2 = vec.gbbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbbg
    {
        vec4 v2 = vec.gbbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbbb
    {
        vec4 v2 = vec.gbbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // brrr
    {
        vec4 v2 = vec.brrr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brrg
    {
        vec4 v2 = vec.brrg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brrb
    {
        vec4 v2 = vec.brrb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // brgr
    {
        vec4 v2 = vec.brgr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brgg
    {
        vec4 v2 = vec.brgg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brgb
    {
        vec4 v2 = vec.brgb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // brbr
    {
        vec4 v2 = vec.brbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brbg
    {
        vec4 v2 = vec.brbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brbb
    {
        vec4 v2 = vec.brbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bgrr
    {
        vec4 v2 = vec.bgrr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bgrg
    {
        vec4 v2 = vec.bgrg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bgrb
    {
        vec4 v2 = vec.bgrb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bggr
    {
        vec4 v2 = vec.bggr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bggg
    {
        vec4 v2 = vec.bggg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bggb
    {
        vec4 v2 = vec.bggb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bgbr
    {
        vec4 v2 = vec.bgbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bgbg
    {
        vec4 v2 = vec.bgbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bgbb
    {
        vec4 v2 = vec.bgbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbrr
    {
        vec4 v2 = vec.bbrr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbrg
    {
        vec4 v2 = vec.bbrg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbrb
    {
        vec4 v2 = vec.bbrb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbgr
    {
        vec4 v2 = vec.bbgr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbgg
    {
        vec4 v2 = vec.bbgg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbgb
    {
        vec4 v2 = vec.bbgb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbbr
    {
        vec4 v2 = vec.bbbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbbg
    {
        vec4 v2 = vec.bbbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbbb
    {
        vec4 v2 = vec.bbbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
}

TEST(GlslikeVector3, Swizzle4Stpq) {
    vec3 vec(1.0f, 2.0f, 3.0f);

    // ssss
    {
        vec4 v2 = vec.ssss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ssst
    {
        vec4 v2 = vec.ssst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sssp
    {
        vec4 v2 = vec.sssp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ssts
    {
        vec4 v2 = vec.ssts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sstt
    {
        vec4 v2 = vec.sstt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sstp
    {
        vec4 v2 = vec.sstp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ssps
    {
        vec4 v2 = vec.ssps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sspt
    {
        vec4 v2 = vec.sspt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sspp
    {
        vec4 v2 = vec.sspp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // stss
    {
        vec4 v2 = vec.stss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // stst
    {
        vec4 v2 = vec.stst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stsp
    {
        vec4 v2 = vec.stsp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // stts
    {
        vec4 v2 = vec.stts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sttt
    {
        vec4 v2 = vec.sttt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sttp
    {
        vec4 v2 = vec.sttp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // stps
    {
        vec4 v2 = vec.stps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // stpt
    {
        vec4 v2 = vec.stpt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stpp
    {
        vec4 v2 = vec.stpp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // spss
    {
        vec4 v2 = vec.spss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // spst
    {
        vec4 v2 = vec.spst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // spsp
    {
        vec4 v2 = vec.spsp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // spts
    {
        vec4 v2 = vec.spts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sptt
    {
        vec4 v2 = vec.sptt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sptp
    {
        vec4 v2 = vec.sptp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // spps
    {
        vec4 v2 = vec.spps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sppt
    {
        vec4 v2 = vec.sppt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sppp
    {
        vec4 v2 = vec.sppp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tsss
    {
        vec4 v2 = vec.tsss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tsst
    {
        vec4 v2 = vec.tsst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tssp
    {
        vec4 v2 = vec.tssp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tsts
    {
        vec4 v2 = vec.tsts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tstt
    {
        vec4 v2 = vec.tstt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tstp
    {
        vec4 v2 = vec.tstp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tsps
    {
        vec4 v2 = vec.tsps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tspt
    {
        vec4 v2 = vec.tspt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tspp
    {
        vec4 v2 = vec.tspp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ttss
    {
        vec4 v2 = vec.ttss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ttst
    {
        vec4 v2 = vec.ttst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttsp
    {
        vec4 v2 = vec.ttsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ttts
    {
        vec4 v2 = vec.ttts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tttt
    {
        vec4 v2 = vec.tttt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tttp
    {
        vec4 v2 = vec.tttp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ttps
    {
        vec4 v2 = vec.ttps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ttpt
    {
        vec4 v2 = vec.ttpt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttpp
    {
        vec4 v2 = vec.ttpp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tpss
    {
        vec4 v2 = vec.tpss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tpst
    {
        vec4 v2 = vec.tpst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tpsp
    {
        vec4 v2 = vec.tpsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tpts
    {
        vec4 v2 = vec.tpts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tptt
    {
        vec4 v2 = vec.tptt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tptp
    {
        vec4 v2 = vec.tptp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tpps
    {
        vec4 v2 = vec.tpps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tppt
    {
        vec4 v2 = vec.tppt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tppp
    {
        vec4 v2 = vec.tppp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // psss
    {
        vec4 v2 = vec.psss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // psst
    {
        vec4 v2 = vec.psst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pssp
    {
        vec4 v2 = vec.pssp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // psts
    {
        vec4 v2 = vec.psts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pstt
    {
        vec4 v2 = vec.pstt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pstp
    {
        vec4 v2 = vec.pstp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // psps
    {
        vec4 v2 = vec.psps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pspt
    {
        vec4 v2 = vec.pspt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pspp
    {
        vec4 v2 = vec.pspp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ptss
    {
        vec4 v2 = vec.ptss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ptst
    {
        vec4 v2 = vec.ptst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ptsp
    {
        vec4 v2 = vec.ptsp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ptts
    {
        vec4 v2 = vec.ptts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pttt
    {
        vec4 v2 = vec.pttt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pttp
    {
        vec4 v2 = vec.pttp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ptps
    {
        vec4 v2 = vec.ptps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ptpt
    {
        vec4 v2 = vec.ptpt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ptpp
    {
        vec4 v2 = vec.ptpp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ppss
    {
        vec4 v2 = vec.ppss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ppst
    {
        vec4 v2 = vec.ppst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ppsp
    {
        vec4 v2 = vec.ppsp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ppts
    {
        vec4 v2 = vec.ppts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pptt
    {
        vec4 v2 = vec.pptt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pptp
    {
        vec4 v2 = vec.pptp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ppps
    {
        vec4 v2 = vec.ppps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pppt
    {
        vec4 v2 = vec.pppt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pppp
    {
        vec4 v2 = vec.pppp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
}


TEST(GlslikeVector4, Attributes) {
    vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_EQ(v.x, 1.0f);
    EXPECT_EQ(v.y, 2.0f);
    EXPECT_EQ(v.z, 3.0f);
    EXPECT_EQ(v.w, 4.0f);
}

TEST(GlslikeVector4, AliasRgba) {
    vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_EQ(v.r, 1.0f);
    EXPECT_EQ(v.g, 2.0f);
    EXPECT_EQ(v.b, 3.0f);
    EXPECT_EQ(v.a, 4.0f);
}

TEST(GlslikeVector3, AliasStpq) {
    vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_EQ(v.s, 1.0f);
    EXPECT_EQ(v.t, 2.0f);
    EXPECT_EQ(v.p, 3.0f);
    EXPECT_EQ(v.q, 4.0f);
}

TEST(GlslikeVector4, Index) {
    vec4 v(1.0f, 2.0f, 3.0f, 4.0f);
    EXPECT_EQ(v[0], 1.0f);
    EXPECT_EQ(v[1], 2.0f);
    EXPECT_EQ(v[2], 3.0f);
    EXPECT_EQ(v[3], 4.0f);
}

TEST(GlslikeVector4, Swizzle2Xy) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // xx
    {
        vec2 v2 = vec.xx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // xy
    {
        vec2 v2 = vec.xy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // xz
    {
        vec2 v2 = vec.xz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // xw
    {
        vec2 v2 = vec.xw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // yx
    {
        vec2 v2 = vec.yx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // yy
    {
        vec2 v2 = vec.yy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // yz
    {
        vec2 v2 = vec.yz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // yw
    {
        vec2 v2 = vec.yw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // zx
    {
        vec2 v2 = vec.zx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // zy
    {
        vec2 v2 = vec.zy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // zz
    {
        vec2 v2 = vec.zz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // zw
    {
        vec2 v2 = vec.zw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // wx
    {
        vec2 v2 = vec.wx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // wy
    {
        vec2 v2 = vec.wy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // wz
    {
        vec2 v2 = vec.wz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // ww
    {
        vec2 v2 = vec.ww;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle2Rg) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // rr
    {
        vec2 v2 = vec.rr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // rg
    {
        vec2 v2 = vec.rg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // rb
    {
        vec2 v2 = vec.rb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // ra
    {
        vec2 v2 = vec.ra;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // gr
    {
        vec2 v2 = vec.gr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // gg
    {
        vec2 v2 = vec.gg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // gb
    {
        vec2 v2 = vec.gb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // ga
    {
        vec2 v2 = vec.ga;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // br
    {
        vec2 v2 = vec.br;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // bg
    {
        vec2 v2 = vec.bg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // bb
    {
        vec2 v2 = vec.bb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // ba
    {
        vec2 v2 = vec.ba;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // ar
    {
        vec2 v2 = vec.ar;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // ag
    {
        vec2 v2 = vec.ag;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // ab
    {
        vec2 v2 = vec.ab;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // aa
    {
        vec2 v2 = vec.aa;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle2St) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // ss
    {
        vec2 v2 = vec.ss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // st
    {
        vec2 v2 = vec.st;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // sp
    {
        vec2 v2 = vec.sp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // sq
    {
        vec2 v2 = vec.sq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // ts
    {
        vec2 v2 = vec.ts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // tt
    {
        vec2 v2 = vec.tt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // tp
    {
        vec2 v2 = vec.tp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // tq
    {
        vec2 v2 = vec.tq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // ps
    {
        vec2 v2 = vec.ps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // pt
    {
        vec2 v2 = vec.pt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // pp
    {
        vec2 v2 = vec.pp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // pq
    {
        vec2 v2 = vec.pq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
    // qs
    {
        vec2 v2 = vec.qs;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
    }
    // qt
    {
        vec2 v2 = vec.qt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
    }
    // qp
    {
        vec2 v2 = vec.qp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
    }
    // qq
    {
        vec2 v2 = vec.qq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle3Xyz) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // xxx
    {
        vec3 v2 = vec.xxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xxy
    {
        vec3 v2 = vec.xxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xxz
    {
        vec3 v2 = vec.xxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // xxw
    {
        vec3 v2 = vec.xxw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // xyx
    {
        vec3 v2 = vec.xyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xyy
    {
        vec3 v2 = vec.xyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xyz
    {
        vec3 v2 = vec.xyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // xyw
    {
        vec3 v2 = vec.xyw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // xzx
    {
        vec3 v2 = vec.xzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xzy
    {
        vec3 v2 = vec.xzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xzz
    {
        vec3 v2 = vec.xzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // xzw
    {
        vec3 v2 = vec.xzw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // xwx
    {
        vec3 v2 = vec.xwx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // xwy
    {
        vec3 v2 = vec.xwy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // xwz
    {
        vec3 v2 = vec.xwz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // xww
    {
        vec3 v2 = vec.xww;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // yxx
    {
        vec3 v2 = vec.yxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yxy
    {
        vec3 v2 = vec.yxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yxz
    {
        vec3 v2 = vec.yxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yxw
    {
        vec3 v2 = vec.yxw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // yyx
    {
        vec3 v2 = vec.yyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yyy
    {
        vec3 v2 = vec.yyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yyz
    {
        vec3 v2 = vec.yyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yyw
    {
        vec3 v2 = vec.yyw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // yzx
    {
        vec3 v2 = vec.yzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // yzy
    {
        vec3 v2 = vec.yzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // yzz
    {
        vec3 v2 = vec.yzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yzw
    {
        vec3 v2 = vec.yzw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // ywx
    {
        vec3 v2 = vec.ywx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ywy
    {
        vec3 v2 = vec.ywy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ywz
    {
        vec3 v2 = vec.ywz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // yww
    {
        vec3 v2 = vec.yww;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // zxx
    {
        vec3 v2 = vec.zxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zxy
    {
        vec3 v2 = vec.zxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zxz
    {
        vec3 v2 = vec.zxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zxw
    {
        vec3 v2 = vec.zxw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // zyx
    {
        vec3 v2 = vec.zyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zyy
    {
        vec3 v2 = vec.zyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zyz
    {
        vec3 v2 = vec.zyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zyw
    {
        vec3 v2 = vec.zyw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // zzx
    {
        vec3 v2 = vec.zzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zzy
    {
        vec3 v2 = vec.zzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zzz
    {
        vec3 v2 = vec.zzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zzw
    {
        vec3 v2 = vec.zzw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // zwx
    {
        vec3 v2 = vec.zwx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // zwy
    {
        vec3 v2 = vec.zwy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // zwz
    {
        vec3 v2 = vec.zwz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // zww
    {
        vec3 v2 = vec.zww;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // wxx
    {
        vec3 v2 = vec.wxx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // wxy
    {
        vec3 v2 = vec.wxy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // wxz
    {
        vec3 v2 = vec.wxz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // wxw
    {
        vec3 v2 = vec.wxw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // wyx
    {
        vec3 v2 = vec.wyx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // wyy
    {
        vec3 v2 = vec.wyy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // wyz
    {
        vec3 v2 = vec.wyz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // wyw
    {
        vec3 v2 = vec.wyw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // wzx
    {
        vec3 v2 = vec.wzx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // wzy
    {
        vec3 v2 = vec.wzy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // wzz
    {
        vec3 v2 = vec.wzz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // wzw
    {
        vec3 v2 = vec.wzw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // wwx
    {
        vec3 v2 = vec.wwx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // wwy
    {
        vec3 v2 = vec.wwy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // wwz
    {
        vec3 v2 = vec.wwz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // www
    {
        vec3 v2 = vec.www;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle3Rgb) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // rrr
    {
        vec3 v2 = vec.rrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rrg
    {
        vec3 v2 = vec.rrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rrb
    {
        vec3 v2 = vec.rrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // rra
    {
        vec3 v2 = vec.rra;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // rgr
    {
        vec3 v2 = vec.rgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rgg
    {
        vec3 v2 = vec.rgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rgb
    {
        vec3 v2 = vec.rgb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // rga
    {
        vec3 v2 = vec.rga;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // rbr
    {
        vec3 v2 = vec.rbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rbg
    {
        vec3 v2 = vec.rbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rbb
    {
        vec3 v2 = vec.rbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // rba
    {
        vec3 v2 = vec.rba;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // rar
    {
        vec3 v2 = vec.rar;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // rag
    {
        vec3 v2 = vec.rag;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // rab
    {
        vec3 v2 = vec.rab;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // raa
    {
        vec3 v2 = vec.raa;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // grr
    {
        vec3 v2 = vec.grr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // grg
    {
        vec3 v2 = vec.grg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // grb
    {
        vec3 v2 = vec.grb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // gra
    {
        vec3 v2 = vec.gra;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // ggr
    {
        vec3 v2 = vec.ggr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ggg
    {
        vec3 v2 = vec.ggg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ggb
    {
        vec3 v2 = vec.ggb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // gga
    {
        vec3 v2 = vec.gga;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // gbr
    {
        vec3 v2 = vec.gbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // gbg
    {
        vec3 v2 = vec.gbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // gbb
    {
        vec3 v2 = vec.gbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // gba
    {
        vec3 v2 = vec.gba;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // gar
    {
        vec3 v2 = vec.gar;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // gag
    {
        vec3 v2 = vec.gag;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // gab
    {
        vec3 v2 = vec.gab;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // gaa
    {
        vec3 v2 = vec.gaa;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // brr
    {
        vec3 v2 = vec.brr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // brg
    {
        vec3 v2 = vec.brg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // brb
    {
        vec3 v2 = vec.brb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // bra
    {
        vec3 v2 = vec.bra;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // bgr
    {
        vec3 v2 = vec.bgr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // bgg
    {
        vec3 v2 = vec.bgg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // bgb
    {
        vec3 v2 = vec.bgb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // bga
    {
        vec3 v2 = vec.bga;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // bbr
    {
        vec3 v2 = vec.bbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // bbg
    {
        vec3 v2 = vec.bbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // bbb
    {
        vec3 v2 = vec.bbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // bba
    {
        vec3 v2 = vec.bba;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // bar
    {
        vec3 v2 = vec.bar;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // bag
    {
        vec3 v2 = vec.bag;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // bab
    {
        vec3 v2 = vec.bab;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // baa
    {
        vec3 v2 = vec.baa;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // arr
    {
        vec3 v2 = vec.arr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // arg
    {
        vec3 v2 = vec.arg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // arb
    {
        vec3 v2 = vec.arb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // ara
    {
        vec3 v2 = vec.ara;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // agr
    {
        vec3 v2 = vec.agr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // agg
    {
        vec3 v2 = vec.agg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // agb
    {
        vec3 v2 = vec.agb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // aga
    {
        vec3 v2 = vec.aga;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // abr
    {
        vec3 v2 = vec.abr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // abg
    {
        vec3 v2 = vec.abg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // abb
    {
        vec3 v2 = vec.abb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // aba
    {
        vec3 v2 = vec.aba;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // aar
    {
        vec3 v2 = vec.aar;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // aag
    {
        vec3 v2 = vec.aag;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // aab
    {
        vec3 v2 = vec.aab;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // aaa
    {
        vec3 v2 = vec.aaa;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle3Stp) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // sss
    {
        vec3 v2 = vec.sss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // sst
    {
        vec3 v2 = vec.sst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ssp
    {
        vec3 v2 = vec.ssp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // ssq
    {
        vec3 v2 = vec.ssq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // sts
    {
        vec3 v2 = vec.sts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // stt
    {
        vec3 v2 = vec.stt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // stp
    {
        vec3 v2 = vec.stp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // stq
    {
        vec3 v2 = vec.stq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // sps
    {
        vec3 v2 = vec.sps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // spt
    {
        vec3 v2 = vec.spt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // spp
    {
        vec3 v2 = vec.spp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // spq
    {
        vec3 v2 = vec.spq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // sqs
    {
        vec3 v2 = vec.sqs;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // sqt
    {
        vec3 v2 = vec.sqt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // sqp
    {
        vec3 v2 = vec.sqp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // sqq
    {
        vec3 v2 = vec.sqq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // tss
    {
        vec3 v2 = vec.tss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // tst
    {
        vec3 v2 = vec.tst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tsp
    {
        vec3 v2 = vec.tsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // tsq
    {
        vec3 v2 = vec.tsq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // tts
    {
        vec3 v2 = vec.tts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ttt
    {
        vec3 v2 = vec.ttt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ttp
    {
        vec3 v2 = vec.ttp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // ttq
    {
        vec3 v2 = vec.ttq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // tps
    {
        vec3 v2 = vec.tps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // tpt
    {
        vec3 v2 = vec.tpt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tpp
    {
        vec3 v2 = vec.tpp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // tpq
    {
        vec3 v2 = vec.tpq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // tqs
    {
        vec3 v2 = vec.tqs;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // tqt
    {
        vec3 v2 = vec.tqt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // tqp
    {
        vec3 v2 = vec.tqp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // tqq
    {
        vec3 v2 = vec.tqq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // pss
    {
        vec3 v2 = vec.pss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // pst
    {
        vec3 v2 = vec.pst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // psp
    {
        vec3 v2 = vec.psp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // psq
    {
        vec3 v2 = vec.psq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // pts
    {
        vec3 v2 = vec.pts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ptt
    {
        vec3 v2 = vec.ptt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ptp
    {
        vec3 v2 = vec.ptp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // ptq
    {
        vec3 v2 = vec.ptq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // pps
    {
        vec3 v2 = vec.pps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // ppt
    {
        vec3 v2 = vec.ppt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // ppp
    {
        vec3 v2 = vec.ppp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // ppq
    {
        vec3 v2 = vec.ppq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // pqs
    {
        vec3 v2 = vec.pqs;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // pqt
    {
        vec3 v2 = vec.pqt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // pqp
    {
        vec3 v2 = vec.pqp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // pqq
    {
        vec3 v2 = vec.pqq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // qss
    {
        vec3 v2 = vec.qss;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // qst
    {
        vec3 v2 = vec.qst;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // qsp
    {
        vec3 v2 = vec.qsp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // qsq
    {
        vec3 v2 = vec.qsq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // qts
    {
        vec3 v2 = vec.qts;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // qtt
    {
        vec3 v2 = vec.qtt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // qtp
    {
        vec3 v2 = vec.qtp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // qtq
    {
        vec3 v2 = vec.qtq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // qps
    {
        vec3 v2 = vec.qps;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // qpt
    {
        vec3 v2 = vec.qpt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // qpp
    {
        vec3 v2 = vec.qpp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // qpq
    {
        vec3 v2 = vec.qpq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
    // qqs
    {
        vec3 v2 = vec.qqs;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
    }
    // qqt
    {
        vec3 v2 = vec.qqt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
    }
    // qqp
    {
        vec3 v2 = vec.qqp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
    }
    // qqq
    {
        vec3 v2 = vec.qqq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle4Xyzw) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // xxxx
    {
        vec4 v2 = vec.xxxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxxy
    {
        vec4 v2 = vec.xxxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxxz
    {
        vec4 v2 = vec.xxxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xxxw
    {
        vec4 v2 = vec.xxxw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xxyx
    {
        vec4 v2 = vec.xxyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxyy
    {
        vec4 v2 = vec.xxyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxyz
    {
        vec4 v2 = vec.xxyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xxyw
    {
        vec4 v2 = vec.xxyw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xxzx
    {
        vec4 v2 = vec.xxzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxzy
    {
        vec4 v2 = vec.xxzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxzz
    {
        vec4 v2 = vec.xxzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xxzw
    {
        vec4 v2 = vec.xxzw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xxwx
    {
        vec4 v2 = vec.xxwx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xxwy
    {
        vec4 v2 = vec.xxwy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xxwz
    {
        vec4 v2 = vec.xxwz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xxww
    {
        vec4 v2 = vec.xxww;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xyxx
    {
        vec4 v2 = vec.xyxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyxy
    {
        vec4 v2 = vec.xyxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyxz
    {
        vec4 v2 = vec.xyxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyxw
    {
        vec4 v2 = vec.xyxw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xyyx
    {
        vec4 v2 = vec.xyyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyyy
    {
        vec4 v2 = vec.xyyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyyz
    {
        vec4 v2 = vec.xyyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyyw
    {
        vec4 v2 = vec.xyyw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xyzx
    {
        vec4 v2 = vec.xyzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xyzy
    {
        vec4 v2 = vec.xyzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xyzz
    {
        vec4 v2 = vec.xyzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyzw
    {
        vec4 v2 = vec.xyzw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xywx
    {
        vec4 v2 = vec.xywx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xywy
    {
        vec4 v2 = vec.xywy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xywz
    {
        vec4 v2 = vec.xywz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xyww
    {
        vec4 v2 = vec.xyww;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xzxx
    {
        vec4 v2 = vec.xzxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzxy
    {
        vec4 v2 = vec.xzxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzxz
    {
        vec4 v2 = vec.xzxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzxw
    {
        vec4 v2 = vec.xzxw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xzyx
    {
        vec4 v2 = vec.xzyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzyy
    {
        vec4 v2 = vec.xzyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzyz
    {
        vec4 v2 = vec.xzyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzyw
    {
        vec4 v2 = vec.xzyw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xzzx
    {
        vec4 v2 = vec.xzzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzzy
    {
        vec4 v2 = vec.xzzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzzz
    {
        vec4 v2 = vec.xzzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzzw
    {
        vec4 v2 = vec.xzzw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xzwx
    {
        vec4 v2 = vec.xzwx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xzwy
    {
        vec4 v2 = vec.xzwy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xzwz
    {
        vec4 v2 = vec.xzwz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xzww
    {
        vec4 v2 = vec.xzww;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xwxx
    {
        vec4 v2 = vec.xwxx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xwxy
    {
        vec4 v2 = vec.xwxy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xwxz
    {
        vec4 v2 = vec.xwxz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xwxw
    {
        vec4 v2 = vec.xwxw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xwyx
    {
        vec4 v2 = vec.xwyx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xwyy
    {
        vec4 v2 = vec.xwyy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xwyz
    {
        vec4 v2 = vec.xwyz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xwyw
    {
        vec4 v2 = vec.xwyw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xwzx
    {
        vec4 v2 = vec.xwzx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xwzy
    {
        vec4 v2 = vec.xwzy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xwzz
    {
        vec4 v2 = vec.xwzz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xwzw
    {
        vec4 v2 = vec.xwzw;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // xwwx
    {
        vec4 v2 = vec.xwwx;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // xwwy
    {
        vec4 v2 = vec.xwwy;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // xwwz
    {
        vec4 v2 = vec.xwwz;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // xwww
    {
        vec4 v2 = vec.xwww;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yxxx
    {
        vec4 v2 = vec.yxxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxxy
    {
        vec4 v2 = vec.yxxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxxz
    {
        vec4 v2 = vec.yxxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxxw
    {
        vec4 v2 = vec.yxxw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yxyx
    {
        vec4 v2 = vec.yxyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxyy
    {
        vec4 v2 = vec.yxyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxyz
    {
        vec4 v2 = vec.yxyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxyw
    {
        vec4 v2 = vec.yxyw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yxzx
    {
        vec4 v2 = vec.yxzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxzy
    {
        vec4 v2 = vec.yxzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxzz
    {
        vec4 v2 = vec.yxzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxzw
    {
        vec4 v2 = vec.yxzw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yxwx
    {
        vec4 v2 = vec.yxwx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yxwy
    {
        vec4 v2 = vec.yxwy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yxwz
    {
        vec4 v2 = vec.yxwz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yxww
    {
        vec4 v2 = vec.yxww;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yyxx
    {
        vec4 v2 = vec.yyxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyxy
    {
        vec4 v2 = vec.yyxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyxz
    {
        vec4 v2 = vec.yyxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyxw
    {
        vec4 v2 = vec.yyxw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yyyx
    {
        vec4 v2 = vec.yyyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyyy
    {
        vec4 v2 = vec.yyyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyyz
    {
        vec4 v2 = vec.yyyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyyw
    {
        vec4 v2 = vec.yyyw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yyzx
    {
        vec4 v2 = vec.yyzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yyzy
    {
        vec4 v2 = vec.yyzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yyzz
    {
        vec4 v2 = vec.yyzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyzw
    {
        vec4 v2 = vec.yyzw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yywx
    {
        vec4 v2 = vec.yywx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yywy
    {
        vec4 v2 = vec.yywy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yywz
    {
        vec4 v2 = vec.yywz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yyww
    {
        vec4 v2 = vec.yyww;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yzxx
    {
        vec4 v2 = vec.yzxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzxy
    {
        vec4 v2 = vec.yzxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzxz
    {
        vec4 v2 = vec.yzxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzxw
    {
        vec4 v2 = vec.yzxw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yzyx
    {
        vec4 v2 = vec.yzyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzyy
    {
        vec4 v2 = vec.yzyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzyz
    {
        vec4 v2 = vec.yzyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzyw
    {
        vec4 v2 = vec.yzyw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yzzx
    {
        vec4 v2 = vec.yzzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzzy
    {
        vec4 v2 = vec.yzzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzzz
    {
        vec4 v2 = vec.yzzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzzw
    {
        vec4 v2 = vec.yzzw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // yzwx
    {
        vec4 v2 = vec.yzwx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // yzwy
    {
        vec4 v2 = vec.yzwy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // yzwz
    {
        vec4 v2 = vec.yzwz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // yzww
    {
        vec4 v2 = vec.yzww;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ywxx
    {
        vec4 v2 = vec.ywxx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ywxy
    {
        vec4 v2 = vec.ywxy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ywxz
    {
        vec4 v2 = vec.ywxz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ywxw
    {
        vec4 v2 = vec.ywxw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ywyx
    {
        vec4 v2 = vec.ywyx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ywyy
    {
        vec4 v2 = vec.ywyy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ywyz
    {
        vec4 v2 = vec.ywyz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ywyw
    {
        vec4 v2 = vec.ywyw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ywzx
    {
        vec4 v2 = vec.ywzx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ywzy
    {
        vec4 v2 = vec.ywzy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ywzz
    {
        vec4 v2 = vec.ywzz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ywzw
    {
        vec4 v2 = vec.ywzw;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ywwx
    {
        vec4 v2 = vec.ywwx;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ywwy
    {
        vec4 v2 = vec.ywwy;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ywwz
    {
        vec4 v2 = vec.ywwz;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ywww
    {
        vec4 v2 = vec.ywww;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zxxx
    {
        vec4 v2 = vec.zxxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxxy
    {
        vec4 v2 = vec.zxxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxxz
    {
        vec4 v2 = vec.zxxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxxw
    {
        vec4 v2 = vec.zxxw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zxyx
    {
        vec4 v2 = vec.zxyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxyy
    {
        vec4 v2 = vec.zxyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxyz
    {
        vec4 v2 = vec.zxyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxyw
    {
        vec4 v2 = vec.zxyw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zxzx
    {
        vec4 v2 = vec.zxzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxzy
    {
        vec4 v2 = vec.zxzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxzz
    {
        vec4 v2 = vec.zxzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxzw
    {
        vec4 v2 = vec.zxzw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zxwx
    {
        vec4 v2 = vec.zxwx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zxwy
    {
        vec4 v2 = vec.zxwy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zxwz
    {
        vec4 v2 = vec.zxwz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zxww
    {
        vec4 v2 = vec.zxww;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zyxx
    {
        vec4 v2 = vec.zyxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zyxy
    {
        vec4 v2 = vec.zyxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zyxz
    {
        vec4 v2 = vec.zyxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyxw
    {
        vec4 v2 = vec.zyxw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zyyx
    {
        vec4 v2 = vec.zyyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zyyy
    {
        vec4 v2 = vec.zyyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zyyz
    {
        vec4 v2 = vec.zyyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyyw
    {
        vec4 v2 = vec.zyyw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zyzx
    {
        vec4 v2 = vec.zyzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zyzy
    {
        vec4 v2 = vec.zyzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zyzz
    {
        vec4 v2 = vec.zyzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyzw
    {
        vec4 v2 = vec.zyzw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zywx
    {
        vec4 v2 = vec.zywx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zywy
    {
        vec4 v2 = vec.zywy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zywz
    {
        vec4 v2 = vec.zywz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zyww
    {
        vec4 v2 = vec.zyww;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zzxx
    {
        vec4 v2 = vec.zzxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzxy
    {
        vec4 v2 = vec.zzxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzxz
    {
        vec4 v2 = vec.zzxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzxw
    {
        vec4 v2 = vec.zzxw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zzyx
    {
        vec4 v2 = vec.zzyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzyy
    {
        vec4 v2 = vec.zzyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzyz
    {
        vec4 v2 = vec.zzyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzyw
    {
        vec4 v2 = vec.zzyw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zzzx
    {
        vec4 v2 = vec.zzzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzzy
    {
        vec4 v2 = vec.zzzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzzz
    {
        vec4 v2 = vec.zzzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzzw
    {
        vec4 v2 = vec.zzzw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zzwx
    {
        vec4 v2 = vec.zzwx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zzwy
    {
        vec4 v2 = vec.zzwy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zzwz
    {
        vec4 v2 = vec.zzwz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zzww
    {
        vec4 v2 = vec.zzww;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zwxx
    {
        vec4 v2 = vec.zwxx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zwxy
    {
        vec4 v2 = vec.zwxy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zwxz
    {
        vec4 v2 = vec.zwxz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zwxw
    {
        vec4 v2 = vec.zwxw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zwyx
    {
        vec4 v2 = vec.zwyx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zwyy
    {
        vec4 v2 = vec.zwyy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zwyz
    {
        vec4 v2 = vec.zwyz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zwyw
    {
        vec4 v2 = vec.zwyw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zwzx
    {
        vec4 v2 = vec.zwzx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zwzy
    {
        vec4 v2 = vec.zwzy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zwzz
    {
        vec4 v2 = vec.zwzz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zwzw
    {
        vec4 v2 = vec.zwzw;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // zwwx
    {
        vec4 v2 = vec.zwwx;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // zwwy
    {
        vec4 v2 = vec.zwwy;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // zwwz
    {
        vec4 v2 = vec.zwwz;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // zwww
    {
        vec4 v2 = vec.zwww;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wxxx
    {
        vec4 v2 = vec.wxxx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wxxy
    {
        vec4 v2 = vec.wxxy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wxxz
    {
        vec4 v2 = vec.wxxz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wxxw
    {
        vec4 v2 = vec.wxxw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wxyx
    {
        vec4 v2 = vec.wxyx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wxyy
    {
        vec4 v2 = vec.wxyy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wxyz
    {
        vec4 v2 = vec.wxyz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wxyw
    {
        vec4 v2 = vec.wxyw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wxzx
    {
        vec4 v2 = vec.wxzx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wxzy
    {
        vec4 v2 = vec.wxzy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wxzz
    {
        vec4 v2 = vec.wxzz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wxzw
    {
        vec4 v2 = vec.wxzw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wxwx
    {
        vec4 v2 = vec.wxwx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wxwy
    {
        vec4 v2 = vec.wxwy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wxwz
    {
        vec4 v2 = vec.wxwz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wxww
    {
        vec4 v2 = vec.wxww;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wyxx
    {
        vec4 v2 = vec.wyxx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wyxy
    {
        vec4 v2 = vec.wyxy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wyxz
    {
        vec4 v2 = vec.wyxz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wyxw
    {
        vec4 v2 = vec.wyxw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wyyx
    {
        vec4 v2 = vec.wyyx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wyyy
    {
        vec4 v2 = vec.wyyy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wyyz
    {
        vec4 v2 = vec.wyyz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wyyw
    {
        vec4 v2 = vec.wyyw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wyzx
    {
        vec4 v2 = vec.wyzx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wyzy
    {
        vec4 v2 = vec.wyzy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wyzz
    {
        vec4 v2 = vec.wyzz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wyzw
    {
        vec4 v2 = vec.wyzw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wywx
    {
        vec4 v2 = vec.wywx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wywy
    {
        vec4 v2 = vec.wywy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wywz
    {
        vec4 v2 = vec.wywz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wyww
    {
        vec4 v2 = vec.wyww;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wzxx
    {
        vec4 v2 = vec.wzxx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wzxy
    {
        vec4 v2 = vec.wzxy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wzxz
    {
        vec4 v2 = vec.wzxz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wzxw
    {
        vec4 v2 = vec.wzxw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wzyx
    {
        vec4 v2 = vec.wzyx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wzyy
    {
        vec4 v2 = vec.wzyy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wzyz
    {
        vec4 v2 = vec.wzyz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wzyw
    {
        vec4 v2 = vec.wzyw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wzzx
    {
        vec4 v2 = vec.wzzx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wzzy
    {
        vec4 v2 = vec.wzzy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wzzz
    {
        vec4 v2 = vec.wzzz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wzzw
    {
        vec4 v2 = vec.wzzw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wzwx
    {
        vec4 v2 = vec.wzwx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wzwy
    {
        vec4 v2 = vec.wzwy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wzwz
    {
        vec4 v2 = vec.wzwz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wzww
    {
        vec4 v2 = vec.wzww;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wwxx
    {
        vec4 v2 = vec.wwxx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wwxy
    {
        vec4 v2 = vec.wwxy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wwxz
    {
        vec4 v2 = vec.wwxz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wwxw
    {
        vec4 v2 = vec.wwxw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wwyx
    {
        vec4 v2 = vec.wwyx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wwyy
    {
        vec4 v2 = vec.wwyy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wwyz
    {
        vec4 v2 = vec.wwyz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wwyw
    {
        vec4 v2 = vec.wwyw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wwzx
    {
        vec4 v2 = vec.wwzx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wwzy
    {
        vec4 v2 = vec.wwzy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wwzz
    {
        vec4 v2 = vec.wwzz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wwzw
    {
        vec4 v2 = vec.wwzw;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // wwwx
    {
        vec4 v2 = vec.wwwx;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // wwwy
    {
        vec4 v2 = vec.wwwy;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // wwwz
    {
        vec4 v2 = vec.wwwz;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // wwww
    {
        vec4 v2 = vec.wwww;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle4Rgba) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // rrrr
    {
        vec4 v2 = vec.rrrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrrg
    {
        vec4 v2 = vec.rrrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrrb
    {
        vec4 v2 = vec.rrrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rrra
    {
        vec4 v2 = vec.rrra;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rrgr
    {
        vec4 v2 = vec.rrgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrgg
    {
        vec4 v2 = vec.rrgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrgb
    {
        vec4 v2 = vec.rrgb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rrga
    {
        vec4 v2 = vec.rrga;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rrbr
    {
        vec4 v2 = vec.rrbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrbg
    {
        vec4 v2 = vec.rrbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrbb
    {
        vec4 v2 = vec.rrbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rrba
    {
        vec4 v2 = vec.rrba;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rrar
    {
        vec4 v2 = vec.rrar;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rrag
    {
        vec4 v2 = vec.rrag;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rrab
    {
        vec4 v2 = vec.rrab;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rraa
    {
        vec4 v2 = vec.rraa;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rgrr
    {
        vec4 v2 = vec.rgrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rgrg
    {
        vec4 v2 = vec.rgrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rgrb
    {
        vec4 v2 = vec.rgrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rgra
    {
        vec4 v2 = vec.rgra;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rggr
    {
        vec4 v2 = vec.rggr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rggg
    {
        vec4 v2 = vec.rggg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rggb
    {
        vec4 v2 = vec.rggb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rgga
    {
        vec4 v2 = vec.rgga;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rgbr
    {
        vec4 v2 = vec.rgbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rgbg
    {
        vec4 v2 = vec.rgbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rgbb
    {
        vec4 v2 = vec.rgbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rgba
    {
        vec4 v2 = vec.rgba;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rgar
    {
        vec4 v2 = vec.rgar;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rgag
    {
        vec4 v2 = vec.rgag;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rgab
    {
        vec4 v2 = vec.rgab;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rgaa
    {
        vec4 v2 = vec.rgaa;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rbrr
    {
        vec4 v2 = vec.rbrr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbrg
    {
        vec4 v2 = vec.rbrg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbrb
    {
        vec4 v2 = vec.rbrb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbra
    {
        vec4 v2 = vec.rbra;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rbgr
    {
        vec4 v2 = vec.rbgr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbgg
    {
        vec4 v2 = vec.rbgg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbgb
    {
        vec4 v2 = vec.rbgb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbga
    {
        vec4 v2 = vec.rbga;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rbbr
    {
        vec4 v2 = vec.rbbr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbbg
    {
        vec4 v2 = vec.rbbg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbbb
    {
        vec4 v2 = vec.rbbb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbba
    {
        vec4 v2 = vec.rbba;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rbar
    {
        vec4 v2 = vec.rbar;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rbag
    {
        vec4 v2 = vec.rbag;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rbab
    {
        vec4 v2 = vec.rbab;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rbaa
    {
        vec4 v2 = vec.rbaa;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rarr
    {
        vec4 v2 = vec.rarr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rarg
    {
        vec4 v2 = vec.rarg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rarb
    {
        vec4 v2 = vec.rarb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // rara
    {
        vec4 v2 = vec.rara;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ragr
    {
        vec4 v2 = vec.ragr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ragg
    {
        vec4 v2 = vec.ragg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ragb
    {
        vec4 v2 = vec.ragb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // raga
    {
        vec4 v2 = vec.raga;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // rabr
    {
        vec4 v2 = vec.rabr;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // rabg
    {
        vec4 v2 = vec.rabg;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // rabb
    {
        vec4 v2 = vec.rabb;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // raba
    {
        vec4 v2 = vec.raba;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // raar
    {
        vec4 v2 = vec.raar;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // raag
    {
        vec4 v2 = vec.raag;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // raab
    {
        vec4 v2 = vec.raab;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // raaa
    {
        vec4 v2 = vec.raaa;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // grrr
    {
        vec4 v2 = vec.grrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grrg
    {
        vec4 v2 = vec.grrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grrb
    {
        vec4 v2 = vec.grrb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // grra
    {
        vec4 v2 = vec.grra;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // grgr
    {
        vec4 v2 = vec.grgr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grgg
    {
        vec4 v2 = vec.grgg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grgb
    {
        vec4 v2 = vec.grgb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // grga
    {
        vec4 v2 = vec.grga;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // grbr
    {
        vec4 v2 = vec.grbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grbg
    {
        vec4 v2 = vec.grbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grbb
    {
        vec4 v2 = vec.grbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // grba
    {
        vec4 v2 = vec.grba;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // grar
    {
        vec4 v2 = vec.grar;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // grag
    {
        vec4 v2 = vec.grag;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // grab
    {
        vec4 v2 = vec.grab;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // graa
    {
        vec4 v2 = vec.graa;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ggrr
    {
        vec4 v2 = vec.ggrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ggrg
    {
        vec4 v2 = vec.ggrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ggrb
    {
        vec4 v2 = vec.ggrb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ggra
    {
        vec4 v2 = vec.ggra;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gggr
    {
        vec4 v2 = vec.gggr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gggg
    {
        vec4 v2 = vec.gggg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gggb
    {
        vec4 v2 = vec.gggb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ggga
    {
        vec4 v2 = vec.ggga;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ggbr
    {
        vec4 v2 = vec.ggbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ggbg
    {
        vec4 v2 = vec.ggbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ggbb
    {
        vec4 v2 = vec.ggbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ggba
    {
        vec4 v2 = vec.ggba;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ggar
    {
        vec4 v2 = vec.ggar;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ggag
    {
        vec4 v2 = vec.ggag;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ggab
    {
        vec4 v2 = vec.ggab;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ggaa
    {
        vec4 v2 = vec.ggaa;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gbrr
    {
        vec4 v2 = vec.gbrr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbrg
    {
        vec4 v2 = vec.gbrg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbrb
    {
        vec4 v2 = vec.gbrb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbra
    {
        vec4 v2 = vec.gbra;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gbgr
    {
        vec4 v2 = vec.gbgr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbgg
    {
        vec4 v2 = vec.gbgg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbgb
    {
        vec4 v2 = vec.gbgb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbga
    {
        vec4 v2 = vec.gbga;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gbbr
    {
        vec4 v2 = vec.gbbr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbbg
    {
        vec4 v2 = vec.gbbg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbbb
    {
        vec4 v2 = vec.gbbb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbba
    {
        vec4 v2 = vec.gbba;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gbar
    {
        vec4 v2 = vec.gbar;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gbag
    {
        vec4 v2 = vec.gbag;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gbab
    {
        vec4 v2 = vec.gbab;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gbaa
    {
        vec4 v2 = vec.gbaa;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // garr
    {
        vec4 v2 = vec.garr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // garg
    {
        vec4 v2 = vec.garg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // garb
    {
        vec4 v2 = vec.garb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gara
    {
        vec4 v2 = vec.gara;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gagr
    {
        vec4 v2 = vec.gagr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gagg
    {
        vec4 v2 = vec.gagg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gagb
    {
        vec4 v2 = vec.gagb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gaga
    {
        vec4 v2 = vec.gaga;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gabr
    {
        vec4 v2 = vec.gabr;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gabg
    {
        vec4 v2 = vec.gabg;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gabb
    {
        vec4 v2 = vec.gabb;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gaba
    {
        vec4 v2 = vec.gaba;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // gaar
    {
        vec4 v2 = vec.gaar;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // gaag
    {
        vec4 v2 = vec.gaag;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // gaab
    {
        vec4 v2 = vec.gaab;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // gaaa
    {
        vec4 v2 = vec.gaaa;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // brrr
    {
        vec4 v2 = vec.brrr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brrg
    {
        vec4 v2 = vec.brrg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brrb
    {
        vec4 v2 = vec.brrb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // brra
    {
        vec4 v2 = vec.brra;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // brgr
    {
        vec4 v2 = vec.brgr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brgg
    {
        vec4 v2 = vec.brgg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brgb
    {
        vec4 v2 = vec.brgb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // brga
    {
        vec4 v2 = vec.brga;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // brbr
    {
        vec4 v2 = vec.brbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brbg
    {
        vec4 v2 = vec.brbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brbb
    {
        vec4 v2 = vec.brbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // brba
    {
        vec4 v2 = vec.brba;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // brar
    {
        vec4 v2 = vec.brar;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // brag
    {
        vec4 v2 = vec.brag;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // brab
    {
        vec4 v2 = vec.brab;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // braa
    {
        vec4 v2 = vec.braa;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bgrr
    {
        vec4 v2 = vec.bgrr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bgrg
    {
        vec4 v2 = vec.bgrg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bgrb
    {
        vec4 v2 = vec.bgrb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bgra
    {
        vec4 v2 = vec.bgra;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bggr
    {
        vec4 v2 = vec.bggr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bggg
    {
        vec4 v2 = vec.bggg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bggb
    {
        vec4 v2 = vec.bggb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bgga
    {
        vec4 v2 = vec.bgga;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bgbr
    {
        vec4 v2 = vec.bgbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bgbg
    {
        vec4 v2 = vec.bgbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bgbb
    {
        vec4 v2 = vec.bgbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bgba
    {
        vec4 v2 = vec.bgba;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bgar
    {
        vec4 v2 = vec.bgar;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bgag
    {
        vec4 v2 = vec.bgag;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bgab
    {
        vec4 v2 = vec.bgab;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bgaa
    {
        vec4 v2 = vec.bgaa;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bbrr
    {
        vec4 v2 = vec.bbrr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbrg
    {
        vec4 v2 = vec.bbrg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbrb
    {
        vec4 v2 = vec.bbrb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbra
    {
        vec4 v2 = vec.bbra;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bbgr
    {
        vec4 v2 = vec.bbgr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbgg
    {
        vec4 v2 = vec.bbgg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbgb
    {
        vec4 v2 = vec.bbgb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbga
    {
        vec4 v2 = vec.bbga;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bbbr
    {
        vec4 v2 = vec.bbbr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbbg
    {
        vec4 v2 = vec.bbbg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbbb
    {
        vec4 v2 = vec.bbbb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbba
    {
        vec4 v2 = vec.bbba;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bbar
    {
        vec4 v2 = vec.bbar;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bbag
    {
        vec4 v2 = vec.bbag;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bbab
    {
        vec4 v2 = vec.bbab;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bbaa
    {
        vec4 v2 = vec.bbaa;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // barr
    {
        vec4 v2 = vec.barr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // barg
    {
        vec4 v2 = vec.barg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // barb
    {
        vec4 v2 = vec.barb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // bara
    {
        vec4 v2 = vec.bara;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // bagr
    {
        vec4 v2 = vec.bagr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // bagg
    {
        vec4 v2 = vec.bagg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // bagb
    {
        vec4 v2 = vec.bagb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // baga
    {
        vec4 v2 = vec.baga;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // babr
    {
        vec4 v2 = vec.babr;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // babg
    {
        vec4 v2 = vec.babg;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // babb
    {
        vec4 v2 = vec.babb;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // baba
    {
        vec4 v2 = vec.baba;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // baar
    {
        vec4 v2 = vec.baar;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // baag
    {
        vec4 v2 = vec.baag;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // baab
    {
        vec4 v2 = vec.baab;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // baaa
    {
        vec4 v2 = vec.baaa;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // arrr
    {
        vec4 v2 = vec.arrr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // arrg
    {
        vec4 v2 = vec.arrg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // arrb
    {
        vec4 v2 = vec.arrb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // arra
    {
        vec4 v2 = vec.arra;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // argr
    {
        vec4 v2 = vec.argr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // argg
    {
        vec4 v2 = vec.argg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // argb
    {
        vec4 v2 = vec.argb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // arga
    {
        vec4 v2 = vec.arga;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // arbr
    {
        vec4 v2 = vec.arbr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // arbg
    {
        vec4 v2 = vec.arbg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // arbb
    {
        vec4 v2 = vec.arbb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // arba
    {
        vec4 v2 = vec.arba;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // arar
    {
        vec4 v2 = vec.arar;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // arag
    {
        vec4 v2 = vec.arag;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // arab
    {
        vec4 v2 = vec.arab;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // araa
    {
        vec4 v2 = vec.araa;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // agrr
    {
        vec4 v2 = vec.agrr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // agrg
    {
        vec4 v2 = vec.agrg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // agrb
    {
        vec4 v2 = vec.agrb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // agra
    {
        vec4 v2 = vec.agra;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // aggr
    {
        vec4 v2 = vec.aggr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // aggg
    {
        vec4 v2 = vec.aggg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // aggb
    {
        vec4 v2 = vec.aggb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // agga
    {
        vec4 v2 = vec.agga;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // agbr
    {
        vec4 v2 = vec.agbr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // agbg
    {
        vec4 v2 = vec.agbg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // agbb
    {
        vec4 v2 = vec.agbb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // agba
    {
        vec4 v2 = vec.agba;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // agar
    {
        vec4 v2 = vec.agar;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // agag
    {
        vec4 v2 = vec.agag;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // agab
    {
        vec4 v2 = vec.agab;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // agaa
    {
        vec4 v2 = vec.agaa;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // abrr
    {
        vec4 v2 = vec.abrr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // abrg
    {
        vec4 v2 = vec.abrg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // abrb
    {
        vec4 v2 = vec.abrb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // abra
    {
        vec4 v2 = vec.abra;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // abgr
    {
        vec4 v2 = vec.abgr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // abgg
    {
        vec4 v2 = vec.abgg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // abgb
    {
        vec4 v2 = vec.abgb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // abga
    {
        vec4 v2 = vec.abga;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // abbr
    {
        vec4 v2 = vec.abbr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // abbg
    {
        vec4 v2 = vec.abbg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // abbb
    {
        vec4 v2 = vec.abbb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // abba
    {
        vec4 v2 = vec.abba;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // abar
    {
        vec4 v2 = vec.abar;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // abag
    {
        vec4 v2 = vec.abag;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // abab
    {
        vec4 v2 = vec.abab;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // abaa
    {
        vec4 v2 = vec.abaa;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // aarr
    {
        vec4 v2 = vec.aarr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // aarg
    {
        vec4 v2 = vec.aarg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // aarb
    {
        vec4 v2 = vec.aarb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // aara
    {
        vec4 v2 = vec.aara;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // aagr
    {
        vec4 v2 = vec.aagr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // aagg
    {
        vec4 v2 = vec.aagg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // aagb
    {
        vec4 v2 = vec.aagb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // aaga
    {
        vec4 v2 = vec.aaga;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // aabr
    {
        vec4 v2 = vec.aabr;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // aabg
    {
        vec4 v2 = vec.aabg;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // aabb
    {
        vec4 v2 = vec.aabb;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // aaba
    {
        vec4 v2 = vec.aaba;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // aaar
    {
        vec4 v2 = vec.aaar;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // aaag
    {
        vec4 v2 = vec.aaag;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // aaab
    {
        vec4 v2 = vec.aaab;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // aaaa
    {
        vec4 v2 = vec.aaaa;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
}

TEST(GlslikeVector4, Swizzle4Stpq) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);

    // ssss
    {
        vec4 v2 = vec.ssss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ssst
    {
        vec4 v2 = vec.ssst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sssp
    {
        vec4 v2 = vec.sssp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sssq
    {
        vec4 v2 = vec.sssq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ssts
    {
        vec4 v2 = vec.ssts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sstt
    {
        vec4 v2 = vec.sstt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sstp
    {
        vec4 v2 = vec.sstp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sstq
    {
        vec4 v2 = vec.sstq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ssps
    {
        vec4 v2 = vec.ssps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sspt
    {
        vec4 v2 = vec.sspt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sspp
    {
        vec4 v2 = vec.sspp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sspq
    {
        vec4 v2 = vec.sspq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ssqs
    {
        vec4 v2 = vec.ssqs;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ssqt
    {
        vec4 v2 = vec.ssqt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ssqp
    {
        vec4 v2 = vec.ssqp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ssqq
    {
        vec4 v2 = vec.ssqq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // stss
    {
        vec4 v2 = vec.stss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // stst
    {
        vec4 v2 = vec.stst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stsp
    {
        vec4 v2 = vec.stsp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // stsq
    {
        vec4 v2 = vec.stsq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // stts
    {
        vec4 v2 = vec.stts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sttt
    {
        vec4 v2 = vec.sttt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sttp
    {
        vec4 v2 = vec.sttp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sttq
    {
        vec4 v2 = vec.sttq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // stps
    {
        vec4 v2 = vec.stps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // stpt
    {
        vec4 v2 = vec.stpt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stpp
    {
        vec4 v2 = vec.stpp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // stpq
    {
        vec4 v2 = vec.stpq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // stqs
    {
        vec4 v2 = vec.stqs;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // stqt
    {
        vec4 v2 = vec.stqt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // stqp
    {
        vec4 v2 = vec.stqp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // stqq
    {
        vec4 v2 = vec.stqq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // spss
    {
        vec4 v2 = vec.spss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // spst
    {
        vec4 v2 = vec.spst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // spsp
    {
        vec4 v2 = vec.spsp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // spsq
    {
        vec4 v2 = vec.spsq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // spts
    {
        vec4 v2 = vec.spts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sptt
    {
        vec4 v2 = vec.sptt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sptp
    {
        vec4 v2 = vec.sptp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sptq
    {
        vec4 v2 = vec.sptq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // spps
    {
        vec4 v2 = vec.spps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sppt
    {
        vec4 v2 = vec.sppt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sppp
    {
        vec4 v2 = vec.sppp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sppq
    {
        vec4 v2 = vec.sppq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // spqs
    {
        vec4 v2 = vec.spqs;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // spqt
    {
        vec4 v2 = vec.spqt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // spqp
    {
        vec4 v2 = vec.spqp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // spqq
    {
        vec4 v2 = vec.spqq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // sqss
    {
        vec4 v2 = vec.sqss;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sqst
    {
        vec4 v2 = vec.sqst;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sqsp
    {
        vec4 v2 = vec.sqsp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sqsq
    {
        vec4 v2 = vec.sqsq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // sqts
    {
        vec4 v2 = vec.sqts;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sqtt
    {
        vec4 v2 = vec.sqtt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sqtp
    {
        vec4 v2 = vec.sqtp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sqtq
    {
        vec4 v2 = vec.sqtq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // sqps
    {
        vec4 v2 = vec.sqps;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sqpt
    {
        vec4 v2 = vec.sqpt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sqpp
    {
        vec4 v2 = vec.sqpp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sqpq
    {
        vec4 v2 = vec.sqpq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // sqqs
    {
        vec4 v2 = vec.sqqs;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // sqqt
    {
        vec4 v2 = vec.sqqt;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // sqqp
    {
        vec4 v2 = vec.sqqp;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // sqqq
    {
        vec4 v2 = vec.sqqq;
        EXPECT_EQ(v2.x, 1.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tsss
    {
        vec4 v2 = vec.tsss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tsst
    {
        vec4 v2 = vec.tsst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tssp
    {
        vec4 v2 = vec.tssp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tssq
    {
        vec4 v2 = vec.tssq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tsts
    {
        vec4 v2 = vec.tsts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tstt
    {
        vec4 v2 = vec.tstt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tstp
    {
        vec4 v2 = vec.tstp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tstq
    {
        vec4 v2 = vec.tstq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tsps
    {
        vec4 v2 = vec.tsps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tspt
    {
        vec4 v2 = vec.tspt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tspp
    {
        vec4 v2 = vec.tspp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tspq
    {
        vec4 v2 = vec.tspq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tsqs
    {
        vec4 v2 = vec.tsqs;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tsqt
    {
        vec4 v2 = vec.tsqt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tsqp
    {
        vec4 v2 = vec.tsqp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tsqq
    {
        vec4 v2 = vec.tsqq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ttss
    {
        vec4 v2 = vec.ttss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ttst
    {
        vec4 v2 = vec.ttst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttsp
    {
        vec4 v2 = vec.ttsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ttsq
    {
        vec4 v2 = vec.ttsq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ttts
    {
        vec4 v2 = vec.ttts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tttt
    {
        vec4 v2 = vec.tttt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tttp
    {
        vec4 v2 = vec.tttp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tttq
    {
        vec4 v2 = vec.tttq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ttps
    {
        vec4 v2 = vec.ttps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ttpt
    {
        vec4 v2 = vec.ttpt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttpp
    {
        vec4 v2 = vec.ttpp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ttpq
    {
        vec4 v2 = vec.ttpq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ttqs
    {
        vec4 v2 = vec.ttqs;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ttqt
    {
        vec4 v2 = vec.ttqt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ttqp
    {
        vec4 v2 = vec.ttqp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ttqq
    {
        vec4 v2 = vec.ttqq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tpss
    {
        vec4 v2 = vec.tpss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tpst
    {
        vec4 v2 = vec.tpst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tpsp
    {
        vec4 v2 = vec.tpsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tpsq
    {
        vec4 v2 = vec.tpsq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tpts
    {
        vec4 v2 = vec.tpts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tptt
    {
        vec4 v2 = vec.tptt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tptp
    {
        vec4 v2 = vec.tptp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tptq
    {
        vec4 v2 = vec.tptq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tpps
    {
        vec4 v2 = vec.tpps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tppt
    {
        vec4 v2 = vec.tppt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tppp
    {
        vec4 v2 = vec.tppp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tppq
    {
        vec4 v2 = vec.tppq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tpqs
    {
        vec4 v2 = vec.tpqs;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tpqt
    {
        vec4 v2 = vec.tpqt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tpqp
    {
        vec4 v2 = vec.tpqp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tpqq
    {
        vec4 v2 = vec.tpqq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tqss
    {
        vec4 v2 = vec.tqss;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tqst
    {
        vec4 v2 = vec.tqst;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tqsp
    {
        vec4 v2 = vec.tqsp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tqsq
    {
        vec4 v2 = vec.tqsq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tqts
    {
        vec4 v2 = vec.tqts;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tqtt
    {
        vec4 v2 = vec.tqtt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tqtp
    {
        vec4 v2 = vec.tqtp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tqtq
    {
        vec4 v2 = vec.tqtq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tqps
    {
        vec4 v2 = vec.tqps;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tqpt
    {
        vec4 v2 = vec.tqpt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tqpp
    {
        vec4 v2 = vec.tqpp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tqpq
    {
        vec4 v2 = vec.tqpq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // tqqs
    {
        vec4 v2 = vec.tqqs;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // tqqt
    {
        vec4 v2 = vec.tqqt;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // tqqp
    {
        vec4 v2 = vec.tqqp;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // tqqq
    {
        vec4 v2 = vec.tqqq;
        EXPECT_EQ(v2.x, 2.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // psss
    {
        vec4 v2 = vec.psss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // psst
    {
        vec4 v2 = vec.psst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pssp
    {
        vec4 v2 = vec.pssp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pssq
    {
        vec4 v2 = vec.pssq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // psts
    {
        vec4 v2 = vec.psts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pstt
    {
        vec4 v2 = vec.pstt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pstp
    {
        vec4 v2 = vec.pstp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pstq
    {
        vec4 v2 = vec.pstq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // psps
    {
        vec4 v2 = vec.psps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pspt
    {
        vec4 v2 = vec.pspt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pspp
    {
        vec4 v2 = vec.pspp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pspq
    {
        vec4 v2 = vec.pspq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // psqs
    {
        vec4 v2 = vec.psqs;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // psqt
    {
        vec4 v2 = vec.psqt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // psqp
    {
        vec4 v2 = vec.psqp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // psqq
    {
        vec4 v2 = vec.psqq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ptss
    {
        vec4 v2 = vec.ptss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ptst
    {
        vec4 v2 = vec.ptst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ptsp
    {
        vec4 v2 = vec.ptsp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ptsq
    {
        vec4 v2 = vec.ptsq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ptts
    {
        vec4 v2 = vec.ptts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pttt
    {
        vec4 v2 = vec.pttt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pttp
    {
        vec4 v2 = vec.pttp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pttq
    {
        vec4 v2 = vec.pttq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ptps
    {
        vec4 v2 = vec.ptps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ptpt
    {
        vec4 v2 = vec.ptpt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ptpp
    {
        vec4 v2 = vec.ptpp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ptpq
    {
        vec4 v2 = vec.ptpq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ptqs
    {
        vec4 v2 = vec.ptqs;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ptqt
    {
        vec4 v2 = vec.ptqt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ptqp
    {
        vec4 v2 = vec.ptqp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ptqq
    {
        vec4 v2 = vec.ptqq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ppss
    {
        vec4 v2 = vec.ppss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ppst
    {
        vec4 v2 = vec.ppst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ppsp
    {
        vec4 v2 = vec.ppsp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ppsq
    {
        vec4 v2 = vec.ppsq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ppts
    {
        vec4 v2 = vec.ppts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pptt
    {
        vec4 v2 = vec.pptt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pptp
    {
        vec4 v2 = vec.pptp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pptq
    {
        vec4 v2 = vec.pptq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ppps
    {
        vec4 v2 = vec.ppps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pppt
    {
        vec4 v2 = vec.pppt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pppp
    {
        vec4 v2 = vec.pppp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pppq
    {
        vec4 v2 = vec.pppq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // ppqs
    {
        vec4 v2 = vec.ppqs;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // ppqt
    {
        vec4 v2 = vec.ppqt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // ppqp
    {
        vec4 v2 = vec.ppqp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // ppqq
    {
        vec4 v2 = vec.ppqq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // pqss
    {
        vec4 v2 = vec.pqss;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pqst
    {
        vec4 v2 = vec.pqst;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pqsp
    {
        vec4 v2 = vec.pqsp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pqsq
    {
        vec4 v2 = vec.pqsq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // pqts
    {
        vec4 v2 = vec.pqts;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pqtt
    {
        vec4 v2 = vec.pqtt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pqtp
    {
        vec4 v2 = vec.pqtp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pqtq
    {
        vec4 v2 = vec.pqtq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // pqps
    {
        vec4 v2 = vec.pqps;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pqpt
    {
        vec4 v2 = vec.pqpt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pqpp
    {
        vec4 v2 = vec.pqpp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pqpq
    {
        vec4 v2 = vec.pqpq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // pqqs
    {
        vec4 v2 = vec.pqqs;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // pqqt
    {
        vec4 v2 = vec.pqqt;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // pqqp
    {
        vec4 v2 = vec.pqqp;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // pqqq
    {
        vec4 v2 = vec.pqqq;
        EXPECT_EQ(v2.x, 3.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qsss
    {
        vec4 v2 = vec.qsss;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qsst
    {
        vec4 v2 = vec.qsst;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qssp
    {
        vec4 v2 = vec.qssp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qssq
    {
        vec4 v2 = vec.qssq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qsts
    {
        vec4 v2 = vec.qsts;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qstt
    {
        vec4 v2 = vec.qstt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qstp
    {
        vec4 v2 = vec.qstp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qstq
    {
        vec4 v2 = vec.qstq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qsps
    {
        vec4 v2 = vec.qsps;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qspt
    {
        vec4 v2 = vec.qspt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qspp
    {
        vec4 v2 = vec.qspp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qspq
    {
        vec4 v2 = vec.qspq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qsqs
    {
        vec4 v2 = vec.qsqs;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qsqt
    {
        vec4 v2 = vec.qsqt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qsqp
    {
        vec4 v2 = vec.qsqp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qsqq
    {
        vec4 v2 = vec.qsqq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 1.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qtss
    {
        vec4 v2 = vec.qtss;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qtst
    {
        vec4 v2 = vec.qtst;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qtsp
    {
        vec4 v2 = vec.qtsp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qtsq
    {
        vec4 v2 = vec.qtsq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qtts
    {
        vec4 v2 = vec.qtts;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qttt
    {
        vec4 v2 = vec.qttt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qttp
    {
        vec4 v2 = vec.qttp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qttq
    {
        vec4 v2 = vec.qttq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qtps
    {
        vec4 v2 = vec.qtps;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qtpt
    {
        vec4 v2 = vec.qtpt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qtpp
    {
        vec4 v2 = vec.qtpp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qtpq
    {
        vec4 v2 = vec.qtpq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qtqs
    {
        vec4 v2 = vec.qtqs;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qtqt
    {
        vec4 v2 = vec.qtqt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qtqp
    {
        vec4 v2 = vec.qtqp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qtqq
    {
        vec4 v2 = vec.qtqq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 2.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qpss
    {
        vec4 v2 = vec.qpss;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qpst
    {
        vec4 v2 = vec.qpst;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qpsp
    {
        vec4 v2 = vec.qpsp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qpsq
    {
        vec4 v2 = vec.qpsq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qpts
    {
        vec4 v2 = vec.qpts;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qptt
    {
        vec4 v2 = vec.qptt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qptp
    {
        vec4 v2 = vec.qptp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qptq
    {
        vec4 v2 = vec.qptq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qpps
    {
        vec4 v2 = vec.qpps;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qppt
    {
        vec4 v2 = vec.qppt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qppp
    {
        vec4 v2 = vec.qppp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qppq
    {
        vec4 v2 = vec.qppq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qpqs
    {
        vec4 v2 = vec.qpqs;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qpqt
    {
        vec4 v2 = vec.qpqt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qpqp
    {
        vec4 v2 = vec.qpqp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qpqq
    {
        vec4 v2 = vec.qpqq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 3.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qqss
    {
        vec4 v2 = vec.qqss;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qqst
    {
        vec4 v2 = vec.qqst;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qqsp
    {
        vec4 v2 = vec.qqsp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qqsq
    {
        vec4 v2 = vec.qqsq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 1.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qqts
    {
        vec4 v2 = vec.qqts;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qqtt
    {
        vec4 v2 = vec.qqtt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qqtp
    {
        vec4 v2 = vec.qqtp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qqtq
    {
        vec4 v2 = vec.qqtq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 2.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qqps
    {
        vec4 v2 = vec.qqps;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qqpt
    {
        vec4 v2 = vec.qqpt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qqpp
    {
        vec4 v2 = vec.qqpp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qqpq
    {
        vec4 v2 = vec.qqpq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 3.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
    // qqqs
    {
        vec4 v2 = vec.qqqs;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 1.0f);
    }
    // qqqt
    {
        vec4 v2 = vec.qqqt;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 2.0f);
    }
    // qqqp
    {
        vec4 v2 = vec.qqqp;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 3.0f);
    }
    // qqqq
    {
        vec4 v2 = vec.qqqq;
        EXPECT_EQ(v2.x, 4.0f);
        EXPECT_EQ(v2.y, 4.0f);
        EXPECT_EQ(v2.z, 4.0f);
        EXPECT_EQ(v2.w, 4.0f);
    }
}


TEST(GlslikeMatrix2, Identity) {
    vec2 vec(1.0f, 2.0f);
    mat2 mat;
    vec2 result = mat * vec;
    EXPECT_EQ(result.x, vec.x);
    EXPECT_EQ(result.y, vec.y);
}


TEST(GlslikeMatrix3, Identity) {
    vec3 vec(1.0f, 2.0f, 3.0f);
    mat3 mat;
    vec3 result = mat * vec;
    EXPECT_EQ(result.x, vec.x);
    EXPECT_EQ(result.y, vec.y);
    EXPECT_EQ(result.z, vec.z);
}


TEST(GlslikeMatrix4, Identity) {
    vec4 vec(1.0f, 2.0f, 3.0f, 4.0f);
    mat4 mat;
    vec4 result = mat * vec;
    EXPECT_EQ(result.x, vec.x);
    EXPECT_EQ(result.y, vec.y);
    EXPECT_EQ(result.z, vec.z);
    EXPECT_EQ(result.w, vec.w);
}
