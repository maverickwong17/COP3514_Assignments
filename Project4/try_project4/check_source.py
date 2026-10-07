#!/usr/bin/env python3
import re
from pathlib import Path

path = Path("project4.c")
if not path.exists():
    print("project4.c was not found in this directory.")
    raise SystemExit(1)

src = path.read_text(errors="replace")
src = re.sub(r"/\*.*?\*/", "", src, flags=re.S)
src = re.sub(r"//.*?$", "", src, flags=re.M)
m = re.search(r"\bpair_sums\s*\([^;{}]*\)\s*\{", src, flags=re.S)
if not m:
    print("Could not find the required pair_sums() function definition.")
    raise SystemExit(1)

start = src.find("{", m.start())
depth = 0
end = None
for i in range(start, len(src)):
    if src[i] == "{": depth += 1
    elif src[i] == "}":
        depth -= 1
        if depth == 0:
            end = i
            break
if end is None:
    print("Could not parse pair_sums().")
    raise SystemExit(1)

body = src[start+1:end]
body = re.sub(r'"(?:\\.|[^"\\])*"', '""', body)
body = re.sub(r"'(?:\\.|[^'\\])*'", "''", body)
if "[" in body or "]" in body:
    print("Pointer check FAILED: pair_sums() contains array subscripting ([]).")
    raise SystemExit(1)

print("Pointer check PASSED: pair_sums() was found and contains no array subscripting.")
