#! /usr/bin/env python3
import re

red_max = 12
green_max = 13
blue_max = 14
id = 1
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
                if info[1] == 'red' and int(info[0]) > red_max:
                    break
                elif info[1] == 'green' and int(info[0]) > green_max:
                    break
                elif info[1] == 'blue' and int(info[0]) > blue_max:
                    break
            else:
                continue
            break
        else:
            sum += id
        id += 1

print(sum)
