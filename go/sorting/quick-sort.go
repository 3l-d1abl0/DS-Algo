package main

import (
	"fmt"
	"math/rand"
)

func partition(arr []int, lidx int, ridx int) int {

	//fmt.Printf("l=%d r=%d\n", lidx, ridx)

	random_index := lidx + rand.Intn(ridx-lidx+1)
	arr[lidx], arr[random_index] = arr[random_index], arr[lidx]
	pivot_val := arr[lidx]

	l_ptr := lidx
	r_ptr := ridx

	for l_ptr < r_ptr {

		for l_ptr <= ridx && arr[l_ptr] <= pivot_val {
			l_ptr++
		}

		for r_ptr >= lidx && arr[r_ptr] > pivot_val {
			r_ptr--
		}

		if l_ptr < r_ptr {
			arr[l_ptr], arr[r_ptr] = arr[r_ptr], arr[l_ptr]
		}
	}

	arr[lidx], arr[r_ptr] = arr[r_ptr], arr[lidx]

	return r_ptr
}

func quicksort(arr []int, lidx int, ridx int) {

	if lidx < ridx {

		part := partition(arr[:], lidx, ridx)

		quicksort(arr[:], lidx, part-1)
		quicksort(arr[:], part+1, ridx)

	}
}

func main() {

	arr := [11]int{1, 4, 16, 29, 46, 53, 67, 88, 56, 43, 39}

	quicksort(arr[:], 0, len(arr)-1)

	fmt.Println(arr)

}
