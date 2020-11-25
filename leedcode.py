class Solution:
    def maxNumber(self, nums1, nums2, k):
        def get(arr1, k):
            if k == len(arr1):
                return arr1
            if k > len(arr1):
                return None
            if k==0:
                return []
            stack = [-1] * k
            count = 0
            for i in range(len(arr1)):
                if count == 0:
                    stack[count] = arr1[i]
                    count += 1
                    continue
                while count > 0 and stack[count - 1] < arr1[i] and len(arr1) - i > k - count:
                    count -= 1
                if count<k:
                    stack[count] = arr1[i]
                    count += 1
            return stack

        def merge(arr1, arr2):
            def greater(arr1,count1,arr2,count2):
                while count1<len(arr1) and count2<len(arr2) and arr1[count1]==arr2[count2]:
                    count1+=1
                    count2+=1
                if count2==len(arr2) or (count1<len(arr1) and arr1[count1]>arr2[count2]):
                    return True
                return False
            ret = []
            count1 = 0
            count2 = 0
            while count1 < len(arr1) and count2 < len(arr2):
                if greater(arr1,count1,arr2,count2):
                    r = arr1[count1]
                    count1 += 1
                else:
                    r = arr2[count2]
                    count2 += 1
                ret.append(r)
            if count2 < len(arr2):
                count1 = count2
                arr1 = arr2
            ret += arr1[count1:]
            return ret

        def compare(arr1, arr2):
            for i in range(len(arr1)):
                if arr1[i] < arr2[i]:
                    return True
                elif arr1[i] > arr2[i]:
                    return False
            return False

        ret = [-1] * k
        for i in range(k + 1):
            arr1 = get(nums1, i)
            arr2 = get(nums2, k - i)
            if arr1 is None or arr2 is None:
                continue
            out = merge(arr1, arr2)
            if compare(ret, out):
                ret = out

        return ret