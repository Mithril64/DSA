```pseudo
\begin{algorithm}
\caption{Quicksort}
\begin{algorithmic}
\Procedure{Quicksort}{$arr$, $low$, $high$}
    \If{$low < high$}
        \State $pivot\_idx \gets$ \Call{Partition}{$arr$, $low$, $high$} \Comment{Place pivot in correct position}
        \State \Call{Quicksort}{$arr$, $low$, $pivot\_idx - 1$} \Comment{Recursively sort left subarray}
        \State \Call{Quicksort}{$arr$, $pivot\_idx + 1$, $high$} \Comment{Recursively sort right subarray}
    \EndIf
\EndProcedure

\Procedure{Partition}{$arr$, $low$, $high$}
    \State $pivot \gets arr[high]$ \Comment{Choose last element as pivot}
    \State $i \gets low - 1$ \Comment{Index for smaller elements}
    \For{$j \gets low$ \textbf{to} $high - 1$}
        \If{$arr[j] \leq pivot$}
            \State $i \gets i + 1$
            \State \Call{Swap}{$arr[i]$, $arr[j]$} \Comment{Move smaller element left}
        \EndIf
    \EndFor
    \State \Call{Swap}{$arr[i + 1]$, $arr[high]$} \Comment{Place pivot in correct position}
    \State \Return $i + 1$ \Comment{Return pivot index}
\EndProcedure
\end{algorithmic}
\end{algorithm}
```
```cpp
void quickSort(vector<int>& arr, int low, int high) {
	if (low < high) {
		pivot_index = partition(arr, low, high);
		quickSort(arr, low, pivot_index - 1);
		quickSort(arr, pivot_index + i, high);
	}
}

int partition(vector<int>& arr, int low, int high) {
	pivot = arr[high];
	i = low - 1;

	for (int j = low; j < high; ++j) {
		if (arr[j] < pivot) {
			++i;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i + 1], arr[high]);

	return i + 1;
}
```
