//{ Driver Code Starts
import java.io.*;
import java.util.*;


class IntArray
{
    public static int[] input(BufferedReader br, int n) throws IOException
    {
        String[] s = br.readLine().trim().split(" ");
        int[] a = new int[n];
        for(int i = 0; i < n; i++)
            a[i] = Integer.parseInt(s[i]);
        
        return a;
    }
    
    public static void print(int[] a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
    
    public static void print(ArrayList<Integer> a)
    {
        for(int e : a)
            System.out.print(e + " ");
        System.out.println();
    }
}

class GFG {
    public static void main(String[] args) throws IOException {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        int t;
        t = Integer.parseInt(br.readLine());
        while(t-- > 0){
            
            int[] a = IntArray.input(br, 3);
            
            
            int[] S1 = IntArray.input(br, a[0]);
            
            
            int[] S2 = IntArray.input(br, a[1]);
            
            
            int[] S3 = IntArray.input(br, a[2]);
            
            Solution obj = new Solution();
            int res = obj.maxEqualSum(a[0],a[1],a[2], S1, S2, S3);
            
            System.out.println(res);
            
        }
    }
}

// } Driver Code Ends


class Solution {
    public static int maxEqualSum(int N1,int N2,int N3, int[] S1, int[] S2, int[] S3) {
                Map<Integer, Integer> mp = new HashMap<>();
        int sum = 0;
        for (int i = N1 - 1; i >= 0; i--) {
            sum += S1[i];
            mp.put(sum, mp.getOrDefault(sum, 0) + 1);
        }

        sum = 0;
        for (int i = N2 - 1; i >= 0; i--) {
            sum += S2[i];
            if (mp.containsKey(sum)) {
                mp.put(sum, mp.get(sum) + 1);
            }
        }

        sum = 0;
        int ans = 0;
        for (int i = N3 - 1; i >= 0; i--) {
            sum += S3[i];
            if (mp.containsKey(sum) && mp.get(sum) == 2) {
                ans = sum;
            }
        }
        return ans;
    }
}
        
