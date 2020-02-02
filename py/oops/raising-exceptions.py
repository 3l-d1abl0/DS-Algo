def make_delim_line(list_to_join, delim):

    try:
        formatted_line = delim.join(list_to_join)
    except TypeError, e:
        print(e.message)
        print(e.args)
        raise TypeError('make_delim_line(): arg 1 must be a list or tuple')

    return formatted_line

fline = make_delim_line(100, ',')
