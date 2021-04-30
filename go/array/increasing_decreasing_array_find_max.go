package main

import (
	"fmt"
	"math"
)

func max(a *int, b *int) int {

	if *a > *b {
		return *a
	} else {
		return *b
	}
}

func search(arr []int, first int, last int) int {
	fmt.Println("first =", first, " last= ", last)
	for first <= last {

		if first == last {
			return arr[first]
		} else if first == last-1 {
			return max(&arr[first], &arr[last]) // arr[first]>arr[last]?arr[first]:arr[last]
		} else {

			mid := first + (last-first)/2
			fmt.Println("mid = ", mid)

			if arr[mid-1] < arr[mid] && arr[mid] > arr[mid+1] {
				return arr[mid]
			} else if arr[mid-1] < arr[mid] && arr[mid] < arr[mid+1] {
				first = mid + 1
			} else if arr[mid-1] > arr[mid] && arr[mid] > arr[mid+1] {
				last = mid - 1
			} else {

				//fmt.Println("Return 1")
				return math.MaxInt64
			}
		}

	}
	fmt.Println("Return 2")
	return math.MaxInt64

}

func solve(arr []int, size int) {

	//Modified binary Search
	result := search(arr, 0, len(arr)-1)
	if math.MaxInt64 == result {
		fmt.Println("No max number found")
	} else {
		fmt.Println("Max Number = ", result)
	}

}

func main() {

	//var arr [11]int
	arr := [11]int{1, 4, 16, 29, 46, 53, 67, 88, 56, 43, 39}

	solve(arr[:], len(arr))
}
