t = int(input())
for x in range(t):

    q = int(input())

    freq_count = {}
    top_count = 0
    toplist= []

    for y in range(q):

        name = input()

        if name == "top":
            toplist.sort()
            #print (*toplist)
            print(' '.join(toplist))
        else:

            name, qty = name.split()

            if name in freq_count:
                freq_count[name] += int(qty)
            else:
                freq_count[name] = int(qty)

            if freq_count[name] > top_count:
                top_count = freq_count[name]
                toplist = [name]
            elif freq_count[name] ==top_count:
                toplist.append(name)
            else:
                pass
