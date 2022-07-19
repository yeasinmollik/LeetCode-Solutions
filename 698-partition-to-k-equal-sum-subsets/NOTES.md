Let's me further explain the two game changers in this solution:
1. if buckets[j] == 0: return false
​
The key is, buckets[j] == 0 means for all k > j, buckets[k] == 0; because this algorithm always fill the previous buckets before trying the next.
So if by putting nums[i] in this empty bucket can't solve the game, putting nums[i] on other empty buckets can't solve the game too.
​
2. nums.sort(reverse=True)
​
Always start from big numbers for this kind of question, just by doing it yourself for a few times you will find out that the big numbers are the easiest to place.
​