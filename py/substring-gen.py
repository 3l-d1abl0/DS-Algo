def get_all_substrings(string):
    length = len(string)
    for i in xrange(length):
        for j in xrange(i + 1, length + 1):
            yield(string[i:j])

for i in get_all_substrings("abcde"):
    print i
