from ..__glslike import *


def test_vec2_swizzle2_xy():
    vec = vec2(1.0, 2.0)
    # xx
    v2 = vec.xx
    assert v2.x == 1.0
    assert v2.y == 1.0
    # xy
    v2 = vec.xy
    assert v2.x == 1.0
    assert v2.y == 2.0
    # yx
    v2 = vec.yx
    assert v2.x == 2.0
    assert v2.y == 1.0
    # yy
    v2 = vec.yy
    assert v2.x == 2.0
    assert v2.y == 2.0

def test_vec2_swizzle2_rg():
    vec = vec2(1.0, 2.0)
    # rr
    v2 = vec.rr
    assert v2.x == 1.0
    assert v2.y == 1.0
    # rg
    v2 = vec.rg
    assert v2.x == 1.0
    assert v2.y == 2.0
    # gr
    v2 = vec.gr
    assert v2.x == 2.0
    assert v2.y == 1.0
    # gg
    v2 = vec.gg
    assert v2.x == 2.0
    assert v2.y == 2.0

def test_vec2_swizzle2_st():
    vec = vec2(1.0, 2.0)
    # ss
    v2 = vec.ss
    assert v2.x == 1.0
    assert v2.y == 1.0
    # st
    v2 = vec.st
    assert v2.x == 1.0
    assert v2.y == 2.0
    # ts
    v2 = vec.ts
    assert v2.x == 2.0
    assert v2.y == 1.0
    # tt
    v2 = vec.tt
    assert v2.x == 2.0
    assert v2.y == 2.0

def test_vec2_swizzle3_xyz():
    vec = vec2(1.0, 2.0)
    # xxx
    v2 = vec.xxx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # xxy
    v2 = vec.xxy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # xyx
    v2 = vec.xyx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # xyy
    v2 = vec.xyy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # yxx
    v2 = vec.yxx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # yxy
    v2 = vec.yxy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # yyx
    v2 = vec.yyx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # yyy
    v2 = vec.yyy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0

def test_vec2_swizzle3_rgb():
    vec = vec2(1.0, 2.0)
    # rrr
    v2 = vec.rrr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # rrg
    v2 = vec.rrg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # rgr
    v2 = vec.rgr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # rgg
    v2 = vec.rgg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # grr
    v2 = vec.grr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # grg
    v2 = vec.grg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # ggr
    v2 = vec.ggr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ggg
    v2 = vec.ggg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0

def test_vec2_swizzle3_stp():
    vec = vec2(1.0, 2.0)
    # sss
    v2 = vec.sss
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # sst
    v2 = vec.sst
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # sts
    v2 = vec.sts
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # stt
    v2 = vec.stt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # tss
    v2 = vec.tss
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # tst
    v2 = vec.tst
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # tts
    v2 = vec.tts
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ttt
    v2 = vec.ttt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0

def test_vec2_swizzle4_xyzw():
    vec = vec2(1.0, 2.0)
    # xxxx
    v2 = vec.xxxx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xxxy
    v2 = vec.xxxy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xxyx
    v2 = vec.xxyx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xxyy
    v2 = vec.xxyy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xyxx
    v2 = vec.xyxx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xyxy
    v2 = vec.xyxy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xyyx
    v2 = vec.xyyx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xyyy
    v2 = vec.xyyy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yxxx
    v2 = vec.yxxx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yxxy
    v2 = vec.yxxy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yxyx
    v2 = vec.yxyx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yxyy
    v2 = vec.yxyy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yyxx
    v2 = vec.yyxx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yyxy
    v2 = vec.yyxy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yyyx
    v2 = vec.yyyx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yyyy
    v2 = vec.yyyy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0

def test_vec2_swizzle4_rgba():
    vec = vec2(1.0, 2.0)
    # rrrr
    v2 = vec.rrrr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rrrg
    v2 = vec.rrrg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rrgr
    v2 = vec.rrgr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rrgg
    v2 = vec.rrgg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rgrr
    v2 = vec.rgrr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rgrg
    v2 = vec.rgrg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rggr
    v2 = vec.rggr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rggg
    v2 = vec.rggg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # grrr
    v2 = vec.grrr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # grrg
    v2 = vec.grrg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # grgr
    v2 = vec.grgr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # grgg
    v2 = vec.grgg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # ggrr
    v2 = vec.ggrr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ggrg
    v2 = vec.ggrg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # gggr
    v2 = vec.gggr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # gggg
    v2 = vec.gggg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0

def test_vec2_swizzle4_stpq():
    vec = vec2(1.0, 2.0)
    # ssss
    v2 = vec.ssss
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ssst
    v2 = vec.ssst
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ssts
    v2 = vec.ssts
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sstt
    v2 = vec.sstt
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # stss
    v2 = vec.stss
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # stst
    v2 = vec.stst
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # stts
    v2 = vec.stts
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sttt
    v2 = vec.sttt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tsss
    v2 = vec.tsss
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # tsst
    v2 = vec.tsst
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # tsts
    v2 = vec.tsts
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tstt
    v2 = vec.tstt
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # ttss
    v2 = vec.ttss
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ttst
    v2 = vec.ttst
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ttts
    v2 = vec.ttts
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tttt
    v2 = vec.tttt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0

def test_vec3_swizzle2_xy():
    vec = vec3(1.0, 2.0, 3.0)
    # xx
    v2 = vec.xx
    assert v2.x == 1.0
    assert v2.y == 1.0
    # xy
    v2 = vec.xy
    assert v2.x == 1.0
    assert v2.y == 2.0
    # xz
    v2 = vec.xz
    assert v2.x == 1.0
    assert v2.y == 3.0
    # yx
    v2 = vec.yx
    assert v2.x == 2.0
    assert v2.y == 1.0
    # yy
    v2 = vec.yy
    assert v2.x == 2.0
    assert v2.y == 2.0
    # yz
    v2 = vec.yz
    assert v2.x == 2.0
    assert v2.y == 3.0
    # zx
    v2 = vec.zx
    assert v2.x == 3.0
    assert v2.y == 1.0
    # zy
    v2 = vec.zy
    assert v2.x == 3.0
    assert v2.y == 2.0
    # zz
    v2 = vec.zz
    assert v2.x == 3.0
    assert v2.y == 3.0

def test_vec3_swizzle2_rg():
    vec = vec3(1.0, 2.0, 3.0)
    # rr
    v2 = vec.rr
    assert v2.x == 1.0
    assert v2.y == 1.0
    # rg
    v2 = vec.rg
    assert v2.x == 1.0
    assert v2.y == 2.0
    # rb
    v2 = vec.rb
    assert v2.x == 1.0
    assert v2.y == 3.0
    # gr
    v2 = vec.gr
    assert v2.x == 2.0
    assert v2.y == 1.0
    # gg
    v2 = vec.gg
    assert v2.x == 2.0
    assert v2.y == 2.0
    # gb
    v2 = vec.gb
    assert v2.x == 2.0
    assert v2.y == 3.0
    # br
    v2 = vec.br
    assert v2.x == 3.0
    assert v2.y == 1.0
    # bg
    v2 = vec.bg
    assert v2.x == 3.0
    assert v2.y == 2.0
    # bb
    v2 = vec.bb
    assert v2.x == 3.0
    assert v2.y == 3.0

def test_vec3_swizzle2_st():
    vec = vec3(1.0, 2.0, 3.0)
    # ss
    v2 = vec.ss
    assert v2.x == 1.0
    assert v2.y == 1.0
    # st
    v2 = vec.st
    assert v2.x == 1.0
    assert v2.y == 2.0
    # sp
    v2 = vec.sp
    assert v2.x == 1.0
    assert v2.y == 3.0
    # ts
    v2 = vec.ts
    assert v2.x == 2.0
    assert v2.y == 1.0
    # tt
    v2 = vec.tt
    assert v2.x == 2.0
    assert v2.y == 2.0
    # tp
    v2 = vec.tp
    assert v2.x == 2.0
    assert v2.y == 3.0
    # ps
    v2 = vec.ps
    assert v2.x == 3.0
    assert v2.y == 1.0
    # pt
    v2 = vec.pt
    assert v2.x == 3.0
    assert v2.y == 2.0
    # pp
    v2 = vec.pp
    assert v2.x == 3.0
    assert v2.y == 3.0

def test_vec3_swizzle3_xyz():
    vec = vec3(1.0, 2.0, 3.0)
    # xxx
    v2 = vec.xxx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # xxy
    v2 = vec.xxy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # xxz
    v2 = vec.xxz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # xyx
    v2 = vec.xyx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # xyy
    v2 = vec.xyy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # xyz
    v2 = vec.xyz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # xzx
    v2 = vec.xzx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # xzy
    v2 = vec.xzy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # xzz
    v2 = vec.xzz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # yxx
    v2 = vec.yxx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # yxy
    v2 = vec.yxy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # yxz
    v2 = vec.yxz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # yyx
    v2 = vec.yyx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # yyy
    v2 = vec.yyy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # yyz
    v2 = vec.yyz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # yzx
    v2 = vec.yzx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # yzy
    v2 = vec.yzy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # yzz
    v2 = vec.yzz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # zxx
    v2 = vec.zxx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # zxy
    v2 = vec.zxy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # zxz
    v2 = vec.zxz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # zyx
    v2 = vec.zyx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # zyy
    v2 = vec.zyy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # zyz
    v2 = vec.zyz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # zzx
    v2 = vec.zzx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # zzy
    v2 = vec.zzy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # zzz
    v2 = vec.zzz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0

