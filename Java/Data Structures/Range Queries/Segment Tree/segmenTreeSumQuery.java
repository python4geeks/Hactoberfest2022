/* SET1: sum queries  */
/* SET2: minimum max queries*/

//memory allocated for segment tree 2*2^(log2(n))-1
//time complexity: O(nlogn)
class SegmentTree {

  int st[];

  // constructer
  SegmentTree(int arr[], int n) {
    // height of tree
    int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
    // size of segment tree
    int max_size = 2 * (int) Math.pow(2, x) - 1;
    st = new int[max_size];
    constructUtil(arr, 0, n - 1, 0);
  }

  int constructUtil(int arr[], int ss, int se, int si) {
    if (ss == se) {
      st[si] = arr[ss];
      return arr[ss];
    }
    int mid = getMid(ss, se);
    st[si] =
      constructUtil(arr, ss, mid, si * 2 + 1) +
      constructUtil(arr, mid + 1, se, si * 2 + 2);
    return st[si];
  }

  int getMid(int s, int e) {
    return s + (e - s) / 2;
  }

  int getSum(int n, int qs, int qe) {
    if (qs < 0 || qe > n - 1 || qs > qe) return -1;

    return getSumUtil(0, n - 1, qs, qe, 0);
  }

  // st --> Pointer to segment tree
  // si --> Index of current node in the segment tree. Initially
  // 0 is passed as root is always at index 0
  // ss & se --> Starting and ending indexes of the segment represented
  // by current node, i.e., st[si]
  // qs & qe --> Starting and ending indexes of query range */

  int getSumUtil(int ss, int se, int qs, int qe, int si) {
    if (qs <= ss && qe >= se) { // segment tree lies under the query ir (qs - ss - se - qe)
      return st[si];
    }

    // out of bound
    if (se < qs || ss > qe) return 0;

    int mid = getMid(ss, se);
    return (
      getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
      getSumUtil(mid + 1, se, qs, qe, 2 * si + 2)
    );
  }

  // i is the index to update
  void updatevalue(int arr[], int n, int i, int new_value) {
    if (i < 0 || i > n - 1) return;
    int diff = new_value - arr[i];
    updateValueUtil(0, n - 1, i, diff, 0);
  }

  void updateValueUtil(int ss, int se, int i, int diff, int si) {
    if (i < ss || i > se) {
      return;
    }
    st[si] += diff;
    if (se != ss) {
      int mid = getMid(ss, se);
      updateValueUtil(ss, mid, i, diff, 2 * si + 1);
      updateValueUtil(mid + 1, se, i, diff, 2 * si + 2);
    }
  }

  // driver code
  public static void main(String[] args) {
    int arr[] = { 1, 3, 5, 7, 9, 11 };
    int n = arr.length;
    SegmentTree tree = new SegmentTree(arr, n);
    System.out.println(tree.getSum(n, 1, 3));
    tree.updatevalue(arr, n, 1, 50);
    System.out.println(tree.getSum(n, 1, 3));
  }
}

class SegmentTreeRMQ { // minimum value

  int st[];

  int minVal(int x, int y) {
    return (x < y) ? x : y;
  }

  int getMid(int s, int e) {
    return s + (e - s) / 2;
  }

  /*
   * A recursive function to get the minimum value in a given range of array
   * indexes. The following are parameters for this function.
   *
   * st --> Pointer to segment tree index --> Index of current node in the segment
   * tree. Initially 0 is passed as root is always at index 0 ss & se --> Starting
   * and ending indexes of the segment represented by current node, i.e.,
   * st[index] qs & qe --> Starting and ending indexes of query range
   */

  int RMQUtil(int ss, int se, int qs, int qe, int index) {
    if (qs <= ss && se <= qe) {
      return st[index];
    }
    if (se < qs || ss > qe) return Integer.MAX_VALUE;

    int mid = getMid(ss, se);
    return minVal(
      RMQUtil(ss, mid, qs, qe, 2 * index + 1),
      RMQUtil(mid + 1, se, qs, qe, 2 * index + 2)
    );
  }

  int RMQ(int n, int qs, int qe) {
    if (qs < 0 || qe > n - 1) return -1;
    return RMQUtil(0, n - 1, qs, qe, 0);
  }

  // A recursive function to construct Segment Tree from given array
  // starting from index 'ss' to 'se'.

  int constructSTutil(int arr[], int ss, int se, int si) {
    if (ss == se) {
      st[si] = arr[si];
      return arr[si];
    }
    int mid = getMid(ss, se);
    st[si] =
      minVal(
        constructSTutil(arr, ss, mid, si * 2 + 1),
        constructSTutil(arr, mid + 2, se, si * 2 + 1)
      );
    return st[si];
  }

  void constructST(int arr[], int n) {
    int x = (int) (Math.ceil(Math.log(n) / Math.log(2)));
    int max_size = 2 * (int) Math.pow(2, x) - 1;
    st = new int[max_size];
    constructSTutil(arr, 0, n - 1, 0);
  }

  // driver code
  public static void main(String args[]) {
    int arr[] = { 1, 3, 2, 7, 9, 11 };
    int n = arr.length;
    SegmentTreeRMQ tree = new SegmentTreeRMQ();

    // Build segment tree from given array
    tree.constructST(arr, n);

    int qs = 1; // Starting index of query range
    int qe = 5; // Ending index of query range

    System.out.println(tree.RMQ(n, qs, qe));
  }
}

class LazySegmentTree {

  final int MAX = 1000;
  int st[] = new int[MAX];
  int lazy[] = new int[MAX];

  void updateRangeUtil(int ss, int se, int us, int ue, int si, int diff) {
    if (lazy[si] != 0) {
      st[si] += (se - ss + 1) * lazy[si];
      if (ss != se) {
        lazy[2 * si + 1] += lazy[si];
        lazy[2 * si + 2] += lazy[si];
      }
      lazy[si] = 0;
    }

    if (ss > se || ss > ue || se < us) return;
    if (ss >= us && se <= ue) {
      st[si] += (se - ss + 1) * diff;
      // If not a leaf node
      if (ss != se) {
        lazy[2 * si + 1] += diff;
        lazy[2 * si + 2] += diff;
      }
      return;
    }

    int mid = ss + (se - ss) / 2;
    updateRangeUtil(ss, mid, us, ue, 2 * si + 1, diff);
    updateRangeUtil(mid + 1, se, us, ue, 2 * si + 2, diff);

    st[si] = st[2 * si + 1] + st[2 * si + 2];
  }

  void updateRange(int n, int us, int ue, int diff) {
    updateRangeUtil(0, n - 1, us, ue, 0, diff);
    // updateRangeUtil(ss, se, us, ue, si, diff);
  }

  int getSumUtil(int ss, int se, int qs, int qe, int si) {
    if (lazy[si] != 0) {
      st[si] += (se - ss + 1) * lazy[si];
      // if not a leaf node
      if (ss != se) {
        lazy[2 * si + 1] += lazy[si];
        lazy[2 * si + 2] += lazy[si];
      }
      lazy[si] = 0;
    }
    // out of range bounds
    if (ss > se || ss > qe || se < qs) {
      return 0;
    }
    // in range
    if (ss >= qs && se <= qe) {
      return st[si];
    }
    // overlaping
    int mid = ss + (se - ss) / 2;
    return (
      getSumUtil(ss, mid, qs, qe, 2 * si + 1) +
      getSumUtil(mid + 1, se, qs, qe, 2 * si + 2)
    );
  }
}
