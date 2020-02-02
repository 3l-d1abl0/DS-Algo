if __name__=="__main__":
    case = int(raw_input())
    #print case
    for i in xrange(case):
        N, pos = raw_input().split(" ")
        N = int(N)
        pos = pos.strip("(").strip(")")
        pos = map(int, pos.split(","))

        #print N
        #print pos

        mov = 2*N-2
        mov += min(N-pos[0], N-pos[1]) +min(pos[0]-1, pos[1]-1)
        mov += min(pos[0]-1, N-pos[1]) + min(N-pos[0],pos[1]-1)


        print N*N -mov
