import sys


def priority(op):
    if op == "+" or op == "-":
        return 1
    if op == "*" or op == "/":
        return 2
    if op == "(":
        return 3
    return 0


def evaluate(expression):
    stack = []
    for char in expression:
        if char.isdigit():
            stack.append(int(char))
        elif char in "+-*/":
            operand2 = stack.pop()
            operand1 = stack.pop()
            if char == "+":
                result = operand1 + operand2
            elif char == "-":
                result = operand1 - operand2
            elif char == "*":
                result = operand1 * operand2
            elif char == "/":
                result = operand1 / operand2
            stack.append(int(result))
    return stack[0]


line = sys.stdin.readline().strip()

stack = []
postfix = []
for char in line:
    if char.isdigit():
        postfix.append(char)
    elif char in "+-*/":
        while stack and stack[-1] != "(" and priority(stack[-1]) >= priority(char):
            postfix.append(stack.pop())
        stack.append(char)
    elif char == "(":
        stack.append(char)
    elif char == ")":
        while stack and stack[-1] != "(":
            postfix.append(stack.pop())
        stack.pop()

while stack:
    postfix.append(stack.pop())


result = evaluate(postfix)
print(result)