def test_vec3_swizzle3_rgb():
    vec = vec3(1.0, 2.0, 3.0)
    # rrr
    v2 = vec.rrr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # rrg
    v2 = vec.rrg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # rrb
    v2 = vec.rrb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # rgr
    v2 = vec.rgr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # rgg
    v2 = vec.rgg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # rgb
    v2 = vec.rgb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # rbr
    v2 = vec.rbr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # rbg
    v2 = vec.rbg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # rbb
    v2 = vec.rbb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # grr
    v2 = vec.grr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # grg
    v2 = vec.grg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # grb
    v2 = vec.grb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # ggr
    v2 = vec.ggr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ggg
    v2 = vec.ggg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # ggb
    v2 = vec.ggb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # gbr
    v2 = vec.gbr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # gbg
    v2 = vec.gbg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # gbb
    v2 = vec.gbb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # brr
    v2 = vec.brr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # brg
    v2 = vec.brg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # brb
    v2 = vec.brb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # bgr
    v2 = vec.bgr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # bgg
    v2 = vec.bgg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # bgb
    v2 = vec.bgb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # bbr
    v2 = vec.bbr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # bbg
    v2 = vec.bbg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # bbb
    v2 = vec.bbb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0

def test_vec3_swizzle3_stp():
    vec = vec3(1.0, 2.0, 3.0)
    # sss
    v2 = vec.sss
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # sst
    v2 = vec.sst
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # ssp
    v2 = vec.ssp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # sts
    v2 = vec.sts
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # stt
    v2 = vec.stt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # stp
    v2 = vec.stp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # sps
    v2 = vec.sps
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # spt
    v2 = vec.spt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # spp
    v2 = vec.spp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # tss
    v2 = vec.tss
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # tst
    v2 = vec.tst
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # tsp
    v2 = vec.tsp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # tts
    v2 = vec.tts
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ttt
    v2 = vec.ttt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # ttp
    v2 = vec.ttp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # tps
    v2 = vec.tps
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # tpt
    v2 = vec.tpt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # tpp
    v2 = vec.tpp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # pss
    v2 = vec.pss
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # pst
    v2 = vec.pst
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # psp
    v2 = vec.psp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # pts
    v2 = vec.pts
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ptt
    v2 = vec.ptt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # ptp
    v2 = vec.ptp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # pps
    v2 = vec.pps
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # ppt
    v2 = vec.ppt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # ppp
    v2 = vec.ppp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0

def test_vec3_swizzle4_xyzw():
    vec = vec3(1.0, 2.0, 3.0)
    # xxxx
    v2 = vec.xxxx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xxxy
    v2 = vec.xxxy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xxxz
    v2 = vec.xxxz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xxyx
    v2 = vec.xxyx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xxyy
    v2 = vec.xxyy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xxyz
    v2 = vec.xxyz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xxzx
    v2 = vec.xxzx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xxzy
    v2 = vec.xxzy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xxzz
    v2 = vec.xxzz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # xyxx
    v2 = vec.xyxx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xyxy
    v2 = vec.xyxy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xyxz
    v2 = vec.xyxz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xyyx
    v2 = vec.xyyx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xyyy
    v2 = vec.xyyy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xyyz
    v2 = vec.xyyz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xyzx
    v2 = vec.xyzx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xyzy
    v2 = vec.xyzy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xyzz
    v2 = vec.xyzz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # xzxx
    v2 = vec.xzxx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xzxy
    v2 = vec.xzxy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xzxz
    v2 = vec.xzxz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xzyx
    v2 = vec.xzyx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xzyy
    v2 = vec.xzyy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xzyz
    v2 = vec.xzyz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xzzx
    v2 = vec.xzzx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xzzy
    v2 = vec.xzzy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xzzz
    v2 = vec.xzzz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # yxxx
    v2 = vec.yxxx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yxxy
    v2 = vec.yxxy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yxxz
    v2 = vec.yxxz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # yxyx
    v2 = vec.yxyx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yxyy
    v2 = vec.yxyy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yxyz
    v2 = vec.yxyz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # yxzx
    v2 = vec.yxzx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # yxzy
    v2 = vec.yxzy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # yxzz
    v2 = vec.yxzz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # yyxx
    v2 = vec.yyxx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yyxy
    v2 = vec.yyxy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yyxz
    v2 = vec.yyxz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # yyyx
    v2 = vec.yyyx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yyyy
    v2 = vec.yyyy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yyyz
    v2 = vec.yyyz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # yyzx
    v2 = vec.yyzx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # yyzy
    v2 = vec.yyzy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # yyzz
    v2 = vec.yyzz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # yzxx
    v2 = vec.yzxx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yzxy
    v2 = vec.yzxy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yzxz
    v2 = vec.yzxz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # yzyx
    v2 = vec.yzyx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yzyy
    v2 = vec.yzyy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yzyz
    v2 = vec.yzyz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # yzzx
    v2 = vec.yzzx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # yzzy
    v2 = vec.yzzy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # yzzz
    v2 = vec.yzzz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zxxx
    v2 = vec.zxxx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zxxy
    v2 = vec.zxxy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zxxz
    v2 = vec.zxxz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zxyx
    v2 = vec.zxyx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zxyy
    v2 = vec.zxyy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zxyz
    v2 = vec.zxyz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zxzx
    v2 = vec.zxzx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zxzy
    v2 = vec.zxzy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zxzz
    v2 = vec.zxzz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zyxx
    v2 = vec.zyxx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zyxy
    v2 = vec.zyxy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zyxz
    v2 = vec.zyxz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zyyx
    v2 = vec.zyyx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zyyy
    v2 = vec.zyyy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zyyz
    v2 = vec.zyyz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zyzx
    v2 = vec.zyzx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zyzy
    v2 = vec.zyzy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zyzz
    v2 = vec.zyzz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zzxx
    v2 = vec.zzxx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zzxy
    v2 = vec.zzxy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zzxz
    v2 = vec.zzxz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zzyx
    v2 = vec.zzyx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zzyy
    v2 = vec.zzyy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zzyz
    v2 = vec.zzyz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zzzx
    v2 = vec.zzzx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zzzy
    v2 = vec.zzzy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zzzz
    v2 = vec.zzzz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0

def test_vec3_swizzle4_rgba():
    vec = vec3(1.0, 2.0, 3.0)
    # rrrr
    v2 = vec.rrrr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rrrg
    v2 = vec.rrrg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rrrb
    v2 = vec.rrrb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rrgr
    v2 = vec.rrgr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rrgg
    v2 = vec.rrgg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rrgb
    v2 = vec.rrgb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # rrbr
    v2 = vec.rrbr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rrbg
    v2 = vec.rrbg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rrbb
    v2 = vec.rrbb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # rgrr
    v2 = vec.rgrr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rgrg
    v2 = vec.rgrg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rgrb
    v2 = vec.rgrb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rggr
    v2 = vec.rggr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rggg
    v2 = vec.rggg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rggb
    v2 = vec.rggb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # rgbr
    v2 = vec.rgbr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rgbg
    v2 = vec.rgbg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rgbb
    v2 = vec.rgbb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # rbrr
    v2 = vec.rbrr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rbrg
    v2 = vec.rbrg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rbrb
    v2 = vec.rbrb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rbgr
    v2 = vec.rbgr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rbgg
    v2 = vec.rbgg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rbgb
    v2 = vec.rbgb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # rbbr
    v2 = vec.rbbr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rbbg
    v2 = vec.rbbg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rbbb
    v2 = vec.rbbb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # grrr
    v2 = vec.grrr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # grrg
    v2 = vec.grrg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # grrb
    v2 = vec.grrb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # grgr
    v2 = vec.grgr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # grgg
    v2 = vec.grgg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # grgb
    v2 = vec.grgb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # grbr
    v2 = vec.grbr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # grbg
    v2 = vec.grbg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # grbb
    v2 = vec.grbb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ggrr
    v2 = vec.ggrr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ggrg
    v2 = vec.ggrg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ggrb
    v2 = vec.ggrb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # gggr
    v2 = vec.gggr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # gggg
    v2 = vec.gggg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # gggb
    v2 = vec.gggb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ggbr
    v2 = vec.ggbr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ggbg
    v2 = vec.ggbg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ggbb
    v2 = vec.ggbb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # gbrr
    v2 = vec.gbrr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # gbrg
    v2 = vec.gbrg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # gbrb
    v2 = vec.gbrb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # gbgr
    v2 = vec.gbgr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # gbgg
    v2 = vec.gbgg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # gbgb
    v2 = vec.gbgb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # gbbr
    v2 = vec.gbbr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # gbbg
    v2 = vec.gbbg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # gbbb
    v2 = vec.gbbb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # brrr
    v2 = vec.brrr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # brrg
    v2 = vec.brrg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # brrb
    v2 = vec.brrb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # brgr
    v2 = vec.brgr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # brgg
    v2 = vec.brgg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # brgb
    v2 = vec.brgb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # brbr
    v2 = vec.brbr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # brbg
    v2 = vec.brbg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # brbb
    v2 = vec.brbb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # bgrr
    v2 = vec.bgrr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # bgrg
    v2 = vec.bgrg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # bgrb
    v2 = vec.bgrb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # bggr
    v2 = vec.bggr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # bggg
    v2 = vec.bggg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # bggb
    v2 = vec.bggb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # bgbr
    v2 = vec.bgbr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # bgbg
    v2 = vec.bgbg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # bgbb
    v2 = vec.bgbb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # bbrr
    v2 = vec.bbrr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # bbrg
    v2 = vec.bbrg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # bbrb
    v2 = vec.bbrb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # bbgr
    v2 = vec.bbgr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # bbgg
    v2 = vec.bbgg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # bbgb
    v2 = vec.bbgb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # bbbr
    v2 = vec.bbbr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # bbbg
    v2 = vec.bbbg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # bbbb
    v2 = vec.bbbb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0

