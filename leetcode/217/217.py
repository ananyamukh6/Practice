def containsDuplicate(nums):
    """
    :type nums: List[int]
    :rtype: bool
    """
    if len(nums) == 0:
        return False
    num_dict = {}
    for idx in range(len(nums)):
        num_dict[nums[idx]] = num_dict.get(nums[idx], 0)+1
        if num_dict[nums[idx]]>1:
            return True
    return False



def containsDuplicate_alternate(nums):
    """
    :type nums: List[int]
    :rtype: bool
    """
    if len(nums) == 0:
        return False
    breakpoint()
    nums = sorted(nums)
    #return len(set(nums)) != len(nums) // one line solution
    for idx in range(len(nums) -1):
        if nums[idx] == nums[idx+1]:
            return True
    return False

nums = [1,2,3,1]
print(containsDuplicate_alternate(nums))