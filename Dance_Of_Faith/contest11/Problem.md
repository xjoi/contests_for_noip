Give the address of this contest:
[contest11](https://cn.vjudge.net/contest/168242)
##### codeforces contest 420
[click here to enter codeforces](http://codeforces.com/contest/821)

## A -Okabe and Future Gadget Laboratory
### Problem
Okabe needs to renovate the Future Gadget Laboratory after he tried doing some crazy experiments! The lab is represented as an n by n square grid of integers. A good lab is defined as a lab in which every number not equal to 1 can be expressed as the sum of a number in the same row and a number in the same column. In other words, for every x, y such that 1 ≤ x, y ≤ n and ax, y ≠ 1, there should exist two indices s and t so that ax, y = ax, s + at, y, where ai, j denotes the integer in i-th row and j-th column.
Help Okabe determine whether a given lab is good!
### Input
The first line of input contains the integer n (1 ≤ n ≤ 50) — the size of the lab.
The next n lines contain n space-separated integers denoting a row of the grid. The j-th integer in the i-th row is ai, j (1 ≤ ai, j ≤ 105).
### Output
Print "Yes" if the given lab is good and "No" otherwise.
You can output each letter in upper or lower case.
### Example
#### Input
3
1 1 2
2 3 1
6 4 1
#### Output
Yes
#### Input
3
1 5 2
1 1 1
1 2 3
#### Output
No
### Note
In the first sample test, the 6 in the bottom left corner is valid because it is the sum of the 2 above it and the 4 on the right. The same holds for every number not equal to 1 in this table, so the answer is "Yes".
In the second sample test, the 5 cannot be formed as the sum of an integer in the same row and an integer in the same column. Thus the answer is "No".

---------------------------------------------------------

## B -Okabe and Banana Trees
### Problem
Okabe needs bananas for one of his experiments for some strange reason. So he decides to go to the forest and cut banana trees.
Consider the point (x, y) in the 2D plane such that x and y are integers and 0 ≤ x, y. There is a tree in such a point, and it has x + y bananas. There are no trees nor bananas in other points. Now, Okabe draws a line with equation . Okabe can select a single rectangle with axis aligned sides with all points on or under the line and cut all the trees in all points that are inside or on the border of this rectangle and take their bananas. Okabe's rectangle can be degenerate; that is, it can be a line segment or even a point.
Help Okabe and find the maximum number of bananas he can get if he chooses the rectangle wisely.
Okabe is sure that the answer does not exceed 1018. You can trust him.
### Input
The first line of input contains two space-separated integers m and b (1 ≤ m ≤ 1000, 1 ≤ b ≤ 10000).
### Output
Print the maximum number of bananas Okabe can get from the trees he cuts.
### Example
#### Input
1 5
#### Output
30
#### Input
2 3
#### Output
25
### Note

![the picture](https://odzkskevi.qnssl.com/d6a7edeace63610feb73b4c78005481e?v=1498432796)

The graph above corresponds to sample test 1. The optimal rectangle is shown in red and has 30 bananas.

---------------------------------------

## C -Okabe and Boxes
### Problem
Okabe and Super Hacker Daru are stacking and removing boxes. There are n boxes numbered from 1 to n. Initially there are no boxes on the stack.
Okabe, being a control freak, gives Daru 2n commands: n of which are to add a box to the top of the stack, and n of which are to remove a box from the top of the stack and throw it in the trash. Okabe wants Daru to throw away the boxes in the order from 1 to n. Of course, this means that it might be impossible for Daru to perform some of Okabe's remove commands, because the required box is not on the top of the stack.
That's why Daru can decide to wait until Okabe looks away and then reorder the boxes in the stack in any way he wants. He can do it at any point of time between Okabe's commands, but he can't add or remove boxes while he does it.
Tell Daru the minimum number of times he needs to reorder the boxes so that he can successfully complete all of Okabe's commands. It is guaranteed that every box is added before it is required to be removed.
### Input
The first line of input contains the integer n (1 ≤ n ≤ 3·105) — the number of boxes.
Each of the next 2n lines of input starts with a string "add" or "remove". If the line starts with the "add", an integer x (1 ≤ x ≤ n) follows, indicating that Daru should add the box with number x to the top of the stack.
It is guaranteed that exactly n lines contain "add" operations, all the boxes added are distinct, and n lines contain "remove" operations. It is also guaranteed that a box is always added before it is required to be removed.
### Output
Print the minimum number of times Daru needs to reorder the boxes to successfully complete all of Okabe's commands.
### Example
#### Input
3
add 1
remove
add 2
add 3
remove
remove
Output
1
#### Input
7
add 3
add 2
add 1
remove
add 4
remove
remove
remove
add 6
add 7
add 5
remove
remove
remove
#### Output
2
### Note
In the first sample, Daru should reorder the boxes after adding box 3 to the stack.
In the second sample, Daru should reorder the boxes after adding box 4 and box 7 to the stack.

-----------------------------------

## D -Okabe and City
### Problem
Okabe likes to be able to walk through his city on a path lit by street lamps. That way, he doesn't get beaten up by schoolchildren.
Okabe's city is represented by a 2D grid of cells. Rows are numbered from 1 to n from top to bottom, and columns are numbered 1 to m from left to right. Exactly k cells in the city are lit by a street lamp. It's guaranteed that the top-left cell is lit.
Okabe starts his walk from the top-left cell, and wants to reach the bottom-right cell. Of course, Okabe will only walk on lit cells, and he can only move to adjacent cells in the up, down, left, and right directions. However, Okabe can also temporarily light all the cells in any single row or column at a time if he pays 1 coin, allowing him to walk through some cells not lit initially.
Note that Okabe can only light a single row or column at a time, and has to pay a coin every time he lights a new row or column. To change the row or column that is temporarily lit, he must stand at a cell that is lit initially. Also, once he removes his temporary light from a row or column, all cells in that row/column not initially lit are now not lit.
Help Okabe find the minimum number of coins he needs to pay to complete his walk!
### Input
The first line of input contains three space-separated integers n, m, and k (2 ≤ n, m, k ≤ 104).
Each of the next k lines contains two space-separated integers ri and ci (1 ≤ ri ≤ n, 1 ≤ ci ≤ m) — the row and the column of the i-th lit cell.
It is guaranteed that all k lit cells are distinct. It is guaranteed that the top-left cell is lit.
### Output
Print the minimum number of coins Okabe needs to pay to complete his walk, or -1 if it's not possible.
### Example
#### Input
4 4 5
1 1
2 1
2 3
3 3
4 3
#### Output
2
#### Input
5 5 4
1 1
2 1
3 1
3 2
#### Output
-1
#### Input
2 2 4
1 1
1 2
2 1
2 2
#### Output
0
#### Input
5 5 4
1 1
2 2
3 3
4 4
#### Output
3
### Note
In the first sample test, Okabe can take the path 

![the path](https://odzkskevi.qnssl.com/93229b0c838b0a0af6a64dcf8fd75dad?v=1498432796)

, paying only when moving to (2, 3)and (4, 4).
In the fourth sample, Okabe can take the path 

![the path](https://odzkskevi.qnssl.com/e964aa5b27c98a22bc90ce85e2271f19?v=1498432796)

, paying when moving to (1, 2), (3, 4),and (5, 4).

-----------------------------------

## E -Okabe and El Psy Kongroo
### Problem
Okabe likes to take walks but knows that spies from the Organization could be anywhere; that's why he wants to know how many different walks he can take in his city safely. Okabe's city can be represented as all points (x, y) such that x and y are non-negative. Okabe starts at the origin (point (0, 0)), and needs to reach the point (k, 0). If Okabe is currently at the point (x, y), in one step he can go to (x + 1, y + 1), (x + 1, y), or (x + 1, y - 1).
Additionally, there are n horizontal line segments, the i-th of which goes from x = ai to x = bi inclusive, and is at y = ci. It is guaranteed that a1 = 0, an ≤ k ≤ bn, and ai = bi - 1 for 2 ≤ i ≤ n. The i-th line segment forces Okabe to walk with y-value in the range 0 ≤ y ≤ ci when his x value satisfies ai ≤ x ≤ bi, or else he might be spied on. This also means he is required to be under two line segments when one segment ends and another begins.
Okabe now wants to know how many walks there are from the origin to the point (k, 0) satisfying these conditions, modulo 109 + 7.
### Input
The first line of input contains the integers n and k (1 ≤ n ≤ 100, 1 ≤ k ≤ 1018) — the number of segments and the destination x coordinate.
The next n lines contain three space-separated integers ai, bi, and ci (0 ≤ ai < bi ≤ 1018, 0 ≤ ci ≤ 15) — the left and right ends of a segment, and its y coordinate.
It is guaranteed that a1 = 0, an ≤ k ≤ bn, and ai = bi - 1 for 2 ≤ i ≤ n.
### Output
Print the number of walks satisfying the conditions, modulo 1000000007 (109 + 7).
### Example
#### Input
1 3
0 3 3
#### Output
4
#### Input
2 6
0 3 0
3 10 2
#### Output
4
### Note

![the picture](https://odzkskevi.qnssl.com/a89ae0e16313c93dc4f0161b4107107b?v=1498432796)

The graph above corresponds to sample 1. The possible walks are:

![path1](https://odzkskevi.qnssl.com/6d642c218edf0f6ec30395a258e53c3a?v=1498432796)

![path2](https://odzkskevi.qnssl.com/4ff0be514a6a9d180717901b5db3f05c?v=1498432796)

![path3](https://odzkskevi.qnssl.com/92868db318c157b1abbf98e355708be7?v=1498432796)

![path4](https://odzkskevi.qnssl.com/aebf9e09a83c9540b1ed481e3369ba1b?v=1498432796)

![the picture](https://odzkskevi.qnssl.com/65d3a80b014f427e9f97489b0499dad1?v=1498432796)

The graph above corresponds to sample 2. There is only one walk for Okabe to reach (3, 0). After this, the possible walks are:

![path1](https://odzkskevi.qnssl.com/0b1feb7b11bb176ae89eacdec09e64b4?v=1498432796)

![path2](https://odzkskevi.qnssl.com/c87fb4b8d346b4b3728ebad09672c2aa?v=1498432796)

![path3](https://odzkskevi.qnssl.com/a85f8a462b64a9ed8fb7089c2faf4511?v=1498432796)

![path4](https://odzkskevi.qnssl.com/05d908cbbb6edf0d7d1bb3972dcf44ee?v=1498432796)

