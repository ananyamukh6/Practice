from collections import OrderedDict
def twoSum(nums, target):
    """
    :type nums: List[int]
    :type target: int
    :rtype: List[int]
    """
    res = []
    '''
    This is o(n^2)
    '''
    for num1_idx in range(len(nums)):
        for num2_idx in range(num1_idx+1, len(nums)):
            if nums[num1_idx] + nums[num2_idx] == target:
                res.append(num1_idx)
                res.append(num2_idx)
    print(res)   

def twoSumSpeedup(nums, target):
    map_num = {}
    for idx in range(0, len(nums)):
        map_num[nums[idx]] = map_num.get(nums[idx], 0) + 1        
        rem = target - nums[idx]
        # print(rem)
        # print(map_num)
        # print(nums[idx])
        
        print("-----")
        found = (rem!=nums[idx] and rem in map_num) or (rem==nums[idx] and map_num[rem] > 1)
        if found:
            print("****",map_num[rem])
            return [nums.index(rem),idx]
        
        #print(map_num)



nums = [3,3]
print(twoSumSpeedup(nums, 6))

