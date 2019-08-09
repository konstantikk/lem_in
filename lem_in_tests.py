import sys
import os
from time import time

flags = ['-h', '--help', '--flow-one', '--flow-ten', '--flow-thousand', '--big', '--big-superposition']
valid = True
flag = sys.argv[1]
if flag in ('--help', '-h') or flag not in flags:
    os.system('./generator.dms --help')
    sys.exit()
test = 'lem_in_output.txt'
test_file = 'lem_in_input.txt'
os.system('./generator.dms %s > %s ' % (flag, test_file))
timer = time()
os.system('./lem-in < %s > %s' % (test_file, test))
timer = time() - timer
with open(test_file, 'r') as f:
    inp = f.read().split('\n')

ants_count, steps_count, graph = int(inp[0]), int(inp[1].partition(': ')[2]), [i for i in inp[2:] if i.count('#') != 1 and i != ""]
nodes = [line.split(' ')[0] for line in graph if '-' not in line]
start = nodes[nodes.index('##start') + 1]
end = nodes[nodes.index('##end') + 1]
nodes.remove('##start')
nodes.remove('##end')
nodes = {i: [] for i in nodes}

for line in graph[len(nodes) + 2:]:
    part_line = line.partition('-')
    nodes[part_line[0]].append(part_line[2])
    nodes[part_line[2]].append(part_line[0])

ants_in_node = nodes.fromkeys(nodes.keys(), 0)
ants_in_node[start] = ants_count
ants = dict()

with open(test, 'r') as f:
    inp = f.read().split('\n')

if inp[-1]:
    valid = False
    print('\033[91m%s\033[0m' % "Error. no \\n at the end of output.")
else:
    inp = inp[:-1]

for index_line, line in enumerate(inp):
    for index_step, step in enumerate(line.split()):
        ant, next_node = step.partition('-')[::2]
        if ant not in ants:
            ants[ant] = start
        ants_in_node[ants[ant]] -= 1
        if next_node in nodes[ants[ant]]:
            ants[ant] = next_node
            ants_in_node[next_node] += 1
        else:
            print("In line: %d step: %d\n\033[91m%s\033[0m " %
                  (index_line, index_step, 'Error. Incorrect link'))
            sys.exit(' '.join(['\033[93m%s\033[0m' % s if i == index_step else s
                               for i, s in enumerate(line.split())]))
        if ants_in_node[next_node] != 1 and next_node != end:
            print("In line: %d step: %d\n\033[91m%s\033[0m " %
                  (index_line, index_step, 'Error. Node overflow'))
            sys.exit(' '.join(['\033[93m%s\033[0m' % s if i == index_step else s
                               for i, s in enumerate(line.split())]))
if ants_in_node[start] != 0:
    sys.exit('\033[91m%s\033[0m' % 'Error. %d ants in start in the end of the game' % ants_in_node[start])

if ants_in_node[end] != ants_count:
    sys.exit('\033[91m%s\033[0m' % "Error. %d ants did't reach the finish" % (ants_count - ants_in_node[end]))

if valid:
    print("\033[92m%s\033[0m" % "Valid output")
print("time:", ("\033[92m%s\033[0m" if timer < 3 else "\033[91m%s\033[0m") %
      timer)
print("steps:", ("\033[92m%s(%s)\033[0m" if steps_count - len(inp) <= 0 else "\033[91m%s(%s)\033[0m") %
      (len(inp), steps_count))


