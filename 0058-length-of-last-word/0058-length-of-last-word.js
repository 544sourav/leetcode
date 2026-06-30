/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function(s) {
    const words = s.trim().split(" ");
    return words.at(-1).length;
};