def test_vec3_swizzle4_stpq():
    vec = vec3(1.0, 2.0, 3.0)
    # ssss
    v2 = vec.ssss
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ssst
    v2 = vec.ssst
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # sssp
    v2 = vec.sssp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ssts
    v2 = vec.ssts
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sstt
    v2 = vec.sstt
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sstp
    v2 = vec.sstp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ssps
    v2 = vec.ssps
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # sspt
    v2 = vec.sspt
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # sspp
    v2 = vec.sspp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # stss
    v2 = vec.stss
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # stst
    v2 = vec.stst
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # stsp
    v2 = vec.stsp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # stts
    v2 = vec.stts
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sttt
    v2 = vec.sttt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sttp
    v2 = vec.sttp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # stps
    v2 = vec.stps
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # stpt
    v2 = vec.stpt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # stpp
    v2 = vec.stpp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # spss
    v2 = vec.spss
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # spst
    v2 = vec.spst
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # spsp
    v2 = vec.spsp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # spts
    v2 = vec.spts
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sptt
    v2 = vec.sptt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sptp
    v2 = vec.sptp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # spps
    v2 = vec.spps
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # sppt
    v2 = vec.sppt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # sppp
    v2 = vec.sppp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # tsss
    v2 = vec.tsss
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # tsst
    v2 = vec.tsst
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # tssp
    v2 = vec.tssp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # tsts
    v2 = vec.tsts
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tstt
    v2 = vec.tstt
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tstp
    v2 = vec.tstp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # tsps
    v2 = vec.tsps
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # tspt
    v2 = vec.tspt
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # tspp
    v2 = vec.tspp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ttss
    v2 = vec.ttss
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ttst
    v2 = vec.ttst
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ttsp
    v2 = vec.ttsp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ttts
    v2 = vec.ttts
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tttt
    v2 = vec.tttt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tttp
    v2 = vec.tttp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ttps
    v2 = vec.ttps
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ttpt
    v2 = vec.ttpt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ttpp
    v2 = vec.ttpp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # tpss
    v2 = vec.tpss
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # tpst
    v2 = vec.tpst
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # tpsp
    v2 = vec.tpsp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # tpts
    v2 = vec.tpts
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tptt
    v2 = vec.tptt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tptp
    v2 = vec.tptp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # tpps
    v2 = vec.tpps
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # tppt
    v2 = vec.tppt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # tppp
    v2 = vec.tppp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # psss
    v2 = vec.psss
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # psst
    v2 = vec.psst
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # pssp
    v2 = vec.pssp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # psts
    v2 = vec.psts
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pstt
    v2 = vec.pstt
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pstp
    v2 = vec.pstp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # psps
    v2 = vec.psps
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # pspt
    v2 = vec.pspt
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # pspp
    v2 = vec.pspp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ptss
    v2 = vec.ptss
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ptst
    v2 = vec.ptst
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ptsp
    v2 = vec.ptsp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ptts
    v2 = vec.ptts
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pttt
    v2 = vec.pttt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pttp
    v2 = vec.pttp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ptps
    v2 = vec.ptps
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ptpt
    v2 = vec.ptpt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ptpp
    v2 = vec.ptpp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ppss
    v2 = vec.ppss
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ppst
    v2 = vec.ppst
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ppsp
    v2 = vec.ppsp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ppts
    v2 = vec.ppts
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pptt
    v2 = vec.pptt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pptp
    v2 = vec.pptp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ppps
    v2 = vec.ppps
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # pppt
    v2 = vec.pppt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # pppp
    v2 = vec.pppp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0

def test_vec4_swizzle2_xy():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # xx
    v2 = vec.xx
    assert v2.x == 1.0
    assert v2.y == 1.0
    # xy
    v2 = vec.xy
    assert v2.x == 1.0
    assert v2.y == 2.0
    # xz
    v2 = vec.xz
    assert v2.x == 1.0
    assert v2.y == 3.0
    # xw
    v2 = vec.xw
    assert v2.x == 1.0
    assert v2.y == 4.0
    # yx
    v2 = vec.yx
    assert v2.x == 2.0
    assert v2.y == 1.0
    # yy
    v2 = vec.yy
    assert v2.x == 2.0
    assert v2.y == 2.0
    # yz
    v2 = vec.yz
    assert v2.x == 2.0
    assert v2.y == 3.0
    # yw
    v2 = vec.yw
    assert v2.x == 2.0
    assert v2.y == 4.0
    # zx
    v2 = vec.zx
    assert v2.x == 3.0
    assert v2.y == 1.0
    # zy
    v2 = vec.zy
    assert v2.x == 3.0
    assert v2.y == 2.0
    # zz
    v2 = vec.zz
    assert v2.x == 3.0
    assert v2.y == 3.0
    # zw
    v2 = vec.zw
    assert v2.x == 3.0
    assert v2.y == 4.0
    # wx
    v2 = vec.wx
    assert v2.x == 4.0
    assert v2.y == 1.0
    # wy
    v2 = vec.wy
    assert v2.x == 4.0
    assert v2.y == 2.0
    # wz
    v2 = vec.wz
    assert v2.x == 4.0
    assert v2.y == 3.0
    # ww
    v2 = vec.ww
    assert v2.x == 4.0
    assert v2.y == 4.0

def test_vec4_swizzle2_rg():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # rr
    v2 = vec.rr
    assert v2.x == 1.0
    assert v2.y == 1.0
    # rg
    v2 = vec.rg
    assert v2.x == 1.0
    assert v2.y == 2.0
    # rb
    v2 = vec.rb
    assert v2.x == 1.0
    assert v2.y == 3.0
    # ra
    v2 = vec.ra
    assert v2.x == 1.0
    assert v2.y == 4.0
    # gr
    v2 = vec.gr
    assert v2.x == 2.0
    assert v2.y == 1.0
    # gg
    v2 = vec.gg
    assert v2.x == 2.0
    assert v2.y == 2.0
    # gb
    v2 = vec.gb
    assert v2.x == 2.0
    assert v2.y == 3.0
    # ga
    v2 = vec.ga
    assert v2.x == 2.0
    assert v2.y == 4.0
    # br
    v2 = vec.br
    assert v2.x == 3.0
    assert v2.y == 1.0
    # bg
    v2 = vec.bg
    assert v2.x == 3.0
    assert v2.y == 2.0
    # bb
    v2 = vec.bb
    assert v2.x == 3.0
    assert v2.y == 3.0
    # ba
    v2 = vec.ba
    assert v2.x == 3.0
    assert v2.y == 4.0
    # ar
    v2 = vec.ar
    assert v2.x == 4.0
    assert v2.y == 1.0
    # ag
    v2 = vec.ag
    assert v2.x == 4.0
    assert v2.y == 2.0
    # ab
    v2 = vec.ab
    assert v2.x == 4.0
    assert v2.y == 3.0
    # aa
    v2 = vec.aa
    assert v2.x == 4.0
    assert v2.y == 4.0

def test_vec4_swizzle2_st():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # ss
    v2 = vec.ss
    assert v2.x == 1.0
    assert v2.y == 1.0
    # st
    v2 = vec.st
    assert v2.x == 1.0
    assert v2.y == 2.0
    # sp
    v2 = vec.sp
    assert v2.x == 1.0
    assert v2.y == 3.0
    # sq
    v2 = vec.sq
    assert v2.x == 1.0
    assert v2.y == 4.0
    # ts
    v2 = vec.ts
    assert v2.x == 2.0
    assert v2.y == 1.0
    # tt
    v2 = vec.tt
    assert v2.x == 2.0
    assert v2.y == 2.0
    # tp
    v2 = vec.tp
    assert v2.x == 2.0
    assert v2.y == 3.0
    # tq
    v2 = vec.tq
    assert v2.x == 2.0
    assert v2.y == 4.0
    # ps
    v2 = vec.ps
    assert v2.x == 3.0
    assert v2.y == 1.0
    # pt
    v2 = vec.pt
    assert v2.x == 3.0
    assert v2.y == 2.0
    # pp
    v2 = vec.pp
    assert v2.x == 3.0
    assert v2.y == 3.0
    # pq
    v2 = vec.pq
    assert v2.x == 3.0
    assert v2.y == 4.0
    # qs
    v2 = vec.qs
    assert v2.x == 4.0
    assert v2.y == 1.0
    # qt
    v2 = vec.qt
    assert v2.x == 4.0
    assert v2.y == 2.0
    # qp
    v2 = vec.qp
    assert v2.x == 4.0
    assert v2.y == 3.0
    # qq
    v2 = vec.qq
    assert v2.x == 4.0
    assert v2.y == 4.0

def test_vec4_swizzle3_xyz():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # xxx
    v2 = vec.xxx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # xxy
    v2 = vec.xxy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # xxz
    v2 = vec.xxz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # xxw
    v2 = vec.xxw
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # xyx
    v2 = vec.xyx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # xyy
    v2 = vec.xyy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # xyz
    v2 = vec.xyz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # xyw
    v2 = vec.xyw
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # xzx
    v2 = vec.xzx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # xzy
    v2 = vec.xzy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # xzz
    v2 = vec.xzz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # xzw
    v2 = vec.xzw
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # xwx
    v2 = vec.xwx
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # xwy
    v2 = vec.xwy
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # xwz
    v2 = vec.xwz
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # xww
    v2 = vec.xww
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # yxx
    v2 = vec.yxx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # yxy
    v2 = vec.yxy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # yxz
    v2 = vec.yxz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # yxw
    v2 = vec.yxw
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # yyx
    v2 = vec.yyx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # yyy
    v2 = vec.yyy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # yyz
    v2 = vec.yyz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # yyw
    v2 = vec.yyw
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # yzx
    v2 = vec.yzx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # yzy
    v2 = vec.yzy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # yzz
    v2 = vec.yzz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # yzw
    v2 = vec.yzw
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # ywx
    v2 = vec.ywx
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # ywy
    v2 = vec.ywy
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # ywz
    v2 = vec.ywz
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # yww
    v2 = vec.yww
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # zxx
    v2 = vec.zxx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # zxy
    v2 = vec.zxy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # zxz
    v2 = vec.zxz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # zxw
    v2 = vec.zxw
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # zyx
    v2 = vec.zyx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # zyy
    v2 = vec.zyy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # zyz
    v2 = vec.zyz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # zyw
    v2 = vec.zyw
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # zzx
    v2 = vec.zzx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # zzy
    v2 = vec.zzy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # zzz
    v2 = vec.zzz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # zzw
    v2 = vec.zzw
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # zwx
    v2 = vec.zwx
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # zwy
    v2 = vec.zwy
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # zwz
    v2 = vec.zwz
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # zww
    v2 = vec.zww
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # wxx
    v2 = vec.wxx
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # wxy
    v2 = vec.wxy
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # wxz
    v2 = vec.wxz
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # wxw
    v2 = vec.wxw
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # wyx
    v2 = vec.wyx
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # wyy
    v2 = vec.wyy
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # wyz
    v2 = vec.wyz
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # wyw
    v2 = vec.wyw
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # wzx
    v2 = vec.wzx
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # wzy
    v2 = vec.wzy
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # wzz
    v2 = vec.wzz
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # wzw
    v2 = vec.wzw
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # wwx
    v2 = vec.wwx
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # wwy
    v2 = vec.wwy
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # wwz
    v2 = vec.wwz
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # www
    v2 = vec.www
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0

def test_vec4_swizzle3_rgb():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # rrr
    v2 = vec.rrr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # rrg
    v2 = vec.rrg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # rrb
    v2 = vec.rrb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # rra
    v2 = vec.rra
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # rgr
    v2 = vec.rgr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # rgg
    v2 = vec.rgg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # rgb
    v2 = vec.rgb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # rga
    v2 = vec.rga
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # rbr
    v2 = vec.rbr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # rbg
    v2 = vec.rbg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # rbb
    v2 = vec.rbb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # rba
    v2 = vec.rba
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # rar
    v2 = vec.rar
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # rag
    v2 = vec.rag
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # rab
    v2 = vec.rab
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # raa
    v2 = vec.raa
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # grr
    v2 = vec.grr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # grg
    v2 = vec.grg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # grb
    v2 = vec.grb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # gra
    v2 = vec.gra
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # ggr
    v2 = vec.ggr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ggg
    v2 = vec.ggg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # ggb
    v2 = vec.ggb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # gga
    v2 = vec.gga
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # gbr
    v2 = vec.gbr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # gbg
    v2 = vec.gbg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # gbb
    v2 = vec.gbb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # gba
    v2 = vec.gba
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # gar
    v2 = vec.gar
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # gag
    v2 = vec.gag
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # gab
    v2 = vec.gab
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # gaa
    v2 = vec.gaa
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # brr
    v2 = vec.brr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # brg
    v2 = vec.brg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # brb
    v2 = vec.brb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # bra
    v2 = vec.bra
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # bgr
    v2 = vec.bgr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # bgg
    v2 = vec.bgg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # bgb
    v2 = vec.bgb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # bga
    v2 = vec.bga
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # bbr
    v2 = vec.bbr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # bbg
    v2 = vec.bbg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # bbb
    v2 = vec.bbb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # bba
    v2 = vec.bba
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # bar
    v2 = vec.bar
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # bag
    v2 = vec.bag
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # bab
    v2 = vec.bab
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # baa
    v2 = vec.baa
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # arr
    v2 = vec.arr
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # arg
    v2 = vec.arg
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # arb
    v2 = vec.arb
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # ara
    v2 = vec.ara
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # agr
    v2 = vec.agr
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # agg
    v2 = vec.agg
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # agb
    v2 = vec.agb
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # aga
    v2 = vec.aga
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # abr
    v2 = vec.abr
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # abg
    v2 = vec.abg
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # abb
    v2 = vec.abb
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # aba
    v2 = vec.aba
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # aar
    v2 = vec.aar
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # aag
    v2 = vec.aag
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # aab
    v2 = vec.aab
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # aaa
    v2 = vec.aaa
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0

def test_vec4_swizzle3_stp():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # sss
    v2 = vec.sss
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # sst
    v2 = vec.sst
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # ssp
    v2 = vec.ssp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # ssq
    v2 = vec.ssq
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # sts
    v2 = vec.sts
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # stt
    v2 = vec.stt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # stp
    v2 = vec.stp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # stq
    v2 = vec.stq
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # sps
    v2 = vec.sps
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # spt
    v2 = vec.spt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # spp
    v2 = vec.spp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # spq
    v2 = vec.spq
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # sqs
    v2 = vec.sqs
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # sqt
    v2 = vec.sqt
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # sqp
    v2 = vec.sqp
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # sqq
    v2 = vec.sqq
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # tss
    v2 = vec.tss
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # tst
    v2 = vec.tst
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # tsp
    v2 = vec.tsp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # tsq
    v2 = vec.tsq
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # tts
    v2 = vec.tts
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ttt
    v2 = vec.ttt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # ttp
    v2 = vec.ttp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # ttq
    v2 = vec.ttq
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # tps
    v2 = vec.tps
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # tpt
    v2 = vec.tpt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # tpp
    v2 = vec.tpp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # tpq
    v2 = vec.tpq
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # tqs
    v2 = vec.tqs
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # tqt
    v2 = vec.tqt
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # tqp
    v2 = vec.tqp
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # tqq
    v2 = vec.tqq
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # pss
    v2 = vec.pss
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # pst
    v2 = vec.pst
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # psp
    v2 = vec.psp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # psq
    v2 = vec.psq
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # pts
    v2 = vec.pts
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # ptt
    v2 = vec.ptt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # ptp
    v2 = vec.ptp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # ptq
    v2 = vec.ptq
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # pps
    v2 = vec.pps
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # ppt
    v2 = vec.ppt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # ppp
    v2 = vec.ppp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # ppq
    v2 = vec.ppq
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # pqs
    v2 = vec.pqs
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # pqt
    v2 = vec.pqt
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # pqp
    v2 = vec.pqp
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # pqq
    v2 = vec.pqq
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    # qss
    v2 = vec.qss
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    # qst
    v2 = vec.qst
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    # qsp
    v2 = vec.qsp
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    # qsq
    v2 = vec.qsq
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    # qts
    v2 = vec.qts
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    # qtt
    v2 = vec.qtt
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    # qtp
    v2 = vec.qtp
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    # qtq
    v2 = vec.qtq
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    # qps
    v2 = vec.qps
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    # qpt
    v2 = vec.qpt
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    # qpp
    v2 = vec.qpp
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    # qpq
    v2 = vec.qpq
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    # qqs
    v2 = vec.qqs
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    # qqt
    v2 = vec.qqt
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    # qqp
    v2 = vec.qqp
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    # qqq
    v2 = vec.qqq
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0

