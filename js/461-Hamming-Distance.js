/**
 *  * @param {number} x
 *   * @param {number} y
 *    * @return {number}
 *     */
var hammingDistance = function(x, y) {
    let z = x ^ y;
    let ans = 0;
    for (let i = 0; i < 32; i++) {
        if (z & (1 << i)) ans++;
    }
    return ans;

};
