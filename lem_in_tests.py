import sys
import os

flag = sys.argv[1]

test_file = 'konstantikk_test_file.txt'

os.system('./generator.dms %s > %s' % (flag, test_file))
graph = dict()
with open(test_file, 'r') as f:
    inp = f.read().split('\n')
    for x in inp:
        if ' ' in x:
            x.partition(' ')
            dict['x'] = 0
         #   print(x)
        elif '-' in x:
            x = x.partition('-')
            dict['x[0]'] += [x[2]]
            dict['x[2]'] += [x[0]]
          #  print (x[0], x[2])
        elif "##start" in x:
            x.readline()
            x.partition(' ')
            print("Start :".x)
        elif "##end" in x:
            x.readline()
            x.partition(' ')
            print("End :".x)