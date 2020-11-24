# -*- coding: utf-8 -*-
import pytest
import numpy as np
from point import Point

# IEEE754
# 0.1 (10) = 0.000110011001100...
# float (simple precision), mantisse 23 bits
# double (double precision), mantisse 52 bits
# valeur exacte: 3.5, 3.25, 3.75, 3.125, .

def test_classic_distance():
    # given
    p1 = Point(2, 4)
    p2 = Point(6, 1)
    # when/test
    common_distance(p1, p2, 5)
 
def test_big_distance_numpy():
    # given
    p1 = Point(np.uint8(255), np.uint8(0))
    p2 = Point(np.uint8(0), np.uint8(0))
    # when/test
    common_distance(p1, p2, 255)

def test_big_distance_double():
    # given
    p1 = Point(1E307, 1E307)
    p2 = Point(4E307, 5E307)
    # when/test
    common_distance(p1, p2, 5E307)

def common_distance(p1, p2, expected_distance):
    # when
    d = p1.distance(p2)
    # then
    assert d==expected_distance
    


