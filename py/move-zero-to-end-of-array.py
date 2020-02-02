def moveZeroRight(arr):

    l = len(arr)

    z_index =0;
    for idx in range(l):
        if arr[idx] !=0:
            arr[idx],arr[z_index] = arr[z_index],arr[idx]
            z_index+=1


def moveZeroLeft(arr):

    l = len(arr)

    z_index = l-1
    for idx in range(l-1,-1,-1):
        if arr[idx] != 0:
            arr[idx], arr[z_index] = arr[z_index], arr[idx]
            z_index -=1;


if __name__ == '__main__':

    arr = [1, 0, 2, 0, 0, 0, 3, 6]
    moveZeroRight(arr)
    print(arr)

    arr = [1, 0, 2, 0, 0, 0, 3, 6]
    moveZeroLeft(arr)
    print(arr)
