def get_all_substrings(string):
  length = len(string)
  alist = []
  for i in xrange(length):
    for j in xrange(i,length):
      alist.append(string[i:j + 1])
  return alist

def get_all_substrings_1(input_string):
  length = len(input_string)
  return [input_string[i:j + 1] for i in xrange(length) for j in xrange(i,length)]

from timeit import timeit
print timeit("get_all_substrings('abcde')", "from __main__ import get_all_substrings")
# 3.33308315277
print timeit("get_all_substrings_1('abcdesdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfsdfdsf')", "from __main__ import get_all_substrings_1")
# 2.67816185951
