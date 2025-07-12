class Solution:
    def calculate(self, s: str) -> int:
        s = s.strip() + '+'
        num = 0
        stack = []
        op = '+'
        for char in s:
            if char.isdigit():
                num = 10 * num + int(char)
            elif char in '+-/*':
                if op == '+':
                    stack.append(num)
                elif op == '-':
                    stack.append(-num)
                elif op == '*':
                    prev = stack.pop()
                    stack.append(prev * num)
                else:
                    prev = stack.pop()
                    stack.append(int(prev / num))
                op = char
                num = 0
        return sum(stack)