/*element present more than n/2 times
 *
 */

class MajorityElement {

  public int majorityElement(int[] nums) {
    int count = 0;
    int majority = 0;
    for (int curr : nums) {
      if (count == 0) {
        majority = curr;
      }
      if (curr == majority) {
        count++;
      } else {
        count--;
      }
    }
    return majority;
  }
}
