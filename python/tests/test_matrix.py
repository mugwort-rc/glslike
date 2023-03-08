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

import pytest

from glslike import *


def test_mat2_identity():
    v = vec2(1.0, 2.0)
    m = mat2()
    v2 = m * v
    assert v2.x == 1.0
    assert v2.y == 2.0

    with pytest.raises(TypeError):
        e = v * m


def test_mat3_identity():
    v = vec3(1.0, 2.0, 3.0)
    m = mat3()
    v2 = m * v
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0

    with pytest.raises(TypeError):
        e = v * m


def test_mat4_identity():
    v = vec4(1.0, 2.0, 3.0, 4.0)
    m = mat4()
    v2 = m * v
    assert v2.x == 1.0
    assert v2.y == 2.0
    assert v2.z == 3.0
    assert v2.w == 4.0

    with pytest.raises(TypeError):
        e = v * m
