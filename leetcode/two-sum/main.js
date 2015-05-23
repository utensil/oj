
// Submission begin

/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number[]}
 */
var twoSum = function(nums, target) {
    var num2indexMap = {};
    var ret = null;

    nums.forEach(function(v, i) {
        num2indexMap[v] = i;
    });

    var stop = false;

    for(var i = 0; i < nums.length; ++i) {
        var v = nums[i];
        var v2 = target - v;
        var i2 = num2indexMap[v2];

        if(i2 != null && i2 != i) {
            ret = [i + 1, i2 + 1];
            break;
        }
    }

    return ret;
};

// Submission end