def test_vec4_swizzle4_xyzw():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # xxxx
    v2 = vec.xxxx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xxxy
    v2 = vec.xxxy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xxxz
    v2 = vec.xxxz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xxxw
    v2 = vec.xxxw
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # xxyx
    v2 = vec.xxyx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xxyy
    v2 = vec.xxyy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xxyz
    v2 = vec.xxyz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xxyw
    v2 = vec.xxyw
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # xxzx
    v2 = vec.xxzx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xxzy
    v2 = vec.xxzy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xxzz
    v2 = vec.xxzz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # xxzw
    v2 = vec.xxzw
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # xxwx
    v2 = vec.xxwx
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # xxwy
    v2 = vec.xxwy
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # xxwz
    v2 = vec.xxwz
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # xxww
    v2 = vec.xxww
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # xyxx
    v2 = vec.xyxx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xyxy
    v2 = vec.xyxy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xyxz
    v2 = vec.xyxz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xyxw
    v2 = vec.xyxw
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # xyyx
    v2 = vec.xyyx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xyyy
    v2 = vec.xyyy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xyyz
    v2 = vec.xyyz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xyyw
    v2 = vec.xyyw
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # xyzx
    v2 = vec.xyzx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xyzy
    v2 = vec.xyzy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xyzz
    v2 = vec.xyzz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # xyzw
    v2 = vec.xyzw
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # xywx
    v2 = vec.xywx
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # xywy
    v2 = vec.xywy
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # xywz
    v2 = vec.xywz
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # xyww
    v2 = vec.xyww
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # xzxx
    v2 = vec.xzxx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xzxy
    v2 = vec.xzxy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xzxz
    v2 = vec.xzxz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xzxw
    v2 = vec.xzxw
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # xzyx
    v2 = vec.xzyx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xzyy
    v2 = vec.xzyy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xzyz
    v2 = vec.xzyz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xzyw
    v2 = vec.xzyw
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # xzzx
    v2 = vec.xzzx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xzzy
    v2 = vec.xzzy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xzzz
    v2 = vec.xzzz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # xzzw
    v2 = vec.xzzw
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # xzwx
    v2 = vec.xzwx
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # xzwy
    v2 = vec.xzwy
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # xzwz
    v2 = vec.xzwz
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # xzww
    v2 = vec.xzww
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # xwxx
    v2 = vec.xwxx
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # xwxy
    v2 = vec.xwxy
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # xwxz
    v2 = vec.xwxz
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # xwxw
    v2 = vec.xwxw
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # xwyx
    v2 = vec.xwyx
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # xwyy
    v2 = vec.xwyy
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # xwyz
    v2 = vec.xwyz
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # xwyw
    v2 = vec.xwyw
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # xwzx
    v2 = vec.xwzx
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # xwzy
    v2 = vec.xwzy
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # xwzz
    v2 = vec.xwzz
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # xwzw
    v2 = vec.xwzw
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # xwwx
    v2 = vec.xwwx
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # xwwy
    v2 = vec.xwwy
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # xwwz
    v2 = vec.xwwz
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # xwww
    v2 = vec.xwww
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # yxxx
    v2 = vec.yxxx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yxxy
    v2 = vec.yxxy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yxxz
    v2 = vec.yxxz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # yxxw
    v2 = vec.yxxw
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # yxyx
    v2 = vec.yxyx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yxyy
    v2 = vec.yxyy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yxyz
    v2 = vec.yxyz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # yxyw
    v2 = vec.yxyw
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # yxzx
    v2 = vec.yxzx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # yxzy
    v2 = vec.yxzy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # yxzz
    v2 = vec.yxzz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # yxzw
    v2 = vec.yxzw
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # yxwx
    v2 = vec.yxwx
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # yxwy
    v2 = vec.yxwy
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # yxwz
    v2 = vec.yxwz
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # yxww
    v2 = vec.yxww
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # yyxx
    v2 = vec.yyxx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yyxy
    v2 = vec.yyxy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yyxz
    v2 = vec.yyxz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # yyxw
    v2 = vec.yyxw
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # yyyx
    v2 = vec.yyyx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yyyy
    v2 = vec.yyyy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yyyz
    v2 = vec.yyyz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # yyyw
    v2 = vec.yyyw
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # yyzx
    v2 = vec.yyzx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # yyzy
    v2 = vec.yyzy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # yyzz
    v2 = vec.yyzz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # yyzw
    v2 = vec.yyzw
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # yywx
    v2 = vec.yywx
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # yywy
    v2 = vec.yywy
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # yywz
    v2 = vec.yywz
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # yyww
    v2 = vec.yyww
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # yzxx
    v2 = vec.yzxx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # yzxy
    v2 = vec.yzxy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # yzxz
    v2 = vec.yzxz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # yzxw
    v2 = vec.yzxw
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # yzyx
    v2 = vec.yzyx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # yzyy
    v2 = vec.yzyy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # yzyz
    v2 = vec.yzyz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # yzyw
    v2 = vec.yzyw
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # yzzx
    v2 = vec.yzzx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # yzzy
    v2 = vec.yzzy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # yzzz
    v2 = vec.yzzz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # yzzw
    v2 = vec.yzzw
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # yzwx
    v2 = vec.yzwx
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # yzwy
    v2 = vec.yzwy
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # yzwz
    v2 = vec.yzwz
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # yzww
    v2 = vec.yzww
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # ywxx
    v2 = vec.ywxx
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ywxy
    v2 = vec.ywxy
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ywxz
    v2 = vec.ywxz
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ywxw
    v2 = vec.ywxw
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # ywyx
    v2 = vec.ywyx
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # ywyy
    v2 = vec.ywyy
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # ywyz
    v2 = vec.ywyz
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ywyw
    v2 = vec.ywyw
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # ywzx
    v2 = vec.ywzx
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ywzy
    v2 = vec.ywzy
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ywzz
    v2 = vec.ywzz
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ywzw
    v2 = vec.ywzw
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # ywwx
    v2 = vec.ywwx
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # ywwy
    v2 = vec.ywwy
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # ywwz
    v2 = vec.ywwz
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # ywww
    v2 = vec.ywww
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # zxxx
    v2 = vec.zxxx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zxxy
    v2 = vec.zxxy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zxxz
    v2 = vec.zxxz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zxxw
    v2 = vec.zxxw
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # zxyx
    v2 = vec.zxyx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zxyy
    v2 = vec.zxyy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zxyz
    v2 = vec.zxyz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zxyw
    v2 = vec.zxyw
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # zxzx
    v2 = vec.zxzx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zxzy
    v2 = vec.zxzy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zxzz
    v2 = vec.zxzz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zxzw
    v2 = vec.zxzw
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # zxwx
    v2 = vec.zxwx
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # zxwy
    v2 = vec.zxwy
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # zxwz
    v2 = vec.zxwz
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # zxww
    v2 = vec.zxww
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # zyxx
    v2 = vec.zyxx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zyxy
    v2 = vec.zyxy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zyxz
    v2 = vec.zyxz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zyxw
    v2 = vec.zyxw
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # zyyx
    v2 = vec.zyyx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zyyy
    v2 = vec.zyyy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zyyz
    v2 = vec.zyyz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zyyw
    v2 = vec.zyyw
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # zyzx
    v2 = vec.zyzx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zyzy
    v2 = vec.zyzy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zyzz
    v2 = vec.zyzz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zyzw
    v2 = vec.zyzw
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # zywx
    v2 = vec.zywx
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # zywy
    v2 = vec.zywy
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # zywz
    v2 = vec.zywz
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # zyww
    v2 = vec.zyww
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # zzxx
    v2 = vec.zzxx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zzxy
    v2 = vec.zzxy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zzxz
    v2 = vec.zzxz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zzxw
    v2 = vec.zzxw
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # zzyx
    v2 = vec.zzyx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zzyy
    v2 = vec.zzyy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zzyz
    v2 = vec.zzyz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zzyw
    v2 = vec.zzyw
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # zzzx
    v2 = vec.zzzx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zzzy
    v2 = vec.zzzy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zzzz
    v2 = vec.zzzz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zzzw
    v2 = vec.zzzw
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # zzwx
    v2 = vec.zzwx
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # zzwy
    v2 = vec.zzwy
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # zzwz
    v2 = vec.zzwz
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # zzww
    v2 = vec.zzww
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # zwxx
    v2 = vec.zwxx
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # zwxy
    v2 = vec.zwxy
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # zwxz
    v2 = vec.zwxz
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # zwxw
    v2 = vec.zwxw
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # zwyx
    v2 = vec.zwyx
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # zwyy
    v2 = vec.zwyy
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # zwyz
    v2 = vec.zwyz
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # zwyw
    v2 = vec.zwyw
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # zwzx
    v2 = vec.zwzx
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # zwzy
    v2 = vec.zwzy
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # zwzz
    v2 = vec.zwzz
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # zwzw
    v2 = vec.zwzw
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # zwwx
    v2 = vec.zwwx
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # zwwy
    v2 = vec.zwwy
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # zwwz
    v2 = vec.zwwz
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # zwww
    v2 = vec.zwww
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # wxxx
    v2 = vec.wxxx
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # wxxy
    v2 = vec.wxxy
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # wxxz
    v2 = vec.wxxz
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # wxxw
    v2 = vec.wxxw
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # wxyx
    v2 = vec.wxyx
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # wxyy
    v2 = vec.wxyy
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # wxyz
    v2 = vec.wxyz
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # wxyw
    v2 = vec.wxyw
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # wxzx
    v2 = vec.wxzx
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # wxzy
    v2 = vec.wxzy
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # wxzz
    v2 = vec.wxzz
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # wxzw
    v2 = vec.wxzw
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # wxwx
    v2 = vec.wxwx
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # wxwy
    v2 = vec.wxwy
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # wxwz
    v2 = vec.wxwz
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # wxww
    v2 = vec.wxww
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # wyxx
    v2 = vec.wyxx
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # wyxy
    v2 = vec.wyxy
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # wyxz
    v2 = vec.wyxz
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # wyxw
    v2 = vec.wyxw
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # wyyx
    v2 = vec.wyyx
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # wyyy
    v2 = vec.wyyy
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # wyyz
    v2 = vec.wyyz
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # wyyw
    v2 = vec.wyyw
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # wyzx
    v2 = vec.wyzx
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # wyzy
    v2 = vec.wyzy
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # wyzz
    v2 = vec.wyzz
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # wyzw
    v2 = vec.wyzw
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # wywx
    v2 = vec.wywx
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # wywy
    v2 = vec.wywy
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # wywz
    v2 = vec.wywz
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # wyww
    v2 = vec.wyww
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # wzxx
    v2 = vec.wzxx
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # wzxy
    v2 = vec.wzxy
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # wzxz
    v2 = vec.wzxz
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # wzxw
    v2 = vec.wzxw
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # wzyx
    v2 = vec.wzyx
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # wzyy
    v2 = vec.wzyy
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # wzyz
    v2 = vec.wzyz
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # wzyw
    v2 = vec.wzyw
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # wzzx
    v2 = vec.wzzx
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # wzzy
    v2 = vec.wzzy
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # wzzz
    v2 = vec.wzzz
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # wzzw
    v2 = vec.wzzw
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # wzwx
    v2 = vec.wzwx
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # wzwy
    v2 = vec.wzwy
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # wzwz
    v2 = vec.wzwz
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # wzww
    v2 = vec.wzww
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # wwxx
    v2 = vec.wwxx
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # wwxy
    v2 = vec.wwxy
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # wwxz
    v2 = vec.wwxz
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # wwxw
    v2 = vec.wwxw
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # wwyx
    v2 = vec.wwyx
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # wwyy
    v2 = vec.wwyy
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # wwyz
    v2 = vec.wwyz
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # wwyw
    v2 = vec.wwyw
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # wwzx
    v2 = vec.wwzx
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # wwzy
    v2 = vec.wwzy
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # wwzz
    v2 = vec.wwzz
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # wwzw
    v2 = vec.wwzw
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # wwwx
    v2 = vec.wwwx
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # wwwy
    v2 = vec.wwwy
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # wwwz
    v2 = vec.wwwz
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # wwww
    v2 = vec.wwww
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0

