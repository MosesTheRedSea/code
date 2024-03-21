"""
█▀▄▀█ █▀▀█ █▀▀ █▀▀ █▀▀ ─█▀▀█ █▀▀▄ █▀▀ █───█ █▀▀█ █── █──█ 
█░█░█ █──█ ▀▀█ █▀▀ ▀▀█ ░█▄▄█ █──█ █▀▀ █▄█▄█ █──█ █── █──█ 
█──░█ ▀▀▀▀ ▀▀▀ ▀▀▀ ▀▀▀ ░█─░█ ▀▀▀─ ▀▀▀ ─▀─▀─ ▀▀▀▀ ▀▀▀ ─▀▀▀

"""

def removeDuplicates(nums):
    size = len(nums)
    val = [nums[0]]
    shift = False
    for i in range(1,len(nums)):
        if (nums[i] not in val):
            print(f"Value : {nums[i]} - Index : {i}")
            val.append(nums[i])
            print(f'No Shift {nums}')
            continue
        else:
            print(f'Index {i}')
            for k in range(len(nums) - i - 1):
                nums[i + k] = nums[i + k + 1]
            nums[len(nums)-1] = None
            size-=1
            print(nums)
    print(nums)
    return size


def removeDup(nums):
    size = len(nums)
    val = []
    i = 0
    shift = False
    while i < len(nums):
        shift = False
        if (nums[i] not in val):
            val.append(nums[i])
            continue
        else:
            shift = True
            for k in range(len(nums) - i - 1):
                nums[i + k] = nums[i + k + 1]
            nums[len(nums)-1] = None
            size-=1
        if shift==False:
            i+=1
    print(nums)
    return size


def removeD(lst):
    index = 0
    while index < len(lst):
        current_element = lst[index]
        # Search for duplicates after the current index
        for i in range(index + 1, len(lst)):
            if lst[i] == current_element:
                # Shift elements to the left to remove the duplicate
                for j in range(i, len(lst) - 1):
                    lst[j] = lst[j + 1]
                # Set the last element to None
                lst[-1] = None
                # Adjust index since the list has been shifted
                index -= 1
        index += 1
    return lst

def rem(lst):
    index = 0
    while index < len(lst):
        current_element = lst[index]
        # Search for duplicates after the current index
        for i in range(index + 1, len(lst)):
            if lst[i] == current_element:
                # Remove the duplicate using list slicing
                lst = lst[:i] + lst[i+1:] + [None]
        index += 1
    return lst

def r(nums):
    nums[:] = sorted(set(nums))
    print(nums)
    return len(nums)

# Testing Method Calls

print(rem([0,0,1,1,1,2,2,3,3,4]))
print(removeDup([1,1,2]))
print(removeDuplicates([1,1,2]))
print(r([0,0,1,1,1,2,2,3,3,4]))
