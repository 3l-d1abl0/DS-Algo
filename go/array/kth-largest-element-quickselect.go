package main

import "math/rand"

func partition(arr []int, lidx int, ridx int) int {

	//fmt.Printf("l=%d r=%d\n", lidx, ridx)

	random_index := lidx + rand.Intn(ridx-lidx+1)
	pivotVal := arr[random_index]
	arr[random_index], arr[ridx] = arr[ridx], arr[random_index]

	swapIdx := lidx

	for idx := lidx; idx < ridx; idx++ {

		if arr[idx] < pivotVal {
			arr[idx], arr[swapIdx] = arr[swapIdx], arr[idx]
			swapIdx++
		}
	}

	arr[swapIdx], arr[ridx] = arr[ridx], arr[swapIdx]

	return swapIdx
}

func quicksort(arr []int, k int, lidx int, ridx int) int {

	k = len(arr) - k
	part := partition(arr[:], lidx, ridx)

	for part != k {

		if part > k {

			part = partition(arr[:], 0, part-1)
		} else {
			part = partition(arr[:], part+1, ridx)
		}
	}

	return arr[part]

}

func findKthLargest(nums []int, k int) int {

	return quicksort(nums[:], k, 0, len(nums)-1)

	//return nums[k]
}
