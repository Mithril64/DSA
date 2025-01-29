```pseudo
\begin{algorithm}
\caption{Longest Palindromic Substring}
\begin{algorithmic}
\Procedure{LongestPalindrome}{$s$}
    \If{$s = \emptyset$}
	    \Return ""
    \EndIf
    \State $start \gets 0$
    \State $end \gets 0$
    \For{$i \gets 0$ \To $|s| - 1$}
        \State $len\_odd \gets$ \Call{ExpandAroundCenter}{$s, i, i$} \Comment{Odd-length palindrome}
        \State $len\_even \gets$ \Call{ExpandAroundCenter}{$s, i, i + 1$} \Comment{Even-length palindrome}
        \State $current\_max \gets \max(len\_odd, len\_even)$
        \If{$current\_max > end - start + 1$}
            \State $start \gets i - \lfloor (current\_max - 1)/2 \rfloor$ \Comment{Update start index}
            \State $end \gets i + \lfloor current\_max/2 \rfloor$ \Comment{Update end index}
        \EndIf
    \EndFor
    \State \Return $s[start \dots end]$ \Comment{Longest palindromic substring}
\EndProcedure

\Procedure{ExpandAroundCenter}{$s, left, right$}
    \While{$left \geq 0$ \textbf{and} $right < |s|$ \textbf{and} $s[left] = s[right]$}
        \State $left \gets left - 1$
        \State $right \gets right + 1$
    \EndWhile
    \State \Return $right - left - 1$ \Comment{Length of valid palindrome}
\EndProcedure
\end{algorithmic}
\end{algorithm}
```
```cpp
string longestPalindrome(string s) {
	if (s.length() == 0) return "";
	int start = 0, end = 0;

	for (int i = 0; i < s.length(); ++i) {
		len_odd = expandAroundCenter(s, i, i);
		len_even = expandAroundCenter(s, i, i + 1);
		current_max = max(len_odd, len_even);

		if (current_max > (end - start + 1)) {
			start = i - floor((current_max - 1) / 2);
			end = i + floor(current_max / 2);
		}
	}

	return s.substr(start, end - start + 1);
}

int expandAroundCenter(string s, int left, int right) {
	while (left >= 0 && right < s.length() && s[left] == s[right]) {
		left--;
		right++;
	}

	return right - left - 1;
}
```
