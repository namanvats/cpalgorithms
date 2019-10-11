def search(list, element):
    first = 0
    last = len(list)-1

    while first <= last:
        mid = (first + last) // 2
        print(mid)
        if list[mid] == element:
            return mid
        else:
            if element < list[mid]:
                last = mid-1
            else:
                first = mid + 1
    return False
