# Reverse Spiral Form of Matrix
## Medium 
<div class="problem-statement">
                <p></p><p><span style="font-size:18px">Given a matrix as 2D array.&nbsp;Return&nbsp;the matrix in reverse spiral form.â€‹<br>
<br>
<strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input</strong>: R = 3, C = 3
  a = {{9, 8, 7},
       {6, 5, 4},
&nbsp;      {3, 2, 1}}
<strong>Output: </strong>{5 6 3 2 1 4 7 8 9}&nbsp;
<strong>Explanation</strong>: Spiral form of the matrix
is 9-&gt;8-&gt;7-&gt;4-&gt;1-&gt;2-&gt;3-&gt;6-&gt;5 and then 
reverse.</span>
</pre>

<p><br>
<span style="font-size:18px"><strong>Example 2:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input: </strong>R = 4, C = 4<strong> 
</strong>  a = {{1, 2, 3, 4},
       {5, 6, 7, 8},
&nbsp;      {9, 10, 11, 12}, 
&nbsp;      {13, 14, 15, 16}}
<strong>Output:&nbsp;</strong>{10 11 7 6 5 9 13 14 15 16 12 8 4 3 2 1}
<strong>Explanation</strong>: Spiral form of the matrix
is 1-&gt;2-&gt;3-&gt;4-&gt;8-&gt;12-&gt;16-&gt;15-&gt;14-&gt;13-&gt;9
-&gt;5-&gt;6-&gt;7-&gt;11-&gt;10 and then reverse. 
</span></pre>

<p><br>
<span style="font-size:18px"><strong>Your Task:&nbsp;&nbsp;</strong><br>
You dont need to read input or print anything. Complete the function <strong>reverseSpiral()&nbsp;</strong>which takes <strong>R, C </strong>and<strong> a</strong>&nbsp;as input parameters and returns the matrix in reverse spiral form.</span><br>
<br>
<span style="font-size:18px"><strong>Expected Time Complexity:</strong> O(R*C)<br>
<strong>Expected Auxiliary Space:</strong> O(R*C)<br>
<br>
<strong>Constraints:</strong><br>
1&nbsp;&lt;= R,C&nbsp;&lt;=100<br>
1&nbsp;&lt;= a[R][C] &lt;=100</span></p>
 <p></p>
            </div>