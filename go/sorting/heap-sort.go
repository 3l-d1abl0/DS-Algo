package main

import "fmt"

func heapify(arr []int, idx int, N int) {

	root := idx
	for root*2+1 < N {

		child := root*2 + 1

		if child+1 < N && arr[child+1] > arr[child] {
			child++
		}

		if arr[child] > arr[root] {
			arr[child], arr[root] = arr[root], arr[child]

			root = child
		} else {
			return
		}
	}
}

func sortHeap(arr []int, lidx int, ridx int) {

	for idx := ridx; idx > 0; idx-- {
		arr[0], arr[idx] = arr[idx], arr[0]
		heapify(arr[:], 0, idx)
	}

}

func buildHeap(arr []int, lidx int, ridx int) {

	//start from last iternal node
	N := ridx + 1

	for idx := (N - 2) / 2; idx >= 0; idx-- {
		heapify(arr[:], idx, N)
	}
}

func heapsort(arr []int, lidx int, ridx int) {

	buildHeap(arr[:], lidx, ridx)
	sortHeap(arr[:], lidx, ridx)
}

func main() {

	arr := [11]int{1, 4, 16, 29, 46, 53, 67, 88, 56, 43, 39}

	heapsort(arr[:], 0, len(arr)-1)

	fmt.Println(arr)

}
