class CircularQueue:
    def __init__(self, size: int):
        self.size = size
        self.queue = [None] * size
        self.front = self.rear = -1

    def is_empty(self):
        return self.front == -1

    def enqueue(self, item):
        if self.is_empty():
            self.front = 0 # Queue is now non-empty

        self.rear = (self.rear + 1) % self.size #Move rear pointer in circular fashion
        self.queue[self.rear] = item #Add value at the rear 

    def dequeue(self):
        if self.is_empty():
            raise IndexError("Queue is empty")
        
        item = self.queue[self.front]
        # Reset the queue when there's only one element left
        if self.front == self.rear:
            self.front = self.rear = -1
        # Move the front pointer in circular fashion
        else:
            self.front = (self.front + 1) % self.size
        return item
    
    def sort(self):
        # Bubble sort the queue values
        for i in range(self.size):
            for j in range(0, self.size-i-1):
                # Need to point to the front to handle circular case
                i1 = (self.front + j) % self.size
                i2 = (self.front + j + 1) % self.size
                if self.queue[i1] > self.queue[i2]:
                    self.queue[i1], self.queue[i2] = self.queue[i2], self.queue[i1]

    def display(self):
        if self.is_empty():
            print("Queue is empty!")
            return
        i = self.front
        while i != self.rear:
            print(self.queue[i], end=" -> ")
            i = (i + 1) % self.size
        print(self.queue[self.rear])

if __name__ == '__main__':
    cq = CircularQueue(5)

    cq.enqueue(60)
    cq.enqueue(20)
    cq.enqueue(30)
    cq.enqueue(50)
    cq.enqueue(40)

    cq.display()

    print("Dequeued:", cq.dequeue())
    cq.display()

    cq.enqueue(60)
    cq.display()

    cq.sort()
    cq.display()


