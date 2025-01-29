```pseudo
\begin{algorithm}
\caption{Sieve of Eratosthenes}
\begin{algorithmic}
\Procedure{Sieve}{$n$}
    \State Create boolean array $is\_prime[0 \dots n]$, initialize all entries to \textbf{true}
    \State $is\_prime[0] \gets \textbf{false}$ \Comment{0 is not prime}
    \State $is\_prime[1] \gets \textbf{false}$ \Comment{1 is not prime}
    \For{$i \gets 2$ \To $\lfloor \sqrt{n} \rfloor$}
        \If{$is\_prime[i]$}
            \For{$j \gets i^2$ \To $n$ \textbf{step} $i$}
                \State $is\_prime[j] \gets \textbf{false}$ \Comment{Mark multiples of $i$ as non-prime}
            \EndFor
        \EndIf
    \EndFor
    \State \textbf{Initialize} $primes \gets \emptyset$
    \For{$p \gets 2$ \To $n$}
        \If{$is\_prime[p]$}
            \State $primes \gets primes \cup \{p\}$ \Comment{Collect remaining primes}
        \EndIf
    \EndFor
    \State \Return $primes$
\EndProcedure
\end{algorithmic}
\end{algorithm}
```
```cpp
vector<int> sieve(int n) {
	if (n < 2) return {};
	
	vector<bool> is_prime(n + 1, true);
	is_prime[0] = is_prime[1] = false;

	for (int i = 2; i * i <= n; ++i) {
		if (is_prime[i]) {
			for (int j = i * i; j <= n; j += i) {
				is_prime[j] = false;
			}
		}
	}
	vector<int> primes;
	for (int p = 2; p <= n; ++p) {
		if (is_prime[p]) {
			primes.push_back(p);
		}
	}

	return primes;
}
```