def test_vec4_swizzle4_rgba():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # rrrr
    v2 = vec.rrrr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rrrg
    v2 = vec.rrrg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rrrb
    v2 = vec.rrrb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rrra
    v2 = vec.rrra
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # rrgr
    v2 = vec.rrgr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rrgg
    v2 = vec.rrgg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rrgb
    v2 = vec.rrgb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # rrga
    v2 = vec.rrga
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # rrbr
    v2 = vec.rrbr
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rrbg
    v2 = vec.rrbg
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rrbb
    v2 = vec.rrbb
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # rrba
    v2 = vec.rrba
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # rrar
    v2 = vec.rrar
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # rrag
    v2 = vec.rrag
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # rrab
    v2 = vec.rrab
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # rraa
    v2 = vec.rraa
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # rgrr
    v2 = vec.rgrr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rgrg
    v2 = vec.rgrg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rgrb
    v2 = vec.rgrb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rgra
    v2 = vec.rgra
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # rggr
    v2 = vec.rggr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rggg
    v2 = vec.rggg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rggb
    v2 = vec.rggb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # rgga
    v2 = vec.rgga
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # rgbr
    v2 = vec.rgbr
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rgbg
    v2 = vec.rgbg
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rgbb
    v2 = vec.rgbb
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # rgba
    v2 = vec.rgba
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # rgar
    v2 = vec.rgar
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # rgag
    v2 = vec.rgag
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # rgab
    v2 = vec.rgab
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # rgaa
    v2 = vec.rgaa
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # rbrr
    v2 = vec.rbrr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rbrg
    v2 = vec.rbrg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rbrb
    v2 = vec.rbrb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rbra
    v2 = vec.rbra
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # rbgr
    v2 = vec.rbgr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # rbgg
    v2 = vec.rbgg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # rbgb
    v2 = vec.rbgb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # rbga
    v2 = vec.rbga
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # rbbr
    v2 = vec.rbbr
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rbbg
    v2 = vec.rbbg
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rbbb
    v2 = vec.rbbb
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # rbba
    v2 = vec.rbba
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # rbar
    v2 = vec.rbar
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # rbag
    v2 = vec.rbag
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # rbab
    v2 = vec.rbab
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # rbaa
    v2 = vec.rbaa
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # rarr
    v2 = vec.rarr
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # rarg
    v2 = vec.rarg
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # rarb
    v2 = vec.rarb
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # rara
    v2 = vec.rara
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # ragr
    v2 = vec.ragr
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # ragg
    v2 = vec.ragg
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # ragb
    v2 = vec.ragb
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # raga
    v2 = vec.raga
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # rabr
    v2 = vec.rabr
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # rabg
    v2 = vec.rabg
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # rabb
    v2 = vec.rabb
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # raba
    v2 = vec.raba
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # raar
    v2 = vec.raar
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # raag
    v2 = vec.raag
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # raab
    v2 = vec.raab
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # raaa
    v2 = vec.raaa
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # grrr
    v2 = vec.grrr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # grrg
    v2 = vec.grrg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # grrb
    v2 = vec.grrb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # grra
    v2 = vec.grra
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # grgr
    v2 = vec.grgr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # grgg
    v2 = vec.grgg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # grgb
    v2 = vec.grgb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # grga
    v2 = vec.grga
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # grbr
    v2 = vec.grbr
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # grbg
    v2 = vec.grbg
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # grbb
    v2 = vec.grbb
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # grba
    v2 = vec.grba
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # grar
    v2 = vec.grar
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # grag
    v2 = vec.grag
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # grab
    v2 = vec.grab
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # graa
    v2 = vec.graa
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # ggrr
    v2 = vec.ggrr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ggrg
    v2 = vec.ggrg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ggrb
    v2 = vec.ggrb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ggra
    v2 = vec.ggra
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # gggr
    v2 = vec.gggr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # gggg
    v2 = vec.gggg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # gggb
    v2 = vec.gggb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # ggga
    v2 = vec.ggga
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # ggbr
    v2 = vec.ggbr
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ggbg
    v2 = vec.ggbg
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ggbb
    v2 = vec.ggbb
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ggba
    v2 = vec.ggba
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # ggar
    v2 = vec.ggar
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # ggag
    v2 = vec.ggag
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # ggab
    v2 = vec.ggab
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # ggaa
    v2 = vec.ggaa
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # gbrr
    v2 = vec.gbrr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # gbrg
    v2 = vec.gbrg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # gbrb
    v2 = vec.gbrb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # gbra
    v2 = vec.gbra
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # gbgr
    v2 = vec.gbgr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # gbgg
    v2 = vec.gbgg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # gbgb
    v2 = vec.gbgb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # gbga
    v2 = vec.gbga
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # gbbr
    v2 = vec.gbbr
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # gbbg
    v2 = vec.gbbg
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # gbbb
    v2 = vec.gbbb
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # gbba
    v2 = vec.gbba
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # gbar
    v2 = vec.gbar
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # gbag
    v2 = vec.gbag
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # gbab
    v2 = vec.gbab
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # gbaa
    v2 = vec.gbaa
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # garr
    v2 = vec.garr
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # garg
    v2 = vec.garg
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # garb
    v2 = vec.garb
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # gara
    v2 = vec.gara
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # gagr
    v2 = vec.gagr
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # gagg
    v2 = vec.gagg
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # gagb
    v2 = vec.gagb
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # gaga
    v2 = vec.gaga
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # gabr
    v2 = vec.gabr
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # gabg
    v2 = vec.gabg
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # gabb
    v2 = vec.gabb
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # gaba
    v2 = vec.gaba
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # gaar
    v2 = vec.gaar
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # gaag
    v2 = vec.gaag
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # gaab
    v2 = vec.gaab
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # gaaa
    v2 = vec.gaaa
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # brrr
    v2 = vec.brrr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # brrg
    v2 = vec.brrg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # brrb
    v2 = vec.brrb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # brra
    v2 = vec.brra
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # brgr
    v2 = vec.brgr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # brgg
    v2 = vec.brgg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # brgb
    v2 = vec.brgb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # brga
    v2 = vec.brga
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # brbr
    v2 = vec.brbr
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # brbg
    v2 = vec.brbg
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # brbb
    v2 = vec.brbb
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # brba
    v2 = vec.brba
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # brar
    v2 = vec.brar
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # brag
    v2 = vec.brag
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # brab
    v2 = vec.brab
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # braa
    v2 = vec.braa
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # bgrr
    v2 = vec.bgrr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # bgrg
    v2 = vec.bgrg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # bgrb
    v2 = vec.bgrb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # bgra
    v2 = vec.bgra
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # bggr
    v2 = vec.bggr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # bggg
    v2 = vec.bggg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # bggb
    v2 = vec.bggb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # bgga
    v2 = vec.bgga
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # bgbr
    v2 = vec.bgbr
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # bgbg
    v2 = vec.bgbg
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # bgbb
    v2 = vec.bgbb
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # bgba
    v2 = vec.bgba
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # bgar
    v2 = vec.bgar
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # bgag
    v2 = vec.bgag
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # bgab
    v2 = vec.bgab
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # bgaa
    v2 = vec.bgaa
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # bbrr
    v2 = vec.bbrr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # bbrg
    v2 = vec.bbrg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # bbrb
    v2 = vec.bbrb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # bbra
    v2 = vec.bbra
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # bbgr
    v2 = vec.bbgr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # bbgg
    v2 = vec.bbgg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # bbgb
    v2 = vec.bbgb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # bbga
    v2 = vec.bbga
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # bbbr
    v2 = vec.bbbr
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # bbbg
    v2 = vec.bbbg
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # bbbb
    v2 = vec.bbbb
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # bbba
    v2 = vec.bbba
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # bbar
    v2 = vec.bbar
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # bbag
    v2 = vec.bbag
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # bbab
    v2 = vec.bbab
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # bbaa
    v2 = vec.bbaa
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # barr
    v2 = vec.barr
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # barg
    v2 = vec.barg
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # barb
    v2 = vec.barb
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # bara
    v2 = vec.bara
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # bagr
    v2 = vec.bagr
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # bagg
    v2 = vec.bagg
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # bagb
    v2 = vec.bagb
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # baga
    v2 = vec.baga
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # babr
    v2 = vec.babr
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # babg
    v2 = vec.babg
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # babb
    v2 = vec.babb
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # baba
    v2 = vec.baba
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # baar
    v2 = vec.baar
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # baag
    v2 = vec.baag
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # baab
    v2 = vec.baab
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # baaa
    v2 = vec.baaa
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # arrr
    v2 = vec.arrr
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # arrg
    v2 = vec.arrg
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # arrb
    v2 = vec.arrb
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # arra
    v2 = vec.arra
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # argr
    v2 = vec.argr
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # argg
    v2 = vec.argg
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # argb
    v2 = vec.argb
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # arga
    v2 = vec.arga
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # arbr
    v2 = vec.arbr
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # arbg
    v2 = vec.arbg
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # arbb
    v2 = vec.arbb
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # arba
    v2 = vec.arba
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # arar
    v2 = vec.arar
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # arag
    v2 = vec.arag
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # arab
    v2 = vec.arab
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # araa
    v2 = vec.araa
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # agrr
    v2 = vec.agrr
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # agrg
    v2 = vec.agrg
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # agrb
    v2 = vec.agrb
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # agra
    v2 = vec.agra
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # aggr
    v2 = vec.aggr
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # aggg
    v2 = vec.aggg
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # aggb
    v2 = vec.aggb
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # agga
    v2 = vec.agga
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # agbr
    v2 = vec.agbr
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # agbg
    v2 = vec.agbg
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # agbb
    v2 = vec.agbb
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # agba
    v2 = vec.agba
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # agar
    v2 = vec.agar
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # agag
    v2 = vec.agag
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # agab
    v2 = vec.agab
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # agaa
    v2 = vec.agaa
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # abrr
    v2 = vec.abrr
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # abrg
    v2 = vec.abrg
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # abrb
    v2 = vec.abrb
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # abra
    v2 = vec.abra
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # abgr
    v2 = vec.abgr
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # abgg
    v2 = vec.abgg
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # abgb
    v2 = vec.abgb
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # abga
    v2 = vec.abga
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # abbr
    v2 = vec.abbr
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # abbg
    v2 = vec.abbg
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # abbb
    v2 = vec.abbb
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # abba
    v2 = vec.abba
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # abar
    v2 = vec.abar
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # abag
    v2 = vec.abag
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # abab
    v2 = vec.abab
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # abaa
    v2 = vec.abaa
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # aarr
    v2 = vec.aarr
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # aarg
    v2 = vec.aarg
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # aarb
    v2 = vec.aarb
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # aara
    v2 = vec.aara
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # aagr
    v2 = vec.aagr
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # aagg
    v2 = vec.aagg
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # aagb
    v2 = vec.aagb
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # aaga
    v2 = vec.aaga
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # aabr
    v2 = vec.aabr
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # aabg
    v2 = vec.aabg
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # aabb
    v2 = vec.aabb
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # aaba
    v2 = vec.aaba
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # aaar
    v2 = vec.aaar
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # aaag
    v2 = vec.aaag
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # aaab
    v2 = vec.aaab
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # aaaa
    v2 = vec.aaaa
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0

