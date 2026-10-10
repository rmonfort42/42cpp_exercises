#!/bin/sh
# Tests for the "replace" program (ex04).
# Usage: sh test.sh   (from the ex04 directory, after "make")

set -u

BIN="./replace"
TMP=".test_tmp"

if [ ! -x "$BIN" ]; then
	echo "error: $BIN not found, run 'make' first" >&2
	exit 1
fi

rm -rf "$TMP"
mkdir -p "$TMP"

pass=0
fail=0

check() {
	if [ "$2" = "$3" ]; then
		pass=$((pass + 1))
		echo "PASS: $1"
	else
		fail=$((fail + 1))
		echo "FAIL: $1"
		echo "  expected: [$3]"
		echo "  got:      [$2]"
	fi
}

# 1. basic replacement
printf 'hola mundo\nhola hola\n' > "$TMP/a.txt"
"$BIN" "$TMP/a.txt" hola adios
check "basic" "$(cat "$TMP/a.txt.replace")" "$(printf 'adios mundo\nadios adios')"

# 2. s1 not found -> identical copy
printf 'abc\n' > "$TMP/b.txt"
"$BIN" "$TMP/b.txt" zzz yyy
check "not found" "$(cat "$TMP/b.txt.replace")" "abc"

# 3. empty s2 -> deletion
printf 'xaxbxc\n' > "$TMP/c.txt"
"$BIN" "$TMP/c.txt" x ""
check "empty s2" "$(cat "$TMP/c.txt.replace")" "abc"

# 4. no trailing newline preserved
printf 'nofinal' > "$TMP/d.txt"
"$BIN" "$TMP/d.txt" no yes
check "no trailing newline" "$(cat "$TMP/d.txt.replace")" "yesfinal"

# 5. error: wrong argc
"$BIN" > /dev/null 2>&1
check "argc error exit code" "$?" "1"

# 6. error: empty s1
"$BIN" "$TMP/a.txt" "" x > /dev/null 2>&1
check "empty s1 exit code" "$?" "1"

# 7. error: missing file
"$BIN" "$TMP/does_not_exist.txt" a b > /dev/null 2>&1
check "missing file exit code" "$?" "1"

echo ""
echo "PASS: $pass   FAIL: $fail"
rm -rf "$TMP"

[ "$fail" -eq 0 ]
