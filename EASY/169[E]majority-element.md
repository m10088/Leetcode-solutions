[原题](https://leetcode.com/problems/majority-element/)

题意：有一个数字出现了 （n/2）向下取整次。找出这个数字。



此题的正确解法是通过voting algorithm。假设你是一个裁判，你面前有n个投票议员。现在你从他们每个人手中依次拿到他们的选票。如果第一个人的选票是投给了A,你就记下：总统是A，票数是1。下面，你走到第二个人面前，如果第二个人的选票还是给A，那么总统不变，票数加1。如果第二个人的选票不是A (例如B,C,D,E,...)，那么票数减1。如果票数变成了0，那你将丢弃之前记下的总统名字，并把它改为这张选票 上的名字(例如B,C,D,E,...)，并把票数重置为1。

你一直朝着剩下的议员走去，直到看完所有人的选票。到此为止，你最后一次记下的总统的名字，就会是得到多数票获选成为总统的人。当然你可以根据他的名字，最后再在所有选票中数一数，看是否超过半数。
这个解法能保证时间复杂度只有O(N)，而且不占用更多的空间。虽然你可能觉得你理解了这个方法，比如，当这个最多数全部出现在数组的前端的时候（trivial）。但此解法的严格证明，并非这么简单的。有兴趣的人可以去[A Linear-Time Majority Vote Algorithm](http://www.cs.utexas.edu/~moore/best-ideas/mjrty/)，里面有原作者的paper。


```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        president = nums[0]
        counter = 1
        for i in range(1, len(nums)):
            this_vote = nums[i]
            if this_vote == president:
                counter += 1
            else:
                counter -= 1
                if counter == 0:
                    president, counter = this_vote, 1
        return president
```

但实际上这个问题有一种更加匪夷所思的解法。那就是随机解法。你随机的从数组n中选一个数，然后统计他出现的次数（这一步需要耗时O(N))。如果他的次数超过了n/2，那么他就是你要找的数。如果不是，你就再随机抽一个，直到你找到位置。
你居然能够证明，此方法的平均消耗时间也是O(N)。你只需要计算期望。因为你要找的数是一个多数，随机一次抽取不到这个数的概率总是小于1/2。连续k次抽取不到这个数的概率是<(1/2)^k。那么，最后能抽取到的抽取次数期望就是
O(\sum_{1}^{\infty}  k(1/2)^k)=O(2)

几何分布的期望。

每抽一次要花n来验证，所以最后的时间复杂度也是O(N)，并且不占额外的空间。


```
class Solution(object):
    def majorityElement(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        from collections import Counter
        cnt = Counter(nums)
        n = len(nums)
        while True:
            sel = nums[random.randint(0, n-1)]
            if n % 2 == 0 and cnt[sel] >= len(nums) // 2:
                return sel
            if n % 2 == 1 and cnt[sel] > len(nums) // 2:
                return sel
```

