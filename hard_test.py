import sys
import os

i = 0
flags = ['-h', '--help', '--flow-one', '--flow-ten', '--flow-thousand', '--big', '--big-superposition']
flag = sys.argv[1]
if flag in ('--help', '-h') or flag not in flags:
    os.system('./generator.dms --help')
    sys.exit()
test = 'lem_in_tests.py'
while i <= 100:
    print ("\033[93m%s\033[0m" % i)
    os.system('python3 %s %s' % (test, flag))
    i += 1
