Give the address of this contest:
[contest8](https://cn.vjudge.net/contest/167828)
##### codeforces contest 379
[click here to enter codeforces](http://codeforces.com/contest/379)

## A -New Year Candles
### Problem
Vasily the Programmer loves romance, so this year he decided to illuminate his room with candles.
Vasily has a candles.When Vasily lights up a new candle, it first burns for an hour and then it goes out. Vasily is smart, so he can make b went out candles into a new candle. As a result, this new candle can be used like any other new candle.
Now Vasily wonders: for how many hours can his candles light up the room if he acts optimally well? Help him find this number.
### Input
The single line contains two integers, a and b (1 ≤ a ≤ 1000; 2 ≤ b ≤ 1000).
### Output
Print a single integer — the number of hours Vasily can light up the room for.
### Example
#### Input
4 2
#### Output
7
#### Input
6 3
#### Output
8
### Note
Consider the first sample. For the first four hours Vasily lights up new candles, then he uses four burned out candles to make two new ones and lights them up. When these candles go out (stop burning), Vasily can make another candle. Overall, Vasily can light up the room for 7 hours.

---------------------------------------------------------

## B -New Year Present
### Problem
The New Year is coming! That's why many people today are busy preparing New Year presents. Vasily the Programmer is no exception.
Vasily knows that the best present is (no, it's not a contest) money. He's put n empty wallets from left to right in a row and decided how much money to put in what wallet. Vasily decided to put ai coins to the i-th wallet from the left.
Vasily is a very busy man, so the money are sorted into the bags by his robot. Initially, the robot stands by the leftmost wallet in the row. The robot can follow instructions of three types: go to the wallet that is to the left of the current one (if such wallet exists), go to the wallet that is to the right of the current one (if such wallet exists), put a coin to the current wallet. Due to some technical malfunctions the robot cannot follow two "put a coin" instructions in a row.
Vasily doesn't want to wait for long, so he wants to write a program for the robot that contains at most 106 operations (not necessarily minimum in length) the robot can use to put coins into the wallets. Help him.
### Input
The first line contains integer n (2 ≤ n ≤ 300) — the number of wallets. The next line contains n integers a1, a2, ..., an (0 ≤ ai ≤ 300).
It is guaranteed that at least one ai is positive.
### Output
Print the sequence that consists of k (1 ≤ k ≤ 106) characters, each of them equals: "L", "R" or "P". Each character of the sequence is an instruction to the robot. Character "L" orders to move to the left, character "R" orders to move to the right, character "P" orders the robot to put a coin in the wallet. The robot is not allowed to go beyond the wallet line. In other words, you cannot give instructions "L" if the robot is at wallet 1, or "R" at wallet n.
As a result of the performed operations, the i-th wallet from the left must contain exactly ai coins. If there are multiple answers, you can print any of them.
### Example
#### Input
2
1 2
#### Output
PRPLRP
#### Input
4
0 2 0 2
#### Output
RPRRPLLPLRRRP

---------------------------------------

## C -New Year Ratings Change
### Problem
One very well-known internet resource site (let's call it X) has come up with a New Year adventure. Specifically, they decided to give ratings to all visitors.
There are n users on the site, for each user we know the rating value he wants to get as a New Year Present. We know that user i wants to get at least ai rating units as a present.
The X site is administered by very creative and thrifty people. On the one hand, they want to give distinct ratings and on the other hand, the total sum of the ratings in the present must be as small as possible.
Help site X cope with the challenging task of rating distribution. Find the optimal distribution.
###Input
The first line contains integer n (1 ≤ n ≤ 3·105) — the number of users on the site. The next line contains integer sequence a1, a2, ..., an (1 ≤ ai ≤ 109).
### Output
Print a sequence of integers b1, b2, ..., bn. Number bi means that user i gets bi of rating as a present. The printed sequence must meet the problem conditions.
If there are multiple optimal solutions, print any of them.
### Example
#### Input
3
5 1 1
#### Output
5 1 2
#### Input
1
1000000000
#### Output
1000000000

-----------------------------------

## D -New Year Letter
### Problem
Many countries have such a New Year or Christmas tradition as writing a letter to Santa including a wish list for presents. Vasya is an ordinary programmer boy. Like all ordinary boys, he is going to write the letter to Santa on the New Year Eve (we Russians actually expect Santa for the New Year, not for Christmas).
Vasya has come up with an algorithm he will follow while writing a letter. First he chooses two strings, s1 anf s2, consisting of uppercase English letters. Then the boy makes string sk, using a recurrent equation sn = sn - 2 + sn - 1, operation '+' means a concatenation (that is, the sequential record) of strings in the given order. Then Vasya writes down string sk on a piece of paper, puts it in the envelope and sends in to Santa.
Vasya is absolutely sure that Santa will bring him the best present if the resulting string sk has exactly x occurrences of substring AC (the short-cut reminds him оf accepted problems). Besides, Vasya decided that string s1 should have length n, and string s2 should have length m. Vasya hasn't decided anything else.
At the moment Vasya's got urgent New Year business, so he asks you to choose two strings for him, s1 and s2 in the required manner. Help Vasya.
### Input
The first line contains four integers k, x, n, m (3 ≤ k ≤ 50; 0 ≤ x ≤ 109; 1 ≤ n, m ≤ 100).
### Output
In the first line print string s1, consisting of n uppercase English letters. In the second line print string s2, consisting of m uppercase English letters. If there are multiple valid strings, print any of them.
If the required pair of strings doesn't exist, print "Happy new year!" without the quotes.
### Example
#### Input
3 2 2 2
#### Output
AC
AC
#### Input
3 3 2 2
#### Output
Happy new year!
#### Input
3 0 2 2
#### Output
AA
AA
#### Input
4 3 2 1
#### Output
Happy new year!
#### Input
4 2 2 1
#### Output
Happy new year!

-----------------------------------

## E -New Year Tree Decorations
### Problem
Due to atheistic Soviet past, Christmas wasn't officially celebrated in Russia for most of the twentieth century. As a result, the Russian traditions for Christmas and New Year mixed into one event celebrated on the New Year but including the tree, a Santa-like 'Grandfather Frost', presents and huge family reunions and dinner parties all over the country. Bying a Tree at the New Year and installing it in the house is a tradition. Usually the whole family decorates the tree on the New Year Eve. We hope that Codeforces is a big and loving family, so in this problem we are going to decorate a tree as well.
So, our decoration consists of n pieces, each piece is a piece of colored paper, its border is a closed polyline of a special shape. The pieces go one by one as is shown on the picture. The i-th piece is a polyline that goes through points: (0, 0), (0, y0), (1, y1), (2, y2), ..., (k, yk), (k, 0). The width of each piece equals k.
The figure to the left shows the decoration, the figure to the right shows the individual pieces it consists of.
The piece number 1 (shown red on the figure) is the outer piece (we see it completely), piece number 2 (shown yellow) follows it (we don't see it completely as it is partially closed by the first piece) and so on. The programmers are quite curious guys, so the moment we hung a decoration on the New Year tree we started to wonder: what area of each piece can people see?
###Input
The first line contains two integers, n and k (1 ≤ n, k ≤ 300). Each of the following n lines contains k + 1 integers — the description of the polyline. If the i-th line contains ontegers yi, 0, yi, 1, ..., yi, k, that means that the polyline of the i-th piece goes through points (0, 0), (0, yi, 0), (1, yi, 1), (2, yi, 2), ..., (k, yi, k), (k, 0) (1 ≤ yi, j ≤ 1000).
###Output
Print n real numbers — for each polyline, the area of its visible part.
The answer will be considered correct if its relative or absolute error do not exceed 10 - 4.
### Example
#### Input
2 2
2 1 2
1 2 1
#### Output
3.000000000000
0.500000000000
#### Input
1 1
1 1
#### Output
1.000000000000
#### Input
4 1
2 7
7 2
5 5
6 4
#### Output
4.500000000000
1.250000000000
0.050000000000
0.016666666667

-----------------------------------

## F -New Year Tree
### Probblem
You are a programmer and you have a New Year Tree (not the traditional fur tree, though) — a tree of four vertices: one vertex of degree three (has number 1), connected with three leaves (their numbers are from 2 to 4).
On the New Year, programmers usually have fun. You decided to have fun as well by adding vertices to the tree. One adding operation looks as follows:
First we choose some leaf of the tree with number v.
Let's mark the number of vertices on the tree at this moment by variable n, then two vertexes are added to the tree, their numbers are n + 1 and n + 2, also you get new edges, one between vertices v and n + 1 and one between vertices v and n + 2.
Your task is not just to model the process of adding vertices to the tree, but after each adding operation print the diameter of the current tree. Come on, let's solve the New Year problem!
### Input
The first line contains integer q (1 ≤ q ≤ 5·105) — the number of operations. Each of the next q lines contains integer vi (1 ≤ vi ≤ n) — the operation of adding leaves to vertex vi. Variable n represents the number of vertices in the current tree.
It is guaranteed that all given operations are correct.
### Output
Print q integers — the diameter of the current tree after each operation.
### Example
#### Input
5
2
3
4
8
5
#### Output
3
4
4
5
6
