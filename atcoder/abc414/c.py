import sys, inspect
sys.setrecursionlimit(10**7)
INF = 10**18
MOD = 10**9+7

def debug(*args):
    frame = inspect.currentframe().f_back
    info = inspect.getframeinfo(frame)
    line = info.code_context[0].strip()
    expr = line[line.find('debug(')+6 : line.rfind(')')]
    names = [n.strip() for n in expr.split(',')]
    
    def _fmt(x):
        if isinstance(x, dict):
            return '{' + ', '.join(f"{_fmt(k)}: {_fmt(v)}" for k, v in x.items()) + '}'
        if isinstance(x, (list, tuple, set)):
            openb, closeb = ('[',']') if isinstance(x, list) else ('(',')') if isinstance(x, tuple) else ('{','}')
            return openb + ', '.join(_fmt(v) for v in x) + closeb
        return str(x)
    
    vals = ', '.join(_fmt(v) for v in args)
    print(f"[{', '.join(names)}] = [{vals}]", file=sys.stderr)

_data = sys.stdin.read().split()
_it = iter(_data)

def read(*types):
    return tuple(t(next(_it)) for t in types)

def tobase(num, base):
    if num == 0: return "0"
    digits = []
    while num:
        digits.append(str(num % base))
        num //= base
    return "".join(reversed(digits))

def solve():
    a, n = read(int, int)
    ans = 0
    for i in range(1, min(10**6 + 5, n + 5)):
        s = str(i)

        t = s + s[::-1]
        for t in (s + s[::-1], s + s[-2::-1]):
            v = int(t)
            nb = tobase(v, a)
            if v <= n and nb == nb[::-1]:
                ans += v
       
    print(ans)

def main():
    solve()

if __name__ == "__main__":
    main()

