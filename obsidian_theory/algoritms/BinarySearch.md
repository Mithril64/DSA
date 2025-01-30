```pseudo
\begin{algorithm}
\caption{Binary Search}
\begin{algorithmic}
\Procedure{BinarySearch}{$A[0 \dots n-1]$, $x$}
    \If{$n = 0$}
        \Return $-1$ \Comment{Empty array}
    \EndIf
    \State $\text{low} \gets 0$
    \State $\text{high} \gets n - 1$
    \While{$\text{low} \leq \text{high}$}
        \State $\text{mid} \gets \left\lfloor \frac{\text{low} + \text{high}}{2} \right\rfloor$ 
        \If{$A[\text{mid}] = x$}
            \Return $\text{mid}$ 
        \ElsIf{$A[\text{mid}] < x$}
            \State $\text{low} \gets \text{mid} + 1$ 
        \Else
            \State $\text{high} \gets \text{mid} - 1$ 
        \EndIf
    \EndWhile
    \State \Return $-1$ 
\EndProcedure
\end{algorithmic}
\end{algorithm}
```
```cpp
int binarySearch(vector<int> sorted_arr, int target) {
	if (sorted_arr.size() == 0) return -1;
	int low = 0, high = sorted_arr.size() - 1;

	while (low <= high) {
		int mid = low + (high - low) / 2;
		if (sorted_arr[mid] == target) {
			return mid;
		} else if (sorted_arr[mid] < target) {
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}

	return -1;
}
```
