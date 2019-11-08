class Node:
    def __init__(self, data):
        self.data = data
        self.next = None

class LinkedList:
    def __init__(self, *, ls = []): 
        self.__head = None
        self.__sz = 0
        for x in ls[::-1]:
            self.push_front(x)

    def __str__(self):
        temp = self.__head
        ret = "None" if temp is None else ""
        while temp:
            ret += str(temp.data) + " "
            temp = temp.next
        return ret

    def __len__(self):
        return self.__sz

    def __del__(self):
        self.__head = None

    def push_front(self, data):
        new_node = Node(data)
        new_node.next = self.__head
        self.__head = new_node
        self.__sz += 1

    def push_back(self, data):
        if self.__head is None:
            self.__head = Node(data)
            self.__sz += 1
            return

        last = self.__head
        while last.next:
            last = last.next
        last.next = Node(data)
        self.__sz += 1


    def array(self):
        temp = self.__head
        newList = []
        while temp:
            newList.append(temp.data)
            temp = temp.next
        return newList

    def matrix(self, row, col):
        if row * col < self.__sz:
            print("Data is insufficient")
            return
        mat = []
        temp = self.__head
        for i in range(row):
            res = []
            for j in range(col):
                res.append(temp.data)
                temp = temp.next
            mat.append(res)
        return mat

if __name__ == '__main__':
    newList = LinkedList(ls = [1, 2, 3, 4, 5])
    arr = newList.array()
    print(arr)
    print(len(newList))
    print(newList)
