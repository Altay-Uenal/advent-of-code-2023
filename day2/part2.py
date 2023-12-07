#! /usr/bin/env python3
import re

curr_red = 0
curr_green = 0
curr_blue = 0
sum = 0

with open('input') as f:
    for line in f:
        line = re.sub(r'^.*?:', '', line)
        line = line.strip()
        rounds = line.split(';')
        for round in rounds:
            cubes = round.split(',')
            for cube in cubes:
                cube = cube.strip()
                info = cube.split(' ')
                if info[1] == 'red':
                    if int(info[0]) > curr_red:
                        curr_red = int(info[0])
                elif info[1] == 'green':
                    if int(info[0]) > curr_green:
                        curr_green = int(info[0])
                elif info[1] == 'blue':
                    if int(info[0]) > curr_blue:
                        curr_blue = int(info[0])
        sum += (curr_red * curr_green * curr_blue)
        curr_red = 0
        curr_green = 0
        curr_blue = 0

print(sum)
