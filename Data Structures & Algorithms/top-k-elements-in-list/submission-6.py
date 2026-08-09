class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        '''
        //store each number in nums as a pair
        //the pair will look like [number : frequency]
        //each time a number apears in nums, add one to its frequency
        //then sort the pairs by frequency
        //return the numbers at index k-1 and above
        '''
        if len(nums) == k:
            return nums

        numbers = {}

        for num in nums:
            if num in numbers:
                numbers[num] += 1
            else:
                numbers[num] = 1
        sorted_pairs = sorted(numbers.items(), key = lambda item: item[1])

        kMostFrequent = []
        for i in range(len(sorted_pairs) - k,len(sorted_pairs) ):
            kMostFrequent.append(sorted_pairs[i][0])
        return kMostFrequent