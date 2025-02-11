class student1:
    def __init__(self, params: list[str, int]):
        self.params = [None, None]
        self.params[0] = params[0]
        self.params[1] = params[1]
    
    def change_name(self, name: str):
        self.params[0] = name

if __name__ == '__main__':
    s1 = student1(['John', 20])
    s1.change_name('Jane')
    print(s1.params[0])