Try out all possible choices at a given index.

Now, i and j represent two characters from strings S1 and S2 respectively. There are only two options that make sense: either the characters represented by i and j match or they don’t.

(i) When the characters match

if(S1[i]==S2[j]), 

If this is true, the characters at i and j match, we can simply move to the next characters of both the strings. So we will just decrement both i and j by 1 and recursively find the answer for the remaining string portions. We return f(i-1,j-1). The following figure makes it clear.


(ii) When the characters don’t match

If the characters don’t match, there are three possible scenarios:

S1[i] == ‘?’
S1[i] == ‘*’
S1[i] is some other character
Let us discuss them one by one:

(i) If S1[i] == ‘?’

In this case, we can explicitly match ‘?’ at index i of S1 with the corresponding character at index j of S2. And then recursively call f(i-1,j-1) to check for the remaining string.

(ii) If S1[i] == ‘*’

This is an interesting case as now ‘*’ can be replaced with any sequence of characters( of length 0 or more) from S2.

We will revisit this example:


If any of these cases return true, we can say that the characters do match. The next question is how to try all possible ways?

We are using two pointers i and j to represent characters of strings S1 and S2. We can surely write a for loop to compare characters from 0 to j of S2 for the above scenario. Can we do it more smartly? Yes, we can. Please understand the approach explained below.

We are using a recursive function f(i,j). If we do only the following two recursive calls:

Call f(i-1,j). i.e replace ‘*’ with nothing and act as if it was not present.
Call f(i,j-1). i.e replace ‘*’ with a single character at index j and make the i pointer to still point at index i. In this, we matched it with a single character (one of the many options that need to be tried) and in the next recursive call, as i still point to ‘*’, we get the exact two recursive calls again.
The following recursive tree will help us to understand the recursion better.


So we see how we can tackle all the required cases associated with ‘*’ by using recursion.

(iii) If S1[i] is neither ‘?’ nor ‘*’, then we can say as the characters at i and j don’t match then the strings don’t match, so we return false.

To summarise:

If S1[i] == ‘?’, return f(i-1,j)
Else if S1[i] == ‘*’, return f(i-1,j) || f(i,j-1)
Else return false
Step 3: Return logical OR (||) of all the choices

If any of the cases return true, we can say that strings do match. We can use OR operator (||) with the recursive calls.

Base Cases:

We are reducing i and j in our recursive relation, there can be two possibilities, either i becomes -1 or j becomes -1., i,e we exhaust either S1 or S2 respectively.

(i) When S1 is exhausted:

When S1 is exhausted (i<0), we know that in order for the strings to match, String S2 should also exhaust simultaneously. If it does, we return true, else we return false.

We can say:

if(i<0 && j<0), return true.
if(i<0 && j>=0), return false.
(ii) When S2 is exhausted:

When S2 is exhausted(j<0) and S1 has not, there is only one pattern that can account for true(matching of strings). It is if S1 is like this “*”,”****”,”***”, i.e: S1 contains only stars. Then we can replace every star with a sequence of length 0 and say that the string match.

If S1 is all-stars, we return true, else return false.
