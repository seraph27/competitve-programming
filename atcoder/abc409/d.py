# type: ignore
from collections import Counter, defaultdict
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
    vals = [t(next(_it)) for t in types]
    return vals[0] if len(vals) == 1 else tuple(vals)


def solve():
    n = read(int)
    s = read(str)

    start = -1
    for i in range(n-1):
        if s[i+1] < s[i]:
            start = i;
            break;

    if start == -1:
        print(s)
        return
    end = n
    for k in range(start+1, n):
        if(s[k] > s[start]):
            end = k
            break
    debug(start, end, s[start:end])
    print(s[:start] + s[start+1:end] + s[start] + s[end:])


def main():
    MULTITEST = True
    t = read(int) if MULTITEST else 1
    for _ in range(t):
        solve()

if __name__ == "__main__":
    main()

