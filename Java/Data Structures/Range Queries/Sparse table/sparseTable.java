class SparseTable {

  private int n;

  // maximum power of 2 needed. floor(log2(n))
  private int P;

  // lookup table for the power of 2(log base 2 of i, 1<=i<=n)
  private int[] log2;

  // sparse table
  private long[][] dp;

  // index table(IT-it) associated with values in dp
  private int[][] it;

  public enum Operation {
    MIN,
    MAX,
    SUM,
    MULT,
    GCD,
  }

  private Operation op;
  // all functtions must be associative e.g: a * (b * c) = (a * b) * c
  private BinaryOperator<Long> sumFn = (a, b) -> a + b;
  private BinaryOperator<Long> minFn = (a, b) -> Math.min(a, b);
  private BinaryOperator<Long> maxFn = (a, b) -> Math.max(a, b);
  private BinaryOperator<Long> multFn = (a, b) -> a * b;
  private BinaryOperator<Long> gcdFn = (a, b) -> {
    long gcd = a;
    while (b != 0) {
      gcd = b;
      b = a % b;
      a = gcd;
    }
    return Math.abs(gcd);
  };

  public SparseTable(long[] values, Operation op) {
    this.op = op;
    init(values);
  }

  private void init(long[] v) {
    n = v.length;
    P = (int) Math.floor(Math.log(n) / Math.log(2));
    dp = new long[P + 1][n];
    it = new int[P + 1][n];

    for (int i = 0; i < n; i++) {
      dp[0][i] = v[i];
      it[0][i] = i;
    }
    log2 = new int[n + 1];
    for (int i = 2; i <= n; i++) {
      log2[i] = log2[i / 2] + 1;
    }

    // build sparse table combining he values of the previous intervals
    for (int i = 1; i <= P; i++) {
      for (int j = 0; j + (1 << i) <= n; j++) {
        long leftinterval = dp[i - 1][j];
        long rightInterval = dp[i - 1][j + (1 << (i - 1))];
        if (op == Operation.MIN) {
          dp[i][j] = minFn.apply(leftinterval, rightInterval);
          // propagate the index of the best value
          if (leftinterval <= rightInterval) {
            it[i][j] = it[i - 1][j];
          } else {
            it[i][j] = it[i - 1][j + (1 << (i - 1))]; // 2 ka power + j
          }
        } else if (op == Operation.MAX) {
          dp[i][j] = maxFn.apply(leftinterval, rightInterval);
          if (leftinterval >= rightInterval) {
            it[i][j] = it[i - 1][j];
          } else {
            it[i][j] = it[i - 1][j + (1 << (i - 1))];
          }
        } else if (op == Operation.SUM) {
          dp[i][j] = sumFn.apply(leftinterval, rightInterval);
        } else if (op == Operation.GCD) {
          dp[i][j] = gcdFn.apply(leftinterval, rightInterval);
        } else if (op == Operation.MULT) {
          dp[i][j] = multFn.apply(leftinterval, rightInterval);
        }
      }
    }
  }

  private void printtable() {
    for (long[] r : dp) {
      for (int i = 0; i < r.length; i++) {
        System.out.printf("%02d,", r[i]);
      }
      System.out.println();
    }
  }

  //queries [l,r] for the operations set on this sparse table
  public long query(int l, int r) {}
}
