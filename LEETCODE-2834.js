/**
 * @param {number} n
 * @param {number} target
 * @return {number}
 */
var minimumPossibleSum = function(n, target) {
    let answer=0, len=0, number=1;
    hashmap={};
    while(len != n) {
        if(!hashmap[number]) {
            answer+= number;
            hashmap[target-number] = 1;
            len++;
        }
        number++;
    }
    return answer;
};