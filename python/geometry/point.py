# -*- coding: utf-8 -*-
import math

class Point:
    
    def __init__(self,x,y):
        self.x = x
        self.y = y
        
    def distance(self, other):
        return math.hypot(
            self.x - other.x,
            self.y - other.y)
        # return math.sqrt(
        #     (self.x - other.x)**2
        #     +(self.y - other.y)**2
        #     )