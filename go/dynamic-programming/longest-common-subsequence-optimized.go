package main

import("fmt")

func max(lenA , lenB uint8) uint8{
	if lenA > lenB{
		return lenA
	}
	return lenB
}

func lcsOptimized(A, B string) uint8{

	dp := make([][]uint8, 2)
	dp[0] = make([]uint8, len(B)+1)
	dp[1] = make([]uint8, len(B)+1)

	var idx bool

	for i := range A{

		//idx = bool(i&1)
		if i%2==0{
			idx = true
		}else{
			idx = false
		}
		for j := range B{

			if(i==0 || j==0){
				dp[int(idx)][j]=0
			}

			if A[i-1] == B[j-1]{
				dp[idx][j] = dp[1-idx][j-1] +1
			}else{
				dp[idx][j] = max(dp[i-idx][j], dp[idx][j-1])
			}
		}

	}

	return dp[idx][len(B)];
}

func main(){

	var A string
	var B string

	fmt.Scanf("%s", &A);
	fmt.Scanf("%s", &B);

	fmt.Println("LCS :: ", lcsOptimized(A, B))
}