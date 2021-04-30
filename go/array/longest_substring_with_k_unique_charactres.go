//given a string , find the longest substring with exactly 'k' unique characters.

package main

import "fmt"

func memsetArray(a []int, v int) {
	if len(a) == 0 {
		return
	}
	a[0] = v
	for bp := 1; bp < len(a); bp *= 2 {
		copy(a[bp:], a[:bp])
	}
}

func is_k(freq []int, K int) bool {

	var cnt int
	for _, val := range freq {

		if val > 0 {
			cnt++
		}
	}

	if cnt > K {
		return false
	} else {
		return true
	}
}

func getUniqueSub(str string, k int) {
	l := len(str)

	var freq [26]int
	uniqueChar := 0

	for idx, _ := range str {

		if freq[str[idx]-'a'] == 0 {
			uniqueChar++

		}
		freq[str[idx]-'a']++

	}

	if uniqueChar < k {
		fmt.Println("Number of Unique characters less than k( %d )", k)
		return
	}

	//memset the frequency array
	memsetArray(freq[:], 0)

	start_pointer := 0
	end_pointer := 0

	window_size := 1
	window_start := 0

	freq[str[0]-'a'] = 1

	for i := 1; i < l; i++ {

		freq[str[i]-'a']++
		end_pointer++

		for is_k(freq[:], k) == false { //while unique char count is >26 keep shortening window from back
			freq[str[start_pointer]-'a']--
			start_pointer++
		}

		if window_size < (end_pointer - start_pointer + 1) {
			window_size = end_pointer - start_pointer + 1
			window_start = start_pointer
		}

	}

	fmt.Println(str[window_start : window_start+window_size])
}

func main() {

	str := "aabbcc"
	k := 4

	fmt.Printf("Input String = %s\n", str)
	fmt.Printf("Unique Characters = %d\n", k)

	getUniqueSub(str, k)

}
