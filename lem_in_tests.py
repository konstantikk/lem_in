import sys
import os

flag = sys.argv[1]

test_file = 'konstantikk_test_file.txt'

os.system('./generator.dms %s > %s' % (flag, test_file))
# graph = dict()
start_flag = False
end_flag = False
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
print(nodes)

#     for x in inp:
#         if x.isnumeric():
#
#         if '#Here' in x:
#             print (x)
#             continue
#         if "##start" in x:
#             start_flag = True
#             continue
#         elif "##end" in x:
#             end_flag = True
#             continue
#         elif ' ' in x:
#             if start_flag:
#                 x = x.partition(' ')
#                 graph.setdefault(x[0], [])
#                 start = x[0]
#                 start_flag = False
#                 continue
#             elif end_flag:
#                 x = x.partition(' ')
#                 graph.setdefault(x[0], [])
#                 end = x[0]
#                 end_flag =  False
#                 continue
#             x = x.partition(' ')
#             graph.setdefault(x[0], [])#graph[x[0]] = list()
#          #  print(x)
#         elif '-' in x:
#             x = x.partition('-')
#             graph[x[0]].append(x[2])
#             graph[x[2]].append(x[0])
# print(graph)
# print (start, end)
# test2_file = "tests"
# os.system('./lem-in < %s > %s'% (test_file, test2_file))
# with open(test2_file, 'r') as f:
#     inp = f.read().split('\n')
#     for x in inp:

