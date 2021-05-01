package main

import "fmt"

func merge(arr []int, lidx int, mid int, ridx int) {

	n1 := mid - lidx + 1
	n2 := ridx - mid

	ar1 := make([]int, n1)
	ar2 := make([]int, n2)

	for idx, _ := range ar1 {
		ar1[idx] = arr[lidx+idx]
	}

	for idx, _ := range ar2 {
		ar2[idx] = arr[mid+1+idx]
	}

	//copy(ar1, arr[lidx:mid])
	//copy(ar2, arr[mid+1:ridx])

	l_ptr := 0
	r_ptr := 0
	ptr := lidx

	for l_ptr < n1 && r_ptr < n2 {

		if ar1[l_ptr] < ar2[r_ptr] {
			arr[ptr] = ar1[l_ptr]
			l_ptr++
		} else {
			arr[ptr] = ar2[r_ptr]
			r_ptr++
		}
		ptr++
	}

	if l_ptr >= n1 {
		for r_ptr < n2 {
			arr[ptr] = ar2[r_ptr]
			ptr++
			r_ptr++
		}
	}

	if r_ptr >= n2 {
		for l_ptr < n1 {
			arr[ptr] = ar1[l_ptr]
			ptr++
			l_ptr++
		}
	}
}

func mergesort(arr []int, lidx int, ridx int) {

	if lidx < ridx {
		mid := lidx + ((ridx - lidx) / 2)

		mergesort(arr[:], lidx, mid)
		mergesort(arr[:], mid+1, ridx)

		merge(arr[:], lidx, mid, ridx)
	}
}

func main() {

	arr := [11]int{1, 4, 16, 29, 46, 53, 67, 88, 56, 43, 39}

	mergesort(arr[:], 0, len(arr)-1)

	fmt.Println(arr)

}