def test_vec4_swizzle4_stpq():
    vec = vec4(1.0, 2.0, 3.0, 4.0)
    # ssss
    v2 = vec.ssss
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ssst
    v2 = vec.ssst
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # sssp
    v2 = vec.sssp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # sssq
    v2 = vec.sssq
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # ssts
    v2 = vec.ssts
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sstt
    v2 = vec.sstt
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sstp
    v2 = vec.sstp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # sstq
    v2 = vec.sstq
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # ssps
    v2 = vec.ssps
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # sspt
    v2 = vec.sspt
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # sspp
    v2 = vec.sspp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # sspq
    v2 = vec.sspq
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # ssqs
    v2 = vec.ssqs
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # ssqt
    v2 = vec.ssqt
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # ssqp
    v2 = vec.ssqp
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # ssqq
    v2 = vec.ssqq
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # stss
    v2 = vec.stss
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # stst
    v2 = vec.stst
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # stsp
    v2 = vec.stsp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # stsq
    v2 = vec.stsq
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # stts
    v2 = vec.stts
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sttt
    v2 = vec.sttt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sttp
    v2 = vec.sttp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # sttq
    v2 = vec.sttq
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # stps
    v2 = vec.stps
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # stpt
    v2 = vec.stpt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # stpp
    v2 = vec.stpp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # stpq
    v2 = vec.stpq
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # stqs
    v2 = vec.stqs
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # stqt
    v2 = vec.stqt
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # stqp
    v2 = vec.stqp
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # stqq
    v2 = vec.stqq
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # spss
    v2 = vec.spss
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # spst
    v2 = vec.spst
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # spsp
    v2 = vec.spsp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # spsq
    v2 = vec.spsq
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # spts
    v2 = vec.spts
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sptt
    v2 = vec.sptt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sptp
    v2 = vec.sptp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # sptq
    v2 = vec.sptq
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # spps
    v2 = vec.spps
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # sppt
    v2 = vec.sppt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # sppp
    v2 = vec.sppp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # sppq
    v2 = vec.sppq
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # spqs
    v2 = vec.spqs
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # spqt
    v2 = vec.spqt
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # spqp
    v2 = vec.spqp
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # spqq
    v2 = vec.spqq
    assert v2.x == 1.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # sqss
    v2 = vec.sqss
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # sqst
    v2 = vec.sqst
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # sqsp
    v2 = vec.sqsp
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # sqsq
    v2 = vec.sqsq
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # sqts
    v2 = vec.sqts
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # sqtt
    v2 = vec.sqtt
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # sqtp
    v2 = vec.sqtp
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # sqtq
    v2 = vec.sqtq
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # sqps
    v2 = vec.sqps
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # sqpt
    v2 = vec.sqpt
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # sqpp
    v2 = vec.sqpp
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # sqpq
    v2 = vec.sqpq
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # sqqs
    v2 = vec.sqqs
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # sqqt
    v2 = vec.sqqt
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # sqqp
    v2 = vec.sqqp
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # sqqq
    v2 = vec.sqqq
    assert v2.x == 1.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # tsss
    v2 = vec.tsss
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # tsst
    v2 = vec.tsst
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # tssp
    v2 = vec.tssp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # tssq
    v2 = vec.tssq
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # tsts
    v2 = vec.tsts
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tstt
    v2 = vec.tstt
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tstp
    v2 = vec.tstp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # tstq
    v2 = vec.tstq
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # tsps
    v2 = vec.tsps
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # tspt
    v2 = vec.tspt
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # tspp
    v2 = vec.tspp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # tspq
    v2 = vec.tspq
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # tsqs
    v2 = vec.tsqs
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # tsqt
    v2 = vec.tsqt
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # tsqp
    v2 = vec.tsqp
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # tsqq
    v2 = vec.tsqq
    assert v2.x == 2.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # ttss
    v2 = vec.ttss
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ttst
    v2 = vec.ttst
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ttsp
    v2 = vec.ttsp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ttsq
    v2 = vec.ttsq
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # ttts
    v2 = vec.ttts
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tttt
    v2 = vec.tttt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tttp
    v2 = vec.tttp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # tttq
    v2 = vec.tttq
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # ttps
    v2 = vec.ttps
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ttpt
    v2 = vec.ttpt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ttpp
    v2 = vec.ttpp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ttpq
    v2 = vec.ttpq
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # ttqs
    v2 = vec.ttqs
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # ttqt
    v2 = vec.ttqt
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # ttqp
    v2 = vec.ttqp
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # ttqq
    v2 = vec.ttqq
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # tpss
    v2 = vec.tpss
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # tpst
    v2 = vec.tpst
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # tpsp
    v2 = vec.tpsp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # tpsq
    v2 = vec.tpsq
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # tpts
    v2 = vec.tpts
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tptt
    v2 = vec.tptt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tptp
    v2 = vec.tptp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # tptq
    v2 = vec.tptq
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # tpps
    v2 = vec.tpps
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # tppt
    v2 = vec.tppt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # tppp
    v2 = vec.tppp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # tppq
    v2 = vec.tppq
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # tpqs
    v2 = vec.tpqs
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # tpqt
    v2 = vec.tpqt
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # tpqp
    v2 = vec.tpqp
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # tpqq
    v2 = vec.tpqq
    assert v2.x == 2.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # tqss
    v2 = vec.tqss
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # tqst
    v2 = vec.tqst
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # tqsp
    v2 = vec.tqsp
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # tqsq
    v2 = vec.tqsq
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # tqts
    v2 = vec.tqts
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # tqtt
    v2 = vec.tqtt
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # tqtp
    v2 = vec.tqtp
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # tqtq
    v2 = vec.tqtq
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # tqps
    v2 = vec.tqps
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # tqpt
    v2 = vec.tqpt
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # tqpp
    v2 = vec.tqpp
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # tqpq
    v2 = vec.tqpq
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # tqqs
    v2 = vec.tqqs
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # tqqt
    v2 = vec.tqqt
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # tqqp
    v2 = vec.tqqp
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # tqqq
    v2 = vec.tqqq
    assert v2.x == 2.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # psss
    v2 = vec.psss
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # psst
    v2 = vec.psst
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # pssp
    v2 = vec.pssp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # pssq
    v2 = vec.pssq
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # psts
    v2 = vec.psts
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pstt
    v2 = vec.pstt
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pstp
    v2 = vec.pstp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # pstq
    v2 = vec.pstq
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # psps
    v2 = vec.psps
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # pspt
    v2 = vec.pspt
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # pspp
    v2 = vec.pspp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # pspq
    v2 = vec.pspq
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # psqs
    v2 = vec.psqs
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # psqt
    v2 = vec.psqt
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # psqp
    v2 = vec.psqp
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # psqq
    v2 = vec.psqq
    assert v2.x == 3.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # ptss
    v2 = vec.ptss
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ptst
    v2 = vec.ptst
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ptsp
    v2 = vec.ptsp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ptsq
    v2 = vec.ptsq
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # ptts
    v2 = vec.ptts
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pttt
    v2 = vec.pttt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pttp
    v2 = vec.pttp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # pttq
    v2 = vec.pttq
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # ptps
    v2 = vec.ptps
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # ptpt
    v2 = vec.ptpt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # ptpp
    v2 = vec.ptpp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # ptpq
    v2 = vec.ptpq
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # ptqs
    v2 = vec.ptqs
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # ptqt
    v2 = vec.ptqt
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # ptqp
    v2 = vec.ptqp
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # ptqq
    v2 = vec.ptqq
    assert v2.x == 3.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # ppss
    v2 = vec.ppss
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # ppst
    v2 = vec.ppst
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # ppsp
    v2 = vec.ppsp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # ppsq
    v2 = vec.ppsq
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # ppts
    v2 = vec.ppts
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pptt
    v2 = vec.pptt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pptp
    v2 = vec.pptp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # pptq
    v2 = vec.pptq
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # ppps
    v2 = vec.ppps
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # pppt
    v2 = vec.pppt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # pppp
    v2 = vec.pppp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # pppq
    v2 = vec.pppq
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # ppqs
    v2 = vec.ppqs
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # ppqt
    v2 = vec.ppqt
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # ppqp
    v2 = vec.ppqp
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # ppqq
    v2 = vec.ppqq
    assert v2.x == 3.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # pqss
    v2 = vec.pqss
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # pqst
    v2 = vec.pqst
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # pqsp
    v2 = vec.pqsp
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # pqsq
    v2 = vec.pqsq
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # pqts
    v2 = vec.pqts
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # pqtt
    v2 = vec.pqtt
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # pqtp
    v2 = vec.pqtp
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # pqtq
    v2 = vec.pqtq
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # pqps
    v2 = vec.pqps
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # pqpt
    v2 = vec.pqpt
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # pqpp
    v2 = vec.pqpp
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # pqpq
    v2 = vec.pqpq
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # pqqs
    v2 = vec.pqqs
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # pqqt
    v2 = vec.pqqt
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # pqqp
    v2 = vec.pqqp
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # pqqq
    v2 = vec.pqqq
    assert v2.x == 3.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # qsss
    v2 = vec.qsss
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # qsst
    v2 = vec.qsst
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # qssp
    v2 = vec.qssp
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # qssq
    v2 = vec.qssq
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # qsts
    v2 = vec.qsts
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # qstt
    v2 = vec.qstt
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # qstp
    v2 = vec.qstp
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # qstq
    v2 = vec.qstq
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # qsps
    v2 = vec.qsps
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # qspt
    v2 = vec.qspt
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # qspp
    v2 = vec.qspp
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # qspq
    v2 = vec.qspq
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # qsqs
    v2 = vec.qsqs
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # qsqt
    v2 = vec.qsqt
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # qsqp
    v2 = vec.qsqp
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # qsqq
    v2 = vec.qsqq
    assert v2.x == 4.0
    assert v2.y == 1.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # qtss
    v2 = vec.qtss
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # qtst
    v2 = vec.qtst
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # qtsp
    v2 = vec.qtsp
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # qtsq
    v2 = vec.qtsq
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # qtts
    v2 = vec.qtts
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # qttt
    v2 = vec.qttt
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # qttp
    v2 = vec.qttp
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # qttq
    v2 = vec.qttq
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # qtps
    v2 = vec.qtps
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # qtpt
    v2 = vec.qtpt
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # qtpp
    v2 = vec.qtpp
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # qtpq
    v2 = vec.qtpq
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # qtqs
    v2 = vec.qtqs
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # qtqt
    v2 = vec.qtqt
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # qtqp
    v2 = vec.qtqp
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # qtqq
    v2 = vec.qtqq
    assert v2.x == 4.0
    assert v2.y == 2.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # qpss
    v2 = vec.qpss
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # qpst
    v2 = vec.qpst
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # qpsp
    v2 = vec.qpsp
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # qpsq
    v2 = vec.qpsq
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # qpts
    v2 = vec.qpts
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # qptt
    v2 = vec.qptt
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # qptp
    v2 = vec.qptp
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # qptq
    v2 = vec.qptq
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # qpps
    v2 = vec.qpps
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # qppt
    v2 = vec.qppt
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # qppp
    v2 = vec.qppp
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # qppq
    v2 = vec.qppq
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # qpqs
    v2 = vec.qpqs
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # qpqt
    v2 = vec.qpqt
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # qpqp
    v2 = vec.qpqp
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # qpqq
    v2 = vec.qpqq
    assert v2.x == 4.0
    assert v2.y == 3.0
    assert v2.z == 4.0
    assert v2.w == 4.0
    # qqss
    v2 = vec.qqss
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 1.0
    # qqst
    v2 = vec.qqst
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 2.0
    # qqsp
    v2 = vec.qqsp
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 3.0
    # qqsq
    v2 = vec.qqsq
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 1.0
    assert v2.w == 4.0
    # qqts
    v2 = vec.qqts
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 1.0
    # qqtt
    v2 = vec.qqtt
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 2.0
    # qqtp
    v2 = vec.qqtp
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 3.0
    # qqtq
    v2 = vec.qqtq
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 2.0
    assert v2.w == 4.0
    # qqps
    v2 = vec.qqps
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 1.0
    # qqpt
    v2 = vec.qqpt
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 2.0
    # qqpp
    v2 = vec.qqpp
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 3.0
    # qqpq
    v2 = vec.qqpq
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 3.0
    assert v2.w == 4.0
    # qqqs
    v2 = vec.qqqs
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 1.0
    # qqqt
    v2 = vec.qqqt
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 2.0
    # qqqp
    v2 = vec.qqqp
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 3.0
    # qqqq
    v2 = vec.qqqq
    assert v2.x == 4.0
    assert v2.y == 4.0
    assert v2.z == 4.0
    assert v2.w == 4.0
