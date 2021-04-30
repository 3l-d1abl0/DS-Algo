package main

import (
	"fmt"
)

// Given two strings A and B return the length of longest common substring of the two strings

func max(a, b uint8) uint8 {
	if a > b {
		return a
	}
	return b
}

func lcs(A string, B string) uint8 {

	dp := make([][]uint8, len(A)+1)
	for i := range dp {
		dp[i] = make([]uint8, len(B)+1)
	}

	for i := range dp {
		for j := range dp[i] {

			if i == 0 || j == 0 {
				continue
			}

			if A[i-1] == B[j-1] {
				dp[i][j] = dp[i-1][j-1] + 1
			} else {
				dp[i][j] = max(dp[i-1][j], dp[i][j-1])
			}
		}
	}

	return dp[len(A)][len(B)]
}

func main() {

	var A string //aggtab abcdgh
	var B string //gxtxayb aedfhr

	fmt.Scanf("%s", &A)
	fmt.Scanf("%s", &B)

	fmt.Printf("Longest common substring of %s and %s = %d\n", A, B, lcs(A, B))

}
