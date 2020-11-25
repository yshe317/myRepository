class Solution {
    public int[] maxNumber(int[] n1, int[] n2, int k) {
        int m = n1.length;
        int n = n2.length;
        int s = Math.max(0, k - n);
        int e = Math.min(m, k);
        int[] res = new int[k];
        for (int i = s; i <= e; i++){
            int[] curr = merge( mx(n1, i), mx(n2, k - i), k);
            if (larger(curr, 0, res, 0)) res = curr;
        }
        return res;
    }
    

    
    private int[] merge(int[] a, int[] b, int cnt){
        int[] res = new int[cnt];
        // int i = 0, j = 0, k = 0;
        for (int i = 0, j = 0, r = 0; r < cnt; ++r)
            res[r] = larger(a, i, b, j) ? a[i++] : b[j++];   //the choice not only depends curr val, but also the val afterwards.
        return res;
    }
    



    private boolean larger(int[] a, int i, int[] b, int j){
        while (i < a.length && j < b.length && a[i] == b[j]) {
            i++;
            j++;
        }
        return j == b.length || i < a.length && a[i] > b[j];
    }
    


    //
    private int[] mx(int[] arr, int cnt) {
        int[] res = new int[cnt];
        int j = 0;
        for (int i = 0; i < arr.length; i++) {
            while (arr.length - i > cnt - j && j > 0 && res[j - 1] < arr[i]) j--;
            if (j < cnt) res[j++] = arr[i];
        }
        
        return res;
    }
} 