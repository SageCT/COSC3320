import sys


def infix_to_postfix(infix):
    infix = infix.replace(" ", "")
    prio = {"+": 1, "-": 1, "*": 2, "/": 2, "^": 3}
    stack = []
    postfix = []

    for token in infix:
        if token.isdigit():
            postfix.append(token)
        elif token == "(":
            stack.append(token)
        elif token == ")":
            while stack and stack[-1] != "(":
                postfix.append(stack.pop())
            stack.pop()
        else:
            while stack and prio.get(token, 0) <= prio.get(stack[-1], 0):
                postfix.append(stack.pop())
            stack.append(token)
    while stack:
        postfix.append(stack.pop())
    return postfix


def postfix_eval(pf):
    stack = []
    for token in pf:
        if token.isdigit():
            stack.append(int(token))
        else:
            b = stack.pop()
            a = stack.pop()
        match token:
            case "+":
                stack.append(a + b)
            case "-":
                stack.append(a - b)
            case "*":
                stack.append(a * b)
            case "/":
                stack.append(a // b)
            case "^":
                stack.append(a**b)
    return stack.pop()


temp = sys.stdin.readline().strip()
# temp = "2 + 3 * 4 + ( 3 * 4 ) / 5".strip()
print(type(input()))

# print(postfix_eval(infix_to_postfix(temp)))
