# -*- coding: utf-8 -*-
#
# Copyright 2022 mugwort_rc.
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#    http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.
#

from glslike import *


def test_add_vec2():
    v = vec2(1.0)
    v2 = v + 1
    assert v2.x == 2.0
    assert v2.y == 2.0


def test_sub_vec2():
    v = vec2(1.0)
    v2 = v - 1
    assert v2.x == 0.0
    assert v2.y == 0.0


def test_mul_vec2():
    v = vec2(1.0)
    v2 = v * 2
    assert v2.x == 2.0
    assert v2.y == 2.0


def test_div_vec2():
    v = vec2(2.0)
    v2 = v / 2.0
    assert v2.x == 1.0
    assert v2.y == 1.0


def test_add_vec3():
    v = vec3(1.0)
    v2 = v + 1
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0


def test_sub_vec3():
    v = vec3(1.0)
    v2 = v - 1
    assert v2.x == 0.0
    assert v2.y == 0.0
    assert v2.z == 0.0


def test_mul_vec3():
    v = vec3(1.0)
    v2 = v * 2
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0


def test_div_vec3():
    v = vec3(2.0)
    v2 = v / 2.0
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0


def test_add_vec4():
    v = vec4(1.0)
    v2 = v + 1
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0


def test_sub_vec4():
    v = vec4(1.0)
    v2 = v - 1
    assert v2.x == 0.0
    assert v2.y == 0.0
    assert v2.z == 0.0
    assert v2.w == 0.0


def test_mul_vec4():
    v = vec4(1.0)
    v2 = v * 2
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0


def test_div_vec4():
    v = vec4(2.0)
    v2 = v / 2.0
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0


def test_radd_vec2():
    v = vec2(1.0)
    v2 = 1 + v
    assert v2.x == 2.0
    assert v2.y == 2.0


def test_rsub_vec2():
    v = vec2(1.0)
    v2 = 1 - v
    assert v2.x == 0.0
    assert v2.y == 0.0


def test_rmul_vec2():
    v = vec2(1.0)
    v2 = 2 * v
    assert v2.x == 2.0
    assert v2.y == 2.0


def test_rdiv_vec2():
    v = vec2(2.0)
    v2 = 2.0 / v
    assert v2.x == 1.0
    assert v2.y == 1.0


def test_radd_vec3():
    v = vec3(1.0)
    v2 = 1 + v
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0


def test_rsub_vec3():
    v = vec3(1.0)
    v2 = 1 - v
    assert v2.x == 0.0
    assert v2.y == 0.0
    assert v2.z == 0.0


def test_rmul_vec3():
    v = vec3(1.0)
    v2 = 2 * v
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0


def test_rdiv_vec3():
    v = vec3(2.0)
    v2 = 2.0 / v
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0


def test_radd_vec4():
    v = vec4(1.0)
    v2 = 1 + v
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0


def test_rsub_vec4():
    v = vec4(1.0)
    v2 = 1 - v
    assert v2.x == 0.0
    assert v2.y == 0.0
    assert v2.z == 0.0
    assert v2.w == 0.0


def test_rmul_vec4():
    v = vec4(1.0)
    v2 = 2 * v
    assert v2.x == 2.0
    assert v2.y == 2.0
    assert v2.z == 2.0
    assert v2.w == 2.0


def test_rdiv_vec4():
    v = vec4(2.0)
    v2 = 2.0 / v
    assert v2.x == 1.0
    assert v2.y == 1.0
    assert v2.z == 1.0
    assert v2.w == 1.0
