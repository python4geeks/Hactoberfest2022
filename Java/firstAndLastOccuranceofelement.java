/*first and last occurance of element
 * binary search modified medium
 */

class GFG {

  ArrayList<Long> find(long arr[], int n, int x) {
    // code here
    ArrayList<Long> res = new ArrayList<Long>();
    res.add(binarysearch(arr, x, true));
    res.add(binarysearch(arr, x, false));
    return res;
  }

  private long binarysearch(long[] nums, int target, boolean first) {
    int res = -1; // possible ans
    int l = 0, r = nums.length - 1;
    while (l <= r) {
      int mid = l + (r - l) / 2;
      if (nums[mid] == target) { // this can be the possible ans
        res = mid;
        if (first) {
          r = mid - 1;
        } else {
          l = mid + 1;
        }
      } else if (nums[mid] > target) {
        r = mid - 1;
      } else l = mid + 1;
    }
    return (long) res;
  }
}

//{ Driver Code Starts.

// Driver class
class firstandlastoccuranceofelement {

  public static void main(String[] args) throws IOException {
    // Taking input using buffered reader
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));

    int testcases = Integer.parseInt(br.readLine());
    // looping through all testcases
    while (testcases-- > 0) {
      //            int n = Integer.parseInt(br.readLine());
      String line = br.readLine();
      String[] q = line.trim().split("\\s+");
      int n = Integer.parseInt(q[0]);
      int x = Integer.parseInt(q[1]);
      //            //int y =Integer.parseInt(q[2]);
      String line1 = br.readLine();
      String[] a1 = line1.trim().split("\\s+");
      long arr[] = new long[n];
      for (int i = 0; i < n; i++) {
        arr[i] = Long.parseLong(a1[i]);
      }
      GFG ob = new GFG();
      ArrayList<Long> ans = ob.find(arr, n, x);
      System.out.println(ans.get(0) + " " + ans.get(1));
    }
  }
}
