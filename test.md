D. Gellyfish and Camellia Japonica

time limit per test: 2 seconds

memory limit per test: 512 megabytes

input: standard input

output: standard output

Gellyfish has an array of $n$ integers $c_1, c_2, \ldots, c_n$. In the beginning, $c = [a_1, a_2, \ldots, a_n]$.

Gellyfish will make $q$ modifications to $c$.

For $i = 1,2,\ldots,q$, Gellyfish is given three integers $x_i$, $y_i$, and $z_i$ between $1$ and $n$. Then Gellyfish will set $c_{z_i} := \min(c_{x_i}, c_{y_i})$.

After the $q$ modifications, $c = [b_1, b_2, \ldots, b_n]$.

Now Flower knows the value of $b$ and the value of the integers $x_i$, $y_i$, and $z_i$ for all $1 \leq i \leq q$, but she doesn't know the value of $a$.

Flower wants to find any possible value of the array $a$ or report that no such $a$ exists.

If there are multiple possible values of the array $a$, you may output any of them.

**Input**

Each test contains multiple test cases. The first line contains the number of test cases $t$ ($1 \le t \le 10^4$). The description of the test cases follows.

The first line of each test case contains two integers $n$ and $q$ ($1 \leq n, q \leq 3 \cdot 10^5$) — the size of the array and the number of modifications.

The second line of each test case contains $n$ integers $b_1, b_2, \ldots, b_n$ ($1 \leq b_i \leq 10^9$) — the value of the array $c$ after the $q$ modifications.

The following $q$ lines each contain three integers $x_i$, $y_i$, and $z_i$ ($1 \leq x_i, y_i, z_i \leq n$) — describing the $i$\-th modification.

It is guaranteed that the sum of $n$ and the sum of $q$ over all test cases does not exceed $3 \cdot 10^5$.

**Output**

For each test case, if $a$ exists, output $n$ integers $a_1, a_2, \ldots, a_n$ ($0 \leq a_i \leq 10^9$) in a single line. Otherwise, output "-1" in a single line.

If there are multiple solutions, print any of them.

Example
input
3
2 1
1 2
2 1 2
3 2
1 2 3
2 3 2
1 2 1
6 4
1 2 2 3 4 5
5 6 6
4 5 5
3 4 4
2 3 3

output
-1
1 2 3 
1 2 3 4 5 5 
