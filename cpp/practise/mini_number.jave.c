
import java.util.*;
class TestClass
{
    public static long find_max(int[] arr, int start, int end){
        long tempMax= -999999999;
        for(int i=start; i<end; i++){
            tempMax = Math.max(arr[i], tempMax);
        }

        return tempMax;
    }

	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		Scanner s = new Scanner(System.in);
		int numtest = s.nextInt();
		int n,k,q;
		n = s.nextInt();
		k = s.nextInt();
		q = s.nextInt();

		int a[] = new int[n];
		int mini = 0;


		int x= n/k;


		for(int i = 0; i<n; ++i)
		{
			a[i] = s.nextInt();
		}

		long ans= 999999999;
		for(int i=0; i<n; i+=x){

		    long max= find_max(a,i,i+x);
		    if(ans>max)
		        ans=max;
		}

		if( ans<q)
		{
				System.out.println(ans);

		}
		else
		{
			System.out.println("NO");
		}

	}
}
